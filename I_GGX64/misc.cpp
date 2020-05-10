
#include "chess.h"



////
//// Includes
////






#ifdef _WIN32
#if _WIN32_WINNT < 0x0601
#undef  _WIN32_WINNT
#define _WIN32_WINNT 0x0601 // Force to include needed API prototypes
#endif
#include <windows.h>
// The needed Windows API for processor groups could be missed from old Windows
// versions, so instead of calling them directly (forcing the linker to resolve
// the calls at compile time), try to load them at runtime. To do this we need
// first to define the corresponding function pointers.
extern "C" {
	typedef bool(*fun1_t)(LOGICAL_PROCESSOR_RELATIONSHIP,
		PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX, PDWORD);
	typedef bool(*fun2_t)(USHORT, PGROUP_AFFINITY);
	typedef bool(*fun3_t)(HANDLE, CONST GROUP_AFFINITY*, PGROUP_AFFINITY);
}
#endif




#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#include "misc.h"
#include "thread.h"

using namespace std;

namespace {

	/// Version number. If Version is left empty, then compile date in the format
	/// DD-MM-YY and show in engine_info.
	const string Version = "";


	/// Our fancy logging facility. The trick here is to replace cin.rdbuf() and
	/// cout.rdbuf() with two Tie objects that tie cin and cout to a file stream. We
	/// can toggle the logging of std::cout and std:cin at runtime while preserving
	/// usual i/o functionality and without changing a single line of code!
	/// Idea from http://groups.google.com/group/comp.lang.c++/msg/1d941c0f26ea0d81

	struct Tie : public streambuf { // MSVC requires split streambuf for cin and cout

		Tie(streambuf* b, streambuf* l) : buf(b), logBuf(l) {}

		int sync() { return logBuf->pubsync(), buf->pubsync(); }
		int overflow(int c) { return log(buf->sputc((char)c), "<< "); }
		int underflow() { return buf->sgetc(); }
		int uflow() { return log(buf->sbumpc(), ">> "); }

		streambuf *buf, *logBuf;

		int log(int c, const char* prefix) {

			static int last = '\n'; // Single log file

			if (last == '\n')
				logBuf->sputn(prefix, 3);

			return last = logBuf->sputc((char)c);
		}
	};

	class Logger {

		Logger() : in(cin.rdbuf(), file.rdbuf()), out(cout.rdbuf(), file.rdbuf()) {}
		~Logger() { start(false); }

		ofstream file;
		Tie in, out;

	public:
		static void start(bool b) {

			static Logger l;

			if (b && !l.file.is_open())
			{
				l.file.open("io_log.txt", ifstream::out);
				cin.rdbuf(&l.in);
				cout.rdbuf(&l.out);
			}
			else if (!b && l.file.is_open())
			{
				cout.rdbuf(l.out.buf);
				cin.rdbuf(l.in.buf);
				l.file.close();
			}
		}
	};

} // namespace

/// engine_info() returns the full name of the current Stockfish version. This
/// will be either "Stockfish <Tag> DD-MM-YY" (where DD-MM-YY is the date when
/// the program was compiled) or "Stockfish <Version>", depending on whether
/// Version is empty.

const string engine_info(bool to_uci) {

	const string months("Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec");
	const string cpu64(" 64bit");
	const string popcnt(" SSE4.2");

	string month, day, year;
	stringstream s, date(__DATE__); // From compiler, format is "Sep 21 2008"

	s << "GGchess " << Version << setfill('0');
	
	if (Version.empty())
	{
		date >> month >> day >> year;
		s << setw(2) << day << setw(2) << (1 + months.find(month) / 4) 
			<< year.substr(0) << "_MAXCPU:" << MAX_CPUS;
	}

	s << (to_uci ? "\nid author ": " by ")
		<< "Li Guolai http://www.ggchess.com";

	return s.str();
}

/// Debug functions used mainly to collect run-time statistics
static int64_t hits[2], means[2];

/// Debug functions used mainly to collect run-time statistics

void dbg_hit_on(bool b) { ++hits[0]; if (b) ++hits[1]; }
void dbg_hit_on(bool c, bool b) { if (c) dbg_hit_on(b); }
void dbg_mean_of(int v) { ++means[0]; means[1] += v; }

void dbg_print() {

	if (hits[0])
		cerr << "Total " << hits[0] << " Hits " << hits[1]
		<< " hit rate (%) " << 100 * hits[1] / hits[0] << endl;

	if (means[0])
		cerr << "Total " << means[0] << " Mean "
		<< (double)means[1] / means[0] << endl;
}


/// Used to serialize access to std::cout to avoid multiple threads to write at
/// the same time.

std::ostream& operator<<(std::ostream& os, SyncCout sc) {

	static Mutex m;

	if (sc == IO_LOCK)
		m.lock();

	if (sc == IO_UNLOCK)
		m.unlock();

	return os;
}


/// Trampoline helper to avoid moving Logger to misc.h
void start_logger(bool b) { Logger::start(b); }


/// prefetch() preloads the given address in L1/L2 cache. This is a non-blocking
/// function that doesn't stall the CPU waiting for data to be loaded from memory,
/// which can be quite slow.
#ifdef NO_PREFETCH

void prefetch(void*) {}

#else

void prefetch(void* addr) {

#  if defined(__INTEL_COMPILER)
	// This hack prevents prefetches from being optimized away by
	// Intel compiler. Both MSVC and gcc seem not be affected by this.
	__asm__("");
#  endif

#  if defined(__INTEL_COMPILER) || defined(_MSC_VER)
	_mm_prefetch((char*)addr, _MM_HINT_T0);
#  else
	__builtin_prefetch(addr);
#  endif
}

#endif

/// cpu_count() tries to detect the number of CPU cores.

int cpu_count() {

#if defined(_MSC_VER)
	SYSTEM_INFO s;
	GetSystemInfo(&s);
	return (int)std::min(size_t(s.dwNumberOfProcessors), size_t(MAX_CPUS));
#else

#  if defined(_SC_NPROCESSORS_ONLN)
	return std::min((int)sysconf(_SC_NPROCESSORS_ONLN), MAX_THREADS);
#  elif defined(__hpux)
	struct pst_dynamic psd;
	if (pstat_getdynamic(&psd, sizeof(psd), (size_t)1, 0) == -1)
		return 1;
	return std::min((int)psd.psd_proc_cnt, MAX_THREADS);
#  else
	return 1;
#  endif

#endif
}


namespace WinProcGroup {

#ifndef _WIN32

	void bindThisThread(size_t) {}

#else

	/// get_group() retrieves logical processor information using Windows specific
	/// API and returns the best group id for the thread with index idx. Original
	/// code from Texel by Peter Österlund.

	int get_group(size_t idx) {

		int threads = 0;
		int nodes = 0;
		int cores = 0;
		DWORD returnLength = 0;
		DWORD byteOffset = 0;

		// Early exit if the needed API is not available at runtime
		HMODULE k32 = GetModuleHandle(L"Kernel32.dll");
		auto fun1 = (fun1_t)GetProcAddress(k32, "GetLogicalProcessorInformationEx");
		if (!fun1)
			return -1;

		// First call to get returnLength. We expect it to fail due to null buffer
		if (fun1(RelationAll, nullptr, &returnLength))
			return -1;

		// Once we know returnLength, allocate the buffer
		SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX *buffer, *ptr;
		ptr = buffer = (SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX*)malloc(returnLength);

		// Second call, now we expect to succeed
		if (!fun1(RelationAll, buffer, &returnLength))
		{
			free(buffer);
			return -1;
		}

		while (ptr->Size > 0 && byteOffset + ptr->Size <= returnLength)
		{
			if (ptr->Relationship == RelationNumaNode)
				nodes++;

			else if (ptr->Relationship == RelationProcessorCore)
			{
				cores++;
				threads += (ptr->Processor.Flags == LTP_PC_SMT) ? 2 : 1;
			}

			byteOffset += ptr->Size;
			ptr = (SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX*)(((char*)ptr) + ptr->Size);
		}

		free(buffer);

		std::vector<int> groups;

		// Run as many threads as possible on the same node until core limit is
		// reached, then move on filling the next node.
		for (int n = 0; n < nodes; n++)
			for (int i = 0; i < cores / nodes; i++)
				groups.push_back(n);

		// In case a core has more than one logical processor (we assume 2) and we
		// have still threads to allocate, then spread them evenly across available
		// nodes.
		for (int t = 0; t < threads - cores; t++)
			groups.push_back(t % nodes);

		// If we still have more threads than the total number of logical processors
		// then return -1 and let the OS to decide what to do.
		return idx < groups.size() ? groups[idx] : -1;
	}


	/// bindThisThread() set the group affinity of the current thread

	void bindThisThread(size_t idx) {

		// If OS already scheduled us on a different group than 0 then don't overwrite
		// the choice, eventually we are one of many one-threaded processes running on
		// some Windows NUMA hardware, for instance in fishtest. To make it simple,
		// just check if running threads are below a threshold, in this case all this
		// NUMA machinery is not needed.
		if (Threads.size() < 8)
			return;

		// Use only local variables to be thread-safe
		int group = get_group(idx);

		if (group == -1)
			return;

		// Early exit if the needed API are not available at runtime
		HMODULE k32 = GetModuleHandle(L"Kernel32.dll");
		auto fun2 = (fun2_t)GetProcAddress(k32, "GetNumaNodeProcessorMaskEx");
		auto fun3 = (fun3_t)GetProcAddress(k32, "SetThreadGroupAffinity");

		if (!fun2 || !fun3)
			return;

		GROUP_AFFINITY affinity;
		if (fun2(group, &affinity))
			fun3(GetCurrentThread(), &affinity, nullptr);
	}

#endif

} // namespace WinProcGroup



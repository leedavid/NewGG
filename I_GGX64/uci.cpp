
#include "chess.h"














#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

#include "evaluate.h"
#include "movegen.h"
#include "position.h"
#include "search.h"
#include "thread.h"
#include "timeman.h"
#include "tt.h"
#include "uci.h"
#include "syzygy/tbprobe.h"



using namespace std;

extern vector<string> setup_bench(const Position&, istream&);


namespace {

	// FEN string for the initial position
	const char* StartFEN = "rnbakabnr/9/1c5c1/p1p1p1p1p/9/9/P1P1P1P1P/1C5C1/9/RNBAKABNR w - - 0 1";

	// position() is called when engine receives the "position" UCI command.
	// The function sets up the position described in the given FEN string ("fen")
	// or the starting position ("startpos") and then makes the moves given in the
	// following move list ("moves").

	void position(Position& pos, istringstream& is, StateListPtr& states) {

		Move m;
		string token, fen;

		is >> token; // operator>>() skips any whitespace

		if (token == "startpos")
		{
			fen = StartFEN;
			is >> token; // Consume "moves" token if any
		}
		else if (token == "fen"){
			while (is >> token && token != "moves")
				fen += token + " ";
		}
		else 
			return;

		states = StateListPtr(new std::deque<StateInfo>(1)); // Drop old and create a new one
		pos.set(fen, &states->back(), Threads.main());

	    // Parse move list (if any)
		// fen 2b1k1b2/4a1P2/3a5/R8/8C/9/9/9/1r2K1p2/2B6 w - - 0 155
		// fen rnbakabnr/9/1c5c1/p1p1p1p1p/9/9/P1P1P1P1P/1C5C1/9/RNBAKABNR w - - 0 1 moves 
		// Parse move list (if any)
		while (is >> token && (m = UCI::to_move(pos, token)) != MOVE_NONE)
		{
			states->emplace_back();
			CheckInfo ci(pos);
			pos.do_move(m, states->back(), pos.gives_check(m, ci), ci);
		}		
	}

	// trace_eval() prints the evaluation for the current position, consistent with the UCI
	// options set so far.

	void trace_eval(Position& pos) {

		StateListPtr states(new std::deque<StateInfo>(1));
		Position p;
		p.set(pos.fen(), &states->back(), Threads.main());

		Eval::NNUE::verify();

		sync_cout << "\n" << Eval::trace(p) << sync_endl;
	}
	void setoption(istringstream& is) {

		string token, name, value;

		is >> token; // Consume "name" token

		// Read option name (can contain spaces)
		while (is >> token && token != "value")
			name += (name.empty() ? "" : " ") + token;

		// Read option value (can contain spaces)
		while (is >> token)
			value += (value.empty() ? "" : " ") + token;

		if (Options.count(name))
			Options[name] = value;
		else
			sync_cout << "No such option: " << name << sync_endl;
	}


  // go() is called when engine receives the "go" UCI command. The function sets
  // the thinking time and other parameters from the input string, then starts
  // the search.

	void go(Position& pos, istringstream& is, StateListPtr& states) {

		Search::LimitsType limits;
		string token;
		bool ponderMode = false;

		limits.startTime = now(); // As early as possible!

		while (is >> token)
			if (token == "searchmoves") // Needs to be the last command on the line
				while (is >> token)
					limits.searchmoves.push_back(UCI::to_move(pos, token));

			else if (token == "wtime")     is >> limits.time[WHITE];
			else if (token == "btime")     is >> limits.time[BLACK];
			else if (token == "winc")      is >> limits.inc[WHITE];
			else if (token == "binc")      is >> limits.inc[BLACK];
			else if (token == "movestogo") is >> limits.movestogo;
			else if (token == "depth")     is >> limits.depth;
			else if (token == "nodes")     is >> limits.nodes;
			else if (token == "movetime")  is >> limits.movetime;
			else if (token == "mate")      is >> limits.mate;
			else if (token == "perft")     is >> limits.perft;
			else if (token == "infinite")  limits.infinite = 1;
			else if (token == "ponder")    ponderMode = true;

		Threads.start_thinking(pos, states, limits, ponderMode);
	}


	// bench() is called when engine receives the "bench" command. Firstly
// a list of UCI commands is setup according to bench parameters, then
// it is run one by one printing a summary at the end.

	void bench(Position& pos, istream& args, StateListPtr& states) {

		string token;
		uint64_t num, nodes = 0, cnt = 1;

		vector<string> list = setup_bench(pos, args);
		num = count_if(list.begin(), list.end(), [](string s) { return s.find("go ") == 0 || s.find("eval") == 0; });

		TimePoint elapsed = now();

		for (const auto& cmd : list)
		{
			istringstream is(cmd);
			is >> skipws >> token;

			if (token == "go" || token == "eval")
			{
				cerr << "\nPosition: " << cnt++ << '/' << num << " (" << pos.fen() << ")" << endl;
				if (token == "go")
				{
					go(pos, is, states);
					Threads.main()->wait_for_search_finished();
					nodes += Threads.nodes_searched();
				}
				else
					trace_eval(pos);
			}
			else if (token == "setoption")  setoption(is);
			else if (token == "position")   position(pos, is, states);
			else if (token == "ucinewgame") { Search::clear(); elapsed = now(); } // Search::clear() may take some while
		}

		elapsed = now() - elapsed + 1; // Ensure positivity to avoid a 'divide by zero'

		dbg_print(); // Just before exiting

		cerr << "\n==========================="
			<< "\nTotal time (ms) : " << elapsed
			<< "\nNodes searched  : " << nodes
			<< "\nNodes/second    : " << 1000 * nodes / elapsed << endl;
	}

	// The win rate model returns the probability (per mille) of winning given an eval
	// and a game-ply. The model fits rather accurately the LTC fishtest statistics.
	int win_rate_model(Value v, int ply) {

		// The model captures only up to 240 plies, so limit input (and rescale)
		double m = std::min(240, ply) / 64.0;

		// Coefficients of a 3rd order polynomial fit based on fishtest data
		// for two parameters needed to transform eval to the argument of a
		// logistic function.
		double as[] = { -8.24404295, 64.23892342, -95.73056462, 153.86478679 };
		double bs[] = { -3.37154371, 28.44489198, -56.67657741,  72.05858751 };
		double a = (((as[0] * m + as[1]) * m + as[2]) * m) + as[3];
		double b = (((bs[0] * m + bs[1]) * m + bs[2]) * m) + bs[3];

		// Transform eval to centipawns with limited range
		double x = std::clamp(double(100 * v) / PawnValueEg, -1000.0, 1000.0);

		// Return win rate in per mille (rounded to nearest)
		return int(0.5 + 1000 / (1 + std::exp((a - x) / b)));
	}
} // namespace



/// UCI::loop() waits for a command from stdin, parses it and calls the appropriate
/// function. Also intercepts EOF from stdin to ensure gracefully exiting if the
/// GUI dies unexpectedly. When called with some command line arguments, e.g. to
/// run 'bench', once the command is executed the function returns immediately.
/// In addition to the UCI ones, also some additional debug commands are supported.

void UCI::loop(int argc, char* argv[]) {

	Position pos;
	string token, cmd;
	StateListPtr states(new std::deque<StateInfo>(1));

	pos.set(StartFEN, &states->back(), Threads.main());

	for (int i = 1; i < argc; ++i)
		cmd += std::string(argv[i]) + " ";

	do	{
		if (argc == 1 && !getline(cin, cmd)) // Block here waiting for input
			cmd = "quit";

		if (cmd.substr(0, 3) == "fen") {
			cmd = "position " + cmd;
		}

		istringstream is(cmd);

		token.clear(); // getline() could return empty or blank line
		is >> skipws >> token;

		if (token == "quit"
			|| token == "stop")
			Threads.stop = true;
		
		// The GUI sends 'ponderhit' to tell us the user has played the expected move.
	    // So 'ponderhit' will be sent if we were told to ponder on the same move the
	    // user has played. We should continue searching but switch from pondering to
	    // normal search.
		else if (token == "ponderhit")
			Threads.main()->ponder = false; // Switch to normal search

		else if (token == "uci")
			sync_cout << "id name " << engine_info(true)
			<< "\n" << Options
			<< "\nuciok" << sync_endl;
		
		else if (token == "setoption")  setoption(is);
		else if (token == "go")         go(pos, is, states);
		else if (token == "position")   position(pos, is, states);
		else if (token == "ucinewgame") Search::clear();
		else if (token == "isready")    sync_cout << "readyok" << sync_endl;

		// Additional custom non-UCI commands, mainly for debugging.
	  // Do not use these commands during a search!
		else if (token == "flip")     pos.flip();
		else if (token == "bench")    bench(pos, is, states);
		else if (token == "d")        sync_cout << pos << sync_endl;
		else if (token == "eval")     trace_eval(pos);
		else if (token == "compiler") sync_cout << compiler_info() << sync_endl;
		else
			sync_cout << "Unknown command: " << cmd << sync_endl;

	} while (token != "quit" && argc == 1); // Command line args are one-shot
}


/// UCI::value() converts a Value to a string suitable for use with the UCI
/// protocol specification:
///
/// cp <x>    The score from the engine's point of view in centipawns.
/// mate <y>  Mate in y moves, not plies. If the engine is getting mated
///           use negative values for y.

string UCI::value(Value v) {

	assert(-VALUE_INFINITE < v&& v < VALUE_INFINITE);

	stringstream ss;

	if (abs(v) < VALUE_MATE_IN_MAX_PLY)
		ss << "cp " << v * 100 / 100;
	else
		ss << "mate " << (v > 0 ? VALUE_MATE - v + 1 : -VALUE_MATE - v) / 2;

	return ss.str();
}


/// UCI::wdl() report WDL statistics given an evaluation and a game ply, based on
/// data gathered for fishtest LTC games.

string UCI::wdl(Value v, int ply) {

	stringstream ss;

	int wdl_w = win_rate_model(v, ply);
	int wdl_l = win_rate_model(-v, ply);
	int wdl_d = 1000 - wdl_w - wdl_l;
	ss << " wdl " << wdl_w << " " << wdl_d << " " << wdl_l;

	return ss.str();
}

/// UCI::square() converts a Square to a string in algebraic notation (g1, a7, etc.)

std::string UCI::square(Square s) {
	return std::string{ char('a' + StoX(s)), char('9' - StoY(s)) };
}


/// UCI::move() converts a Move to a string in coordinate notation (g1f3, a7a8q).
/// The only special case is castling, where we print in the e1g1 notation in
/// normal chess mode, and in e1h1 notation in chess960 mode. Internally all
/// castling moves are always encoded as 'king captures rook'.

string UCI::move(Move m) {

	Square from = from_sq(m);
	Square to = to_sq(m);

	if (m == MOVE_NONE)
		return "0000";
	else if (m == MOVE_NULL)
		return "0000";
	
	string move = UCI::square(from) + UCI::square(to);
	
	return move;
}









/// UCI::to_move() converts a string representing a move in coordinate notation
/// (g1f3, a7a8q) to the corresponding legal Move, if any.

Move UCI::to_move(Position& pos, string& str) {

	if (str.length() == 5) // Junior could send promotion piece in uppercase
		str[4] = char(tolower(str[4]));

	for (const auto& m : MoveList<LEGAL>(pos))
		if (str == UCI::move(m))
			return m;

	return MOVE_NONE;
}

#ifdef _MSC_VER_NOT_USE_NOW
bool ccmd(Position& pos, istringstream& uip){
	string token;
	while(uip >> token){
		if(token == "eval"){	

#ifdef CAN_OUT_EVAL_INFO
			//Value margin;
			// 
			Eval::init();		
			// 全局变量,可输出评估信息了. 
			MustOuPutEvalInf = true;
			Eval::evaluate(pos);
			//print_eval_info(RootPosition,eiInfo,val);		
#endif
		}
		else if(token == "bookmove"){
			while (uip >> token){
				int move_delay_time = 0;
				if(token == "delay"){
					uip >> move_delay_time;
					uip >> token;
				}

				sleep_ms(DELEY_BEST_MOVE_TIME);
				std::cout << "bestmove " << token << std::endl;
				return true;
			}
		}
		else if(token == "see"){
			//int m;
			if(uip >> token){

				pos.board_display("see!");

				Move m = move_from_string(pos, token);
				int see = pos.see_ge(Move(m), VALUE_ZERO);
				// pos.board_display("see!");

				std::cout << "see value: " << see << std::endl;
			}
		}
		else if(token == "cf"){
			// fen 4kab2/4a4/4b4/4nr2p/3R5/9/4P3P/4B1N2/4A4/4K4 b - - 0 53 moves f6f3 d5d6 e6g5 d6d4 g5h3 e0d0 f3f5 d4d2 f5b5 e2c0 b5b0 d2c2 b0b4 g2f0 b4d4 c2d2 d4c4 c0a2 c4c3 f0g2 c3b3 a2c0 b3b4 d2c2 e8d9 g2f0 f9e8 d0e0 h3g1 e0d0 g1f3 c2f2 f3g5 d0e0 e8f7 e0d0 b4g4 f2g2 g4h4 g2e2 f7e8 c0a2 i6i5 f0g2 h4d4 d0e0 g5h3 g2h0 d4f4 e2g2 h3g5 h0i2 g5e6 i2g3 f4g4 a2c0

			// istringstream ifen("fen 4kab2/4a4/4b4/4nr2p/3R5/9/4P3P/4B1N2/4A4/4K4 b - - 0 53 moves f6f3 d5d6 e6g5 d6d4 g5h3 e0d0 f3f5 d4d2 f5b5 e2c0 b5b0 d2c2 b0b4 g2f0 b4d4 c2d2 d4c4 c0a2 c4c3 f0g2 c3b3 a2c0 b3b4 d2c2 e8d9 g2f0 f9e8 d0e0 h3g1 e0d0 g1f3 c2f2 f3g5 d0e0 e8f7 e0d0 b4g4 f2g2 g4h4 g2e2 f7e8 c0a2 i6i5 f0g2 h4d4 d0e0 g5h3 g2h0 d4f4 e2g2 h3g5 h0i2 g5e6 i2g3 f4g4 a2c0");
			
			istringstream ifen("fen 2bak3C/1R2a4/3c5/4p4/2p3R2/2P6/2r1c3n/C3r3N/4Ap3/3NKAB2 w - - 0 2 moves g5g9 e8f9 g9g8 f9e8 g8g9");
			position(pos, ifen);
		}

		else if(token == "repeat"){

			// fen 1nbaka3/5r3/3Pb4/p1p1p3p/3c5/P1PN5/R5p2/2N1CAn2/9/2B1KAB2 b - - 0 moves d5e5 e0d0 e5d5 d0e0 d5e5 e0d0 e5d5 d0e0
			// fen 1nbaka3/5r3/3Pb4/p1p1p3p/3c5/P1PN5/R5p2/2N1C1n2/4A4/2B1KAB2 b - - 0 moves d5e5 e0d0 e5d5 d0e0 d5e5 e0d0 e5d5 d0e0
			// fen 3k5/1R7/3ara3/9/6n2/6B2/9/4C4/4AK3/c5B2 w - - 0 1 moves b8b9 d9d8 b9a9 a0b0 a9a8 d8d9 a8b8 b0a0 b8b9


#define REPEAT_DEBUG
#ifdef REPEAT_DEBUG
			pos.board_display("repeat test!");

			switch(pos.is_repeat()){
			case REPEAT_TRUE:
				std::cout << "REPEAT_TRUE!" << std::endl;
				break;
			case REPEAT_BAN_ME_CHECK:
				std::cout << "REPEAT_BAN_ME_CHECK!" << std::endl;
				break;
			case REPEAT_BAN_OTHER_CHECK:
				std::cout << "REPEAT_BAN_OTHER_CHECK!" << std::endl;
				break;
			case REPEAT_BAN_ME_CAP:
				std::cout << "REPEAT_BAN_ME_CAP!" << std::endl;
				break;
			case REPEAT_BAN_OTHER_CAP:
				std::cout << "REPEAT_BAN_OTHER_CAP!" << std::endl;
				break;
			case REPEAT_NO:
				std::cout << "REPEAT_NO!" << std::endl;
				break;
			}
#else
			pos.board_display("repeat test!");

			switch (pos.is_repeat()){
			case REPEAT_TRUE:
				std::cout << "REPEAT_TRUE!" << std::endl;
				break;
			case REPEAT_BAN_ME:
				std::cout << "REPEAT_BAN_ME_CHECK!" << std::endl;
				break;
			case REPEAT_BAN_OTHER:
				std::cout << "REPEAT_BAN_OTHER_CHECK!" << std::endl;
				break;
			case REPEAT_NO:
				std::cout << "REPEAT_NO!" << std::endl;
				break;
			}
#endif


			//if(!isre){
			//	RootPosition.board_display("repeat Now!");
			//}
			//else{
			//	std::cout << "not repeat!" << std::endl;
			//}
		}
	}
	return true;
}
#endif

#ifdef _MSC_VER_NOT_USE_NOW

#include <io.h>
#include <fcntl.h>
#include <share.h>
#include  <windows.h>  
#include <shellapi.h>
#include <sys/stat.h>

void read_uci_set_file(){
	//打开设定文件
	TCHAR filename[1024];  
	swprintf_s(filename,1024,L"%s\\%s",installDir,L"ggX64set2017.ini");

	int pFile;
	char rbuf[4096];

	errno_t err = _wsopen_s(&pFile,filename,_O_RDONLY, _SH_DENYNO,_S_IREAD);

	if(err == 0){
		int byteRead = _read(pFile,rbuf,4096);
		rbuf[byteRead] = 0;
		_close(pFile);

		
		//在这儿读出设定数据
		//setoption name xx value xx
		char *p = rbuf;

		char name[512];
		char value[512];

		char opcmd[1024];

        // 当有字节存在时
		while(*p != 0){

			//name
			if(*p == 10) p++;
			for(int i=0; i<128;i++){
				name[i] = *p;
				p++;
				if(*p == 0) return;
				if(*p == '='){
					name[i+1] = 0;
					break;
				}				
			}

			p++;
			for(int i=0; i<128; i++){
				value[i] = *p;
				p++;
				if(*p == 0) return;
				if(*p == 10){
					value[i+1] = 0;
					break;
				}	
			}

			if(strlen(name) > 2 && strlen(value) > 0){
				sprintf_s(opcmd,1024,"name %s value %s",name,value);
				istringstream uip(opcmd);
				set_option(uip);
			}
			else{
				return;
			}
		}      

	}
	else{
		printf("\ncannot open set file!!\n");
	}
}

#else

void read_uci_set_file() {
	
}

#endif


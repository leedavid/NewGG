#if !defined(SS_TYPES_H_INCLUDEDs)
#define SS_TYPES_H_INCLUDEDs

#include "limits.h"
#include <cstdlib>
#include <string>

#include "platform.h"
#include "define.h"
#include "my_const.h"

#define unlikely(x) (x) // For code annotation purposes

#if defined(_WIN32) || defined(_WIN64)
//#include <sys/timeb.h>
//typedef __timeb64 sys_time_t;
//inline void system_time(sys_time_t* t) { _ftime64_s(t); }
//inline sint64 system_time_to_msec() { 
//  __timeb64 t;
//  _ftime64_s(&t);
//  return t.time * 1000LL + t.millitm; }
#else
//include <sys/time.h>
//	typedef timeval my_time_t;
//inline void system_time(my_time_t* t) { gettimeofday(t, NULL); }
//inline uint64 time_to_msec(const my_time_t& t) { return t.tv_sec * 1000LL + t.tv_usec / 1000; }
#endif

#if !defined(_WIN32) && !defined(_WIN64)
#define TCHAR char
#endif

#define CACHE_LINE_SIZE 64
// Cache line alignment specification
#if defined(_MSC_VER) || defined(__INTEL_COMPILER)
#define CACHE_LINE_ALIGNMENT __declspec(align(CACHE_LINE_SIZE))
#else
#define CACHE_LINE_ALIGNMENT  __attribute__ ((aligned(CACHE_LINE_SIZE)))
#endif

// Define FORCE_INLINE macro to force inlining overriding compiler choice
#if defined(_MSC_VER)
#define FORCE_INLINE  __forceinline
#elif defined(__GNUC__)
#define FORCE_INLINE  inline __attribute__((always_inline))
#else
#define FORCE_INLINE  inline
#endif

/// cpu_has_popcnt() detects support for popcnt instruction at runtime
//inline bool cpu_has_popcnt() {
//
//	int CPUInfo[4] = {-1};
//	__cpuid(CPUInfo, 0x00000001);
//	return (CPUInfo[2] >> 23) & 1;
//}

/// Score enum keeps a midgame and an endgame value in a single
/// integer (enum), first LSB 16 bits are used to store endgame
/// value, while upper bits are used for midgame value. Compiler
/// is free to choose the enum type as long as can keep its data,
/// so ensure Score to be an integer type.
enum Score {
	SCORE_ZERO ,
	SCORE_ENSURE_INTEGER_SIZE_P = INT_MAX,
	SCORE_ENSURE_INTEGER_SIZE_N = INT_MIN
};

enum Bound {
	BOUND_NONE,
	BOUND_UPPER,
	BOUND_LOWER,
	BOUND_EXACT = BOUND_UPPER | BOUND_LOWER
};

enum PieceType {
	NO_PIECE_TYPE_S = 0,
	KING=1, SHI=2, XIANG=3, MA=4, CHE=5, PAO=6, PAWN=7
};

const int MAX_PLY        = 148;                    // must 120 因为中象120才和
//const int MAX_PLY_PLUS_6 = MAX_PLY + 6;


#ifdef REPEAT_DEBUG
#else
enum Value {
	VALUE_ZERO = 0,
	VALUE_DRAW = 1,
	VALUE_KNOWN_WIN = 10000,  // 	
	VALUE_BAN_CAP   = 11000,  //
#ifndef STORE_ALWAYS_CHECK 
	VALUE_BAN_CHECK = 29000,  //
#else
	VALUE_BAN_CHECK = 12000,
#endif
	VALUE_MATE = 32000,
	VALUE_INFINITE = 32001,
	VALUE_NONE = 32002,
	
	VALUE_ENSURE_INTEGER_SIZE_P = INT_MAX,
	VALUE_ENSURE_INTEGER_SIZE_N = INT_MIN
};

#define VALUE_MATE_IN_MAX_PLY  ( VALUE_MATE - MAX_PLY)
#define VALUE_MATED_IN_MAX_PLY (-VALUE_MATE + MAX_PLY)

#define VALUE_BAN_IN_MAX_PLY        ( VALUE_MATE - MAX_PLY)
#define VALUE_BANED_IN_MAX_PLY      (-VALUE_MATE + MAX_PLY)
#endif

enum Piece
{
	EMPTY=0,  // 这个不用了
	RKING=1,  RSHI=2, RXIANG=3, RMA=4, RCHE=5, RPAO=6, RPAWN=7,
	_X_X =8,
	BKING=9,  BSHI=10,BXIANG=11,BMA=12,BCHE=13,BPAO=14,BPAWN=15,   
};



const Value KING_VAL           = Value(10000); //     10000
const Value SHI_VAL            = Value(135);   //      145          //170
const Value XIANG_VAL          = Value(145);   //      125          //160
const Value CHE_VAL            = Value(980);   //      950          //1000
const Value MA_VAL             = Value(400);   //       400         //400
const Value PAO_VAL            = Value(400);   //       400         //400
const Value PAWN_VAL           = Value(100);   //       100         //100


const Value PawnValueMidgame   = Value(80);
const Value PawnValueEndgame   = Value(128);

const Value PieceValueMidgame[16] = {
	Value(0), 
	Value(0), SHI_VAL, XIANG_VAL, MA_VAL, CHE_VAL, PAO_VAL, PawnValueMidgame,
	Value(0), 
	Value(0), SHI_VAL, XIANG_VAL, MA_VAL, CHE_VAL, PAO_VAL, PawnValueMidgame,
};
const Value PieceValueEndgame[16] = {
	Value(0), 
	Value(0), SHI_VAL, XIANG_VAL, MA_VAL, CHE_VAL, PAO_VAL, PawnValueEndgame,
	Value(0), 
	Value(0), SHI_VAL, XIANG_VAL, MA_VAL, CHE_VAL, PAO_VAL, PawnValueEndgame,
};

enum Color {
	WHITE,
	BLACK,
	COLOR_NONE, COLOR_NB = 2
};

enum Depth {

	ONE_PLY = 1,

	DEPTH_ZERO          =  0 ,
	DEPTH_QS_CHECKS     = -0 ,
	DEPTH_QS_NO_CHECKS  = -1 ,
	DEPTH_QS_RECAPTURES = -5 ,

	////DEPTH_ZERO = 0 * ONE_PLY,
	////DEPTH_QS_CHECKS = -0 * ONE_PLY,
	////DEPTH_QS_NO_CHECKS = -1 * ONE_PLY,
	////DEPTH_QS_RECAPTURES = -5 * ONE_PLY,

	DEPTH_NONE = -6,
	DEPTH_MAX = MAX_PLY
};

//
//#define DEPTH_ZERO (0 * ONE_PLY)
//#define DEPTH_QS_CHECKS  (-1 * ONE_PLY)
//#define DEPTH_QS_NO_CHECKS (-2 * ONE_PLY)
//#define DEPTH_QS_RECAPTURES (-5 * ONE_PLY)
//#define DEPTH_NONE  (-127 * ONE_PLY)


enum Square {	
	SQ_START  = 0,
	SQ_END90  = 90
};

const Color _piece_color[16] = {
	COLOR_NONE,
	WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,
	COLOR_NONE, 	
	BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,
};

const uint8 revertChess[] = {
	EMPTY, 
	BKING, BSHI, BXIANG, BMA, BCHE, BPAO, BPAWN,
	_X_X,
	RKING, RSHI, RXIANG, RMA, RCHE, RPAO, RPAWN,
};

const bool ChessCanDirectCheck[] = {

	false,  // 这个不用了
	false, false, false, true, true, true, true,
	false,
	false, false, false, true, true, true, true,
};

/// Game phase
enum Phase {
	PHASE_ENDGAME = 0,
	PHASE_MIDGAME = 128,
	MG = 0, EG = 1, PHASE_NB = 2
};

//#define ChessCanDirCheck(c) ChessCanDirectCheck[x]

enum Direction {
	DIR_左右 = 0, DIR_上下 = 1, DIR_马 = 2, DIR_相 = 3, DIR_仕 = 4, DIR_NONE = 5,
};

enum Move {
	MOVE_NONE = 0,
	MOVE_NULL = 0x0101	
};

const int MAX_MOVES = 128;




inline Square from_sq(Move m) {
	return Square(((m) >> MOVE_BIT) & MOVE_MASK);
}

inline Square to_sq(Move m) {
	return Square(m & MOVE_MASK);
}

//inline int move_is_special(Move m) {
//	return false;  // return m & (0x1F << 12);
//}

inline Move make_move(int from, int to) {
	return Move(to | (from << MOVE_BIT));
}

inline int from_to(Move m) {
	return m & 0xFFFF;	
}


inline bool is_ok(Move m) {
	return from_sq(m) != to_sq(m); // Catches also MOVE_NULL and MOVE_NONE
}




inline Score make_score(int mg, int eg) { return Score((mg << 16) + eg); }




/// Extracting the signed lower and upper 16 bits it not so trivial because
/// according to the standard a simple cast to short is implementation defined
/// and so is a right shift of a signed integer.
inline Value mg_value(Score s) {
	return Value(((s + 0x8000) & ~0xffff) / 0x10000);
}

inline Value eg_value(Score s) {
	return Value((int)(unsigned(s) & 0x7FFFU) - (int)(unsigned(s) & 0x8000U));
}



//////////////////////////////////////////////////////////////////////////
#define ENABLE_BASE_OPERATORS_ON(T)                                         \
inline T operator+(const T d1, const T d2) { return T(int(d1) + int(d2)); } \
inline T operator-(const T d1, const T d2) { return T(int(d1) - int(d2)); } \
inline T operator*(int i, const T d) { return T(i * int(d)); }              \
inline T operator*(const T d, int i) { return T(int(d) * i); }              \
inline T operator-(const T d) { return T(-int(d)); }                        \
inline T& operator+=(T& d1, const T d2) { return d1 = d1 + d2; }            \
inline T& operator-=(T& d1, const T d2) { return d1 = d1 - d2; }            \
inline T& operator*=(T& d, int i) { return d = T(int(d) * i); }

ENABLE_BASE_OPERATORS_ON(Score)

#define ENABLE_FULL_OPERATORS_ON(T)                                         \
ENABLE_BASE_OPERATORS_ON(T)                                                 \
inline T& operator++(T& d) { return d = T(int(d) + 1); }        \
inline T& operator--(T& d) { return d = T(int(d) - 1); }        \
inline T operator/(T d, int i) { return T(int(d) / i); }        \
inline int operator/(T d1, T d2) { return int(d1) / int(d2); }  \
inline T& operator/=(T& d, int i) { return d = T(int(d) / i); }

ENABLE_FULL_OPERATORS_ON(Value)
ENABLE_FULL_OPERATORS_ON(PieceType)
ENABLE_FULL_OPERATORS_ON(Piece)
ENABLE_FULL_OPERATORS_ON(Color)
ENABLE_FULL_OPERATORS_ON(Depth)
ENABLE_FULL_OPERATORS_ON(Square)

#undef ENABLE_FULL_OPERATORS_ON
#undef ENABLE_BASE_OPERATORS_ON


inline Piece operator++(Piece& d, int) { d = Piece(int(d) + 1); return d; }
inline Square operator++(Square& d, int) { d = Square(int(d) + 1); return d; }

inline Square operator+(Square v, int i) { return Square(int(v) + i); }
inline Square operator-(Square v, int i) { return Square(int(v) - i); }

/// Additional operators to add integers to a Value
inline Value operator+(Value v, int i) { return Value(int(v) + i); }
inline Value operator-(Value v, int i) { return Value(int(v) - i); }
inline Value& operator+=(Value& v, int i) { return v = v + i; }
inline Value& operator-=(Value& v, int i) { return v = v - i; }

//ENABLE_SAFE_OPERATORS_ON(Score)



/// Only declared but not defined. We don't want to multiply two scores due to
/// a very high risk of overflow. So user should explicitly convert to integer.
//inline Score operator*(Score s1, Score s2);

/// Division of a Score must be handled separately for each term
inline Score operator/(Score s, int i) {
return make_score(mg_value(s) / i, eg_value(s) / i);
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
#ifdef REPEAT_DEBUG
inline Value value_ban_check_in(int ply) {
	return VALUE_BAN_CHECK - ply;
	//return VALUE_BAN;
}
#else
//inline Value value_ban_in(int ply) {
//	return VALUE_BAN - ply;
//	//return VALUE_BAN;
//}
#endif

inline PieceType type_of(Piece p)  {
	return PieceType(int(p) & 7);
}


// 棋子是不是兵或仕
inline bool isPawnShiXiangKing(Piece p){
	static const bool _ispawnshi[] = 
	{
		    false,  // 这个不用了
			true,  true, true, false, false, false, true,
			false,
			true,  true, true, false, false, false, true,   

			//EMPTY=0,  // 这个不用了
			//RKING=1,  RSHI=2, RXIANG=3, RMA=4, RCHE=5, RPAO=6, RPAWN=7,
			//_X_X =8,
			//BKING=9,  BSHI=10,BXIANG=11,BMA=12,BCHE=13,BPAO=14,BPAWN=15,  
	};

	return _ispawnshi[p];
}



inline Color color_of(Piece p) {
	return _piece_color[p];
}


inline bool piece_type_is_ok(PieceType pc) {
	return pc >= KING && pc <= PAWN;
}

inline bool piece_is_ok(Piece pc) {
	return pc >= RKING && pc <= BPAWN;
}

inline Value mate_in(int ply) {
	return VALUE_MATE - ply;  // return Value(VALUE_MATE - Value(ply));
}

inline Value mated_in(int ply) {
	return -VALUE_MATE + ply; // return Value(-VALUE_MATE + Value(ply));
}

#ifdef REPEAT_DEBUG

#else

#pragma warning(disable : 4100)   
// 常将分．　
inline Value value_baned_check_in(int ply) {
	return -VALUE_BAN_CHECK;  // return -VALUE_BAN_CHECK + ply;
}
// 常捉分．
inline Value value_baned_cap_in(int ply) {
	return -VALUE_BAN_CAP;   // return -VALUE_BAN_CAP + ply;	
}

#endif



inline Color operator~(Color c) {
	return Color(c ^ 1);
}

inline bool color_is_ok(Color c) {
	return c == WHITE || c == BLACK;
}

inline Square square_from_string(const std::string& str) {
	return Square((str[0] - 'a') + (('9' - str[1]) * 9));
}



extern uint8 DirectionTable[90][90];

inline Direction direction_between_squares(Square s1, Square s2) {
	return Direction(DirectionTable[s1][s2]);
}

inline bool square_is_ok(Square s) {
	return (s >= 0 && s < 90);
}

#define PB90(sq) (POSITION.piece_on(Square(sq)))

extern uint8 Relative_rank90[2][90];

// 相对rank
inline int relative_rank(Color c, Square s) {
	//return relative_rank(c, rank_of(s));
	return Relative_rank90[c][s];
}

// 
struct CPUINFO {
	char CPUString[0x20];
	char CPUBrandString[0x40];
	int CPUInfo[4];
	int nSteppingID;
	int nModel;
	int nFamily;
	int nProcessorType;
	int nExtendedmodel;
	int nExtendedfamily;
	int nBrandIndex;
	int nCLFLUSHcachelinesize;
	int nLogicalProcessors;
	int nAPICPhysicalID;
	int nFeatureInfo;
	int nCacheLineSize;
	int nL2Associativity;
	int nCacheSizeK;
	int nPhysicalAddress;
	int nVirtualAddress;
	int nRet;

	int nCores;
	int nCacheType;
	int nCacheLevel;
	int nMaxThread;
	int nSysLineSize;
	int nPhysicalLinePartitions;
	int nWaysAssociativity;
	int nNumberSets;

	unsigned    nIds, nExIds, i;

	bool    bSSE3Instructions;
	bool    bMONITOR_MWAIT;
	bool    bCPLQualifiedDebugStore;
	bool    bVirtualMachineExtensions;
	bool    bEnhancedIntelSpeedStepTechnology;
	bool    bThermalMonitor2;
	bool    bSupplementalSSE3;
	bool    bL1ContextID;
	bool    bCMPXCHG16B;
	bool    bxTPRUpdateControl;
	bool    bPerfDebugCapabilityMSR;
	bool    bSSE41Extensions;
	bool    bSSE42Extensions;
	bool    bPOPCNT;

	bool    bMultithreading;

	bool    bLAHF_SAHFAvailable;
	bool    bCmpLegacy;
	bool    bSVM;
	bool    bExtApicSpace;
	bool    bAltMovCr8;
	bool    bLZCNT;
	bool    bSSE4A;
	bool    bMisalignedSSE;
	bool    bPREFETCH;
	bool    bSKINITandDEV;
	bool    bSYSCALL_SYSRETAvailable;
	bool    bExecuteDisableBitAvailable;
	bool    bMMXExtensions;
	bool    bFFXSR;
	bool    b1GBSupport;
	bool    bRDTSCP;
	bool    b64Available;
	bool    b3DNowExt;
	bool    b3DNow;
	bool    bNestedPaging;
	bool    bLBRVisualization;
	bool    bFP128;
	bool    bMOVOptimization;

	bool    bSelfInit;
	bool    bFullyAssociative;
};


#endif
#if !defined(SS_TYPES_H_INCLUDEDs)
#define SS_TYPES_H_INCLUDEDs

#include "limits.h"
#include <cstdlib>
#include <string>

#include "platform.h"
#include "define.h"
#include "my_const.h"

/// When compiling with provided Makefile (e.g. for Linux and OSX), configuration
/// is done automatically. To get started type 'make help'.
///
/// When Makefile is not used (e.g. with Microsoft Visual Studio) some switches
/// need to be set manually:
///
/// -DNDEBUG      | Disable debugging mode. Always use this for release.
///
/// -DNO_PREFETCH | Disable use of prefetch asm-instruction. You may need this to
///               | run on some very old machines.
///
/// -DUSE_POPCNT  | Add runtime support for use of popcnt asm-instruction. Works
///               | only in 64-bit mode and requires hardware with popcnt support.
///
/// -DUSE_PEXT    | Add runtime support for use of pext asm-instruction. Works
///               | only in 64-bit mode and requires hardware with pext support.











#include <cassert>
#include <cctype>
#include <cstdint>
#include <cstdlib>
#include <algorithm>

#if defined(_MSC_VER)
// Disable some silly and noisy warning from MSVC compiler
#pragma warning(disable: 4127) // Conditional expression is constant
#pragma warning(disable: 4146) // Unary minus operator applied to unsigned type
#pragma warning(disable: 4800) // Forcing value to bool 'true' or 'false'
#endif

/// Predefined macros hell:
///
/// __GNUC__           Compiler is gcc, Clang or Intel on Linux
/// __INTEL_COMPILER   Compiler is Intel
/// _MSC_VER           Compiler is MSVC or Intel on Windows
/// _WIN32             Building on Windows (any)
/// _WIN64             Building on Windows 64 bit

#if defined(__GNUC__ ) && (__GNUC__ < 9 || (__GNUC__ == 9 && __GNUC_MINOR__ <= 2)) && defined(_WIN32) && !defined(__clang__)
#define ALIGNAS_ON_STACK_VARIABLES_BROKEN
#endif

#define ASSERT_ALIGNED(ptr, alignment) assert(reinterpret_cast<uintptr_t>(ptr) % alignment == 0)

#if defined(_WIN64) && defined(_MSC_VER) // No Makefile used
#  include <intrin.h> // Microsoft header for _BitScanForward64()
#  define IS_64BIT
#endif

#if defined(USE_POPCNT) && (defined(__INTEL_COMPILER) || defined(_MSC_VER))
#  include <nmmintrin.h> // Intel and Microsoft header for _mm_popcnt_u64()
#endif

#if !defined(NO_PREFETCH) && (defined(__INTEL_COMPILER) || defined(_MSC_VER))
#  include <xmmintrin.h> // Intel and Microsoft header for _mm_prefetch()
#endif

#if defined(USE_PEXT)
#  include <immintrin.h> // Header for _pext_u64() intrinsic
#  define pext(b, m) _pext_u64(b, m)
#else
#  define pext(b, m) 0
#endif

#ifdef USE_POPCNT
constexpr bool HasPopCnt = true;
#else
constexpr bool HasPopCnt = false;
#endif

#ifdef USE_PEXT
constexpr bool HasPext = true;
#else
constexpr bool HasPext = false;
#endif

#ifdef IS_64BIT
constexpr bool Is64Bit = true;
#else
constexpr bool Is64Bit = false;
#endif

typedef uint64_t Key;
//typedef uint64_t Bitboard;

constexpr int MAX_MOVES = 256;
constexpr int MAX_PLY = 246;

/// cpu_has_popcnt() detects support for popcnt instruction at runtime
//inline bool cpu_has_popcnt() {
//
//	int CPUInfo[4] = {-1};
//	__cpuid(CPUInfo, 0x00000001);
//	return (CPUInfo[2] >> 23) & 1;
//}





enum Move : int {
	MOVE_NONE = 0,
	MOVE_NULL = 0x0101
};

//enum MoveType {
//	NORMAL,
//	PROMOTION = 1 << 14,
//	EN_PASSANT = 2 << 14,
//	CASTLING = 3 << 14
//};

enum Color {
	WHITE,	BLACK, COLOR_NB = 2
};

//enum CastlingRights {
//	NO_CASTLING,
//	WHITE_OO,
//	WHITE_OOO = WHITE_OO << 1,
//	BLACK_OO = WHITE_OO << 2,
//	BLACK_OOO = WHITE_OO << 3,
//
//	KING_SIDE = WHITE_OO | BLACK_OO,
//	QUEEN_SIDE = WHITE_OOO | BLACK_OOO,
//	WHITE_CASTLING = WHITE_OO | WHITE_OOO,
//	BLACK_CASTLING = BLACK_OO | BLACK_OOO,
//	ANY_CASTLING = WHITE_CASTLING | BLACK_CASTLING,
//
//	CASTLING_RIGHT_NB = 16
//};

enum Phase {
	PHASE_ENDGAME = 0,
	PHASE_MIDGAME = 128,
	MG = 0, EG = 1, PHASE_NB = 2
};

enum ScaleFactor {
	SCALE_FACTOR_DRAW = 0,
	SCALE_FACTOR_NORMAL = 64,
	SCALE_FACTOR_MAX = 128,
	SCALE_FACTOR_NONE = 255
};

enum Bound {
	BOUND_NONE,
	BOUND_UPPER,
	BOUND_LOWER,
	BOUND_EXACT = BOUND_UPPER | BOUND_LOWER
};

enum Value : int {
	VALUE_ZERO = 0,
	VALUE_DRAW = 0,
	VALUE_KNOWN_WIN = 10000,
	VALUE_MATE = 32000,
	VALUE_INFINITE = 32001,
	VALUE_NONE = 32002,

	VALUE_TB_WIN_IN_MAX_PLY = VALUE_MATE - 2 * MAX_PLY,
	VALUE_TB_LOSS_IN_MAX_PLY = -VALUE_TB_WIN_IN_MAX_PLY,
	VALUE_MATE_IN_MAX_PLY = VALUE_MATE - MAX_PLY,
	VALUE_MATED_IN_MAX_PLY = -VALUE_MATE_IN_MAX_PLY,

	KING_VAL = 10000, SHI_VAL = 135, XIANG_VAL = 145,
	CHE_VAL = 980, MA_VAL = 400, PAO_VAL = 400, PAWN_VAL = 100,
	PawnValueMidgame = 80,
	PawnValueEndgame = 128, 
	Tempo = 28,

	MidgameLimit = 15258, EndgameLimit = 3915
};


enum PieceType {
	NO_PIECE_TYPE = 0,	KING = 1, SHI = 2, XIANG = 3, MA = 4, CHE = 5, PAO = 6, PAWN = 7,
	ALL_PIECES = 0,
	PIECE_TYPE_NB = 8
};

enum Piece {
	NO_PIECE = 0,  
	RKING = 1, RSHI = 2, RXIANG = 3, RMA = 4, RCHE = 5, RPAO = 6, RPAWN = 7,	_X_X = 8,
	BKING = 9, BSHI = 10, BXIANG = 11, BMA = 12, BCHE = 13, BPAO = 14, BPAWN = 15,
	PIECE_NB = 16
};

//constexpr Value PieceValue[PHASE_NB][PIECE_NB] = {
//  { VALUE_ZERO, PawnValueMg, KnightValueMg, BishopValueMg, RookValueMg, QueenValueMg, VALUE_ZERO, VALUE_ZERO,
//	VALUE_ZERO, PawnValueMg, KnightValueMg, BishopValueMg, RookValueMg, QueenValueMg, VALUE_ZERO, VALUE_ZERO },
//  { VALUE_ZERO, PawnValueEg, KnightValueEg, BishopValueEg, RookValueEg, QueenValueEg, VALUE_ZERO, VALUE_ZERO,
//	VALUE_ZERO, PawnValueEg, KnightValueEg, BishopValueEg, RookValueEg, QueenValueEg, VALUE_ZERO, VALUE_ZERO }
//};

typedef int Depth;

enum : int {
	DEPTH_QS_CHECKS = 0,
	DEPTH_QS_NO_CHECKS = -1,
	DEPTH_QS_RECAPTURES = -5,

	DEPTH_NONE = -6,

	DEPTH_OFFSET = -7 // value used only for TT entry occupancy check
};

enum Square {
	//SQ_A1, SQ_B1, SQ_C1, SQ_D1, SQ_E1, SQ_F1, SQ_G1, SQ_H1,
	//SQ_A2, SQ_B2, SQ_C2, SQ_D2, SQ_E2, SQ_F2, SQ_G2, SQ_H2,
	//SQ_A3, SQ_B3, SQ_C3, SQ_D3, SQ_E3, SQ_F3, SQ_G3, SQ_H3,
	//SQ_A4, SQ_B4, SQ_C4, SQ_D4, SQ_E4, SQ_F4, SQ_G4, SQ_H4,
	//SQ_A5, SQ_B5, SQ_C5, SQ_D5, SQ_E5, SQ_F5, SQ_G5, SQ_H5,
	//SQ_A6, SQ_B6, SQ_C6, SQ_D6, SQ_E6, SQ_F6, SQ_G6, SQ_H6,
	//SQ_A7, SQ_B7, SQ_C7, SQ_D7, SQ_E7, SQ_F7, SQ_G7, SQ_H7,
	//SQ_A8, SQ_B8, SQ_C8, SQ_D8, SQ_E8, SQ_F8, SQ_G8, SQ_H8,
	//SQ_NONE,

	SQ_START = 0,
	SQ_END90 = 90
};

enum Direction {
	DIR_左右 = 0, 
	DIR_上下 = 1, 
	DIR_马 = 2, 
	DIR_相 = 3, 
	DIR_仕 = 4, 
	DIR_NONE = 5,
};




//enum File : int {
//	FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NB
//};
//
//enum Rank : int {
//	RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NB
//};

// Keep track of what a move changes on the board (used by NNUE)
struct DirtyPiece {

	// Number of changed pieces
	int dirty_num;

	// Max 3 pieces can change in one move. A promotion with capture moves
	// both the pawn and the captured piece to SQ_NONE and the piece promoted
	// to from SQ_NONE to the capture square.
	Piece piece[3];

	// From and to squares, which may be SQ_NONE
	Square from[3];
	Square to[3];
};

/// Score enum stores a middlegame and an endgame value in a single integer (enum).
/// The least significant 16 bits are used to store the middlegame value and the
/// upper 16 bits are used to store the endgame value. We have to take care to
/// avoid left-shifting a signed int to avoid undefined behavior.
enum Score : int { SCORE_ZERO };

constexpr Score make_score(int mg, int eg) {
	return Score((int)((unsigned int)eg << 16) + mg);
}

/// Extracting the signed lower and upper 16 bits is not so trivial because
/// according to the standard a simple cast to short is implementation defined
/// and so is a right shift of a signed integer.
inline Value eg_value(Score s) {
	union { uint16_t u; int16_t s; } eg = { uint16_t(unsigned(s + 0x8000) >> 16) };
	return Value(eg.s);
}

inline Value mg_value(Score s) {
	union { uint16_t u; int16_t s; } mg = { uint16_t(unsigned(s)) };
	return Value(mg.s);
}

#define ENABLE_BASE_OPERATORS_ON(T)                                \
constexpr T operator+(T d1, int d2) { return T(int(d1) + d2); }    \
constexpr T operator-(T d1, int d2) { return T(int(d1) - d2); }    \
constexpr T operator-(T d) { return T(-int(d)); }                  \
inline T& operator+=(T& d1, int d2) { return d1 = d1 + d2; }       \
inline T& operator-=(T& d1, int d2) { return d1 = d1 - d2; }

#define ENABLE_INCR_OPERATORS_ON(T)                                \
inline T& operator++(T& d) { return d = T(int(d) + 1); }           \
inline T& operator--(T& d) { return d = T(int(d) - 1); }

#define ENABLE_FULL_OPERATORS_ON(T)                                \
ENABLE_BASE_OPERATORS_ON(T)                                        \
constexpr T operator*(int i, T d) { return T(i * int(d)); }        \
constexpr T operator*(T d, int i) { return T(int(d) * i); }        \
constexpr T operator/(T d, int i) { return T(int(d) / i); }        \
constexpr int operator/(T d1, T d2) { return int(d1) / int(d2); }  \
inline T& operator*=(T& d, int i) { return d = T(int(d) * i); }    \
inline T& operator/=(T& d, int i) { return d = T(int(d) / i); }

ENABLE_FULL_OPERATORS_ON(Value)
ENABLE_FULL_OPERATORS_ON(Direction)

ENABLE_INCR_OPERATORS_ON(Piece)
ENABLE_INCR_OPERATORS_ON(PieceType)
ENABLE_INCR_OPERATORS_ON(Square)
//ENABLE_INCR_OPERATORS_ON(File)
//ENABLE_INCR_OPERATORS_ON(Rank)

ENABLE_BASE_OPERATORS_ON(Score)

#undef ENABLE_FULL_OPERATORS_ON
#undef ENABLE_INCR_OPERATORS_ON
#undef ENABLE_BASE_OPERATORS_ON

/// Additional operators to add a Direction to a Square
constexpr Square operator+(Square s, Direction d) { return Square(int(s) + int(d)); }
constexpr Square operator-(Square s, Direction d) { return Square(int(s) - int(d)); }
inline Square& operator+=(Square& s, Direction d) { return s = s + d; }
inline Square& operator-=(Square& s, Direction d) { return s = s - d; }

/// Only declared but not defined. We don't want to multiply two scores due to
/// a very high risk of overflow. So user should explicitly convert to integer.
Score operator*(Score, Score) = delete;

/// Division of a Score must be handled separately for each term
inline Score operator/(Score s, int i) {
	return make_score(mg_value(s) / i, eg_value(s) / i);
}

/// Multiplication of a Score by an integer. We check for overflow in debug mode.
inline Score operator*(Score s, int i) {

	Score result = Score(int(s) * i);

	assert(eg_value(result) == (i * eg_value(s)));
	assert(mg_value(result) == (i * mg_value(s)));
	assert((i == 0) || (result / i) == s);

	return result;
}

/// Multiplication of a Score by a boolean
inline Score operator*(Score s, bool b) {
	return b ? s : SCORE_ZERO;
}

constexpr Color operator~(Color c) {
	return Color(c ^ BLACK); // Toggle color
}

inline bool color_is_ok(Color c) {
	return c == WHITE || c == BLACK;
}

//
//constexpr Square flip_rank(Square s) { // Swap A1 <-> A8
//	return Square(s ^ SQ_A8);
//}
//
//constexpr Square flip_file(Square s) { // Swap A1 <-> H1
//	return Square(s ^ SQ_H1);
//}

constexpr Piece operator~(Piece pc) {
	return Piece(pc ^ 8); // Swap color of piece B_KNIGHT <-> W_KNIGHT
}

//constexpr CastlingRights operator&(Color c, CastlingRights cr) {
//	return CastlingRights((c == WHITE ? WHITE_CASTLING : BLACK_CASTLING) & cr);
//}

constexpr Value mate_in(int ply) {
	return VALUE_MATE - ply;
}

constexpr Value mated_in(int ply) {
	return -VALUE_MATE + ply;
}

//constexpr Square make_square(File f, Rank r) {
//	return Square((r << 3) + f);
//}

//constexpr Piece make_piece(Color c, PieceType pt) {
//	return Piece((c << 3) + pt);
//}

constexpr PieceType type_of(Piece pc) {
	return PieceType(pc & 7);
}

inline Color color_of(Piece pc) {
	assert(pc != NO_PIECE);
	return Color(pc >> 3);
}

constexpr bool is_ok(Square s) {
	return s >= 0 && s <= 89;
}

//constexpr File file_of(Square s) {
//	return File(s & 7);
//}
//
//constexpr Rank rank_of(Square s) {
//	return Rank(s >> 3);
//}

//constexpr Square relative_square(Color c, Square s) {
//	return Square(s ^ (c * 56));
//}

//constexpr Rank relative_rank(Color c, Rank r) {
//	return Rank(r ^ (c * 7));
//}
//
//constexpr Rank relative_rank(Color c, Square s) {
//	return relative_rank(c, rank_of(s));
//}

//constexpr Direction pawn_push(Color c) {
//	return c == WHITE ? NORTH : SOUTH;
//}

constexpr Square from_sq(Move m) {
	return Square(((m) >> MOVE_BIT) & MOVE_MASK);
}

constexpr Square to_sq(Move m) {
	return Square(m & MOVE_MASK);
}

constexpr int from_to(Move m) {
	return m & 0xFFFF;
}

//constexpr MoveType type_of(Move m) {
//	return MoveType(m & (3 << 14));
//}

//constexpr PieceType promotion_type(Move m) {
//	return PieceType(((m >> 12) & 3) + KNIGHT);
//}

constexpr Move make_move(Square from, Square to) {
	return Move(to | (from << MOVE_BIT));
}

constexpr Move reverse_move(Move m) {
	return make_move(to_sq(m), from_sq(m));
}

//template<MoveType T>
//constexpr Move make(Square from, Square to, PieceType pt = KNIGHT) {
//	return Move(T + ((pt - KNIGHT) << 12) + (from << 6) + to);
//}

constexpr bool is_ok(Move m) {
	return from_sq(m) != to_sq(m); // Catch MOVE_NULL and MOVE_NONE
}

/// Based on a congruential pseudo random number generator
constexpr Key make_key(uint64_t seed) {
	return seed * 6364136223846793005ULL + 1442695040888963407ULL;
}

constexpr Value PieceValueMidgame[16] = {
	VALUE_ZERO, 
	VALUE_ZERO, SHI_VAL, XIANG_VAL, MA_VAL, CHE_VAL, PAO_VAL, PawnValueMidgame,
	VALUE_ZERO, 
	VALUE_ZERO, SHI_VAL, XIANG_VAL, MA_VAL, CHE_VAL, PAO_VAL, PawnValueMidgame,
};
constexpr Value PieceValueEndgame[16] = {
	VALUE_ZERO, 
	VALUE_ZERO, SHI_VAL, XIANG_VAL, MA_VAL, CHE_VAL, PAO_VAL, PawnValueEndgame,
	VALUE_ZERO, 
	VALUE_ZERO, SHI_VAL, XIANG_VAL, MA_VAL, CHE_VAL, PAO_VAL, PawnValueEndgame,
};


constexpr Color _piece_color[16] = {
	COLOR_NB,
	WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,
	COLOR_NB,
	BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,
};

constexpr uint8 revertChess[] = {
	NO_PIECE,
	BKING, BSHI, BXIANG, BMA, BCHE, BPAO, BPAWN,
	_X_X,
	RKING, RSHI, RXIANG, RMA, RCHE, RPAO, RPAWN,
};

constexpr bool ChessCanDirectCheck[] = {

	false,  // 这个不用了
	false, false, false, true, true, true, true,
	false,
	false, false, false, true, true, true, true,
};


// 棋子是不是兵或仕
inline bool isPawnShiXiangKing(Piece p){
	static const bool _ispawnshi[] = 
	{
		    false,  // 这个不用了
			true,  true, true, false, false, false, true,
			false,
			true,  true, true, false, false, false, true,   

			//EM=0,  // 这个不用了
			//RKING=1,  RSHI=2, RXIANG=3, RMA=4, RCHE=5, RPAO=6, RPAWN=7,
			//_X_X =8,
			//BKING=9,  BSHI=10,BXIANG=11,BMA=12,BCHE=13,BPAO=14,BPAWN=15,  
	};
	return _ispawnshi[p];
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

#if defined(_MSC_VER)
#define FORCE_INLINE  __forceinline
#elif defined(__GNUC__)
#define FORCE_INLINE  inline __attribute__((always_inline))
#else
#define FORCE_INLINE  inline
#endif


#endif

#include "tune.h" // Global visibility to tuning setup

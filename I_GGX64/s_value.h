#if !defined(VALUE_H_INCLUDED)
#define VALUE_H_INCLUDED

////
//// Includes
////

#include "s_piece.h"















////
//// Types
////

enum ValueType {
	VALUE_TYPE_NONE  = 0,
	VALUE_TYPE_UPPER = 1,  // Upper bound
	VALUE_TYPE_LOWER = 2,  // Lower bound
	VALUE_TYPE_EXACT = VALUE_TYPE_UPPER | VALUE_TYPE_LOWER
};


enum Value {
	VALUE_ZERO      = 0,
	VALUE_DRAW      = -1,
	VALUE_KNOWN_WIN = 15000,
	//VALUE_BAN       = 29000,         //　常捉，常将的分数
	VALUE_BAN_CHECK = 28500,           // 29500,
	//VALUE_BAN_CAP   = 28000,
	VALUE_MATE      = 30000,
	VALUE_INFINITE  = 30001,
	VALUE_NONE      = 30002,
	VALUE_B_ONE     = 1,
	VALUE_W_ONE     = -1,
	VALUE_ENSURE_SIGNED = -1
};

ENABLE_OPERATORS_ON(Value);

/// Score enum keeps a midgame and an endgame value in a single
/// integer (enum), first LSB 16 bits are used to store endgame
/// value, while upper bits are used for midgame value.

// Compiler is free to choose the enum type as long as can keep
// its data, so ensure Score to be an integer type.
enum Score {
	SCORE_ZERO = 0,
	SCORE_ENSURE_32_BITS_SIZE_P =  (1 << 16),
	SCORE_ENSURE_32_BITS_SIZE_N = -(1 << 16)
};

//ENABLE_OPERATORS_ON(Score);


// Extracting the _signed_ lower and upper 16 bits it not so trivial
// because according to the standard a simple cast to short is
// implementation defined and so is a right shift of a signed integer.
inline Value mg_value(Score s) { return Value(((int(s) + 32768) & ~0xffff) / 0x10000); }

// Unfortunatly on Intel 64 bit we have a small speed regression, so use a faster code in
// this case, although not 100% standard compliant it seems to work for Intel and MSVC.
#if defined(IS_64BIT) && (!defined(__GNUC__) || defined(__INTEL_COMPILER))
inline Value eg_value(Score s) { return Value(sint16(s & 0xffff)); }
#else
inline Value eg_value(Score s) { return Value((int)(unsigned(s) & 0x7fffu) - (int)(unsigned(s) & 0x8000u)); }
#endif

inline Score make_score(int mg, int eg) { return Score((mg << 16) + eg); }

inline Score operator-(Score s) { return Score(-int(s)); }
inline Score operator+(Score s1, Score s2) { return Score(int(s1) + int(s2)); }
inline Score operator-(Score s1, Score s2) { return Score(int(s1) - int(s2)); }
inline void operator+=(Score& s1, Score s2) { s1 = Score(int(s1) + int(s2)); }
inline void operator-=(Score& s1, Score s2) { s1 = Score(int(s1) - int(s2)); }
inline Score operator*(int i, Score s) { return Score(i * int(s)); }

// Division must be handled separately for each term
inline Score operator/(Score s, int i) { return make_score(mg_value(s) / i, eg_value(s) / i); }


// Only declared but not defined. We don't want to multiply two scores due to
// a very high risk of overflow. So user should explicitly convert to integer.
inline Score operator*(Score s1, Score s2);


////
//// Constants and variables
////

/// Piece values, middle game and endgame

/// Important: If the material values are changed, one must also
/// adjust the piece square tables, and the method game_phase() in the
/// Position class!
///
/// Values modified by Joona Kiiski

//const Value PawnValueMidgame   = Value(80);   // was Value(0x0C6);
//const Value PawnValueEndgame   = Value(128);  // was Value(0x0C6);

const Value KING_VAL           = Value(10000); //     10000
const Value SHI_VAL            = Value(145);   //     145         //170
const Value XIANG_VAL          = Value(135);   //      125         //160
const Value CHE_VAL            = Value(950);   //      950         //1000
const Value MA_VAL             = Value(400);   //       400         //400
const Value PAO_VAL            = Value(400);   //       400         //400
const Value PAWN_VAL           = Value(100);   //       100         //100


const Value PawnValueMidgame  = Value(80);
const Value PawnValueEndgame  = Value(120);

//const Value RookValueMidgame   = Value(950);
//const Value RookValueEndgame   = Value(1050); 

const Value PieceValueMidgame[16] = {
	Value(0), 
	Value(0), SHI_VAL, XIANG_VAL, MA_VAL, CHE_VAL, PAO_VAL, PAWN_VAL,
	Value(0), 
	Value(0), SHI_VAL, XIANG_VAL, MA_VAL, CHE_VAL, PAO_VAL, PAWN_VAL,
};
const Value PieceValueEndgame[16] = {
	Value(0), 
	Value(0), SHI_VAL, XIANG_VAL, MA_VAL, CHE_VAL, PAO_VAL, PAWN_VAL,
	Value(0), 
	Value(0), SHI_VAL, XIANG_VAL, MA_VAL, CHE_VAL, PAO_VAL, PAWN_VAL,
};


//const Value PawnValueMidgame   = Value(0x0C6);
//const Value PawnValueEndgame   = Value(0x102);
//const Value KnightValueMidgame = Value(0x331);
//const Value KnightValueEndgame = Value(0x34E);
//const Value BishopValueMidgame = Value(0x344);
//const Value BishopValueEndgame = Value(0x359);
//const Value RookValueMidgame   = Value(0x4F6);
//const Value RookValueEndgame   = Value(0x4FE);
//const Value QueenValueMidgame  = Value(0x9D9);
//const Value QueenValueEndgame  = Value(0x9FE);

//const Value PieceValueMidgame[17] = {
//	Value(0),
//	PawnValueMidgame, KnightValueMidgame, BishopValueMidgame,
//	RookValueMidgame, QueenValueMidgame,
//	Value(0), Value(0), Value(0),
//	PawnValueMidgame, KnightValueMidgame, BishopValueMidgame,
//	RookValueMidgame, QueenValueMidgame,
//	Value(0), Value(0), Value(0)
//};
//
//const Value PieceValueEndgame[17] = {
//	Value(0),
//	PawnValueEndgame, KnightValueEndgame, BishopValueEndgame,
//	RookValueEndgame, QueenValueEndgame,
//	Value(0), Value(0), Value(0),
//	PawnValueEndgame, KnightValueEndgame, BishopValueEndgame,
//	RookValueEndgame, QueenValueEndgame,
//	Value(0), Value(0), Value(0)
//};

/// Bonus for having the side to move (modified by Joona Kiiski)

const Score TempoValue = make_score(32, 10);  // make_score(48, 22);


////
//// Inline functions
////

inline Value operator+ (Value v, int i) { return Value(int(v) + i); }
inline Value operator- (Value v, int i) { return Value(int(v) - i); }
inline Value operator-- (Value& d, int) { d = Value(int(d) - 1); return d; }

inline Value value_mate_in(int ply) {
	return Value(VALUE_MATE - Value(ply));
}

inline Value value_mated_in(int ply) {
	return Value(-VALUE_MATE + Value(ply));
}

// 常将分．　
inline Value value_baned_check_in(int ply) {
	return Value(-VALUE_BAN_CHECK + Value(ply));
	//return -VALUE_BAN;
}

inline Value value_ban_check_in(int ply) {
	return Value(VALUE_BAN_CHECK - Value(ply));
	//return VALUE_BAN;
}
//常捉的分
//inline Value value_baned_cap_in(int ply) {
//	return Value(-VALUE_BAN_CAP + Value(ply));
//	//return -VALUE_BAN;
//}
//
//inline Value value_ban_cap_in(int ply) {
//	return Value(VALUE_BAN_CAP - Value(ply));
//	//return VALUE_BAN;
//}

//
//inline bool is_upper_bound(ValueType vt) {
//	return (int(vt) & int(VALUE_TYPE_UPPER)) != 0;
//}
//
//inline bool is_lower_bound(ValueType vt) {
//	return (int(vt) & int(VALUE_TYPE_LOWER)) != 0;
//}

inline Value piece_value_midgame(Piece p) {
	return PieceValueMidgame[p];
}

inline Value piece_value_endgame(Piece p) {
	return PieceValueEndgame[p];
}

//inline Value piece_value_midgame(PieceType pt) {
//	return PieceValueMidgame[pt];
//}
//
//inline Value piece_value_endgame(PieceType pt) {
//	return PieceValueEndgame[pt];
//}
//
//inline Value piece_value_midgame(Piece p) {
//	return PieceValueMidgame[p];
//}
//
//inline Value piece_value_endgame(Piece p) {
//	return PieceValueEndgame[p];
//}


////
//// Prototypes
////

//extern Value value_to_tt(Value v, int ply);
//extern Value value_from_tt(Value v, int ply);
extern int value_to_centipawns(Value v);
extern Value value_from_centipawns(int cp);
//extern const std::string value_to_uci(Value v);


#endif // !defined(VALUE_H_INCLUDED)

#if !defined(EVVALL_H_INCLUDED)
#define EVVALL_H_INCLUDED

#include "eval_const.h"
#include "pawns.h"
#include "VMP.h"
class Position;

struct EvalInfo {

	Bitboard attackedBy[16];	         // 
	Bitboard attackKingBoard[2];
	Bitboard KongPao[2];                 // 二个空炮
	Bitboard xray_bit[2];                // 这个还是需要的. 可判断这个子能不能走哇.
	Pawns::Entry* pi;                    // 兵的信息，包括仕哇
	sint8 rcan;
	sint8 bcan;
	sint16 attPoint[2];                  // 合计的攻击数
	sint16 evscore;	
	uint8 rsafe;
	uint8 bsafe;
	uint8 mul;
	uint8 dummy;

#ifdef CAN_OUT_EVAL_INFO
	Value kingDanger[2];	
#endif

	Bitboard attacked_by(Color c)  { return attackedBy[COLOR_BY_SIDE_ADD[c]]; }
	Bitboard attacked_by(Piece pc) { ASSERT(pc != RSHI && pc != RPAWN && pc != BSHI && pc != BPAWN);
		return attackedBy[pc]; }

};


// Evaluation weights, initialized from UCI options
extern Score WeightMobility, WeightPawnStructure;
extern Score WeightPassedPawns, WeightSpace;
extern Score WeightKingSafety[2];

//////////////////////////////////////////////////////////////////////////
/// point(opening,endgame) (((opening) << 16) + (endgame))
static const  Score LackXiangAttackByCheMaPoint[] = {
	Score(((0) << 0) + (0)), Score(((24) << 16) + (64)), Score(((32) << 16) + (80))
};
//////////////////////////////////////////////////////////////////////////
// 如果有兵，还要加分
static const  Score LackXiangAttackByCheMaPawnPoint =  Score(((16) << 16) + (48));


extern void eval_white_pawn_can(Position& pos, EvalInfo& ei);
extern void eval_black_pawn_can(Position& pos, EvalInfo& ei);

extern Value scale_by_game_phase(Position& pos, EvalInfo& ei, const Score& v);

//////////////////////////////////////////////////////////////////////////
/// 
//template<Color Us>
//extern void evaluate_king_first(Position& pos, EvalInfo& ei);


//////////////////////////////////////////////////////////////////////////
///
template<Color Us>
extern Score evaluate_pieces_no_include_king_first(Position& pos, EvalInfo& ei);


//////////////////////////////////////////////////////////////////////////
///
template<Color Us>
extern Score evaluate_pieces_no_include_king_first(Position& pos, EvalInfo& ei);


//////////////////////////////////////////////////////////////////////////
/// 炮的第二将评估
template<Color Us>
extern Score evaluate_pao_che_ma_pawn_second(Position& pos, EvalInfo& ei);


//////////////////////////////////////////////////////////////////////////
/// 
template<Color Us>
extern Score eval_weak_piece(Position& pos, EvalInfo& ei);

//////////////////////////////////////////////////////////////////////////
///
template<Color Us>
extern Score eval_wo_xing_ma(Position& pos, EvalInfo& ei);

//////////////////////////////////////////////////////////////////////////
///
template<Color Us>
extern Score eval_lack_shi_xiang(Position& pos, EvalInfo& ei);

//////////////////////////////////////////////////////////////////////////
/// 中炮,底炮,
template<Color Us>
extern Score eval_zhong_di_pao(Position& pos, EvalInfo& ei);




//////////////////////////////////////////////////////////////////////////
///
template<Color Us>
Score eval_Only_1Che1PaoxPawn(Position& pos, EvalInfo& ei);

//////////////////////////////////////////////////////////////////////////
///
template<Color Us>
Score eval_Only_1chexPaoxPawnNoshi(Position& pos, EvalInfo& ei);

////////////////////////////////////////////////////////////////////////////
/////
//template<Color Us>
//Score eval_PawnCan_MustADD_by_att(const Position& pos, EvalInfo& ei);

//////////////////////////////////////////////////////////////////////////
/// 空中炮, 空底炮
template<Color Us>
extern Score eval_kong_zhong_di_pao(Position& pos, EvalInfo& ei);

//////////////////////////////////////////////////////////////////////////
///
template<Color Us>
extern Score eval_king_safe(Position& pos, EvalInfo& ei, Value& margin);

//////////////////////////////////////////////////////////////////////////
/// 闷宫威胁的评估
extern Score eval_men_gong_threat(Position& pos, EvalInfo& ei);


namespace Eval {

const Value Tempo = Value(17); // Must be visible to search

void init();
Value evaluate(Position& pos);
Value do_evaluate(Position& pos);
}



//#ifdef DEBUG_EVAL_OPP_SIDE_IS_SAME
//extern Value evaluate_debug(const Position& pos, EvalInfo& ei);
//#endif

#endif
#include "eval_total.h"

//////////////////////////////////////////////////////////////////////////
////
template<Color Us>
Score eval_Only_1chexPaoxPawnNoshi(Position& pos, EvalInfo& ei){

	Score bonus = SCORE_ZERO;

	// fen 6b2/3ka4/R8/p3p4/2p1r4/6B2/P2C2cCP/5p3/9/3K2B2 b - - 0 1
	//const Piece delt = COLOR_BY_SIDE_ADD[Us];
	const Color Them = (Us == WHITE ? BLACK : WHITE);

	//if(ei.att_pawn_num[Us] >= 1){   // 我方也有兵过河了。
	//	return bonus;
	//}

	if(have_bit(ei.attackKingBoard[Us],Us == WHITE ? pos.pieces(RPAWN) : pos.pieces(BPAWN))){
		return bonus;
	}

	int yalr = PawnOverRiver<Them>(pos,ei);

	bonus -= yalr * make_score(16,32);

	// 如果对方有兵在攻击了，就要加分。
	//if(yalr >= 1){
	//	Bitboard byp = m_and(pos.pieces(BPAWN - delt), Us == WHITE ? 
	//}
	if(yalr >= 1){
		//bonus -= int((ei.att_pawn_num[Them]+1)/2) * make_score(32,64);
		bonus -= count_1s(ei.attackKingBoard[Them],Us == WHITE ? pos.pieces(BPAWN) : pos.pieces(RPAWN)) * make_score(32,64);
	}

	return bonus;
}
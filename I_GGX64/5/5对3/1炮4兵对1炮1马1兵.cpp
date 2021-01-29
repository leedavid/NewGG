#ifndef END_my_m_MT_R_1pao4pawn_B_1pao1ma1pawn
#define END_my_m_MT_R_1pao4pawn_B_1pao1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1炮4兵对1炮1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 
#pragma warning(disable : 4100) 
void my_m_MT_R_1pao4pawn_B_1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){	

	// fen 4ka3/4an3/8b/3P3P1/8P/4p4/P8/c4A3/3C5/4KAB2 b - - 0 1
	//Square yma = S90_from_piecelist(POSITION,your_ma,0);
	//Square mk  = my_king_pos;

	//if((my_shi_num + my_xiang_num) >= 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
	//	if(EV_MY_CAN >= 3 && StoY(yma) MY_SMALL_EQL MY_RANK1){
	//		Bitboard ymAtt = _mm_andnot_si128(
	//			m_or(MyUpBB[MY_RANK1],ei.pi->pawnshi_attacks(MY_COLOR)),ei.attacked_by(your_ma));

	//		if(!m_have_bit(ymAtt)){
	//			MY_EV_ADD(EV_MY_CAN * 16);
	//		}


	//	}
	//}

}
#ifndef END_my_m_MT_R_2pao_B_2pawn
#define END_my_m_MT_R_2pao_B_2pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "2炮对2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 




void my_m_MT_R_2pao_B_2pawn(typePOS &POSITION, EvalInfo &ei){

	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1PaoXPawn_2Pao_ByPawnShi[my_shi_num]);

	// fen 2b2k3/9/8b/9/9/4C4/5C3/4p4/5K3/3p5 w - - 0 1
	if (my_shi_num == 0 && my_xiang_num == 0){
		if (your_xiang_num == 2){
			if (PB90(MY_SQ43) == your_pawn){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4k4/9/4b4/9/6p1p/C2C5/9/9/9/4KA3 w - - 0 1
	if (my_shi_num <= 1 && my_xiang_num == 0){
		if (your_xiang_num >= 1){
			Bitboard lp = Your_get_connect_Pawn(POSITION);
			if (have_bit(lp, MyUpBB[MY_RANK7])){
				RETRUN_MUL(8);
			}
			if (count_1s(bb_my_pao, RankBB_A[MY_RANK5]) == 2){
				if (PB90(MY_SQ2A) == your_pawn &&  PB90(MY_SQ2C) == your_pawn){
					RETRUN_MUL(8);
				}
				if (PB90(MY_SQ24) == your_pawn &&  PB90(MY_SQ26) == your_pawn){
					RETRUN_MUL(8);
				}
			}
		}
	}




}


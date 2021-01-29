#ifndef END_my_m_MT_R_2che2pawn_B_2che1ma
#define END_my_m_MT_R_2che2pawn_B_2che1ma
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "2车2兵对2车1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



void my_m_MT_R_2che2pawn_B_2che1ma(typePOS &POSITION, EvalInfo &ei){

	Square mk  = my_king_pos;
	Square yk  = your_king_pos;
	Square yma = S90_from_piecelist(POSITION,your_ma,0);

	// fen 4kab2/4a4/4b4/5r3/3PR2P1/P3P4/9/4B4/8R/3AKABrc w - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && MY_SQ55 == mk){
		if(StoY(yma) MY_SMALL_EQL MY_RANK3){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 3ak1b2/4a4/b4nr2/3R5/1P1R3P1/2B6/9/9/4Ar3/4KA3 w - - 0 1
	if(my_shi_num == 2 && MY_SQ55 == mk){
		if(StoY(yma) MY_SMALL_EQL MY_RANK2){
			if(my_xiang_num >= 1){
				MY_EV_ADD(EV_MY_CAN * 16);
			}
			int malr = My_pawn_already_over_river(POSITION);
			if(malr == 2){
				MY_EV_ADD((sint16)count_1s(bb_my_pawn,MyLowBB[StoY(yma)]) * 32);
			}
		}
	}

    // fen 3ak1b2/4a4/2n1b4/9/P3R4/2P3B2/2r5r/4BR3/4A4/3AK4 b - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && MY_SQ55 == mk){
		if(StoY(yma) MY_SMALL_EQL MY_RANK4){
			MY_EV_ADD(32);
			if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
				if(EV_MY_CAN <= 1){
					RETRUN_MUL(8);
				}
			}
		}
	}
}

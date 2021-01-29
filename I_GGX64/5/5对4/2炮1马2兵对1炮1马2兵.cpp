#ifndef END_my_m_MT_R_2pao1ma2pawn_B_1pao1ma2pawn
#define END_my_m_MT_R_2pao1ma2pawn_B_1pao1ma2pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "2炮1马2兵对1炮1马2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



void my_m_MT_R_2pao1ma2pawn_B_1pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){


	MY_EV_ADD(32);

	// fen 5P3/4k4/b2aba3/p8/7C1/P5n2/2N3C2/5p3/8c/4K4 w - - 0 1
	if(EV_YOUR_CAN <= 1){
		// 二线上没有对方的兵
		if(!have_bit(bb_your_pawn,RankBB_A[MY_RANK8])){
			MY_EV_ADD(32);
		}
	}

	// fen 9/9/b3k2N1/C2c5/4C4/9/P4p2P/2n1Bp3/9/2B1K4 b - - 0 1
	if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
		if(!have_bit(bb_my_pawn,m_and(LeftBB[0x7],RightBB[0x1]))){
			MY_EV_SUB(EV_YOUR_CAN * 32);
			if(my_shi_num == 0){
				if(count_1s(bb_your_pawn,MyLowBB[MY_RANK5]) == 2){
					MY_EV_SUB(32);
					MY_EV_SUB(EV_YOUR_CAN * 32);
				}
			}
		}
	}

}


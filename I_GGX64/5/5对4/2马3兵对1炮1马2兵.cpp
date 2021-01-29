#ifndef END_my_m_MT_R_2ma3pawn_B_1pao1ma2pawn
#define END_my_m_MT_R_2ma3pawn_B_1pao1ma2pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2马3兵对1炮1马2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_2ma3pawn_B_1pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;

	if((your_shi_num + your_xiang_num) == 4){
		int mcan = EV_MY_CAN;
		if(mcan <= 1){
			MY_EV_SUB(64);
		}
	}

	// fen 4k1b2/4a4/3cba3/5P3/2pN2P2/1N7/P4n1p1/4BA3/4AK3/9 w - - 0 1
	if (my_shi_num == 2 && my_xiang >= 1 && EV_YOUR_CAN <= 1){
		if (My_pawn_already_over_river(POSITION) >= 2){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 3cka3/9/3ab4/1P1NP4/6b2/3pp2NP/2n6/5A3/4A4/5KB2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(EV_YOUR_CAN == 2){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
				MY_EV_SUB(32);
			}
		}
	}

	// fen 2bk1ab2/4a4/8c/N2NP4/6p2/P8/2p3P2/9/4A4/4KAn2 b - - 0 1
	if((my_shi_num + my_xiang_num) <= 3){
		if((your_shi_num + your_xiang_num) >= 3){
			MY_EV_SUB(32);
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK2])){
				MY_EV_SUB(32);
			}
		}
	}


	// fen 2ba1k3/9/3abN3/4p3p/9/Pc1n4P/4P4/4B1N2/4A4/2BAK4 w - - 0 1
	if((your_shi_num + your_xiang_num) == 4 && EV_MY_CAN <= 1){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
			if((my_shi_num + my_xiang_num) >= 3 && EV_YOUR_CAN == 0){
				RETRUN_MUL(12);
			}
		}
	}
}


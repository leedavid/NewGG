#ifndef ENDR_1che2pao3pawn_B_1che1pao1ma2pawn
#define ENDR_1che2pao3pawn_B_1che1pao1ma2pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车2炮3兵对1车1炮1马2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1che2pao3pawn_B_1che1pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square yma = S90_from_piecelist(POSITION, your_ma, 0);
	Square mche = S90_from_piecelist(POSITION, my_che, 0);

	// fen c2k1ab2/4a4/4b4/2r3p1p/3C5/1RCnP1P2/8P/5A3/9/4KAB2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(EV_MY_CAN <= 1 && !have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
			MY_EV_SUB(32);
			MY_EV_SUB(EV_YOUR_CAN * 16);
			if(StoY(yma) MY_LARGE_EQL MY_RANK4){
				MY_EV_SUB(16);
			}
		}
	}

	// fen 2b2C1R1/4k4/3ab4/p3p4/5rc2/2P6/P1n1P4/8C/4A4/3AK1B2 w - - 0 1
	if (EV_MY_CAN == 0){
		if ((my_shi_num + my_xiang_num) <= 3){
			if (your_xiang_num == 2){
				MY_EV_SUB(16);
				if (StoY(yma) MY_LARGE_EQL MY_RANK5 && StoY(mche) MY_SMALL_EQL MY_RANK2){
					MY_EV_SUB(32);
				}
			}
		}
	}
}
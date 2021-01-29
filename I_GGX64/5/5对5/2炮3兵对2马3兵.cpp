#ifndef ENDR_my_m_MT_R_2pao3pawn_B_2ma3pawn
#define ENDR_my_m_MT_R_2pao3pawn_B_2ma3pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "2炮3兵对2马3兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_2pao3pawn_B_2ma3pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;

	// fen 3k1ab2/4a4/4b4/5N2p/4P4/6P2/p3N3P/3A5/2p1A1c2/5Kc2 b - - 0 1
	if(your_shi_num == 2 && EV_MY_CAN <= 2){
		Bitboard ghp = m_and(bb_my_pawn,MyUpBB[MY_RANK5]);
		if(StoX(yk) == 0x3 && !have_bit(bb_your_shi,FileBB_A[0x3])){
			if(!have_bit(ghp,LeftBB[0x5])){
				MY_EV_SUB(EV_YOUR_CAN * 32);
			}
		}
		if(StoX(yk) == 0x5 && !have_bit(bb_your_shi,FileBB_A[0x5])){
			if(!have_bit(ghp,RightBB[0x3])){
				MY_EV_SUB(EV_YOUR_CAN * 32);
			}
		}
	}

	// fen 5a3/4aPP2/4k4/2nC5/p7C/2B6/P2n5/3ABA3/2p4p1/5K3 w - - 0 1
	if(your_shi_num == 2 && EV_MY_CAN <= 2){
		Bitboard upp = m_and(bb_my_pawn,MyUpBB[StoY(yk)]);
		if(count_1s(upp) == 2){
			MY_EV_SUB(64);
			if(!have_bit(LeftBB[0x4],upp) || !have_bit(RightBB[0x4],upp)){
			   MY_EV_SUB(EV_YOUR_CAN * 32);
			}
		}
	}
}
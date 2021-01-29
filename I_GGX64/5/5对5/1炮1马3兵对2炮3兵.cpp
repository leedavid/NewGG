
#ifndef ENDR_my_m_MT_R_1pao1ma3pawn_B_2pao3pawn
#define ENDR_my_m_MT_R_1pao1ma3pawn_B_2pao3pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1炮1马3兵对2炮3兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1pao1ma3pawn_B_2pao3pawn(typePOS &POSITION, EvalInfo &ei){

	// fen 3a1a3/4k1N2/3Cb4/p3p1c2/9/P1P5p/4P4/5A3/9/2B1KAB1c b - - 0 1
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1MaXPawn_3pawn_ShiAdd[your_shi_num]);

	Square mk = my_king_pos;

	Bitboard ymp = m_and(bb_your_pawn, MyUpBB[StoY(mk)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1MaXPawn_3pawn_ShiAdd[my_shi_num]);

	// fen 2bk1ab2/4a4/1c7/2p1C3p/p8/2c3P2/P3P3P/N2A5/9/2BK5 b - - 0 1
	if(EV_YOUR_CAN <= 1){
		if(my_shi_num >= 1 && my_xiang_num >= 1){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
		//MY_EV_ADD(32);
	}
	MY_EV_ADD(EV_MY_CAN * 16);
	MY_EV_SUB(EV_YOUR_CAN * 8);

	// fen 2bak4/4a2c1/4b4/p7p/4p4/1n7/PC2P3P/2C1BA3/9/4KAB2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && EV_MY_CAN <= 0){
		MY_EV_SUB(32);
	}
}


#ifndef END_my_m_MT_R_1pao2ma3pawn_B_2pao1ma2pawn
#define END_my_m_MT_R_1pao2ma3pawn_B_2pao1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
#include "..\\..\\endgame\mat.h"
#include "1炮2马3兵对2炮1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1pao2ma3pawn_B_2pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2Pao1Ma3pawn_To_1Pao2Ma3Pawn_ByPawn[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_2Pao1Ma3pawn_To_1Pao2Ma3Pawn_ByPawn[my_shi_num]);

	//int mcan = EV_MY_CAN;
	//int ycan = EV_YOUR_CAN;

	//MY_EV_ADD(mcan * 32);
	//MY_EV_SUB(ycan * 32);

	// fen 2bk1ab2/4a4/5c3/3C4p/p3P1P2/4nN3/8P/1N3c3/9/3A1K3 w - - 0 1
	//如果对方的兵全在边上，且没有过河
	int malr = My_pawn_already_over_river(POSITION);
	if(malr >= 2){
		if(!have_bit(bb_your_pawn,m_and(LeftBB[0x7],RightBB[0x1]))){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	// fen 4k1b2/4a4/N3ba3/p2C1N3/2p2P3/P8/2P6/4B4/3K2n2/c3c4 w - - 0 1
	if (EV_YOUR_CAN == 0) {
		MY_EV_ADD(EV_MY_CAN * 32);
	}

}
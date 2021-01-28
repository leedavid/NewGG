#ifndef ENDR_1pao2ma3pawn_B_1pao2ma2pawn
#define ENDR_1pao2ma3pawn_B_1pao2ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1炮2马3兵对1炮2马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1pao2ma3pawn_B_1pao2ma2pawn(typePOS &POSITION, EvalInfo &ei){

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

	// fen 5kb2/4a4/3a5/4C1P2/p2Np3P/9/2N1Pn3/3nB4/5K3/1cB6 b - - 0 1
	if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK5]) && my_xiang_num == 2){
		if(malr >= 2){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

}
#ifndef END_my_m_MT_R_1che1pao1ma1pawn_B_1che1ma1pawn
#define END_my_m_MT_R_1che1pao1ma1pawn_B_1che1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车1炮1马1兵对1车1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1che1pao1ma1pawn_B_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	//// ADD_MY
	//Square yk = your_king_pos;
	//Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	//int pmok = (int)count_1s(bmp);
	//MY_EV_ADD(pmok * ADD_1che1pao1ma1pawn_1che1pao1ma_ByShi[your_shi_num]);

	Square yma   = S90_from_piecelist(POSITION,your_ma,0);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square yche  = S90_from_piecelist(POSITION,your_che,0);

	// fen 4k4/6R2/1c7/9/2n2r3/2B6/p3P4/3A2N2/4A4/2B1K4 b - - 0 1
	if(StoY(ypawn) MY_SMALL_EQL MY_RANK4 && StoY(yma) MY_SMALL_EQL MY_RANK4){
		MY_EV_ADD(32);
	    MY_EV_ADD(EV_MY_CAN * 32);
	}

	// fen 3nkarC1/3Na4/4b4/8P/2b4R1/9/9/1p7/4K4/9 b - - 0 1
	if(bit_is_set(EV_MY_XBIT,yche)){
		MY_EV_ADD(32);
		if(StoY(yma) MY_SMALL_EQL MY_RANK2){
			MY_EV_ADD(32);
		}
		MY_EV_ADD(EV_MY_CAN * 16);
	}

}
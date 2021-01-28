#ifndef END_my_m_MT_R_1che1ma2pawn_B_2pao1ma1pawn
#define END_my_m_MT_R_1che1ma2pawn_B_2pao1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1马2兵对2炮1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1che1ma2pawn_B_2pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheMaXPawn_To_2Pao1Ma_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_CheMaXPawn_To_2Pao1Ma_ByPawn[my_shi_num]);


	// fen 2b6/4ak3/4ba3/9/1P7/6N1n/4PR3/3K4p/4A2c1/8c w - - 0 1
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	if(abs(StoX(ypawn) - 0x4) >= 3){
		MY_EV_ADD(16);
		MY_EV_ADD(EV_MY_CAN * 16);
	}
}

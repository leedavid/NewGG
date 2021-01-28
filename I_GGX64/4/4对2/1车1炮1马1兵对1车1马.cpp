#ifndef END_my_m_MT_R_1che1pao1ma1pawn_B_1che1ma
#define END_my_m_MT_R_1che1pao1ma1pawn_B_1che1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1炮1马1兵对1车1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int  ADD_1Che1Pao1MaXPawn_2CheOnly[3]         = {96, 64, 32};   //1 
//const int  ADD_1Che1Pao1MaXPawn_2CheOnly_Safe       =  96;

void my_m_MT_R_1che1pao1ma1pawn_B_1che1ma(typePOS &POSITION, EvalInfo &ei){

	Square mk    = my_king_pos;
	//Square mpao  = S90_from_piecelist(POSITION,my_pao,0);
	Square yma   = S90_from_piecelist(POSITION,your_ma,0);
	// fen 6R2/4k4/5cN2/9/2n6/2B6/2p1r4/3AB4/4A4/4K4 w - - 0 1
	//if(StoY(mk) MY_LARGE_EQL MY_RANK7){
	//	if(StoY(mpao) MY_LARGE_EQL MY_RANK7){
	//		MY_EV_ADD(16);
	//		MY_EV_ADD(EV_MY_CAN * 32);
	//	}
	//}

	MY_EV_ADD(32);
	MY_EV_ADD(EV_MY_CAN * 64);
	if(abs(StoY(yma) - StoY(mk)) >= 3){
		MY_EV_ADD(32);
	}
}


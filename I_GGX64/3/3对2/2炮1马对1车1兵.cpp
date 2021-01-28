#ifndef END_my_m_MT_R_2pao_1ma_B_1che1pawn
#define END_my_m_MT_R_2pao_1ma_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮1马对1车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//2炮1马对1车, 炮马方要加分

void my_m_MT_R_2pao_1ma_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){


	//如果没有过河,或者马炮方有仕
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	if(EV_YOUR_CAN == 0 || my_shi_num >= 1){
		MY_EV_ADD(Add_1炮2马对1车1兵);
	}

	// fen 2bak4/4a4/4b4/8N/9/p7r/9/2N1BC3/9/2B2K3 w - - 0 1
	if(my_xiang_num == 2 && StoY(ypawn) MY_SMALL_EQL MY_RANK5){
		MY_EV_ADD(80);
	}

	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * Add_2炮1马对1车1兵_byPawn_Shi[my_shi_num]);

}



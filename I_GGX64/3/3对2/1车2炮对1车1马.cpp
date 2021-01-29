#ifndef END_my_m_MT_R_1che2pao_B_1che1ma
#define END_my_m_MT_R_1che2pao_B_1che1ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车2炮对1车1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//车2炮对车马
void my_m_MT_R_1che2pao_B_1che1ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;

	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	Square mk  = my_king_pos;

	// fen 1Nb1ka3/4a4/4b4/p8/5n3/5N3/P7P/6R2/5K3/2r6 b - - 0 1
	if(EV_YOUR_CAN == 0){
		MY_EV_ADD(32);
		if(abs(StoY(yma) - StoY(mk)) >= 3){
			MY_EV_ADD(32);
		}
	}

	// fen 4k4/4a4/4ba3/9/9/2B6/3r2n2/2R6/9/C4KC2 w - - 0 1
	if((my_shi_num + my_xiang_num) <= 1 && StoY(yma) MY_LARGE_EQL MY_RANK5){
		MY_EV_SUB(32);
		if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
			MY_EV_SUB(32);
		}
	}

	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		RETRUN_MUL(8);
	}
}

//void m_MT_B_1che2pao_R_1che1ma(typePOS &POSITION, EvalInfo &ei){
///*
//    if(board->R_shi == 2 && board->R_xiang == 2){
//	   return 8;
//	}
//
//	return 16;	/*/
//}
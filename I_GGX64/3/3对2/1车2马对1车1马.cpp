#ifndef END_my_m_MT_R_1che2ma_B_1che1ma
#define END_my_m_MT_R_1che2ma_B_1che1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车2马对1车1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



//车2炮对车炮
void my_m_MT_R_1che2ma_B_1che1ma(typePOS &POSITION, EvalInfo &ei){

	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	Square mk  = my_king_pos;

	// fen 1Nb1ka3/4a4/4b4/p8/5n3/5N3/P7P/6R2/5K3/2r6 b - - 0 1
	if(EV_YOUR_CAN == 0){
		MY_EV_ADD(32);
		if(abs(StoY(yma) - StoY(mk)) >= 3){
			MY_EV_ADD(32);
		}
	}

	Square yk = your_king_pos;
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		RETRUN_MUL(8);
	}
}

//void m_MT_B_1che2ma_R_1che1ma(typePOS &POSITION, EvalInfo &ei){
///*
//	//premat_t* pMat = board->pMat;
//	//uint16 cInfo16 = pMat->sixiangInfo8;
//
//	//if((cInfo16 & CK_R_2x) && (cInfo16 & CK_R_2s)){
//	if(board->R_shi == 2 && board->R_xiang == 2){
//	   return 8;
//	}
//
//	*/	
//}
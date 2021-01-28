#ifndef END_my_m_MT_R_1che1pao1ma_B_1che1pao
#define END_my_m_MT_R_1che1pao1ma_B_1che1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮1马对1车1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



//车2炮对车炮
void my_m_MT_R_1che1pao1ma_B_1che1pao(typePOS &POSITION, EvalInfo &ei){
	
	Square yk = your_king_pos;

	Square mma = S90_from_piecelist(POSITION,my_ma,0);
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);

	// fen 4k1b2/4a4/5a3/9/6b1N/C3R4/9/4K4/1r7/c5B2 b - - 0 1
	if(StoY(ypao) MY_LARGE_EQL MY_RANK5){
		MY_EV_ADD(32);
	}

	// fen 4k1b2/4a4/5a3/9/6b1N/C3R4/9/4K4/1r7/c5B2 b - - 0 1

	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(32);
	}

	if((my_shi_num + my_xiang_num) >= 1){
		MY_EV_ADD(64);
	}

	// fen 3ck4/4a3N/4ba2b/4r4/9/R3C4/9/9/9/4K4 w - - 0 1
	if(StoY(mma) MY_SMALL_EQL MY_RANK4){
		MY_EV_ADD(64);
	}

}

//void m_MT_B_1che1pao1ma_R_1che1pao(typePOS &POSITION, EvalInfo &ei){
///*
//	//premat_t* pMat = board->pMat;
//	//uint16 cInfo16 = pMat->sixiangInfo8;
//
//	//if((cInfo16 & CK_R_2x) && (cInfo16 & CK_R_2s)){
//	if(board->R_shi == 2 && board->R_xiang == 2){
//	   return 14;
//	}
//
//	return 16;	/*/
//}
#ifndef END_my_m_MT_R_1che2ma_B_1che1pao
#define END_my_m_MT_R_1che2ma_B_1che1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车2马对1车1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



//车2马对车炮
void my_m_MT_R_1che2ma_B_1che1pao(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		RETRUN_MUL(8);
	}
}

//void m_MT_B_1che2ma_R_1che1pao(typePOS &POSITION, EvalInfo &ei){
///*
//	//premat_t* pMat = board->pMat;
//	//uint16 cInfo16 = pMat->sixiangInfo8;
//
//	if(board->R_shi == 2 && board->R_xiang == 2){
//	   return 8;
//	}
//
//	return 16;	/*/
//}
#ifndef END_my_m_MT_R_2pao_B_2ma
#define END_my_m_MT_R_2pao_B_2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮对2马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



// fen 9/4k4/9/9/9/9/3C2n2/4nK3/3C5/9 w - - 49 49

void my_m_MT_R_2pao_B_2ma(typePOS &POSITION, EvalInfo &ei){

	// fen 4k4/4a4/4b4/9/2b6/4n4/3n1C3/7C1/3KA4/9 b - - 0 0
	if((my_xiang_num + my_shi_num) == 0){
		MY_EV_SUB(96);
	}


    if((my_xiang_num + my_shi_num) == 0 && (your_shi_num + your_xiang_num) == 0){		
		RETRUN_MUL(4);
	}
	if((my_xiang_num + my_shi_num) != 0 && (your_shi_num + your_xiang_num) != 0){
		RETRUN_MUL(4);
	}

	Square mk = my_king_pos;

	// 如果二个炮者在家里
	// fen 2bk5/4a4/5a3/9/9/5n3/9/3C5/1n2K4/4C4 w - - 0 1
	if(StoX(mk) == 0x4){
		Bitboard p = m_and(bb_my_pao, MyLowBB[MY_RANK6]);
		if(count_1s(p) == 2){
			RETRUN_MUL(4);
		}
	}

	RETRUN_MUL(8);
}

//void m_MT_B_2pao_R_2ma(typePOS &POSITION, EvalInfo &ei){
///*
//	if(board->B_shi == 0 && board->B_xiang == 0 && board->R_shi == 0 && board->R_xiang == 0){
//		return 1;
//	}
//
//	if((board->B_shi + board->B_xiang) != 0 && (board->R_shi + board->R_xiang) != 0){
//		return 2;
//	}
//	return 8;/*/
//}
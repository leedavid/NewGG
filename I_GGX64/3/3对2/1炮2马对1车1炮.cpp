#ifndef END_my_m_MT_R_1pao2ma_B_1che1pao
#define END_my_m_MT_R_1pao2ma_B_1che1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮2马对1车1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1pao2ma_B_1che1pao(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;
	Square yk = your_king_pos;
	
	if(StoY(mk) != MY_RANK9){
		MY_EV_SUB(ADD_NO_CHE_OP_KING_NOT_BOTTOM);
	}

	// fen 3ak1b2/5c3/1R1a5/9/2b1nNn2/6B2/9/4B4/4A4/4K4 b - - 0 1
	if((your_shi_num + your_xiang_num) >= 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		MY_EV_SUB(64);
	}
	
	// fen 3k1a3/9/n2a3rb/C2N5/2N6/2B6/9/4B4/9/3AKA3 w - - 127 
	if((your_shi_num + your_xiang_num) >= 2){
		if((my_shi_num + my_xiang_num) >= 3){
			RETRUN_MUL(8);
		}
	}
}


//void m_MT_B_1pao2ma_R_1che1pao(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//	
//	if(StoY(bk) != 0x3){
//		board->mulScore += ADD_NO_CHE_OP_KING_NOT_BOTTOM;
//	}
//
//	// fen 3k1a3/9/n2a3rb/C2N5/2N6/2B6/9/4B4/9/3AKA3 w - - 127 
//	if((board->R_shi + board->R_xiang) >= 2 ){
//		if((board->B_shi + board->B_xiang) >= 3){
//			return 8;
//		}
//	}
//	*/
//}
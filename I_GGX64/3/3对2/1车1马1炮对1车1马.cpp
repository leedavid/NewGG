#ifndef END_my_m_MT_R_1che1pao1ma_B_1che1ma
#define END_my_m_MT_R_1che1pao1ma_B_1che1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1马1炮对1车1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//车马炮对车炮
void my_m_MT_R_1che1pao1ma_B_1che1ma(typePOS &POSITION, EvalInfo &ei){
	
	Square yk = your_king_pos;
	Square mk = my_king_pos;

	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	Square mche = S90_from_piecelist(POSITION,my_che,0);
	Square yche = S90_from_piecelist(POSITION,your_che,0);
	Square mma  = S90_from_piecelist(POSITION,my_ma,0);
	//Square mk  = my_king_pos;

	// fen 1Nb1ka3/4a4/4b4/p8/5n3/5N3/P7P/6R2/5K3/2r6 b - - 0 1
	if(EV_YOUR_CAN == 0){
		MY_EV_ADD(32);
		if(abs(StoY(yma) - StoY(mk)) >= 3){
			MY_EV_ADD(32);
		}
	}

	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(96);
	}

	// fen 2b1kc3/4a4/n8/3NR4/6r2/9/9/4B4/4A4/3AK1B2 b - - 0 1
	if((my_shi_num + my_xiang_num) >= 2 && StoY(mk) == MY_RANK9){
		MY_EV_ADD(64);
	}

	// fen 2ba2R1C/4ak3/4b1N2/6r2/4n4/9/9/4BA3/4A4/2B1K4 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mche) MY_SMALL_EQL MY_RANK1 && StoX(mche) == StoX(mma)){
			if(StoX(yk) > 0x4 && MY_SQ18 == mma && StoX(yche) == 0x6){
				RETRUN_MUL(4);
			}
			if(StoX(yk) < 0x4 && MY_SQ14 == mma && StoX(yche) == 0x2){
				RETRUN_MUL(4);
			}
		}
	}
}

//void m_MT_B_1che1pao1ma_R_1che1ma(typePOS &POSITION, EvalInfo &ei){
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
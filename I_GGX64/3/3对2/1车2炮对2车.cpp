#ifndef END_my_m_MT_R_1che2pao_B_2che
#define END_my_m_MT_R_1che2pao_B_2che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车2炮对2车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//车2炮对车炮
void my_m_MT_R_1che2pao_B_2che(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	MY_EV_SUB(64);

	if(StoY(mk) != MY_RANK9){
		MY_EV_SUB(80);
	}

	// fen 3akcc2/9/4ba3/9/6b2/3R3R1/9/4BA3/4A4/1r2K1B2 w - - 84 84
	if(my_shi_num == 2 && StoY(mk) == MY_RANK9){
		EV_MY_SAFE = TRUE;
	}



	// fen 5k3/9/1r1ab4/9/9/2B1r4/7R1/3CB4/4A4/3CKA3 b - - 0 1
	if(EV_MY_SAFE){
		if((your_shi_num + your_xiang_num) >= 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){			
			if(count_1s(bb_my_pao,MyLowBB[MY_RANK4]) == 2){
				RETRUN_MUL(4);
			}
		}
	}
	// fen 3akcc2/9/4ba3/9/6b2/3R3R1/9/4BA3/4A4/1r2K1B2 w - - 84 84
	if(EV_MY_SAFE){
		if((your_shi_num + your_xiang_num) >= 2 && StoY(yk) == MY_RANK0){
			RETRUN_MUL(8);
		}
	}
	// fen 9/3k5/9/9/9/9/9/C3RA2B/r2r5/4KC3 b - - 0 1
	if(my_shi_num <= 1){
		if(count_1s(bb_your_che,RankBB_A[MY_RANK8]) == 2){
            MY_EV_SUB(96);
		}
	}



	// fen 9/3k5/9/9/9/9/9/C3RA2B/r2r5/4KC3 b - - 0 1
	//if(my_shi_num >= 1)
}

//void m_MT_B_1che2pao_R_2che(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	if(board->B_shi == 2 && StoY(bk) == 0x3){
//		board->bsafe = TRUE;
//
//		if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//			return 8;
//		}
//	}
//
//	*/
//	
//}
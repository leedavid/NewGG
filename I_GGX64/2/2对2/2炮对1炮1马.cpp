#ifndef END_my_m_MT_R_2pao_B_1pao1ma
#define END_my_m_MT_R_2pao_B_1pao1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮对1炮1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//MAT_R_2ma_B_2pao
//红方二炮,黑方一炮一马
void my_m_MT_R_2pao_B_1pao1ma(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;
	
	if(my_shi_num <= 1){
		EV_YOUR_SAFE = TRUE;
	}

	if(your_shi_num == 0){
		EV_MY_SAFE = TRUE;
	}
	
	// fen 2bk1a3/4a4/4b1C2/4C4/9/9/c3n4/3A4B/4A4/4K4 w - - 2 2
	if((my_shi_num + my_xiang_num) >= 3){
		EV_MY_SAFE = TRUE;
	}

	if(my_xiang_num == 2 || my_shi_num == 2){
		EV_MY_SAFE = TRUE;
	}

	if(your_shi_num == 2 || your_xiang_num == 2){
		EV_YOUR_SAFE = TRUE;
	}

	// fen 2b2k3/9/4ba3/2c1C4/9/2B6/3Cn4/3A5/9/5K3 b - - 0 1
	if(EV_YOUR_SAFE){
		if((my_shi_num + my_xiang_num) >= 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			RETRUN_MUL(4);
		}
	}

	// fen 4k4/9/4ba3/4c4/2b6/9/9/5n1C1/5C3/2B2K3 b - - 0 1
	if(my_xiang_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(!have_bit(bb_my_pao,MyUpBB[MY_RANK4])){
			RETRUN_MUL(4);
		}
		RETRUN_MUL(6);
	}


	// fen 3k5/9/3c5/3N5/9/6B2/3c5/5A3/2C1A4/3K5 w - - 29 29
    RETRUN_MUL(8);

}

//void m_MT_B_2pao_R_1pao1ma(typePOS &POSITION, EvalInfo &ei){
///*
//	//if(board->B_shi <= 1 && board->R_shi == 0){
//	//	return 1;
//	//}
//
//   Square bk = PieceListStart(board,BKING);
//
//
//
//	if(board->B_shi <= 1){
//		board->rsafe = TRUE;
//	}
//
//	if(board->R_shi == 0){
//		board->bsafe = TRUE;
//	}
//
//	if((board->B_shi + board->B_xiang) >= 3){
//		board->bsafe = TRUE;
//	}
//
//	if(board->R_xiang == 2 || board->R_shi == 2){
//		board->rsafe = TRUE;
//	}
//
//	if(board->B_xiang == 2){
//		board->bsafe = TRUE;
//	}
//	// fen 3k5/9/3aca3/9/1C4N2/1cB6/9/4BA3/4A4/4K4 b - - 120 120
//	if(board->B_shi == 2){
//		board->bsafe = TRUE;
//	}
//
//	return 8;
//
//
//	//*/
//}
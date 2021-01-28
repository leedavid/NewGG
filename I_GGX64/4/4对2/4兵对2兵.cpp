#ifndef END_my_m_MT_R_4pawn_B_2pawn
#define END_my_m_MT_R_4pawn_B_2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "4兵对2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//4兵对2兵
void my_m_MT_R_4pawn_B_2pawn(typePOS &POSITION, EvalInfo &ei){

	BothOnlyPawnEval(POSITION,ei);

	//红方只能过一个兵,其它的兵被顶住了，或是相守住了，就是和棋

	int mcan = EV_MY_CAN;
  
	// fen 3k5/2P1a4/4b4/p8/6b1p/P1P6/8P/3A5/9/2B1K4 w - - 5 5
	if(EV_MY_SAFE){
		if(mcan <= 1){
			if((your_xiang_num + your_shi_num) >= 2){
				RETRUN_MUL(2);
			}
		}
	}

	if(EV_YOUR_CAN <= 1){
		EV_MY_SAFE = TRUE;
	}
}

//4兵对2兵
//void m_MT_B_4pawn_R_2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	BothOnlyPawnEval(board);
//	
//int rcan = RpawnCanOverLiver(board);
//int bcan = BpawnCanOverLiver(board);
//
//	if(bcan == 1){
//		if((board->R_xiang + board->R_shi) >= 2){
//			// fen 3k5/2P1a4/4b4/p8/6b1p/P1P6/8P/3A5/9/2B1K4 w - - 5 5
//			board->rsafe = TRUE;
//		}
//	}
//
//	if(bcan == 0){
//		board->rsafe = TRUE;
//	}
//
//	if(rcan <= 1){
//		board->bsafe = TRUE;
//	}
//
//	*/
//}
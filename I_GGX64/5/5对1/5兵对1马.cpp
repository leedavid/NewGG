#ifndef END_my_m_MT_R_5pawn_B_1ma
#define END_my_m_MT_R_5pawn_B_1ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "5兵对1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int PawnShiAdd[3] = {96,48,0};

void my_m_MT_R_5pawn_B_1ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_XPawnToMa_ByPawnShi[your_shi_num]);

	int mcan = EV_MY_CAN;
	if(mcan <= 1){
		RETRUN_MUL(2);
	}
}

//void m_MT_B_5pawn_R_1ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//
//	bool AllpawnBlowKing = TRUE;
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= ADD_XPawnToMa_ByPawnShi[board->R_shi];
//
//			if(StoY(from) <= StoY(rk)){
//				AllpawnBlowKing = FALSE;
//			}
//		}
//	}
//
//	if(AllpawnBlowKing == TRUE){   //所有的兵在对方的将下面了,也是和了
//		board->mulScore = 0;
//		return 1;
//	}
//
//
//	//if(board->R_shi == 2){
//	//	board->mulScore /= 8;
//	//	return 1;
//	//}
//	//else if(board->R_shi == 1){
//	//	board->mulScore /= 4;
//	//	return 1;
//	//}
//
//
//	return 16;	/*/
//}
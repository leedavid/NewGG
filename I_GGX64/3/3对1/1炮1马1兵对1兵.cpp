#ifndef END_my_m_MT_R_1che1pawn_B_1ma1pawn
#define END_my_m_MT_R_1che1pawn_B_1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮1马1兵对1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//还有就是马过河了

void my_m_MT_R_1pao1ma_1pawn_B_1pawn(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao1MaXPawn_1Pawn[your_shi_num]);
}

//void m_MT_B_1pao1ma_1pawn_R_1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1Pao1MaXPawn_1Pawn[board->R_shi];
//		}
//	}
//
//	*/
//}
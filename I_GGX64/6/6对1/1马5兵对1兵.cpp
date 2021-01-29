#ifndef END_my_m_MT_R_1ma5pawn_B_1pawn
#define END_my_m_MT_R_1ma5pawn_B_1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1马5兵对1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



void my_m_MT_R_1ma5pawn_B_1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1MaXPawn_1Pawn_ByPawnShi[your_shi_num]);

	MY_EV_ADD(ADD_1MaXPawn_1Pawn);
}

//void m_MT_B_1ma5pawn_R_1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	//
//	Square rk = PieceListStart(board,RKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -=  ADD_1MaXPawn_1Pawn_ByPawnShi[board->R_shi];
//		}
//	}
//
//
//	board->mulScore -= ADD_1MaXPawn_1Pawn;
//
//	*/
//}
#ifndef END_my_m_MT_R_5pawn_B_1ma3pawn
#define END_my_m_MT_R_5pawn_B_1ma3pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "5兵对1马3兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_5pawn_B_1ma3pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_3pawn_MaXPawn_ShiAdd[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1MaXPawn_3pawn_ShiAdd[my_shi_num]);

	//fen 3k5/9/b8/p4P1np/2pP5/8P/P1P6/4B4/9/3AKAB2 w - - 0 1
	MY_EV_SUB(ADD_1MaXPawn_3Pawn);

}

//void m_MT_B_5pawn_R_1ma3pawn(typePOS &POSITION, EvalInfo &ei){
//	/*
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore +=  ADD_1MaXPawn_3pawn_ShiAdd[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_3pawn_MaXPawn_ShiAdd[board->R_shi];
//		}
//	}
//
//	board->mulScore += ADD_1MaXPawn_3Pawn;    //炮兵方的别外加分
//
//	*/
//
//}
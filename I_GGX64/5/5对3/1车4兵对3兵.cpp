#ifndef END_my_m_MT_R_1che4pawn_B_3pawn
#define END_my_m_MT_R_1che4pawn_B_3pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车4兵对3兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1che4pawn_B_3pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheXPawn_To_PawnByShi[your_shi_num]);

	MY_EV_ADD(ADD_CheXPawn_To_3Pawn);
}

//void m_MT_B_1che4pawn_R_3pawn(typePOS &POSITION, EvalInfo &ei){
///*
//    Square rk    = PieceListStart(board,RKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_CheXPawn_To_PawnByShi[board->R_shi];
//		}
//	}
//
//	board->mulScore -= ADD_CheXPawn_To_3Pawn;
//	*/
//}




//m_MT_R_1che3pawn_B_3pawn
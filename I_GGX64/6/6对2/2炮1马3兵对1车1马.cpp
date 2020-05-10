#ifndef END_my_m_MT_R_2pao1ma3pawn_B_1che1ma
#define END_my_m_MT_R_2pao1ma3pawn_B_1che1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮1马3兵对1车1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2pao1ma3pawn_B_1che1ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2Pao1MaXPawn_1Che1Ma_To_ByPawn[your_shi_num]);
}
//
//void m_MT_B_2pao1ma3pawn_R_1che1ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2Pao1MaXPawn_1Che1Ma_To_ByPawn[board->R_shi];
//		}
//	}
//
//
//	*/
//}




//m_MT_R_2pao1ma1pawn_B_1che1pao(
#ifndef END_my_m_MT_R_2pao1ma1pawn_B_1che1pao1pawn
#define END_my_m_MT_R_2pao1ma1pawn_B_1che1pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮1马1兵对1车1炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_2pao1ma1pawn_B_1che1pao1pawn(typePOS &POSITION, EvalInfo &ei){
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_ChePaoXPawn_To_2Pao1Ma_ByPawn[my_shi_num]);

}

//void m_MT_B_2pao1ma1pawn_R_1che1pao1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_ChePaoXPawn_To_2Pao1Ma_ByPawn[board->R_shi];
//		}
//	}
//
//	*/
//}



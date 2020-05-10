#ifndef END_my_m_MT_R_2pao1ma_B_2pao1pawn
#define END_my_m_MT_R_2pao1ma_B_2pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2ÅÚ1Âí¶Ô2ÅÚ1±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//ADD_1PaoXPawn_1PaoXPawn_ByShi

void my_m_MT_R_2pao1ma_B_2pao1pawn(typePOS &POSITION, EvalInfo &ei){

	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_2pao1ma_2paoXpawn_ByShi[my_shi_num]);



}

//void m_MT_B_2pao1ma_R_2pao1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	//int rcan = RpawnAlreadyRiver(board);
//	//int bcan = BpawnAlreadyRiver(board);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_2pao1ma_2paoXpawn_ByShi[board->B_shi];
//		}
//	}
//
//	//for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//	//	if(StoY(from) < StoY(rk)){
//	//		board->mulScore -= ADD_R_2pao1ma_B_2pao1pawn[board->R_shi];
//	//	}
//	//}
//
//	//board->mulScore += rcan * 64;
//	//board->mulScore -= bcan * 64;
//
//	*/
//}
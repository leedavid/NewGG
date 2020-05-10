#ifndef END_my_m_MT_R_2pao2pawn_B_1ma1pawn
#define END_my_m_MT_R_2pao2pawn_B_1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2ÅÚ2±ø¶Ô1Âí1±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2pao2pawn_B_1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * Add_MAT_B_1che1pawn_R_2pao1pawn_ByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * Add_MAT_B_1che1pawn_R_2pao1pawn_ByShi[my_shi_num]);
}
//
//void m_MT_B_2pao2pawn_R_1ma1pawn(typePOS &POSITION, EvalInfo &ei){
//	/*
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= 96;
//		}
//
//	}
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > 0x3){
//			board->mulScore += 96;
//		}
//	}
//
//	*/
//}
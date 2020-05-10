#ifndef END_my_m_MT_R_2pao2pawn_B_2ma
#define END_my_m_MT_R_2pao2pawn_B_2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2ÅÚ2±ø¶Ô2Âí.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_2pao2pawn_B_2ma(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2PaoXPawn_2Ma_ByPawnShi[your_shi_num]);
}

//void m_MT_B_2pao2pawn_R_2ma(typePOS &POSITION, EvalInfo &ei){
//	/*
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= ADD_2PaoXPawn_2Ma_ByPawnShi[board->R_shi];
//		}
//	}
//
//	*/
//}
#ifndef END_my_m_MT_R_1che1pao5pawn_B_1che1ma
#define END_my_m_MT_R_1che1pao5pawn_B_1che1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮5兵对1车1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che1pao5pawn_B_1che1ma(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	// ADD 
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoPawn_CheMa_ByPawnByShi[your_shi_num]);
}

//void m_MT_B_1che1pao5pawn_R_1che1ma(typePOS &POSITION, EvalInfo &ei){
//	/*
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -=  ADD_ChePaoPawn_CheMa_ByPawnByShi[board->R_shi];
//		}
//
//	}
//
//	*/
//}

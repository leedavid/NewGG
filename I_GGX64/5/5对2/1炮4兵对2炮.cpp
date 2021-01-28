#ifndef END_my_m_MT_R_1pao4pawn_B_2pao
#define END_my_m_MT_R_1pao4pawn_B_2pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮4兵对2炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 





void my_m_MT_R_1pao4pawn_B_2pao(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1PaoXPawn_2Pao_ByPawnShi[your_shi_num]);
}

//void m_MT_B_1pao4pawn_R_2pao(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1PaoXPawn_2Pao_ByPawnShi[board->R_shi];
//		}
//	}
//
//	*/
//}
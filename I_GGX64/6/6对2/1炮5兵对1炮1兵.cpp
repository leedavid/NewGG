#ifndef END_my_m_MT_R_1pao5pawn_B_1pao1pawn
#define END_my_m_MT_R_1pao5pawn_B_1pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮5兵对1炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int  ADD_1PaoXPawn_1Ma1Pawn_ByPawnShi[3]      = {96, 64, 32};             //炮x兵对1马1兵, 多兵的加分
//const int  ADD_1PaoXPawn_1Ma1Pawn_ByMaPanw[3]       = {96, 64, 32};             //炮x兵对1马1兵, 多兵的加分



void my_m_MT_R_1pao5pawn_B_1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1PaoXPawn_1Pao1Pawn_ByPawnShi[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1PaoXPawn_1Pao1Pawn_ByPawnShi[my_shi_num]);
}
//
//void m_MT_B_1pao5pawn_R_1pao1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_1PaoXPawn_1Pao1Pawn_ByPawnShi[board->B_shi];
//		}
//	}
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1PaoXPawn_1Pao1Pawn_ByPawnShi[board->R_shi];
//		}
//	}
//
//	*/
//}
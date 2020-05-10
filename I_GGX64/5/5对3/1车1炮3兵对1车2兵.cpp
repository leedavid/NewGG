#ifndef END_my_m_MT_R_1che1pao3pawn_B_1che2pawn
#define END_my_m_MT_R_1che1pao3pawn_B_1che2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮3兵对1车2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int  ADD_CheMaXPawn_VS_1Che2Pawn_ByShi[3]     = {96, 64, 32};            //车炮X兵对车2兵_兵的加分
//const int  ADD_1Che2Pawn_VS_CheMaXPawn_ByShi[3]     = {96, 64, 32};            //车2兵_兵对车炮X兵的加分


void my_m_MT_R_1che1pao3pawn_B_1che2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoXPawn_VS_1Che2Pawn_ByShi[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1Che2Pawn_VS_ChePaoXPawn_ByShi[my_shi_num]);


	// fen 3aka3/7R1/9/2p1p4/7C1/P5r2/4P3P/3A1p3/3K5/9 w - - 0 1
	if(my_shi_num >= 1 && your_xiang_num == 0){
		Bitboard ylr = m_and(bb_your_pawn,MyLowBB[MY_RANK4]);
		if(count_1s(ylr) <= 1){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}
}

//void m_MT_B_1che1pao3pawn_R_1che2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_1Che2Pawn_VS_ChePaoXPawn_ByShi[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_ChePaoXPawn_VS_1Che2Pawn_ByShi[board->R_shi];
//		}
//	}
//
//
//
//	*/
//}
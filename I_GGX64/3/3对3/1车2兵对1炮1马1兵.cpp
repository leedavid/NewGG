#ifndef END_my_m_MT_R_1che2pawn_B_1pao1ma1pawn
#define END_my_m_MT_R_1che2pawn_B_1pao1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车2兵对1炮1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che2pawn_B_1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){
	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheXPawn_To_1Pao1Ma1Pawn_ByPawn[your_shi_num]);

	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1Pao1Ma1Pawn_To_CheXPawn_ByPawn[my_shi_num]);

	// fen 3ak1b2/4a4/4b4/8P/3c1n3/9/P3p2R1/9/4A4/2B1KA3 b - - 0 1
	MY_EV_ADD(32);
	MY_EV_ADD(EV_MY_CAN * 64);


}

//void m_MT_B_1che2pawn_R_1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//    Square rk    = PieceListStart(board,RKING);
//	Square bk    = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1Pao1Ma1Pawn_To_CheXPawn_ByPawn[board->R_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_CheXPawn_To_1Pao1Ma1Pawn_ByPawn[board->B_shi];
//		}
//	}
//
//	*/
//}




//m_MT_R_1che3pawn_B_3pawn
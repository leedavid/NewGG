#ifndef END_my_m_MT_R_2pao1ma3pawn_B_1pao2ma1pawn
#define END_my_m_MT_R_2pao1ma3pawn_B_1pao2ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮1马3兵对1炮2马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int ADD_2Pao1MaXpawn_To_1Pao2Ma1Pawn_ByPawn[3]     = { 96, 64, 32};   //
//const int ADD_2Pao1Ma1pawn_To_1Pao2MaXPawn_ByPawn[3]     = { 96, 64, 32};   //


void my_m_MT_R_2pao1ma3pawn_B_1pao2ma1pawn(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2Pao1MaXpawn_To_1Pao2Ma1Pawn_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_2Pao1Ma1pawn_To_1Pao2MaXPawn_ByPawn[my_shi_num]);
	// fen 2ba1k3/9/4ba3/4CN2C/2n6/p5P1P/4P4/4B4/2n1A4/3K3c1 w - - 0 40
	MY_EV_ADD(EV_MY_CAN * 16);

	// fen 2bak4/C3a4/4c4/4PP2C/p4N3/5c3/P8/4B4/4K1n2/9 b - - 0 1
	if(EV_YOUR_CAN == 0){
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	// fen 2b1kab2/4a4/3c5/C6P1/p4P3/2BC5/P2nN4/9/1n1K5/5A3 b - - 0 1
}

//void m_MT_B_2pao1ma3pawn_R_1pao2ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_2Pao1Ma1pawn_To_1Pao2MaXPawn_ByPawn[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2Pao1MaXpawn_To_1Pao2Ma1Pawn_ByPawn[board->R_shi];
//		}
//	}
//
//	*/
//}
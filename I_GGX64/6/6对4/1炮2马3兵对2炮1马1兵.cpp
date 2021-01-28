#ifndef END_my_m_MT_R_1pao2ma3pawn_B_2pao1ma1pawn
#define END_my_m_MT_R_1pao2ma3pawn_B_2pao1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮2马3兵对2炮1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int ADD_2Pao1MaXpawn_To_1Pao2Ma1Pawn_ByPawn[3]     = { 96, 64, 32};   //
//const int ADD_2Pao1Ma1pawn_To_1Pao2MaXPawn_ByPawn[3]     = { 96, 64, 32};   //


void my_m_MT_R_1pao2ma3pawn_B_2pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	//
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao2MaXpawn_To_2Pao1Ma1Pawn_ByPawn[your_shi_num]);
	//
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_2Pao1Ma1pawn_To_1Pao2MaXPawn_ByPawn[my_shi_num]);

	//MY_EV_ADD(EV_MY_CAN * 16);
	// fen 2bak4/C3a4/4c4/4PP2C/p4N3/5c3/P8/4B4/4K1n2/9 b - - 0 1
	if(EV_YOUR_CAN == 0){
		MY_EV_ADD(EV_MY_CAN * 16);
	}

	// fen 2ba1kb2/9/5a2n/C4N3/8p/4P1N2/2P5P/9/3KA4/6cc1 b - - 0 1
	if(StoY(yma) MY_SMALL_EQL MY_RANK2 && EV_YOUR_CAN == 0){
		MY_EV_ADD(EV_MY_CAN * 16);
	}
}

//void m_MT_B_1pao2ma3pawn_R_2pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){
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
//			board->mulScore -= ADD_1Pao2MaXpawn_To_2Pao1Ma1Pawn_ByPawn[board->R_shi];
//		}
//	}
//
//	*/
//}
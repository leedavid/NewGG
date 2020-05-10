#ifndef END_my_m_MT_R_1che1ma5pawn_B_1che1ma3pawn
#define END_my_m_MT_R_1che1ma5pawn_B_1che1ma3pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1马5兵对1车1马3兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che1ma5pawn_B_1che1ma3pawn(typePOS &POSITION, EvalInfo &ei){

	Square yma = S90_from_piecelist(POSITION,your_ma,0);

	// fen 3ak1b2/4a1P2/2n6/1PN1p3p/p5b2/4P4/P1r5P/1R7/3K5/9 w - - 0 1
    if(EV_YOUR_CAN == 0){
		if(StoY(yma) MY_SMALL_EQL MY_RANK2){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	//Square yk = your_king_pos;
	////
	//Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	//MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheMaXPawn_To_2Pao1Ma_ByPawn[your_shi_num]);
	////
	//Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	//MY_EV_SUB((sint16)count_1s(ymp) * ADD_CheMaXPawn_To_2Pao1Ma_ByPawn[my_shi_num]);
}

//void m_MT_B_1che1ma5pawn_R_2pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_CheMaXPawn_To_2Pao1Ma_ByPawn[board->R_shi];
//		}
//	}
//
//	*/
//}



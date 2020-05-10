#ifndef END_my_m_MT_R_1pao1ma5pawn_B_1che2pawn
#define END_my_m_MT_R_1pao1ma5pawn_B_1che2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马5兵对1车2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



//const int ADD_Che2Pawn_To_1Pao1MaXPawn_ByPawn[3]    =  { 96, 64, 32};  //车2兵,对1炮1马X兵
//const int ADD_1Pao1MaXPawn_To_Che2Pawn_ByPawn[3]    =  { 96, 64, 32};  //车2兵,对1炮1马X兵

void my_m_MT_R_1pao1ma5pawn_B_1che2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao1MaXPawn_To_Che2Pawn_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_Che2Pawn_To_1Pao1MaXPawn_ByPawn[my_shi_num]);



	// fen 4kab2/9/4ba1n1/4p3p/p1p6/c4R3/4P3P/4B4/4A4/2BAK4 w - - 2 2
	//如果车方的二个兵都不能过河,就要减分哇

	int ycan = EV_YOUR_CAN;
	if(ycan == 0){
		MY_EV_ADD(ADD_Che2Pawn_Can0);
	}

	// fen 4kab2/9/4ba1n1/4p3p/p1p6/c4R3/4P3P/4B4/4A4/2BAK4 w - - 2 2
}

//void m_MT_B_1pao1ma5pawn_R_1che2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//    Square rk    = PieceListStart(board,RKING);
//	Square bk    = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1Pao1MaXPawn_To_Che2Pawn_ByPawn[board->R_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_Che2Pawn_To_1Pao1MaXPawn_ByPawn[board->B_shi];
//		}
//	}
//
//	*/
//}




//m_MT_R_1che3pawn_B_3pawn
#ifndef END_my_m_MT_R_5pawn_B_1ma2pawn
#define END_my_m_MT_R_5pawn_B_1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "5兵对1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_5pawn_B_1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_3pawn_MaXPawn_ShiAdd[your_shi_num]);

	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1MaXPawn_3pawn_ShiAdd[my_shi_num]);

	MY_EV_SUB(ADD_1MaXPawn_3Pawn);

	// fen 2bak4/4a4/4b4/p3p4/8p/4P1B2/P1p6/6p2/N8/2BAKA3 b - - 0 0
	if(your_shi_num == 2){
		MY_EV_SUB(128);
	}


}

//void m_MT_B_5pawn_R_1ma2pawn(typePOS &POSITION, EvalInfo &ei){
//	/*
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore +=  ADD_1MaXPawn_3pawn_ShiAdd[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_3pawn_MaXPawn_ShiAdd[board->R_shi];
//		}
//	}
//
//	board->mulScore += ADD_1MaXPawn_3Pawn;    //炮兵方的别外加分
//
//	// fen 2bak4/4a4/4b4/p3p4/8p/4P1B2/P1p6/6p2/N8/2BAKA3 b - - 0 0
//	if(board->R_shi == 2 && board->R_xiang == 2){
//		board->mulScore += 128;
//	}
//
//	*/
//
//}
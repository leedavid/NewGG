#ifndef END_my_m_MT_R_1ma3pawn_B_3pawn
#define END_my_m_MT_R_1ma3pawn_B_3pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马3兵对3兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1ma3pawn_B_3pawn(typePOS &POSITION, EvalInfo &ei){
	
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1MaXPawn_3pawn_ShiAdd[your_shi_num]);
	

	int ycan = EV_YOUR_CAN;
	if(ycan >= 2){
		Square mk = my_king_pos;
		Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
		int pyok = (int)count_1s(ymp);
		MY_EV_SUB(pyok * ADD_3pawn_MaXPawn_ShiAdd[my_shi_num]);
	}

	MY_EV_ADD(ADD_1MaXPawn_3Pawn);

}

//void m_MT_B_1ma3pawn_R_3pawn(typePOS &POSITION, EvalInfo &ei){
//	/*
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//
//	int rcan   = RpawnCanOverLiver(board);
//	if(rcan >= 2){
//		for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//			if(StoY(from) > StoY(bk)){
//				board->mulScore +=  ADD_3pawn_MaXPawn_ShiAdd[board->B_shi];
//			}
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1MaXPawn_3pawn_ShiAdd[board->R_shi];
//		}
//	}
//
//	board->mulScore -= ADD_1MaXPawn_3Pawn;    //马兵方的别外加分
//
//	*/
//
//}

#ifndef END_my_m_MT_R_1ma5pawn_B_5pawn
#define END_my_m_MT_R_1ma5pawn_B_5pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马5兵对5兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1ma5pawn_B_5pawn(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	//
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1MaXPawn_3pawn_ShiAdd[your_shi_num]);

	int ycan = EV_YOUR_CAN;
	
	if(ycan >= 2){
		//
		Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
		MY_EV_SUB((sint16)count_1s(ymp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[my_shi_num]);
	}

	MY_EV_ADD(ADD_1MaXPawn_3Pawn);  //马兵方的别外加分

}

//void m_MT_B_1ma5pawn_R_5pawn(typePOS &POSITION, EvalInfo &ei){
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

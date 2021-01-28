#ifndef END_my_m_MT_R_1pao4pawn_B_5pawn
#define END_my_m_MT_R_1pao4pawn_B_5pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮4兵对5兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};


void my_m_MT_R_1pao4pawn_B_5pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_3pawn_PaoXPawn_ShiAdd[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_3pawn_PaoXPawn_ShiAdd[my_shi_num]);

	MY_EV_ADD(ADD_1PaoXPawn_3Pawn);
}

//void m_MT_B_1pao4pawn_R_5pawn(typePOS &POSITION, EvalInfo &ei){
///*
//
//	
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//
//	int rcan   = RpawnCanOverLiver(board);
//	if(rcan >= 2){
//		for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//			if(StoY(from) > StoY(bk)){
//				board->mulScore +=  ADD_3pawn_PaoXPawn_ShiAdd[board->B_shi];
//			}
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1PaoXPawn_3pawn_ShiAdd[board->R_shi];
//		}
//	}
//
//	board->mulScore -= ADD_1PaoXPawn_3Pawn;    //炮兵方的别外加分
//
//	*/
//}
//
//

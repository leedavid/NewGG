#ifndef END_my_m_MT_R_1pao3pawn_B_3pawn
#define END_my_m_MT_R_1pao3pawn_B_3pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮3兵对3兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};


void my_m_MT_R_1pao3pawn_B_3pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1PaoXPawn_3pawn_ShiAdd[your_shi_num]);

	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_3pawn_PaoXPawn_ShiAdd[my_shi_num]);

	MY_EV_ADD(ADD_1PaoXPawn_3Pawn);
}

//void m_MT_B_1pao3pawn_R_3pawn(typePOS &POSITION, EvalInfo &ei){
//
//
///*	
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



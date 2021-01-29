#ifndef END_my_m_MT_R_1pao2ma1pawn_B_1che1ma1pawn
#define END_my_m_MT_R_1pao2ma1pawn_B_1che1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮2马1兵对1车1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



void my_m_MT_R_1pao2ma1pawn_B_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){
	
	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[your_shi_num]);
	
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_CheMaXPawn_To_1Pao2Ma_ByPawn[my_shi_num]);

	// fen 4k1C2/1nC1a4/3a5/p5N2/2b6/P1B6/4r4/4B4/9/3AKA3 b - - 0 1
	if(EV_MY_CAN == 0){
		MY_EV_SUB(64);
	}
}

//void m_MT_B_1pao2ma1pawn_R_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_CheMaXPawn_To_1Pao2Ma_ByPawn[board->B_shi];
//		}
//	}
//
//	*/
//}



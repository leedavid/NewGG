#ifndef END_my_m_MT_R_2pao1ma1pawn_B_1che1ma1pawn
#define END_my_m_MT_R_2pao1ma1pawn_B_1che1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮1马1兵对1车1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_2pao1ma1pawn_B_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_CheMaXPawn_To_2Pao1Ma_ByPawn[my_shi_num]);

	// fen 4k1C2/1nC1a4/3a5/p5N2/2b6/P1B6/4r4/4B4/9/3AKA3 b - - 0 1
	if(EV_MY_CAN == 0){
		MY_EV_SUB(64);
	}

}

//void m_MT_B_2pao1ma1pawn_R_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_CheMaXPawn_To_2Pao1Ma_ByPawn[board->B_shi];
//		}
//	}
//
//	*/
//}



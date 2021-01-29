#ifndef END_my_m_MT_R_1pao3pawn_B_2pawn
#define END_my_m_MT_R_1pao3pawn_B_2pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮3兵对2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1pao3pawn_B_2pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1PaoXPawn_To_2Pawn_ByPaoPawn[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1PaoXPawn_To_2Pawn_ByPawnSide[my_shi_num]);

	MY_EV_ADD(ADD_1PaoXPawn_2Pawn);
}

//
//void m_MT_B_1pao3pawn_R_2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore +=  ADD_1PaoXPawn_To_2Pawn_ByPawnSide[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -=  ADD_1PaoXPawn_To_2Pawn_ByPaoPawn[board->R_shi];
//		}
//	}
//
//
//	board->mulScore -= ADD_1PaoXPawn_2Pawn;
//
//	*/
//}



//const int  ADD_1PaoXPawn_2Pawn                      = 128;              //1炮x兵对2兵的加分
//const int  ADD_1PaoXPawn_To_2Pawn_ByPaoPawn[3]      = {96,  64, 32};
//const int  ADD_1PaoXPawn_To_2Pawn_ByPawnSide[3]     = {80,  48, 16};
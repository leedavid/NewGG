#ifndef END_my_m_MT_R_1pao_1ma4pawn_B_1che
#define END_my_m_MT_R_1pao_1ma4pawn_B_1che
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮1马4兵对1车.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

void my_m_MT_R_1pao_1ma4pawn_B_1che(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao1MaXPawn_To_1Che_PawnByShi[your_shi_num]);
}


//void m_MT_B_1pao_1ma4pawn_R_1che(typePOS &POSITION, EvalInfo &ei){
///*
//
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1Pao1MaXPawn_To_1Che_PawnByShi[board->R_shi];
//		}
//	}
//
//
//	*/
//}


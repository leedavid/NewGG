#ifndef END_my_m_MT_R_2che1ma1pawn_B_2che
#define END_my_m_MT_R_2che1ma1pawn_B_2che
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2车1马1兵对2车.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//ADD_1Pao1MaXPawn_2Ma_ByPawnShi

void my_m_MT_R_2che1ma1pawn_B_2che(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2che1maXpawn_2che_ByShi[your_shi_num]);
}

//void m_MT_B_2che1ma1pawn_R_2che(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2che1maXpawn_2che_ByShi[board->R_shi];
//		}
//
//	}
//
//	*/
//}
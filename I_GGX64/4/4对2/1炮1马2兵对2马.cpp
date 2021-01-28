#ifndef END_my_m_MT_R_1ma1pao2pawn_B_2ma
#define END_my_m_MT_R_1ma1pao2pawn_B_2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马2兵对2马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//ADD_1Pao1MaXPawn_2Ma_ByPawnShi

void my_m_MT_R_1ma1pao2pawn_B_2ma(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1Pao1MaXPawn_2Ma_ByPawnShi[your_shi_num]);
}
//
//void m_MT_B_1ma1pao2pawn_R_2ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1Pao1MaXPawn_2Ma_ByPawnShi[board->R_shi];
//		}
//
//	}
//
//	*/
//}
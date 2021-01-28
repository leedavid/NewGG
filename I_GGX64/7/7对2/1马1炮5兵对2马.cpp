#ifndef END_my_m_MT_R_1ma1pao5pawn_B_2ma
#define END_my_m_MT_R_1ma1pao5pawn_B_2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马1炮5兵对2马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1ma1pao5pawn_B_2ma(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	// ADD 
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao1MaXPawn_2Ma_ByPawnShi[your_shi_num]);
}

//void m_MT_B_1ma1pao5pawn_R_2ma(typePOS &POSITION, EvalInfo &ei){
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
#ifndef END_my_m_MT_R_1che1pao4pawn_B_2che1ma
#define END_my_m_MT_R_1che1pao4pawn_B_2che1ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1炮4兵对2车1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

void my_m_MT_R_1che1pao4pawn_B_2che1ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Che1PaoXPawn_2Che1Ma_ByPawnShi[your_shi_num]);
}

//void m_MT_B_1che1pao4pawn_R_2che1ma(typePOS &POSITION, EvalInfo &ei){
//
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -=  ADD_1Che1PaoXPawn_2Che1Ma_ByPawnShi[board->R_shi];;
//		}
//	}
//
//	*/
//}
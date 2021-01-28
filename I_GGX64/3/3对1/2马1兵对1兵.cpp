#ifndef END_my_m_MT_R_2ma_1pawn_B_1pawn
#define END_my_m_MT_R_2ma_1pawn_B_1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2马1兵对1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 




void my_m_MT_R_2ma_1pawn_B_1pawn(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2MaXPawn_1Pawn[your_shi_num]);

	MY_EV_ADD(32);

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	// fen 4k4/1N2aP3/b2ab4/9/9/2P6/9/B7B/4K2p1/9 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1 && StoY(ypawn) MY_LARGE_EQL MY_RANK4){
		bmp = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
		if(count_1s(bmp) == 1){
			if(EV_MY_CAN <= 1){
				RETRUN_MUL(4);
			}
		}
	}
}



//void m_MT_B_2ma_1pawn_R_1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2MaXPawn_1Pawn[board->R_shi];
//		}
//	}
//
//
//	*/
//}
#ifndef END_my_m_MT_R_1pao1ma3pawn_B_2pao1ma
#define END_my_m_MT_R_1pao1ma3pawn_B_2pao1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1ÅÚ1Âí3±ø¶Ô2ÅÚ1Âí.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//ADD_1PaoXPawn_1PaoXPawn_ByShi

void my_m_MT_R_1pao1ma3pawn_B_2pao1ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2pao1ma_1pao1maXpawn_ByShi[your_shi_num]);

	// fen 4kab2/3ca4/4b4/1C3P3/P2N5/6P2/1c5n1/4B4/4A4/2BAK4 w - - 0 1
	if(StoY(yk) == MY_RANK0){
		if(your_shi_num == 2 && your_xiang_num == 2){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK2])){
				MY_EV_SUB(32);
				if(StoY(yma) MY_LARGE_EQL MY_RANK5){
					MY_EV_SUB(16);
				}
			}
		}
	}
}

//void m_MT_B_1pao1ma3pawn_R_2pao1ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	//int rcan = RpawnAlreadyRiver(board);
//	//int bcan = BpawnAlreadyRiver(board);
//	//
//	//for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//	//	if(StoY(from) > StoY(bk)){
//	//		board->mulScore += ADD_2pao1ma_2pao1pawn_ByShi[board->B_shi];
//	//	}
//	//}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2pao1ma_1pao1maXpawn_ByShi[board->R_shi];
//		}
//	}
//
//
//	//board->mulScore += rcan * 64;
//	//board->mulScore -= bcan * 64;
//
//	*/
//}
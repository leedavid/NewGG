#ifndef END_my_m_MT_R_1che4pawn_B_1che1pawn
#define END_my_m_MT_R_1che4pawn_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1³µ4±ø¶Ô1³µ1±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



//const int PawnAdd = 32;

void my_m_MT_R_1che4pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePawn_To_ChePawnByShi[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_ChePawn_To_ChePawnByShi[my_shi_num]);


	if(my_shi_num >= 1 || EV_YOUR_CAN == 0){
		EV_MY_SAFE = TRUE;
	}

	// fen 2ba5/5k3/b4a3/5R2p/7r1/9/P3P1P1P/8B/4A4/3AK4 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(EV_MY_CAN <= 3 && !have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3akab2/9/4b4/9/P2P4p/4P1r2/4R3P/9/4K4/9 b - - 0 1
	if(EV_YOUR_CAN == 0){
		MY_EV_ADD(EV_MY_CAN * 16);
	}
}

//void m_MT_B_1che4pawn_R_1che1pawn(typePOS &POSITION, EvalInfo &ei){
//	/*
//    Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_ChePawn_To_ChePawnByShi[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_ChePawn_To_ChePawnByShi[board->R_shi];
//		}
//	}
//
//	*/
//
//}
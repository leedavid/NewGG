#ifndef END_my_m_MT_R_2pao1ma3pawn_B_2pao1ma1pawn
#define END_my_m_MT_R_2pao1ma3pawn_B_2pao1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2ÅÚ1Âí3±ø¶Ô2ÅÚ1Âí1±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int ADD_2Pao1MaXpawn_To_1Pao2Ma1Pawn_ByPawn[3]     = { 96, 64, 32};   //
//const int ADD_2Pao1Ma1pawn_To_1Pao2MaXPawn_ByPawn[3]     = { 96, 64, 32};   //


void my_m_MT_R_2pao1ma3pawn_B_2pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2Pao1MaXpawn_To_2Pao1Ma1Pawn_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_2Pao1Ma1pawn_To_2Pao1MaXPawn_ByPawn[my_shi_num]);

	MY_EV_ADD(EV_MY_CAN * 16);
	// fen 2bak4/C3a4/4c4/4PP2C/p4N3/5c3/P8/4B4/4K1n2/9 b - - 0 1
	if(EV_YOUR_CAN == 0){
		MY_EV_ADD(EV_MY_CAN * 16);
	}
	// fen 5k3/4ac3/5a2b/2N3C1P/4P4/6P2/n6c1/4K2C1/5p3/2B6 b - - 0 1
	if(StoY(ypawn) MY_LARGE_EQL StoY(mk)){
		MY_EV_ADD(EV_MY_CAN * 16);
	}

	Square mma = S90_from_piecelist(POSITION,my_ma,0);

	// fen 3k1ab2/4a4/9/9/6b2/6N2/8P/4BA3/4K4/1r4B2 w - - 0 1
	if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
		MY_EV_SUB(32);
		if(StoY(mk) != MY_RANK9 && StoY(ypawn) MY_LARGE_EQL MY_RANK5){
			if(StoY(mma) MY_LARGE_EQL MY_RANK6){
				MY_EV_SUB(64);
			}
		}
	}
}

//void m_MT_B_2pao1ma3pawn_R_2pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_2Pao1Ma1pawn_To_2Pao1MaXPawn_ByPawn[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2Pao1MaXpawn_To_2Pao1Ma1Pawn_ByPawn[board->R_shi];
//		}
//	}
//
//	*/
//}
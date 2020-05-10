#ifndef END_my_m_MT_R_1pao1ma3pawn_B_1pao2ma_a
#define END_my_m_MT_R_1pao1ma3pawn_B_1pao2ma_a
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1ÅÚ1Âí3±ø¶Ô1ÅÚ2Âí.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//ADD_1PaoXPawn_1PaoXPawn_ByShi

void my_m_MT_R_1pao1ma3pawn_B_1pao2ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1pao2ma_1pao1maXpawn_ByShi[your_shi_num]);

	MY_EV_SUB(32);

	// fen 2bak1b2/4a4/1P7/9/5C2P/2N1n1P2/P1cn5/3AB4/9/2BAK4 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2){
		Bitboard mp = m_and(bb_my_pawn,MyLowBB[MY_RANK4]);
		Bitboard lr = m_or(m_and(bb_my_pawn,LeftBB[0x2]),m_and(bb_my_pawn,RightBB[0x6]));
		MY_EV_SUB((sint16)count_1s(m_or(mp,lr)) * 16);
	}
}

//void m_MT_B_1pao1ma3pawn_R_1pao2ma(typePOS &POSITION, EvalInfo &ei){
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
//			board->mulScore -= ADD_1pao2ma_1pao1maXpawn_ByShi[board->R_shi];
//		}
//	}
//
//
//	//board->mulScore += rcan * 64;
//	//board->mulScore -= bcan * 64;
//
//	*/
//}
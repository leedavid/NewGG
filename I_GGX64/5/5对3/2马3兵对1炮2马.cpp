#ifndef END_my_m_MT_R_2ma3pawn_B_1pao2ma
#define END_my_m_MT_R_2ma3pawn_B_1pao2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2Âí3±ø¶Ô1ÅÚ2Âí.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//ADD_1PaoXPawn_1PaoXPawn_ByShi
// fen 1N1k1a3/1N7/3a5/9/4C3p/4p4/4p3n/4B4/1n7/2BA1K3 b - - 0 0</
void my_m_MT_R_2ma3pawn_B_1pao2ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1pao2ma_2maXpawn_ByShi[your_shi_num]);

	if((my_shi_num + my_xiang_num) <= 2){
		MY_EV_SUB(168);
	}

	//fen 3a1a3/4k4/8c/5Nn2/8P/4P1B2/P8/6n2/6N2/2BAKA3 b - - 0 1
	Bitboard lp = My_get_connect_Pawn(POSITION);
	if (!m_have_bit(lp)){
		MY_EV_SUB(32);
		if (your_shi_num == 2){
			if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK3])){
				MY_EV_SUB(32);
			}
		}
	}
}

//void m_MT_B_2ma3pawn_R_1pao2ma(typePOS &POSITION, EvalInfo &ei){
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
//			board->mulScore -= ADD_1pao2ma_2maXpawn_ByShi[board->R_shi];
//		}
//	}
//
//
//	//board->mulScore += rcan * 64;
//	//board->mulScore -= bcan * 64;
//
//	*/
//}
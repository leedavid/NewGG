#ifndef END_my_m_MT_R_1pao1ma5pawn_B_1pao2ma
#define END_my_m_MT_R_1pao1ma5pawn_B_1pao2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1ÅÚ1Âí5±ø¶Ô1ÅÚ2Âí.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



//ADD_1PaoXPawn_1PaoXPawn_ByShi

void my_m_MT_R_1pao1ma5pawn_B_1pao2ma(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	Square mma = S90_from_piecelist(POSITION, my_ma, 0);
	int mcan = EV_MY_CAN;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1pao2ma_1pao1maXpawn_ByShi[your_shi_num]);

	MY_EV_ADD(mcan * ADD_2pao1ma_1pao1maXpawn_ByShi[your_shi_num]);

	//fen 9/C3k4/3N1aNn1/6p2/9/3pp3p/1p5c1/9/4A4/4KAB2 w - - 0 1
	if ((my_shi_num + my_xiang_num) <= 1){
		if (StoY(mma) MY_LARGE_EQL MY_RANK6){
			MY_EV_SUB(32);
		}	
		MY_EV_SUB(32);
	}

}

//void m_MT_B_1pao1ma5pawn_R_1pao2ma(typePOS &POSITION, EvalInfo &ei){
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
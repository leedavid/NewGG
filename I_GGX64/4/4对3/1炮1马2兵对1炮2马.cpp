#ifndef END_my_m_MT_R_1pao1ma2pawn_B_1pao2ma
#define END_my_m_MT_R_1pao1ma2pawn_B_1pao2ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮1马2兵对1炮2马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



//ADD_1PaoXPawn_1PaoXPawn_ByShi

void my_m_MT_R_1pao1ma2pawn_B_1pao2ma(typePOS &POSITION, EvalInfo &ei){
	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1pao2ma_1pao1maXpawn_ByShi[your_shi_num]);
	
	// fen 5kb2/4a4/4ba3/8p/p8/5n3/2N6/4C4/2C1K4/3A1A2c w - - 0 1
	if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
		MY_EV_SUB(32);
		if(!have_bit(bb_my_pawn,m_and(LeftBB[0x7],RightBB[0x1]))){
			MY_EV_SUB(16);
		}
	}
	if(!have_bit(bb_my_pawn,m_and(LeftBB[0x7],RightBB[0x1]))){
		MY_EV_SUB(32);
	}
}

//void m_MT_B_1pao1ma2pawn_R_1pao2ma(typePOS &POSITION, EvalInfo &ei){
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
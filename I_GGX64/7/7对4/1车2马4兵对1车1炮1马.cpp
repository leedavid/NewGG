#ifndef END_my_m_MT_R_1che2ma4pawn_B_1che1pao1ma
#define END_my_m_MT_R_1che2ma4pawn_B_1che1pao1ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车2马4兵对1车1炮1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1che2ma4pawn_B_1che1pao1ma(typePOS &POSITION, EvalInfo &ei){

	Square yma  = S90_from_piecelist(POSITION,your_ma,0);
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1che2ma1pawn_1che1pao1ma_ByShi[your_shi_num]);

	// fen 3k2b2/n3a4/3ab4/5RN2/3NP4/P1P6/1r6P/c8/4K4/9 b - - 0 1
	if(StoY(yma) MY_SMALL_EQL MY_RANK3){
		MY_EV_ADD(EV_MY_CAN * 16);
		if(StoY(ypao) MY_LARGE_EQL MY_RANK5){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}
}

//void m_MT_B_1che2ma4pawn_R_1che1pao1ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);	
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1che2ma1pawn_1che1pao1ma_ByShi[board->R_shi];
//		}
//	}
//
//
//
//	*/
//}
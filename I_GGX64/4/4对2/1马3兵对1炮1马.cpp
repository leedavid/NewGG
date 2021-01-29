#ifndef END_my_m_MT_R_1ma3pawn_B_1pao1ma
#define END_my_m_MT_R_1ma3pawn_B_1pao1ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1马3兵对1炮1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//


// 马兵对炮马
void my_m_MT_R_1ma3pawn_B_1pao1ma(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_MaPawn_To_1Pao1Ma_ByShi[your_shi_num]);

	// fen 2ba1k2c/4a4/9/7N1/1n7/P8/4P3P/4B4/4A4/2BAK4 w - - 0 1
	if(your_shi_num >= 1){
		MY_EV_SUB(32);
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK4])){
			MY_EV_SUB(32);
		}
	}
}
//
//void m_MT_B_1ma3pawn_R_1pao1ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_MaPawn_To_1Pao1Ma_ByShi[board->R_shi];
//		}
//	}
//	*/
//}
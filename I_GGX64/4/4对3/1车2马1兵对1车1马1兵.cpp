#ifndef END_my_m_MT_R_1che2ma1pawn_B_1che1ma1pawn
#define END_my_m_MT_R_1che2ma1pawn_B_1che1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车2马1兵对1车1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

void my_m_MT_R_1che2ma1pawn_B_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){
	// ADD_MY
	//Square yk = your_king_pos;

	Square yma  = S90_from_piecelist(POSITION,your_ma,0);

	// fen 2bk1a3/4a4/4b4/3N4p/1N4n2/6R1P/4r4/9/5K3/9 b - - 0 1
	if(StoY(yma) MY_SMALL_EQL MY_RANK4){
		MY_EV_ADD(32);
	}
	if(EV_YOUR_CAN == 0){
		MY_EV_ADD(32);
		if(StoY(yma) MY_SMALL_EQL MY_RANK4){
			MY_EV_ADD(32);
			if(!have_bit(bb_my_ma,MyLowBB[MY_RANK6])){
				MY_EV_ADD(32);
			}
		}
	}
}

//void m_MT_B_1che2ma1pawn_R_1che1pao1ma(typePOS &POSITION, EvalInfo &ei){
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
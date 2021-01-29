#ifndef END_my_m_MT_R_1che1ma3pawn_B_1che2pawn
#define END_my_m_MT_R_1che1ma3pawn_B_1che2pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1马3兵对1车2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

void my_m_MT_R_1che1ma3pawn_B_1che2pawn(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheMaXPawn_VS_1Che2Pawn_ByShi[your_shi_num]);

	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1Che2Pawn_VS_CheMaXPawn_ByShi[my_shi_num]);

	// fen 4kab2/4a4/4b1R2/p1P1p4/6p2/3NP4/P8/9/5K3/3r5 w - - 0 1
	if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK5])){
		MY_EV_ADD(EV_MY_CAN * 16);
	}

	// fen 2b1ka3/4aP3/4b4/1Nr6/1P6p/9/4p3P/5R3/9/3K5 b - - 0 1
	if(EV_YOUR_CAN <= 1){
		if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK6])){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

}

//void m_MT_B_1che1ma3pawn_R_1che2pawn(typePOS &POSITION, EvalInfo &ei){
//
///*
//    Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_1Che2Pawn_VS_CheMaXPawn_ByShi[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_CheMaXPawn_VS_1Che2Pawn_ByShi[board->R_shi];
//		}
//	}
//
//	*/
//}
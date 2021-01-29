#ifndef END_my_m_MT_R_1che5pawn_B_1che2pawn
#define END_my_m_MT_R_1che5pawn_B_1che2pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车5兵对1车2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1che5pawn_B_1che2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePawn_To_ChePawnByShi[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_ChePawn_To_ChePawnByShi[my_shi_num]);

	// fen 2baka3/9/4b4/R8/6p1p/4P4/P1P3P1P/9/3rA4/2B1KAB2 b - - 0 1
	if(EV_YOUR_CAN <= 1){
		if(my_shi_num >= 1){
			EV_MY_SAFE = TRUE;
		}
	}
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		EV_MY_SAFE = TRUE;
	}

	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
				RETRUN_MUL(4);
			}
		}
	}
}

//void m_MT_B_1che5pawn_R_1che2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//    Square bk    = PieceListStart(board,BKING);
//	Square rk    = PieceListStart(board,RKING);
//
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
//}
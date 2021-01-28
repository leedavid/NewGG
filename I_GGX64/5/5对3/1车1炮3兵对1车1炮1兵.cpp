#ifndef END_my_m_MT_R_1che1pao3pawn_B_1che1pao1pawn
#define END_my_m_MT_R_1che1pao3pawn_B_1che1pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮3兵对1车1炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1che1pao3pawn_B_1che1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoPawn_ChePao1pawn_ByPawnByShi[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_ChePaoPawn_ChePao1pawn_ByPawnByShi[my_shi_num]);

	Square ypao = S90_from_piecelist(POSITION,your_pao,0);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	// fen 2b1kacC1/4a4/4b4/8p/R8/4P3P/P8/3A5/3K5/5r3 w - - 0 1
	if(EV_YOUR_CAN == 0){
		if(bit_is_set(EV_MY_XBIT,ypao) && StoY(ypao) == MY_RANK0){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
		// fen 3aka3/9/2C1b4/p3R4/9/P1P1P4/9/4BK3/3r5/c1B6 b - - 0 1
		MY_EV_ADD(EV_MY_CAN * 16);
		if(my_xiang_num == 2){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 4k1b2/4a4/4b4/C8/4P3p/2P3R2/P3cr3/3A5/4K4/6B2 w - - 0 1
	if(StoY(ypawn) MY_SMALL_EQL MY_RANK4){
		MY_EV_ADD(EV_MY_CAN * 16);
	}
	if(abs(StoX(ypawn) - 0x4) == 4){
		MY_EV_ADD(EV_MY_CAN * 16);
	}
}
//
//void m_MT_B_1che1pao3pawn_R_1che1pao1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_ChePaoPawn_ChePao1pawn_ByPawnByShi[board->B_shi]/2;
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_ChePaoPawn_ChePao1pawn_ByPawnByShi[board->R_shi];
//		}
//	}
//
//	*/
//}
#ifndef END_my_m_MT_R_1che1pao4pawn_B_1che2pao1pawns
#define END_my_m_MT_R_1che1pao4pawn_B_1che2pao1pawns
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1炮4兵对1车2炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che1pao4pawn_B_1che2pao1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	//
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoPawn_ChePao1pawn_ByPawnByShi[your_shi_num]);

	Square mk = my_king_pos;
	//
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_ChePaoPawn_ChePao1pawn_ByPawnByShi[my_shi_num]);

	// fen 2b1ka3/9/c8/C5R1p/2P1P4/3r5/6P1P/4BA3/1c2K4/2B6 b - - 0 1
	if(your_shi_num <= 1 && your_xiang_num <= 1 && EV_YOUR_CAN == 0){
		if(my_xiang_num == 2){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}
}

//void m_MT_B_1che1pao4pawn_R_2pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_ChePaoXPawn_To_2Pao1Ma_ByPawn[board->R_shi];
//		}
//	}
//
//	*/
//}



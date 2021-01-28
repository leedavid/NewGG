#ifndef END_my_m_MT_R_1che1pao4pawn_B_1che1ma
#define END_my_m_MT_R_1che1pao4pawn_B_1che1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮4兵对1车1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1che1pao4pawn_B_1che1ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoPawn_CheMa_ByPawnByShi[your_shi_num]);

	// fen 3k1ab2/4a4/4b4/C3R4/1r7/P8/8P/3A5/3KA1n2/9 b - - 0 1
	if(my_shi_num == 2 || my_xiang_num == 2){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			MY_EV_ADD(EV_MY_CAN * 16);
			if(!IsOnSameSide(yma,mk)){
				MY_EV_ADD(EV_MY_CAN * 16);
			}
		}
	}
}
//
//void m_MT_B_1che1pao4pawn_R_1che1ma(typePOS &POSITION, EvalInfo &ei){
//	/*
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -=  ADD_ChePaoPawn_CheMa_ByPawnByShi[board->R_shi];
//		}
//
//	}
//
//	*/
//}

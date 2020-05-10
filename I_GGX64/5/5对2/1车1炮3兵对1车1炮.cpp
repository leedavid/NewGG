#ifndef END_my_m_MT_R_1che1pao3pawn_B_1che1pao
#define END_my_m_MT_R_1che1pao3pawn_B_1che1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1³µ1ÅÚ3±ø¶Ô1³µ1ÅÚ.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1che1pao3pawn_B_1che1pao(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoPawn_ChePao_ByPawnByShi[your_shi_num]);

	if((my_shi_num + my_xiang_num) >= 1){
		MY_EV_ADD(ADD_ChePaoPawn_ChePao_ByShiXiang);
	}
}

//void m_MT_B_1che1pao3pawn_R_1che1pao(typePOS &POSITION, EvalInfo &ei){
//	/*
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= ADD_ChePaoPawn_ChePao_ByPawnByShi[board->R_shi];
//		}
//	}
//	if((board->B_shi + board->B_xiang) != 0){
//		board->mulScore -= ADD_ChePaoPawn_ChePao_ByShiXiang;
//	}
//
//	*/
//}

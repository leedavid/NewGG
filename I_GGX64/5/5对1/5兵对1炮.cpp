#ifndef END_my_m_MT_R_5pawn_B_1pao
#define END_my_m_MT_R_5pawn_B_1pao
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "5兵对1炮.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int _3pawn1pao_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_5pawn_B_1pao(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_XPawnToPao_ByPawnShi[your_shi_num]);
	
}
//
//void m_MT_B_5pawn_R_1pao(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -=  ADD_XPawnToPao_ByPawnShi[board->R_shi];
//
//			//if(StoX(from) == 0x7){  //兵在中线
//			//	if(board->b256[from+1] == RPAWN || board->b256[
//			//}
//		}
//	}
//	*/
//}
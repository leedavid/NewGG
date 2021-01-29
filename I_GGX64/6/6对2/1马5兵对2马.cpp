#ifndef END_my_m_MT_R_1ma5pawn_B_2ma
#define END_my_m_MT_R_1ma5pawn_B_2ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1马5兵对2马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//


// 马兵对2马
void my_m_MT_R_1ma5pawn_B_2ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_MaPawn_To_2Ma_ByShi[your_shi_num]);
}

//void m_MT_B_1ma5pawn_R_2ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_MaPawn_To_2Ma_ByShi[board->R_shi];
//		}
//	}
//
//	*/
//}
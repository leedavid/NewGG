#ifndef END_my_m_MT_R_2che1pao1pawn_B_2che1pao
#define END_my_m_MT_R_2che1pao1pawn_B_2che1pao
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2车1炮1兵对2车1炮.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 




void my_m_MT_R_2che1pao1pawn_B_2che1pao(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_MT_2che1pao1pawn_2che1pao_ByShi[your_shi_num]);

}
//
//void m_MT_B_2che1pao1pawn_R_2che1pao(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_MT_2che1pao1pawn_2che1pao_ByShi[board->R_shi];
//		}
//	}
//
//	*/
//}
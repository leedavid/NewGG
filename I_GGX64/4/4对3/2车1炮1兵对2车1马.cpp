#ifndef END_my_m_MT_R_2che1pao1pawn_B_2che1ma
#define END_my_m_MT_R_2che1pao1pawn_B_2che1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2车1炮1兵对2车1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_2che1pao1pawn_B_2che1ma(typePOS &POSITION, EvalInfo &ei){
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_MT_2che1pao1pawn_2che1ma_ByShi[your_shi_num]);

	// fen 2b1ka3/4a4/3nb4/9/8r/PR1R4C/8r/4B4/4A4/2B1KA3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
		Bitboard cmpp = m_or(bb_my_pao,m_or(bb_my_pawn,bb_my_che));
		if(count_1s(cmpp) == 4){
			MY_EV_SUB(64);
		}
	}

}
//
//void m_MT_B_2che1pao1pawn_R_2che1ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_MT_2che1pao1pawn_2che1ma_ByShi[board->R_shi];
//		}
//	}
//
//	*/
//}
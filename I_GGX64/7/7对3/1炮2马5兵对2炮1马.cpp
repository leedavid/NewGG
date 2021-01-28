#ifndef END_my_m_MT_R_1pao2ma5pawn_B_2pao1ma
#define END_my_m_MT_R_1pao2ma5pawn_B_2pao1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮2马5兵对2炮1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 




void my_m_MT_R_1pao2ma5pawn_B_2pao1ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// 
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao2MaXpawn_To_2Pao1Ma_ByPawn[your_shi_num]);
}

//void m_MT_B_1pao2ma5pawn_R_2pao1ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_2Pao1Ma_To_1Pao2MaXpawn_ByPawn[board->B_shi];
//		}
//
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1Pao2MaXpawn_To_2Pao1Ma_ByPawn[board->R_shi];
//		}
//	}
//
//
//
//	*/
//}
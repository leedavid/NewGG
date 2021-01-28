#ifndef END_my_m_MT_R_1pao1ma5pawn_B_2pao1pawn
#define END_my_m_MT_R_1pao1ma5pawn_B_2pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马5兵对2炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 




void my_m_MT_R_1pao1ma5pawn_B_2pao1pawn(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1pao1maXpawn_To_2ma1pawn_ByPs[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1pao1maXpawn_To_2ma1pawn_ByPs[my_shi_num]);

	MY_EV_ADD(ADD_1pao1maXpawn_To_2ma1pawn);
}

//void m_MT_B_1pao1ma5pawn_R_2ma1pawn(typePOS &POSITION, EvalInfo &ei){
//	/*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_1pao1maXpawn_To_2ma1pawn_ByPs[board->B_shi];
//		}
//
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1pao1maXpawn_To_2ma1pawn_ByPs[board->R_shi];
//		}
//	}
//
//	board->mulScore -= ADD_1pao1maXpawn_To_2ma1pawn;
//
//	*/
//}
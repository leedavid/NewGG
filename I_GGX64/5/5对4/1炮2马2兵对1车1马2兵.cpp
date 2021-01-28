#ifndef END_my_m_MT_R_1pao2ma2pawn_B_1che1ma2pawn
#define END_my_m_MT_R_1pao2ma2pawn_B_1che1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮2马2兵对1车1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1pao2ma2pawn_B_1che1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_CheMaXPawn_To_1Pao2Ma_ByPawn[my_shi_num]);
}
//
//void m_MT_B_1pao2ma2pawn_R_1che1ma2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_CheMaXPawn_To_1Pao2Ma_ByPawn[board->B_shi];
//		}
//	}
//
//	*/
//}
//


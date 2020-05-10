#ifndef END_my_m_MT_R_2ma3pawn_B_1pao2pawn
#define END_my_m_MT_R_2ma3pawn_B_1pao2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2马3兵对1炮2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//
//const int  ADD_2MaXPawn_2Pao1Pawn_ByPawn[3]         = {96, 64, 32};            //2马x兵对1炮2兵, 多兵的加分
//const int  ADD_2Pao1Pawn_2MaXPawn_ByPawn[3]         = {96, 64, 32};            //1炮2兵对2马x兵, 多兵的加分



void my_m_MT_R_2ma3pawn_B_1pao2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2MaXPawn_1Pao2Pawn_ByPawn[your_shi_num]);

	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1Pao2Pawn_2MaXPawn_ByPawn[my_shi_num]);

}

//void m_MT_B_2ma3pawn_R_1pao2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_1Pao2Pawn_2MaXPawn_ByPawn[board->B_shi];
//		}
//	}
//
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2MaXPawn_1Pao2Pawn_ByPawn[board->R_shi];
//		}
//	}
//
//	*/
//
//}

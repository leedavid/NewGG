#ifndef END_my_m_MAT_R_1pao1ma2pawn_B_1ma2pawn
#define END_my_m_MAT_R_1pao1ma2pawn_B_1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马2兵对1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1pao1ma2pawn_B_1ma2pawn(typePOS &POSITION, EvalInfo &ei){
	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1pao1maXpawn_To_1ma2pawn_ByPs[your_shi_num]);

	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1pao1maXpawn_To_1ma2pawn_ByPs[my_shi_num]);

	MY_EV_ADD(ADD_1pao1maXpawn_To_1ma2pawn);

}

//void m_MAT_B_1pao1ma2pawn_R_1ma2pawn(typePOS &POSITION, EvalInfo &ei){
//	/*
//	Square rk = PieceListStart(pos,RKING);
//	Square bk = PieceListStart(pos,BKING);
//	
//	for(int from = PieceListStart(pos,RPAWN); from > 0x32; from = NextPiece(pos,from)){
//		if(StoY(from) > StoY(bk)){
//			pos.mulScore += ADD_1pao1maXpawn_To_1ma2pawn_ByPs[pos.B_shi];
//		}
//
//	}
//
//	for(int from = PieceListStart(pos,BPAWN); from > 0x32; from = NextPiece(pos,from)){
//		if(StoY(from) < StoY(rk)){
//			pos.mulScore -= ADD_1pao1maXpawn_To_1ma2pawn_ByPs[pos.R_shi];
//		}
//	}
//
//	pos.mulScore -= ADD_1pao1maXpawn_To_1ma2pawn;
//
//	*/
//}
#ifndef END_my_m_MAT_R_1ma1pao2pawn_B_1pao1pawn
#define END_my_m_MAT_R_1ma1pao2pawn_B_1pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马2兵对1炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1ma1pao2pawn_B_1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[my_shi_num]);

	MY_EV_ADD(96);
	
}
//
//void m_MAT_B_1ma1pao2pawn_R_1pao1pawn(typePOS &POSITION, EvalInfo &ei){
//	/*
//	for(int from = PieceListStart(pos,BPAWN); from > 0x32; from = NextPiece(pos,from)){
//		if(StoY(from) < 0xc){
//			pos.mulScore -= 96;
//		}
//
//	}
//
//	for(int from = PieceListStart(pos,RPAWN); from > 0x32; from = NextPiece(pos,from)){
//		if(StoY(from) > 0x3){
//			pos.mulScore += 96;
//		}
//
//	}
//
//	pos.mulScore -= ADD_MAPAO_Xpawn_To_PAO1Pawn ;
//
//	*/
//}
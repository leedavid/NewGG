#ifndef END_my_m_MAT_R_1ma1pao2pawn_B_1ma1pawn
#define END_my_m_MAT_R_1ma1pao2pawn_B_1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马2兵对1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1ma1pao2pawn_B_1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_MaPawn_To_PaoPawnByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_MaPawn_To_PaoPawnByShi[my_shi_num]);

	MY_EV_ADD(MaPaoXPawn_MaPawn);

}

//void m_MAT_B_1ma1pao2pawn_R_1ma1pawn(typePOS &POSITION, EvalInfo &ei){
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
//	//马炮方另外加分
//	pos.mulScore -= MaPaoXPawn_MaPawn ;
//
//	*/
//}
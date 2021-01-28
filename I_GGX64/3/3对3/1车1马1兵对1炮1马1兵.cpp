#ifndef END_my_m_MT_R_1che1ma1pawn_B_1pao1ma1pawn
#define END_my_m_MT_R_1che1ma1pawn_B_1pao1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1马1兵对1炮1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 





void my_m_MT_R_1che1ma1pawn_B_1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_CheMaXPawn_To_1Pao1Ma1Pawn_ByPawn[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1Pao1Ma1Pawn_To_CheMaXPawn_ByPawn[my_shi_num]);
}


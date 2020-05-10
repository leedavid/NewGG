#ifndef END_my_m_MT_R_1che2pawn_B_3pawn
#define END_my_m_MT_R_1che2pawn_B_3pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1³µ2±ø¶Ô3±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che2pawn_B_3pawn(typePOS &POSITION, EvalInfo &ei){
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_CheXPawn_To_PawnByShi[your_shi_num]);

	MY_EV_ADD(ADD_CheXPawn_To_3Pawn);
}


#ifndef END_my_m_MT_R_2pao1ma3pawn_B_1pao2ma2pawn
#define END_my_m_MT_R_2pao1ma3pawn_B_1pao2ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2ÅÚ1Âí3±ø¶Ô1ÅÚ2Âí2±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_2pao1ma3pawn_B_1pao2ma2pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2Pao1Ma3pawn_To_1Pao2Ma3Pawn_ByPawn[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_2Pao1Ma3pawn_To_1Pao2Ma3Pawn_ByPawn[my_shi_num]);

	//int mcan = EV_MY_CAN;
	//int ycan = EV_YOUR_CAN;

	//MY_EV_ADD(mcan * 32);
	//MY_EV_SUB(ycan * 32);
}
#ifndef END_my_m_MT_R_1pao4pawn_B_3pawn
#define END_my_m_MT_R_1pao4pawn_B_3pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮4兵对3兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};


void my_m_MT_R_1pao4pawn_B_3pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1PaoXPawn_3pawn_ShiAdd[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_3pawn_PaoXPawn_ShiAdd[my_shi_num]);

	MY_EV_ADD(ADD_1PaoXPawn_3Pawn);
}


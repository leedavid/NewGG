#ifndef END_my_m_MT_R_2pao5pawn_B_2pao1pawn
#define END_my_m_MT_R_2pao5pawn_B_2pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮5兵对2炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



//ADD_2PaoXPawn_2Pao1Pawn_ByPawnShi


void my_m_MT_R_2pao5pawn_B_2pao1pawn(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2PaoXPawn_2Pao1Pawn_ByPawnShi[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_2Pao1Pawn_2PaoXPawn_ByPawnShi[my_shi_num]);
}


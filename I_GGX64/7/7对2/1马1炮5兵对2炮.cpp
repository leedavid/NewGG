#ifndef END_my_m_MT_R_1ma1pao5pawn_B_2pao
#define END_my_m_MT_R_1ma1pao5pawn_B_2pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1Âí1ÅÚ5±ø¶Ô2ÅÚ.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1ma1pao5pawn_B_2pao(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	// ADD 
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao1MaXPawn_2Pao_ByPawnShi[your_shi_num]);
}


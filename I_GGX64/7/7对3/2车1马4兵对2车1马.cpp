#ifndef END_my_m_MT_R_2che1ma4pawn_B_2che1ma
#define END_my_m_MT_R_2che1ma4pawn_B_2che1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2车1马4兵对2车1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 




void my_m_MT_R_2che1ma4pawn_B_2che1ma(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_MT_2che1ma1pawn_2che1ma_ByShi[your_shi_num]);
}


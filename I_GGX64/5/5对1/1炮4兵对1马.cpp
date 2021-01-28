#ifndef END_my_m_MT_R_1PAO4PAWN_B_1MA
#define END_my_m_MT_R_1PAO4PAWN_B_1MA
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮4兵对1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//炮4兵对1马
void my_m_MT_R_1PAO4PAWN_B_1MA(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1PaoXPawn_1Ma_ByPawn[your_shi_num]);
}


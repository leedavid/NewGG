#ifndef END_my_m_MT_R_2che1ma5pawn_B_2che
#define END_my_m_MT_R_2che1ma5pawn_B_2che
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2车1马5兵对2车.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



//ADD_1Pao1MaXPawn_2Ma_ByPawnShi

void my_m_MT_R_2che1ma5pawn_B_2che(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2che1maXpawn_2che_ByShi[your_shi_num]);
}


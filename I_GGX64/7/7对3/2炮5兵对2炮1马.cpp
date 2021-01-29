#ifndef END_my_m_MT_R_2pao5pawn_B_2pao1ma
#define END_my_m_MT_R_2pao5pawn_B_2pao1ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2炮5兵对2炮1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//ADD_1PaoXPawn_1PaoXPawn_ByShi

void my_m_MT_R_2pao5pawn_B_2pao1ma(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2pao1ma_2paoXpawn_ByShi[your_shi_num]);
	
}


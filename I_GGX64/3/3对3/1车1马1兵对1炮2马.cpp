#ifndef END_my_m_MT_R_1che1ma1pawn_B_1pao2ma
#define END_my_m_MT_R_1che1ma1pawn_B_1pao2ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1马1兵对1炮2马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1che1ma1pawn_B_1pao2ma(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheMaXPawn_To_1Pao2Ma_ByPawn[your_shi_num]);

	// fen N2a1kb2/8c/5a3/3P5/6b2/4Rn3/7n1/4B4/9/3K5 w - - 0 1
	MY_EV_ADD(EV_MY_CAN * 64);
}


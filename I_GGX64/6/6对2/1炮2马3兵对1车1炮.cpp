#ifndef END_my_m_MT_R_1pao2ma3pawn_B_1che1pao
#define END_my_m_MT_R_1pao2ma3pawn_B_1che1pao
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮2马3兵对1车1炮.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1pao2ma3pawn_B_1che1pao(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao2MaXPawn_1Che1Pao_To_ByPawn[your_shi_num]);
}

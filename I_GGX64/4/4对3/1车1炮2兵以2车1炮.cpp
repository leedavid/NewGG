#ifndef END_my_m_MT_R_1che1pao2pawn_B_2che1pao
#define END_my_m_MT_R_1che1pao2pawn_B_2che1pao
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1炮2兵以2车1炮.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1che1pao2pawn_B_2che1pao(typePOS &POSITION, EvalInfo &ei){
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1Che1PaoXPawn_2Che1Pao_ByPawnShi[your_shi_num]);
}


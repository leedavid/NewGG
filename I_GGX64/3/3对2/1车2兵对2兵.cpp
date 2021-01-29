#ifndef END_my_m_MT_R_1che2pawn_B_2pawn
#define END_my_m_MT_R_1che2pawn_B_2pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车2兵对2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1che2pawn_B_2pawn(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_CheXPawn_To_2PawnByShi[your_shi_num]);
}


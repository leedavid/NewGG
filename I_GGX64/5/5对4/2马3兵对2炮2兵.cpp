#ifndef ENDR_my_m_MT_R_2ma3pawn_B_2pao2pawn
#define ENDR_my_m_MT_R_2ma3pawn_B_2pao2pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "2马3兵对2炮2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_2ma3pawn_B_2pao2pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;

	// fen 3k5/2P1a1P2/4ba3/8P/3NcNb2/9/5c3/3K5/2pp5/3A5 b - - 0 1
	if(count_1s(bb_your_pawn,MyLowBB[StoY(mk)]) == 2){
		MY_EV_ADD(EV_MY_CAN * 32);
		if(EV_MY_CAN >= 3){
			MY_EV_ADD(32);
		}
	}
}
#ifndef END_my_m_MT_R_1che1pao1ma2pawn_B_1che1pao3pawn
#define END_my_m_MT_R_1che1pao1ma2pawn_B_1che1pao3pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车1炮1马2兵对1车1炮3兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che1pao1ma2pawn_B_1che1pao3pawn(typePOS &POSITION, EvalInfo &ei){


	Square yche = S90_from_piecelist(POSITION, your_che, 0);
	Square mma = S90_from_piecelist(POSITION, my_ma, 0);
	// fen 4kab2/9/2R1b4/p8/6p2/2P6/PC3p3/2N1BA3/9/2B1KA1rc b - - 0 1
	if (EV_YOUR_CAN >= 2 && EV_MY_CAN == 0){
		if (bit_is_set(EV_YOUR_XBIT, yche)){
			if (StoY(mma) MY_LARGE_EQL MY_RANK6){
				MY_EV_SUB(32);
				if (have_bit(bb_your_pawn, MyLowBB[MY_RANK4])){
					MY_EV_SUB(64);
				}
			}
		}
	}
}
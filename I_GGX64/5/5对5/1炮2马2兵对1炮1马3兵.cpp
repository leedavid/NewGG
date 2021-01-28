#ifndef END_my_m_MT_R_1pao2ma2pawn_B_1pao1ma3pawn
#define END_my_m_MT_R_1pao2ma2pawn_B_1pao1ma3pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1炮2马2兵对1炮1马3兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1pao2ma2pawn_B_1pao1ma3pawn(typePOS &POSITION, EvalInfo &ei){

	// fen 1N2kab2/4a4/4b4/p7p/2p6/4n4/P3N3P/6C2/5K3/2B3c2 b - - 0 1
	if(my_xiang_num >= 1 && EV_MY_CAN <= 1){
		if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK4])){
			MY_EV_ADD(32);
		}
	}

}
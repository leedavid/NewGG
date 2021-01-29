#ifndef END_my_m_MT_R_2pao2ma5pawn_B_1che2pao2pawn
#define END_my_m_MT_R_2pao2ma5pawn_B_1che2pao2pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "2炮2马5兵对1车2炮2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_2pao2ma5pawn_B_1che2pao2pawn(typePOS &POSITION, EvalInfo &ei){


	Square mk = my_king_pos;


	// fen 2bak1b2/4a4/4c4/p3CP2p/4N4/P4N3/2r1P3P/1c2C4/4AK3/3A2B2 w - - 0 1
	if(EV_YOUR_CAN == 0){
		if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			if(have_bit(EV_MY_XBIT,bb_your_pao)){
				MY_EV_ADD(EV_MY_CAN * 32);
			}
		}
	}

}

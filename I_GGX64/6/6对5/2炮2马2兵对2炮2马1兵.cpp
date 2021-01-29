#ifndef END_my_m_MT_R_2pao2ma2pawn_B_2pao2ma1pawn
#define END_my_m_MT_R_2pao2ma2pawn_B_2pao2ma1pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "2炮2马2兵对2炮2马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



void my_m_MT_R_2pao2ma2pawn_B_2pao2ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;

	// fen C1cak4/4a4/4b4/2n1n4/3N2b2/8c/P3P2p1/2N1BA3/1C7/4KAB2 b - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if(have_bit(EV_MY_XBIT,m_or(bb_your_ma,bb_your_pao))){
			MY_EV_ADD(EV_MY_CAN * 16);
			MY_EV_ADD(32);
		}
	}

	// fen 2ba1k3/1c2a3c/2C1b4/7NC/4pP3/9/1N1nP3n/9/4A4/2BAK4 b - - 0 1
	if (EV_YOUR_CAN == 0){
		if (have_bit(MyUpBB[MY_RANK5], bb_my_pawn)){
			if ((my_shi_num + my_xiang_num) >= 3 && StoY(mk) == MY_RANK9){
				MY_EV_ADD(32);
			}
		}
	}

}
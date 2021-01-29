#ifndef END_my_m_MT_R_1che1pao4pawn_B_1che1pao2pawn
#define END_my_m_MT_R_1che1pao4pawn_B_1che1pao2pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车1炮4兵对1车1炮2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

void my_m_MT_R_1che1pao4pawn_B_1che1pao2pawn(typePOS &POSITION, EvalInfo &ei){


	Square ypao = S90_from_piecelist(POSITION,your_pao,0);

	// fen 4kab2/4a3C/4b4/p6r1/3P4p/PR4B2/4P3P/9/8c/5K3 b - - 0 1
	if(EV_YOUR_CAN == 0){
		if(StoY(ypao) MY_LARGE_EQL MY_RANK5){
			if(EV_MY_CAN >= 2){
				MY_EV_ADD(EV_MY_CAN * 32);
			}
		}
	}

}
#ifndef END_my_m_MT_R_2pao2ma1pawn_B_2pao1ma2pawn
#define END_my_m_MT_R_2pao2ma1pawn_B_2pao1ma2pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "2炮2马1兵对2炮1马2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_2pao2ma1pawn_B_2pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	// fen 5kb2/5c3/b2a5/4C4/4Nn2p/9/1C6P/9/4A1p2/cN1AK4 w - - 0 1
	Square mk = my_king_pos;
	if(EV_YOUR_CAN <= 1){
		if(my_shi_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			MY_EV_ADD(32);
		}
	}
}
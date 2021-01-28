#ifndef END_my_m_MT_R_1che1ma4pawn_B_1che1ma2pawn
#define END_my_m_MT_R_1che1ma4pawn_B_1che1ma2pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车1马4兵对1车1马2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

void my_m_MT_R_1che1ma4pawn_B_1che1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;

	// fen P2akab2/9/4b1n2/4p4/8p/9/P3P1r1P/5RN2/4A4/4KAB2 w - - 0 1
	if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) == MY_RANK9){
		if(EV_YOUR_CAN == 0){
			MY_EV_ADD(32);
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

}
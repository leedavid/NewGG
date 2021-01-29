#ifndef END_my_m_MT_R_1che2pao1ma2pawn_B_2che1pao1pawn
#define END_my_m_MT_R_1che2pao1ma2pawn_B_2che1pao1pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车2炮1马2兵对2车1炮1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

void my_m_MT_R_1che2pao1ma2pawn_B_2che1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	Square mma = S90_from_piecelist(POSITION,my_ma,0);
	
	// fen 2bk1C3/9/1r3a1R1/8C/4p1r2/9/P3c3P/B3N3B/4A4/3AK4 w - - 0 1
	if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){   // 我方没有兵过河
		if(StoY(mma) MY_LARGE_EQL MY_RANK7 && bit_is_set(EV_YOUR_XBIT,mma)){
			MY_EV_SUB(EV_YOUR_CAN * 32);
			MY_EV_SUB(32);
			if(your_shi_num >= 1 && your_xiang_num >= 1){
				MY_EV_SUB(32);
			}
		}
	}
}
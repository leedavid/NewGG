#ifndef END_my_m_MT_R_1ma1pao1pawn_B_1che1ma
#define END_my_m_MT_R_1ma1pao1pawn_B_1che1ma
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1炮1马1兵对1车1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1ma1pao1pawn_B_1che1ma(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpao  = S90_from_piecelist(POSITION,my_pao,0);
	Square mma   = S90_from_piecelist(POSITION,my_ma,0);

    // fen 2b1ka3/4a4/4b4/4P4/7r1/9/9/3NBA3/4A1n2/2BK1C3 b - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if(StoY(mpawn) == MY_RANK3){
			MY_EV_ADD(32);
		}
		if (StoY(mpao) == MY_RANK7){
			MY_EV_ADD(32);
		}
		if (MY_SQ2F == mma || MY_SQ33 == mma){
			if (bit_is_set(MY_ATTACK, mma)){
				MY_EV_ADD(32);
			}
		}
		if(StoY(mpao) MY_LARGE_EQL MY_RANK8){
			if(PB90(MY_SQ42) == my_shi && PB90(MY_SQ44) == my_ma){
				RETRUN_MUL(8);
			}
			if(PB90(MY_SQ44) == my_shi && PB90(MY_SQ42) == my_ma){
				RETRUN_MUL(8);
			}
		}
	}

}
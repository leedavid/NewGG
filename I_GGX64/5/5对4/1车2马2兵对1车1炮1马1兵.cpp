#ifndef END_my_m_m_MT_R_1che2ma2pawn_B_1che1pao1ma1pawn 
#define END_my_m_m_MT_R_1che2ma2pawn_B_1che1pao1ma1pawn 
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车2马2兵对1车1炮1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1che2ma2pawn_B_1che1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;

	// fen 3ak1b2/3Pa4/4b4/p8/4N1n2/Pc6r/9/4N4/4A4/2BAKR3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
		if(EV_MY_CAN <= 1 && my_xiang_num <= 1){
			MY_EV_SUB(32);
			if(have_bit(bb_my_ma,MyLowBB[MY_RANK6])){
				MY_EV_SUB(32);
			}
		}
	}
}
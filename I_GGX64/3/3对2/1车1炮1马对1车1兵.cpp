#ifndef END_my_m_MT_R_1che1pao1ma_B_1che1pawn
#define END_my_m_MT_R_1che1pao1ma_B_1che1pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车1炮1马对1车1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//车马炮对车炮
void my_m_MT_R_1che1pao1ma_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	//Square mk = my_king_pos;
	Square yche = S90_from_piecelist(POSITION,your_che,0);

	// fen 3ak4/3R5/3Nba3/9/6b2/3r5/3p5/8C/9/4KA3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
		if(StoY(yche) MY_LARGE MY_RANK2){
			if(PB90(MY_SQ15) == my_ma && PB90(MY_SQ0C) == my_che){
				if(StoX(yche) == 0x3){
					MY_EV_SUB(96);
					RETRUN_MUL(4);
				}
			}
			if(PB90(MY_SQ17) == my_ma && PB90(MY_SQ0E) == my_che){
				if(StoX(yche) == 0x5){
					MY_EV_SUB(96);
					RETRUN_MUL(4);
				}
			}
		}
	}


}

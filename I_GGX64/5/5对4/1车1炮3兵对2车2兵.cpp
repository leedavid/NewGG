#ifndef END_my_m_MT_R_1che1pao3pawn_B_2che2pawn
#define END_my_m_MT_R_1che1pao3pawn_B_2che2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1炮3兵对2车2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1che1pao3pawn_B_2che2pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;

	// fen Cr1ak4/4a4/9/R1pP4p/P8/2P5r/9/4B4/4A4/3AK4 w - - 0 1
	if(my_shi_num == 2 && StoY(mk) == MY_RANK9){
		if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK5]) && EV_YOUR_CAN <= 1)
			if(your_xiang_num  <= 1 && have_bit(EV_MY_XBIT,bb_your_che)){
				// 我方过了二个兵
				if(count_1s(bb_my_pawn,MyUpBB[MY_RANK5]) >= 2){
					MY_EV_ADD(32);
					MY_EV_ADD(EV_MY_CAN * 16);
				}
			}
	}
}


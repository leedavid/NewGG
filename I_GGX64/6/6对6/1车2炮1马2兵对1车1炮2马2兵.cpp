#ifndef END_my_m_MT_R_1che2pao1ma2pawn_B_1che1pao2ma2pawn
#define END_my_m_MT_R_1che2pao1ma2pawn_B_1che1pao2ma2pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车2炮1马2兵对1车1炮2马2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che2pao1ma2pawn_B_1che1pao2ma2pawn (typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// fen 3ak1bn1/3na4/4b3c/4p3p/6r2/1R3N3/4P3P/4CC3/4A4/4KAB2 w - - 0 1
	if(my_xiang_num <= 1){
		if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
			if(EV_MY_CAN == 0){
				MY_EV_SUB(32);
				if(!have_bit(MyUpBB[MY_RANK5],m_or(bb_my_pao,bb_my_ma))){
					MY_EV_SUB(32);
				}
			}
		}
	}
}
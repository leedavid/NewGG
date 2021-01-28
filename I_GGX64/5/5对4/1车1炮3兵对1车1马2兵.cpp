#ifndef END_my_m_MT_R_1che1pao3pawn_B_1che1ma2pawn
#define END_my_m_MT_R_1che1pao3pawn_B_1che1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1炮3兵对1车1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1che1pao3pawn_B_1che1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk   = your_king_pos;
	Square yma  = S90_from_piecelist(POSITION,your_ma,0);
	Square yche = S90_from_piecelist(POSITION,your_che,0);

	// fen 3ak1b2/5R3/5a3/C2n4p/4p4/9/Pr2P3P/9/4A4/3AK4 w - - 0 1
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(EV_MY_CAN <= 1 && my_xiang_num == 0 && StoY(yma) MY_LARGE_EQL MY_RANK2){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
				MY_EV_SUB(32);
				if(StoY(yche) MY_LARGE_EQL MY_RANK5){
					MY_EV_SUB(16);
				}
			}
		}
	}
}
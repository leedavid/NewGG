#ifndef END_my_m_MT_R_1che1pao1ma3pawn_B_1che2pao1ma1pawn
#define END_my_m_MT_R_1che1pao1ma3pawn_B_1che2pao1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1炮1马3兵对1车2炮1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1che1pao1ma3pawn_B_1che2pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;

	Square mma = S90_from_piecelist(POSITION, my_ma, 0);
	Square yma = S90_from_piecelist(POSITION, your_ma, 0);
	Square yche = S90_from_piecelist(POSITION, your_che, 0);

	// fen 2bak4/2n1a4/c3b2r1/2CP5/3P3cp/2N4R1/8P/4B4/4A4/4KAB2 b - - 0 1
	if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if (EV_YOUR_CAN == 0 && count_1s(bb_your_pao,MyLowBB[MY_RANK4]) <= 1){
			if (count_1s(bb_my_pawn, MyUpBB[MY_RANK5]) == 2){
				MY_EV_ADD(16);
				if (StoY(yche) MY_SMALL_EQL MY_RANK3){
					MY_EV_ADD(16);
				}
				if (StoY(yma) MY_SMALL_EQL MY_RANK1 && StoY(mma) MY_SMALL_EQL MY_RANK5){
					MY_EV_ADD(32);
				}
			}
		}
	}

}
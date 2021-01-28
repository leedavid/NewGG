#ifndef END_my_m_MT_R_2che4pawn_B_1che2pao1ma2pawn
#define END_my_m_MT_R_2che4pawn_B_1che2pao1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2车4兵对1车2炮1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_2che4pawn_B_1che2pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yma = S90_from_piecelist(POSITION, your_ma,0);
	Square mk = my_king_pos;

	//fen 2bak1b2/4a4/2c2c2n/p1r3p2/1R6P/4P1P2/PR7/4B4/4A4/4KAB2 b - - 0 1
	if ((my_shi_num + my_xiang_num) == 4)
	{
		if (StoY(yma) MY_SMALL_EQL(MY_RANK2)){
			MY_EV_ADD(32);
			if (EV_MY_CAN >= 2){
				MY_EV_ADD(32);
			}
		}
	}

	//  fen 2bak1b2/4a4/2c2c2n/p1r3p2/1R7/4P1P1P/PR7/4B4/4A4/4KAB2 w - - 0 1
	if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9) {
		if (count_1s(m_and(m_or(bb_your_pao, bb_your_ma), MyUpBB[MY_RANK4])) == 3) {
			MY_EV_ADD(EV_MY_CAN * 16);
		}
		if (EV_YOUR_CAN == 0) {
			MY_EV_ADD(32);
		}
	}
}
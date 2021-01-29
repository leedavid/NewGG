#ifndef END_my_m_MT_R_1che1pao1ma3pawn_B_1che2ma3pawn
#define END_my_m_MT_R_1che1pao1ma3pawn_B_1che2ma3pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车1炮1马3兵对1车1马4兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che1pao1ma3pawn_B_1che1ma4pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;

	// fen 2baka3/4n4/2n1b4/p1R1p4/7r1/2P1P1B2/P8/2CNB2p1/4A4/4KA3 b - - 0 1
	if (my_shi_num == 2 && StoY(mk) == MY_RANK9){
		if (!have_bit(bb_your_ma, MyLowBB[MY_RANK2])){
			MY_EV_ADD(32);
			// fen 2b1ka3/4a3n/n3b2r1/p1pR5/9/4N4/P2CP3P/4B4/4A1p2/4KA3 b - - 0 1
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}
}
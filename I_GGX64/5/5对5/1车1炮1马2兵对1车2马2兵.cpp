#ifndef END_my_m_MT_R_1che1pao1ma2pawn_B_1che2ma2pawn
#define END_my_m_MT_R_1che1pao1ma2pawn_B_1che2ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1炮1马2兵对1车2马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che1pao1ma2pawn_B_1che2ma2pawn(typePOS &POSITION, EvalInfo &ei) {

	Square mk = my_king_pos;
	Square mma = S90_from_piecelist(POSITION, my_ma, 0);

	//  fen 4k1b2/4a4/3ab3n/1N4p2/p2P5/6P1C/1n6r/3R4B/4A4/3AK4 w - - 0 1
	if (my_shi_num >= 2 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9) {
		if (EV_YOUR_CAN <= 1) {
			MY_EV_ADD(EV_MY_CAN * 16);
		}
		if (have_bit(bb_your_ma, MyUpBB[MY_RANK3]) && StoY(mma) MY_SMALL_EQL MY_RANK5) {
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

}
#ifndef END_my_m_MT_R_1pao2ma2pawn_B_1pao1ma2pawn
#define END_my_m_MT_R_1pao2ma2pawn_B_1pao1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1炮2马2兵对1炮1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1pao2ma2pawn_B_1pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){


	MY_EV_ADD(32);

	// fen 5P3/4k4/b2aba3/p8/7C1/P5n2/2N3C2/5p3/8c/4K4 w - - 0 1
	if(EV_YOUR_CAN <= 1){
		// 二线上没有对方的兵
		if(!have_bit(bb_your_pawn,RankBB_A[MY_RANK8])){
			MY_EV_ADD(32);
		}
	}

}
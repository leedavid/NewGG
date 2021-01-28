#ifndef END_my_m_MT_R_1che2pao1ma2pawn_B_1che2ma2pawn
#define END_my_m_MT_R_1che2pao1ma2pawn_B_1che2ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车2炮1马2兵对1车2马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che2pao1ma2pawn_B_1che2ma2pawn(typePOS &POSITION, EvalInfo &ei){

	//Square mk = my_king_pos;

	// fen 2bk1a3/4a4/n3b4/4C1p2/3NP3p/6P2/1n7/1CR6/4K4/3r5 b - - 0 1
	//对方没有兵过河，对方只有一个以上马过河
	if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK4])){
		MY_EV_ADD(16);
		MY_EV_ADD(EV_MY_CAN * 16);

		if(have_bit(bb_your_ma,MyUpBB[MY_RANK5])){
			MY_EV_ADD(32);
		}
	}

}
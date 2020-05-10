#ifndef END_my_m_MT_R_1che2pao1ma5pawn_B_1che1pao2ma2pawn
#define END_my_m_MT_R_1che2pao1ma5pawn_B_1che1pao2ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车2炮1马5兵对1车1炮2马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che2pao1ma5pawn_B_1che1pao2ma2pawn(typePOS &POSITION, EvalInfo &ei){

	// fen 2ba1k3/4an3/n3b4/3R2p1p/C1P6/4P1P2/P3N3P/4B1N2/4K4/1r6c b - - 0 1
	if(EV_YOUR_CAN == 0 && !have_bit(bb_your_ma,MyLowBB[MY_RANK2])){
		if(!have_bit(_mm_andnot_si128(MY_ATTACK,ei.attacked_by(your_ma)),MyLowBB[MY_RANK3])){
			MY_EV_ADD(16);
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}
}
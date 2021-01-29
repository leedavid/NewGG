#ifndef END_my_m_MT_R_2pao2ma2pawn_B_2pao1ma3pawn
#define END_my_m_MT_R_2pao2ma2pawn_B_2pao1ma3pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "2炮2马2兵对2炮1马3兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_2pao2ma2pawn_B_2pao1ma3pawn(typePOS &POSITION, EvalInfo &ei){

	Square yma = S90_from_piecelist(POSITION,your_ma,0);

	// fen 4kab2/4a4/4b4/p3p2c1/1n6p/PNB3C2/4P4/2NC5/9/c3K4 b - - 0 1
	if(EV_YOUR_CAN <= 1){
		if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK5])){
			MY_EV_ADD(32);
			if(StoY(yma) MY_SMALL_EQL MY_RANK4){
				MY_EV_ADD(32);
			}
		}
	}
}
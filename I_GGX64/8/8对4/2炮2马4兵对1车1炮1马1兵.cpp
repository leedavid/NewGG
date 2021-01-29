#ifndef END_my_m_MT_R_2pao2ma4pawn_B_1che1pao1ma1pawn
#define END_my_m_MT_R_2pao2ma4pawn_B_1che1pao1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "2炮2马4兵对1车1炮1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_2pao2ma4pawn_B_1che1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){


	// fen 3a2C2/4k4/3a2n2/4p4/2P6/P2N5/4P3P/2N2C3/4K4/2Bc3r1 b - - 
	if((my_shi_num + my_xiang_num) <= 1){
		MY_EV_SUB(32);
	}
	if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK4])){
		MY_EV_SUB(32);
	}
	// fen C3kab2/4a4/6n2/p3p4/1R3np1p/9/4P4/B1N2A3/4K4/3c1A2c b - - 0 1
	if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
		MY_EV_SUB(32);
	}
}
#ifndef END_my_m_MT_R_1che2pao4pawn_B_1che4pao2pawnn
#define END_my_m_MT_R_1che2pao4pawn_B_1che4pao2pawnn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车2炮4兵对1车2炮2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che2pao4pawn_B_1che2pao2pawn(typePOS &POSITION, EvalInfo &ei){

	// fen 2b2k3/4a4/1c1ab3c/4C1p2/1C2P3p/6P2/2P1R3P/4B4/7r1/2B1K4 w - - 0 1
	if(EV_YOUR_CAN == 0 && my_xiang_num == 2){
		MY_EV_ADD(EV_MY_CAN * 16);
		if(have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
			MY_EV_ADD(32);
		}
	}
}
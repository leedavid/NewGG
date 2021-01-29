#ifndef END_my_m_MT_R_1che2pao3pawn_B_1che1pao2pawn
#define END_my_m_MT_R_1che2pao3pawn_B_1che1pao2pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车2炮3兵对1车1炮2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

void my_m_MT_R_1che2pao3pawn_B_1che1pao2pawn(typePOS &POSITION, EvalInfo &ei){

	MY_EV_ADD(16);

	// fen 4kab2/4a4/4b1C2/p7p/4C4/1r2P2R1/2P5P/9/4K4/6c2 b - - 0 1
	if(EV_YOUR_CAN <= 1){
        if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK4])){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}
}
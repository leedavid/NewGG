#ifndef END_my_m_MT_R_1che1pao1ma1pawn_B_1che1pao1pawn
#define END_my_m_MT_R_1che1pao1ma1pawn_B_1che1pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1炮1马1兵对1车1炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che1pao1ma1pawn_B_1che1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	//Square mk = my_king_pos;

	// fen 4kab2/9/4ba3/p3R3p/cr7/9/7NP/9/3CK4/6B2 w - - 0 1
	if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK5])){
		if(have_bit(LeftBB[0x1],bb_your_pawn) && have_bit(RightBB[0x7],bb_your_pawn)){
			MY_EV_ADD(32);
		}
	}

	// fen 5k3/2Nca4/5a2b/3C2R2/2b2r2p/9/8P/4B4/4K4/9 b - - 0 1
	//if(EV_YOUR_CAN == 0 && my_xiang_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
	//	MY_EV_ADD(32);
	//}

}

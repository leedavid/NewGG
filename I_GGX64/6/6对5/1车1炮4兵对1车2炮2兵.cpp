#ifndef END_my_m_MT_R_1che1pao4pawn_B_1che2pao2pawn
#define END_my_m_MT_R_1che1pao4pawn_B_1che2pao2pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车1炮4兵对1车2炮2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



void my_m_MT_R_1che1pao4pawn_B_1che2pao2pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;

	// fen c1r1ka2c/4a4/1R7/9/2p3P1C/9/2P1P3P/2p1B4/4A4/2BAK4 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && MY_SQ55 == mk){
		if(your_xiang_num == 0 && EV_YOUR_CAN <= 1){
			MY_EV_ADD((sint16)count_1s(RankBB_A[MY_RANK0],
				m_or(bb_your_pao,bb_your_che)) * 16);
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}
}
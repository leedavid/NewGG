#ifndef END_my_m_MT_R_1pao2ma1pawn_B_1pao1ma2pawn
#define END_my_m_MT_R_1pao2ma1pawn_B_1pao1ma2pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1炮2马1兵对1炮1马2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

// fen 2b1ka3/9/5a3/p3p4/6C2/2P1Pc3/8n/4B1C2/4A4/2BAK4 w - - 0 0

void my_m_MT_R_1pao2ma1pawn_B_1pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;

	// fen 3k1ab2/4a4/8b/8P/4N4/2N3B2/9/c1CA1K3/3pp4/5n3 b - - 0 1
	if(!have_bit(MyLowBB[StoY(mk)],bb_my_pawn)){
		MY_EV_ADD(64);
		MY_EV_ADD(EV_MY_CAN * 32);
		if(my_shi_num >= 1){
			MY_EV_ADD(32);
		}
	}
}

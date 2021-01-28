#ifndef END_my_m_MT_R_1ma3pawn_B_1pao1ma1pawn
#define END_my_m_MT_R_1ma3pawn_B_1pao1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1马3兵对1炮1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//1马3兵对1炮2兵 //ADD_1PaoXPawn_1MaXPawn_ByShi

void my_m_MT_R_1ma3pawn_B_1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){	

	Square mk    = my_king_pos;
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	if (EV_YOUR_CAN) {
		MY_EV_SUB(32);
	}

	//  fen 3k5/2P1a2P1/2Pab4/3N5/9/p8/8c/3AB4/5K1n1/2BA5 w - - 0 1
	if (your_shi_num == 2) {
		MY_EV_SUB(32);
		MY_EV_SUB(EV_YOUR_CAN * 32);
		if (have_bit(bb_your_shi, RankBB_A[MY_RANK2])) {
			MY_EV_SUB(32);
		}
	}

	// fen 2bak4/4a4/9/4PP3/4c1b2/8P/3nN4/3A1A3/2p6/5K3 w - - 0 1
	if(my_shi_num == 2 && StoY(mk) == MY_RANK9 && abs(StoX(ypawn) - StoX(mk)) >= 2){
		Bitboard lp = My_get_connect_Pawn(POSITION);
		if(have_bit(lp,RankBB_A[MY_RANK3])){
			RETRUN_MUL(8);
		}
	}
}
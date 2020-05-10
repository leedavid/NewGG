#ifndef END_my_m_MT_R_2pao1ma1pawn_B_1che2pawn
#define END_my_m_MT_R_2pao1ma1pawn_B_1che2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2炮1马1兵对1车2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2pao1ma1pawn_B_1che2pawn(typePOS &POSITION, EvalInfo &ei){


	Square mk    = my_king_pos;
	Square yk    = your_king_pos;
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	// fen 3k5/4aPN2/4ba3/4p4/9/9/2r6/3C5/2p1A3C/4KA3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		MY_EV_SUB(EV_YOUR_CAN * 32);
		if(abs(StoX(mpawn) - StoX(yk)) >= 2){
			MY_EV_SUB(EV_YOUR_CAN * 16);
			if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
				if(StoX(mpawn) > 0x4 && PB90(MY_SQ17) == your_shi){
					MY_EV_SUB(EV_YOUR_CAN * 16);
				}
				if(StoX(mpawn) < 0x4 && PB90(MY_SQ15) == your_shi){
					MY_EV_SUB(EV_YOUR_CAN * 16);
				}
			}
		}
	}

	// fen 6P2/5k3/3ab1N2/p8/5N3/3C1r3/9/9/3KA4/5p3 w - - 0 1
	if(my_shi_num >= 1){
		if(have_bit(bb_your_pawn,RankBB_A[MY_RANK9])){  // 一个兵到了底线
			// 得到另一个兵
			Bitboard op = m_and(bb_your_pawn,MyUpBB[MY_RANK5]);
			if(m_have_bit(op)){
				MY_EV_ADD(16);
				Square np = pop_1st_bit_sq(op);
				if(abs(StoX(np) - 0x4) >= 2){
					MY_EV_ADD(16);
				}
				if(your_shi_num <= 1 && your_xiang_num <= 1){
					MY_EV_ADD(EV_MY_CAN * 16);
				}
			}
		}
	}

	// fen 3k1abC1/4a4/4b1P2/p2N5/3r1N3/9/9/9/4Ap3/3AK4 w - - 0 1
	if(my_shi_num == 2 && StoY(mk) == MY_RANK9){
		if(have_bit(bb_your_pawn,MyUpBB[MY_RANK5])){
			MY_EV_ADD(32);
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}
}
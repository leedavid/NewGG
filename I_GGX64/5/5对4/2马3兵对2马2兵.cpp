#ifndef END_my_m_MT_R_2ma3pawn_B_2ma2pawn
#define END_my_m_MT_R_2ma3pawn_B_2ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2Âí3±ø¶Ô2Âí2±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_2ma3pawn_B_2ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;
	Square yk = your_king_pos;

	// fen 4k1b2/4a4/5a3/9/2P2N3/1N2P4/P7n/7p1/3KApn2/5A3 b - - 0 1
	if(my_shi_num == 2){
		if(StoX(mk) < 0x4 && !have_bit(bb_your_pawn,LeftBB[0x5])){
			MY_EV_ADD(EV_MY_CAN * 32);
			if(!have_bit(bb_my_shi,LeftBB[0x4])){
				Bitboard lowp = m_and(bb_your_pawn,MyLowBB[StoY(mk) MY_SUB 0x1]);
				MY_EV_ADD((sint16)count_1s(lowp) * 32);
			}
		}
		if(StoX(mk) > 0x4 && !have_bit(bb_your_pawn,RightBB[0x3])){
			MY_EV_ADD(EV_MY_CAN * 32);
			if(!have_bit(bb_my_shi,RightBB[0x4])){
				Bitboard lowp = m_and(bb_your_pawn,MyLowBB[StoY(mk) MY_SUB 0x1]);
				MY_EV_ADD((sint16)count_1s(lowp) * 32);
			}
		}
	}

	// fen 2baka3/9/4b1N2/5P3/8P/2pN2P2/3p5/6n1n/4A4/2B1KA3 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num >= 1){
		if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK6]) && StoY(mk) == MY_RANK9){
			MY_EV_ADD(EV_MY_CAN * 24);
		}
	}

	// fen 2b6/3kaP3/b4a3/p1PN5/3n5/P1B1n4/1N7/3AB4/4A1p2/5K3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(EV_MY_CAN <= 2 && count_1s(bb_my_pawn,MyUpBB[MY_RANK3]) <= 1){
			MY_EV_SUB(32);
			MY_EV_SUB(EV_YOUR_CAN * 16);
		}
	}

	// fen 4kab2/9/3ab4/9/4p3P/P5B2/4P4/6n2/2nNAN1p1/2BAK4 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && EV_YOUR_CAN <= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		MY_EV_ADD(EV_MY_CAN * 32);
		MY_EV_ADD(32);
	}
}
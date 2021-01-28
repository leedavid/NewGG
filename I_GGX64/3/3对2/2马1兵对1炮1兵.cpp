#ifndef END_my_m_MT_R_2ma1pawn_B_1pao1pawn
#define END_my_m_MT_R_2ma1pawn_B_1pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2马1兵对1炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2ma1pawn_B_1pao1pawn(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2MaXPawn_1Pao1Pawn_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_2MaXPawn_1Pao1Pawn_ByPawn[my_shi_num]);
	
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	// fen 9/4P4/3k5/9/3n5/2Bn5/3C5/4KA3/3pA4/9 b - - 0 1
	// 二个马不能走
	if(!m_have_bit(_mm_andnot_si128(EV_YOUR_XBIT,bb_my_ma))){
		MY_EV_SUB(168);
	}
	// fen 2b1k4/9/3aba3/4N4/4p4/2B2cN2/4P4/4BA3/9/4K4 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(EV_MY_CAN == 0){
			MY_EV_SUB(32);
		}
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
			MY_EV_SUB(32);
		}
		RETRUN_MUL(8);
		//// fen 5kb2/2N1a1P2/5a1Nb/9/5c3/2B6/9/3ABA3/9/4K4 b - - 124 124
	}

	// fen 9/3k3P1/3ab4/5n3/2b6/2B6/3p4C/B2A5/4A1n2/5K3 w - - 198 198
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if(StoY(ypawn) MY_LARGE_EQL MY_RANK5){
			RETRUN_MUL(8);
		}
	}
}


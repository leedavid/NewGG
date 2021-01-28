
#ifndef ENDR_my_m_MT_R_1pao1ma4pawn_B_1pao2ma2pawn
#define ENDR_my_m_MT_R_1pao1ma4pawn_B_1pao2ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1炮1马4兵对1炮2马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1pao1ma4pawn_B_1pao2ma2pawn(typePOS &POSITION, EvalInfo &ei){

	// fen 3nk4/5PP2/b4a3/4p4/3n2cN1/p1P1P4/9/BC7/4A4/2BAK4 b - - 0 1
	if(EV_MY_CAN <= 2 && your_shi_num >= 1 && your_xiang_num >= 1){
		MY_EV_SUB(EV_YOUR_CAN * 32);
		//
		Bitboard mp = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
		if(count_1s(mp) == 2){
			if(!have_bit(mp,LeftBB[0x5]) && PB90(MY_SQ17) == your_shi){
				MY_EV_SUB(64);
			}
			if(!have_bit(mp,RightBB[0x3]) && PB90(MY_SQ15) == your_shi){
				MY_EV_SUB(64);
			}
		}
	}

	// fen 3a5/9/5k3/pn1cp4/5C3/PNP6/4Pn2P/4B4/4A4/4KAB2 b - - 0 1
	if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
		MY_EV_SUB(16);
		if(!have_bit(bb_your_ma,MyUpBB[MY_RANK2])){
			MY_EV_SUB(32);
		}
	}
}
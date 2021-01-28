#ifndef END_my_m_MT_R_1che2pao3pawn_B_1che1pao1ma3pawn 
#define END_my_m_MT_R_1che2pao3pawn_B_1che1pao1ma3pawn 
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车2炮3兵对1车1炮1马3兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che2pao3pawn_B_1che1pao1ma3pawn (typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	Square mche = S90_from_piecelist(POSITION,my_che,0);
	// fen C3kab1C/4a4/2n1b4/1r2p3p/2p2c3/P2RP3P/9/4B4/9/2BAKA3 w - - 0 1
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(16);
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
			MY_EV_SUB(32);
		}
	}

	// fen 1Cbakab2/9/9/2r1p4/p5p1P/9/P3P4/1R2B3n/1Cc1A4/2B1KA3 b - - 0 1
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if(StoY(yma) MY_LARGE_EQL MY_RANK5){
			MY_EV_SUB(16);
		}
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK4])){
			MY_EV_SUB(16);
		}
		if(EV_MY_CAN <= 1){
			MY_EV_SUB(16);
		}
	}

	// fen 4kab1C/4a4/9/p3p4/6p2/P2n5/4P1c1P/4BR3/3rA4/2CAK4 w - - 0 1
	if(my_xiang_num <= 1 && !have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
		if(StoY(yma) MY_LARGE_EQL MY_RANK5){
			MY_EV_SUB(16);
		}
		if(StoY(mche) MY_LARGE_EQL MY_RANK5){
			MY_EV_SUB(16);
		}
	}
}
#ifndef ENDR_1che1pao1ma3pawn_B_2che3pawn
#define ENDR_1che1pao1ma3pawn_B_2che3pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1炮1马3兵对2车3兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che1pao1ma3pawn_B_2che3pawn(typePOS &POSITION, EvalInfo &ei){

	Square mma = S90_from_piecelist(POSITION,my_ma,0);
	Square yk  = your_king_pos;
	
	// fen 3k1a3/9/3a5/p3p2R1/2pr5/4r3P/P1P6/N3B4/4A1C2/2BAK4 w - - 0 1
	if((your_shi_num + your_xiang_num) >= 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mma) MY_LARGE_EQL MY_RANK7 && !have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
			MY_EV_SUB(64);
			MY_EV_SUB(EV_YOUR_CAN * 32);
		}
	}

	// fen 4ka3/4a4/4b1n2/p1R5p/2pPR4/9/P5r1P/9/4K4/7c1 b - - 0 1
	if ((my_xiang_num + my_shi_num) <= 3){
		if (StoY(mma) MY_LARGE_EQL MY_RANK6){
			MY_EV_SUB(32);
		}
		if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK5])){
			MY_EV_SUB(32);
		}
	}
}
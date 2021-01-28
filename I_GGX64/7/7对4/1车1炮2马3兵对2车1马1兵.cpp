#ifndef END_my_m_MT_R_1che1pao2ma3pawn_B_2che1ma1pawn
#define END_my_m_MT_R_1che1pao2ma3pawn_B_2che1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1炮2马3兵对2车1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che1pao2ma3pawn_B_2che1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	// fen 2bak4/4a4/4b4/1P7/8P/3p2P2/2r2n2N/R2CB4/4A1r2/2N1KAB2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
			MY_EV_SUB(16);
		}
		if(StoY(ypawn) MY_LARGE_EQL MY_RANK5){
			if(!have_bit(bb_my_ma,MyUpBB[MY_RANK4])){
				MY_EV_SUB(16);
			}
		}
	}
}
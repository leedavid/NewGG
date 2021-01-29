#ifndef END_my_m_MT_R_1che1pao2ma3pawn_B_2che4pawn
#define END_my_m_MT_R_1che1pao2ma3pawn_B_2che4pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车2马1炮3兵对2车4兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che1pao2ma3pawn_B_2che4pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;

	// fen 1r2ka1r1/4a4/2R1b4/p7p/9/6P2/P2p1p2P/4C4/2N1AN3/3AK4 b - - 0 1
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
		if(!have_bit(bb_my_ma,MyUpBB[MY_RANK4]) && EV_YOUR_CAN >= 2){
			if(count_1s(bb_your_pawn,MyLowBB[MY_RANK5]) >= 2){
				MY_EV_SUB(EV_YOUR_CAN * 16);
			}
		}
	}
}

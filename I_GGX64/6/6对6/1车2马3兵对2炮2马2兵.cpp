#ifndef END_my_m_MT_R_1che2ma3pawn_B_2pao2ma2pawn
#define END_my_m_MT_R_1che2ma3pawn_B_2pao2ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车2马3兵对2炮2马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che2ma3pawn_B_2pao2ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;

	// fen 2b1ka3/4a4/4b4/8R/2n1p4/1p4B2/1c1nP1P1P/3AB1N2/9/1cNA1K3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
			MY_EV_SUB(16);
			if(!have_bit(bb_my_ma,MyUpBB[MY_RANK7])){
				MY_EV_SUB(16);
				MY_EV_SUB(EV_YOUR_CAN * 16);
			}
		}
	}
}
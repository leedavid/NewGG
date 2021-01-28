#ifndef END_my_m_MT_R_1che2ma4pawn_B_1che2pao3pawn
#define END_my_m_MT_R_1che2ma4pawn_B_1che2pao3pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车2马4兵对1车2炮3兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che2ma4pawn_B_1che2pao3pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;
	// fen 2baka3/7c1/9/p1p3R1p/9/2PN3N1/P3P3P/4Br3/9/3AK3c b - - 0 1
	if((my_shi_num + my_xiang_num) >= 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(your_xiang_num <= 1){
			MY_EV_ADD((sint16)count_1s(bb_my_ma,MyUpBB[MY_RANK6]) * 16);
			if(have_bit(bb_your_pao,MyLowBB[MY_RANK6]) && have_bit(bb_your_pao,MyUpBB[MY_RANK7])){
				MY_EV_ADD(EV_MY_CAN * 16);
				MY_EV_ADD(16);				
			}
		}
	}

}
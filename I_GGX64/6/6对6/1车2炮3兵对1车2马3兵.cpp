#ifndef END_my_m_MT_R_1che2pao3pawn_B_1che2ma3pawn 
#define END_my_m_MT_R_1che2pao3pawn_B_1che2ma3pawn 
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车2炮3兵对1车2马3兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che2pao3pawn_B_1che2ma3pawn (typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;

	// fen 2b1ka3/4a4/n3b4/p7p/1r3np2/P6RP/4P4/3CB4/4A4/2BAK1C2 w - - 0 1
	if(EV_MY_CAN <= 1 && !have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			MY_EV_SUB(32);
			if(count_1s(bb_my_pao,MyLowBB[MY_RANK4]) == 2){
				MY_EV_SUB(32);
			}
		}
	}
}
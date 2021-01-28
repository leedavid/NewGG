#ifndef END_my_m_MT_R_1che2pao4pawn_B_1che2pao1ma2pawn
#define END_my_m_MT_R_1che2pao4pawn_B_1che2pao1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车2炮4兵对1车2炮1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che2pao4pawn_B_1che2pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	// fen C8/4ak3/3a5/p3c3p/1r7/3nC1P2/P1R1P3P/4B1n2/4A4/3AK1B2 b - - 0 1
	if(your_shi_num == 2 || your_xiang_num == 2){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
			MY_EV_SUB(32);
		}
	}
}
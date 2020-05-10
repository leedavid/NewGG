#ifndef END_my_m_MT_R_2che2pawn_B_1che1ma2pawn
#define END_my_m_MT_R_2che2pawn_B_1che1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2车2兵对1车1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int ADD_2CheXPawn_1Che1Pao1Ma1Pawn_ByPawnShi[3]    = {96, 64, 32};            //2车x兵对1车1炮1马1兵, 兵方的加分
//const int ADD_1Che1Pao1Ma1Pawn_2CheXPawn_ByPawnShi[3]    = {96, 64, 32};            //1车1炮1马1兵对2车x兵, 兵方的加分

void my_m_MT_R_2che2pawn_B_1che1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;
	Square yk = your_king_pos;
	Square yma = S90_from_piecelist(POSITION,your_ma,0);

	// fen 3ak1b2/4a1R2/9/p7p/9/8P/P1r6/9/2n2R3/3K5 b - - 0 1
	if((your_shi_num + your_xiang_num) <= 3){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			if(EV_YOUR_CAN == 0){
				MY_EV_ADD(64);
			}
		}
	}

	// fen 4k4/3ra4/4R4/3P1N2p/p8/4P4/r8/9/4A4/3AK4 b - - 0 1
	if(your_shi_num == 2 && MY_SQ04 == yk){
		if(my_shi_num <= 1 && EV_YOUR_CAN == 2){
			if(StoY(yma) MY_LARGE_EQL MY_RANK5){
				if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
					MY_EV_SUB(64);
				}
			}
		}
	}

	// fen 3ak1b2/4a4/4b4/6R2/p4P2p/9/r7P/3R5/2nK5/9 b - - 0 1
	if(EV_MY_CAN <= 1 && !have_bit(bb_your_pawn,MyLowBB[MY_RANK4])){
		if(have_bit(bb_your_pawn,MyUpBB[MY_RANK5])){
			MY_EV_ADD(32);
		}
	}
}
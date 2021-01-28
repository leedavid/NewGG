#ifndef END_my_m_MT_R_1che1pao2pawn_B_1che2pao
#define END_my_m_MT_R_1che1pao2pawn_B_1che2pao
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车1炮2兵对1车2炮.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int  ADD_CheMaXPawn_VS_1Che2Pawn_ByShi[3]     = {96, 64, 32};            //车炮X兵对车2兵_兵的加分
//const int  ADD_1Che2Pawn_VS_CheMaXPawn_ByShi[3]     = {96, 64, 32};            //车2兵_兵对车炮X兵的加分


void my_m_MT_R_1che1pao2pawn_B_1che2pao(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoXPawn_VS_1Che2Pawn_ByShi[your_shi_num]);

	// fen 3k1a3/4a2c1/8c/P8/3PR2C1/6P2/9/4B4/4K4/3r1A3 w - - 0 1
	if(my_xiang_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(your_xiang_num == 0){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	// fen 4k4/4a4/4b4/9/pr2c1b2/4R2C1/5pp2/4B4/2C1A4/3AK1B2 b - - 0 90
	if (your_shi_num == 2 && your_xiang_num == 2){
		if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK3])){
			MY_EV_SUB(32);
		}
		if (have_bit(bb_my_pawn, MyLowBB[MY_RANK4])){
			MY_EV_SUB(32);
		}
	}
}


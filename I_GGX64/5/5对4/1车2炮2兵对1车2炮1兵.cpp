#ifndef END_m_MT_R_1che2pao2pawn_B_1che2pao1pawn
#define END_m_MT_R_1che2pao2pawn_B_1che2pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
#include "..\\..\\endgame\mat.h"
#include "1车2炮2兵对1车2炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan      =  32;                     //2车方有兵可过河，


void my_m_MT_R_1che2pao2pawn_B_1che2pao1pawn(typePOS &POSITION, EvalInfo &ei){

	// fen 2c1ka3/4a4/4b4/1R7/3NP1b2/3C5/p7P/2r4c1/9/3AKAB2 b - - 0 1
	MY_EV_ADD(EV_MY_CAN * 32);

	Square mk = my_king_pos;

	if(my_xiang_num == 2 && my_shi_num >= 1 && StoY(mk) == MY_RANK9){
		MY_EV_ADD(EV_MY_CAN * 16);
	}

	//  fen 2b1k2C1/9/3aba3/4R2P1/p4c1P1/4c1C2/3r5/5A3/4K4/5AB2 b - - 0 1
	if (!have_bit(bb_your_pawn, MyLowBB[MY_RANK4])) {
		MY_EV_ADD(count_1s(bb_my_pawn, MyUpBB[MY_RANK5]) * 32);
	}
}
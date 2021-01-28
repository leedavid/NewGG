#ifndef END_m_MT_R_1che1pao1ma2pawn_B_1che1pao2pawn
#define END_m_MT_R_1che1pao1ma2pawn_B_1che1pao2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
#include "..\\..\\endgame\mat.h"
#include "1车1炮1马2兵对1车1炮2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan      =  32;                     //2车方有兵可过河，


void my_m_MT_R_1che1pao1ma2pawn_B_1che1pao2pawn(typePOS &POSITION, EvalInfo &ei){

	// fen 3akab2/9/4b1N2/8p/p8/2R1P1C2/Pr6P/4K4/9/c1B6 b - - 0 1
	if(EV_YOUR_CAN == 0){
		MY_EV_ADD(32);
	}

	if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK5])){
		MY_EV_ADD(EV_MY_CAN * 16);
	}
}
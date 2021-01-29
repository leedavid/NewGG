#ifndef END_my_m_MT_R_1che1pao1ma3pawn_B_1che1pao2pawn
#define END_my_m_MT_R_1che1pao1ma3pawn_B_1che1pao2pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车1炮1马3兵对1车1炮2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 
#pragma warning(disable : 4100) 
void my_m_MT_R_1che1pao1ma3pawn_B_1che1pao2pawn(typePOS &POSITION, EvalInfo &ei){

	// fen 4kab2/4a4/5c3/8p/C1b1RN3/P1p6/4P3P/9/4K4/2r6 b - - 0 1

	if(EV_YOUR_CAN <= 1){
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	// fen 3akab2/9/4b1N2/8p/p8/2R1P1C2/Pr6P/4K4/9/c1B6 b - - 0 1
	if(EV_YOUR_CAN == 0){
		MY_EV_ADD(32);
	}
}

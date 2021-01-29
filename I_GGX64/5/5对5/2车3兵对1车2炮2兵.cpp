#ifndef END_my_m_MT_R_2che3pawn_B_1che2pao2pawn
#define END_my_m_MT_R_2che3pawn_B_1che2pao2pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "2车3兵对1车2炮2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//const int ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan      =  32;                     //2车方有兵可过河，


void my_m_MT_R_2che3pawn_B_1che2pao2pawn(typePOS &POSITION, EvalInfo &ei){

	// fen 2c1ka3/4a4/9/p7p/9/9/P1P3R1P/4K4/r8/2c1R4 b - - 0 1
	if(your_xiang_num == 0 && EV_YOUR_CAN <= 0){
		MY_EV_ADD(EV_MY_CAN * 32);
		MY_EV_ADD(64);
	}
}
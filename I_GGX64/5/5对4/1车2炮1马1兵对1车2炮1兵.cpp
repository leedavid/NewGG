#ifndef END_my_m_MT_R_1che2pao1ma1pawn_B_1che2pao1pawn
#define END_my_m_MT_R_1che2pao1ma1pawn_B_1che2pao1pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车2炮1马1兵对1车2炮1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//const int ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan      =  32;                     //2车方有兵可过河，


void my_m_MT_R_1che2pao1ma1pawn_B_1che2pao1pawn(typePOS &POSITION, EvalInfo &ei){

	// fen 1C2c4/5k3/7r1/4C3p/3P5/3R5/9/B8/1n1KA4/5AB1c b - - 0 1
    Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	Square mma = S90_from_piecelist(POSITION,my_ma,0);

	if(StoY(ypawn) MY_SMALL_EQL MY_RANK5){
		MY_EV_ADD(64);
	}

	if(StoY(mma) MY_SMALL_EQL MY_RANK4){
		MY_EV_ADD(32);
	}
}

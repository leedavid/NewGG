#ifndef END_m_MT_R_1che1pao1ma2pawn_B_1che1ma1pawn
#define END_m_MT_R_1che1pao1ma2pawn_B_1che1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"
#include "../../endgame/mat.h"
#include "1车1炮1马2兵对1车1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//const int ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan      =  32;                     //2车方有兵可过河，


void my_m_MT_R_1che1pao1ma2pawn_B_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yma = S90_from_piecelist(POSITION,your_ma,0);

	MY_EV_ADD(16);
	// fen 2ba1R3/C3k4/n2ab4/N1p6/P3P1p2/3r5/9/4K4/9/9 b - - 0 1
	if(StoY(yma) MY_SMALL_EQL MY_RANK3){
		if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK4])){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}	
}

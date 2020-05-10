#ifndef END_my_m_MT_R_2che1pao4pawn_B_2che1ma2pawn2
#define END_my_m_MT_R_2che1pao4pawn_B_2che1ma2pawn2
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2车1炮4兵对2车1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan      =  32;                     //2车方有兵可过河，


void my_m_MT_R_2che1pao4pawn_B_2che1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;
	Square yma = S90_from_piecelist(POSITION,your_ma,0);

    // fen 4kab2/4a4/2r1b4/9/pn2P1p2/2C5R/P3R1P1P/4B2r1/9/3AKA3 w - - 0 1
	if(my_shi_num == 2 && StoY(mk) == MY_RANK9){
		if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK4]) && StoY(yma) MY_SMALL_EQL MY_RANK4){
			MY_EV_ADD(EV_MY_CAN * 16);
			if(EV_YOUR_CAN == 0){
				MY_EV_ADD(32);
			}
		}
	}
}
#ifndef END_m_MT_R_1che1pao1ma2pawn_B_1che2ma1pawn
#define END_m_MT_R_1che1pao1ma2pawn_B_1che2ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
#include "..\\..\\endgame\mat.h"
#include "1车1炮1马2兵对1车2马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan      =  32;                     //2车方有兵可过河，


void my_m_MT_R_1che1pao1ma2pawn_B_1che2ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	// fen 2bak1b2/4a4/5n3/9/3r3np/4R4/P3P4/4B2C1/4A1N2/4KA3 b - - 0 1
	if(StoY(mk) == MY_RANK9){
		if((my_shi_num + my_xiang_num) >= 3){
			if(!have_bit(bb_your_ma,MyLowBB[MY_RANK4])){
				MY_EV_ADD(EV_MY_CAN * 16);
			}
			if(StoY(ypawn) MY_SMALL_EQL MY_RANK4){
				MY_EV_ADD(EV_MY_CAN * 16);
			}
		}
	}

	// fen 2bak4/4a4/4b1n2/9/3R5/4P4/pn4P2/2C1BA1rN/4A4/4K1B2 w - - 0 1
	if(abs(StoX(ypawn) - 0x4) >= 3){
		MY_EV_ADD(32);
	}
	if((my_shi_num + my_xiang_num) == 4 && StoY(mk) == MY_RANK9){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK6){
			MY_EV_ADD(32);
		}
	}
}
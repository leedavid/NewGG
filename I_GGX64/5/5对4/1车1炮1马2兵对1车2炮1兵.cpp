#ifndef END_m_MT_R_1che1pao1ma2pawn_B_1che2pao1pawn
#define END_m_MT_R_1che1pao1ma2pawn_B_1che2pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
#include "..\\..\\endgame\mat.h"
#include "1车1炮1马2兵对1车2炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan      =  32;                     //2车方有兵可过河，


void my_m_MT_R_1che1pao1ma2pawn_B_1che2pao1pawn(typePOS &POSITION, EvalInfo &ei){
	
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mk    = my_king_pos;

	// fen 2c1ka3/4a4/4b4/1R7/3NP1b2/3C5/p7P/2r4c1/9/3AKAB2 b - - 0 1
	MY_EV_ADD(EV_MY_CAN * 32);

	// fen 4kab2/4aC3/N3c3b/3R5/1P2P3p/2r3P2/8c/3AB4/9/4K4 b - - 0 1
	if(my_shi_num >= 1 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK6 && abs(StoX(ypawn) - 0x4) == 4){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 2b1kacC1/1NP1a4/4b4/3rp2R1/5c3/P8/9/5A3/9/4KA3 w - - 0 1
	if(my_shi_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK4])){
			MY_EV_ADD(EV_MY_CAN * 16);

			//我方的一个炮在底线，给对方控制了
			if(have_bit(bb_your_pao,m_and(MyUpBB[MY_RANK2],EV_MY_XBIT))){
				MY_EV_ADD(32);
			}
		}
	}
}

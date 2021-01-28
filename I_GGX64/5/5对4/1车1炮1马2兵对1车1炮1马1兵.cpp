#ifndef END_m_MT_R_1che1pao1ma2pawn_B_1che1pao1ma1pawn
#define END_m_MT_R_1che1pao1ma2pawn_B_1che1pao1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
#include "..\\..\\endgame\mat.h"
#include "1车1炮1马2兵对1车1炮1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan      =  32;                     //2车方有兵可过河，


void my_m_MT_R_1che1pao1ma2pawn_B_1che1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square mma = S90_from_piecelist(POSITION,my_ma,0);
	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square yk = your_king_pos;
	// fen 2bak4/4a3c/4b4/7R1/9/2PnP4/3r2p2/3NB4/4A4/3AKCB2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5]) && EV_MY_CAN <= 1 && StoY(mma) MY_LARGE_EQL MY_RANK7){
			if(StoY(ypawn) MY_LARGE_EQL MY_RANK5 && StoY(yma) MY_LARGE_EQL MY_RANK5){
				MY_EV_SUB(32);
			}
		}
	}
}
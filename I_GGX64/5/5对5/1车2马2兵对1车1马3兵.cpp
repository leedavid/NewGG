#ifndef END_my_m_MT_R_1che2ma2pawn_B_1che1ma3pawn
#define END_my_m_MT_R_1che2ma2pawn_B_1che1ma3pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车2马2兵对1车1马3兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che2ma2pawn_B_1che1ma3pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mche = S90_from_piecelist(POSITION, my_che, 0);
	Square yche = S90_from_piecelist(POSITION, your_che, 0);
	Square yma = S90_from_piecelist(POSITION, your_ma, 0);

	// fen 2b1ka3/4a4/4b4/9/p3p3p/1N1n5/P1r5P/R1N6/4A4/2BAK1B2 w - - 0 1
	if (EV_MY_CAN == 0){
		if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if (StoY(mche) MY_LARGE_EQL MY_RANK7 && StoY(yche) MY_LARGE_EQL MY_RANK5){
				if (!have_bit(bb_my_ma, MyUpBB[MY_RANK5])){
					if (EV_YOUR_CAN >= 1){
						MY_EV_SUB(32);
						if (StoY(yma) MY_LARGE_EQL MY_RANK5){
							MY_EV_SUB(32);
						}
					}
				}
			}
		}
	}
}
#ifndef ENDR_1che2pao3pawn_B_2che3pawn
#define ENDR_1che2pao3pawn_B_2che3pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车2炮3兵对2车3兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che2pao3pawn_B_2che3pawn(typePOS &POSITION, EvalInfo &ei){

	// fen 3ak1b2/1R2a4/1c2b2c1/2p6/p1r5p/6P2/P2R4P/4B4/9/3AKAB2 w - - 20 20
	//双车有一个车背了

	if((my_shi_num + my_xiang_num) == 4 && StoY(my_king_pos) == MY_RANK9){
		int ycan  = EV_YOUR_CAN;
		int yover = Your_pawn_already_over_river(POSITION);

		if(ycan == 0 && yover == 0){
			MY_EV_ADD(128);

			Square mpao1 = S90_from_piecelist(POSITION,my_pao,0);
			Square mpao2 = S90_from_piecelist(POSITION,my_pao,1);

			if(StoY(mpao1) == MY_RANK7 && StoY(mpao2) == MY_RANK7 && !IsOnSameSide(mpao1,mpao2)){
				if(m_have_bit(m_and(
					bb_your_che,MyLowBB[MY_RANK7]))){
						MY_EV_ADD(96);
				}
			}
		}
	}
}


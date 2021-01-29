#ifndef END_my_m_MT_R_1che1pao2ma3pawn_B_1che1pao1ma1pawn
#define END_my_m_MT_R_1che1pao2ma3pawn_B_1che1pao1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车1炮2马3兵对1车1炮1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che1pao2ma3pawn_B_1che1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){


	Square yma  = S90_from_piecelist(POSITION,your_ma,0);
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);

	
	//对方的兵没有过河
	if(!have_bit(MyLowBB[MY_RANK4],bb_your_pawn)){
		MY_EV_ADD(32);
		//对方的马没有过河


		if(StoY(yma) MY_SMALL_EQL MY_RANK3){
			MY_EV_ADD(32);  // 对方的炮在我这边
			if(StoY(ypao) MY_LARGE_EQL MY_RANK5){
				MY_EV_ADD(32);
			}
		}
		
	}
	
}
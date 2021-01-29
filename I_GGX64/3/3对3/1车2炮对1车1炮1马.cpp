#ifndef END_my_m_MT_R_1che2pao_B_1che1pao1ma
#define END_my_m_MT_R_1che2pao_B_1che1pao1ma
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车2炮对1车1炮1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int  AD_Che_CanNotMove = 256;

void my_m_MT_R_1che2pao_B_1che1pao1ma(typePOS &POSITION, EvalInfo &ei){


	Square mk = my_king_pos;
	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	Square yche = S90_from_piecelist(POSITION,your_che,0);

	// fen 4k4/1R7/4b4/c8/9/1n7/9/3K1A3/2C1AC3/2r6 b - - 0 1
	if(StoY(mk) == MY_RANK7){
		if(StoY(yma) MY_LARGE_EQL MY_RANK5){
			MY_EV_SUB(32);
			if(StoY(yche) MY_LARGE_EQL MY_RANK5){
				MY_EV_SUB(32);
			}
		}
		if(my_xiang_num == 0){
			MY_EV_SUB(32);
		}
	}
}
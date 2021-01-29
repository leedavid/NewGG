#ifndef END_my_m_MT_R_1che2ma2pawn_B_1che1ma1pawn
#define END_my_m_MT_R_1che2ma2pawn_B_1che1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车2马2兵对1车1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

void my_m_MT_R_1che2ma2pawn_B_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	Square mk  = my_king_pos;

	// fen 1Nb1ka3/4a4/4b4/p8/5n3/5N3/P7P/6R2/5K3/2r6 b - - 0 1
	if(EV_YOUR_CAN == 0){
		MY_EV_ADD(32);
		MY_EV_ADD(EV_MY_CAN * 64);
		if(abs(StoY(yma) - StoY(mk)) >= 3){
			MY_EV_ADD(32);
		}
	}

}


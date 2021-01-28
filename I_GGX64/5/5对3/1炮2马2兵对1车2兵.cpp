#ifndef END_my_m_MT_R_1pao2ma2pawn_B_1che2paawn
#define END_my_m_MT_R_1pao2ma2pawn_B_1che2paawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1炮2马2兵对1车2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1pao2ma2pawn_B_1che2pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;
	Square yche = S90_from_piecelist(POSITION,your_che,0);
	// fen r3ka3/4a4/4b4/2N5p/2b6/2N5P/P2C5/4p4/4A4/3AK4 b - - 0 1
	if(EV_YOUR_CAN <= 1){
		if(StoY(mk) == MY_RANK9 && my_shi_num == 2 && !have_bit(bb_my_ma,MyLowBB[MY_RANK6])){
			if(StoY(yche) MY_SMALL_EQL MY_RANK4){
				MY_EV_ADD(32);
				MY_EV_ADD(EV_MY_CAN * 16);
			}
		}
	}
}
#ifndef END_my_m_MT_R_2pao2ma1pawn_B_1che1pao1pawn
#define END_my_m_MT_R_2pao2ma1pawn_B_1che1pao1pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "2炮2马1兵对1车1炮1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

void my_m_MT_R_2pao2ma1pawn_B_1che1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	// fen C2k1abr1/4a4/4b4/1C7/1P7/3p5/2c6/2N1BA2N/3K5/5AB2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(!have_bit(bb_my_ma,MyUpBB[MY_RANK5])){
			MY_EV_SUB(32);
			if(StoY(mk) != MY_RANK9){
				MY_EV_SUB(32);
				if(StoY(ypawn) MY_LARGE_EQL MY_RANK5){
					MY_EV_SUB(32);
				}
			}
		}
	}

}
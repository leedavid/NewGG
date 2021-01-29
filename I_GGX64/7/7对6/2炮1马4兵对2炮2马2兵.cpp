#ifndef END_my_m_MT_R_2pao1ma4pawn_B_2pao2ma2pawn
#define END_my_m_MT_R_2pao1ma4pawn_B_2pao2ma2pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "2炮1马4兵对2炮2马2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_2pao1ma4pawn_B_2pao2ma2pawn(typePOS &POSITION, EvalInfo &ei){
	//
	Square yk = your_king_pos;

	// fen 1nba1ab2/4k4/4c1n2/p1P5p/5Cc2/3N2N2/P3P3P/4B4/4A4/2BAK4 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(count_1s(bb_my_pawn,MyUpBB[MY_RANK4]) <= 1){
			MY_EV_SUB(64);
		}
	}
}

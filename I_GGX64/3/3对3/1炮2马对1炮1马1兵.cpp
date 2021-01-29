#ifndef END_my_m_MT_R_1pao2ma_B_1pao1ma1pawn
#define END_my_m_MT_R_1pao2ma_B_1pao1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮2马对1炮1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



//ADD_1PaoXPawn_1PaoXPawn_ByShi

void my_m_MT_R_1pao2ma_B_1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){


	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1pao2ma_1pao1maXpawn_ByShi[my_shi_num]);

}

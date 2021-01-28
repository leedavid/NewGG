#ifndef END_my_m_MT_R_2ma3pawn_B_1pao2ma1pawn
#define END_my_m_MT_R_2ma3pawn_B_1pao2ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2马3兵对1炮2马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_2ma3pawn_B_1pao2ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// fen 1nbakab2/5Nc2/3P5/p7c/5N3/9/P3P4/4B4/4A4/2BAK4 b - - 0 1
	if(count_1s(bb_my_pawn,MyUpBB[MY_RANK3]) <= 1){
		if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			MY_EV_SUB(64);
		}
	}
	MY_EV_SUB(EV_YOUR_CAN * 32);
}
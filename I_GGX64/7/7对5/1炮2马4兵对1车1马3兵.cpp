#ifndef END_my_m_MT_R_1pao2ma4pawn_B_1che1ma3pawn
#define END_my_m_MT_R_1pao2ma4pawn_B_1che1ma3pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1炮2马4兵对1车1马3兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1pao2ma4pawn_B_1che1ma3pawn(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;

	// fen 3akab2/9/1P2b4/p3p1C2/7np/6P2/P1r1P3P/3CB3N/9/3AKAB2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(16);
		if(count_1s(bb_my_pawn,MyUpBB[MY_RANK4]) <= 1){
			MY_EV_SUB(32);
		}
	}
}
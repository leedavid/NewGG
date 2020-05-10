#ifndef END_my_m_MT_R_1che2pao1pawn_B_2che
#define END_my_m_MT_R_1che2pao1pawn_B_2che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1³µ2ÅÚ1±ø¶Ô2³µ.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che2pao1pawn_B_2che(typePOS &POSITION, EvalInfo &ei){

	
	Square yk = your_king_pos;
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	if(my_shi_num == 2 && PB90(MY_SQ55) == my_king){
		EV_MY_SAFE = TRUE;
	}

	// fen 3ak1b2/4a4/4b4/9/4c1p1c/3R4R/2r6/4B4/4A4/4KAB2 b - - 146 146
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5 && EV_MY_SAFE){
			RETRUN_MUL(4);
		}
	}
}

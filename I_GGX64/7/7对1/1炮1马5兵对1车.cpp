#ifndef END_my_m_MT_R_1pao_1ma5pawn_B_1che
#define END_my_m_MT_R_1pao_1ma5pawn_B_1che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马5兵对1车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1pao_1ma5pawn_B_1che(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao1MaXPawn_To_1Che_PawnByShi[your_shi_num]);

	//如果对方是仕相全，且我方的兵没有过河，要减分
	// fen 3ak1b2/4a4/4b4/5r3/9/5CP1P/P3N4/4B4/4A4/2B1KA3 w - - 6 6
	// SUB
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		MY_EV_SUB((sint16)count_1s(bb_my_pawn,MyLowBB[MY_RANK4]) 
			* ADD_1Pao1MaXPawn_To_1Che_PawnNotRiver);
	}
}




#ifndef END_my_m_MAT_R_1pao1ma2pawn_B_1pao2pawn
#define END_my_m_MAT_R_1pao1ma2pawn_B_1pao2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1ÅÚ1Âí2±ø¶Ô1ÅÚ2±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 




void my_m_MT_R_1pao1ma2pawn_B_1pao2pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1pao1maXpawn_To_1pao2pawn_ByPs[your_shi_num]);

	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1pao1maXpawn_To_1pao2pawn_ByPs[my_shi_num]);

	MY_EV_ADD(ADD_1pao1maXpawn_To_1pao2pawn);

	//fen 1P2k4/4a4/4ba3/3P5/3NC1b2/5p3/5c1p1/4B4/4A4/3AK4 b - - 0 4
	if (my_shi_num >= 1){
		MY_EV_ADD(64);
	}
}


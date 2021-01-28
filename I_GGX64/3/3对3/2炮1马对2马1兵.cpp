#ifndef END_my_m_MT_R_2pao1ma_B_2ma1pawn
#define END_my_m_MT_R_2pao1ma_B_2ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮1马对2马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



//ADD_1PaoXPawn_1PaoXPawn_ByShi

void my_m_MT_R_2pao1ma_B_2ma1pawn(typePOS &POSITION, EvalInfo &ei){

	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_2pao1ma_2maXpawn_ByShi[my_shi_num]);



}


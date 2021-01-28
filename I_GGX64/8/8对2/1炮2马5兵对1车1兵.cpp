#ifndef END_my_m_MT_R_1pao_2ma5pawn_B_1che1pawn
#define END_my_m_MT_R_1pao_2ma5pawn_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮2马5兵对1车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//1炮2马5兵对1车, 炮马方要加分

void my_m_MT_R_1pao_2ma5pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	if(StoY(ypawn) MY_SMALL MY_RANK5 || my_shi_num > 0){
		MY_EV_ADD(Add_1炮2马对1车1兵);
	}

	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * Add_1炮2马对1车1兵_byPawn_Shi[your_shi_num]);
}


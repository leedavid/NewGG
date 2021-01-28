#ifndef END_my_m_MT_R_4pawn_B_1ma2pawn
#define END_my_m_MT_R_4pawn_B_1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "4兵对1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_4pawn_B_1ma2pawn(typePOS &POSITION, EvalInfo &ei){
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_3pawn_MaXPawn_ShiAdd[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1MaXPawn_3pawn_ShiAdd[my_shi_num]);

	MY_EV_SUB(ADD_1MaXPawn_3Pawn);


	// fen 2bak4/4a4/4b4/p3p4/8p/4P1B2/P1p6/6p2/N8/2BAKA3 b - - 0 0
	if(your_shi_num == 2){
		MY_EV_SUB(128);
	}
}


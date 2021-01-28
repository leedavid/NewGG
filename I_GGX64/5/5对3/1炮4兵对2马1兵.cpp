#ifndef END_my_m_MT_R_1pao4pawn_B_2ma1pawn
#define END_my_m_MT_R_1pao4pawn_B_2ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1炮4兵对2马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1pao4pawn_B_2ma1pawn(typePOS &POSITION, EvalInfo &ei){	

	Square yk = your_king_pos;
	// fen 3a1k3/4a4/4P4/4PC3/4P3P/2Bn1n3/2p6/3AB4/4A4/4K4 b - - 0 64
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1paoXPawn_2Ma1Pawn_ShiAdd[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1PaoXPawn_1MaXPawn_ByShi[my_shi_num]);

	Square mk = my_king_pos;

	if((my_shi_num + my_xiang_num) == 4 && StoY(mk) MY_SMALL_EQL MY_RANK8){
		MY_EV_ADD(EV_MY_CAN * 8);
	}
}

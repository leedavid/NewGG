#ifndef END_my_m_MT_R_1pao3pawn_B_2pao1pawn
#define END_my_m_MT_R_1pao3pawn_B_2pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1ÅÚ3±ø¶Ô2ÅÚ1±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1pao3pawn_B_2pao1pawn(typePOS &POSITION, EvalInfo &ei){	

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

	// fen 4k4/9/3aCa3/p3p4/8p/P1B6/9/5C3/c3A4/2BAK4 w - - 0 1
	if (EV_YOUR_CAN == 0){
		if (my_shi_num == 2){
			if (PB90(MY_SQ43) == your_pao && PB90(MY_SQ42) == my_shi && PB90(MY_SQ44) == my_shi){
				if (PB90(MY_SQ3A) == my_pawn){
					MY_EV_ADD(256);
					if ((your_shi_num + your_xiang_num) >= 2 && EV_MY_CAN <= 2){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}
}

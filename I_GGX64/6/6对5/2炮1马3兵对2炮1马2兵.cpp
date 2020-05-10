#ifndef END_my_m_MT_R_2pao1ma3pawn_B_2pao1ma2pawn
#define END_my_m_MT_R_2pao1ma3pawn_B_2pao1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2ÅÚ1Âí3±ø¶Ô2ÅÚ1Âí2±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_2pao1ma3pawn_B_2pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2Pao1Ma3pawn_To_1Pao2Ma3Pawn_ByPawn[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_2Pao1Ma3pawn_To_1Pao2Ma3Pawn_ByPawn[my_shi_num]);

	// fen 4kab2/4a4/3c2n2/C7p/4P4/P7P/2p3N2/8C/3KA4/5Ac2 b - - 0 1
	if(EV_YOUR_CAN <= 1){
		if(PB90(MY_SQ28) == my_pawn){
			if(PB90(MY_SQ18) == your_ma && 
				bit_is_set(MY_ATTACK,MY_SQ2B)){
					MY_EV_ADD(EV_MY_CAN * 16);
			}
			if(PB90(MY_SQ14) == your_ma && 
				bit_is_set(MY_ATTACK,MY_SQ25)){
					MY_EV_ADD(EV_MY_CAN * 16);
			}
		}
	}

	// fen C4ab2/4k4/3ab4/2P1N3p/6p2/4P4/1C6P/3A2c2/4K4/1c1n5 b - - 0 1
	if(EV_YOUR_CAN <= 1 && have_bit(bb_my_pawn,MyUpBB[MY_RANK4])){
		MY_EV_ADD(EV_MY_CAN * 32);
		if(my_shi_num >= 1 || my_xiang_num >= 1){
			MY_EV_ADD(32);
		}
	}

}
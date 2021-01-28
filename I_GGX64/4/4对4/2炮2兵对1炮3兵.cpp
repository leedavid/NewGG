#ifndef END_my_m_MT_R_2pao2pawn_B_1pao3pawn
#define END_my_m_MT_R_2pao2pawn_B_1pao3pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2炮2兵对1炮3兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_2pao2pawn_B_1pao3pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	//Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn, MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2Pao2Pawn_To_2MaxPawn_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn, MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_2Pao2Pawn_To_2MaxPawn_ByPawn[my_shi_num]);

    // fen 4k4/9/3aCa3/p3p3p/9/2B6/P7P/9/4A4/c1BAKC3 w - - 0 1
	if (EV_MY_CAN == 0){
		if (your_shi_num == 2){
			if (PB90(MY_SQ16) == my_pao && PB90(MY_SQ15) == your_shi && PB90(MY_SQ17) == your_shi){
				if (PB90(MY_SQ1F) == your_pawn){
					MY_EV_SUB(256);
					if ((my_shi_num + my_xiang_num) >= 2){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

}
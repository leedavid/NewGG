#ifndef END_my_m_MT_R_2che1pawn_B_1che2pawn
#define END_my_m_MT_R_2che1pawn_B_1che2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2车1兵对1车2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//2车1兵对1车2兵
void my_m_MT_R_2che1pawn_B_1che2pawn(typePOS &POSITION, EvalInfo &ei){
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2CheXPawn_1Che2Pawn_ByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1CheXPawn__2Che1Pawn_ByShi[my_shi_num]);


	// fen 4kab2/4a2R1/4br3/9/6p2/9/4R1P1p/4B4/4A4/2B1KA3 w - - 9 9
	if((your_shi_num + your_xiang_num) == 4 && MY_SQ04 == yk){
		if(PB90(MY_SQ16) == your_xiang){
			if(PB90(MY_SQ2A) == your_pawn){
				if(PB90(MY_SQ3C) == my_pawn && PB90(MY_SQ3E) == your_pawn){
					RETRUN_MUL(4);
				}
			}
			if(PB90(MY_SQ26) == your_pawn){
				if(PB90(MY_SQ38) == my_pawn && PB90(MY_SQ36) == your_pawn){
					RETRUN_MUL(4);
				}
			}
		}
	}

}


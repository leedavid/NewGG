
#ifndef END_my_m_MT_R_1che1ma5pawn_B_2che
#define END_my_m_MT_R_1che1ma5pawn_B_2che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1马5兵对2车_not.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int MAT_R_2che1pawn_B_1che1ma1pawn_MaSafe = 256;


void my_m_MT_R_1che1ma5pawn_B_2che(typePOS &POSITION, EvalInfo &ei){
	////////////////////
	Square mk = my_king_pos;

	Square yk = your_king_pos;

	your_m_MT_R_2CHE_B_1CHE1MA(POSITION,ei);

	if(ei.mul <= 2){
		EV_MY_SAFE = TRUE;
	}

	if(my_xiang_num >= 1 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if(PB90(MY_SQ3A) == my_ma && PB90(MY_SQ43) == your_che){
			if(PB90(MY_SQ53) == my_xiang && PB90(MY_SQ4B) == your_che){
				EV_MY_SAFE = TRUE;
			}
			if(PB90(MY_SQ57) == my_xiang && PB90(MY_SQ4D) == your_che){
				EV_MY_SAFE = TRUE;
			}
		}
	}

	// ADD 
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	if(EV_MY_SAFE){
		MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheMaPawn_2Che_MaSafe_ByPawn[your_shi_num] * 3/2);
	}
	else{
		MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheMaPawn_2Che_MaSafe_ByPawn[your_shi_num]);
	}

}


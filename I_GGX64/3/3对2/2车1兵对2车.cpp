#ifndef END_my_m_MT_R_2che1pawn_B_2che
#define END_my_m_MT_R_2che1pawn_B_2che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
#include "..\\..\\endgame\mat.h"
#include "2车1兵对2车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int const_Shi_add[3] = {128,48,0};
//const int const_Pawn_add   =  48;

//2车1兵对2车
void my_m_MT_R_2che1pawn_B_2che(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2车x兵对2车_byPawn[your_shi_num]);

	MY_EV_ADD(ADD_2che_2che_const_Shi_add[your_shi_num]);
	MY_EV_SUB(ADD_2che_2che_const_Shi_add[my_shi_num]);

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	if(StoY(mpawn) != MY_RANK0){
		MY_EV_ADD(64);
	}

	if(my_shi_num == 2 && my_xiang_num >= 1 && PB90(MY_SQ55) == my_king){
		EV_MY_SAFE = TRUE;
	}

	int mcan = EV_MY_CAN;

	if(your_shi_num == 2 && your_xiang_num >= 1 && mcan == 0){
		if(PB90(MY_SQ04) == your_king){
			EV_YOUR_SAFE = TRUE;
		}
	}

	// fen 2b1ka3/4a4/4b4/8r/1r7/P4RR2/9/4B4/4A4/4KAB2 b - - 0 0
	if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
		if(your_shi_num == 2 && your_xiang_num == 2 && PB90(MY_SQ04) == your_king){
			EV_YOUR_SAFE = TRUE;
		}
	}
	
	// fen 3ak4/4a4/4b4/1r6p/2b6/R6R1/8r/9/4A4/2B1KA3 w - - 11 11
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num >=1 && PB90(MY_SQ04) == your_king){
			Square yche1 = S90_from_piecelist(POSITION,your_che,0);
			Square yche2 = S90_from_piecelist(POSITION,your_che,1);
			if(StoY(yche1) == StoY(yche2) && StoY(yche1) MY_LARGE_EQL MY_RANK3){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4ka3/4a4/4br3/4R3R/8P/6r2/9/9/4A4/4KAB2 w - - 0 1
	if (EV_MY_SAFE) {
		if (your_shi_num == 2 && your_xiang_num >= 1 && PB90(MY_SQ04) == your_king) {
			if (StoY(mpawn) MY_LARGE_EQL MY_RANK3) {
				RETRUN_MUL(8);
			}
		}
	}
}


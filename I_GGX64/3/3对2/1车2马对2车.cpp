#ifndef END_my_m_MT_R_1che2ma_B_2che
#define END_my_m_MT_R_1che2ma_B_2che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车2马对2车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//车2炮对车炮
void my_m_MT_R_1che2ma_B_2che(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;

	if((your_shi_num + your_xiang_num) >= 2 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(ADD_2车x兵对1车2马);
	}

	Bitboard bmma = m_and(bb_my_ma,MyLowBB[MY_RANK6]);
	if(count_1s(bmma) == 2 && my_shi_num <= 1){
		MY_EV_SUB(32);
	}

	if((my_shi_num + my_xiang_num) == 4 && StoY(mk) == MY_RANK9){
		EV_MY_SAFE = TRUE;
	}

	// fen 2bk5/6R2/2r6/3NP4/2br5/9/9/9/4A4/3AK1B2 w - - 0 133
	if((my_shi_num + my_xiang_num) <= 3){

		MY_EV_SUB((4 - (my_shi_num + my_xiang_num)) * 64);

		if((your_shi_num + your_xiang_num) >= 2){
			MY_EV_SUB(64);
		}
	}

	// fen 3k2b2/4a4/4brN2/4R4/5N3/9/3r5/9/4A4/3AK1B2 b - - 0 1
	if (my_shi_num == 2 && my_xiang_num >= 1 && MY_SQ55 == mk){
		MY_EV_ADD(32);
	}

	



	// fen r1ba1k3/4a4/9/1R2PN3/2b2r3/9/9/4B4/9/2BAKA3 w - - 0 1
	if(EV_MY_SAFE && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if((your_shi_num + your_xiang_num) >= 2){
			MY_EV_SUB(80);
			RETRUN_MUL(4);
		}
		if(your_xiang_num == 2){
			if(PB90(MY_SQ0C) != my_pawn){
				MY_EV_SUB(80);
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3k2b2/4a4/4brN2/4R4/5N3/9/3r5/9/4A4/3AK1B2 b - - 0 1
	if (my_shi_num == 2 && my_xiang_num >= 1 && MY_SQ55 == mk){
		if ((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
			RETRUN_MUL(8);
		}
	}
}


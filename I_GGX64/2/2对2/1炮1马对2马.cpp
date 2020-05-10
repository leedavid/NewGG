#ifndef END_my_m_MT_R_1pao1ma_B_2ma
#define END_my_m_MT_R_1pao1ma_B_2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1ÅÚ1Âí¶Ô2Âí.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//prematerilainfo.cpp(765): pMat->mat_dummy = (uint16)(turn == WHITE ? MAT_R_1pao1ma_B_2ma : MAT_B_1pao1ma_R_2ma);
void my_m_MT_R_1pao1ma_B_2ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;

	if((your_shi_num + your_xiang_num) == 4){
		if(StoY(yk) == MY_RANK0){
			RETRUN_MUL(2);
		}
	}

	if((my_shi_num + my_xiang_num) >= 2){
		EV_MY_SAFE = TRUE;
	}

	if(my_shi_num >= 1 || my_xiang_num >= 1){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			EV_MY_SAFE = TRUE;
		}
	}

	MY_EV_ADD(64);

	if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		MY_EV_SUB(80);
	}

	if(my_shi_num == 0){
		RETRUN_MUL(2);
	}
	// fen 4k4/4a4/1Nn1ba3/9/3n5/2B3B2/9/3A5/4A4/2C2K3 b - - 0 114
	if((my_shi_num + my_xiang_num) >= 2){
		if((your_shi_num + your_xiang_num) >= 3){
			if(StoY(yk) MY_SMALL_EQL MY_RANK1){
				RETRUN_MUL(4);
			}
		}
	}
	// fen 3k5/2N1a4/3ab4/4c4/2b1N1n2/6B2/9/4B4/4K4/9 r
	if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(!have_bit(EV_MY_XBIT,bb_your_ma)){
		    RETRUN_MUL(6);
		}
	}

	// fen 5k3/9/b4a3/4N4/4n4/9/3nC4/4BA3/4A4/2BK5 b - - 0 1
	if(EV_MY_SAFE){
		if((your_shi_num + your_xiang_num) >= 2){
			if(!have_bit(bb_your_ma,MyLowBB[MY_RANK6])){
				RETRUN_MUL(6);
			}
		}
	}

	// fen 4k4/4a4/9/5N3/1n7/2B6/9/B2A1n3/5C3/4K4 w - - 0 1
	if((your_shi_num + your_xiang_num) >= 1){
		RETRUN_MUL(8);
	}

	// fen 4k4/9/9/6N2/9/9/9/2n2A1n1/3K5/5C3 w - - 0 1
	if((my_shi_num + my_xiang_num) <= 1){
		RETRUN_MUL(8);
	}

	// fen 4k4/9/9/9/9/3Nn4/3C5/4B1n2/4A4/3K5 w - - 0 1
	if(EV_MY_SAFE){
		if(my_shi_num <= 1 && my_xiang_num <= 1){
			if(!have_bit(EV_MY_XBIT,bb_your_ma)){
				RETRUN_MUL(8);
			}
		}
	}
}


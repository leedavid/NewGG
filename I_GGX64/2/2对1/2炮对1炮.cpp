#ifndef END_my_m_MT_R_2pao_B_1pao
#define END_my_m_MT_R_2pao_B_1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮对1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_2pao_B_1pao(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;

	Square ypao = S90_from_piecelist(POSITION,your_pao,0);

	// 双炮例和炮仕相全
	if((your_shi_num + your_xiang_num) == 4){
		RETRUN_MUL(2);
	}
	// 双炮例和一炮
	if((my_shi_num + my_xiang_num) == 0){
		RETRUN_MUL(2);
	}

	// fen 4k4/4C4/1c7/9/9/2B6/9/9/C8/4K4 b - - 0 1
	if (my_shi_num == 0){
		if (StoY(ypao) MY_SMALL_EQL MY_RANK4){
			RETRUN_MUL(2);
		}
	}

	// fen 4c4/5c3/3k5/9/6b2/9/9/9/4K4/3C5 w - - 0 1
	if(my_shi_num == 0){
		if(StoY(ypao) == MY_RANK0 && StoY(yk) != MY_RANK0){
			RETRUN_MUL(2);
		}
	}

	// fen 4k1b2/9/6c2/6c2/6b2/9/9/5C3/4A4/4K4 b - - 0 1
	if (my_shi_num == 0){
		if (your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if (!bit_is_set(EV_MY_XBIT, ypao)){
				RETRUN_MUL(2);
			}
		}
	}

	// fen C1bCk4/3c5/4b4/9/9/6B2/9/5A3/9/2B1KA3 b - - 0 0
	// 如果对方的一炮一动也不能动了，也算和棋
	if((your_xiang_num + your_shi_num) >= 2 && StoY(yk) == MY_RANK0){
		if(PB90(MY_SQ03) == my_pao && PB90(MY_SQ0C) == your_pao){
			if(PB90(MY_SQ02) == your_xiang){
				RETRUN_MUL(2);
			}
		}
		if(PB90(MY_SQ05) == my_pao && PB90(MY_SQ0E) == your_pao){
			if(PB90(MY_SQ06) == your_xiang){
				RETRUN_MUL(2);
			}
		}
	}

	if(my_shi_num == 0){
		MY_EV_SUB(96);
	}

	// fen 3k1a3/4c4/4b3b/7C1/9/6B2/9/9/3C5/3K5 w - - 109 109
	if(my_shi_num == 0 && your_xiang_num == 2){
		RETRUN_MUL(2);
	}

	// fen 3ak4/4c4/b8/9/2b6/2B6/5C3/5C3/9/3A1K3 w - - 0 1
	if (your_shi_num >= 1 && your_xiang_num == 2
		&& StoY(yk) == MY_RANK0) {
		if (my_shi_num <= 1) {
			RETRUN_MUL(2);
		}
	}

	// fen 4k4/4c4/4b4/9/2b6/9/9/3A2C2/9/3K1C3 b - - 0 1
	if(your_xiang_num == 2){
		if(my_xiang_num == 0){
			if(StoY(yk) MY_SMALL_EQL MY_RANK1){
				MY_EV_SUB(128);
			}
			RETRUN_MUL(3);
		}
		RETRUN_MUL(4);
	}

	// fen 3a1k3/3c3c1/3ab4/9/2b6/9/5C3/3A5/4A4/4K1B2 w - - 58 58
	// fen 3a1k3/3c3c1/3ab4/9/2b6/9/5C3/3A5/4A4/4K1B2 w - - 58 58
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(StoY(yk) == MY_RANK0){
			RETRUN_MUL(2);
		}
		if(StoY(yk) == MY_RANK1){
			RETRUN_MUL(4);
		}
	}

	if(my_shi_num == 0){
		if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(4);
		}
	}

	// fen 4k4/4c4/3aba1c1/7C1/2b6/9/9/4B4/4K4/9 w - - 0 1
	if(your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		RETRUN_MUL(8);
	}
	
}



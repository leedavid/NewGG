#ifndef END_my_m_MT_R_2pao_B_1che
#define END_my_m_MT_R_2pao_B_1che
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2炮对1车.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

// fen 9/3kc4/5c3/9/9/8R/9/9/9/3K5 w

// fen 3c5/3k5/9/9/5c3/8R/9/9/9/4K4 w

//const int CheAdd = 96;

void my_m_MT_R_2pao_B_1che(typePOS &POSITION, EvalInfo &ei){

	Square mk    = my_king_pos;
	Square mpao1 = S90_from_piecelist(POSITION,my_pao,0);
	Square mpao2 = S90_from_piecelist(POSITION,my_pao,1);

	// 当炮方没有2仕或2相后,还有一个可和的形
	if(my_shi_num == 2 || my_xiang_num == 2){
		RETRUN_MUL(2);
	}
	// 
	if(StoY(mk) MY_SMALL_EQL MY_RANK8){
		if(StoY(mpao1) == MY_RANK9 && StoX(mk) == StoX(mpao1)){
			RETRUN_MUL(2);
		}
		if(StoY(mpao2) == MY_RANK9 && StoX(mk) == StoX(mpao2)){
			RETRUN_MUL(2);
		}
	}

	//  fen 3k1ab2/4a4/9/3r5/2b6/9/9/8C/4CK3/9 b - - 0 1
	if (StoY(mk) MY_LARGE_EQL MY_RANK8) {
		if (StoY(mpao1) == (StoY(mk) MY_SUB 1)) {
			if (StoY(mpao2) == StoY(mk)) {
				if (StoX(mk) >= 0x4 && StoX(mpao2) < StoX(mk)) {
					RETRUN_MUL(4);
				}
				if (StoX(mk) <= 0x4 && StoX(mpao2) > StoX(mk)) {
					RETRUN_MUL(4);
				}
			}
		}
		if (StoY(mpao2) == (StoY(mk) MY_SUB 1)) {
			if (StoY(mpao1) == StoY(mk)) {
				if (StoX(mk) >= 0x4 && StoX(mpao1) < StoX(mk)) {
					RETRUN_MUL(4);
				}
				if (StoX(mk) <= 0x4 && StoX(mpao1) > StoX(mk)) {
					RETRUN_MUL(4);
				}
			}
		}
	}

	//  fen 3k1ab2/4a4/9/9/2b6/9/9/9/3rCK3/8C b - - 0 1
	if (StoY(mk) == MY_RANK8) {
		if (StoY(mpao1) == MY_RANK9) {
			if (StoY(mpao2) == StoY(mk)) {
				if (StoX(mk) >= 0x4 && StoX(mpao2) < StoX(mk)) {
					RETRUN_MUL(4);
				}
				if (StoX(mk) <= 0x4 && StoX(mpao2) > StoX(mk)) {
					RETRUN_MUL(4);
				}
			}
		}
		if (StoY(mpao2) == MY_RANK9) {
			if (StoY(mpao1) == StoY(mk)) {
				if (StoX(mk) >= 0x4 && StoX(mpao1) < StoX(mk)) {
					RETRUN_MUL(4);
				}
				if (StoX(mk) <= 0x4 && StoX(mpao1) > StoX(mk)) {
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 4k4/3ca4/3cb4/5R3/9/6B2/9/4B4/4A4/4K4 w - - 0 0
	if((my_shi_num + my_xiang_num) >= 2 && StoY(mk) == MY_RANK9){
		if(StoY(mpao1) MY_LARGE_EQL  MY_RANK7 && StoY(mpao2) MY_LARGE_EQL MY_RANK7){
			RETRUN_MUL(4);
		}		
		RETRUN_MUL(8);
	}
}



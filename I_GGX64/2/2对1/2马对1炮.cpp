#ifndef END_my_m_MT_R_2ma_B_1pao
#define END_my_m_MT_R_2ma_B_1pao
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2马对1炮.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



// fen 3k5/4a4/9/5n3/9/6B2/4C4/4K4/4A2n1/6B2 w - - 131 131 
void my_m_MT_R_2ma_B_1pao(typePOS &POSITION, EvalInfo &ei){

	Square yk   = your_king_pos;
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);

	// fen 3k5/7N1/c2a1a3/5N3/9/2B6/9/9/3KA4/9 b - - 0 1
	if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(ypao) == MY_RANK2){
			MY_EV_SUB(64);
		}
	}

	if(your_xiang_num == 2 && your_shi_num >= 1){
		if(StoY(yk) == MY_RANK0){
		  RETRUN_MUL(3);
		}
		RETRUN_MUL(4);
	}

	// fen 4k4/4a4/5a1N1/5N3/5c3/2B6/9/9/3K5/3A1A3 w - - 0 1
	if(StoY(yk) == MY_RANK0){
		if(your_shi_num == 2){
			RETRUN_MUL(4);
		}
	}
	// fen 4k4/9/5a3/9/2b6/9/3n5/5n2B/5C3/5KB2 w - - 0 0
	if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		Square x1 = S90_from_piecelist(POSITION,your_xiang,0);
		Square x2 = S90_from_piecelist(POSITION,your_xiang,1);
		Bitboard xatt = POSITION.xiang_attacks_bb(x1);
		if(bit_is_set(xatt,x2)){
			RETRUN_MUL(4);
		}
	}

	// fen 4k4/4a4/4ba3/5N3/4cN3/9/9/3AB3B/4A4/5K3 w - - 0 0
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(PB90(MY_SQ15) == your_shi || PB90(MY_SQ17) == your_shi){
			if(StoY(ypao) MY_SMALL_EQL MY_RANK4){
				RETRUN_MUL(4);
			}
			RETRUN_MUL(8);
		}
	}
	if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		RETRUN_MUL(8);
	}
}



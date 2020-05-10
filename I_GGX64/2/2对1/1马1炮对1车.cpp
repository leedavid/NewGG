#ifndef END_my_m_MT_R_1pao1ma_B_1che
#define END_my_m_MT_R_1pao1ma_B_1che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马1炮对1车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

// fen 9/3k5/3c5/4R4/9/2n6/9/9/9/3K5 w

//const int MaPao2ShiAdd = 16;

//马炮对车
void my_m_MT_R_1pao1ma_B_1che(typePOS &POSITION, EvalInfo &ei){

	Square mk   = my_king_pos;
	Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	Square mma  = S90_from_piecelist(POSITION,my_ma,0);

	Square yche = S90_from_piecelist(POSITION,your_che,0);

	//
	if(my_shi_num == 2 || my_xiang_num == 2){
		MY_EV_ADD(64);
		RETRUN_MUL(2);
	}

	// fen 4ka3/4a4/9/9/2b3b2/9/9/9/4A1r2/1C2K1N2 b - - 0 0
	if(mk == MY_SQ55 && PB90(MY_SQ4C) == my_shi){
		if(IsOnSameSide(mma,mpao) == FALSE){
			if(PB90(MY_SQ53) == my_ma || PB90(MY_SQ57) == my_ma){
				
				Bitboard peat = POSITION.Pao_Eat_bb(mpao);
				if(StoY(mpao) == MY_RANK9 && bit_is_set(peat,mma)){
					RETRUN_MUL(2);
				}
			}
		}
	}

	//则马炮方要求和了, 
	//马炮要想守和一车,要二点;
	//1,炮在将后, 以免车在当头照将,再用马做应着,这是最好的一种和局的形势
	//2,炮在将前, 随时紧帖互保, 马切不可跳得太远,
	if(StoX(mpao) == StoX(mk) && (your_shi_num + your_xiang_num) == 0){
		//
		if(StoY(mpao) MY_LARGE StoY(mk)){
			if(abs(StoX(mma) - StoX(mk)) < 3){
				RETRUN_MUL(2);
			}
		}

		if(StoY(mk) == MY_RANK8 && StoY(mpao) == MY_RANK7){
			if(abs(StoX(mma) - StoX(mk)) < 3){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 4kc3/4a4/3n5/9/9/9/9/6R1B/9/2BAK4 w - - 0 1
	if(my_shi_num >= 1 && MY_SQ55 == mk && PB90(MY_SQ4C) == my_shi && StoY(mpao) == MY_RANK9){
		if(StoX(mpao) < 0x4 && bit_is_set(ei.attacked_by(my_ma),Square(MY_SQ57))){
			RETRUN_MUL(4);
		}
		if(StoX(mpao) > 0x4 && bit_is_set(ei.attacked_by(my_ma),Square(MY_SQ53))){
			RETRUN_MUL(4);
		}
	}

	// fen 2n1kc3/4a1R2/9/9/9/9/9/9/9/2BAK1B2 b - - 0 1
	if(my_shi_num >= 1 && MY_SQ55 == mk && PB90(MY_SQ4C) == my_shi){
		if(PB90(MY_SQ53) == my_ma && StoX(mpao) > 0x4 && StoX(yche) > 0x4){
			RETRUN_MUL(4);
		}
		if(PB90(MY_SQ57) == my_ma && StoX(mpao) < 0x4 && StoX(yche) < 0x4){
			RETRUN_MUL(4);
		}
	}

	// fen 3ak4/9/b2a5/9/2b6/9/r8/4N4/4A4/2B1KC3 w - - 0 1
	if(my_shi_num >= 1 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9){
		if(StoY(mpao) == MY_RANK9 && PB90(MY_SQ43) == my_ma){
			if(StoX(mpao) < 0x4 && have_bit(bb_my_xiang,RightBB[0x4])){
				RETRUN_MUL(4);
			}
			if(StoX(mpao) > 0x4 && have_bit(bb_my_xiang,LeftBB[0x4])){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4k4/9/5a3/9/9/9/9/4C4/4A1r2/4KN3 w - - 0 1
	if(my_shi_num >= 1 && MY_SQ55 == mk){
		if(MY_SQ54 == mma || MY_SQ56 == mma){
			if(StoY(mpao) MY_LARGE_EQL MY_RANK6){
				if(StoX(mma) < 0x4 && StoX(mpao) >= 0x4){
					RETRUN_MUL(8);
				}
				if(StoX(mma) > 0x4 && StoX(mpao) <= 0x4){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 3ak4/9/b2a5/9/2b6/9/r8/4N4/4A4/2B1KC3 w - - 0 1
	if((my_shi_num + my_xiang_num) >= 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		RETRUN_MUL(8);
	}
}



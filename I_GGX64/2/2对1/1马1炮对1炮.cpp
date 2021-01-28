#ifndef END_my_m_MT_R_1pao1ma_B_1pao
#define END_my_m_MT_R_1pao1ma_B_1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马1炮对1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//马炮对炮
void my_m_MT_R_1pao1ma_B_1pao(typePOS &POSITION, EvalInfo &ei){

	Square yk  = your_king_pos;
	Square mma  = S90_from_piecelist(POSITION,my_ma,0);
	Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);

	// fen 9/9/3k5/9/9/2B3B2/9/3nC4/3K4c/9 w - - 0 0
	//马不能动了,是和棋
	if(my_shi_num == 0){
		if(StoY(mma) MY_SMALL_EQL MY_RANK2 && (yk MY_ADD 9) == mma){
			if(isStringByChe(POSITION,my_king_pos,mma,yk)){
				RETRUN_MUL(2);
			}
		}
	}
	// fen 3aka3/4n4/4b1c2/9/2b1C4/9/9/9/4A4/3K5 b - - 0 0
	//被闷宫了,也可能是和棋
	if(my_king_pos == MY_SQ55 && mma == MY_SQ4C 
		&& PB90(MY_SQ54) == my_shi && PB90(MY_SQ56) == my_shi){
			if(isStringByPao(POSITION,ypao,mma,Square(MY_SQ55))){
				if((your_shi_num + your_xiang_num) >= 1){
					RETRUN_MUL(2);
				}
			}
	}

	if(StoY(ypao) MY_SMALL_EQL MY_RANK4){
		MY_EV_SUB(32);
	}

	// fen 3k1Cb2/5c3/4b4/8N/9/6B2/9/3A1A3/9/2B1K4 b - - 0 1
	if(your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(MY_SQ05 == mpao && MY_SQ0E == ypao && PB90(MY_SQ06) == your_xiang){
			RETRUN_MUL(2);
		}
		if(MY_SQ03 == mpao && MY_SQ0C== ypao && PB90(MY_SQ02) == your_xiang){
			RETRUN_MUL(2);
		}
	}

	// 对方仕相全
	if((your_shi_num + your_xiang_num) == 4){
		if(StoY(yk) == MY_RANK0){
			RETRUN_MUL(2);
		}
		RETRUN_MUL(4);
	}

	// fen 5kb2/9/8b/6cN1/9/2B6/9/4B4/4C4/4K4 b - - 130 130
	if(my_shi_num == 0 && your_xiang_num == 2){
		if(StoY(yk) MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(4);
		}
	}
	//if(your_xiang_num == 2 && StoY(yk) == MY_RANK1){
	//	MY_EV_SUB(96);
	//}



     // fen 9/3k5/3N5/9/9/2B6/9/1c1K5/4A4/3C5 w - - 0 1
	if(PB90(yk MY_ADD 0x9) == my_ma && StoY(mma) MY_SMALL_EQL MY_RANK2){
		if(StoY(ypao) MY_LARGE_EQL MY_RANK6){
		    if(StoX(yk) == 0x3 && StoX(ypao) <= 0x2){
				RETRUN_MUL(4);
			}
			if(StoX(yk) == 0x5 && StoX(ypao) >= 0x6){
				RETRUN_MUL(4);
			}

			// fen 4k4/4N4/8b/9/9/9/9/9/C3K4/3A2c2 w - - 0 1
			if(my_shi_num <= 1 && my_xiang_num == 0){
				if(StoY(ypao) == MY_RANK9){
					RETRUN_MUL(4);
				}
			}
		}
		RETRUN_MUL(8);
	}

	// fen 2ba1k3/4a4/4b4/9/9/9/9/3nB4/4C4/3K1cB2 r
	if(your_xiang_num == 2 && StoY(yk) == MY_RANK0){

		MY_EV_SUB(96);

		if(my_shi_num == 0){
			MY_EV_SUB(168);
		}

		if(abs(StoX(mpao) - 0x4) <= 1 && StoY(mpao) == MY_RANK0){
			RETRUN_MUL(8);
		}
		// fen 4k4/2Nc5/4b3b/9/9/3C5/9/3AB4/4A4/5K3 w - - 0 1
		if(StoY(ypao) == MY_RANK1){
			RETRUN_MUL(8);
		}
	}


	// fen 9/4a4/3k5/5c3/9/9/9/B3B4/5Cn2/4K4 w - - 0 1
	if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK0){
		if(StoY(ypao) MY_SMALL_EQL MY_RANK2 && my_shi_num <= 1 && my_xiang_num == 0){
			RETRUN_MUL(8);
		}
	}





}



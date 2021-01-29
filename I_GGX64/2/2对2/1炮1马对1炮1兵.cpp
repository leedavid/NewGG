#ifndef END_my_m_MT_R_1pao1ma_B_1pao1pawn
#define END_my_m_MT_R_1pao1ma_B_1pao1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮1马对1炮1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//1炮1马对1炮1兵
void my_m_MT_R_1pao1ma_B_1pao1pawn(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	int ycan  = EV_YOUR_CAN;
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);
	Square mma  = S90_from_piecelist(POSITION,my_ma,0);

	if(your_shi_num == 0){
		MY_EV_ADD(128);
	}

	if(StoY(ypawn) MY_SMALL MY_RANK8){
		MY_EV_SUB(32);
	}

	// fen 4ka3/2c6/3a5/9/9/4N4/9/C3p4/9/4K4 w - - 0 1
	if (your_xiang_num == 0){
		MY_EV_ADD(64);
	}

	// fen 5a3/3k5/b3ba3/7P1/9/6B2/9/9/1n1C5/2BcK4 w - - 136 136
	// 困死对方一个炮
	if(your_xiang_num >= 1 && ycan != 0){
		if(MY_SQ04 == your_king_pos){
			if(PB90(MY_SQ03) == my_pao && PB90(MY_SQ02) == your_xiang
				&& PB90(MY_SQ0C) == your_pao){
					RETRUN_MUL(2);
			}
			if(PB90(MY_SQ05) == my_pao && PB90(MY_SQ06) == your_xiang
				&& PB90(MY_SQ0E) == your_pao){
					RETRUN_MUL(2);
			}
		}
	}
	if((your_shi_num + your_xiang_num) == 4){
		if(StoY(yk) == MY_RANK0){
			RETRUN_MUL(2);
		}
	}
    // fen 2ba1k3/9/5C3/3N5/6b2/2B6/9/1c7/5p3/3K5 b - - 0 0
	//要吃对方的仕相
	if((your_shi_num + your_xiang_num)  <= 3 && (my_shi_num + my_xiang_num) >= 1){
		MY_EV_ADD(128);
	}

	// fen 5kb2/3c5/4b4/7N1/9/2B6/9/5C3/3K5/5p3 w - - 0 1
	if(my_shi_num == 0 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(ypawn) MY_LARGE_EQL MY_RANK5){
			RETRUN_MUL(4);
		}
	}


	// fen C2k5/3N5/5a2c/9/8p/4p4/8P/4BA3/9/3K1AB2 w - - 0 1
	if(StoY(ypawn) == MY_RANK6 && your_shi_num >= 1){
		if(bit_is_set(EV_YOUR_XBIT,mma) && bit_is_set(ei.attacked_by(your_king),mma)){
			RETRUN_MUL(4);
		}
	}

	// fen 9/4k4/3aCa3/2N1c4/9/9/1p7/9/4A4/2B2K3 b - - 0 1
	if(EV_YOUR_CAN >= 1){
		if(PB90(MY_SQ16) == my_pao && PB90(MY_SQ15) == your_shi && PB90(MY_SQ17) == your_shi){
			if(PB90(MY_SQ1F) == your_pao && StoX(yk) == 0x4){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3ak4/4c4/6N2/9/p1b3b2/6B1C/9/9/9/3K5 b - - 0 1
	if(my_shi_num == 0){
		if(your_xiang_num == 2){
			MY_EV_SUB(80);
			if(your_shi_num >= 1){
			   RETRUN_MUL(4);
			}
			RETRUN_MUL(8);
		}
	}

	// fen 2b2a3/3ka4/b8/3N5/3c4p/9/9/5A2B/2C1A4/4K4 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		MY_EV_SUB(EV_YOUR_CAN * 64);
		if(StoY(ypao) MY_SMALL_EQL MY_RANK4){
			RETRUN_MUL(8);
		}
	}

}


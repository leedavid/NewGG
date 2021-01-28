#ifndef END_my_m_MT_R_1pao1ma_B_1ma
#define END_my_m_MT_R_1pao1ma_B_1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马1炮对1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//1, 我方的马要过河
//const int MaPaoXPawn_Vs_Ma_PaoMao_Over_River =  96;
//const int PaoMao_Over_River =  96;
//const int PaoAtHome         =  32;
//const int GaoXiang          =  16;
//const int GaoShi            =  16;
//const int OtherXiangQuan    =

//马炮对马 //总能胜, 一定要加分
void my_m_MT_R_1pao1ma_B_1ma(typePOS &POSITION, EvalInfo &ei){

	Square yk   = your_king_pos;
	Square mma  = S90_from_piecelist(POSITION,my_ma,0);
	Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	Square yma  = S90_from_piecelist(POSITION,your_ma,0);

	if((my_shi_num + my_xiang_num) == 0){
		if((your_shi_num + your_xiang_num) == 4){
			if(StoY(yk) == MY_RANK0){
				RETRUN_MUL(2);
			}
		}
	}

	MY_EV_ADD(96);
	//1, 我方的马要过河
	if(StoY(mma) MY_SMALL MY_RANK5){
		MY_EV_ADD(64);
	}
	//2, 炮要回家
	if(StoY(mpao) MY_LARGE MY_RANK5){
		MY_EV_ADD(32);
	}
	//3, 相要飞起
	//4,高仕
	if(PB90(MY_SQ42) == my_shi || PB90(MY_SQ44) == my_shi){
		MY_EV_ADD(32);
	}

	if((your_shi_num + your_xiang_num) >= 3){
         MY_EV_SUB(80);
	}

	//马炮难胜马双象
	// fen 5kb2/9/8b/5N3/9/2B6/9/4B1Cn1/9/3K5 w - - 89 89
	if(my_shi_num == 0 && your_xiang_num == 2){
		if(StoY(yk) MY_SMALL MY_RANK2 && StoY(yma) MY_SMALL_EQL MY_RANK4){
			RETRUN_MUL(2);
		}
	}

	// fen 5k3/5N3/8b/9/9/9/6n2/5KC2/9/9 b - - 0 1
	if(my_shi_num == 0 && my_xiang_num == 0){
		if(your_shi_num >= 1 || your_xiang_num >= 1){
			if(StoY(yk) MY_SMALL_EQL MY_RANK1){
				if(mma == yk MY_ADD 0x9){
					RETRUN_MUL(2);
				}
			}
		}
	}

	//fen 6b2/3kN4/4b4/9/5n3/9/9/4CA3/4A4/2B1K1B2 b - - 0 1
	if (your_xiang_num == 2 && MY_SQ0D == mma && StoX(mpao) == 0x4){
		if (MY_SQ0C == yk || MY_SQ0E == yk){			
			if (!m_have_bit(_mm_andnot_si128(YOUR_ATTACK, ei.attacked_by(my_ma)))){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 9/4k4/4N4/9/9/C8/9/3A1A3/4K3n/9 b - - 0 1
	if(my_xiang_num == 0 && !bit_is_set(EV_MY_XBIT,yma) && StoX(yk) == 0x4){
		if(bit_is_set(ei.attacked_by(your_king),mma) && bit_is_set(EV_YOUR_XBIT,mma)){
			RETRUN_MUL(4);
		}
	}

	//马炮难胜马双象
	// fen 5kb2/9/8b/5N3/9/2B6/9/4B1Cn1/9/3K5 w - - 89 89
	if (my_shi_num == 0 && your_xiang_num == 2) {
		if (StoY(yk) MY_SMALL MY_RANK2) {
			RETRUN_MUL(4);
		}
	}

	// fen 3k5/9/9/6c2/9/6B2/6nN1/3ABK3/4A4/9 w - - 0 
	if (your_shi_num == 2 && your_xiang_num == 2) {
		if (my_shi_num == 0) {
			if (my_xiang_num == 0) {
				RETRUN_MUL(2);
			}
			RETRUN_MUL(4);
		}
	}



	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){

		// fen 2c6/4ak3/9/9/2b6/6B2/9/3A1N3/2n1A4/2B2K3 w - - 0 1
		if(PB90(MY_SQ15) == your_ma && PB90(MY_SQ17) == your_shi){
			RETRUN_MUL(4);
		}
		if(PB90(MY_SQ17) == your_ma && PB90(MY_SQ15) == your_shi){
			RETRUN_MUL(4);
		}

		if(StoY(yk) == MY_RANK0){
			if(abs(StoY(yma) - MY_RANK4) <= 2){
				RETRUN_MUL(4);
			}
		}

		RETRUN_MUL(6);
	}
	// fen 3k1a3/9/5a3/9/1nN6/3C5/9/9/9/2B1K4 w - - 0 1
	if(my_shi_num == 0 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(your_shi_num == 2 || your_xiang_num == 2){
			RETRUN_MUL(8);
		}
	}

	// fen 2b1k1b2/9/9/4N1n2/9/2B3B2/9/5A3/3K5/2C6 w - - 0 1  这个要吃相
	if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		RETRUN_MUL(12);
	}

}


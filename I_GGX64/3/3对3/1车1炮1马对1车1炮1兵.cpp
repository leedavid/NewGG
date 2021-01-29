#ifndef END_my_m_MT_R_1che1pao1ma_B_1che1pao1pawn
#define END_my_m_MT_R_1che1pao1ma_B_1che1pao1pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车1炮1马对1车1炮1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int  AD_Che_CanNotMove = 256;

void my_m_MT_R_1che1pao1ma_B_1che1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mk    = my_king_pos;
	Square yk    = your_king_pos;
	Square mma   = S90_from_piecelist(POSITION,my_ma,0);
	Square yche  = S90_from_piecelist(POSITION,your_che,0);
	//Square mpao  = S90_from_piecelist(POSITION,my_pao,0);
	//Square mche  = S90_from_piecelist(POSITION,my_che,0);
	//Square ypao  = S90_from_piecelist(POSITION,your_pao,0);

	// fen 2b1kc3/4a4/n8/R8/9/2N3P2/8r/4B4/4A4/3AK1B2 w - - 0 1
	if((my_shi_num + my_xiang_num) >= 2){
		MY_EV_ADD(32);
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK7 && StoY(mk) == MY_RANK9){
			MY_EV_ADD(32);
		}
	}

	if(StoY(mma) MY_SMALL_EQL MY_RANK5){
		MY_EV_ADD(32);
	}

	// fen 3akab2/9/4b4/7R1/1c6N/1C7/p5r2/9/4A4/3AK4 b - - 0 1
	if(StoY(ypawn) MY_SMALL_EQL MY_RANK6){
		MY_EV_ADD(64);
	}
	if(abs(StoX(ypawn) - 0x4) >= 3){
		MY_EV_ADD(32);
	}

	// fen C2k1ab2/4a3N/b8/6r1p/6c2/2R6/9/4B4/4A4/3AK4 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		MY_EV_SUB(32);
		if(abs(StoX(mma) - 0x4) == 4 && !IsOnSameSide(mma,yk)){
			MY_EV_SUB(32);
		}
	}

	// fen 3k1ab2/2cCa4/1r2b4/1N1R5/9/8p/9/B3BA3/4A4/4K4 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(MY_SQ03 == yk && PB90(MY_SQ0C) == my_pao && PB90(MY_SQ0B) == your_pao){
			if(PB90(MY_SQ1C) == my_ma && PB90(MY_SQ1E) == my_che && PB90(MY_SQ13) == your_che){
				RETRUN_MUL(4);
			}
		}
		if(MY_SQ05 == yk && PB90(MY_SQ0E) == my_pao && PB90(MY_SQ0F) == your_pao){
			if(PB90(MY_SQ22) == my_ma && PB90(MY_SQ20) == my_che && PB90(MY_SQ19) == your_che){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4k4/9/9/9/9/1p3C3/2R1cr3/B3N4/4A4/3AK1B2 w - - 0 1
	if(PB90(MY_SQ3A) == your_pao && PB90(MY_SQ43) == my_ma){
		if(my_shi_num == 2 && PB90(MY_SQ4C) == my_shi && MY_SQ55 == mk){
			if(EV_YOUR_CAN >= 1 && !IsOnSameSide(yche,ypawn)
				&& StoY(yche) == MY_RANK6 && abs(StoX(ypawn) - 0x4) >= 3){
					MY_EV_SUB(64);

					if(PB90(MY_SQ54) == my_shi && StoX(yche) >= 0x5){
						MY_EV_SUB(64);
						RETRUN_MUL(4);
					}
					if(PB90(MY_SQ56) == my_shi && StoX(yche) <= 0x3){
						MY_EV_SUB(64);
						RETRUN_MUL(4);
					}					
			}
		}
	}

	// fen Nrba1k3/4a2c1/4b4/R3p4/9/9/9/4BA3/C3A4/4K4 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if((MY_SQ00 == mma && PB90(MY_SQ01) == your_che)
			||(MY_SQ08 == mma && PB90(MY_SQ07) == your_che)){
			MY_EV_SUB(96);
			if((my_shi_num + my_xiang_num) >= 2 && StoY(ypawn) MY_SMALL_EQL MY_RANK6){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 2c1k4/4a4/4ba3/9/2b6/3R3N1/6r2/4K1C2/4A1p2/5A3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mk) == MY_RANK7 && StoY(ypawn) MY_LARGE_EQL MY_RANK5){
			MY_EV_SUB(EV_YOUR_CAN * 32);
			if(abs(StoX(mk) - StoX(ypawn)) <= 2){
				MY_EV_SUB(16);
			}
		}
	}

	// fen C2k1ab2/4a3N/b8/6r1p/6c2/2R6/9/4B4/4A4/3AK4 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(abs(StoX(mma) - 0x4) == 4 && !IsOnSameSide(mma,yk)){
			if(StoY(yche) == MY_RANK3 && IsOnSameSide(yche,mma)){
				RETRUN_MUL(8);
			}
		}
	}
}


#ifndef END_my_m_MT_R_1CHE_B_1PAO
#define END_my_m_MT_R_1CHE_B_1PAO
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "1车对1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 
//红方一个车，黑方一个炮
void my_m_MT_R_1CHE_B_1PAO(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	Square ypao = S90_from_piecelist(POSITION, your_pao, 0);
	Square mche = S90_from_piecelist(POSITION, my_che, 0);

	if (your_shi_num == 2 || your_xiang_num == 2){
		MY_EV_SUB(128);
	}

	// 1车难胜炮双象
	if(StoY(yk) MY_SMALL MY_RANK2 && StoY(ypao) MY_SMALL_EQL MY_RANK6){
		if(your_xiang_num == 2){
			if(your_shi_num == 2){
				RETRUN_MUL(2);
			}
			if(StoY(yk) == MY_RANK0){
				if(StoY(ypao) MY_SMALL MY_RANK5){
					RETRUN_MUL(2);
				}
			}
			RETRUN_MUL(2);
		}
	}
	// 1车难胜炮双仕
	if(your_shi_num == 2){
		if(StoX(ypao) == StoX(yk)){
			RETRUN_MUL(2);
		}
	}

	// fen 3a1k3/9/9/9/2b6/9/9/B2KBr3/9/3C5 b - - 0 1
	if(your_xiang_num == 2){
		if(StoY(ypao) MY_SMALL StoY(yk) && StoX(yk) != 0x4){
			if(StoX(ypao) == StoX(yk)){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 9/3ka4/3a5/3R5/9/9/2c6/5A3/3KA4/9 w - - 0 1
	if (your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1 && PB90(MY_SQ0D) == your_shi){
		if (StoY(ypao) MY_LARGE MY_RANK2 && StoY(ypao) MY_SMALL MY_RANK7){
			if (StoX(mche) == 0x3 && PB90(MY_SQ15) == your_shi){
				RETRUN_MUL(2);
			}
			if (StoX(mche) == 0x5 && PB90(MY_SQ17) == your_shi){
				RETRUN_MUL(2);
			}
		}
	}

   // fen 1R1ck4/4a4/4ba3/9/9/2B6/9/3A5/9/2BAK4 w - - 0 1
	if (your_shi_num == 2 && StoY(yk) == MY_RANK0) {
		if (StoY(ypao) == MY_RANK0 && abs(StoX(ypao) - 0x4) <= 1) {
			RETRUN_MUL(2);
		}
	}


	if (your_shi_num == 2){
		RETRUN_MUL(4);
	}
}
// 3k1a3/9/3cb4/9/3R2b2/6B2/9/8B/9/3AKA3 w - - 0 0

#ifndef END_my_m_MT_R_1PAO1ma_B_NO
#define END_my_m_MT_R_1PAO1ma_B_NO
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1炮1马对无.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//const int _PaoPawn_To_No_Canwin = 128;  //胜棋分

//应该是我方一点一点好，对方一点一点差来判断

//我方一炮一兵，对方 0 attacker
void my_m_MT_R_1PAO1ma_B_NO(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;

	Square mma = S90_from_piecelist(POSITION,my_ma,0);

	// fen 6c2/9/3kb4/9/9/2B6/9/5A3/3nA4/3K5 w - - 0 1
	if((your_shi_num + your_xiang_num) >= 2){
		if(my_shi_num == 0){
			if(MY_SQ05 == yk && PB90(MY_SQ0E) == my_ma && PB90(MY_SQ17) != your_shi){
				RETRUN_MUL(2);
			}
			if(MY_SQ03 == yk && PB90(MY_SQ0C) == my_ma && PB90(MY_SQ15) != your_shi){
				RETRUN_MUL(2);
			}
			// fen 9/3k5/b2Nb4/9/9/9/9/3K5/9/3C5 b - - 0 1
			if(MY_SQ0C == yk && PB90(MY_SQ15) == my_ma){
				RETRUN_MUL(2);
			}
			if(MY_SQ0E == yk && PB90(MY_SQ17) == my_ma){
				RETRUN_MUL(2);
			}
		}
	}

	// fen C1bak4/4N4/9/9/2b6/9/9/3AK4/9/2B2A3 w - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2 && MY_SQ04 == yk){
		if(MY_SQ0D == mma && bit_is_set(EV_YOUR_XBIT,mma)){
			RETRUN_MUL(2);
		} 
	}
}


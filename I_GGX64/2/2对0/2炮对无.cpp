#ifndef END_my_m_MT_R_2pao_B_NO
#define END_my_m_MT_R_2pao_B_NO
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮对无.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_2pao_B_NO(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// fen 2bak4/4a4/4b4/9/9/2B6/1C7/9/4K3C/9 b
	if(my_shi_num == 0 && my_xiang_num == 0){
		// fen 2b2k3/9/4b4/9/9/3C5/9/4K4/4C4/9 w
		// 双炮例和双象
		// 双象连环,掩护中营,双炮无法取胜
		if(your_xiang_num == 2 && PB90(MY_SQ16) == your_xiang){
			RETRUN_MUL(1);
		}
	}



	// fen 2bk5/9/2c6/9/9/9/9/B8/3c5/2B1K4 w - - 198 198
	if(my_shi_num == 0 && my_xiang_num <= 1){

		//if(my_shi_num == 0){
			MY_EV_SUB(128);
		//}

        // fen 4k1b2/9/9/3C5/2b6/9/9/7C1/5K3/9 b - - 0 1
		if(my_xiang_num == 0){
			if(your_xiang_num == 2){
				MY_EV_SUB(168);
			}
		}

		if(your_xiang_num == 2){
			if(StoX(your_king_pos) == 0x4){
				MY_EV_SUB(256);
			}
			RETRUN_MUL(2);
		}
	}

	//// fen 6c2/9/3kb4/9/9/2B6/9/5A3/3nA4/3K5 w - - 0 1
 //   if((your_shi_num + your_xiang_num) >= 2){
	//	if(my_shi_num == 0){
	//		if(MY_SQ05 == yk && PB90(MY_SQ0E) == my_ma && PB90(MY_SQ17) != your_shi){
	//			RETRUN_MUL(2);
	//		}
	//		if(MY_SQ03 == yk && PB90(MY_SQ0C) == my_ma && PB90(MY_SQ15) != your_shi){
	//			RETRUN_MUL(2);
	//		}
	//	}
	//}

	// 
	if(your_shi_num == 2 && your_xiang_num == 2 
		&& StoY(yk) MY_SMALL_EQL MY_RANK1){
        if(my_shi_num == 0){
			Bitboard sup = POSITION.Pao_Super_bb(your_king_pos);
			if(m_have_bit(m_and(sup,bb_my_pao)) == FALSE){
				RETRUN_MUL(4);
			}
			RETRUN_MUL(8);
		}
	}
}


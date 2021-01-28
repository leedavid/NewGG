#ifndef END_my_m_MT_R_2pao_B_1ma1pawn
#define END_my_m_MT_R_2pao_B_1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2炮对1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 




void my_m_MT_R_2pao_B_1ma1pawn(typePOS &POSITION, EvalInfo &ei){
	
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square yma   = S90_from_piecelist(POSITION,your_ma,0);
	Square mk    = my_king_pos;
	Square yk    = your_king_pos;

	if(StoY(ypawn) MY_SMALL StoY(mk)){
		MY_EV_SUB(ADD_1PaoXPawn_2Pao_ByPawnShi[my_shi_num]);
	}

	// fen 4k4/3Pa4/4ba3/6N2/6b2/2B6/9/Bc1A5/4A4/1c3K3 b - - 213 213
    //马方有仕相全的话, 炮方难胜
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) != MY_RANK2){
		EV_YOUR_SAFE = TRUE;
	}

	if(StoY(mk) MY_SMALL_EQL StoY(ypawn)){
		EV_MY_SAFE = TRUE;
	}
	if(my_shi_num >= 1){
		EV_MY_SAFE = TRUE;
	}


	// fen 3k5/4a4/5a3/9/2b6/6B2/4p4/4BA1n1/C3A4/4KC3 w - - 121 121
	//炮对马兵单缺相
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) != MY_RANK2){
		if(StoY(ypawn) == MY_RANK6){
			if(EV_MY_SAFE){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 4c4/3k3c1/5a3/4P4/2bN5/9/9/4B4/9/4K1B2 w - - 121 121
	if(your_xiang_num == 2 && StoY(yk) != MY_RANK2){
		if(StoY(my_shi_num) <= 1){
			if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3k5/4ac3/4ba3/3P5/6b2/2N6/2c6/5A3/4A4/4K4 b - - 0 0
	if((your_shi_num == 2 || your_xiang_num == 2) && StoY(yk) MY_SMALL_EQL MY_RANK1){
		MY_EV_SUB(128);
		if(StoY(ypawn) == MY_RANK6){
			if(abs(StoY(yma) - MY_RANK4) <= 2){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3k1ab1C/9/9/9/2C5p/4n4/9/3AB4/9/4K4 w - - 0 1	
	if(my_shi_num <= 1 && EV_YOUR_CAN >= 1 && StoY(ypawn) MY_SMALL_EQL MY_RANK6){
		if((your_shi_num + your_xiang_num) >= 2){
			RETRUN_MUL(8);
		}
	}
	// fen 4k3C/9/4b4/9/9/8p/9/4B4/1n2KC3/9 b - - 0 1
	if(my_shi_num == 0 && EV_YOUR_CAN >= 1 && StoY(ypawn) MY_SMALL_EQL MY_RANK6){
		if((your_shi_num + your_xiang_num) >= 1){
			RETRUN_MUL(8);
		}
	}

	
}


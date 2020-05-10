#ifndef END_my_m_MT_R_2ma_B_1ma
#define END_my_m_MT_R_2ma_B_1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2马对1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_2ma_B_1ma(typePOS &POSITION, EvalInfo &ei){

	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	Square yk  = your_king_pos;


	if(your_shi_num == 2 || your_xiang_num == 2){
		if(StoY(yk) MY_SMALL_EQL MY_RANK1){
			MY_EV_SUB(64);
		}
	}

	// fen 2ba1k3/4a1N2/4b4/6N2/9/9/8n/4B4/4A4/2BAK4 w - - 0 0
	if(my_shi_num >= 1 && my_xiang_num == 2){
		if(StoY(yma) MY_LARGE_EQL MY_RANK6){
			if(PB90(yma MY_SUB 0x9) == my_ma){
				MY_EV_ADD(128);
			}
		}
	}
	// fen 6b2/4Nk3/4b4/4nN3/9/6B2/9/3AB4/9/3K1A3 b - - 16 16
	// 一个马给困住了,不能动了,也是和棋
	if(your_xiang_num == 2){
		if(PB90(MY_SQ0D) == my_ma){
			if(PB90(MY_SQ16) == your_xiang && MY_SQ1F == yma){
				if(StoY(yk) MY_SMALL_EQL MY_RANK1){
					RETRUN_MUL(2);
				}
			}
		}
	}   

	//双马难胜双相单仁
	// fen 9/3ka4/5a3/3N5/6b2/9/3n5/4BAn1B/5K3/9 w - - 66 66
	if(StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(your_xiang_num == 2 && your_shi_num >= 1){
			if(StoY(yma) MY_SMALL_EQL MY_RANK6){
				RETRUN_MUL(2);
			}
			RETRUN_MUL(4);
		}
	}

	// fen 9/4ak3/5a2b/3N5/4N4/7n1/9/9/5K3/2B6 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(yma) MY_SMALL_EQL MY_RANK4){
			RETRUN_MUL(4);
		}
	}

	// fen 9/4ak3/2Nn1a2N/9/9/2B6/9/3A4B/9/3A1K3 b - - 0 1
	if(StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(your_shi_num == 2 && have_bit(bb_your_shi,RankBB_A[MY_RANK2])){
			if(StoY(yma) MY_SMALL_EQL MY_RANK4){
				RETRUN_MUL(4);
			}
		}
	}

	if(StoY(yk) MY_SMALL_EQL MY_RANK1){
		// fen 9/4ak1N1/4ba3/4N4/9/9/6n2/9/9/5KB2 b - - 0 1 not he
		if(your_xiang_num >= 1 && your_shi_num == 2){
			if(StoY(yma) MY_SMALL_EQL MY_RANK4){
				RETRUN_MUL(4);
			}
			RETRUN_MUL(8);
		}
	}

	// fen 5a3/3k5/5a3/9/9/4n1B2/9/4B1n2/6N2/4K4 w - - 0 1
	if(your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(yma) MY_SMALL_EQL MY_RANK5){
			MY_EV_SUB(196);
		}
	}

	// fen 3a1k3/9/3a5/3N5/n8/3N5/9/5A2B/9/3A1K3 w - - 0 1
	if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		RETRUN_MUL(8);
	}



}



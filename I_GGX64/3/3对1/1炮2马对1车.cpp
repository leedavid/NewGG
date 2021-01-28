#ifndef END_my_m_MT_R_1pao_2ma_B_1che
#define END_my_m_MT_R_1pao_2ma_B_1che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮2马对1车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//1炮2马对1车, 炮马方要加分

void my_m_MT_R_1pao_2ma_B_1che(typePOS &POSITION, EvalInfo &ei){

	//ei.evScore += Add_1炮2马对1车;
	MY_EV_ADD(Add_1炮2马对1车);

	Square mk = my_king_pos;
	Square yk = your_king_pos;

	// fen 4k1b2/4a4/4ba3/1r7/9/4N4/9/2CN1A3/4A4/4K4 b - - 0 1
	if((my_shi_num + my_xiang_num) >= 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		EV_MY_SAFE = TRUE;
	}
	// fen 5k3/4a4/8b/5N3/2bN1r3/5C3/9/B3B4/9/4K4 w - - 0 1
	if(count_1s(ei.attacked_by(your_che),bb_my_ma) == 2){
		MY_EV_SUB(128);
	}
	if((my_shi_num + my_xiang_num) <= 2){
		MY_EV_SUB(96);
	}
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		MY_EV_SUB(64);
	}

	// fen 4k4/4a4/5a3/7r1/2b1N1b2/6N2/5C3/4B4/4A4/2BK1A3 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2){
			if(StoY(yk) == MY_RANK0){
			   RETRUN_MUL(4);
			}
			if(StoY(yk) MY_SMALL_EQL MY_RANK1){
			  RETRUN_MUL(8);
			}
		}
	}

	// fen 4k1b2/4a4/4ba3/1r7/9/4N4/9/2CN1A3/4A4/4K4 b - - 0 1
	if(EV_MY_SAFE){
		if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
			if((my_shi_num + my_xiang_num) <= 2){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 5k3/4a4/8b/5N3/2bN1r3/5C3/9/B3B4/9/4K4 w - - 0 1	
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
		if(count_1s(ei.attacked_by(your_che),bb_my_ma) == 2){
			RETRUN_MUL(8);
		}
	}
	

}


//void m_MT_B_1pao_2ma_R_1che(typePOS &POSITION, EvalInfo &ei){
//
//	//ei.evScore -= Add_1炮2马对1车;
//}
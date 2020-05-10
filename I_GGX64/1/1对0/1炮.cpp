#ifndef Emy_m_MT_R_1PAO
#define Emy_m_MT_R_1PAO
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

//#define PaoAdd 16
//#define cons_炮仕例胜象 168
 
#include "1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif  

//const int PaoAdd = 16;
//const int cons_炮仕例胜象 = 168;


//红方一个炮
void my_m_MT_R_1PAO(typePOS &POSITION, EvalInfo &ei){
	
	Square yk = your_king_pos;


	// fen 4k4/9/9/9/9/9/4C4/3A1A3/9/2B1K4 w - - 0 1
	if(my_shi_num == 2){
		if(your_shi_num == 0 && your_xiang_num == 0){
			MY_EV_ADD(96);
		}
	}

	// fen 2b1k4/4a4/3a1c3/9/9/2B6/9/3A5/9/3K1A3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >=1 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(168);
	}

	// fen 4ka3/9/4ba3/9/9/6B2/9/3ABC3/4A4/3K5 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(have_bit(bb_your_shi,RankBB_A[MY_RANK2])){
			MY_EV_SUB(64);
		}
	}

	// 我方没有一个仕
	if(my_shi_num == 0){
		RETRUN_MUL(1);
	}

	// 对方有两个相
	if(your_xiang_num == 2){
		RETRUN_MUL(1);
	}

	if(your_xiang_num >= 1){ // 43局 炮仕相全和单仕象
		if(your_shi_num != 0){
			//if(your_shi_num == 1){
            //              if()
			//}
			// 要没有构成中炮
			// fen 4k4/4a4/4b4/9/9/9/4C4/3A5/4K4/9 w
			// fen 9/4ak3/4b4/9/9/9/4C4/3A5/4K4/9 w
			if(m_have_bit(m_and(POSITION.Pao_Super_bb(your_king_pos),
				bb_my_pao)) == FALSE){
					RETRUN_MUL(2);
			}			
		}
		if(your_shi_num == 2){
			ei.mul /= 2;
		}
	}
	
	if(your_shi_num >= 1 && your_xiang_num >= 1){
		if(StoY(yk) MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(2);
		}
	}

	//// 炮仕例胜象, 得加一些分	
	//MY_EV_ADD(168);

	if(your_shi_num == 0 && your_xiang_num <= 1 && my_shi_num != 0){
		MY_EV_ADD(128);
	}

	// fen 9/1P3k3/3ac4/9/9/9/9/5A3/9/3K1A3 w - - 0 1
	//if (your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
	//	RETRUN_MUL(8);
	//}
}


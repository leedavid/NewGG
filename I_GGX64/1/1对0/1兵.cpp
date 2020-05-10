#ifndef Emy_m_MT_R_1PAWN
#define Emy_m_MT_R_1PAWN
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

//#define PawnAddOk  64  // 有兵方的加分  
 
#include "1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif  
//引用书目 象棋残局基础

//const int PawnAddOk = 24;                //有兵方的加分

//红方一个兵
void my_m_MT_R_1PAWN(typePOS &POSITION, EvalInfo &ei){

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square yk = your_king_pos;

	// fen 5k3/9/3aPa3/9/9/9/9/9/9/4K4 w - - 0 1 
	if(your_xiang_num == 0 && your_shi_num <= 2){
		if(mpawn == MY_SQ16 && PB90(MY_SQ15) == your_shi && PB90(MY_SQ17) == your_shi){
			RETRUN_MUL(16);
		}
	}
	////////////////////////////////////////////////////////////////////////////////////////////
	// 对方有相
	// fen 3k2b2/9/4b4/5P3/9/9/9/9/9/4K4 w
	if(your_xiang_num == 2){
		RETRUN_MUL(1);
	}
	// fen 3k5/9/4b4/5P3/9/9/9/9/9/4K4 w
	if(your_xiang_num == 1){
		// <<象棋残局例典>> page 3 高兵例和象
		// 我方的兵吃不到对方的象。
		if(m_have_bit(m_and(my_pawn_k_attacks(mpawn),
			bb_your_xiang)) == FALSE){
            RETRUN_MUL(1);
		}
		if(your_shi_num >= 1){
			RETRUN_MUL(1);
		}
		// fen 3a5/3k5/4ba2b/9/9/9/9/3pB4/9/5K3 w - - 0 1
		if(StoX(yk) != 0x4){
			RETRUN_MUL(1);
		}
	}
	if(your_shi_num == 2){
        // <<象棋残局例典>> 一兵胜二仕
		RETRUN_MUL(1);
	}

	////////////////////////////////////////////////////////////////////////////////////////////
	// <<象棋殘局例典>>
	// 第1页 第1局 底兵例和单将 
	//兵到低了, 
	if(StoY(mpawn) == MY_RANK0){
		RETRUN_MUL(1);
	}

	MY_EV_ADD(64); // 多兵方加分

	// fen 9/3P5/3a1k3/9/9/2B6/9/3A1A3/9/5KB2 w - - 0 0
	if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
		if(IsOnSameSide(mpawn,yk) == FALSE){
			if(StoX(mpawn) < 0x4 && PB90(MY_SQ15) == your_shi){
				RETRUN_MUL(1);
			}
			if(StoX(mpawn) > 0x4 && PB90(MY_SQ17) == your_shi){
				RETRUN_MUL(1);
			}
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////
	//对方有一个仕的情况
	if(your_shi_num == 1){
		int yshi = S90_from_piecelist(POSITION,your_shi,0);		

		if(StoY(mpawn) MY_SMALL StoY(yk)){
			ei.evscore /= 16;
		}

		// fen 4ka3/9/9/4P4/9/9/9/9/4K4/9 w 
		// <<象棋残局例典>>，page 3 第9局  高兵例和仕
		//  只要不受牵制就行了。 不形成 将 仕 将
		if(StoX(my_king_pos) != StoX(your_king_pos)){
			RETRUN_MUL(1);
		}
		if(abs(StoY(mpawn) - StoY(yshi)) >= 2){
			RETRUN_MUL(1);
		}
	}

	// fen 3k5/4a4/6P2/9/9/2B6/9/3A5/9/3K5 w - - 0 1
    if(your_shi_num >= 1 && StoY(mpawn) MY_SMALL_EQL MY_RANK2){
		//
		if(StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi){
			if(StoX(mpawn) > 0x5){
				RETRUN_MUL(2);
			}
			if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
				if(StoX(mpawn) >= 0x4){
					RETRUN_MUL(2);
				}
			}
		}
		if(StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi){
			if(StoX(mpawn) < 0x3){
				RETRUN_MUL(2);
			}
			// fen 5a3/5P3/3k5/9/9/9/9/3AB4/9/3K5 b - - 0 1
			if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
				if(StoX(mpawn) <= 0x4){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 9/2P1a4/3k5/9/9/9/9/B2A5/3K5/2B6 w - - 0 1
	if (your_shi_num >= 1 && StoY(mpawn) MY_SMALL StoY(yk)){
		if (StoX(yk) == 0x3 && StoX(mpawn) < 0x3){
			RETRUN_MUL(2);
		}
		if (StoX(yk) == 0x5 && StoX(mpawn) > 0x5){
			RETRUN_MUL(2);
		}
	}


	// fen 3a5/5P3/3k5/9/9/9/9/3AB4/9/3K5 b - - 0 1
	if(your_shi_num >= 1 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
		if(StoY(yk) MY_LARGE_EQL MY_RANK1){
			if(StoX(yk) <= 0x4 && PB90(MY_SQ03) == your_shi && StoX(mpawn) > 0x4){
				RETRUN_MUL(4);
			}
			if(StoX(yk) >= 0x4 && PB90(MY_SQ05) == your_shi && StoX(mpawn) < 0x4){
				RETRUN_MUL(4);
			}
		}
	}

	// 必胜的棋
	// fen 9/4a4/4k4/9/6b2/9/9/3K5/6p2/9 b - - 0 0<
	if ((your_shi_num + your_xiang_num) == 0){
		if (StoY(mpawn) MY_LARGE_EQL MY_RANK1){
			MY_EV_ADD(128);
		}
	}
}


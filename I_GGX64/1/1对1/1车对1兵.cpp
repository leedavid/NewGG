#ifndef END_my_m_MT_R_1CHE_B_1PAWN
#define END_my_m_MT_R_1CHE_B_1PAWN
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "1车对1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//红方一个车，黑方一个兵
void my_m_MT_R_1CHE_B_1PAWN(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mche  = S90_from_piecelist(POSITION,my_che,0);
	my_m_MT_R_1CHE(POSITION,ei);

	if(ei.mul == 1){
		RETRUN_MUL(1);
	}
	
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(StoY(yk) == MY_RANK0){			
			// fen 2bk5/4a4/b1R2a3/9/9/2B6/9/3AK3B/4A4/1p7 b
			if(StoY(ypawn) MY_LARGE MY_RANK4){ // 兵已过河
				// R
				if(StoX(mche) > 0x4){
					if(PB90(MY_SQ06) == your_xiang && PB90(MY_SQ1A) == your_xiang){
						RETRUN_MUL(1);
					}
					// fen 7P1/4a4/b3ka3/9/6b2/9/9/3AB1r2/4A4/5KB2 r
					if(PB90(MY_SQ16) == your_xiang && PB90(MY_SQ06) == your_xiang){
						RETRUN_MUL(1);
					}
				}
				// L
				if(StoX(mche) < 0x4){
					if(PB90(MY_SQ02) == your_xiang && PB90(MY_SQ12) == your_xiang){
						RETRUN_MUL(1);
					}
					if(PB90(MY_SQ16) == your_xiang && PB90(MY_SQ02) == your_xiang){
						RETRUN_MUL(1);
					}
				}
			}
		}
	}
	// fen 2b1k4/4a4/b4a3/R8/9/9/9/B2AK3B/4A4/1p7 b - - 0 0

	// fen 3ak3P/9/3ab3b/9/9/2P6/9/4BA3/3KA4/1r4B2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2){
		if   ( (StoX(yk) == 0x3 && !have_bit(bb_your_shi,LeftBB[0x4]))
			|| (StoX(yk) == 0x5 && !have_bit(bb_your_shi,RightBB[0x4]))){
				if(StoY(mche) == MY_RANK0 && StoY(yk) MY_SMALL_EQL MY_RANK1){
					RETRUN_MUL(2);
				}
				if(StoY(yk) == MY_RANK0){
					RETRUN_MUL(2);
				}
		}
	}

}

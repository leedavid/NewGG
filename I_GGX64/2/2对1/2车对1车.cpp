#ifndef END_my_m_MT_R_2CHE_B_1CHE
#define END_my_m_MT_R_2CHE_B_1CHE
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2车对1车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//红方二个车，黑方一个车
void my_m_MT_R_2CHE_B_1CHE(typePOS &POSITION, EvalInfo &ei){

	Square yk   = your_king_pos;
	Square yche = S90_from_piecelist(POSITION,your_che,0);

	if((your_shi_num + your_xiang_num) == 4){
		if(PB90(MY_SQ16) == your_xiang){
			if(MY_SQ04 == yk){
				RETRUN_MUL(2);
			}

			if(MY_SQ03 == yk){
				if(PB90(MY_SQ02) == your_xiang){
					if(StoY(yche) == MY_RANK2 && StoX(yche) < 0x4){
						RETRUN_MUL(2);
					}
				}
			}

			if(MY_SQ05 == yk){
				if(PB90(MY_SQ06) == your_xiang){
					if(StoY(yche) == MY_RANK2 && StoX(yche) > 0x4){
						RETRUN_MUL(2);
					}
				}
			}
		}
		
		// fen 5a3/3k5/9/9/9/9/9/6R2/3rA4/2BA1KBr1 b - - 0 1
		if(StoY(yk) == MY_RANK0){
			if(StoY(yche) MY_SMALL_EQL MY_RANK4){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 5a3/3k5/9/9/9/9/9/6R2/3rA4/2BA1KBr1 b - - 0 1

}


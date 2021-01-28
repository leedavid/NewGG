#ifndef END_my_m_MT_R_1che1ma1pawn_B_2che
#define END_my_m_MT_R_1che1ma1pawn_B_2che
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1马1兵对2车.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//const int MAT_R_2che1pawn_B_1che1ma1pawn_MaSafe = 256;


void my_m_MT_R_1che1ma1pawn_B_2che(typePOS &POSITION, EvalInfo &ei){


	your_m_MT_R_2CHE_B_1CHE1MA(POSITION,ei);

	if(ei.mul <= 2){
		EV_MY_SAFE = TRUE;
	}
	Square mk = my_king_pos;
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	// fen 4kab2/4aR3/4R4/4n1r2/9/9/9/4B4/9/2BAKA3 w - - 0 0
	//红方二个车一个也不能动了,也是和棋

	// fen 4kab2/4aR3/4R4/4n1r2/9/9/9/4B4/9/2BAKA3 w - - 0 0
	if(my_xiang_num >= 1 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if(PB90(MY_SQ3A) == my_ma && PB90(MY_SQ43) == your_che){
			if(PB90(MY_SQ53) == my_xiang && PB90(MY_SQ4B) == your_che){
				RETRUN_MUL(2);
			}
			if(PB90(MY_SQ57) == my_xiang && PB90(MY_SQ4D) == your_che){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 2bk5/6R2/2r6/3NP4/2br5/9/9/9/4A4/3AK1B2 w - - 0 133
	if((my_shi_num + my_xiang_num) <= 3){
		MY_EV_SUB((4 - (my_shi_num + my_xiang_num)) * 64);

		if((your_shi_num + your_xiang_num) >= 2){
			MY_EV_SUB(64);
		}
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			MY_EV_SUB(64);
		}
	}



	// fen 3ak1b2/4a4/4b1n2/3Rp4/8r/5R3/9/4B4/4A4/4KAB2 w - - 0 0
	//一般性的和棋
	if((my_shi_num + my_xiang_num) == 4 && StoY(mk) == MY_RANK9){
		EV_MY_SAFE = TRUE;
	}

	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_CheMaPawn_2Che_MaSafe_ByPawn[your_shi_num]);
	

	// fen r1ba1k3/4a4/9/1R2PN3/2b2r3/9/9/4B4/9/2BAKA3 w - - 0 1
	if(EV_MY_SAFE){
		if((your_shi_num + your_xiang_num) >= 2){
			MY_EV_SUB(80);
			RETRUN_MUL(4);
		}
		if(your_xiang_num == 2){
			if(PB90(MY_SQ0C) != my_pawn){
				MY_EV_SUB(80);
				RETRUN_MUL(4);
			}
		}
	}

}


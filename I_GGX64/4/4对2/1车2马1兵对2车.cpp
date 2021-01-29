#ifndef END_my_m_MT_R_1che2ma1pawn_B_2che
#define END_my_m_MT_R_1che2ma1pawn_B_2che
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车2马1兵对2车.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1che2ma1pawn_B_2che(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		EV_MY_SAFE = TRUE;
		// fen 3akab2/9/9/8R/1r4b1N/9/P2r5/2N1B4/4A4/4KAB2 b - - 0 1
		if (mk == MY_SQ55){
			MY_EV_ADD(32);
		}
		MY_EV_ADD(32);
	}

	if(EV_MY_SAFE == FALSE){
		MY_EV_SUB(64);
	}

	// fen 3a5/1P2ak3/4b4/1N7/2b6/2Nr5/1R7/3AB4/4Ar3/3K2B2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		MY_EV_SUB(32);
		Bitboard mmp = m_and(MyUpBB[MY_RANK5],m_or(bb_my_ma,bb_my_pawn));
		if(StoX(yk) > 0x4 && !have_bit(mmp,RightBB[0x3])){
			MY_EV_SUB(64);
		}
		if(StoX(yk) < 0x4 && !have_bit(mmp,LeftBB[0x5])){
			MY_EV_SUB(64);
		}
	}




	// fen 3r1k3/4a4/4ba3/PR1N5/3r2b2/2N6/9/4B4/4A4/2B1KA3 b - - 0 1
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3 && EV_MY_SAFE){
			RETRUN_MUL(6);
		}
		if(EV_MY_SAFE){
			RETRUN_MUL(8);
		}
	}
}

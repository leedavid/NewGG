#ifndef END_my_m_MT_R_1ma2pawn_B_1che1pawn_s
#define END_my_m_MT_R_1ma2pawn_B_1che1pawn_s
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1马2兵对1车1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//
//const int PawnNotSameSide = 64;         //二兵方的兵不在一边,要加分

// fen 3ak1b2/9/3a4b/6r1N/5P2P/9/9/3AB4/4A4/p3K1B2 w - - 0 1
void my_m_MT_R_1ma2pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;
	//Square yk = your_king_pos;
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mma   = S90_from_piecelist(POSITION,my_ma,0);

	// fen 2b2ab2/4k4/N2a5/3P1P3/9/9/2r6/1p2B4/4A4/3AK1B2 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if(count_1s(bb_my_pawn,RankBB_A[MY_RANK3]) == 2 
			&& StoY(mma) MY_SMALL_EQL MY_RANK7){
			MY_EV_ADD(80);
		}
	}

	// fen 3ak1b2/9/3a4b/6r1N/5P2P/9/9/3AB4/4A4/p3K1B2 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if(your_shi_num >= 1 || EV_MY_CAN <= 1){
			if(StoY(ypawn) == MY_RANK9){
				if(abs(StoX(ypawn) - 0x4) >= 3){
					RETRUN_MUL(3);
				}
			}
		}
	}

	// fen 2b2ab2/4k4/N2a5/3P1P3/9/9/2r6/1p2B4/4A4/3AK1B2 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if(count_1s(bb_my_pawn,RankBB_A[MY_RANK3]) == 2){
			if(!have_bit(bb_my_pawn,LeftBB[0x3]) 
				&& !have_bit(bb_my_pawn,RightBB[0x5])){
                RETRUN_MUL(4);
			}
		}
	}

}



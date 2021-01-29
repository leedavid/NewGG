#ifndef END_my_m_MT_R_1che1ma3pawn_B_1che1ma2pawn
#define END_my_m_MT_R_1che1ma3pawn_B_1che1ma2pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车1马3兵对1车1马2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

void my_m_MT_R_1che1ma3pawn_B_1che1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;
	Square yk = your_king_pos;

	// fen 2ba1k3/4a4/4b4/4p4/1P4n1p/1r2P4/2N1R3P/B8/9/3AKA3 w - - 0 1
	if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) == MY_RANK9){
		if(EV_YOUR_CAN == 0){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	if ((my_shi_num + my_xiang_num) == 4 && StoY(mk) == MY_RANK9){
		if (EV_YOUR_CAN <= 1){
			EV_MY_SAFE = TRUE;
		}
	}

	// fen 2b1k3N/4a4/4ba3/PP4r2/8p/9/6pnP/3AB2R1/4A4/3K5 w - - 0 1
	if (EV_YOUR_CAN <= 1){
		if ((my_shi_num + my_xiang_num) >= 3 && StoY(mk) == MY_RANK9){
			if (!have_bit(bb_your_pawn, MyLowBB[MY_RANK6])){
				MY_EV_ADD(EV_MY_CAN * 16);
			}
			Bitboard lp = My_get_connect_Pawn(POSITION);
			if (have_bit(lp, RankBB_A[MY_RANK3])){
				MY_EV_ADD(32);
			}
		}
	}

	// fen 2baka1R1/9/8b/p5p2/9/1n2P3P/P1r6/3N5/9/3AKA3 w - - 0 1
	if(my_shi_num == 2 && MY_SQ55 == mk){
		if(EV_YOUR_CAN <= 1 && !have_bit(bb_your_pawn,MyLowBB[MY_RANK4])){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	// fen 2baka3/9/2N1b4/4p3p/7n1/2P3P1P/4r4/4B4/1R2A4/2BAK4 w - - 0 1
	if (EV_MY_SAFE){
		if ((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
			if (EV_MY_CAN == 0){
				RETRUN_MUL(8);
			}
		}
	}

}
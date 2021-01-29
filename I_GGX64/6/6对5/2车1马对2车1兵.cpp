#ifndef END_my_m_MT_R_2che1ma_B_2che1pawn
#define END_my_m_MT_R_2che1ma_B_2che1pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "2车1马对2车1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 




void my_m_MT_R_2che1ma_B_2che1pawn(typePOS &POSITION, EvalInfo &ei){
	
	Square yk = your_king_pos;
	//fen 2rk1ab2/4a1N2/4b4/7R1/9/9/1R7/B3B1p2/3rA4/4KA3 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(64);
		if (EV_YOUR_CAN){
			MY_EV_SUB(64);
		}
		if (have_bit(bb_your_che, FileBB_A[StoX(yk)])){
			MY_EV_SUB(64);
		}
	}
}
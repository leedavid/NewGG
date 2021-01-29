#ifndef END_my_m_MT_R_1che1pawn_B_1pao1ma
#define END_my_m_MT_R_1che1pawn_B_1pao1ma
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车1马对1炮1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//车兵对炮兵
void my_m_MT_R_1che1ma_B_1pao1ma(typePOS &POSITION, EvalInfo &ei){


	Square yk   = your_king_pos;
	Square yma  = S90_from_piecelist(POSITION,your_ma,0);
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);

	// fen 3c1kb2/2N1a4/3abn3/9/9/2R6/9/4B4/4A4/3AK4 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(ypao) MY_SMALL_EQL MY_RANK3){

			MY_EV_SUB(64);

			// fen 3ak1b2/4a4/1N1n5/5c1R1/6b2/9/9/5A3/9/4KAB2 b - - 0 1
			if(MY_SQ17 == yma){
				RETRUN_MUL(8);
			}
			if(MY_SQ15 == yma){
				RETRUN_MUL(8);
			}
		}
	}

}
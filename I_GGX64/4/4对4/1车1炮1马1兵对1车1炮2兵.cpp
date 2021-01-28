#ifndef END_my_m_MT_R_1che1pao1ma1pawn_B_1che1pao2pawn
#define END_my_m_MT_R_1che1pao1ma1pawn_B_1che1pao2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1炮1马1兵对1车1炮2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che1pao1ma1pawn_B_1che1pao2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	//Square ypao = S90_from_piecelist(POSITION,your_pao,0);

	// fen 4k4/4a3N/3c1a2b/p8/9/1R3p1r1/P1C6/3A5/4K4/9 b - - 0 1
	if(EV_MY_CAN == 0){
		if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
			if((PB90(MY_SQ11) == my_ma && PB90(MY_SQ1A) == your_xiang)
				|| (PB90(MY_SQ09) == my_ma && PB90(MY_SQ12) == your_xiang)){
                MY_EV_SUB(EV_YOUR_CAN * 32);
			}
		}
	}

	// fen 3ckab2/4a4/4b4/8p/6p2/2R6/2Nr4P/4C4/4A4/4KA3 w - - 0 1
	MY_EV_ADD(32);
	if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK5])){
		MY_EV_ADD(32);
	}

	// fen 4kab2/9/4ba3/p3R3p/cr7/9/7NP/9/3CK4/6B2 w - - 0 1
	if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK5])){
		if(have_bit(LeftBB[0x1],bb_your_pawn) && have_bit(RightBB[0x7],bb_your_pawn)){
			MY_EV_ADD(32);
		}
	}

}

//


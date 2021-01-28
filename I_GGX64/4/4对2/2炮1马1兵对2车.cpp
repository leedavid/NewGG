#ifndef END_my_m_MT_R_2pao1ma1pawn_B_2che
#define END_my_m_MT_R_2pao1ma1pawn_B_2che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2炮1马1兵对2车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_2pao1ma1pawn_B_2che(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;

	// fen 2b1ka3/4a4/n2cb4/9/8p/8c/4R4/4B4/4A1R2/2BAK4 w - - 0 1
	if (my_shi_num == 2 && my_xiang_num == 2 && PB90(MY_SQ43) == my_xiang){
		if (MY_SQ55 == mk){
			if (PB90(MY_SQ44) == my_pao && PB90(MY_SQ57) == my_xiang){
				if (PB90(MY_SQ47) == my_ma && PB90(MY_SQ54) == my_shi){
					if (have_bit(LeftBB[0x04], bb_my_pao)){
						RETRUN_MUL(4);
					}
				}
			}
			if (PB90(MY_SQ42) == my_pao && PB90(MY_SQ53) == my_xiang){
				if (PB90(MY_SQ3F) == my_ma && PB90(MY_SQ56) == my_shi){
					if (have_bit(RightBB[0x04], bb_my_pao)){
						RETRUN_MUL(4);
					}
				}
			}
			RETRUN_MUL(8);
		}
	}

}
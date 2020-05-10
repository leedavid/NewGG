#ifndef END_my_m_MT_R_2pao1ma_B_1pao2ma
#define END_my_m_MT_R_2pao1ma_B_1pao2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2ÅÚ1Âí¶Ô1ÅÚ2Âí.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//ADD_1PaoXPawn_1PaoXPawn_ByShi

void my_m_MT_R_2pao1ma_B_1pao2ma(typePOS &POSITION, EvalInfo &ei){


	Square mk = my_king_pos;
	Square yk = your_king_pos;

	// fen 3ak4/2c1a4/4b1N2/2C4n1/3n5/6B2/9/3AC3B/4A4/5K3 w - - 0 1
	if((my_shi_num + my_xiang_num) >= 3){
		if((your_shi_num + your_xiang_num) >= 3){
			if(StoY(mk) == MY_RANK9 && StoY(yk) == MY_RANK0){
				RETRUN_MUL(8);
			}
		}
	}



}


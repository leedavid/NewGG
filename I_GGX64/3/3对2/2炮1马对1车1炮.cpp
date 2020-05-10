#ifndef END_my_m_MT_R_2pao1ma_B_1che1pao
#define END_my_m_MT_R_2pao1ma_B_1che1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2ÅÚ1Âí¶Ô1³µ1ÅÚ.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2pao1ma_B_1che1pao(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;

	if(StoY(my_king_pos) != MY_RANK9){
		MY_EV_SUB(ADD_NO_CHE_OP_KING_NOT_BOTTOM);
	}

	// fen 3ak1b2/5c3/1R1a5/9/2b1nNn2/6B2/9/4B4/4A4/4K4 b - - 0 1
	if((your_shi_num + your_xiang_num) >= 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		MY_EV_SUB(64);
	}

	// fen 3k1a3/9/n2a3rb/C2N5/2N6/2B6/9/4B4/9/3AKA3 w - - 127 
	if((your_shi_num + your_xiang_num) >= 2){
		if((my_shi_num + my_xiang_num) >= 3 && StoY(my_king_pos) == MY_RANK9){
			RETRUN_MUL(8);
		}
	}	
}



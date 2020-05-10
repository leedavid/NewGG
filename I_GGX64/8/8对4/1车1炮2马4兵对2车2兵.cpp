#ifndef END_my_m_MT_R_1che1pao2ma4pawn_B_2che2pawn
#define END_my_m_MT_R_1che1pao2ma4pawn_B_2che2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1炮2马4兵对2车2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//
void my_m_MT_R_1che1pao2ma4pawn_B_2che2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;

	// fen 3ak4/9/3ab4/3N4p/5P3/9/P1P1p3P/NR2B1r2/5r3/1C2KA3 w - - 0 1
	if(my_shi_num <= 1 && my_xiang_num <= 1){
		MY_EV_SUB(16);
		if(have_bit(bb_your_pawn,MyLowBB[MY_RANK5])){
			MY_EV_SUB(64);
			if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
				if(have_bit(bb_my_ma,MyLowBB[MY_RANK6])){
					MY_EV_SUB(32);
				}
			}
		}		
	}
}
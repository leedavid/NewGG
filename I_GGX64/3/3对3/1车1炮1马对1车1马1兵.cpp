#ifndef END_my_m_MT_R_1che1pao1ma_B_1che1ma1pawn
#define END_my_m_MT_R_1che1pao1ma_B_1che1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1炮1马对1车1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int  AD_Che_CanNotMove = 256;

void my_m_MT_R_1che1pao1ma_B_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mk    = my_king_pos;
	Square yk    = your_king_pos;
	Square mma   = S90_from_piecelist(POSITION,my_ma,0);

	// fen 2b1kc3/4a4/n8/R8/9/2N3P2/8r/4B4/4A4/3AK1B2 w - - 0 1
	if((my_shi_num + my_xiang_num) >= 2){
		MY_EV_ADD(64);
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK7 && StoY(mk) == MY_RANK9){
			MY_EV_ADD(32);
		}
	}

	// fen N6r1/R3ak3/b2a5/3C5/2b6/3n5/9/4BA3/4A1p2/2B1K4 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(bit_is_set(ei.attacked_by(your_che),mma)){
			if((PB90(MY_SQ00) == my_ma && PB90(MY_SQ09) == my_che && PB90(MY_SQ12) == your_xiang)
				|| (PB90(MY_SQ08) == my_ma && PB90(MY_SQ11) == my_che && PB90(MY_SQ1A) == your_xiang)){
					MY_EV_SUB(96);
					MY_EV_SUB(EV_YOUR_CAN * 64);
			}
		}
	}
	
}


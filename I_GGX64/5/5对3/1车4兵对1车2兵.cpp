#ifndef END_my_m_MT_R_1che4pawn_B_1che2pawn
#define END_my_m_MT_R_1che4pawn_B_1che2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车4兵对1车2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1che4pawn_B_1che2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePawn_To_ChePawnByShi[your_shi_num]);

	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_ChePawn_To_ChePawnByShi[my_shi_num]);

	// fen 2baka3/9/4b4/R8/6p1p/4P4/P1P3P1P/9/3rA4/2B1KAB2 b - - 0 1
	if(EV_YOUR_CAN <= 1){
		if(my_shi_num >= 1){
			EV_MY_SAFE = TRUE;
		}
	}
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		EV_MY_SAFE = TRUE;
	}


	// fen 2b1ka3/4a2P1/4b4/9/p5r1p/2P3B2/P6RP/4B4/9/3AKA3 b - - 121 121
    //在这红方只有一个兵过河, 其它的三个兵都不能过河,就难胜
	int mcan = EV_MY_CAN;
	int ycan = EV_YOUR_CAN;
	if(mcan <= 1 && ycan <= 1){
		if((your_xiang_num + your_shi_num) == 4 && StoY(yk) == MY_RANK0){
			RETRUN_MUL(4);
		}
	} 
	// fen 2bk1a3/4a2P1/4b4/9/p5r1p/6B2/P3R3P/4B4/4A4/3AK4 w - - 0 0

	// fen 5Rb2/4k4/4bP3/4p3p/p8/8P/4pr3/4B4/4A4/3AK1B2 w - - 3 3
	if(my_xiang_num >= 1 && ycan <= 1){		
		if(PB90(MY_SQ4C) == my_king){
			Square p = SQ_START;
			bool bad = false;
			if(PB90(MY_SQ54) == your_che && PB90(MY_SQ42) == your_pawn){
				bad = true;
				p = Square(MY_SQ42);
			}
			if(PB90(MY_SQ56) == your_che && PB90(MY_SQ44) == your_pawn){
				bad = true;
				p = Square(MY_SQ44);
			}
			if(bad){
				Square mche = S90_from_piecelist(POSITION,my_che,0);
				//print_bb(ei.attacked_by(my_che]);				
				if(bit_is_set(ei.attacked_by(my_che),p) 
					&& bit_is_set(ei.attacked_by(MY_COLOR),mche)){
						MY_EV_ADD(mcan * 96);
				}
			}
		}
	}
	

	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
				RETRUN_MUL(4);
			}
		}
	}
}


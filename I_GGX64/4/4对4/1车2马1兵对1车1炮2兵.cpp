#ifndef END_my_m_m_MT_R_1che2ma1pawn_B_1che1pao2pawn 
#define END_my_m_m_MT_R_1che2ma1pawn_B_1che1pao2pawn 
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车2马1兵对1车1炮2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che2ma1pawn_B_1che1pao2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;

	// fen 4ka3/4a4/4c3b/R3N4/6b1p/6p2/5N2P/4B4/9/1r1AKA3 w - - 0 1
	if(MY_SQ04 == yk && your_shi_num == 2 && your_xiang_num == 2){
		if(EV_MY_CAN == 0){
			MY_EV_SUB(32);
			if(my_xiang_num <= 1){
				MY_EV_SUB(EV_YOUR_CAN * 32);
			}
		}
	}
	
}
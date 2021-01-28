#ifndef END_my_m_MT_R_1pao3pawn_B_1pao1ma1pawn
#define END_my_m_MT_R_1pao3pawn_B_1pao1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1炮3兵对1炮1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int RBcanByPawnAdd = 48;


void my_m_MT_R_1pao3pawn_B_1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){	

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square yma   = S90_from_piecelist(POSITION,your_ma,0);
	Square mpao  = S90_from_piecelist(POSITION,my_pao,0);
	Square mk    = my_king_pos;

	// fen 3k3P1/4a4/b3b4/3P1C3/5P3/2B1c4/9/4B4/3pA2n1/3AK4 b - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(ypawn) MY_LARGE_EQL MY_RANK8){
		if(MY_SQ55 == mk && have_bit(bb_my_pawn,RankBB_A[MY_RANK3])){
			if(StoX(ypawn) < 0x4 && !have_bit(bb_my_shi,RightBB[0x4])){
				if(StoX(yma) > 0x4 && StoX(mpao) == 0x5){
					RETRUN_MUL(8);
				}
			}
			if(StoX(ypawn) > 0x4 && !have_bit(bb_my_shi,LeftBB[0x4])){
				if(StoX(yma) < 0x4 && StoX(mpao) == 0x3){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 3k3P1/4a4/b3b4/3P1C3/5P3/2B1c4/9/4B4/3pA2n1/3AK4 b - - 0 1
	if(EV_MY_CAN >= 2 && have_bit(bb_my_pawn,RankBB_A[MY_RANK3])){
		if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			if(StoX(ypawn) < 0x4 && StoX(mk) >= 0x4 && !have_bit(bb_my_shi,RightBB[0x4])){
				MY_EV_ADD(EV_MY_CAN * 32);
				RETRUN_MUL(8);
			}
			if(StoX(ypawn) > 0x4 && StoX(mk) <= 0x4 && !have_bit(bb_my_shi,LeftBB[0x4])){
				MY_EV_ADD(EV_MY_CAN * 32);
				RETRUN_MUL(8);
			}
		}
	}

}
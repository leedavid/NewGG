#ifndef END_my_m_MT_R_1pao2ma3pawn_B_1che1ma3pawn
#define END_my_m_MT_R_1pao2ma3pawn_B_1che1ma3pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1炮2马3兵对1车1马3兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1pao2ma3pawn_B_1che1ma3pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	//
	if(StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(EV_MY_CAN <= 1){
			if((your_shi_num + your_xiang_num) >= 3){
				MY_EV_SUB(EV_MY_CAN * 32);
			}
			MY_EV_SUB(32);
		}
	}
}
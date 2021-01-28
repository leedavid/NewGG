#ifndef ENDR_my_m_MT_R_1pao1ma4pawn_B_1pao1ma3pawn
#define ENDR_my_m_MT_R_1pao1ma4pawn_B_1pao1ma3pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1炮1马4兵对1炮1马3兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1pao1ma4pawn_B_1pao1ma3pawn(typePOS &POSITION, EvalInfo &ei){

	//Square mk = my_king_pos;
	// fen C2k1a3/4a4/9/p1N5p/9/2P1P4/P7P/2n3p2/9/c1B1KA3 w - - 0 1
	if(EV_YOUR_CAN <= 1){
		if((my_shi_num + my_xiang_num) >= 2){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

}
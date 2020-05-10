
#ifndef ENDR_my_m_MT_R_1pao1ma4pawn_B_2pao3pawn
#define ENDR_my_m_MT_R_1pao1ma4pawn_B_2pao3pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1ÅÚ1Âí4±ø¶Ô2ÅÚ3±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1pao1ma4pawn_B_2pao3pawn(typePOS &POSITION, EvalInfo &ei){

	// fen 2bk1ab2/4a4/1c7/2p1C3p/p8/2c3P2/P3P3P/N2A5/9/2BK5 b - - 0 1
	if(EV_YOUR_CAN <= 1){
		if(my_shi_num >= 1 && my_xiang_num >= 1){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	MY_EV_ADD(EV_MY_CAN * 32);
}


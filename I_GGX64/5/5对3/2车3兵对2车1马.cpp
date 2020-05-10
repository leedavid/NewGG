#ifndef END_my_m_MT_R_2che3pawn_B_2che1ma
#define END_my_m_MT_R_2che3pawn_B_2che1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2车3兵对2车1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2che3pawn_B_2che1ma(typePOS &POSITION, EvalInfo &ei){

	Square mk  = my_king_pos;
	Square yma = S90_from_piecelist(POSITION,your_ma,0);

	// fen 4kab2/4a4/4b4/5r3/3PR2P1/P3P4/9/4B4/8R/3AKABrc w - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && MY_SQ55 == mk){
		if(StoY(yma) MY_SMALL_EQL MY_RANK3){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}
}

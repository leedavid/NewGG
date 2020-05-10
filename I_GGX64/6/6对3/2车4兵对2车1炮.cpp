#ifndef END_my_m_MT_R_2che4pawn_B_2che1pao
#define END_my_m_MT_R_2che4pawn_B_2che1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2³µ4±ø¶Ô2³µ1ÅÚ.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2che4pawn_B_2che1pao(typePOS &POSITION, EvalInfo &ei){

	Square mk  = my_king_pos;
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);

	// fen 4kab2/4a4/4b4/5r3/3PR2P1/P3P4/9/4B4/8R/3AKABrc w - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && MY_SQ55 == mk){
       if(MY_SQ59 == ypao && PB90(MY_SQ58) == your_che && PB90(MY_SQ50) == my_che){
		   if(PB90(MY_SQ57) == my_xiang && PB90(MY_SQ56) == my_shi){
			   MY_EV_ADD(EV_MY_CAN * 16);
		   }
	   }
	   if(MY_SQ51 == ypao && PB90(MY_SQ52) == your_che && PB90(MY_SQ48) == my_che){
		   if(PB90(MY_SQ53) == my_xiang && PB90(MY_SQ54) == my_shi){
			   MY_EV_ADD(EV_MY_CAN * 16);
		   }
	   }
	}
}

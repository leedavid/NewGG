#ifndef END_my_m_MT_B_1pao1ma3pawn_R_1che3pawn
#define END_my_m_MT_B_1pao1ma3pawn_R_1che3pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1炮1马3兵对1车3兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



void  my_m_MT_R_1pao1ma3pawn_B_1che3pawn(typePOS &POSITION, EvalInfo &ei){

	// fen 3a5/4a4/5k3/p3C3p/5Np2/9/P5P1P/4B4/4A4/4KA1r1 b - - 0 1
	if(EV_MY_CAN <= 1){
		MY_EV_SUB(32);		
	}
	if((my_shi_num + my_xiang_num) <= 3){
		MY_EV_SUB(32);
	}
}
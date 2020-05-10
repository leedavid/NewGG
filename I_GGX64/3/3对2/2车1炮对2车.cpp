#ifndef END_my_m_MT_R_2che1pao_B_2che
#define END_my_m_MT_R_2che1pao_B_2che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
#include "..\\..\\endgame\mat.h"
#include "2车1炮对2车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int const_Shi_add[3] = {128,48,0};
//const int const_Pawn_add   =  48;

//2车1兵对2车
void my_m_MT_R_2che1pao_B_2che(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;
	Square yk = your_king_pos;

	if(my_shi_num == 2 && StoY(mk) == MY_RANK9){
		EV_MY_SAFE = true;
	}

    // fen 1r1ak4/4a4/4b4/6r2/2b6/5R3/7R1/C8/4A4/4KA3 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
			RETRUN_MUL(8);
		}
	}
}
#ifndef END_my_m_MT_R_2pao_B_1pawn
#define END_my_m_MT_R_2pao_B_1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮对1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

// 2炮对1马


// fen 4ck3/4a4/3a5/1N7/6b2/6B2/4c4/9/4A4/2BAK4 w - - 126 126 

void my_m_MT_R_2pao_B_1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;

	if(my_shi_num == 0 && my_xiang_num == 0 && your_xiang_num == 2){
		RETRUN_MUL(2);
	}

	if(my_shi_num == 0){
		RETRUN_MUL(4);
	}

	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		RETRUN_MUL(8);
	}
}


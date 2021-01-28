#ifndef END_my_m_MT_R_1che2pao_B_1che1pao
#define END_my_m_MT_R_1che2pao_B_1che1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车2炮对1车1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



//车2炮对车炮
void my_m_MT_R_1che2pao_B_1che1pao(typePOS &POSITION, EvalInfo &ei){
   
	Square yk   = your_king_pos;
	Square yche = S90_from_piecelist(POSITION,your_che,0);

	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){

		// fen 2bak4/4a4/4b4/4R4/4c4/2B6/4r4/3C5/4A4/3CKAB2 b - - 0 1
		if(PB90(MY_SQ1F) == my_che && PB90(MY_SQ28) == your_pao){
			if(StoX(yche) == 0x4 && StoY(yche) MY_LARGE_EQL MY_RANK5){
				MY_EV_SUB(128);
			}
		}

		RETRUN_MUL(8);
	}
}

//void m_MT_B_1che2pao_R_1che1pao(typePOS &POSITION, EvalInfo &ei){
//   /* 
//	if(board->R_shi == 2 && board->R_xiang == 2){
//	   return 8;
//	}
//
//	return 16;	/*/
//}
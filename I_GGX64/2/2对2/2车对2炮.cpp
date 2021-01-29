#ifndef END_my_m_MT_K2CHE_B_2PAO_S
#define END_my_m_MT_K2CHE_B_2PAO_S
#include "../../chess.h"
#include "../../preGen.h" 
#include "../../endgame/mat.h"
#include "2车对2炮.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//my_m_MT_R_2CHE_B_1CHE1PAO 
//我方2车，对方一车一炮
void my_m_MT_R_2che_B_2pao(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;

	// fen 3akab2/9/1c2bc3/4R4/5R3/9/9/4B4/4A4/2BAK4 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
		if(!have_bit(bb_your_xiang,MyLowBB[MY_RANK3])){
			// 左右一个炮
			if(!have_bit(bb_your_pao,MyLowBB[MY_RANK2])){
				if(have_bit(bb_your_pao,LeftBB[0x4]) && have_bit(bb_your_pao,RightBB[0x4])){
					RETRUN_MUL(2);
				}
			}
		}
	}
}
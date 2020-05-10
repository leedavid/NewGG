#ifndef END_my_m_MT_R_2che1pao4pawn_B_2che2pao1pawn
#define END_my_m_MT_R_2che1pao4pawn_B_2che2pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2车1炮4兵对2车2炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan      =  32;                     //2车方有兵可过河，


void my_m_MT_R_2che1pao4pawn_B_2che2pao1pawn(typePOS &POSITION, EvalInfo &ei){

	//int ycan = EV_YOUR_CAN;
	//if(ycan == 0){
	//	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(my_king_pos) == MY_RANK9){
	//		MY_EV_ADD(EV_MY_CAN * ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan);
	//	}
	//}
	Square mk = my_king_pos;

	// fen 2baka3/9/4b4/8p/1P1PPC1r1/4c2r1/4R3P/4B4/4A2c1/2B1KA1R1 b - - 0 1
	if(EV_YOUR_CAN == 0 && my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		//对方的二个炮，都被我方攻击了
		if(!m_have_bit(_mm_andnot_si128(MY_ATTACK,bb_your_pao))){
			MY_EV_ADD(EV_MY_CAN * 16);			
		}
		Bitboard mp = m_and(bb_my_pawn,MyUpBB[MY_RANK5]);
		MY_EV_ADD((sint16)count_1s(mp) * 16);
	}
}


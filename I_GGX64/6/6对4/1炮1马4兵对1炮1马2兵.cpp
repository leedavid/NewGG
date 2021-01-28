#ifndef END_m_MT_R_1pao1ma4pawn_B_1pao1ma2pawn
#define END_m_MT_R_1pao1ma4pawn_B_1pao1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1炮1马4兵对1炮1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1pao1ma4pawn_B_1pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	// fen 3k1ab2/4a4/4b4/1P7/3P3cp/6P2/8P/2N2C3/2p6/n2K1AB2 b - - 0 1
	if(my_shi_num >= 1 && my_xiang_num >= 1){
		if(EV_YOUR_CAN <= 1 && EV_MY_CAN >= 2){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}
}
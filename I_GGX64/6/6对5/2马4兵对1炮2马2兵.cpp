#ifndef END_my_m_MT_R_2ma4pawn_B_1pao2ma2pawn
#define END_my_m_MT_R_2ma4pawn_B_1pao2ma2pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "2马4兵对1炮2马2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_2ma4pawn_B_1pao2ma2pawn(typePOS &POSITION, EvalInfo &ei) {


	//  fen 2bak4/9/3a5/5C3/p4N2p/9/Pn1pp3P/1N6B/4A1n2/3K1A3 w - - 0 1
	if (your_shi_num == 2) {
		MY_EV_SUB(32);
		if (EV_MY_CAN <= 2) {
			MY_EV_SUB(32);
		}
	}

}
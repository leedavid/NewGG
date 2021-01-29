#ifndef END_my_m_MT_R_1ma4pawn_B_2ma2pawn
#define END_my_m_MT_R_1ma4pawn_B_2ma2pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1马4兵对2马2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


// fen 3akab2/9/4b4/p8/4p3p/2B6/P1n1P3P/2N1BA3/4Ap3/3K5 b - - 10 10
void my_m_MT_R_1ma4pawn_B_2ma2pawn(typePOS &POSITION, EvalInfo &ei) {

	if (your_shi_num == 2) {
		if (count_1s(bb_my_pawn, MyUpBB[MY_RANK3]) <= 1) {
			EV_YOUR_SAFE = true;
		}
	}

	//  fen 4k1b2/4a4/5a2b/p5p2/1P7/3N2P2/P1n1P4/3A5/2n1AK3/2B6 b - - 0 1
	if (EV_YOUR_SAFE) {
		if (my_shi_num == 2 && my_xiang_num >= 1) {
			if (EV_YOUR_CAN == 0) {
				RETRUN_MUL(8);
			}
		}
	}

}
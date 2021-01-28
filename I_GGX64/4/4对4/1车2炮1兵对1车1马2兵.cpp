#ifndef END_m_MT_R_1che2pao1pawn_B_1che1ma2pawn
#define END_m_MT_R_1che2pao1pawn_B_1che1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
#include "..\\..\\endgame\mat.h"
#include "1车2炮1兵对1车1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1che2pao1pawn_B_1che1ma2pawn(typePOS &POSITION, EvalInfo &ei) {

	// fen 2ba2b2/4k4/5C3/p3C4/9/4p3P/r6n1/9/5R3/2BK5 b - - 0 1

	Square mpawn = S90_from_piecelist(POSITION, my_pawn, 0);

	if (my_shi_num == 0 && my_xiang_num <= 1) {
		MY_EV_SUB(EV_YOUR_CAN * 32);

		if (abs(StoX(mpawn) - 0x4) >= 3 && StoY(mpawn) MY_LARGE_EQL MY_RANK5) {
			MY_EV_SUB(32);
		}
	}
}
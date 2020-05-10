#ifndef ENDR_1che2ma3pawn_B_1che2pao1ma1pawn
#define ENDR_1che2ma3pawn_B_1che2pao1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车2马3兵对1车2炮1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che2ma3pawn_B_1che2pao1ma1pawn(typePOS &POSITION, EvalInfo &ei) {

	Square yma = S90_from_piecelist(POSITION, your_ma, 0);

	//  fen 2b1ka1R1/c8/n2r4b/N1p6/P2PPN3/9/5c3/4B4/4A4/2BA1K3 b - - 0 1
	if (EV_YOUR_CAN == 0) {
		if (EV_MY_CAN >= 3) {
			MY_EV_ADD(EV_MY_CAN * 16);
			if (StoY(yma) MY_SMALL_EQL MY_RANK2) {
				MY_EV_ADD(16);
			}
		}
	}

}
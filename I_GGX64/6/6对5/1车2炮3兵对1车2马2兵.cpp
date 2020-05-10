#ifndef ENDR_1che2pao3pawn_B_1che2ma2pawn
#define ENDR_1che2pao3pawn_B_1che2ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车2炮3兵对1车2马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che2pao3pawn_B_1che2ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;
	Square yche = S90_from_piecelist(POSITION,your_che,0);
	// fen 2bak2r1/4a4/4b2Cn/4C2R1/P7p/2B1n1P2/8P/9/2p1A4/2BAK4 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && EV_YOUR_CAN <= 1){
		if(MY_SQ55 == mk && StoY(yche) MY_SMALL_EQL MY_RANK2){
			MY_EV_ADD(16);
			if(have_bit(bb_your_ma,MyUpBB[MY_RANK3])){
				MY_EV_ADD(16);
			}
		}

		// fen 2nakab2/9/2R1b4/p2r5/2P1P4/9/P8/3CB1C2/4A1n1p/2BK1A3 b - - 0 1
		if(StoY(mk) == MY_RANK9 && EV_MY_CAN >= 2){
			if(have_bit(bb_your_pawn,LeftBB[0x1]) && have_bit(bb_your_pawn,RightBB[0x7])){
				MY_EV_ADD(32);
			}
		}
	}
}
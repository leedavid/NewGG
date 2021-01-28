#ifndef END_my_m_MT_R_2pao2ma3pawn_B_1che2ma2pawn
#define END_my_m_MT_R_2pao2ma3pawn_B_1che2ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2炮2马3兵对1车2马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2pao2ma3pawn_B_1che2ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;

	// fen 2bak1b2/4a4/9/2r3P2/3N2p1p/3n1N3/4P3P/1n3C2B/4A4/1C1AK1B2 b - - 0 1
    if(mk == MY_SQ55 && my_shi_num == 2 && my_xiang_num == 2 && EV_YOUR_CAN == 0){
		MY_EV_ADD(EV_MY_CAN * 32);
		// 二相相连

	}
}
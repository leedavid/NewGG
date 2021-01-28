#ifndef END_my_m_MT_R_2pao1ma2pawn_B_1che1ma2pawn
#define END_my_m_MT_R_2pao1ma2pawn_B_1che1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2炮1马2兵对1车3兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_2pao1ma2pawn_B_1che3pawn(typePOS &POSITION, EvalInfo &ei) {


	//  fen 4kab2/4a3C/6N2/pr7/6b1P/2C2p3/P3p4/4B4/4A4/3AK1B2 b - - 0 1
	if (EV_YOUR_CAN >= 2) {
		MY_EV_SUB(32);

		Bitboard ygp = m_and(bb_your_pawn, MyLowBB[MY_RANK4]);
		MY_EV_SUB(count_1s(ygp) * 32);
	}

}
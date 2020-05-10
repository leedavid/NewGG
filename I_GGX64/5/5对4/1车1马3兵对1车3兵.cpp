#ifndef END_my_m_MT_R_1che1ma3pawn_B_1che3pawn
#define END_my_m_MT_R_1che1ma3pawn_B_1che3pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1马3兵对1车3兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1che1ma3pawn_B_1che3pawn(typePOS &POSITION, EvalInfo &ei){

	// fen 4kab2/4a4/4b1R2/p1P1p4/6p2/3NP4/P8/9/5K3/3r5 w - - 0 1
	//对方一个兵也没有过河

	MY_EV_ADD(EV_MY_CAN * 16);

    //Bitboard yghp = m_and(bb_your_pawn,MyLowBB[MY_RANK4])
	if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK4])){
		MY_EV_ADD(EV_MY_CAN * 32);
	}

}

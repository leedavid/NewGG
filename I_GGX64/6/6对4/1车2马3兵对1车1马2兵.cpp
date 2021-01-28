#ifndef END_my_m_m_MT_R_1che2ma3pawn_B_1che1ma2pawn 
#define END_my_m_m_MT_R_1che2ma3pawn_B_1che1ma2pawn 
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车2马3兵对1车1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che2ma3pawn_B_1che1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk  = my_king_pos;
	Square yma = S90_from_piecelist(POSITION,your_ma,0);

	// fen 3k1ab2/9/b4a3/2P2N2p/4P4/3N4P/9/2pnR4/5K3/4r4 b - - 0 1
    if(EV_YOUR_CAN <= 1){
		MY_EV_ADD(EV_MY_CAN * 16);
		if(PB90(MY_SQ55) == your_che && PB90(MY_SQ43) == my_che){
		  if(mk == MY_SQ4D && PB90(MY_SQ42) == your_ma && PB90(MY_SQ41) == your_pawn && PB90(MY_SQ30) == my_ma){
			  MY_EV_ADD(64);
			  MY_EV_ADD(EV_MY_CAN * 32);
		  }
		  if(mk == MY_SQ4B && PB90(MY_SQ44) == your_ma && PB90(MY_SQ45) == your_pawn && PB90(MY_SQ32) == my_ma){
			  MY_EV_ADD(64);
			  MY_EV_ADD(EV_MY_CAN * 32);
		  }
		}
	}

	// fen 2b2k3/4a4/4ba3/p8/2PN4p/P8/n3P4/4N4/2R1K4/8r b - - 0 1
	if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK4])){
		MY_EV_ADD(16);
		MY_EV_ADD(EV_MY_CAN * 8);
	}
	if(abs(StoX(yma) - 0x4) == 4){
		MY_EV_ADD(EV_MY_CAN * 16);
	}
    
}


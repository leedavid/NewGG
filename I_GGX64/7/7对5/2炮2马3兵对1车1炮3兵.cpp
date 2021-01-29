#ifndef END_my_m_MT_R_2pao2ma3pawn_B_1che1pao3pawn
#define END_my_m_MT_R_2pao2ma3pawn_B_1che1pao3pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "2炮2马3兵对1车1炮3兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



void my_m_MT_R_2pao2ma3pawn_B_1che1pao3pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;

	// fen 2b1kab2/2c1a4/9/p3p3p/1C7/1N2P4/P2N1r2P/4K2C1/4A4/2BA2B2 b - - 0 1
	if(StoY(mk) == MY_RANK7){
		MY_EV_SUB(64);
	}
}
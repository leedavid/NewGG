#ifndef END_my_m_MT_R_1che1pao1ma5pawn_B_2che1pao3pawn
#define END_my_m_MT_R_1che1pao1ma5pawn_B_2che1pao3pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1炮1马5兵对2车1炮3兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che1pao1ma5pawn_B_2che1pao3pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;

	// fen 4ka1r1/4a4/2R6/p7p/2p3P2/5N3/P1P1P3P/4BC3/4A3c/1r1AK1B2 b - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && mk == MY_SQ55){
		if(EV_YOUR_CAN == 0){
		   MY_EV_ADD(EV_MY_CAN * 32);
		}
	}
}
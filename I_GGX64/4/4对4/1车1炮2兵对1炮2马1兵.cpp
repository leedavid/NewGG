#ifndef END_my_m_MT_R_1che1pao2pawn_B_1pao2ma1pawn
#define END_my_m_MT_R_1che1pao2pawn_B_1pao2ma1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1炮2兵对1炮2马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1che1pao2pawn_B_1pao2ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[my_shi_num]);

	// fen 4k4/9/2N6/p3N4/3C5/P3r4/9/3K1A3/6c2/2B1p1B2 w - - 0 113
	if((my_shi_num + my_xiang_num) == 0){
		if(EV_MY_CAN == 0){
		   MY_EV_SUB(80);
		}
	}
}



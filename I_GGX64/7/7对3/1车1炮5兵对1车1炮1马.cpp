#ifndef END_my_m_MT_R_1che1pao5pawn_B_1che1pao1ma
#define END_my_m_MT_R_1che1pao5pawn_B_1che1pao1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1炮5兵对1车1炮1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1che1pao5pawn_B_1che1pao1ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	//Square mk = my_king_pos;
	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	//
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[your_shi_num]);
	//
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[my_shi_num]);

	// fen 2baka3/9/2n1b4/2C2PP2/P1P5p/9/8P/1r2B2R1/4A4/3AK3c b - - 0 1
	if((my_shi_num + my_xiang_num) >= 2){
		if(StoY(yma) MY_SMALL_EQL MY_RANK2){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}
}

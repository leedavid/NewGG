#ifndef END_my_m_MT_R_1che1pao3pawn_B_1che3pawn
#define END_my_m_MT_R_1che1pao3pawn_B_1che3pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1炮3兵对1车3兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1che1pao3pawn_B_1che3pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	//// ADD
	//Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	//MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[your_shi_num]);
	//// SUB
	//Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	//MY_EV_SUB((sint16)count_1s(ymp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[my_shi_num]);

	// fen 2ba1k3/9/4b4/p3P3p/4P1p2/3c5/7RP/4B4/4K4/2B2r3 w - - 0 1
	if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1 && my_shi_num <= 1){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
			Bitboard yp = m_and(bb_your_pawn,MyLowBB[MY_RANK4]);
			MY_EV_SUB((sint16)count_1s(yp) * 32 * (2 - my_shi_num));
		}
	}

	// fen 3aka3/7R1/9/2p1p4/7C1/P5r2/4P3P/3A1p3/3K5/9 w - - 0 1
	if(my_shi_num >= 1 && your_xiang_num == 0){
		Bitboard ylr = m_and(bb_your_pawn,MyLowBB[MY_RANK4]);
		if(count_1s(ylr) <= 1){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}
}

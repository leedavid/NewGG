#ifndef END_my_m_MT_R_1che1ma4pawn_B_1che1pao1ma1pawn
#define END_my_m_MT_R_1che1ma4pawn_B_1che1pao1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1马4兵对1车1炮1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1che1ma4pawn_B_1che1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	//Square yk = your_king_pos;
	//
	//Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	//MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheMaXPawn_To_1Pao2Ma_ByPawn[your_shi_num]);
	////
	//Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	//MY_EV_SUB((sint16)count_1s(ymp) * ADD_CheMaXPawn_To_1Pao2Ma_ByPawn[my_shi_num]);

	// fen 3k5/4a4/b8/3r4p/1PP2RP2/1n7/4P3P/3Ac1N2/4A4/5K3 b - - 0 1
	if(your_shi_num <= 1 && your_xiang_num <= 1 && EV_YOUR_CAN == 0){
		if(my_shi_num == 2 && PB90(MY_SQ43) == your_pao){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

}


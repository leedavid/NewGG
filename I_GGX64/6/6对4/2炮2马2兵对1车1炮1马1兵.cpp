#ifndef END_my_m_MT_R_2pao2ma2pawn_B_1che1pao1ma1pawn
#define END_my_m_MT_R_2pao2ma2pawn_B_1che1pao1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2炮2马2兵对1车1炮1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int ADD_2Pao1MaXpawn_To_1Pao2Ma1Pawn_ByPawn[3]     = { 96, 64, 32};   //
//const int ADD_2Pao1Ma1pawn_To_1Pao2MaXPawn_ByPawn[3]     = { 96, 64, 32};   //


void my_m_MT_R_2pao2ma2pawn_B_1che1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk =  your_king_pos;

	// fen 3akc3/4a4/4b4/p4n2P/2r6/P8/6P2/N1C1N1C2/4A4/2BAK4 w - - 0 1
	if(count_1s(bb_my_pawn,MyUpBB[MY_RANK5]) <= 1){
		if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
			MY_EV_SUB(32);
			if(count_1s(MyLowBB[MY_RANK5],m_or(bb_my_ma,bb_my_pao)) >= 3){
				MY_EV_SUB(32);
			}
		}
	}
}
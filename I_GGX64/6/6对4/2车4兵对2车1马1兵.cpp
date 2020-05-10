#ifndef END_my_m_MT_R_2che4pawn_B_2che1ma1pawn
#define END_my_m_MT_R_2che4pawn_B_2che1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2车4兵对2车1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2che4pawn_B_2che1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk  = my_king_pos;
	Square yma = S90_from_piecelist(POSITION,your_ma,0);

	// fen 4kab2/4a4/4b4/5r3/3PR2P1/P3P4/9/4B4/8R/3AKABrc w - - 0 1
	if(EV_YOUR_CAN <= 0){
		if(my_shi_num == 2 && MY_SQ55 == mk){
			if(StoY(yma) MY_SMALL_EQL MY_RANK2){
				MY_EV_ADD(EV_MY_CAN * 16);
				Bitboard bmp = m_and(bb_my_pawn,MyUpBB[MY_RANK4]);
				// 马那边有兵
				if(StoX(yma) >= 0x4 && have_bit(bmp,RightBB[0x4])){
					MY_EV_ADD(EV_MY_CAN * 16);
				}
				if(StoX(yma) <= 0x4 && have_bit(bmp,LeftBB[0x4])){
					MY_EV_ADD(EV_MY_CAN * 16);
				}
			}
		}
	}
}
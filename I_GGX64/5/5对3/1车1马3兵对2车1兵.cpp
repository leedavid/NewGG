#ifndef END_my_m_MT_R_1che1ma3pawn_B_2che1pawn
#define END_my_m_MT_R_1che1ma3pawn_B_2che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1马3兵对2车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che1ma3pawn_B_2che1pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	
	// fen 3ak4/4a1r2/2P1b4/4N4/1r2P3P/p8/4R4/4B4/9/3AKAB2 b - - 0 1
	if(MY_SQ55 == mk){
		if(my_shi_num == 2 && my_xiang_num >= 1){
			if(EV_MY_CAN == 3){
				if(StoY(ypawn) MY_SMALL_EQL MY_RANK6 && abs(StoX(ypawn) - 0x4) >= 2){
					if((your_shi_num + your_xiang_num) <= 3){
						MY_EV_ADD(EV_MY_CAN * 16);
						Bitboard mgp = m_and(bb_my_pawn,MyUpBB[MY_RANK5]);
						MY_EV_ADD((sint16)count_1s(mgp) * 16);
					}
				}
			}
		}
	}
}
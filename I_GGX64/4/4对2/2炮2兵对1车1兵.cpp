#ifndef END_my_m_MT_R_2pao2pawn_B_1che1pawn
#define END_my_m_MT_R_2pao2pawn_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2ÅÚ2±ø¶Ô1³µ1±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByShi

// ºì·½2ÅÚ±ø,ºÚ·½³µ±ø
void my_m_MT_R_2pao2pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * Add_MAT_B_2pao1pawn_R_1che1pawn_ByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * Add_MAT_B_1che1pawn_R_2pao1pawn_ByShi[my_shi_num]);

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	// fen 4k4/4a4/4b3b/4C4/2P1P4/r8/5p3/4B4/4AC3/4KA3 w - - 0 1
	if((my_shi_num + my_xiang_num) <= 3){
		if(EV_YOUR_CAN >= 1){
		   MY_EV_SUB(32);
		}
		if(StoY(ypawn) == MY_RANK6){
			MY_EV_SUB(32);
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
				MY_EV_SUB(32);
			}
		}
	}
}


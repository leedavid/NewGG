#ifndef END_my_m_MT_R_1che2pao2pawn_B_1che1pao3pawn
#define END_my_m_MT_R_1che2pao2pawn_B_1che1pao3pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1³µ2ÅÚ2±ø¶Ô1³µ1ÅÚ3±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che2pao2pawn_B_1che1pao3pawn(typePOS &POSITION, EvalInfo &ei){

	// fen C1b1R4/3k5/5a3/9/8p/3p5/P2c4P/4BC3/2r3p2/4KA3 w - - 0 1
	if(my_shi_num <= 1 && my_xiang_num <= 1){
		if(EV_YOUR_CAN >= 2){
			if(have_bit(bb_your_pawn,
				m_and(RankBB_A[MY_RANK8],m_and(LeftBB[0x7],RightBB[0x1])))){
					MY_EV_SUB(EV_YOUR_CAN * 64);
			}
		}
	}

}

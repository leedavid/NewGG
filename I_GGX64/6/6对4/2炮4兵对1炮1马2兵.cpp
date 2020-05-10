#ifndef END_m_MT_R_2pao4pawn_B_1pao1ma2pawn
#define END_m_MT_R_2pao4pawn_B_1pao1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2ÅÚ4±ø¶Ô1ÅÚ1Âí2±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2pao4pawn_B_1pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yma = S90_from_piecelist(POSITION,your_ma,0);

	// fen 3k1ab2/4a4/4b1n2/8p/PC2P4/6PC1/8P/2p6/9/1c2KA3 b - - 0 1
	if(my_shi_num >= 1 && EV_YOUR_CAN <= 1){
		if(StoY(yma) MY_SMALL_EQL MY_RANK2 && EV_MY_CAN >= 2){
			MY_EV_ADD(EV_MY_CAN * 32);
			Bitboard bym = _mm_andnot_si128(MyUpBB[MY_RANK2],ei.attacked_by(your_ma));
			bym = _mm_andnot_si128(MY_ATTACK,bym);
			if(!m_have_bit(bym)){
				MY_EV_ADD(EV_MY_CAN * 24);
			}
		}
	}
}
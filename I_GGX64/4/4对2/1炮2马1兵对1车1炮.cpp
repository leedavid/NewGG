#ifndef END_my_m_MT_R_1pao2ma1pawn_B_1che1pao
#define END_my_m_MT_R_1pao2ma1pawn_B_1che1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1ÅÚ2Âí1±ø¶Ô1³µ1ÅÚ.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1pao2ma1pawn_B_1che1pao(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Square mk = my_king_pos;
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1Pao2MaXPawn_1Che1Pao_To_ByPawn[your_shi_num]);

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	// fen 4kab2/9/3ab4/r3N4/9/3N5/4P3c/C3B4/4A4/2BAK4 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK4){
			MY_EV_SUB(64);
		}
	}

	// fen 4k4/4a4/4ba3/PN7/2b6/2Nr5/1c2P4/4B1C2/4A4/4KAB2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(32);
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
			MY_EV_SUB(32);
		}
		if(have_bit(bb_my_ma,MyLowBB[MY_RANK4])){
			MY_EV_SUB(32);
		}
	}

	// fen 4k4/4a4/3ab3b/9/3n2p2/9/2n2R3/4cA2B/4A2C1/3K5 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if(EV_MY_CAN == 0){
			if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
				RETRUN_MUL(8);
			}
		}
	}
}

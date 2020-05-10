#ifndef END_my_m_MT_R_1ma2pawn_B_2pawn
#define END_my_m_MT_R_1ma2pawn_B_2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马2兵对2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int  ADD_1MaXPawn_2Pawn                       = 128;              //1马x兵对2兵的加分 
//const int  ADD_1MaXPawn_To_2Pawn_ByMaPawn[3]        = {96,  64, 32};
//const int  ADD_1MaXPawn_To_2Pawn_ByPawnSide[3]      = {80,  48, 16};


void my_m_MT_R_1ma2pawn_B_2pawn(typePOS &POSITION, EvalInfo &ei){
	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1MaXPawn_To_2Pawn_ByMaPawn[your_shi_num]);

	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1MaXPawn_To_2Pawn_ByPawnSide[my_shi_num]);

	MY_EV_ADD(ADD_1MaXPawn_2Pawn);

	Square mma = S90_from_piecelist(POSITION,my_ma,0);

	// fen 2ba5/4ak3/b8/2p1P4/9/1pP1n4/9/4BA3/4A4/2BK5 b - - 141 141
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(PB90(MY_SQ3A) == your_pawn){
			if(PB90(MY_SQ3C) == my_pawn && PB90(MY_SQ2A) == your_pawn){
				RETRUN_MUL(4);
			}
			if(PB90(MY_SQ38) == my_pawn && PB90(MY_SQ26) == your_pawn){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 2b1k4/4aP3/4ba3/9/2p6/6N2/2Pp5/B8/9/3K2B2 b
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(EV_MY_CAN <= 1 && have_bit(YOUR_ATTACK,bb_my_pawn)){
			if(PB90(MY_SQ0D) != my_pawn){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 9/3ka4/b3ba3/8p/9/4p1P1P/9/3ABAN2/9/2B2K3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		//
		if(EV_MY_CAN == 0 && StoY(mma) MY_LARGE_EQL MY_RANK6){
			if(PB90(MY_SQ33) == my_pawn && PB90(MY_SQ31) == your_pawn){
				RETRUN_MUL(4);
			}
			if(PB90(MY_SQ2F) == my_pawn && PB90(MY_SQ31) == your_pawn){
				RETRUN_MUL(4);
			}
		}
	}

}


#ifndef END_my_m_MT_R_1pao2pawn_B_1pawn
#define END_my_m_MT_R_1pao2pawn_B_1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1ÅÚ2±ø¶Ô1±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1pao2pawn_B_1pawn(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1PaoXPawn_1Pawn_ByPawnShi[your_shi_num]);

	MY_EV_ADD(ADD_1PaoXPawn_1Pawn);

	int mcan = EV_MY_CAN;

	Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);
	Square ypawn  = S90_from_piecelist(POSITION,your_pawn,0);
	
	if((your_shi_num + your_xiang_num) == 4){
		if(PB90(MY_SQ04) == your_king){
			if(PB90(MY_SQ15) == your_shi || PB90(MY_SQ17) == your_shi){
				// fen 3k1a3/9/5a2b/4c1p2/2b6/6P2/9/B2AB4/4Ap3/4K4 w - - 120 120
				if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 || StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
					if(PB90(MY_SQ26) == your_pawn && PB90(MY_SQ38) == my_pawn){
						RETRUN_MUL(2);
					}
					if(PB90(MY_SQ2A) == your_pawn && PB90(MY_SQ3C) == my_pawn){
						RETRUN_MUL(2);
					}

					// fen 4k4/4aP3/4ba2b/9/9/2B3P2/3p5/9/3KA4/7C1 w - - 120 	
					if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
						if(mcan <= 1){
							RETRUN_MUL(2);
						}
					}
				}				
			}
		}
	}

	// fen 4PPb2/5k3/9/9/9/9/9/4B4/6C2/2BK5 b - - 0 0
	if(my_shi_num == 0 && StoY(mpawn1) == MY_RANK0 && StoY(mpawn2) == MY_RANK0){
		RETRUN_MUL(2);
	}

	// fen 1P4b2/2P6/b3k4/9/9/9/7p1/4BA2B/3C5/3K5 b - - 0 1
	if(StoY(ypawn) == MY_RANK6 || StoY(ypawn) == MY_RANK5){
		if(your_xiang_num == 2 && StoY(yk) == MY_RANK2){
			if(StoY(mpawn1) == MY_RANK0 || StoY(mpawn2) == MY_RANK0){
				if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
					RETRUN_MUL(4);
				}
			}
		}
	}


}


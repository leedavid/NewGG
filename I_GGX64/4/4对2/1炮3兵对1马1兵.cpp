#ifndef END_my_m_MT_R_1PAO2PAWN_B_1MA
#define END_my_m_MT_R_1PAO2PAWN_B_1MA
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮3兵对1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int  ADD_1PaoXPawn_1Ma1Pawn_ByPawnShi[3]      = {96, 64, 32};             //炮x兵对1马1兵, 多兵的加分
//const int  ADD_1PaoXPawn_1Ma1Pawn_ByMaPanw[3]       = {96, 64, 32};             //炮x兵对1马1兵, 多兵的加分



void my_m_MT_R_1pao3pawn_B_1ma1pawn(typePOS &POSITION, EvalInfo &ei){
	
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1PaoXPawn_1Ma1Pawn_ByPawnShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1PaoXPawn_1Ma1Pawn_ByMaPawn[my_shi_num]);

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	// fen 4k4/3P5/9/8p/4N4/9/8c/2p1B4/3KAp3/3A5 b - - 7 7
	if(my_shi_num == 0 && my_shi_num == 0){
		if(StoY(ypawn) MY_SMALL StoY(mk)){
			MY_EV_SUB(MaPawn_PaoPawnPaoNoShiXiang);
		}
	}	
	Square yma  = S90_from_piecelist(POSITION,your_ma,0);
	Square mpao = S90_from_piecelist(POSITION,my_pao,0);

	// fen 4kab2/4a4/4b4/3Cp4/2n6/6P1P/P8/4B4/4A4/3K1A3 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2){
		if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK5])){
			MY_EV_SUB(32);
			if (EV_MY_CAN <= 2){
				MY_EV_SUB(32);
			}
			if (EV_YOUR_CAN >= 1 && StoY(ypawn) MY_SMALL_EQL MY_RANK5){
				MY_EV_SUB(32);
			}
		}
	}

	// fen 4k4/4a4/4ba3/p1P6/6b2/6B2/1N7/6p1B/3KAp3/1c3A3 w - - 120 120
	if(your_shi_num == 2 && your_xiang_num == 2 && pmok <= 2){
		if(StoY(mpao) MY_SMALL StoY(yma) && StoX(mpao) == StoX(yma)){
			if(PB90(MY_SQ3E) == my_pawn && PB90(MY_SQ3C) == your_pawn){
				if(PB90(MY_SQ22) == your_ma){
					RETRUN_MUL(4);
				}
			}
			if(PB90(MY_SQ36) == my_pawn && PB90(MY_SQ38) == your_pawn){
				if(PB90(MY_SQ1C) == your_ma){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 3a1k3/9/4ba3/1c7/p1p1N1b2/9/P6p1/4B4/4A4/3K1AB2 w - - 13 13
	int mcan = EV_MY_CAN;
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(mcan <= 1){
			RETRUN_MUL(4);
		}

		// fen 3akab2/9/4b4/p5p1p/9/6P1c/9/1N2B4/4A4/4KAB2 w - - 0 0
		if(mcan <= 2){
			if(PB90(MY_SQ2A) == your_ma && PB90(MY_SQ3E) == my_pawn){
				if(PB90(MY_SQ38) == my_pawn && PB90(MY_SQ26) == your_pawn){
					RETRUN_MUL(4);
				}
			}
			if(PB90(MY_SQ26) == your_ma && PB90(MY_SQ36) == my_pawn){
				if(PB90(MY_SQ3C) == my_pawn && PB90(MY_SQ2A) == your_pawn){
					RETRUN_MUL(4);
				}
			}
		}
	}	
	
	// fen 3a5/4ak3/4b4/2C4P1/P8/2P6/4n4/4B4/4p4/2BK5 b - - 0 1
	if(MY_SQ4C == ypawn && StoY(mk) == MY_RANK9 && my_xiang_num >= 1){		
		Bitboard m_at_k = m_and(POSITION.king_to_ma_attacks_bb(mk),
			ei.attacked_by(your_ma));
		//print_bb(m_at_k);
		m_at_k = _mm_andnot_si128(ei.attacked_by(my_pao),m_at_k);
		if(!m_have_bit(m_at_k)){
			MY_EV_ADD(EV_MY_CAN * 64);
			if(EV_MY_CAN >= 2){
				MY_EV_ADD(EV_MY_CAN * 32);
			}
		}
	}
}


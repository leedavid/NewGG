#ifndef END_my_m_MT_R_1che1pao1ma4pawn_B_2che
#define END_my_m_MT_R_1che1pao1ma4pawn_B_2che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮1马4兵对2车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int  ADD_1Che1Pao1MaXPawn_2CheOnly[3]         = {96, 64, 32};   //1 
//const int  ADD_1Che1Pao1MaXPawn_2CheOnly_Safe       =  96;

void my_m_MT_R_1che1pao1ma4pawn_B_2che(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Che1Pao1MaXPawn_2CheOnly[your_shi_num]);

	int mcan = EV_MY_CAN;

	Square mk = my_king_pos;

	if(my_shi_num == 2 && my_xiang_num == 2){
		if(StoY(mk) == MY_RANK9){
			EV_MY_SAFE = TRUE;
		}
	}

	if(my_shi_num == 2){
		if(MY_SQ55 == mk && PB90(MY_SQ4C) == my_shi){

			Square sq = SQ_END90;
			if(PB90(MY_SQ54) == my_shi){
				sq = Square(MY_SQ56);
			}
			if(PB90(MY_SQ56) == my_shi){
				sq = Square(MY_SQ54);
			}
			if(sq != SQ_END90){
				if(PB90(sq) == my_che || PB90(sq) == my_pao){
					EV_MY_SAFE = TRUE;
				}
				Bitboard bsq = POSITION.Rook_attacks_bb(sq);
				if(m_have_bit(
					m_and(bsq,m_or(bb_my_pao,
					bb_my_che)))){
						EV_MY_SAFE = TRUE;
				}
			}
		}
	}

	if(EV_MY_SAFE){
		MY_EV_ADD(mcan * ADD_1Che1Pao1MaXPawn_2CheOnly_Safe);
	}
}


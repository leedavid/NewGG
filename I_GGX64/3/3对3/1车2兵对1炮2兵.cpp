#ifndef END_my_m_MT_R_1che2pawn_B_1pao2pawn
#define END_my_m_MT_R_1che2pawn_B_1pao2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1³µ2±ø¶Ô1ÅÚ2±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1che2pawn_B_1pao2pawn(typePOS &POSITION, EvalInfo &ei){
	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheXPawn_To_1Pao2Pawn_ByPawn[your_shi_num]);

	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1Pao2Pawn_To_CheXPawn_ByPawn[my_shi_num]);

	//Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	//Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);

	//Square ypawn1 = S90_from_piecelist(POSITION,your_pawn,0);
	//Square ypawn2 = S90_from_piecelist(POSITION,your_pawn,1);

	int mcan = EV_MY_CAN;
	Square mche = S90_from_piecelist(POSITION,my_che,0);
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);

	// fen 4kab2/c3a4/4b4/p7p/9/9/P3R3P/3AB4/9/2BAK4 w - - 1 1
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0 && mcan == 0){
		if(StoY(ypao) MY_SMALL_EQL MY_RANK3){
			Bitboard peat = POSITION.Pao_Eat_bb(ypao);
			peat = m_and(peat,bb_my_pawn);

			Square p;
			while (pop_1st_bit_sq(peat, p)) {
				if(p == MY_SQ2D || p == MY_SQ36 || p == MY_SQ35 || p == MY_SQ3E){
					if(StoY(mche) == StoY(p)){
						RETRUN_MUL(2);
					}
				}
			}
		}
	}
}


#ifndef END_my_m_MT_R_2pao2pawn_B_2pao
#define END_my_m_MT_R_2pao2pawn_B_2pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮2兵对2炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_2pao2pawn_B_2pao(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2PaoXPawn_2Pao_ByPawnShi[your_shi_num]);

	// fen 4k4/4a4/4ba3/9/2c1c1b2/P1B3P2/5C3/3AB4/4A4/4K1C2 b - - 120 120
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		Bitboard p = m_and(bb_my_pawn,MyLowBB[MY_RANK4]);
		if(count_1s(p) == 2){
			p = m_and(RankBB_A[MY_RANK4],bb_your_pao);
			if(count_1s(p) == 2){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 2b2k3/6P2/4b1P2/5c3/4Cc3/2B6/9/9/9/3KC1B2 w - - 129 129
	if(my_shi_num == 0 && your_xiang_num == 2){
		Bitboard p = m_and(bb_my_pawn,MyUpBB[MY_RANK3]);
		if(count_1s(p) == 2){
			if(StoX(yk) == 0x5){
				Bitboard p1 = m_and(p,RightBB[0x5]);
				if(count_1s(p1) == 2){
					Bitboard p2 = m_and(bb_your_pao,FileBB_A[0x5]);
					if(count_1s(p2) == 2){
						RETRUN_MUL(4);
					}
				}
			}
			if(StoX(yk) == 0x3){
				Bitboard p1 = m_and(p,RightBB[0x3]);
				if(count_1s(p1) == 2){
					Bitboard p2 = m_and(bb_your_pao,FileBB_A[0x3]);
					if(count_1s(p2) == 2){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}	
}

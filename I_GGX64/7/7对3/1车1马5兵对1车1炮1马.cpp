#ifndef END_my_m_MT_R_1che1ma5pawn_B_1che1pao1ma
#define END_my_m_MT_R_1che1ma5pawn_B_1che1pao1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1马5兵对1车1炮1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1che1ma5pawn_B_1che1pao1ma(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheMaPawn_ChePao1pawn_ByPawnByShi[your_shi_num]);

	Square yma = S90_from_piecelist(POSITION,your_ma,0);

	// fen 2bk1ab2/2Nna4/9/7P1/1PP1R4/9/3rP3P/4B3B/4K4/3c5 b - - 0 1
	if(StoY(yma) MY_SMALL_EQL MY_RANK2){
		MY_EV_ADD(EV_MY_CAN * 8);
		Bitboard lp = My_get_connect_Pawn(POSITION);
		if(m_have_bit(lp)){
			MY_EV_ADD(32);
			if(my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
				MY_EV_ADD(EV_MY_CAN * 8);
			}
		}

		// 对方的马的所有步子给我方控制了？
		Bitboard ymAtt= _mm_andnot_si128(m_or(MyUpBB[MY_RANK1],ei.attacked_by(MY_COLOR)),ei.attacked_by(your_ma));
		if(!m_have_bit(ymAtt)){
			MY_EV_ADD(EV_MY_CAN * 8);
		}
	}

	

}
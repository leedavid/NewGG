
#ifndef END_my_m_MT_R_1ma1pao3pawn_B_1che1pawn
#define END_my_m_MT_R_1ma1pao3pawn_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马3兵对1车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByShi

// 红方马炮兵,黑方车兵
void my_m_MT_R_1ma1pao3pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	your_m_MT_R_1che1pawn_B_1pao1ma(POSITION,ei);	

	if(ei.mul <= 2){
		ei.rsafe = TRUE;
	}
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByShi[your_shi_num]);

	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * Add_MAT_B_1che1pawn_R_1ma1pao1pawn_ByShi[my_shi_num]);

	Bitboard lp = My_get_connect_Pawn(POSITION);
	// fen 5k3/r5PP1/9/4PP3/2P6/5N3/6C2/9/4Ap3/4KA3 w
	// fen 5k3/r5PP1/9/4PP3/2P6/5N3/3C5/9/4Ap3/4KA3 w
	//print_bb(lp);
	if(m_have_bit(m_and(lp,MyLowBB[MY_RANK2]))){
		//print_bb(m_and(lp,MyLowBB[MY_RANK2]));
		MY_EV_ADD(Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByConPawn);
	}

	// fen 2bak4/4a4/4b1N2/8p/6P2/9/P7P/9/4C4/2rAKA3 b - - 0 1
	if (EV_YOUR_CAN == 0){
		if (my_shi_num == 2 && StoY(mk) == MY_RANK9){
			MY_EV_ADD(EV_MY_CAN * 32);
		}

		// fen 3k1ab2/4a4/4b4/2p6/5N1Cr/2P1P4/P8/4B4/9/2B1K4 w - - 0 1
		if (my_xiang_num == 2){
			if (PB90(MY_SQ2F) == my_pawn && PB90(MY_SQ1D) == your_pawn){
				MY_EV_ADD(128);
				MY_EV_ADD(EV_MY_CAN * 32);
			}
			else if (PB90(MY_SQ33) == my_pawn && PB90(MY_SQ21) == your_pawn){
				MY_EV_ADD(128);
				MY_EV_ADD(EV_MY_CAN * 32);
			}
		}
	}
}


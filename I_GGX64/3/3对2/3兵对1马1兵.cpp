#ifndef END_my_m_MT_R_3pawn_B_1ma1pawn
#define END_my_m_MT_R_3pawn_B_1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "3兵对1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_3pawn_B_1ma1pawn(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_3pawn_MaXPawn_ShiAdd[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1MaXPawn_3pawn_ShiAdd[my_shi_num]);

	MY_EV_SUB(ADD_1MaXPawn_3Pawn);   //马兵方的别外加分
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	// fen 3a5/3k1P3/2P6/4P4/9/2B6/6n2/5K3/3p5/6B2 b - - 0 1
	if(your_shi_num <= 1){
		if(StoY(ypawn) MY_LARGE_EQL StoY(mk)){
			MY_EV_ADD(32);
			if(have_bit(bb_my_pawn,RankBB_A[MY_RANK3])){
				MY_EV_ADD(32);
				MY_EV_ADD(EV_MY_CAN * 32);
			}
		}
	}

	//
	if(your_shi_num >= 1 || EV_MY_CAN <= 2){
		EV_YOUR_SAFE = true;
	}
	// fen 3k1a3/5P3/3ab3b/9/7P1/2B1P4/4pn3/5A3/4A4/3K5 b - - 0 1
	if(EV_YOUR_SAFE && EV_MY_CAN >= 1){
		if(my_shi_num == 2 && my_xiang_num >= 1){
			if(StoY(my_king_pos) MY_LARGE_EQL MY_RANK8){
				RETRUN_MUL(4);
			}
		}
	}

	Bitboard lp = My_get_connect_Pawn(POSITION);
	// fen 2b1k1b2/3Pa4/3a5/4PP3/9/4n1B2/9/3A5/3K1p3/2B6 w - - 0 1
	if (have_bit(lp, RankBB_A[MY_RANK3])){
		MY_EV_ADD(64);
		if (my_shi_num >= 1){
			MY_EV_ADD(64);
		}
	}
	// fen 4ka3/4aP3/9/4PP3/3n5/6B2/6p2/9/4A4/4K1B2 w - - 0 1
	if(EV_YOUR_SAFE){		
		if(have_bit(lp,RankBB_A[MY_RANK3])){
			if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) MY_LARGE_EQL MY_RANK8){
				RETRUN_MUL(8)
			}
		}
	}
}


//}
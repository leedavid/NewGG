#ifndef END_my_m_MT_R_1pao1ma2pawn_B_2ma1pawn
#define END_my_m_MT_R_1pao1ma2pawn_B_2ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马2兵对2马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1pao1ma2pawn_B_2ma1pawn(typePOS &POSITION, EvalInfo &ei){
	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1pao1maXpawn_To_2ma1pawn_ByPs[your_shi_num]);

	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1pao1maXpawn_To_2ma1pawn_ByPs[my_shi_num]);

	MY_EV_ADD(ADD_1pao1maXpawn_To_2ma1pawn);

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mpao  = S90_from_piecelist(POSITION, my_pao, 0);

	// fen 4kab2/4a4/4b4/4n1C1p/9/6N2/P3P4/8n/4A4/4KA3 w - - 0 1
	if(StoY(ypawn) MY_SMALL_EQL MY_RANK4){
		MY_EV_ADD(EV_MY_CAN * 16);
	}

	// fen 5ab2/3ka1N2/4b4/5P3/4C2n1/3n5/P8/3AB4/2p1A4/2BK5 w - - 0 1
	if((my_shi_num + my_xiang_num) >= 2){
		MY_EV_ADD(EV_MY_CAN * 16);
	}

	// fen 2bak4/4a4/2n5b/p4C2N/9/4P4/8P/1n7/4A4/2B1K1B2 b - - 0 1
	// 有边兵也要减分
	if(have_bit(bb_your_pawn,LeftBB[0x1])){
		MY_EV_ADD(EV_MY_CAN * 16);		
	}
	if(have_bit(bb_your_pawn,RightBB[0x7])){
		MY_EV_ADD(EV_MY_CAN * 16);
	}

	// fen 4k4/2PPa4/3ab4/9/2b1n4/9/5pn1N/4B4/3KA3C/2B6 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2){
		if (StoY(yk) == MY_RANK0 && StoY(ypawn) == MY_RANK6){
			if (!have_bit(MyLowBB[MY_RANK1], bb_my_pawn)){
				if (PB90(MY_SQ15) == your_shi
					&& !have_bit(RightBB[0x4], bb_my_pawn)){
					MY_EV_SUB(64);
				}
				if (PB90(MY_SQ17) == your_shi
					&& !have_bit(LeftBB[0x4], bb_my_pawn)){
					MY_EV_SUB(64);
				}
			}
		}
		// fen 2b1k4/4aP3/3a2N1b/p5n2/9/P2Cn4/9/4BA3/4A4/4K1B2 b - - 0 1
		if (StoY(yk) == MY_RANK0 && EV_MY_CAN <= 1){
			if (abs(StoY(mpao) - MY_RANK4) <= 1){
				if (PB90(MY_SQ2D) == my_pawn && MY_SQ1B == ypawn){
					if (have_bit(bb_my_pawn, RightBB[0x4])){
						MY_EV_SUB(128);
					}
				}
				if (PB90(MY_SQ35) == my_pawn && MY_SQ23 == ypawn){
					if (have_bit(bb_my_pawn, LeftBB[0x4])){
						MY_EV_SUB(128);
					}
				}
			}
		}
	}
	
	// fen 4k4/3Pa4/3aNn3/3C5/1Pb6/9/3n1p3/3A4B/4A4/2B2K3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(PB90(MY_SQ16) == my_ma){
			if(!have_bit(bb_my_pawn,RightBB[0x3])){
				if(PB90(MY_SQ15) == your_shi && PB90(MY_SQ17) == your_ma){
					if(PB90(MY_SQ1E) == my_pao && PB90(MY_SQ26) == your_xiang){
						MY_EV_SUB(168);
					}
				}
			}
			if(!have_bit(bb_my_pawn,LeftBB[0x5])){
				if(PB90(MY_SQ17) == your_shi && PB90(MY_SQ15) == your_ma){
					if(PB90(MY_SQ20) == my_pao && PB90(MY_SQ2A) == your_xiang){
						MY_EV_SUB(168);
					}
				}
			}
		}
	}

	// fen 2ba1k3/4a2P1/4b4/7np/7N1/6B1P/9/5A1nB/4A3C/4K4 w - - 0 1
	//  吃死一个兵
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if (EV_MY_CAN <= 1){
			MY_EV_SUB(32);
			Bitboard up = m_and(bb_my_pawn, MyUpBB[MY_RANK2]);
			if (have_bit(up, LeftBB[0x2]) || have_bit(up, RightBB[0x6])){
				MY_EV_SUB(32);
				if (StoY(mpao) MY_LARGE_EQL MY_RANK7){
					if (PB90(MY_SQ35) == my_pawn && PB90(MY_SQ23) == your_pawn){
						if (PB90(MY_SQ46) == your_ma){
							if (StoX(mpao) == 0x8){
								RETRUN_MUL(6);
							}
						}
					}
					if (PB90(MY_SQ2D) == my_pawn && PB90(MY_SQ1B) == your_pawn){
						if (PB90(MY_SQ40) == your_ma){
							if (StoX(mpao) == 0x0){
								RETRUN_MUL(6);
							}
						}
					}
				}
			}
		}
	}

}


#ifndef END_my_m_MT_R_1che1pao1pawn_B_1che2pawn
#define END_my_m_MT_R_1che1pao1pawn_B_1che2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮1兵对1车2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che1pao1pawn_B_1che2pawn(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_ChePaoXPawn_VS_1Che2Pawn_ByShi[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1Che2Pawn_VS_ChePaoXPawn_ByShi[my_shi_num]);

	int mcan = EV_MY_CAN;
	int ycan = EV_YOUR_CAN;


	Square mche = S90_from_piecelist(POSITION,my_che,0);
	Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	Square yche = S90_from_piecelist(POSITION,your_che,0);
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	if(ycan <= 1){
		if(my_shi_num >= 1 && my_xiang_num >= 1){
			EV_MY_SAFE = TRUE;
		}
	}

	//  fen 4k4/9/3Rba2b/6r2/P8/9/9/4p4/1C7/3K5 b - - 0 1
	if (my_shi_num <= 1 && my_xiang_num == 0) {
		if (EV_MY_CAN == 0) {
			if (EV_YOUR_CAN >= 1) {
				MY_EV_SUB(64);
				if (abs(StoX(mpawn) - 0x4) == 4) {
					MY_EV_SUB(32);
				}
				if (have_bit(bb_your_pawn, RankBB_A[StoY(mk) MY_SUB 1])) {
					MY_EV_SUB(32);
				}
				if (StoY(mpao) MY_SMALL_EQL MY_RANK4) {
					MY_EV_SUB(32);
				}
			}
		}
	}

	// fen 3ak4/9/3a5/4C3p/6P2/2B1R4/5r3/3p5/4K4/9 w - - 0 1
	if (my_shi_num == 0 && my_xiang_num <= 1){
		if (EV_YOUR_CAN >= 2 && (your_shi_num + your_xiang_num) >= 2){
			if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK4])){
				if (have_bit(ymp, MyLowBB[MY_RANK6])){
					MY_EV_SUB(32);
					if (StoY(yche) MY_LARGE_EQL MY_RANK5){
						MY_EV_SUB(32);
					}
				}
			}
		}
	}

	// fen 4k4/4a4/5a3/4R4/9/1r7/P4pp2/9/4A4/3CK4 w - - 0 1
	if (my_shi_num <= 1){
		if (Your_pawn_already_over_river(POSITION) >= 2){
			MY_EV_SUB(16);
			if (have_bit(bb_my_pawn, LeftBB[0x1])){
				MY_EV_SUB(16);
			}
			if (have_bit(bb_my_pawn, RightBB[0x7])){
				MY_EV_SUB(16);
			}
		}
	}

	// fen 3a5/4k4/2R6/9/9/4C1B1P/2pp5/4BA3/3K5/5r3 w - - 0 1
	if(my_shi_num == 0){
		MY_EV_SUB(EV_YOUR_CAN * 32);
	}

	if(my_shi_num <= 1){
		Bitboard lp = Your_get_connect_Pawn(POSITION);
		if(have_bit(lp,MyLowBB[MY_RANK4])){
			MY_EV_SUB(64);
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK4 && abs(StoX(mpawn) - 0x4) >= 3){
				MY_EV_SUB(64);
			}
		}
	}

	// fen 9/3P5/5k3/8R/8P/4p4/4c4/3A5/4K4/5rB2 b - - 0 1
	if (my_shi_num == 0 && my_xiang_num == 0){
		Bitboard yp = m_and(bb_your_pawn, m_and(MyLowBB[MY_RANK4],MyUpBB[MY_RANK9]));
		if (count_1s(yp) == 2){
			MY_EV_SUB(32);
			if (StoY(mpawn) MY_LARGE_EQL MY_RANK4 && StoY(mpao) MY_SMALL_EQL StoY(mpawn)){
				if (your_shi_num >= 1){
					MY_EV_SUB(32);
				}
			}
		}
	}

	//Square yk = your_king_pos;
	// fen 3a1kb2/4a4/4b4/4R4/p3Cr3/4p4/P8/B8/3KA4/5AB2 w
	// fen 3a1kb2/4a4/4b4/4R4/p3Cr3/4p1P2/P8/B8/3KA4/5AB2 w - - 123 123
	if(mcan == 0 && My_pawn_already_over_river(POSITION) == 0){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if(PB90(MY_SQ1F) == my_che && PB90(MY_SQ28) == my_pao && PB90(MY_SQ31) == your_pawn){
				if(ycan <= 1){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 4k4/9/4b4/8p/9/2B5P/4rCR2/4BA3/3pAK3/9 b - - 120 120
	//车炮给牵制住了.
	if(your_shi_num > 0 || your_xiang_num > 0 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(mcan == 0 && EV_MY_SAFE){
			if(isStringByChe(POSITION,mche,mpao,yche)){
				RETRUN_MUL(2);
			} //m_have_bit()
		} //have_bit()
	}

	// fen 4kab2/4a4/4b4/8p/p8/9/1r6P/1CR5B/4A4/4KAB2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(EV_MY_SAFE){
			if(EV_MY_CAN == 0){
				MY_EV_SUB(64);
				if(abs(StoX(mpawn) - 0x4) == 4){
					MY_EV_SUB(32);
					if(StoY(mpao) MY_LARGE_EQL MY_RANK1 && StoX(mpao) != 0x4){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 2bk5/4a4/3ab4/8p/2p6/4R2CP/9/9/5K3/7r1 b - - 0 1
	if(EV_YOUR_CAN <= 1 && EV_MY_CAN == 0){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK4])){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 2bk4C/4a4/3ab4/9/2p5p/4R3P/9/9/8r/4K4 b
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK4])){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
				if(my_xiang_num == 0 && bit_is_set(ei.attacked_by(your_che),mpawn)){
					if(StoY(mche) == StoY(mpawn)){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}
}


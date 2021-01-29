#ifndef END_my_m_MT_R_1che1pao2pawn_B_1che1ma1pawn
#define END_my_m_MT_R_1che1pao2pawn_B_1che1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1炮2兵对1车1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

void my_m_MT_R_1che1pao2pawn_B_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_ChePaoPawn_CheMa1pawn_ByPawnByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_CheMaPawn_ChePao1pawn_ByPawnByShi[my_shi_num]);
	Square mpao = S90_from_piecelist(POSITION,my_pao,0);

	int ycan = EV_YOUR_CAN;
	Square yche = S90_from_piecelist(POSITION,your_che,0);
	Square mche = S90_from_piecelist(POSITION,my_che,0);
	Square yma  = S90_from_piecelist(POSITION,your_ma,0);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) == MY_RANK9){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK6){
			EV_MY_SAFE = TRUE;
		}
	}

	// fen 2bk5/5R3/4b4/9/C8/6P2/8P/4BKn2/8r/3p2B2 w - - 0 1
	if(my_shi_num == 0){
		if(StoY(yma) MY_LARGE_EQL MY_RANK5){
			MY_EV_SUB(32);
		}
		if(have_bit(bb_your_pawn,MyLowBB[MY_RANK4])){
			MY_EV_SUB(32);
		}
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
			MY_EV_SUB(32);
		}
	}

	//  fen 5P3/9/3k4b/6R2/9/4r1n1p/P8/9/3C5/5K3 w - - 0 1
	if (my_shi_num == 0 && my_xiang_num == 0) {
		MY_EV_SUB(EV_YOUR_CAN * 32);
		if (have_bit(bb_my_pawn, MyUpBB[MY_RANK1])) {
			MY_EV_SUB(32);
		}
		if (StoY(yma) MY_LARGE_EQL MY_RANK5) {
			MY_EV_SUB(64);
		}
		// 有边兵
		if (have_bit(bb_my_pawn, m_or(FileBB_A[0x0], FileBB_A[0x8]))) {
			MY_EV_SUB(32);
		}
	}


	//  fen 2bak4/4a4/4b4/6RC1/9/P3p1Br1/1n6P/9/4A4/2BK1A3 w - - 0 1
	if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9) {
		MY_EV_ADD(32 * EV_MY_CAN);
	}


	// fen 4ka3/4a1r2/3nb4/p8/6b2/2P6/P5R2/8C/4A4/2BAK1B2 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
		if (EV_MY_CAN <= 1 && !have_bit(bb_my_pawn, MyUpBB[MY_RANK5])){
			MY_EV_SUB(32);
			if (StoY(yma) MY_LARGE_EQL MY_RANK2){
				MY_EV_SUB(32);
			}
		}
	}

	// fen 3ak1b2/3Pa4/4b4/9/5r3/8P/4R4/5C3/1pn1A4/2BA1K3 b - - 0 1
	if (my_shi_num == 2 && my_xiang_num >= 1){
		if (StoY(mk) MY_LARGE_EQL MY_RANK8){
			MY_EV_ADD(16);
			if (abs(StoX(ypawn) - 0x4) >= 3 && !IsOnSameSide(ypawn, mk)){
				MY_EV_ADD(32);
				MY_EV_ADD(EV_MY_CAN * 32);
			}
		}
	}



	// fen 2bak4/4a4/4b4/9/4n4/5r2p/P1R1P4/4B4/4A3C/3AK1B2 w - - 0 1
	if(have_bit(bb_my_pawn,MyUpBB[MY_RANK5]) && (your_shi_num + your_xiang_num) <= 3){

		// fen 4kab2/4a4/4b4/C3p4/5r3/6R2/P7P/3An4/3KA4/9 w - - 0 1
		if(my_shi_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			if(StoY(ypawn) MY_SMALL_EQL MY_RANK5){
				MY_EV_ADD(EV_MY_CAN * 16);
			}
		}

		// fen 4kab2/9/3ab4/C2r5/P5n2/9/4P4/3R5/4A3p/4KA3 b - - 0 1
		MY_EV_ADD(EV_MY_CAN * 24);


		if(my_shi_num == 2 && StoY(mk) == MY_RANK9){
			if(abs(StoX(ypawn) - StoX(mk)) >= 3 || !IsOnSameSide(mk,ypawn)){
				MY_EV_ADD(32);
			}
		}

		// fen 2b1ka3/4a4/9/p8/4P2R1/8P/2r4n1/3A1A3/5K3/3C5 b - - 0 1
		if(my_shi_num == 2 || my_xiang_num == 2){
			if(StoY(ypawn) MY_SMALL_EQL MY_RANK4 || abs(StoX(ypawn) - 0x4) == 4){
				if(StoY(mk) MY_LARGE_EQL MY_RANK8 && StoY(mpao) MY_LARGE_EQL MY_RANK7){
					MY_EV_ADD(EV_MY_CAN * 16);
				}
			}
		}
		// fen 5ab2/4k4/3ab4/C8/P3R1n2/9/4P4/3r4p/4A4/4KA3 b - - 0 1
		if(my_shi_num == 2 && StoY(mk) == MY_RANK9){
			MY_EV_ADD(EV_MY_CAN * 16);
			if(abs(StoX(ypawn) - 0x4) >= 3){
				MY_EV_ADD(EV_MY_CAN * 8);

				if(MY_SQ55 == mk){
					if(StoX(ypawn) > 0x4 && PB90(MY_SQ56) == my_shi){
						MY_EV_ADD(EV_MY_CAN * 16);
					}
					if(StoX(ypawn) < 0x4 && PB90(MY_SQ54) == my_shi){
						MY_EV_ADD(EV_MY_CAN * 16);
					}
					if(StoY(yma) MY_SMALL_EQL MY_RANK4){
						MY_EV_ADD(EV_MY_CAN * 16);
					}
				}
			}
		}
	}

	// fen 3k4C/4a3P/b3ba3/p8/9/P1r6/1n7/B2A3R1/4A4/3K5 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(EV_MY_CAN <= 1 && my_xiang_num <= 1){
			if(!have_bit(bb_my_pawn,m_and(LeftBB[0x8],RightBB[0x0]))){
				MY_EV_SUB(64);
			}
		}
	}

	// fen 5R3/3kaPC2/b2a2n2/9/p1b2r3/9/P8/B3BA3/4A4/5K3 b - - 0 1
	if(EV_YOUR_CAN <= 0){
		if(my_shi_num == 2 || my_xiang_num == 2){
			if(StoY(mk) MY_LARGE_EQL MY_RANK8 && !IsOnSameSide(mk,yma)){
				EV_MY_SAFE = TRUE;
			}
		}
	}

	// fen 3ak4/4a4/1c7/p3r3p/7R1/2N6/P8/4B4/4A4/2BAK4 w - - 4 4
	
	if(StoY(ypawn) MY_SMALL MY_RANK5 && ycan == 0 && StoY(mk) == MY_RANK9){
		if(my_shi_num == 2 || my_xiang_num == 2){
			MY_EV_ADD(32);
		}
	}

	// fen 3P2b2/4k4/5a3/8p/4n4/8P/4r4/2R1B4/3CA4/4K4 b黑车5平4有???这局感觉是红好多.红炮已经回家了.
	if(EV_YOUR_CAN == 0 && (my_shi_num + my_xiang_num) >= 2 && StoY(mk) == MY_RANK9){
		MY_EV_ADD(32);
		if(StoY(mpao) MY_LARGE_EQL MY_RANK6 && (your_shi_num + your_xiang_num) <= 2){
			MY_EV_ADD(32);
		}
	}

	// fen 4kab2/4a4/4b4/P5R2/9/3Cn1B1P/5r3/4B4/2p1A4/4KA3 w - - 0 1
    if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if(abs(StoX(ypawn) - StoX(mk)) >= 2){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	// fen 2b1ka3/4a4/4b4/8C/5P1P1/1p7/2Pn4r/3R5/4A4/3AK4 w - - 0 1
	if(my_shi_num == 2 && MY_SQ55 == mk){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK5){
			MY_EV_ADD(32);
		}
		MY_EV_ADD(EV_MY_CAN * 16);
	}
	// fen 2bak4/4a4/4b4/9/P6P1/9/3np4/B2C3r1/1R2A4/4KA3 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9){
		if(StoY(mpao) MY_LARGE_EQL MY_RANK7 && StoY(ypawn) MY_SMALL_EQL MY_RANK6){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	// fen 5R3/3kaPC2/b2a2n2/9/p1b2r3/9/P8/B3BA3/4A4/5K3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && EV_MY_CAN <= 1){
		if(StoX(yk) == 3 && PB90(MY_SQ05) == my_che 
			&& PB90(MY_SQ0E) == my_pawn && StoX(yche) == 0x5){
				MY_EV_SUB(96);
				if(bit_is_set(ei.attacked_by(your_ma),yche)){
					MY_EV_SUB(96);
					if(EV_MY_SAFE){
						RETRUN_MUL(8);
					}
				}
		}
		if(StoX(yk) == 5 && PB90(MY_SQ03) == my_che 
			&& PB90(MY_SQ0C) == my_pawn && StoX(yche) == 0x3){
				MY_EV_SUB(96);
				if(bit_is_set(ei.attacked_by(your_ma),yche)){
					MY_EV_SUB(96);
					if(EV_MY_SAFE){
						RETRUN_MUL(8);
					}
				}
		}
	}

	// fen 2b2k3/4a4/4ba3/1C6p/5r3/P8/5n2P/4B4/4A2R1/4KAB2 w - - 0 1
    if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(EV_MY_CAN <= 1 && StoY(yma) MY_LARGE_EQL MY_RANK4){
				if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK4])){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 4ka3/4a4/4b3b/7np/4r4/8P/P7R/3C4B/4A4/4KA3 b - - 0 1
	if(EV_MY_CAN <= 1 && !have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if((my_shi_num + my_xiang_num) >= 2 && EV_YOUR_CAN == 0){
				if(have_bit(ei.attacked_by(your_ma),bb_my_pawn)){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 3ak1b2/4a4/9/p8/9/P5B2/4P1n1R/4B4/4A4/4KA1rC b - - 0 1
	if (EV_MY_SAFE){
		if ((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
			if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK5])){
				if (bit_is_set(ei.attacked_by(your_che), mpao)){
					if (bit_is_set(ei.attacked_by(my_che), mpao)){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 2bak4/4a4/4b4/9/4n4/5r2p/P1R1P4/4B4/4A3C/3AK1B2 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 1Cbak4/4a4/1P7/2r5p/2n6/8P/2R6/9/4A4/2B1KA3 b - - 0 1
	if(EV_MY_CAN <= 1 && your_shi_num == 2 && your_xiang_num >= 1 && MY_SQ04 == yk){
		Bitboard mp = m_and(bb_my_pawn,MyUpBB[MY_RANK3]);
		if(StoY(yche) != MY_RANK0){
			if(StoX(mpao) <= 0x1 && StoX(yche) == 0x2){
				if(have_bit(mp,LeftBB[0x2])){					
					if(StoY(mche) MY_LARGE_EQL MY_RANK4 && EV_MY_SAFE){
						RETRUN_MUL(8);
					}
				}
			}
			if(StoX(mpao) >= 0x7 && StoX(yche) == 0x6){
				if(have_bit(mp,RightBB[0x6])){				
					if(StoY(mche) MY_LARGE_EQL MY_RANK4 && EV_MY_SAFE){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

}


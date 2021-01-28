#ifndef END_my_m_MT_R_1CHE1PAWN_B_1CHE
#define END_my_m_MT_R_1CHE1PAWN_B_1CHE
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1兵对1车xxxxxxx.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//红方一车一兵, 黑方一车
void my_m_MT_R_1CHE1PAWN_B_1CHE(typePOS *POSITION, EvalInfo *ei){

	int mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	int mche  = S90_from_piecelist(POSITION,my_che,0);
	int yche  = S90_from_piecelist(POSITION,your_che,0);

	Bitboard yCheATT = rook_attacks_bb(yche,BitboardOCC);
	
	// <<象棋残局例典>> page295 车高兵仕例和车2仕
	if(your_shi_num == 2){
		if(StoY(your_king_pos) == MY_RANK0 
			|| StoY(mpawn) MY_SMALL StoY(your_king_pos)){
				if(StoX(mpawn) < 0x4){
					if(PB90[MY_SQ03] == your_shi){
						MY_EV_SUB(64);
					}
				}
				if(StoX(mpawn) > 0x4){
					if(PB90[MY_SQ05] == your_shi){
						MY_EV_SUB(64);
					}
				}
				RETRUN_MUL(1);
		}
	}

	MY_EV_ADD(196);  // 有兵方的加分.

	
	if(your_shi_num >= 1 && your_xiang_num >= 1){
		
		// fen 3ak1b2/9/9/9/5r3/2P4R1/9/4B3B/4A4/4KA3 r cmd eval cmd:
		// 对方的兵没有过河
		if(StoY(your_king_pos) == MY_RANK0){
			if(StoY(mpawn) MY_LARGE MY_RANK4){
				RETRUN_MUL(1);
			}
		}

		//fen 4ka3/1P1r5/4b4/9/9/1R7/9/3A5/9/3K5 w - - 26 26
		//车兵对车仕象
		if(your_king_pos == MY_SQ04){
			if(StoY(mche) MY_LARGE StoY(yche)){
				if((StoX(mpawn) <= 0x02 && PB90[MY_SQ05] == your_shi)
					|| (StoX(mpawn) >= 0x06 && PB90[MY_SQ03] == your_shi)){
						if(XYtoS(StoX(mche),StoY(yche)) == mpawn){
						     RETRUN_MUL(1)
						}
				}
			}
		}

		//fen 3ak4/9/4b4/5P3/9/9/1R7/9/4K4/5r3 w - - 196 196
		if(your_king_pos == MY_SQ04){
			if(my_shi_num == 0 && my_xiang_num == 0){
				if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
					RETRUN_MUL(1);
				}
			}
		}
	} // if(your_shi_num >= 1 && your_xiang_num >= 1){

	// fen 3k5/9/9/4R4/9/2B6/9/3A5/1r1K1p3/9 w - - 211 211
	// 单车领高仕
	if(your_shi_num != 0 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
		if(StoY(yche) MY_LARGE MY_RANK2){
			// R
			if(StoX(mpawn) > 0x4 && PB90[MY_SQ15] == your_shi){
				if(StoX(mche) != 0x3){
					if(m128_is_have_bit(
						m128_bb_and_bb(yCheATT,_mm_load_si128 ((__m128i*)File3BB)))){
							RETRUN_MUL(1);
					}
				}
			}
			// L
			if(StoX(mpawn) < 0x4 && PB90[MY_SQ17] == your_shi){
				if(StoX(mche) != 0x5){
					if(m128_is_have_bit(
						m128_bb_and_bb(yCheATT,_mm_load_si128 ((__m128i*)File5BB)))){
							RETRUN_MUL(1);
					}
				}
			}
		}
	}

	// 车兵难胜单缺仕	
	if(your_xiang_num == 2 && your_shi_num >= 1 && StoY(your_king_pos) == MY_RANK0){
		// fen 2b1k4/9/4b4/9/9/6R2/5r3/4B4/4A2p1/4K1B2 w - - 41 41  
		if(ABS(StoX(mpawn) - 0x4) > 2 || StoY(mpawn) != MY_RANK1){
			RETRUN_MUL(1);
		}
		// fen 4k1b2/4a4/4b4/9/5R3/9/9/4B4/6p2/2B1KA2r w - - 121 121
		if(StoX(mpawn) >= 0x5 && StoX(mche) >= 0x6){
			if(PB90[MY_SQ05] == your_shi && StoX(yche) == 0x5){
				RETRUN_MUL(1);
			}
		}
		if(StoX(mpawn) <= 0x3 && StoX(mche) <= 0x2){
			if(PB90[MY_SQ03] == your_shi && StoX(yche) == 0x3){
				RETRUN_MUL(1);
			}
		}

		//fen 3k5/4a4/9/9/2b2r3/9/9/B3B4/4Ap1R1/4K4 w - - 124 124

	}// 车兵难胜单缺仕	
}


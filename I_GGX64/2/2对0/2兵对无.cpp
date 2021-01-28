#ifndef END_my_m_MT_R_2PAWN
#define END_my_m_MT_R_2PAWN
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2兵对无.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int Pawn_Add_ok   = 64;
//const int Pawn_Add_bad  = 16;
// fen 9/5PP2/3k5/9/9/6B2/9/B8/9/4K4 w
//红方二兵，对方 0 attacker
void my_m_MT_R_2PAWN(typePOS &POSITION, EvalInfo &ei){

	BothOnlyPawnEval(POSITION, ei);

	Bitboard p = bb_my_pawn;

	Square yk = your_king_pos;

	// fen 3ak1b2/4a4/9/9/2b6/9/6p2/4BA2B/2p6/3K1A3 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2){
		MY_EV_SUB(128);
		if (StoX(yk) == 0x3){
			if (!have_bit(bb_your_shi, LeftBB[0x4])){
				MY_EV_SUB(196);
			}
		}
		if (StoX(yk) == 0x5){
			if (!have_bit(bb_your_shi, RightBB[0x4])){
				MY_EV_SUB(196);
			}
		}
	}


	int dp = (int)count_1s(p, RankBB_A[MY_RANK0]);

	// fen 2bk2P1P/9/9/9/9/9/9/B8/9/2B1K4 w
	if (dp == 2){
		RETRUN_MUL(1);
	}// fen fen 9/4P1P2/3k5/9/9/6B2/9/B8/9/4K4 b
	// fen 2b3P2/3k5/6P2/9/9/9/9/B8/9/2B1K4 w
	// fen 9/5PP2/3k5/9/9/6B2/9/B8/9/4K4 w
	if (dp == 1){
		if (your_xiang_num != 0){
			RETRUN_MUL(1);
		}
	}

	Square mpawn1 = S90_from_piecelist(POSITION, my_pawn, 0);
	Square mpawn2 = S90_from_piecelist(POSITION, my_pawn, 1);

	if ((your_shi_num + your_xiang_num) >= 3){
		MY_EV_SUB(128);
	}
	else if (your_shi_num >= 1 && your_xiang_num >= 1){
		MY_EV_SUB(64);
	}

	// <<象棋残局例典>> 22页 双高兵例和单仕象, 不能形成二个兵在一边,就胜了. 
	if (your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) != MY_RANK0){
		RETRUN_MUL(1);
	}
	//对方有仕相，则只要将在兵上就和了
	if (your_xiang_num >= 1){
		dp = (int)count_1s(p,MyUpBB[StoY(yk)]);
		if (dp == 2){ // fen 2b6/5PP2/4k4/9/9/9/9/B3B4/9/4K4 w
			RETRUN_MUL(1);
		}
	}

	// fen 3k2b2/2P1aP3/4ba3/9/9/2B6/9/9/9/2BA1K3 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2){
		if (!have_bit(bb_my_pawn, MyLowBB[MY_RANK1])){
			if (StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi){
				RETRUN_MUL(1);
			}
			if (StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi){
				RETRUN_MUL(1);
			}
		}
	}

	// fen 5a3/3k5/5a3/9/2p3b2/9/9/B4K3/3p5/2B6 w
	if (EV_MY_CAN <= 1 && (your_shi_num + your_xiang_num) >= 2){
		RETRUN_MUL(1);
	}


	// fen 5kb2/4a4/9/9/9/9/9/3A1A3/1p1p5/4K4 w - - 90 90
	// 二个兵在一边,也是和棋

	if (your_shi_num == 2 && IsOnSameSide(mpawn1, mpawn2)){
		if (StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
			if (PB90(MY_SQ15) == your_shi && PB90(MY_SQ17) == your_shi){
				RETRUN_MUL(1);
			}
			if (StoX(yk) == 0x3 && PB90(MY_SQ17) == your_shi){
				RETRUN_MUL(1);
			}
			if (StoX(yk) == 0x5 && PB90(MY_SQ15) == your_shi){
				RETRUN_MUL(1);
			}
		}
	}

	// fen 4ka3/3PaP3/b8/9/9/9/9/3AB4/9/4K4 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1 && MY_SQ04 == yk) {
		if (!have_bit(bb_my_pawn, MyLowBB[MY_RANK1])) {
			if (have_bit(bb_my_pawn, LeftBB[0x4]) && have_bit(bb_my_pawn, RightBB[0x4])) {
				RETRUN_MUL(1);
			}
		}
	}

	// fen 2ba1k3/6P2/4bP3/9/9/9/9/4B4/4A4/2B1K4 r
	if (your_shi_num >= 1 && your_xiang_num == 2){
		if (PB90(MY_SQ16) == your_xiang){
			if (!have_bit(bb_my_pawn, MyLowBB[MY_RANK2])){
				if (StoY(yk) == MY_RANK0){
					if (StoX(yk) >= 0x4
						&& count_1s(bb_my_pawn, RightBB[0x4]) == 2){
						RETRUN_MUL(2);
					}
					if (StoX(yk) <= 0x4
						&& count_1s(bb_my_pawn, LeftBB[0x4]) == 2){
						RETRUN_MUL(2);
					}
				}
			}
		}
	}

	// fen 5a1P1/5k3/6P2/9/9/9/9/5A2B/4A4/3K5 w - - 0 1
	if (your_shi_num >= 1 && StoY(yk) != MY_RANK0){
		if (have_bit(bb_my_pawn, RankBB_A[MY_RANK0]) && 
			!have_bit(bb_my_pawn,MyLowBB[MY_RANK2])){
			Bitboard p2 = m_and(bb_my_pawn, MyLowBB[MY_RANK0]);
			if (StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi){
				if (have_bit(p2, RightBB[0x5])){
					RETRUN_MUL(2);
				}
			}
			if (StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi){
				if (have_bit(p2, LeftBB[0x3])){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 3k5/2P1aP3/5a2b/9/9/9/9/B2AB4/4A4/4K4 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1){
		if (StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
			if (!IsOnSameSide(mpawn1, mpawn2)){
				if (MY_SQ03 == yk && PB90(MY_SQ15) != your_shi){
					RETRUN_MUL(2);
				}
				if (MY_SQ05 == yk && PB90(MY_SQ17) != your_shi){
					RETRUN_MUL(2);
				}
			}
		}
	}



	// fen 6P2/4a4/3k2P2/9/9/9/9/5A3/4A4/5K3 b - - 0 1
	if (your_shi_num >= 1 && StoY(yk) != MY_RANK0){
		if (StoY(mpawn1) == MY_RANK0){
			if (StoY(mpawn2) MY_SMALL_EQL MY_RANK2){
				if (!IsOnSameSide(yk, mpawn2) && abs(StoX(yk) - StoX(mpawn2)) >= 2){
					RETRUN_MUL(2);
				}
			}
		}
		if (StoY(mpawn2) == MY_RANK0){
			if (StoY(mpawn1) MY_SMALL_EQL MY_RANK2){
				if (!IsOnSameSide(yk, mpawn1) && abs(StoX(yk) - StoX(mpawn1)) >= 2){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 4k4/3PaP3/b4a3/9/9/2B6/9/B2A5/9/4K4 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1){
		if (MY_SQ04 == yk){
			if (!have_bit(bb_my_pawn, MyLowBB[MY_RANK1])){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 4ka3/4aP3/6P2/9/9/9/9/3AB4/9/4K4 b - - 0 1
	if (your_shi_num == 2 && !have_bit(bb_my_pawn, MyLowBB[MY_RANK2])){
		if (!have_bit(bb_your_shi, LeftBB[0x4])
			&& !have_bit(bb_my_pawn, LeftBB[0x5])){
			RETRUN_MUL(2);
		}
		if (!have_bit(bb_your_shi, RightBB[0x4])
			&& !have_bit(bb_my_pawn, RightBB[0x3])){
			RETRUN_MUL(2);
		}
	}

	// fen 4k1b2/3P5/2P1ba3/9/9/9/9/B8/4AK3/5A3 b - - 0 1
	if (your_xiang_num == 2 && your_shi_num >= 1 && MY_SQ04 == yk){
		if (!have_bit(bb_your_pawn, MyLowBB[MY_RANK2]) && PB90(MY_SQ16) == your_xiang
			&& have_bit(bb_my_pawn, RankBB_A[MY_RANK1])){
			if (!have_bit(LeftBB[0x4], bb_my_pawn)
				|| !have_bit(RightBB[0x4], bb_my_pawn)){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 4ka3/4aP3/6P2/9/9/9/9/3AB4/9/4K4 b - - 0 1
	if (your_shi_num >= 1 && !have_bit(bb_my_pawn, MyLowBB[MY_RANK1])){
		if (StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi && PB90(MY_SQ05) != your_shi){
			if (!have_bit(bb_my_pawn, LeftBB[0x5])){
				RETRUN_MUL(2);
			}
		}
		if (StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi && PB90(MY_SQ03) != your_shi){
			if (!have_bit(bb_my_pawn, RightBB[0x3])){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 9/9/3k5/9/9/9/9/5K3/4A1p2/8p w - - 0 0
	//一个兵到了底线,另一个兵在二线的将的同一边
	if (your_shi_num >= 1){
		if (StoY(mpawn1) == MY_RANK0 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
			if (IsOnSameSide(yk, mpawn2)){
				RETRUN_MUL(2);
			}
		}
		if (StoY(mpawn2) == MY_RANK0 && StoY(mpawn1) MY_SMALL_EQL MY_RANK1){
			if (IsOnSameSide(yk, mpawn1)){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 4k1b2/1P1Pa4/4b4/9/9/6B2/9/4B4/4A4/4KA3 r

	if (your_shi_num >= 1 && your_xiang_num == 2){
		if (StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
			if (PB90(MY_SQ16) == your_xiang && PB90(MY_SQ0D) == your_shi && yk == MY_SQ04){
				if (IsOnSameSide(mpawn1, mpawn2)){
					RETRUN_MUL(2);
				}
			}
			// fen 3k1ab2/1PP6/4b4/9/9/2B6/9/3ABK3/4A4/9 b - - 0 1
			if (yk == MY_SQ03 && StoX(mpawn1) <= 0x3 && StoX(mpawn2) <= 0x3){
				RETRUN_MUL(2);
			}
			if (yk == MY_SQ05 && StoX(mpawn1) >= 0x5 && StoX(mpawn2) >= 0x5){
				RETRUN_MUL(2);
			}

			// fen 3k5/2P3P2/5a3/9/2b3b2/9/9/9/4A4/3AK4 w - - 0 1		
			if (!IsOnSameSide(mpawn1, mpawn2)){
				if (StoX(yk) == 0x3 && PB90(MY_SQ17) == your_shi){
					RETRUN_MUL(2);
				}
				if (StoX(yk) == 0x5 && PB90(MY_SQ15) == your_shi){
					RETRUN_MUL(2);
				}
			}
		}
	}


	if (your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		/*Bitboard byp = m_and(bb_your_pawn,MyUpBB[MY_RANK2]);*/
		if (StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
			if (!IsOnSameSide(mpawn1, mpawn2)){
				if (StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi){
					RETRUN_MUL(2);
				}
				if (StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 3k5/4a4/2P4P1/9/2b3b2/2B6/9/3A5/4K4/5AB2 w - - 0 1
	//if(your_xiang_num == 2 && your_shi_num >= 1){
	//	if(StoY(p1) MY_SMALL_EQL MY_RANK2 && StoY(p2) MY_SMALL_EQL MY_RANK2){
	//		if(!IsOnSameSide(p1,p2)){
	//			if(StoX(yk) == 0x3){ 
	//				if(PB90(MY_SQ0D) == your_shi ){
	//					RETRUN_MUL(2);
	//				}
	//				if(PB90(MY_SQ17) == your_shi && !bit_is_set(ei.pi->pawnshi_attacks(MY_COLOR),Square(MY_SQ17))){
	//					RETRUN_MUL(2);
	//				}
	//			}
	//			if(StoX(yk) == 0x5){
	//				if(PB90(MY_SQ0D) == your_shi && !bit_is_set(ei.pi->pawnshi_attacks(MY_COLOR),Square(MY_SQ0D))){
	//					RETRUN_MUL(2);
	//				}
	//				if(PB90(MY_SQ15) == your_shi && !bit_is_set(ei.pi->pawnshi_attacks(MY_COLOR),Square(MY_SQ15))){
	//					RETRUN_MUL(2);
	//				}
	//			}
	//		}
	//	}
	//}

	// fen 4k4/5PP2/5a3/9/6b2/9/9/3K5/4A4/5A3 w - - 0 1
	if (your_shi_num >= 1 && your_xiang_num >= 1){
		if (!have_bit(bb_my_pawn, MyLowBB[MY_RANK1])){
			if (IsOnSameSide(mpawn1, mpawn2)){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 5k3/4a1P2/2P1ba3/9/9/9/9/4B4/9/3K1A3 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1){
		if (StoY(yk) == MY_RANK0 && PB90(MY_SQ0D) != my_pawn){
			RETRUN_MUL(2);
		}
	}

	// fen 5k3/4a1P2/2P1b4/9/9/9/9/3K5/9/2B3B2 b - - 0 1
	if (your_shi_num >= 1 && your_xiang_num >= 1 && StoX(yk) != 0x4){
		if (!have_bit(bb_my_pawn, MyLowBB[MY_RANK1]) && !IsOnSameSide(mpawn1, mpawn2)){
			if (PB90(yk MY_SUB 18) != your_shi && !have_bit(FileBB_A[0x4], bb_my_pawn)){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 3a5/4ak3/9/9/2b3b2/9/9/4K4/4Ap3/4p4 w - - 0 1
	if (MY_SQ16 == yk && your_shi_num >= 1){
		if (StoY(mpawn1) == MY_RANK0 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(2);
		}
		if (StoY(mpawn2) == MY_RANK0 && StoY(mpawn1) MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(2);
		}
	}

	// fen 3k5/2P1a4/b5P2/9/9/9/9/4B4/4A4/4KAB2 b - - 0 1
	if (your_shi_num >= 1 && your_xiang_num >= 1){
		Bitboard mp = m_and(bb_my_pawn, MyUpBB[MY_RANK2]);
		if (have_bit(mp, LeftBB[0x3]) && StoX(yk) == 0x3){
			Bitboard op = m_and(bb_my_pawn, MyUpBB[MY_RANK3]);
			if (have_bit(RightBB[0x4], op)){
				if (PB90(MY_SQ0D) == your_shi || PB90(MY_SQ17) == your_shi){
					RETRUN_MUL(2);
				}
			}
		}
		if (have_bit(mp, RightBB[0x5]) && StoX(yk) == 0x5){
			Bitboard op = m_and(bb_my_pawn, MyUpBB[MY_RANK3]);
			if (have_bit(LeftBB[0x4], op)){
				if (PB90(MY_SQ0D) == your_shi || PB90(MY_SQ15) == your_shi){
					RETRUN_MUL(2);
				}
			}
		}
	}
	

	// fen 4kab2/3Pa1P2/8b/9/9/9/9/3ABA3/9/5KB2 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2){

		MY_EV_SUB(128);

		if (yk == MY_SQ04){
			RETRUN_MUL(2);
		}

		if (yk == MY_SQ03 && PB90(MY_SQ15) == EMPTY){
			RETRUN_MUL(2);
		}
		// fen 2bk1a3/2P2P3/5a3/9/6b2/2B6/9/3AB4/4A4/4K4 w - - 0 1
		if (yk == MY_SQ05 && PB90(MY_SQ17) == EMPTY){
			RETRUN_MUL(2);
		}

		RETRUN_MUL(4);
	}
	// fen 4k4/4aP3/5a2b/5P3/9/6B2/9/B8/9/3K1A3 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if (have_bit(bb_your_shi, RankBB_A[MY_RANK2])){
			RETRUN_MUL(4);
		}
	}

	// fen 5k3/4a1P2/9/5P3/6b2/9/9/9/4A4/2B1KA3 b - - 0 1
	if (your_shi_num >= 1 && your_xiang_num >= 1){
		Bitboard m2p = m_and(bb_my_pawn, MyUpBB[MY_RANK2]);
		if (StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi){
			if (have_bit(m2p, RightBB[0x5])){
					RETRUN_MUL(4);				
			}
		}
		if (StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi){
			if (have_bit(m2p, LeftBB[0x3])){
					RETRUN_MUL(4);				
			}
		}
	}

	// fen 5kb2/4a1P2/9/4P4/2b6/9/9/4B4/9/2BAK4 b - - 0 1
	if (your_shi_num >= 1 && your_xiang_num == 2){
		if (StoX(yk) == 0x5 && !have_bit(bb_your_shi, RightBB[0x4])){
			RETRUN_MUL(4);
		}
		if (StoX(yk) == 0x3 && !have_bit(bb_your_shi, LeftBB[0x4])){
			RETRUN_MUL(4);
		}
	}


	// fen 4k4/4aP3/5a2b/5P3/9/6B2/9/B8/9/3K1A3 b - - 0 1
	// fen 2b1k4/9/3a5/P5P2/9/9/9/5A3/5K3/3A5 w - - 0 1
	if (your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if (abs(StoX(mpawn1) - 0x4) >= 2){
			MY_EV_SUB(96);
		}
		if (abs(StoX(mpawn2) - 0x4) >= 2){
			MY_EV_SUB(96);
		}
		RETRUN_MUL(8);
	}

	// fen 2b1k4/9/3a5/P5P2/9/9/9/5A3/5K3/3A5 w - - 0 1

}


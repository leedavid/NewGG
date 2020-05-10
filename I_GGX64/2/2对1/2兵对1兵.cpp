#ifndef END_my_m_MT_R_2pawn_B_1pawn
#define END_my_m_MT_R_2pawn_B_1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2兵对1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int My_Pawn_Add = 80;
//const int 
//const int My_Add             =  24;
//const int My_Pawn_Shi_Add[3] = {64,32,16};

//红方两个兵，黑方一个兵
void my_m_MT_R_2pawn_B_1pawn(typePOS &POSITION, EvalInfo &ei) {

	Square mk = my_king_pos;
	Square yk = your_king_pos;
	Square ypawn = S90_from_piecelist(POSITION, your_pawn, 0);
	Square mpawn1 = S90_from_piecelist(POSITION, my_pawn, 0);
	Square mpawn2 = S90_from_piecelist(POSITION, my_pawn, 1);

	BothOnlyPawnEval(POSITION, ei);

	MY_EV_ADD(64);

	if (your_shi_num == 2 && your_xiang_num >= 1 && EV_YOUR_CAN >= 1) {
		if (StoX(yk) == 0x4 && !have_bit(bb_your_shi, MyUpBB[MY_RANK2])) {
			if (!have_bit(bb_my_pawn, MyLowBB[MY_RANK1])) {
				EV_YOUR_SAFE = true;
			}
		}
	}

	// fen 5k3/4a1P2/3a2P2/9/6b2/9/9/3KBA3/2p1A4/9 w - - 0 1
	if (your_shi_num == 2 && EV_YOUR_CAN >= 1) {
		Bitboard mup = m_and(bb_my_pawn, MyUpBB[MY_RANK3]);
		if (count_1s(mup) == 2) {
			if (StoX(yk) == 0x5 && !have_bit(bb_your_shi, RightBB[0x4])) {
				RETRUN_MUL(1);
			}
			if (StoX(yk) == 0x3 && !have_bit(bb_your_shi, LeftBB[0x4])) {
				RETRUN_MUL(1);
			}
		}
	}

	// fen 4k4/2PP5/b8/9/9/2B3B2/9/3A1K3/2p6/9 w - - 0 1
	if (your_xiang_num >= 1 && EV_YOUR_CAN >= 1 && StoX(yk) == 0x4 && StoX(ypawn) != StoX(mk)) {
		if (count_1s(bb_my_pawn, MyUpBB[MY_RANK2]) == 2) {
			if (PB90(MY_SQ12) == your_xiang && !have_bit(bb_my_pawn, RightBB[0x3])) {
				RETRUN_MUL(1);
			}
			if (PB90(MY_SQ1A) == your_xiang && !have_bit(bb_my_pawn, LeftBB[0x5])) {
				RETRUN_MUL(1);
			}
		}
	}

	//  fen 3ak4/3PaP3/9/9/9/6B2/9/3A1A3/5K3/7p1 b - - 0 1
	if (your_shi_num == 2 && StoY(ypawn) == MY_RANK9) {
		if (abs(StoX(ypawn) - 0x4) >= 3) {
			if (MY_SQ04 == yk) {
				if (!have_bit(bb_my_pawn, MyLowBB[MY_RANK1])) {
					if (have_bit(bb_my_pawn, LeftBB[0x4]) && have_bit(bb_my_pawn, RightBB[0x4])) {
						RETRUN_MUL(1);
					}
				}
			}
		}
	}

	if (your_shi_num == 2) {
		RETRUN_MUL(2);
	}

	// fen 3P5/9/4k4/8p/9/8P/9/4BA3/3K5/2B2A3 b - - 122 122 
	//一个兵没有过河,一个兵到了将下面,也是和棋
	if (count_1s(bb_my_pawn, RankBB_A[MY_RANK0]) >= 1) {
		RETRUN_MUL(2);
	}

	//  fen 4k4/9/4b4/7P1/p8/9/P8/4B3B/4A4/3A1K3 w - - 0 1
	if (your_xiang_num >= 1) {
		if (PB90(MY_SQ36) == my_pawn && PB90(MY_SQ24) == your_pawn) {
			if (PB90(MY_SQ25) != my_pawn) {
				RETRUN_MUL(2);
			}
		}
		if (PB90(MY_SQ3E) == my_pawn && PB90(MY_SQ2C) == your_pawn) {
			if (PB90(MY_SQ2B) != my_pawn) {
				RETRUN_MUL(2);
			}
		}
	}


	// fen 4k4/9/b2a1a3/p8/9/P8/9/3K5/5p3/5A3 w - - 0 1
	if (EV_MY_CAN <= 1 && your_shi_num >= 1 && StoY(yk) MY_LARGE_EQL MY_RANK1) {
		if ((StoX(yk) == 0x5 && PB90(MY_SQ17) == your_shi)
			|| (StoX(yk) == 0x3 && PB90(MY_SQ15) == your_shi)) {
		}
		else {
			if (StoY(mpawn1) MY_SMALL_EQL MY_RANK1) {
				RETRUN_MUL(2);
			}
			if (StoY(mpawn2) MY_SMALL_EQL MY_RANK1) {
				RETRUN_MUL(2);
			}
		}
	}

	// fen 3k5/2P1a1P2/9/9/9/9/9/5A3/4K4/2p6 w - - 0 1
	if (your_shi_num >= 1) {
		if (StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1) {
			if (StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi) {
				if (StoX(mpawn1) <= 0x3 && StoX(mpawn2) >= 0x5) {
					RETRUN_MUL(2);
				}
				if (StoX(mpawn2) <= 0x3 && StoX(mpawn1) >= 0x5) {
					RETRUN_MUL(2);
				}
			}
			if (StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi) {
				if (StoX(mpawn1) >= 0x5 && StoX(mpawn2) <= 0x3) {
					RETRUN_MUL(2);
				}
				if (StoX(mpawn2) >= 0x5 && StoX(mpawn1) <= 0x3) {
					RETRUN_MUL(2);
				}
			}
		}
	}





	// fen 9/3P5/3P1k3/9/6b2/9/9/4K4/5p3/2BA2B2 w - - 0 1
	if(your_xiang_num >= 1 && StoY(yk) == MY_RANK2 && EV_YOUR_CAN){
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK2]) && have_bit(bb_my_pawn,RankBB_A[MY_RANK1])){
			if(bit_is_set(YOUR_ATTACK,Square(MY_SQ16))){
				if(!have_bit(RightBB[0x4],bb_my_pawn) && StoX(yk) >= 0x4){
					RETRUN_MUL(2);
				}
				if(!have_bit(LeftBB[0x4],bb_my_pawn) && StoX(yk) <= 0x4){
					RETRUN_MUL(2);
				}
			}
		}
	}


	// fen 2b6/P4k3/2P6/9/9/9/9/9/4p4/3K5 b - - 120 120
	if(your_xiang_num != 0 && my_shi_num == 0){
		if(StoY(ypawn) MY_LARGE MY_RANK4 && StoY(ypawn) MY_SMALL StoY(mk)){
			if(StoX(ypawn) == 0x4){
				if(count_1s(bb_my_pawn,MyUpBB[StoY(yk) MY_ADD 1]) >= 1){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 9/5k3/8b/4P4/2p6/9/2P6/3K5/9/5A3 b - - 0 1
	if(your_xiang_num >= 1 && EV_MY_CAN <= 1){
		if(have_bit(bb_my_pawn,MyUpBB[MY_RANK4])){
			if(PB90(MY_SQ26) == your_pawn && PB90(MY_SQ38) == my_pawn){
				RETRUN_MUL(2);
			}
			if(PB90(MY_SQ2A) == your_pawn && PB90(MY_SQ3C) == my_pawn){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 9/4P4/3k4b/9/8p/9/8P/4K3B/9/9 b - - 0 1
	if(your_xiang_num >= 1 && EV_MY_CAN <= 1){
		if(have_bit(bb_my_pawn,MyUpBB[StoY(yk)])){
			RETRUN_MUL(2);
		}
	}


	// fen 4ka3/5PP2/b7b/9/9/9/9/4BA3/3KA4/4p1B2 w - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2){
		if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
			if(StoX(mpawn1) > 0x4 && StoX(mpawn2) > 0x4 && PB90(MY_SQ1A) == your_xiang){
				if(yk == MY_SQ04 && PB90(MY_SQ0D) != your_shi){
					RETRUN_MUL(2);
				}
				if(StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi){
					RETRUN_MUL(2);
				}
			}
			if(StoX(mpawn1) < 0x4 && StoX(mpawn2) < 0x4 && PB90(MY_SQ12) == your_xiang){
				if(yk == MY_SQ04 && PB90(MY_SQ0D) != your_shi){
					RETRUN_MUL(2);
				}
				if(StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi){
					RETRUN_MUL(2);
				}
			}
		}
	}



	// fen 4k4/3P5/9/9/2b6/7p1/6P2/5K2B/9/3A5 b - - 120 120
	if(your_xiang_num != 0){
		if(StoY(ypawn) MY_LARGE MY_RANK4 && EV_MY_CAN <= 1){
			if(count_1s(bb_my_pawn,MyUpBB[MY_RANK2]) >= 1){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 4k4/9/3aba3/4P4/9/6B2/9/B2p1p3/4K4/9 w - - 120 120
	if(your_xiang_num == 2 && StoY(yk) MY_LARGE_EQL MY_RANK1){
		if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
			if(abs(StoX(ypawn) - 0x4) <= 1){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 4k4/3Pa4/b8/6P2/9/4p4/9/5A3/9/3AK4 w - - 0 0
	if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(StoY(ypawn) == MY_RANK6 || StoY(ypawn) == MY_RANK5){
			if(StoX(ypawn) == StoX(mk)){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 2bak4/4a2P1/4b4/9/9/6B2/9/9/1p2A1p2/4K1B2 b - - 0 0</
	if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(IsOnSameSide(mpawn1,mpawn2) == FALSE){
			if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
				if(abs(StoX(mpawn1) - 0x4) >= 2 && abs(StoX(mpawn2) - 0x4) >= 2){
					RETRUN_MUL(2);
				}
				
				if(StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi){
					RETRUN_MUL(2);
				}
				if(StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi){
					RETRUN_MUL(2);
				}
				
			}
		}
	}

	// fen 4k4/3P1P3/b4a2b/9/9/9/9/4BK3/3p5/3A5 w - - 0 1
	if(your_shi_num >= 1 && your_xiang_num >= 1 && !have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
		if(!IsOnSameSide(mpawn1,mpawn2) && StoX(yk) == 0x4 && StoY(ypawn) != MY_RANK9){
			if(PB90(MY_SQ17) == your_shi && StoX(mk) != 0x3){
				if(StoX(ypawn) == 0x3){
					RETRUN_MUL(2);
				}
			}
			if(PB90(MY_SQ15) == your_shi && StoX(mk) != 0x5){
				if(StoX(ypawn) == 0x5){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 9/3k1P3/2P6/9/6b2/6B2/3p5/9/4A4/3K1AB2 b - - 0 1
	if(StoY(ypawn) == MY_RANK6 && abs(StoX(ypawn) - 0x4) <= 2){
		if(your_xiang_num >= 1 && StoY(mpawn1) MY_SMALL_EQL MY_RANK2 && StoY(mpawn2) MY_SMALL_EQL MY_RANK2){
			if(StoY(yk) != MY_RANK0 && !IsOnSameSide(mpawn1,mpawn2)){
				if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 || StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 5k3/4a1P2/4b4/3P5/9/6B2/9/4K4/5p3/9 b - - 0 1
	if (your_shi_num >= 1 && your_xiang_num >= 1){
		if (EV_YOUR_CAN >= 1 && StoY(yk) == MY_RANK0){
			Bitboard upp = m_and(bb_my_pawn, MyUpBB[MY_RANK2]);
			if (StoX(yk) == 0x5 && have_bit(upp, RightBB[0x4])){
				RETRUN_MUL(2);
			}
			if (StoX(yk) == 0x3 && have_bit(upp, LeftBB[0x4])){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 9/3Pak3/9/5P3/2b6/9/9/4B4/3K5/4p4 w - - 0 1
	if (your_shi_num >= 1 && your_xiang_num >= 1) {
		if (StoY(ypawn) MY_LARGE_EQL MY_RANK5) {
			if (StoY(yk) != MY_RANK0) {
				if (StoX(yk) == 0x5) {
					if (have_bit(bb_my_pawn, m_and(LeftBB[0x4], MyUpBB[MY_RANK2]))) {
						RETRUN_MUL(2);
					}
				}
				if (StoX(yk) == 0x3) {
					if (have_bit(bb_my_pawn, m_and(RightBB[0x4], MyUpBB[MY_RANK2]))) {
						RETRUN_MUL(2);
					}
				}
			}
		}
	}

	// fen 4k4/2PPa4/4b4/9/9/2B6/9/4BK3/4A4/p4A3 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num >= 1){
		if((StoY(ypawn) MY_LARGE_EQL MY_RANK5) ||
			(StoY(ypawn) == MY_RANK9 && abs(StoX(ypawn) - 0x4) >= 3)){
				if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
					if(StoX(mpawn1) < 0x4 && StoX(mpawn2) < 0x4) RETRUN_MUL(2);
					if(StoX(mpawn1) > 0x4 && StoX(mpawn2) > 0x4) RETRUN_MUL(2);
				}
		}
	}

	// fen 9/4P4/2P2k3/9/6b2/9/9/4BA3/4p4/5K3 b - - 0 1
	if ((my_shi_num <= 1 && StoY(mk) == MY_RANK9 && PB90(MY_SQ4C) == your_pawn)
		|| (StoY(ypawn) == MY_RANK6)) {
		if (your_xiang_num >= 1) {
			Bitboard byp = m_and(bb_my_pawn, MyUpBB[StoY(yk)]);
			int pn = (int)count_1s(byp);
			// fen 9/2P1P4/5k3/9/6b2/9/9/4BA3/4p4/5K3 b - - 0 1
			if (pn == 2 && EV_YOUR_CAN >= 1) {
				RETRUN_MUL(2);
			}
			if (pn == 1) { // 一个高兵在相线,且与将不在一边,
				if (StoY(yk) == MY_RANK2) {
					byp = m_and(bb_my_pawn, RankBB_A[MY_RANK2]);
					Square ps;
					if (pop_1st_bit_sq(byp, ps)) {
						if (!IsOnSameSide(ps, yk)) {
							RETRUN_MUL(4);
						}
					}
				}
			}
		}
	}






	// fen 3a5/5k3/4P4/9/p8/9/P8/3A1A3/9/3K5 w - - 0 1
	if (EV_MY_CAN <= 1 && your_shi_num >= 1){
		if (StoX(yk) == 0x5 && PB90(MY_SQ03) == your_shi){
			RETRUN_MUL(4);
		}
		if (StoX(yk) == 0x3 && PB90(MY_SQ05) == your_shi){
			RETRUN_MUL(4);
		}
		Bitboard thp = m_and(MyUpBB[MY_RANK3], bb_my_pawn);
		if (StoX(yk) == 0x3 && !have_bit(LeftBB[0x6], thp)){
			RETRUN_MUL(4);
		}
		if (StoX(yk) == 0x5 && !have_bit(RightBB[0x2], thp)){
			RETRUN_MUL(4);
		}
	}


	// fen 2bk1ab2/2P6/9/6P2/9/9/9/4Bp3/4K4/3A5 w - - 0 125
	if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(ypawn) MY_SMALL StoY(mk) && EV_YOUR_CAN >= 1){

		if(StoY(yk) != MY_RANK0 && !IsOnSameSide(mpawn1,mpawn2)){
			// fen 2bk1ab2/2P6/9/6P2/9/9/9/4Bp3/4K4/3A5 w - - 0 125
			if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK2){
				if(StoX(mpawn1) > 0x4 && PB90(MY_SQ17) == your_shi){
					RETRUN_MUL(2);
				}
				if(StoX(mpawn1) < 0x4 && PB90(MY_SQ15) == your_shi){
					RETRUN_MUL(2);
				}
			}
			if(StoY(mpawn2) MY_SMALL_EQL MY_RANK1 && StoY(mpawn1) MY_SMALL_EQL MY_RANK2){
				if(StoX(mpawn2) > 0x4 && PB90(MY_SQ17) == your_shi){
					RETRUN_MUL(2);
				}
				if(StoX(mpawn2) < 0x4 && PB90(MY_SQ15) == your_shi){
					RETRUN_MUL(2);
				}
			}
		}

		if(StoX(yk) != 0x4){
			if(StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi){
		         RETRUN_MUL(4);
			}
			if(StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi){
				RETRUN_MUL(4);
			}
		}
	}

	if(your_xiang_num >= 1 && EV_MY_CAN <= 1){
		if(your_xiang_num == 2){
			RETRUN_MUL(4);
		}
	}

	// fen 4ka3/9/8b/3P2P2/9/9/3p5/5A3/4A4/4K4 r
	if(your_shi_num >= 1 && your_xiang_num >= 1){
		if(StoY(ypawn) == MY_RANK6 && abs(StoX(ypawn) - 0x4) <= 1){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK2])){
				RETRUN_MUL(4);
			}
		}
	}



	// fen 9/3kaP3/b4a3/9/6b2/9/9/4BK2B/1p1p5/5A3 w - - 0 111

	// fen 9/3Pak3/4b4/6P2/2b6/9/9/B2AK4/3pA4/6B2 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(ypawn) MY_LARGE_EQL MY_RANK5){
		if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1){
			if(StoX(mpawn1) < 0x4 && StoX(yk) > 0x4 && PB90(MY_SQ17) != your_shi){
				RETRUN_MUL(4);
			}
			if(StoX(mpawn1) > 0x4 && StoX(yk) < 0x4 && PB90(MY_SQ15) != your_shi){
				RETRUN_MUL(4);
			}
		}
		if(StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
			if(StoX(mpawn2) < 0x4 && StoX(yk) > 0x4 && PB90(MY_SQ17) != your_shi){
				RETRUN_MUL(4);
			}
			if(StoX(mpawn2) > 0x4 && StoX(yk) < 0x4 && PB90(MY_SQ15) != your_shi){
				RETRUN_MUL(4);
			}
		}
	}	

	// fen 4P4/9/4k4/9/9/9/9/B1p3p2/4A4/3K5 b - - 0 1
	if (your_shi_num >= 1 && your_xiang_num >= 1) {
		if (StoY(ypawn) MY_LARGE_EQL MY_RANK5) { // 对方的兵已过河
			if (StoY(mpawn1) MY_SMALL_EQL MY_RANK2 && StoY(mpawn2) MY_SMALL_EQL MY_RANK2) {
				MY_EV_SUB(64);
				if (abs(StoX(mpawn1) - 0x4) >= 2 && abs(StoX(mpawn2) - 0x4) >= 2) {
					if (StoX(yk) != 0x4 && !have_bit(bb_your_shi, FileBB_A[StoX(yk)])) {
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 3k5/5P3/3a1P3/9/6b2/2B6/9/B3K4/2p1A4/9 w - - 0 95
	if(EV_YOUR_CAN >= 1 && your_shi_num >= 1 && your_xiang_num >= 1){
		if(StoY(mpawn1) MY_SMALL_EQL MY_RANK2 && StoY(mpawn2) MY_SMALL_EQL MY_RANK2){
			if(IsOnSameSide(mpawn1,mpawn2)){
				RETRUN_MUL(4);
			}
		}
		RETRUN_MUL(8);
	}



}

//OrgFen: fen 5k3/4a4/3a5/4P4/6b2/2B3B2/9/3K5/2p2p3/9 b - - 0 0
//BcRFen: fen 9/3P2P2/5k3/9/2b3b2/2B6/4p4/5A3/4A4/3K5 w - - 0 0
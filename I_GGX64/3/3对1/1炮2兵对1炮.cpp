#ifndef END_my_m_MT_R_1PAO2PAWN_B_1PAO
#define END_my_m_MT_R_1PAO2PAWN_B_1PAO
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮2兵对1炮.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int PawnAdd = 64;

//我方一炮二兵，对方一炮
void my_m_MT_R_1PAO2PAWN_B_1PAO(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1PaoXPawn_1Pao_ByPawn[your_shi_num]);

	Square ypao   = S90_from_piecelist(POSITION,your_pao,0);
	Square mpao   = S90_from_piecelist(POSITION,my_pao,0);
	Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);
	//Square yk     = your_king_pos;
	int mcan  = EV_MY_CAN;
	int malr  = My_pawn_already_over_river(POSITION);
	Square mk = my_king_pos;

	//// fen 5kb2/3Pa4/3a5/3C5/3c2b2/2B5P/9/4BA3/9/3K1A3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(have_bit(bb_my_pawn,MyUpBB[MY_RANK2])){
			if(abs(StoX(mpawn1) - 0x4) == 4 && StoY(mpawn1) MY_LARGE_EQL MY_RANK5){
				if(bit_is_set(ei.attacked_by(your_pao),XYtoS(StoX(mpawn1),MY_RANK4))){
					MY_EV_SUB(64);
					if(StoX(yk) != 0x4 && !have_bit(bb_your_shi,FileBB_A[StoX(yk)])){
						MY_EV_SUB(32);
					}
					if(!IsOnSameSide(mpawn2,yk)){
						MY_EV_SUB(32);
					}
				}
			}
			if(abs(StoX(mpawn2) - 0x4) == 4 && StoY(mpawn2) MY_LARGE_EQL MY_RANK5){
				if(bit_is_set(ei.attacked_by(your_pao),XYtoS(StoX(mpawn2),MY_RANK4))){
					MY_EV_SUB(64);
					if(StoX(yk) != 0x4 && !have_bit(bb_your_shi,FileBB_A[StoX(yk)])){
						MY_EV_SUB(32);
					}
					if(!IsOnSameSide(mpawn1,yk)){
						MY_EV_SUB(32);
					}
				}
			}
		}
	}

	// fen 5P3/3k5/3a2P2/9/C8/1c4B2/9/9/9/3K5 w - - 0 1
	if (my_shi_num == 0 && have_bit(bb_my_pawn, RankBB_A[MY_RANK0])){
		if (!have_bit(bb_my_pawn, MyLowBB[MY_RANK2])){
			if (StoY(yk) != MY_RANK0){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 5a3/1PP4C1/3kba1c1/9/9/9/9/9/4K4/2B6 b - - 0 1
	if (my_shi_num == 0){
		if (count_1s(bb_my_pawn, MyUpBB[StoY(yk)]) == 2){
			if (your_shi_num == 2){
				RETRUN_MUL(2);
			}
		}
	}




	// fen 9/4ck3/5a3/9/2b3b2/9/9/4Bp1p1/2C1A4/4K1B2 w - - 0 0
	if(your_shi_num >= 1 && your_xiang_num == 2){
		if(StoY(mpawn1) == MY_RANK2 && StoY(mpawn2) == MY_RANK2){
			if(IsOnSameSide(mpawn1,mpawn2) && !IsOnSameSide(mpawn1,ypao)){
				if(StoY(ypao) == MY_RANK1){
					RETRUN_MUL(2);
				}
			}
		}
	}

	
	// fen 4k4/4a4/9/4P4/1cb6/8P/9/9/5K3/4C4 b - - 40 40
	// fen 2bk5/5P3/4b1c2/3P5/9/9/9/9/9/3K5 w - - 0 0
	// fen 9/4k4/b4P3/9/6bc1/P3C4/9/9/9/3K5 w - - 53 53
	if(my_shi_num == 0 && my_xiang_num == 0 && your_xiang_num >= 1){
		//1个兵过河了,一个兵不能过河
		if(StoY(mpawn1) MY_SMALL_EQL MY_RANK3 || StoY(mpawn2) MY_SMALL_EQL MY_RANK3){			
			Square sq = SQ_END90;
			if(StoY(mpawn1) MY_LARGE_EQL MY_RANK5){
				sq = XYtoS(StoX(mpawn1),MY_RANK4);
			}
			if(StoY(mpawn2) MY_LARGE_EQL MY_RANK5){
				sq = XYtoS(StoX(mpawn2),MY_RANK4);
			}
			if(sq != SQ_END90){
				Bitboard peat = POSITION.Pao_Eat_bb(ypao);
				if(bit_is_set(peat,sq)){
					RETRUN_MUL(2);
				}
			}
		}
	}

	if(StoY(mpawn2) == MY_RANK0 && StoY(mpawn1) == MY_RANK0){
		if(your_xiang_num == 2 && StoY(yk) != MY_RANK0){
			RETRUN_MUL(2);
		}
	}

	// fen 3a1k3/6P2/b2abc3/9/9/2P6/9/3A4B/5K3/4C4 w - - 0 1
	if(EV_MY_CAN <= 1){
		if(your_shi_num == 2 && your_xiang_num == 2){
			if(have_bit(bb_my_pawn,MyUpBB[MY_RANK2]) && PB90(MY_SQ0D) != my_pawn){
				if(StoX(yk) != 0x4 && PB90(XYtoS(StoX(yk),MY_RANK2)) != your_shi){
					RETRUN_MUL(2);
				}
			}
		}
	}

	//  fen 3ak1b2/9/3a5/5P3/1cb6/8P/4C4/3AB4/4A4/4K1B2 b - - 0 1
    // 有一个兵没有办法过河
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0) {

		MY_EV_SUB(64);

		Bitboard sidep = m_and(bb_my_pawn, MyLowBB[MY_RANK4]);
		if (have_bit(sidep, m_or(FileBB_A[0x0], FileBB_A[0x8]))) {
			RETRUN_MUL(3);
		}
	}

	// fen 4k4/2c1aP3/4b4/5P3/6b2/2B6/9/9/5C3/2B1K4 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2){
		//三个子在一条纵线上，并且对方的炮打住了我方的一个兵。
		if(PB90(MY_SQ0D) == your_shi && StoY(ypao) == MY_RANK1){
			if(PB90(MY_SQ0E) == my_pawn && StoX(ypao) <= 0x3){
				if(PB90(MY_SQ20) == my_pawn || PB90(MY_SQ29) == my_pawn){
					if(StoX(mpao) == 0x5){
						if(my_shi_num == 0){
							RETRUN_MUL(3);
						}
						RETRUN_MUL(4);
					}
				}
			}
			if(PB90(MY_SQ0C) == my_pawn && StoX(ypao) >= 0x5){
				if(PB90(MY_SQ1E) == my_pawn || PB90(MY_SQ27) == my_pawn){
					if(StoX(mpao) == 0x3){
						if(my_shi_num == 0){
							RETRUN_MUL(3);
						}
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 5kb2/1P2a1P2/c2ab4/9/9/6B2/9/5C3/9/4K4 w - - 0 1
	if (your_shi_num == 2 && your_shi_num == 2) {
		if (my_shi_num == 0) {
			Bitboard mp = m_and(bb_my_pawn, MyUpBB[MY_RANK2]);
			if (count_1s(mp) == 2) {
				if (StoX(yk) == 0x5 && !have_bit(bb_your_shi, RightBB[0x4])) {
					if (have_bit(mp, LeftBB[0x4])) {
						RETRUN_MUL(4);
					}
				}
				if (StoX(yk) == 0x3 && !have_bit(bb_your_shi, LeftBB[0x4])) {
					if (have_bit(mp, RightBB[0x4])) {
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 6b2/3ka4/4ba3/9/3C5/9/4c4/4B4/3pA4/2BAK1p2 b - - 0 1
	if (your_shi_num == 2 && your_shi_num == 2) {
		if (have_bit(bb_my_pawn, RankBB_A[MY_RANK0])) { // 有底线兵
			MY_EV_SUB(64);

			Bitboard bysx = m_or(bb_your_shi, bb_your_xiang);

			if (StoY(ypao) MY_SMALL MY_RANK7) {
				//-----------------------------------------------------------
				if (StoY(mpawn1) == MY_RANK0 && StoY(mpawn2) != MY_RANK0) {
					if (StoY(mpawn2) MY_SMALL_EQL MY_RANK1) {
						if (StoX(mpawn1) <= 0x2 && StoX(mpawn2) > 0x4) {
							MY_EV_SUB(32);
							if (!have_bit(bysx, LeftBB[0x4])) {
								RETRUN_MUL(4);
							}
						}
						if (StoX(mpawn1) >= 0x6 && StoX(mpawn2) <  0x4) {
							MY_EV_SUB(32);
							if (!have_bit(bysx, RightBB[0x4])) {
								RETRUN_MUL(4);
							}
						}
					}
				}
				//-----------------------------------------------------------
				if (StoY(mpawn2) == MY_RANK0 && StoY(mpawn1) != MY_RANK0) {
					if (StoY(mpawn1) MY_SMALL_EQL MY_RANK1) {
						if (StoX(mpawn2) <= 0x2 && StoX(mpawn1) > 0x4) {
							MY_EV_SUB(32);
							if (!have_bit(bysx, LeftBB[0x4])) {
								RETRUN_MUL(4);
							}
						}
						if (StoX(mpawn2) >= 0x6 && StoX(mpawn1) <  0x4) {
							MY_EV_SUB(32);
							if (!have_bit(bysx, RightBB[0x4])) {
								RETRUN_MUL(4);
							}
						}
					}
				}
			}
		}
	}

	// fen 4k4/5P3/b4a3/5C3/6b2/2P2cB2/9/9/3K5/2B6 w - - 0 1
	if (your_xiang_num == 2 && your_shi_num >= 1){
		if (have_bit(MyUpBB[MY_RANK2], bb_my_pawn)){
			if (have_bit(MyLowBB[MY_RANK1], bb_your_shi)){
				if (EV_MY_CAN <= 1){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 9/4k4/4ca3/9/9/9/9/3A5/3C2pp1/3K1AB2 w - - 0 1
	if (my_shi_num <= 1){
		if (your_shi_num == 2 && your_xiang_num >= 1){
			if (StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
				if (StoX(mpawn1) < 0x4 && StoX(mpawn2) < 0x4
					&& StoX(yk) > 0x4 && PB90(MY_SQ17) == your_shi){
					RETRUN_MUL(4);
				}
				if (StoX(mpawn1) > 0x4 && StoX(mpawn2) > 0x4
					&& StoX(yk) < 0x4 && PB90(MY_SQ15) == your_shi){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 1P5P1/5k3/4b4/9/2b2c3/2B6/9/5A3/6C2/3K5 w - - 0 1
	if(StoY(mpawn2) == MY_RANK0 && StoY(mpawn1) == MY_RANK0){
		if(your_xiang_num == 2){
			RETRUN_MUL(4);
		}
	}

	// fen 2b1k4/5P3/9/9/1cb6/6P2/9/5A3/3KC4/5A3 w - - 0 1
	if(your_xiang_num == 2 && my_xiang_num == 0){
		if(StoX(yk) == 0x4 && count_1s(bb_my_pawn,MyUpBB[MY_RANK5]) == 1){
			if(have_bit(bb_my_pawn,MyUpBB[MY_RANK2]) && StoY(ypao) == MY_RANK4){
				if(StoX(ypao) < 0x2 && PB90(MY_SQ26) == your_xiang){
					if(PB90(MY_SQ33) == my_pawn || PB90(MY_SQ3C) == my_pawn){
						RETRUN_MUL(4);
					}
				}
				if(StoX(ypao) > 0x6 && PB90(MY_SQ2A) == your_xiang){
					if(PB90(MY_SQ2F) == my_pawn || PB90(MY_SQ38) == my_pawn){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}
	// fen 3a5/1C3PP2/1c1k1a3/9/9/9/9/4BA3/4A4/4K4 w - - 0 1
	if(your_shi_num == 2){
		if(count_1s(MyUpBB[StoY(yk)],bb_my_pawn) == 2){
			if(StoY(mpao) MY_SMALL StoY(yk)){
				RETRUN_MUL(4);
			}
		}
	}

	// fen C2a5/4ak3/4P4/5P3/6b2/2B1c4/9/3AB4/4A4/5K3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(PB90(MY_SQ16) == my_pawn && have_bit(bb_my_pawn,MyLowBB[MY_RANK2])){
			RETRUN_MUL(4);
		}
	}

	// fen P3k2C1/4a3c/4baP2/9/9/9/9/5A3/5K3/9 b - - 0 1
	if(have_bit(bb_my_pawn,RankBB_A[MY_RANK0])){
		if((my_shi_num + my_xiang_num) <= 1){
			if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
				if(have_bit(bb_your_shi,RankBB_A[MY_RANK2])){
					if(have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 4k1b2/3P5/5a3/9/3c2b2/8P/4C4/B3K4/9/2B6 b - - 0 1
	if (my_shi_num == 0){
		// fen 9/3P1k3/4bC3/9/c5b2/8P/9/B8/5K3/6B2 b - - 0 1
		if (your_xiang_num == 2){
			// MY_EV_SUB(128);
			if (have_bit(bb_my_pawn, MyUpBB[MY_RANK2]) && StoY(ypao) == MY_RANK4){
				if (StoY(mpawn1) MY_LARGE_EQL MY_RANK5){
					if (abs(StoX(mpawn1) - 0x4) == 4){
						if (abs(StoX(ypao) - StoX(mpawn1)) >= 3){
							RETRUN_MUL(4);
						}
					}
				}
				if (StoY(mpawn2) MY_LARGE_EQL MY_RANK5){
					if (abs(StoX(mpawn2) - 0x4) == 4){
						if (abs(StoX(ypao) - StoX(mpawn2)) >= 3){
							RETRUN_MUL(4);
						}
					}
				}
			}
		}
	}

	// fen 9/4ak3/2c3PP1/5C3/6b2/2B6/9/9/9/4K4 b - - 0 1
	if (my_shi_num == 0 && your_shi_num >= 1 && your_xiang_num >= 1) {
		if (!have_bit(bb_my_pawn, MyLowBB[MY_RANK2])) {
			if (!have_bit(bb_my_pawn, LeftBB[0x6])) {
				RETRUN_MUL(4);
			}
			if (!have_bit(bb_my_pawn, RightBB[0x2])) {
				RETRUN_MUL(4);
			}
		}
	}

	// fen C1bak4/9/bP1a3c1/1P7/9/2B6/9/9/4A4/3A1K3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(!have_bit(bb_my_pawn,LeftBB[0x1]) || !have_bit(bb_my_pawn,RightBB[0x7])){
			if(have_bit(bb_my_pawn,ei.attacked_by(your_pao))){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4k4/3PaP3/3a5/3C1c3/2b6/2B6/9/4BK3/4A4/3A5 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(!IsOnSameSide(mpawn1,mpawn2) && !have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
			if(have_bit(bb_your_shi,RankBB_A[MY_RANK2])){
				if(StoX(ypao) == StoX(mk)){
					RETRUN_MUL(4);
				}
				RETRUN_MUL(6);
			}
		}
	}



	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		// fen 3ak2P1/4a4/2c1b3b/7P1/4C4/9/9/B2AB4/5K3/3A5 w - - 0 1
		// 有一个低兵，且这个兵在三线外面
		if((StoY(mpawn1) == MY_RANK0 && abs(StoX(mpawn1) - 0x4) >= 3)
			|| (StoY(mpawn2) == MY_RANK0 && abs(StoX(mpawn2) - 0x4) >= 3)){
				if(StoY(mpawn1) MY_LARGE_EQL MY_RANK3 || StoY(mpawn2) MY_LARGE_EQL MY_RANK3){
					RETRUN_MUL(6);
				}
		}
	}

	// fen 4k2C1/3Pa1P2/4ba3/7c1/9/2B3B2/9/9/5K3/3A5 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(!IsOnSameSide(mpawn1,mpawn2) && StoY(mpao) MY_SMALL_EQL MY_RANK2){
			if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
				
				MY_EV_SUB(64);

				if(StoX(mpao) > 0x4 && PB90(MY_SQ17) == your_shi){
					RETRUN_MUL(6);
				}
				if(StoX(mpao) < 0x4 && PB90(MY_SQ15) == your_shi){
					RETRUN_MUL(6);
				}
				// fen 6PC1/3P1k1c1/3aba3/9/9/2B6/9/4B4/9/3AK4 w - - 0 1
				if(StoY(mpawn1) == MY_RANK0 || StoY(mpawn2) == MY_RANK0){
					RETRUN_MUL(6);
				}
			}
		}
	}

	// fen 3k1abC1/2P1aP3/4b4/4c4/9/9/9/5K3/4A4/3A5 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
			if(have_bit(LeftBB[0x4],bb_my_pawn) && have_bit(RightBB[0x4],bb_my_pawn)){
				if(StoX(yk) != 0x4 && !have_bit(bb_your_shi,RankBB_A[MY_RANK2])){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// 我方有中炮或底炮.
	if (bit_is_set(EV_MY_XBIT, MY_SQ0D) && bit_is_set(EV_MY_XBIT, MY_SQ16)){
		return;
	}

	// fen 4P4/3k5/5P2b/7C1/9/2B6/4c4/8B/4K4/9 w - - 255 255
	// 如果红方没有仕,且只有一个可过河,对方还有相,则是和棋
	if(my_shi_num == 0){
		//有一个兵到了底线
		if(StoY(mpawn1) == MY_RANK0 || StoY(mpawn2) == MY_RANK0){
			if(your_xiang_num >= 1){
				RETRUN_MUL(2);
			}
		}
		// fen 3k5/2P1a1P2/4ba3/4cC3/9/9/9/9/4K4/9 b - - 145 145
		if(your_shi_num == 2 && your_xiang_num >= 1){
			if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
				//二个兵不在一边
				if(!IsOnSameSide(mpawn1,mpawn2) && StoX(yk) != 0x4){
					RETRUN_MUL(2);
				}
			}
		}
		// fen 2P3P2/3k5/3a5/9/9/3c3C1/9/9/5K3/9 b - - 0 0
		if(StoY(mpawn1) == MY_RANK0 && StoY(mpawn2) == MY_RANK0){
			RETRUN_MUL(2);
		}

		// fen 2b1k4/2P2P3/3a4b/9/9/9/3c5/9/9/5K1C1 w - - 121 121
		if(your_shi_num >= 1 && your_xiang_num == 2 && my_xiang_num == 0){
			if(abs(StoX(mpawn1) - 0x4) >= 2 || abs(StoX(mpawn2) - 0x4) >= 2){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 2b2k3/9/4b4/9/2p6/9/3c5/B4C3/3pA4/4KA3 r
	if(mcan <= 1 && malr <= 1){
		if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
			Bitboard mp = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
			if(count_1s(mp) == 1){
				RETRUN_MUL(4);
			}
		}
	}

	if((your_shi_num + your_xiang_num) == 4){
		RETRUN_MUL(4);
	}
	


	// fen 5c3/3k5/4ba3/9/9/2B6/4C4/4K4/3p5/3p5 b - - 121 121
	//二个兵,一个到了底线,一个在二线以下,有可能是和棋
	if(your_xiang_num >= 1 && StoY(yk) == MY_RANK2){
		if(StoY(mpawn1) MY_SMALL MY_RANK2 && StoY(mpawn2) MY_SMALL MY_RANK2){
			RETRUN_MUL(4);
		}
	}

	// fen 3k1a3/1P7/5a3/7P1/2b5C/6B2/4c4/9/9/4K4 w - - 127 127
	if(my_shi_num == 0){
		if(your_shi_num == 2 && your_xiang_num >= 1 && StoX(yk) != 0x4){
			RETRUN_MUL(4);
		}
	}

	// fen 5k3/1PCP5/4b4/8c/9/9/9/3K5/9/9 w - - 0 1
    if(my_shi_num == 0 && my_xiang_num == 0){
		if(your_xiang_num >= 1){
			Bitboard pp = m_and(m_or(bb_my_pawn,bb_my_pao),RankBB_A[MY_RANK1]);
			if(count_1s(pp) == 3){
				if(!have_bit(LeftBB[0x4],pp)){
					RETRUN_MUL(4);
				}
				if(!have_bit(RightBB[0x4],pp)){
					RETRUN_MUL(4);
				}
			}
		}
	}


	// fen 3a1k3/9/5a3/1P6P/4c4/9/4C4/8B/4A4/5KB2 w - - 0 1
	if(my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(your_shi_num == 2){
			if(count_1s(bb_my_pawn,RankBB_A[MY_RANK3]) == 2){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 2c6/3PP4/4k4/9/9/9/9/3C5/9/3K5 w - - 0 1
	if(my_shi_num == 0 && my_xiang_num == 0){
		if(count_1s(bb_my_pawn,MyUpBB[StoY(yk)]) == 2){
			if(StoY(ypao) == MY_RANK0){
				RETRUN_MUL(4);
			}
			RETRUN_MUL(8);
		}
	}


	// fen 3k5/2P1a4/b4a3/4P4/9/2B6/9/3CB4/3cA4/3A1K3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(have_bit(bb_my_pawn,MyLowBB[MY_RANK2])){
			RETRUN_MUL(8);
		}
	}

	// fen 3k5/2P1a4/b4a3/4P4/9/2B6/9/3CB4/3cA4/3A1K3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(PB90(MY_SQ16) == my_pawn && have_bit(bb_your_shi,RankBB_A[MY_RANK2])){
			RETRUN_MUL(8);
		}
	}

	// fen 2b1k4/5P3/9/9/1cb6/6P2/9/5A3/3KC4/5A3 w - - 0 1
	if(my_xiang_num == 2 && your_shi_num == 0 && EV_MY_CAN <= 1){
		if(StoX(yk) == 0x4 && have_bit(bb_my_pawn,MyUpBB[MY_RANK2])){
			RETRUN_MUL(8);
		}
	}

	// fen 9/4P4/3kb4/6C2/1cb6/6P2/9/5A3/9/4KA3 b - - 0 1
	if(your_xiang_num == 2 && my_shi_num == 0 && EV_MY_CAN <= 1){
		if(have_bit(bb_my_pawn,MyUpBB[StoY(yk)])){
			RETRUN_MUL(8);
		}
	}

	if(have_bit(bb_my_pawn,RankBB_A[MY_RANK0])){
		if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
			if(have_bit(bb_your_shi,RankBB_A[MY_RANK2])){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3a5/1C3PP2/1c1k1a3/9/9/9/9/4BA3/4A4/4K4 w - - 0 1
	if(your_shi_num == 2){
		if(count_1s(MyUpBB[StoY(yk)],bb_my_pawn) == 2){
			RETRUN_MUL(8);
		}
	}

	// fen 9/4ak3/2Pa3P1/9/6b2/4C4/4c4/3AK4/9/9 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1){
		if (!have_bit(bb_my_pawn, MyLowBB[MY_RANK2])){
			MY_EV_SUB(64);
			if (have_bit(bb_my_pawn, LeftBB[0x4])
				&& have_bit(bb_my_pawn, RightBB[0x4])){
				if (have_bit(bb_your_shi, RankBB_A[MY_RANK2])){
					MY_EV_SUB(64);
					if (StoY(mpao) MY_SMALL StoY(ypao) && StoY(mpao) MY_SMALL_EQL MY_RANK5){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 3a1k3/9/5a3/1P6P/4c4/9/4C4/8B/4A4/5KB2 w - - 0 1
	if(my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8 && your_shi_num == 2){
		RETRUN_MUL(8);
	}
}

////我方一炮二兵，对方一炮
//void m_MT_B_1PAO2PAWN_R_1PAO(typePOS &POSITION, EvalInfo &ei){
///*
//	int    rk      = PieceListStart(board,RKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -=  ADD_1PaoXPawn_1Pao_ByPawn[board->R_shi];
//		}
//	}
//
//
//	Square bpawn1 = PieceListStart(board,BPAWN);
//	Square bpawn2 = NextPiece(board,bpawn1);
//	int rpao   = PieceListStart(board,RPAO);
//
//	if(Is_BhaveTianMenShuanCanControl_Rking(board)){  //有铁门栓
//
//		return 16;
//	}
//
//	// fen 9/4k4/b4P3/9/6bc1/P3C4/9/9/9/3K5 w - - 53 53
//	if(board->B_shi == 0 && board->B_xiang == 0 && board->R_xiang == 2){
//		//1个兵过河了,一个兵不能过河
//		if(StoY(bpawn1) < 0x8){ //此兵没有过河,且不能过河
//			if(StoY(bpawn2) >= 0xa){
//				if(StoX(bpawn1) < 0x7){
//					if(board->b256[0x89] == RXIANG){
//						if(board->b256[0x8a] == RPAO){
//							return 1;
//						}
//					}
//				}
//				if(StoX(bpawn1) > 0x7){
//					if(board->b256[0x85] == RXIANG){
//						if(board->b256[0x84] == RPAO){
//							return 1;
//						}
//					}
//				}
//			}
//		}
//
//		if(StoY(bpawn2) < 0x8){
//			if(StoY(bpawn1) >= 0xa){
//				if(StoX(bpawn2) < 0x7){
//					if(board->b256[0x89] == RXIANG){
//						if(board->b256[0x8a] == RPAO){
//							return 1;
//						}
//					}
//				}
//				if(StoX(bpawn2) > 0x7){
//					if(board->b256[0x85] == RXIANG){
//						if(board->b256[0x84] == RPAO){
//							return 1;
//						}
//					}
//				}
//			}
//		}
//	}
//
//
//	// fen 4P4/3k5/5P2b/7C1/9/2B6/4c4/8B/4K4/9 w - - 255 255
//	//如果红方没有仕,且只有一个可过河,对方还有相,则是和棋
//	if(board->B_shi == 0){
//		//有一个兵到了底线
//		if(StoY(bpawn1) == 0xc || StoY(bpawn2) == 0xc){
//			if(board->R_xiang >= 1){
//				return 1;
//			}
//		}
//	}
//
//	// fen 3k5/2P1a1P2/4ba3/4cC3/9/9/9/9/4K4/9 b - - 145 145
//	if(board->R_shi == 2 && board->R_xiang >= 1){
//		if(StoY(bpawn1) >= 0xb && StoY(bpawn2) >= 0xb){
//			if(board->b256[0xb6] == BPAWN && board->b256[0xb8] == BPAWN && board->b256[0xc7] == RKING){
//			}
//			else{
//				//二个兵不在一边
//				if(IsOnSameSide(bpawn1,bpawn2) == FALSE){
//					if(board->B_shi == 0){
//						return 1;
//					}
//				}
//			}
//		}
//	}
//
//	// fen 2P3P2/3k5/3a5/9/9/3c3C1/9/9/5K3/9 b - - 0 0
//	if(StoY(bpawn1) == 0xc && StoY(bpawn2) == 0xc){
//		if(board->B_shi == 0 && board->B_xiang == 0){
//			return 1;
//		}
//	}
//
//
//	//if((Info16 & CK_R_2s) && (Info16 & CK_R_2x)){
//	if(board->R_shi == 2 && board->R_xiang == 2){
//		//board->mulScore /= 4;
//		return 2;
//	}
//
//	// fen 2b1k4/2P2P3/3a4b/9/9/9/3c5/9/9/5K1C1 w - - 121 121
//	if(board->R_shi >= 1 && board->R_xiang == 2){
//		if(board->B_shi == 0 && board->B_xiang == 0){
//			if(IsOnSameSide(bpawn1,bpawn2) == FALSE 
//				&& StoY(bpawn1) >= 0xb && StoY(bpawn2) >= 0xb){
//				if(board->b256[0xa6] == RSHI 
//					&& (StoX(bpawn1) <= 0x5 || StoX(bpawn2) <= 0x5)){
//					return 2;
//				}
//				if(board->b256[0xa8] == RSHI 
//					&& (StoX(bpawn1) >= 0x9 || StoX(bpawn2) >= 0x9)){
//					return 2;
//				}
//			}
//		}
//	}
//
//	// fen 9/4ck3/5a3/9/2b3b2/9/9/4Bp1p1/2C1A4/4K1B2 w - - 0 0
//	if(board->R_shi >= 1 && board->R_xiang == 2){
//		if(StoY(bpawn1) == 0xa && StoY(bpawn2) == 0xa && StoY(rpao) == 0xb){
//			if(IsOnSameSide(bpawn1,bpawn2) && !IsOnSameSide(bpawn1,rpao)){
//				return 4;
//			}
//		}
//	}
//
//	// fen 4k4/4a4/9/4P4/1cb6/8P/9/9/5K3/4C4 b - - 40 40
//	if(board->B_shi == 0 && board->B_xiang == 0){
//		if(board->R_shi >= 1 && board->R_xiang >= 1){
//			if(StoY(bpawn1) <= 0x7 || StoY(bpawn2) <= 0x7){
//				return 4;
//			}
//		}
//	}
//
//
//	// fen 5c3/3k5/4ba3/9/9/2B6/4C4/4K4/3p5/3p5 b - - 121 121
//	//二个兵,一个到了底线,一个在二线以下,有可能是和棋
//	if(board->R_xiang >= 1 && StoY(rk) == 0xa){
//		if((StoY(bpawn1) + StoY(bpawn2)) > (0xb*2)){
//			return 4;
//		}
//	}
//
//	
//	// fen 3k1a3/1P7/5a3/7P1/2b5C/6B2/4c4/9/9/4K4 w - - 127 127
//	if(board->B_shi == 0){
//		if(board->R_shi == 2 && board->R_xiang >= 1 && StoX(rk) != 0x7){
//			return 8;
//		}
//	}
//
//
//
//	*/
//}
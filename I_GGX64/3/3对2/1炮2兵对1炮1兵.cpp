#ifndef END_my_m_MT_R_1pao2pawn_B_1pao1pawn
#define END_my_m_MT_R_1pao2pawn_B_1pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮2兵对1炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1pao2pawn_B_1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_PaoXPawn_To_PaoPawnByShi[your_shi_num]);

	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_PaoXPawn_To_PaoPawnByShi[my_shi_num]);

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	// fen 5k3/2P1a1P2/4b4/1C7/3c2b2/5p3/9/9/9/2BK1A3 b - - 0 1
	if (StoY(ypawn) == MY_RANK6 || StoY(ypawn) == MY_RANK5){
		MY_EV_SUB(64);
		if (my_shi_num <= 1){
			MY_EV_SUB(32);
		}
	}

	if (EV_MY_CAN >= 1){
		EV_MY_SAFE = true;
	}

	// fen 3ak4/9/P2ab1P2/9/6b2/5p3/9/4B4/4A4/2B1KAC1c w - - 0 0
	if((your_shi_num + your_xiang_num) == 4){
		if(PB90(MY_SQ15) == your_shi || PB90(MY_SQ17) == your_shi){
			EV_YOUR_SAFE = TRUE;
		}
		if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
			EV_YOUR_SAFE = TRUE;
		}
	}

	// fen 4kab2/4a4/4b4/p3P3C/7P1/c8/9/9/4K4/3A1AB2 w - - 0 0
	if((my_shi_num + my_xiang_num) >= 2){
		EV_MY_SAFE = TRUE;
	}

	
	// fen 4ka3/9/4ba3/C8/8P/c2p5/4P4/4B4/9/3AKA3 w - - 3 3
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(PB90(MY_SQ3A) == my_pawn){
			if(PB90(MY_SQ30) == your_pawn || PB90(MY_SQ32) == your_pawn){
				RETRUN_MUL(2);
			}
		}
	}
	Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);
	Square ypao   = S90_from_piecelist(POSITION,your_pao,0);
	Square mpao   = S90_from_piecelist(POSITION,my_pao,0);



	// fen 9/3Pa2P1/5k3/9/6b2/9/5Cc2/9/4p4/5K3 b - - 0 1
	if(my_shi_num == 0 && MY_SQ4C == ypawn && StoY(mk) == MY_RANK9){
		MY_EV_SUB(64);
		if(count_1s(bb_my_pawn,MyUpBB[StoY(yk)]) == 2){
			MY_EV_SUB(32);
		}
		if(StoX(mpao) == StoX(mk) && StoX(yk) == StoX(mk)){
			MY_EV_SUB(32);
		}
	}

	// fen C3k4/2P1a1P2/4ba3/c8/9/9/9/3A5/3p5/5K3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if((my_shi_num + my_xiang_num) <= 1){
			MY_EV_SUB(EV_YOUR_CAN * 64);
			if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
				if(have_bit(bb_your_shi,RankBB_A[MY_RANK2])){
					MY_EV_SUB(32);
					if(have_bit(LeftBB[0x3],bb_my_pawn) 
						|| have_bit(RightBB[0x5],bb_my_pawn)){
						MY_EV_SUB(EV_YOUR_CAN * 32);
					}
				}

			}
		}
	}

	// fen c8/2P4P1/b3k4/9/4C1b2/9/9/3K5/4p4/9 w - - 0 1
	if(StoY(ypawn) MY_LARGE_EQL StoY(mk)){
		if(your_shi_num == 0){
			EV_MY_SAFE = true;
		}
	}

	// fen 2ba1k3/3P5/3P5/9/9/9/3c5/9/1C2p4/3K5 b - - 0 1
	if(your_shi_num <= 1){
		if(EV_MY_CAN >= 2){
			MY_EV_ADD(EV_MY_CAN * 64);
		}
	}

	// fen 4kaP2/3P3c1/9/4C4/9/9/9/8B/4p4/3K5 w - - 0 1
	if(my_shi_num == 0 && have_bit(bb_my_pawn,RankBB_A[MY_RANK0])){
		MY_EV_SUB(EV_YOUR_CAN * 64);
	}


	// fen 3k1c3/9/3a1a3/4PP3/9/4C4/9/4p4/5K3/3A5 b - - 0 1
	if(my_xiang_num == 0 && my_shi_num <= 1){
		if(MY_SQ43 == ypawn){
			MY_EV_SUB(64);
			if(your_shi_num == 2){
				if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK2])){
					MY_EV_SUB(32);
					// fen 4k4/4ac3/4Pa3/3P5/9/9/3C5/4p4/9/3AK4 b - - 0 1
					if(have_bit(bb_your_shi,RankBB_A[MY_RANK2])){
						if(PB90(MY_SQ16) == my_pawn){
							MY_EV_SUB(32);
						}
					}
				}
				if(StoY(ypao) MY_SMALL_EQL MY_RANK2){
					MY_EV_SUB(32);
				}
			}
		}
	}


	// fen 3a1k3/4a4/2P1b4/9/7C1/4p4/P8/4BA2B/9/3AK3c b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(32);
	}
	// fen 2bak4/4a4/8b/4PP3/9/5C3/4p4/5c3/4A4/4K4 b - - 0 1
	MY_EV_ADD(EV_MY_CAN * 32);

	if(my_shi_num >= 1){
		MY_EV_ADD(32);
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	// fen 9/4a1P2/b4k3/5c3/9/2B6/9/5A3/2pp3C1/3AK4 w - - 131 131
	//黑炮不能动了．
	if(your_shi_num == 2 && your_xiang_num >= 1 && PB90(MY_SQ04) == your_king){
		if(IsOnSameSide(mpawn1,mpawn2) && StoY(mpawn1) MY_SMALL_EQL MY_RANK1
			&& StoY(mpawn2) MY_SMALL_EQL MY_RANK1 && !IsOnSameSide(mpawn1,ypao)){
            if(PB90(MY_SQ0D) == EMPTY && PB90(MY_SQ16) == EMPTY && StoY(ypao) == MY_RANK1){
				if(PB90(MY_SQ42) == my_king && PB90(MY_SQ4A) == your_pawn && PB90(MY_SQ15) == your_shi){
					if(StoX(ypao) < 0X4){
						RETRUN_MUL(2);
					}
				}
				if(PB90(MY_SQ44) == my_king && PB90(MY_SQ4E) == your_pawn && PB90(MY_SQ17) == your_shi){
					if(StoX(ypao) > 0X4){
						RETRUN_MUL(2);
					}
				}
			}
		}
	}
	// fen 2bak2C1/7c1/3a5/9/1P6P/2B6/5p3/9/4A4/4K4 w - - 0 1
	if(EV_MY_CAN == 2 && (your_shi_num + your_xiang_num) <= 3){
		MY_EV_ADD(64);
	}	

	
	if(EV_MY_SAFE){	
		//fen 3aka3/9/9/9/6b2/5p2P/P3c4/4BC3/4A4/3AK1B2 w - - 0 1
		if (your_shi_num == 2 && your_xiang_num >= 1){
			if (StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
				if (abs(StoX(mpawn1) - 0x4) >= 3 || abs(StoX(mpawn2) - 0x4) >= 3)
					RETRUN_MUL(4);
			}
		}

		// fen 5k3/4a4/2Pab4/9/6b2/9/5c3/3CB1pp1/4A4/4KA3 b - - 0 1
		if((your_shi_num + your_xiang_num) >= 3){
			Bitboard mp = m_and(bb_my_pawn,RankBB_A[MY_RANK2]);
			if(count_1s(mp) == 2 && StoY(ypao) == MY_RANK2){
				if(!have_bit(mp,RightBB[0x3]) && PB90(MY_SQ05) == EMPTY){
					if(StoX(ypao) >= 0x5){
						RETRUN_MUL(4);
					}
				}
				if(!have_bit(mp,LeftBB[0x5]) && PB90(MY_SQ03) == EMPTY){
					if(StoX(ypao) <= 0x3){
						RETRUN_MUL(4);
					}
				}
			}
		}
		// fen C1Pa2c2/1P2ak3/9/9/9/2B6/9/4BAp2/4A4/3K5 w - - 0 1
		if(your_shi_num == 2){
			if(have_bit(bb_my_pawn,RankBB_A[MY_RANK0])){ // 有一个底兵
				Bitboard mp = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
				if(!have_bit(mp,RightBB[0x3]) && PB90(MY_SQ05) == EMPTY){
					if(StoX(ypao) >= 0x5 && StoX(yk) == 0x5 && StoY(yk) != MY_RANK0){
						RETRUN_MUL(4);
					}
				}
				if(!have_bit(mp,LeftBB[0x5]) && PB90(MY_SQ03) == EMPTY){
					if(StoX(ypao) <= 0x3 && StoX(yk) == 0x3 && StoY(yk) != MY_RANK0){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 4k4/3Pa3c/4b4/3P5/9/3C5/9/B2p5/4K4/9 w - - 0 1
	if (your_shi_num >= 1 && your_xiang_num >= 1){
		// 找出交叉点的兵。
		Bitboard mpyp = m_and(ei.attacked_by(your_pao), bb_my_pawn);
		while (m_have_bit(mpyp)){
			Square mp = pop_1st_bit_sq(mpyp);
			if (bit_is_set(ei.attacked_by(my_pao), mp)){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4k4/4a4/3ab2P1/5C3/6p2/6B2/6P2/5A3/4A2c1/3K2B2 b - - 0 1
	if (EV_MY_SAFE){
		if (your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if (have_bit(bb_my_pawn, MyUpBB[MY_RANK3])){
				if (have_bit(bb_my_pawn, MyLowBB[MY_RANK4]) && EV_MY_CAN <= 1){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 4kab2/4a4/8c/9/8p/9/2C1P3P/8B/4A4/4KAB2 b - - 0 1
	if(EV_MY_SAFE){
		if((your_shi_num + your_xiang_num) >= 3){
			if(EV_MY_CAN <= 1 && !have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
				Bitboard pp = m_and(ei.attacked_by(my_pao),ei.attacked_by(your_pao));
				if(have_bit(pp,m_and(bb_my_pawn,MyLowBB[MY_RANK4]))){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen c8/2P4P1/b3k4/9/4C1b2/9/9/3K5/4p4/9 w - - 0 1
	if(my_shi_num == 0 && count_1s(bb_my_pawn,MyUpBB[StoY(yk)]) == 2){
		if(StoX(yk) == 0x4){
			RETRUN_MUL(4);
		}
	}

	if (EV_MY_SAFE){
		Bitboard upp = m_and(bb_my_pawn, MyUpBB[StoY(yk)]);
		if (count_1s(upp) == 2 && your_shi_num == 2){
			if (my_shi_num <= 1){
				RETRUN_MUL(4);
			}
			RETRUN_MUL(8);
		}
	}

	// fen 3a5/3kaPC2/6c2/5P3/2b6/9/4p4/4BA3/4A4/4K4 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num >= 1){
			if(StoY(mpao) MY_SMALL_EQL MY_RANK2 && PB90(XYtoS(StoX(yk),MY_RANK2)) != your_shi){
				// 有一个兵在2线以下，且对方的将能向上跑

				if(StoY(ypawn) == MY_RANK6){
					MY_EV_SUB(64);
				}

				Bitboard upp = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
				if(StoX(yk) < 0x4 && have_bit(upp,RightBB[0x4])){
					RETRUN_MUL(8);
				}
				if(StoX(yk) > 0x4 && have_bit(upp,LeftBB[0x4])){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 3k5/4a4/5a3/3P5/c1b6/4C1P2/3p5/5A2B/4A4/4K1B2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(StoY(ypawn) == MY_RANK6){
			MY_EV_SUB(64);
            if(EV_MY_CAN <= 1) RETRUN_MUL(4);
			//print_bb(YOUR_ATTACK);
			if(StoY(mpawn1) MY_SMALL_EQL MY_RANK3){
				if(StoY(mpawn2) MY_LARGE_EQL MY_RANK5){
					if(bit_is_set(YOUR_ATTACK,XYtoS(StoX(mpawn2), MY_RANK4))){
						RETRUN_MUL(8);
					}
				}
			}
			if(StoY(mpawn2) MY_SMALL_EQL MY_RANK3){
				if(StoY(mpawn1) MY_LARGE_EQL MY_RANK5){
					if(bit_is_set(YOUR_ATTACK,XYtoS(StoX(mpawn1), MY_RANK4))){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 3a1a3/9/4k4/3P5/5C3/4c4/9/4BA3/3pA1p2/4K4 w - - 132 132
	if(your_shi_num == 2 && your_xiang_num >= 1 && PB90(MY_SQ04) == your_king){
		if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
			if(abs(StoX(ypawn) - StoX(mk)) <= 1){
				if(PB90(MY_SQ15) == your_shi || PB90(MY_SQ17) == your_shi){
					RETRUN_MUL(8);
				}
			}
		}
	}


	
	// fen 5k3/4a4/3a5/3P5/5c3/6B2/1C1pp4/4B4/4A4/4K4 w
	if((your_xiang_num + your_shi_num) >= 3 && StoY(yk) == MY_RANK0){
		// fen C1bak4/4c4/3ab4/9/3P5/8P/P8/9/4A4/4KAB2 b - - 0 1
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK2])){
			MY_EV_SUB(96);
		}
		else{
			MY_EV_SUB(64);
		}

		if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
			if(StoY(mpawn1) == StoY(mpawn2) && StoY(mpawn1) == StoY(ypao)){
				if(StoY(ypao) == MY_RANK3 || StoY(ypao) == MY_RANK4){
					RETRUN_MUL(8);
				}
			}
			// fen 1Cbaka3/6P2/4P4/1c7/9/2B6/4p4/9/9/3AK4 w - - 0 1
			if(StoY(mpao) == MY_RANK0){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3ak4/4a4/9/1P2p3C/6b2/P8/8c/4B4/4A4/3A1KB2 b - - 0 1
	if (EV_MY_SAFE) {
		if (your_shi_num == 2 && your_xiang_num >= 1) {
			MY_EV_SUB(32);
			if (EV_YOUR_CAN >= 1) {
				MY_EV_SUB(32);
				if (StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6) {
					RETRUN_MUL(8);
				}
			}
		}
	}
	
	// fen 4kab2/4a4/9/3P5/8P/6B2/9/3C5/c2p5/4K4 w - - 0 1
	if(EV_MY_CAN == 2 && my_xiang_num >= 1){
		if(StoX(mk) == 0x4){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
		//if(my_shi_num == 0 && EV_YOUR_CAN >= 1 && (your_shi_num + your_xiang_num) >= 3){
		//	RETRUN_MUL(8);
		//}
	}

	// fen 5k3/4a4/5a3/4CP3/6b1c/P5B2/5p3/3AB4/4A4/4K4 b - - 0 1
	if(your_xiang_num >= 1 && your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(ypawn) == MY_RANK6){
			if(have_bit(bb_my_pawn,MyLowBB[MY_RANK4])){
				if(PB90(MY_SQ2D) == my_pawn && bit_is_set(ei.attacked_by(your_pao),Square(MY_SQ24))){
					RETRUN_MUL(8);
				}
				if(PB90(MY_SQ35) == my_pawn && bit_is_set(ei.attacked_by(your_pao),Square(MY_SQ2C))){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 4k4/2P1a1P2/3abc3/9/9/9/3C5/4K4/9/6p2 b - - 0 1
    if(my_shi_num == 0 && your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(32);
		if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
			if(!IsOnSameSide(mpawn1,mpawn2) && StoY(ypao) MY_SMALL_EQL MY_RANK4){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 2ba1k1C1/2P6/3a5/5P3/2b6/9/9/c8/4p4/5K3 b - - 0 1
	if (EV_YOUR_SAFE){
		if (my_shi_num == 0 && abs(StoY(ypawn) - StoY(mk)) <= 1
			&& StoY(ypawn) MY_SMALL StoY(mk)){
			if (have_bit(bb_my_pawn, RankBB_A[MY_RANK3])){
				RETRUN_MUL(8);
			}
		}
	}

	// fen C3ka3/9/b2ab4/8p/4P4/1c7/9/4B1p2/4A4/3K1A3 w - - 0 1
    if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
			if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK4){
				//中线没有二个兵
				if(have_bit(bb_my_pawn,m_or(LeftBB[0x3],RightBB[0x5]))){
					RETRUN_MUL(8);
				}				
			}
		}
	}

	// fen 3k1ab1C/2P1a2P1/9/9/6p2/9/9/3A4B/5Kc2/9 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num >= 1 && my_xiang_num <= 1){
			if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
				if(!IsOnSameSide(mpawn1,mpawn2) && MY_SQ04 != yk){
					if(have_bit(bb_my_pawn,LeftBB[0x02]) || have_bit(bb_my_pawn,RightBB[0x6])){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 5a3/3kaPC2/9/4P4/6b2/6B2/5c3/3A3p1/9/4KAB2 w - - 0 1
	if(EV_YOUR_CAN >= 1 && StoY(ypawn) MY_SMALL_EQL MY_RANK7){
		if(your_shi_num == 2 && your_xiang_num >= 1){
			if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1){
				if(StoX(mpawn1) > 0x4 && PB90(MY_SQ05) == your_shi){
					RETRUN_MUL(8);
				}
				if(StoX(mpawn1) < 0x4 && PB90(MY_SQ03) == your_shi){
					RETRUN_MUL(8);
				}
			}
			if(StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
				if(StoX(mpawn2) > 0x4 && PB90(MY_SQ05) == your_shi){
					RETRUN_MUL(8);
				}
				if(StoX(mpawn2) < 0x4 && PB90(MY_SQ03) == your_shi){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 2bak4/4a4/8b/4PP3/9/5C3/4p4/5c3/4A4/4K4 b - - 0 1
	if(EV_YOUR_SAFE && StoY(ypawn) == MY_RANK6){
		RETRUN_MUL(8);
	}

	// fen 4kab2/4a4/4b4/C3P4/4P3p/9/8c/5A3/4A4/3K5 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(EV_YOUR_CAN){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3a4C/1PP1a3c/5k3/9/9/2B6/9/3p5/9/4K1B2 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && EV_YOUR_CAN){
			if(count_1s(bb_my_pawn,MyUpBB[StoY(yk)]) == 2){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3a5/3C1k3/2P2aP2/9/6b2/c8/3p5/4B4/4A4/4KAB2 b - - 0 1
	if(StoY(ypawn) == MY_RANK6){
		MY_EV_SUB(32);
		if(your_shi_num == 2 && your_xiang_num >= 1){
			MY_EV_SUB(64);
			if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK2])){
				if((abs(StoX(mpawn1) - 0x4) + abs(StoX(mpawn2) - 0x4)) >= 3){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 2bakc3/9/5a3/4P3p/9/8P/9/3A4B/9/4KA2C w - - 0 1
	if(EV_MY_SAFE){
		if(EV_MY_CAN <= 1 && your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoY(ypao) MY_SMALL_EQL MY_RANK1){
				Bitboard upb = m_and(bb_my_pawn,MyUpBB[MY_RANK5]);
				if(StoX(ypawn) == 0x8 && StoX(ypao) >= 0x5 
					&& have_bit(bb_my_pawn,FileBB_A[0x8])){
						if(have_bit(upb,LeftBB[0x5])){
						   RETRUN_MUL(8);
						}
				}
				if(StoX(ypawn) == 0x0 && StoX(ypao) <= 0x3
					&& have_bit(bb_my_pawn,FileBB_A[0x0])){
						if(have_bit(upb,RightBB[0x3])){
							RETRUN_MUL(8);
						}
				}
			}

		}
	}

	// fen 4k4/4a4/3ab2P1/8p/9/6B1P/8C/4K4/4Ac3/3A5 b - - 0 1
	if(EV_MY_CAN <= 1 && have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
		if(your_shi_num == 2 && your_xiang_num >= 1 && have_bit(bb_your_shi,RankBB_A[MY_RANK2])){
			RETRUN_MUL(8);
		}
	}

	// fen 1C1a5/4ak3/4P4/1c3P3/6b2/9/9/B3K4/5p3/9 w - - 0 1
	if(my_shi_num == 0 && StoY(mpao) MY_SMALL_EQL MY_RANK2){
		if(your_shi_num == 2 && your_xiang_num >= 1 && PB90(MY_SQ16) == my_pawn){
			if(have_bit(bb_my_pawn,RankBB_A[MY_RANK3])){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 5k3/2P1a1P2/4b4/1C7/3c2b2/5p3/9/9/9/2BK1A3 b - - 0 1
	if ((StoY(ypawn) == MY_RANK6 || StoY(ypawn) == MY_RANK5) && my_shi_num <= 1){
		if (your_shi_num >= 1 && your_xiang_num == 2){
			if (count_1s(bb_my_pawn, MyUpBB[MY_RANK2]) == 2){
				if ((abs(StoX(mpawn1) - StoX(yk)) + abs(StoX(mpawn2) - StoX(yk))) >= 3){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 4k4/3PaP3/3a5/9/6b2/2B6/3C1c3/B4K3/2p1A4/9 w - - 0 1
	if (EV_YOUR_CAN){
		if (your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
			if (abs(StoX(ypao) - 0x4) <= 1 && StoY(ypao) MY_SMALL_EQL MY_RANK7){
				if (!have_bit(bb_your_shi, RankBB_A[MY_RANK0])){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 6c2/2P6/b3k4/1C7/9/P8/3p5/9/4A4/3K5 w - - 0 1
	if(my_shi_num <= 1 && my_xiang_num == 0 && your_xiang_num >= 1){
		if(have_bit(bb_my_pawn,MyLowBB[MY_RANK4]) && have_bit(bb_my_pawn,MyUpBB[StoY(yk)])){
			if(StoY(ypawn) == MY_RANK6)
				RETRUN_MUL(8);
			RETRUN_MUL(12);
		}
	}

	// fen 4ka3/9/2Ca2P2/p8/1P4b2/9/6c2/9/4A4/5K3 w - - 0 1
	if (my_xiang_num == 0 && your_shi_num == 2 && your_xiang_num >= 1){
		if (have_bit(MyLowBB[MY_RANK3], bb_my_pawn)){
			RETRUN_MUL(8);
		}
	}

	// fen 3ak4/4a4/9/1P2p3C/6b2/P8/8c/4B4/4A4/3A1KB2 b - - 0 1
	if (EV_MY_SAFE) {
		if (your_shi_num == 2 && your_xiang_num >= 1 && EV_YOUR_CAN >= 1) {
			MY_EV_SUB(32);
			if (StoY(ypawn) MY_SMALL MY_RANK7 && StoY(yk) MY_SMALL_EQL MY_RANK1) {
				RETRUN_MUL(8);
			}
		}
	}
}


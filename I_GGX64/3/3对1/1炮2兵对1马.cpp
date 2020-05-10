#ifndef END_my_m_MT_R_1PAO2PAWN_B_1MA
#define END_my_m_MT_R_1PAO2PAWN_B_1MA
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮2兵对1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int Panw_Add = 96;
//ADD_1PaoXPawn_1Ma_ByPawn

//我方一炮二兵，对方一马
void my_m_MT_R_1PAO2PAWN_B_1MA(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// fen 5k3/4c4/9/9/2N6/9/9/4K3B/1p7/7p1 w - - 0 0
	// 二兵到将下面，且没有仕。 
	if(my_shi_num == 0){
		//if(!m_have_bit(m_and(MyLowBB[StoY(yk) my_sub],bb_my_pawn))){
		//	RETRUN_MUL(2);
		//}
		if (count_1s(bb_my_pawn, MyUpBB[StoY(yk)]) == 2) {
			RETRUN_MUL(2);
		}
	}

	//

	Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);
	Square yma    = S90_from_piecelist(POSITION,your_ma,0);
	Square mpao   = S90_from_piecelist(POSITION,my_pao,0);

	// fen 3k5/2P1a4/5a2b/2P6/9/2B1n4/C8/4B4/9/4K4 b - - 0 1
	if(my_shi_num == 0){
		if(your_shi_num == 2 && your_xiang_num >= 1){
			MY_EV_SUB(64);
		}
	}

	// fen 3a5/2P1aP3/b2k5/9/6b2/2B3B2/2n6/2CA5/4AK3/9 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(count_1s(MyUpBB[StoY(yk)],bb_my_pawn) == 2){
			MY_EV_SUB(64);
			if(!bit_is_set(EV_MY_XBIT,yma)){
				MY_EV_SUB(64);
			}
			if(abs(StoY(yma) - MY_RANK7) <= 2){
				MY_EV_SUB(64);
			}
		}
		MY_EV_SUB(64);
	}
	
	// fen 5k3/4a4/3a5/9/9/4N4/9/B8/3KA4/cp3Ap2 w 
	if(StoY(mpawn1) == MY_RANK0 && StoY(mpawn2) == MY_RANK0){
		if((your_shi_num + your_xiang_num) >= 2){
			RETRUN_MUL(2);
		}
	}

	// fen 4k1b2/3Pa4/1P1ab4/9/1n7/9/9/4BA3/5C3/2BAK4 w - - 0 1
    if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
		if(PB90(MY_SQ03) != your_shi && PB90(MY_SQ05) != your_shi){
			if(StoY(yma) MY_LARGE_EQL MY_RANK2 && !have_bit(MyLowBB[MY_RANK2],bb_my_pawn)){
				if(StoX(mpawn1) < 0x4 && StoX(mpawn2) < 0x4){
					RETRUN_MUL(2);
				}
				if(StoX(mpawn1) > 0x4 && StoX(mpawn2) > 0x4){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 5a3/4aPP2/b2k4b/9/9/9/9/7n1/3CK4/3A5 w - - 0 1
	if(my_xiang_num == 0 && my_shi_num <= 1 && !bit_is_set(EV_MY_XBIT,yma)){
		if(count_1s(MyUpBB[StoY(yk)],bb_my_pawn) == 2){
			if(your_shi_num == 2 && your_xiang_num == 2){
				RETRUN_MUL(3);
			}
		}
	}

	// fen 1Cbak4/2PPa4/b8/3n5/9/9/9/9/4A4/2B2KB2 b - - 0 1



	// fen 3c5/4ak3/3a5/9/9/4N1B2/9/4BA3/3pAp3/4K4 w - - 0 0
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		Bitboard psuper = POSITION.Pao_Super_bb(mpao);
		if(bit_is_set(psuper,yk)){
		}
		else{
			if(StoY(yma) MY_SMALL_EQL MY_RANK4){
				if(PB90(MY_SQ15) == your_shi || PB90(MY_SQ17) == your_shi){
					RETRUN_MUL(2);
				}
				RETRUN_MUL(3);
			}
		}
		RETRUN_MUL(4);
	}

	// fen 5a3/3Pak3/b8/9/9/2Pn5/9/4BA3/3K5/5C3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && EV_MY_CAN <= 1 && StoY(yk) != MY_RANK0){
        if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && !IsOnSameSide(mpawn1,yk)){
			RETRUN_MUL(4);
		}
		if(StoY(mpawn2) MY_SMALL_EQL MY_RANK1 && !IsOnSameSide(mpawn2,yk)){
			RETRUN_MUL(4);
		}
	}

	// fen 5a3/3Pa1P2/b4k3/9/2n6/9/9/9/4K4/2BC1A3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(StoY(yk) == MY_RANK2 && !have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
			//
			if(my_shi_num <= 1 && StoY(yma) MY_LARGE_EQL MY_RANK4){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4k4/9/b4P2b/9/9/2B1C1P2/5n3/4B4/9/3K5 w - - 0 1
	if (your_xiang_num == 2 && my_shi_num == 0 && have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
		if (have_bit(bb_my_pawn, MyLowBB[MY_RANK4])){
			if (EV_MY_CAN <= 1){
				RETRUN_MUL(4);
			}
			if (PB90(MY_SQ33) == my_pawn && MY_SQ3B == yma){
				RETRUN_MUL(4);
			}
			if (PB90(MY_SQ2F) == my_pawn && MY_SQ39 == yma){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 1P1k1a3/4a4/b5C2/3P5/4n4/9/9/9/4A4/4K4 b - - 0 1
	if(your_shi_num == 2 && your_shi_num >=1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(have_bit(bb_my_pawn,RankBB_A[MY_RANK0])){
			if(have_bit(bb_my_pawn,MyLowBB[MY_RANK2]) && StoX(yk) != 0x4){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3k4P/6P2/3aba3/9/9/9/5n3/5K3/9/4C4 w - - 0 1
	if(my_shi_num == 0 && my_xiang_num == 0){
		if(your_shi_num == 2 && your_xiang_num >= 1 && have_bit(bb_my_pawn,RankBB_A[MY_RANK0])){
			if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1]) && StoY(yma) MY_LARGE_EQL MY_RANK2){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3a2P2/1P2a4/3k5/9/9/2B3B2/9/9/1n2AK3/4C4 b - - 0 1
	if(StoY(yk) == MY_RANK2 && have_bit(bb_my_pawn,RankBB_A[MY_RANK0])){
		if(your_shi_num == 2 || your_xiang_num == 2){
			if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
				if(StoY(yma) MY_LARGE_EQL MY_RANK5 && my_shi_num <= 1){
					if(StoX(yk) <= 0x4 && StoX(yma) < 0x4){
						RETRUN_MUL(4);
					}
					if(StoX(yk) >= 0x4 && StoX(yma) > 0x4){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 9/3k1P1P1/3ab4/9/2b6/3n5/3C5/5A3/5K3/3A5 w - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) != MY_RANK0){
		if(StoX(yk) < 0x4 && !have_bit(bb_my_pawn,LeftBB[0x4])){
			RETRUN_MUL(4);
		}
		if(StoX(yk) > 0x4 && !have_bit(bb_my_pawn,RightBB[0x4])){
			RETRUN_MUL(4);
		}
	}

	// fen 9/4P4/3k4b/9/9/6P2/9/B3B4/4K2n1/4C4 b - - 135 135</
	if(EV_MY_CAN <= 1 && my_shi_num == 0 && your_xiang_num >= 1){
		Bitboard p = m_and(bb_my_pawn, MyUpBB[StoY(yk)]);
		if(count_1s(p) >= 1){
		  RETRUN_MUL(4);
		}
	}

	// fen 4Pab2/2P2k3/5a3/2n6/6b2/6B2/9/4BA3/3K1C3/3A5 b - - 0 105
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn1) == MY_RANK0 || StoY(mpawn2) == MY_RANK1){
			if(EV_MY_CAN <= 1){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3a5/3k2c2/4ba3/9/2p3b2/4N4/9/B3BA3/5p3/4K4 w - - 0 123
	if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(EV_MY_CAN <= 1){
			//MY_EV_SUB(96);
			RETRUN_MUL(4);
		}
	}

	// fen 9/2P1k1P2/1n1a1a3/9/6b2/2B6/9/3A5/9/4CKB2 r
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK1){
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
			if(abs(StoY(yma) - MY_RANK4) <= 2){
				if((abs(StoX(mpawn1) - 0x4) + abs(StoX(mpawn2) - 0x4)) >= 4){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 5a3/2P1aP3/4k4/9/2b3b2/6B2/9/3AB4/1n2A4/2C2K3 w - - 0 1
    if(your_xiang_num == 2){
		if(count_1s(bb_my_pawn,MyUpBB[StoY(yk)]) == 2){
			if(abs(StoY(yma) - MY_RANK6) <= 2){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 2b2k3/4a4/5c3/9/9/9/5N3/B3BA3/2pp1K3/5A3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK1){
		if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
			if(StoX(mpawn1) > 0x4 && StoX(mpawn2) > 0x4 && yk == MY_SQ0C){
				if(PB90(MY_SQ05) != your_shi){
					RETRUN_MUL(4);
				}
			}
			if(StoX(mpawn1) < 0x4 && StoX(mpawn2) < 0x4 && yk == MY_SQ0E){
				if(PB90(MY_SQ03) != your_shi){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 9/2P2k3/1P1a1a3/9/2bn5/9/9/5A3/9/2B1KCB2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(abs(StoY(yma) - MY_RANK4) <= 2 && !have_bit(bb_my_pawn,MyLowBB[MY_RANK2])){
			if(StoX(yk) >= 0x4 && !have_bit(bb_my_pawn,RightBB[0x3])){
				RETRUN_MUL(4);
			}
			if(StoX(yk) <= 0x4 && !have_bit(bb_my_pawn,LeftBB[0x5])){
				RETRUN_MUL(4);
			}
		}

	}

	// fen 9/2P2k3/1P1a1a3/9/2bn5/9/9/5A3/9/2B1KCB2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(abs(StoY(yma) - MY_RANK4) <= 2 && !have_bit(bb_my_pawn,MyLowBB[MY_RANK2])){
			if(have_bit(bb_my_pawn,RankBB_A[MY_RANK0])){
				if(StoY(yk) == MY_RANK1){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 5a3/2P3P2/3abk3/9/9/9/9/5A3/3KA2n1/6C2 b - - 0 1
	if(StoY(yk) == MY_RANK2 && !have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
		if((your_shi_num + your_xiang_num) >=  3){
			// fen 5a3/2P3P2/3abk3/9/9/9/5n3/5A3/3KA4/5C3 b
			if(abs(StoY(yma) - MY_RANK7) <= 2 && !bit_is_set(EV_MY_XBIT,yma)){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 7P1/4aP3/4k4/9/6b2/2B6/9/5A3/3KA4/2C1n4 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) == MY_RANK2){
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK2]) && have_bit(bb_my_pawn,RankBB_A[MY_RANK0])){
			if(StoY(yma) MY_LARGE_EQL MY_RANK5 && !bit_is_set(EV_MY_XBIT,yma)){
				RETRUN_MUL(4); // fen 7P1/4aP3/4k4/9/6b2/2B6/4n4/5A3/3KA4/4C4 b
			}
		}
	}

	if(my_shi_num == 0){
		if(your_shi_num == 2 && your_xiang_num >= 1){
			if(!have_bit(MyLowBB[StoY(yma)],bb_my_pawn)){
				if(!have_bit(bb_my_pawn,m_or(LeftBB[0x6],RightBB[0x2]))){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 4ka1P1/4a4/8b/2P6/9/9/5C3/4Kn3/9/9 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && my_shi_num == 0
		&& have_bit(bb_my_pawn,RankBB_A[MY_RANK0])){
        if(!bit_is_set(EV_MY_XBIT,yma)){
			RETRUN_MUL(4);
		}
	}

	// fen 4k4/2P1a2P1/3a5/7n1/2b6/9/9/3A1A3/9/3K3C1 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(have_bit(bb_your_shi,RankBB_A[MY_RANK2])){
			if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
				if(!bit_is_set(EV_MY_XBIT,yma)){
					if(have_bit(LeftBB[0x3],bb_my_pawn)){
						RETRUN_MUL(4);
					}
					if(have_bit(RightBB[0x5],bb_my_pawn)){
						RETRUN_MUL(4);
					}
				}

			}
		}
	}

	// fen 4k4/4a1P2/3a5/5P3/6b2/9/2n6/9/9/2BK1C3 b - - 0 1
	if (my_shi_num == 0){
		if (your_shi_num == 2 && your_xiang_num >= 1){
			if (StoY(yma) MY_LARGE_EQL MY_RANK3){
				if ((
					(abs(StoX(mpawn1) - StoX(yk)) 
					+ abs(StoY(mpawn1) - StoY(yk)))
					+ (abs(StoX(mpawn2) - StoX(yk))
					+ abs(StoY(mpawn2) - StoY(yk)))) >= 5){
					RETRUN_MUL(4);
				}
			}
		}
	}

	if(my_shi_num == 0){
		if(your_shi_num == 2 && your_xiang_num >= 1){
			RETRUN_MUL(8);
		}
	}


	// fen fen 3k2b2/9/4b4/1c7/4N4/2B6/2p6/2p1B4/4A4/4K4 b - - 0 
	if(your_shi_num >= 1 && your_xiang_num == 2 && my_shi_num == 0){
		RETRUN_MUL(8);
	}

	// fen 2P6/3k1P3/5a3/9/9/4n1B2/3C5/4K4/4A4/9 b - - 0 1
	if(your_shi_num >= 1 && StoY(yk) != MY_RANK0 && my_shi_num <= 1){
		if(!bit_is_set(EV_MY_XBIT,yma)){ // fen 2P6/3k1P3/5a3/9/9/3n2B2/9/3K5/4AC3/9 r
			if(StoY(mpawn1) == MY_RANK0 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
				RETRUN_MUL(8);
			}
			if(StoY(mpawn2) == MY_RANK0 && StoY(mpawn1) MY_SMALL_EQL MY_RANK1){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4k4/2P1a2P1/3a5/7n1/2b6/9/9/3A1A3/9/3K3C1 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(have_bit(bb_your_shi,RankBB_A[MY_RANK2])){	
			if(!bit_is_set(EV_MY_XBIT,yma)){	
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4k4/2P1aP3/5a3/9/n5b2/2B6/9/9/3KA4/5CB2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && MY_SQ04 == yk){
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1]) && have_bit(bb_your_shi,RankBB_A[MY_RANK2])){
			if(!IsOnSameSide(mpawn1,mpawn2) && StoY(yma) MY_SMALL_EQL MY_RANK4){
				if(abs(StoX(mpawn1) - 0x4) >= 2 || abs(StoX(mpawn2) - 0x4) >= 2){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 6P2/2P1ak1C1/5a2b/9/9/9/5n3/5A3/4A4/2B2K3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && have_bit(bb_my_pawn,RankBB_A[MY_RANK0])){
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1]) && !IsOnSameSide(mpawn1,mpawn2)){
			if(StoY(yk) != MY_RANK0 && !bit_is_set(EV_MY_XBIT,yma)){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 9/2P1k1P2/1n1a1a3/9/6b2/2B6/9/3A5/9/4CKB2 r
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK1){
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
			if(abs(StoY(yma) - MY_RANK4) <= 2){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3a5/2P1a4/3k2P2/3n5/2b3b2/9/C8/B2AK4/9/3A5 w - - 0 1
	if(your_xiang_num == 2 && your_xiang_num == 2 && have_bit(bb_my_pawn,RankBB_A[StoY(yk)])){
		if(!IsOnSameSide(mpawn1,mpawn2)){
			if(!bit_is_set(EV_MY_XBIT,yma)){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 1P1k1a3/4a4/b5C2/3P5/4n4/9/9/9/4A4/4K4 b - - 0 1
	if(your_shi_num == 2 && your_shi_num >=1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(have_bit(bb_my_pawn,RankBB_A[MY_RANK0])){
			RETRUN_MUL(8);
		}
	}
}


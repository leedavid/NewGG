#ifndef END_my_m_MT_R_1ma2pawn_B_1ma1pawn_s
#define END_my_m_MT_R_1ma2pawn_B_1ma1pawn_s
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马2兵对1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//
//const int PawnNotSameSide = 64;         //二兵方的兵不在一边,要加分

void my_m_MT_R_1ma2pawn_B_1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_MaPawn_To_MaPawnByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_MaPawn_To_MaPawnByShi[my_shi_num]);

	Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);
	Square ypawn  = S90_from_piecelist(POSITION,your_pawn,0);

	//兵在二边,得加分
	// fen 3k5/9/2P3P2/9/9/6n2/3N5/5p3/9/4K4 w
	if(!IsOnSameSide(mpawn1,mpawn2)){
		MY_EV_ADD(32);
	}
	Square mma = S90_from_piecelist(POSITION,my_ma,0);
	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	int mcan = EV_MY_CAN;
	int ycan = EV_YOUR_CAN;
	//Square yk = your_king_pos;

	if(my_shi_num >= 1){
		EV_MY_SAFE = TRUE;
	}
	if(EV_YOUR_CAN == 0){
		EV_MY_SAFE = TRUE;
	}
	// fen 3ak4/n3a4/4P4/p1P6/9/2N3B2/6p2/9/4AK3/5AB2 w - - 0 1
	if(my_shi_num >= 1 || StoY(ypawn) == MY_RANK9){
		MY_EV_ADD(96);
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	// fen 4k4/4a4/4b3b/6PN1/9/4n1P2/9/5A2B/4A1p2/3K5 b - - 0 1
	if (your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if (EV_YOUR_CAN >= 1){
			MY_EV_SUB(32);
			if (EV_MY_CAN <= 1){
				MY_EV_SUB(32);
				if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK2])){
					MY_EV_SUB(32);
					if (MY_SQ31 == yma){
						MY_EV_SUB(32);
					}
				}
			}
		}
	}



	// fen 3k1a3/2P1a4/4N4/3P5/4n4/9/9/3A5/7p1/4KAB2 b - - 0 1
	if(your_shi_num == 2 && StoX(yk) != 0x4){
		MY_EV_SUB(64);
		if(EV_YOUR_CAN){
			MY_EV_SUB(32);
		}
	}

	if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(ypawn) == MY_RANK6){
			MY_EV_SUB(96);
		}
	}

	if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
		MY_EV_SUB(64);
	}
	MY_EV_ADD(EV_MY_CAN * 16);
	// fen 4ka3/5P3/4b4/7Np/6n2/6B2/9/3pBK3/4A4/3A5 b - - 0 53
	if(my_shi_num >= 1){
	     MY_EV_ADD(EV_MY_CAN * 32);
	}

	if(MY_SQ1F == yma){
		MY_EV_SUB(80);
	}

	// fen 2ba2bn1/2P2k1N1/5a3/2p3p2/9/9/9/9/4K4/2B3B2 w - - 0 0
    //底兵搜山，全吃光
	if(StoY(mma) == MY_RANK9 && PB90(mma MY_SUB 0x9) == your_ma){
		if(mcan == 0 && ycan >= 1){
			MY_EV_SUB(168);
		}
	}
	if(my_shi_num >= 1 || StoY(ypawn) MY_SMALL_EQL MY_RANK4){
		EV_MY_SAFE = TRUE;
	}
	// 黑马可守着两边下兵
	if(MY_SQ1F == yma && your_shi_num >= 1){
        MY_EV_SUB(80);
	}

	// fen 3k2b2/4a4/5a3/5PP2/4N4/4n1B2/9/3A5/4K1p2/5A3 w
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
			MY_EV_SUB(80);
		}
	}

	// fen 5kb2/4a1PP1/4b4/9/4N4/5nB2/9/3KB4/4Ap3/5A3 w - - 3 3
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn1) MY_SMALL_EQL MY_RANK2 && StoY(mpawn2) MY_SMALL_EQL MY_RANK2){ //二个兵到了底线
		   if(IsOnSameSide(mpawn1,mpawn2)){
			   RETRUN_MUL(2);
		   }	
		}

		//
	}


	// fen 4k1P2/4a2P1/3a5/9/5N3/5nB2/9/3KB4/4Ap3/5A3 b - - 0 0 如果有一个兵到了底线
	if(your_shi_num == 2){
		if(StoY(mpawn1) == MY_RANK0 || StoY(mpawn2) == MY_RANK0){
			if(StoX(mpawn1) > 0x4 && StoX(mpawn2) > 0x4 ){
				RETRUN_MUL(2);
			}
			if(StoX(mpawn1) < 0x4 && StoX(mpawn2) < 0x4){
				RETRUN_MUL(2);
			}
		}
	}


	//如果红方的可过河兵==0; 
	//int rcan = rcan;
	if(mcan == 0){
		// fen 4k4/9/5a3/3N5/p2n5/9/P8/5K3/4p4/2B6 w - - 0 0
		if((your_shi_num + your_xiang_num) >= 1){
			RETRUN_MUL(2);
		}
	}

	// fen 2bak4/4a4/9/2P6/2p6/1N2n4/2P6/3AB4/4A4/2BK5 w - - 4 4
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(PB90(ypawn MY_ADD 18) == my_pawn || PB90(ypawn MY_ADD 27) == my_pawn){
			RETRUN_MUL(2);
		}
	}
	//***********************************
	// fen 5P3/5P3/5k3/6N2/9/9/9/B2n5/9/p3K4 w - - 88 88
	//双方都是低兵了
	if(StoY(ypawn) == MY_RANK9){
		EV_MY_SAFE = TRUE;
	}
	if(StoY(ypawn) MY_LARGE_EQL StoY(mk)){
		EV_MY_SAFE = TRUE;
	}

	


	if(StoY(mpawn1) MY_SMALL StoY(yk) && StoY(mpawn2) MY_SMALL StoY(yk)){
		if(StoY(mpawn1) == MY_RANK0){
			EV_YOUR_SAFE = TRUE;
		}
		if(StoY(mpawn2) == MY_RANK0){
			EV_YOUR_SAFE = TRUE;
		}
	}
	//Square yma = S90_from_piecelist(POSITION,your_ma,0);
    // fen 3k5/4a4/5aP2/p8/9/Pn7/1N7/3AB4/4K4/3A5 w - - 30 30
	if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(PB90(ypawn MY_ADD 18) == my_pawn || PB90(ypawn MY_ADD 27) == my_pawn){
			if(StoY(mpawn1) MY_SMALL_EQL MY_RANK2 || StoY(mpawn2) MY_SMALL_EQL MY_RANK2){
				if(abs(StoX(yma) - StoX(ypawn)) <= 2){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 2b6/4PP3/3k5/1N7/9/4n4/9/9/3pA4/3A1K3 b - - 0 1
	if(EV_MY_SAFE){
		if(count_1s(bb_my_pawn,MyUpBB[StoY(yk)]) == 2){
			if(EV_YOUR_CAN){
				if(your_xiang_num >= 1){
					if(abs(StoY(yma) - MY_RANK5) <= 2){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 3a1ab2/1P3k1N1/7n1/3P5/2b6/9/9/4B4/3K5/4p4 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2){
		if (mma == 0x10 && yma == 0x19){
			if (!have_bit(RightBB[0x4], bb_my_pawn)){
				RETRUN_MUL(4);
			}
		}
		if (mma == 0x0A && yma == 0x13){
			if (!have_bit(LeftBB[0x4], bb_my_pawn)){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3ak4/3Pa4/4P1N2/3n5/9/6B2/9/9/3K1p3/5A3 b - - 0 1
	if(EV_MY_SAFE){
		if(EV_YOUR_CAN >= 1){
			if(your_shi_num == 2 && PB90(MY_SQ16) == my_pawn){
				if(have_bit(bb_my_pawn,MyUpBB[MY_RANK2])){
					if(bit_is_set(ei.attacked_by(your_ma),MY_SQ0D) 
						&& !have_bit(bb_your_shi,MyLowBB[MY_RANK1])){
							RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 3k1a3/2P1a4/1Nn1P4/9/9/2B6/9/3A4B/3p1K3/9 b - - 0 1
	if(EV_MY_SAFE){
		if(EV_YOUR_CAN >= 1 && your_shi_num == 2){
			if(PB90(MY_SQ16) == my_pawn && StoX(yk) != 0x4){
				if(have_bit(bb_my_pawn,MyUpBB[MY_RANK2])){
					if(StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi && MY_SQ14 == yma){
						RETRUN_MUL(4);
					}
					if(StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi && MY_SQ18 == yma){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	int malr = My_pawn_already_over_river(POSITION);
	//***********************************
	// fen 3ak4/9/5a3/p8/2b3n2/P4NB2/4P4/4B4/4A4/3AK4 w - - 0 
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(PB90(ypawn MY_ADD 18) == my_pawn || PB90(ypawn MY_ADD 27) == my_pawn){
			if(malr == 0){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 5a3/2P2P3/3k1a3/9/2b2Nb2/9/3n5/3K5/6p2/2BA1AB2 w - - 0 1
	if(EV_MY_SAFE){
		if(!have_bit(bb_my_pawn,MyLowBB[StoY(yk) MY_ADD 1])){
			if(((your_shi_num + your_xiang_num) >= 3) && StoY(yma) MY_LARGE StoY(yk)){
				if(StoY(yma) MY_SMALL_EQL MY_RANK6){
					RETRUN_MUL(4);
				}
			}
		}
	}

	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(PB90(MY_SQ15) == your_shi || PB90(MY_SQ17) == your_shi){
				if(StoY(yma) MY_SMALL_EQL MY_RANK4){
					if(MY_SQ03 == yk && PB90(MY_SQ15) == your_shi){

					}
					else if(MY_SQ05 == yk && PB90(MY_SQ17) == your_shi){

					}
					else{
						RETRUN_MUL(4);
					}
				}
			}
			// fen 3a1k3/9/5a3/9/2p3b2/3n1N3/9/4BA3/2p1A4/3K5 w - - 133 133
		}
	}

	// fen 9/4k4/5P2b/9/4n1b2/5NP2/9/3AB4/2p6/3A1KB2 w - - 0 1
	if(EV_MY_CAN <= 1){
		if(your_xiang_num == 2 && StoY(yk) != MY_RANK0){
			if(EV_YOUR_CAN >= 1 && StoY(yma) MY_SMALL_EQL MY_RANK4){
				RETRUN_MUL(4);
			}
		}
	}


	// fen 2bk5/9/3a1a3/4P4/2b6/9/4n4/B1p1N1p1B/4A4/5K3 w - - 120 120
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
		if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
			if(StoY(yma) MY_SMALL_EQL MY_RANK5 && StoY(yma) MY_LARGE_EQL MY_RANK2){
				if(abs(StoX(mpawn1) - 0x4) >= 2 && abs(StoX(mpawn2) - 0x4) >= 2){
					RETRUN_MUL(4);
				}
			}
		}
	}


	// fen 9/4k1P2/3P4b/9/2b6/2Bn5/N8/8B/4p4/3K5 w - - 67 67
	if(my_shi_num == 0 && PB90(MY_SQ4C) == your_pawn && StoY(mk) == MY_RANK9){
		if(StoY(yma) MY_LARGE_EQL MY_RANK5 && StoX(yk) != StoX(mk)){
			if(StoY(yk) MY_LARGE_EQL StoY(mpawn1) || StoY(yk) MY_LARGE_EQL StoY(mpawn2)){
				if(!IsOnSameSide(mpawn1,mpawn2) && StoY(yk) != MY_RANK0 && your_xiang_num >= 1){
					MY_EV_SUB(256);
				}
			}
		}
	}

	// fen 4ka3/4a4/4b4/2P1N3p/9/9/P7n/4B4/4A4/4K1B2 w - - 0 0
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num >= 1 && ycan >= 1){
			if(StoY(mpawn1) MY_LARGE_EQL MY_RANK3 || StoY(mpawn2) MY_LARGE_EQL MY_RANK3){
				if(StoY(yk) MY_SMALL_EQL MY_RANK1 && StoY(yma) MY_SMALL_EQL MY_RANK4){
					RETRUN_MUL(4);
				}
			}
		}
	}


	// fen 5ab2/3k5/2Na5/p8/2b6/PnB6/3p5/9/4A4/5K3 w - - 120 120
	if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn1) MY_SMALL_EQL MY_RANK3 || StoY(mpawn2) MY_SMALL_EQL MY_RANK3){
			Square sq = SQ_END90;
			if(PB90(MY_SQ24) == your_pawn && PB90(MY_SQ36) == my_pawn){
				sq = MY_SQ36;
			}
			if(PB90(MY_SQ2C) == your_pawn && PB90(MY_SQ3E) == my_pawn){
				sq = MY_SQ3E;
			}
			if(sq != SQ_END90){				
				Bitboard matt = POSITION.ma_to_king_attacks_bb(yma);
				if(bit_is_set(matt,sq)){
					RETRUN_MUL(4);
				}
			}
		}
	}
	// fen 3k2b2/1P2a4/4n1P2/3N5/9/9/3p5/5A3/9/3AK4 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn1) MY_SMALL_EQL MY_RANK2 && StoY(mpawn2) MY_SMALL_EQL MY_RANK2){
			if(PB90(MY_SQ16) == your_ma){
				if(abs(StoX(mpawn1) - 0x4) >= 2 && abs(StoX(mpawn2) - 0x4) >= 2){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 9/4k4/8b/p3P4/1n7/PN4B2/9/4BA3/4A4/4K4 w - - 0 1
	if(your_xiang_num >= 1 && EV_MY_CAN <= 1){
		if(PB90(MY_SQ1B) == your_pawn && PB90(MY_SQ2D) == my_pawn){
			if(PB90(MY_SQ25) == your_ma && PB90(MY_SQ2E) == my_ma){
				Bitboard mop = m_and(bb_my_pawn,RightBB[0x03]);
				if(count_1s(mop) == 1){
					RETRUN_MUL(4);
				}
			}
		}
		if(PB90(MY_SQ23) == your_pawn && PB90(MY_SQ35) == my_pawn){
			if(PB90(MY_SQ2B) == your_ma && PB90(MY_SQ34) == my_ma){
				Bitboard mop = m_and(bb_my_pawn,LeftBB[0x05]);
				if(count_1s(mop) == 1){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 5a3/2P6/3ak4/9/pN7/6B2/P8/B1nA5/4A4/5K3 w - - 0 1
	if(your_shi_num == 2 && EV_MY_SAFE <= 1){
		if(have_bit(MyUpBB[StoY(yk)],bb_my_pawn)){
			MY_EV_SUB(96);
            if(StoY(ypawn) MY_SMALL_EQL MY_RANK4){
				Square mp = Square(ypawn MY_ADD 18);
				if(PB90(mp) == my_pawn && abs(StoX(ypawn) - 0x4) == 0x4){
					if(bit_is_set(ei.attacked_by(your_ma),mp) && bit_is_set(ei.attacked_by(my_ma),mp)){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 3k1a3/4aP3/2P1b1N1b/9/9/4n4/9/B3K4/3p5/3A1AB2 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK2]) && abs(StoY(yma) - MY_RANK3) <= 2
				&& (abs(StoX(mpawn1) - 0x4) + abs(StoX(mpawn2) - 0x4)) >= 3){
					if(StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi){
						RETRUN_MUL(4);
					}
					if(StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi){
						RETRUN_MUL(4);
					}
			}
		}
	}

	// fen 9/3ka1P2/3n1a3/3P5/3N5/9/9/3A5/1p2K4/3A2B2 b - - 0 1
	if(EV_YOUR_CAN >= 1 && your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(yma) MY_SMALL_EQL MY_RANK5){
			if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1){
				if(StoX(mpawn1) > 0x4 && PB90(MY_SQ17) == your_shi && StoX(yk) == 0x3){
					RETRUN_MUL(4);
				}
				if(StoX(mpawn1) < 0x4 && PB90(MY_SQ15) == your_shi && StoX(yk) == 0x5){
					RETRUN_MUL(4);
				}
			}
			if(StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
				if(StoX(mpawn2) > 0x4 && PB90(MY_SQ17) == your_shi && StoX(yk) == 0x3){
					RETRUN_MUL(4);
				}
				if(StoX(mpawn2) < 0x4 && PB90(MY_SQ15) == your_shi && StoX(yk) == 0x5){
					RETRUN_MUL(4);
				}
			}
		}
	}


	// fen 2bk5/4a4/b4aP2/4P4/9/9/6N2/4BKn1B/2p1A4/5A3 w - - 0 1
    if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mma) MY_LARGE_EQL MY_RANK5){
			if(abs(StoX(mpawn1) - StoX(yk)) >= 2 || abs(StoX(mpawn2) - StoX(yk)) >= 2){
				MY_EV_SUB(128);
			}
		}
		// fen 2ba1k3/2N1a4/4b4/4P4/9/p3P4/9/2n1B4/4A4/2BAK4 b - - 0 1
		if(EV_MY_SAFE){
			if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
				if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK2])){
					RETRUN_MUL(4);
				}
			}
			//RETRUN_MUL(8);
		}
	}

	// fen 3a5/3Pak3/b3n1P2/5N3/9/6B2/9/3A1A2B/3p5/5K3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK2]) && !IsOnSameSide(mpawn1,mpawn2)){
			if(PB90(MY_SQ16) == your_ma ){
				if(StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi){
					RETRUN_MUL(4);
				}
				if(StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 3a5/3ka1P2/b3b4/7N1/8p/9/4n4/2p2A3/4A4/5K3 w - - 0 1
	if(EV_YOUR_CAN >= 1 && your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK8){
			if(have_bit(bb_my_pawn,MyLowBB[MY_RANK4])){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 2ba1a3/4k4/9/p6N1/2b6/n7P/6P2/4B4/4A4/4KAB2 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK2])){
				RETRUN_MUL(6);
			}
		}
	}

	// fen 2b1k4/4aP3/2n6/9/P5b2/5NB2/9/3K1A3/6p2/2B2A3 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if(have_bit(bb_my_pawn,LeftBB[0x1]) || 
				have_bit(bb_my_pawn,RightBB[0x7])){
					if(StoY(yma) MY_SMALL_EQL MY_RANK5){
						RETRUN_MUL(6);
					}
			}
		}
	}

	// fen 3k2b2/1P2a4/1N2n1P2/9/9/9/3p5/5A3/9/3A1K3 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(ypawn) == MY_RANK6){
			if(StoY(mpawn1) MY_SMALL_EQL MY_RANK2 && StoY(mpawn2) MY_SMALL_EQL MY_RANK2){
				if(abs(StoX(mpawn1) - 0x4) >= 2 && abs(StoX(mpawn2) - 0x4) >= 2){
					RETRUN_MUL(8);
				}
			}
		}
	}
	
	
	//9/4k1P2/3P4b/9/2b6/2Bn5/N8/8B/4p4/3K5 w - - 67 67
	if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(ypawn) MY_LARGE_EQL MY_RANK5){
		if(mcan <= 1){
			RETRUN_MUL(8);
		}
	}
	// fen 4ka3/5P3/4b4/7Np/6n2/6B2/9/3pBK3/4A4/3A5 b - - 0 1
	//if(my_shi_num >= 1 || EV_YOUR_CAN == 0){
	//	MY_EV_ADD(EV_MY_CAN * 32);
	//}
	//
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yma) MY_SMALL MY_RANK7){
		RETRUN_MUL(8);
	} 

	// fen 5kb2/4a1PP1/4b4/9/4N4/5nB2/9/3KB4/4Ap3/5A3 w - - 3 3
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){

		if(have_bit(bb_my_pawn,RankBB_A[MY_RANK0])){
			MY_EV_SUB(64);
		}

		if(abs(StoX(mpawn1) - 0x4) >= 0x2 || abs(StoX(mpawn2) - 0x4) >= 0x2){
			RETRUN_MUL(8);
		}
	}

	// fen 9/2P1a4/3k5/9/4n4/4N4/9/4K4/3pAp3/9 w - - 0 1
	if(EV_YOUR_CAN && EV_MY_SAFE){
		if(your_shi_num >= 1){
			if(pmok == 0){
				MY_EV_SUB(96);
				RETRUN_MUL(8);
			}
		}
	}

	// fen 9/4ak3/3n1a3/4p4/9/N3P4/1p7/4B4/9/3AK4 b - - 0 1
	if(EV_MY_CAN <= 1){
		MY_EV_SUB(64);
		if(EV_MY_SAFE){		
			if((your_shi_num >= 1 && your_xiang_num >= 1) || (your_shi_num == 2)){
				if(StoY(yk) MY_SMALL_EQL MY_RANK1){
					RETRUN_MUL(8);
				}
			}
		}
	}


	// fen 3k1a3/4a4/3n5/3N5/p8/2B1P4/P8/B2A5/9/3AK4 w - - 0 1
	if(EV_MY_SAFE && EV_MY_CAN <= 1){
		if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
			if(StoY(yma) MY_LARGE_EQL MY_RANK2){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3k5/4aP3/3ab4/3P5/9/3n1N3/9/3A1K3/2p1A4/9 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
			if(have_bit(bb_my_pawn,MyLowBB[MY_RANK2])){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3k1a3/2P1a4/4N4/3P5/4n4/9/9/3A5/7p1/4KAB2 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && StoX(yk) != 0x4 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(8);
		}
	}

	// fen 5k3/4a1P2/3aP4/9/4nN3/9/9/2p6/3K5/2B3B2 w - - 0 1
    if(EV_YOUR_CAN >= 1 && your_shi_num == 2){
		if(PB90(MY_SQ16) == my_pawn && StoY(yma) MY_SMALL_EQL MY_RANK4){
			Bitboard mp = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
			if(count_1s(mp) == 1){
				if(StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi && have_bit(mp,RightBB[0x5])){
					RETRUN_MUL(8);
				}
				if(StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi && have_bit(mp,LeftBB[0x3])){
					RETRUN_MUL(8);
				}
			}
		}
		// fen 9/3ka1P2/3n1a3/3P5/3N5/9/9/3A5/1p2K4/3A2B2 b - - 0 1
		if(StoY(yma) MY_SMALL_EQL MY_RANK4){
			RETRUN_MUL(8);
		}
	}

	// fen 5k3/4a4/5a3/9/1P1N1P3/9/3n1p3/B4A3/4AK3/2B6 w - - 0 1
	if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(ypawn) == MY_RANK6){
			RETRUN_MUL(8);
		}
	}

	// fen 3ak4/4a4/4P4/4P4/9/2n1N4/9/9/p3A4/3A1K3 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
			if(PB90(MY_SQ16) == my_pawn){
				if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK2])){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 3k2b2/2P1a4/b8/5P3/9/3n5/3N5/3p5/4K4/5A3 w - - 0 1
	if(StoY(ypawn) MY_LARGE_EQL MY_RANK6 && StoY(ypawn) MY_SMALL StoY(mk)){
		if(my_xiang_num == 0 && my_shi_num <= 1 && StoY(mma) MY_LARGE_EQL MY_RANK5){
			if((your_xiang_num + your_shi_num) >= 3 && StoX(yk) != 0x4){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 9/5P3/3k5/2N2n2p/2b6/8P/9/9/4A4/4KA3 w - - 0 1
	if(EV_MY_SAFE && EV_MY_CAN <= 1){
		if(your_xiang_num >= 1){
			if(StoY(mpawn1) MY_SMALL_EQL StoY(yk)){
				RETRUN_MUL(8);
			}
			if(StoY(mpawn2) MY_SMALL_EQL StoY(yk)){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4k1b2/3Pa4/4b4/2N2P3/9/5n3/9/5K3/6p2/2BA2B2 b - - 0 1
	if(StoY(ypawn) MY_LARGE_EQL StoY(mk) || my_shi_num >= 1){
		if(your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk) == MY_RANK0){
			if(have_bit(bb_my_pawn,MyLowBB[MY_RANK2])){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 6b2/4k4/4b4/4P2Np/9/4n3P/9/4B4/4K4/2B6 w - - 0 1
	if(EV_MY_CAN <= 1 && your_xiang_num == 2 && EV_MY_SAFE){
		if(PB90(MY_SQ1F) == my_pawn && MY_SQ31 == yma){ 					
			RETRUN_MUL(8);			
		}
	}
	
}



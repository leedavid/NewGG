#ifndef END_my_m_MT_R_1ma2pawn_B_1ma
#define END_my_m_MT_R_1ma2pawn_B_1ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1马2兵对1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1ma2pawn_B_1ma(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pok = (int)count_1s(bmp);
	MY_EV_ADD(pok * ADD_1马兵对1马_by_Pawn_By_Shi[your_shi_num]);

    Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);

	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	// Square yk = your_king_pos;

	if(your_shi_num >= 1 && StoY(yk) == MY_RANK2 && !have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
		if(have_bit(bb_my_pawn,RankBB_A[MY_RANK0])){
			MY_EV_SUB(128);
		}
	}
	// fen 3k5/1P7/3a3N1/1n6p/9/9/P8/B2AB4/9/4K4 w - - 0 1
	if (your_shi_num >= 1){
		if (have_bit(bb_my_pawn, MyLowBB[MY_RANK4])){
			MY_EV_SUB(64);
		}
	}

	// fen 3a1a3/1P2k4/n7b/4P2N1/9/2B3B2/9/9/3K5/9 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if (have_bit(bb_my_pawn, LeftBB[0x2])){
			MY_EV_SUB(64);
		}
		if (have_bit(bb_my_pawn, RightBB[0x6])){
			MY_EV_SUB(64);
		}
	}


	if(MY_SQ1F == yma){  //黑马可守着两边下兵
		MY_EV_SUB(64);
	}
	int mcan = EV_MY_CAN;
	int malr = My_pawn_already_over_river(POSITION);

	// fen 2ba1k3/2N4P1/3a5/9/9/2P6/1n7/9/4A4/3K1A3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(have_bit(bb_my_pawn,MyLowBB[MY_RANK4])){
			MY_EV_SUB(32);
		}
		if(StoX(yk) > 0x4 && !have_bit(bb_your_shi,RightBB[0x4])){
			MY_EV_SUB(64);
		}
		if(StoX(yk) < 0x4 && !have_bit(bb_your_shi,LeftBB[0x4])){
			MY_EV_SUB(64);
		}
	}

	// fen 1P3k3/4a4/3a2P2/9/2b2N3/5nB2/9/3KB4/9/9 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1){

		if(StoX(yk) != 0x4 && PB90(yk MY_ADD 18) != your_shi){
			MY_EV_SUB(64);
		}
		// fen 2P1ka3/9/5a2b/2N3n2/9/8P/9/4B4/4K4/3A1A3 w - - 0 1
		if(StoY(mpawn1) == MY_RANK0 && abs(StoX(mpawn1) - 0x4) >= 2){
			MY_EV_SUB(128);

			if(StoY(mpawn2) MY_LARGE_EQL MY_RANK5){
				MY_EV_SUB(64);
				if(abs(StoX(mpawn2) - 0x4) == 4){
					MY_EV_SUB(64);
				}
			}
		}
		if(StoY(mpawn2) == MY_RANK0 && abs(StoX(mpawn2) - 0x4) >= 2){
			MY_EV_SUB(128);
			if(StoY(mpawn1) MY_LARGE_EQL MY_RANK5){
				MY_EV_SUB(64);
				if(abs(StoX(mpawn1) - 0x4) == 4){
					MY_EV_SUB(64);
				}
			}
		}


	}



	// fen 4k4/5P3/3ab4/9/1N4b2/2P6/3n5/9/5K3/2B6 b - - 121 121
	//只有一个兵可过河,且对方已走成可和的形势
	//如果二个相, 一个以上的仕
	// fen 6b2/9/3abk3/9/6p2/9/9/4B1nNB/5p3/3K1A3 w - - 13 13
	if(your_xiang_num == 2 && your_shi_num >= 1){
		if(mcan == 0){
			RETRUN_MUL(2);
		}

		if(mcan == 1 && malr <= 1){
			if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 || StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
				if(StoX(yk) == 0x3 && PB90(MY_SQ15) == your_shi){
				}
				else if(StoX(yk) == 0x5 && PB90(MY_SQ17) == your_shi){
				}
				else{
					RETRUN_MUL(2);
				}
			}
		}
	}


	// fen 3ak1b2/9/5a3/9/4n4/9/4N4/3A1A3/2p3p2/5K3 w - - 127 127 
	// 二个兵都到了低线
	// 马能守到要位
	if(your_shi_num == 2 && StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
		if(MY_SQ04 == yk && MY_SQ0C == mpawn1 && MY_SQ0E == mpawn2){
		}
		else {
			if(MY_SQ1F == yma){
				RETRUN_MUL(2);
			}
		}
	}
	// fen 6b2/9/3abk3/9/6p2/6B2/9/4B1nN1/9/3K1p3 w - - 0 0
	if(your_xiang_num == 2 && mcan == 0){
		RETRUN_MUL(2);
	}
	
	// 



	if(StoY(mpawn1) == MY_RANK0 && StoY(mpawn2) == MY_RANK0){
		RETRUN_MUL(2);
	}

	//如果二个兵要分别在一边
	if(IsOnSameSide(mpawn1,mpawn2) == FALSE){
		MY_EV_ADD(32);
	}


	// fen 2bk5/5P3/3a1a3/4n4/4N1b2/2B6/9/3AB1p2/4A1p2/5K3 w - - 121 121 
    // fen 6b2/3PP4/5k3/9/5Nb2/6B2/5n3/9/9/2B1KA3 b - - 0 0
	//二个红兵都小于黑将了,
	if(pok == 0){
		if((your_shi_num + your_xiang_num) >= 2){
			RETRUN_MUL(2);
		}
	}

	// fen 1P3k3/4a1P2/4b4/3nN4/9/6B2/9/4B4/4K4/9 b - - 138 138
    //有一个兵到了底线，　另一个兵不能卡肋，
	if(your_xiang_num >= 1 && your_shi_num >= 1 && StoY(yk) == MY_RANK0){
		if(StoY(yma) MY_SMALL_EQL MY_RANK4){
			if(StoY(mpawn1) == MY_RANK0 && StoY(mpawn2) == MY_RANK1 && StoX(yk) != 0x4){
				if(IsOnSameSide(mpawn2,yk)){
					RETRUN_MUL(2);
				}
			}
			if(StoY(mpawn2) == MY_RANK0 && StoY(mpawn1) == MY_RANK1){
				if(IsOnSameSide(mpawn1,yk)){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 6b2/9/3abk3/9/6p2/9/9/4B1nNB/5p3/3K1A3 w - - 13 13
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk)  MY_SMALL_EQL MY_RANK1){
		//要防止二个兵同时卡肋
		if(MY_SQ04 == yk && PB90(MY_SQ0C) == my_pawn && PB90(MY_SQ0E) == my_pawn){
		}
		else{
			RETRUN_MUL(2);
		}
	}

    // fen 2P2a3/3ka4/7P1/9/9/3N1n3/9/4B4/4A4/4K1B2 b - - 0 1
	if(your_shi_num == 2 && have_bit(bb_my_pawn,MyUpBB[MY_RANK1])){  // 有底线兵
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK2])){
			Bitboard p = m_and(bb_my_pawn,MyLowBB[MY_RANK0]);
			if(StoX(yk) == 0x3 && !have_bit(p,LeftBB[0x4])){
				RETRUN_MUL(4);
			}
			if(StoX(yk) == 0x5 && !have_bit(p,RightBB[0x4])){
				RETRUN_MUL(4);
			}
		}
	}


	// fen 2bk5/4a4/b1P6/9/5N3/2P6/3n5/3A1A3/9/4K4 w - - 0 1
	if(EV_MY_CAN <= 1){
		if(your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk) == MY_RANK0){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3]) && StoY(yma) MY_SMALL_EQL MY_RANK5){
				RETRUN_MUL(4);
			}
		}
	}

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

	// fen 5P3/4P4/3kb4/1Nn6/9/9/9/3AK4/9/9 r
	if(your_xiang_num >= 1 && count_1s(bb_my_pawn,MyUpBB[StoY(yk)]) == 2){
		if(have_bit(bb_my_pawn,MyUpBB[MY_RANK1])){  // 有一个兵到了底线了。
			RETRUN_MUL(4);
		}
	}
	

	// fen 6b2/3k5/9/9/9/9/4nN3/3A1A2B/3p1p3/4K4 w - - 123 123
    //这个形好多时候是和棋
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
			if(PB90(MY_SQ15) == your_shi && PB90(MY_SQ17) == your_shi){
				if(StoY(yma) MY_SMALL_EQL MY_RANK3){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen  9/3ka1P2/4b4/6n2/5Nb2/2B3B1P/9/3A1A3/9/5K3 b - - 120 120
    //看死一个兵
	if(your_shi_num >= 1 && your_xiang_num == 2){
		if(StoY(mpawn1) MY_LARGE_EQL MY_RANK5 || StoY(mpawn2) MY_LARGE_EQL MY_RANK5){
			if(StoY(mpawn1) MY_SMALL_EQL StoY(yk) || StoY(mpawn2) MY_SMALL_EQL StoY(yk)){
				RETRUN_MUL(4);
			}
		}
	}
	//
	// fen 7P1/4k4/3P1a2b/4N4/4n4/9/9/8B/3K5/9 b - - 90 90
	//如果一个兵到了底线, 对方有1仕1象
	if(your_shi_num >= 1 && your_xiang_num >= 1){
		if(StoY(mpawn1) == MY_RANK0 || StoY(mpawn2) == MY_RANK0){
			RETRUN_MUL(4);
		}
	}

	// fen 3k5/9/8b/9/9/4N4/4n4/4BAp2/3pA4/5K3 w - - 120 120
	// fen 3k5/9/8b/9/9/4N4/4n4/4BAp2/3pA4/5K3 w - - 120 120

	// fen 3aka3/9/4b3b/9/7n1/4N4/9/3AB4/2p3p2/5K3 w - - 120 120
	if(your_shi_num >= 1 && your_xiang_num >= 1 && (StoX(yk) != 0x4 || abs(StoX(mpawn1) - StoX(mpawn2)) >= 3)){
		if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1 && PB90(MY_SQ0D) != my_pawn){
			if(!IsOnSameSide(mpawn1,mpawn2)){
				if(PB90(MY_SQ28) == your_ma){
					if(StoX(yk) == 0x3 && PB90(MY_SQ15) == your_shi){
					}
					else if(StoX(yk) == 0x5 && PB90(MY_SQ17) == your_shi){
					}
		            RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 2bk5/4a4/b1P6/9/5N3/2P6/3n5/3A1A3/9/4K4 w - - 0 1
	if(EV_MY_CAN <= 1){
		if((your_xiang_num + your_shi_num) >= 3 && StoY(yk) == MY_RANK0){
			if(StoY(mpawn1) MY_LARGE_EQL MY_RANK5){
				if(abs(StoX(mpawn2) - 0x4) >= 2){
					RETRUN_MUL(4);
				}
			}
			if(StoY(mpawn2) MY_LARGE_EQL MY_RANK5){
				if(abs(StoX(mpawn1) - 0x4) >= 2){
					RETRUN_MUL(4);
				}
			}
		}
	}


   // fen 3k1a3/4a1P2/8b/7P1/4N4/4n4/9/9/4K4/9 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(yma) MY_LARGE_EQL MY_RANK2 && StoY(yma) MY_SMALL_EQL MY_RANK6){
			if(StoX(yk) < 0x4 && have_bit(bb_my_pawn,m_and(MyUpBB[MY_RANK3],RightBB[0x4]))){
				if(!have_bit(bb_your_shi,LeftBB[0x4])){
				   RETRUN_MUL(4);
				}
			}
			if(StoX(yk) > 0x4 && have_bit(bb_my_pawn,m_and(MyUpBB[MY_RANK3],LeftBB[0x4]))){
				if(!have_bit(bb_your_shi,RightBB[0x4])){
					RETRUN_MUL(4);
				}
			}
		}
	}

	

	// fen 5k3/4a1P2/bP7/9/2b1n4/4N4/9/9/9/4K4 b - - 120 120
	if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn1) MY_SMALL_EQL MY_RANK2 && StoY(mpawn2) MY_SMALL_EQL MY_RANK2){
			if(IsOnSameSide(mpawn1,mpawn2) == FALSE){
				if(StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi){
					RETRUN_MUL(4);
				}
				if(StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi){
					RETRUN_MUL(4);
				}
			}
		}
		// fen 5k3/2P3P2/3a5/9/2b1nNb2/2B6/9/B8/9/4K4 b - - 121 121

		RETRUN_MUL(8);
	}	

	// 4k4/4a4/6P1b/9/5N3/4n1P2/9/5A3/9/3A1K3 w - - 0 1
	if (your_shi_num >= 1 && your_xiang_num >= 1 && my_xiang_num == 0){
		if (have_bit(bb_my_pawn, RankBB_A[MY_RANK5])){
			Bitboard upp = m_and(bb_my_pawn, MyUpBB[MY_RANK3]);
			if (m_have_bit(upp)){
				if (PB90(MY_SQ33) == my_pawn && bit_is_set(YOUR_ATTACK, MY_SQ2A)){
					RETRUN_MUL(8);
				}
				if (PB90(MY_SQ2F) == my_pawn && bit_is_set(YOUR_ATTACK, MY_SQ26)){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 1P4b2/3k5/4b4/4NP3/9/9/4n4/9/4K4/9 w - - 0 1
	if(your_xiang_num == 2 && (StoY(mpawn1) == MY_RANK0 || StoY(mpawn2) == MY_RANK0)){
		if(StoY(yk) == MY_RANK1){
			if(StoY(mpawn1) MY_LARGE_EQL MY_RANK3 || StoY(mpawn2) MY_LARGE_EQL MY_RANK3){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4P4/2P1a4/4k4/9/4N4/4n4/9/9/9/5K3 b - - 0 1
	if(StoY(yk) MY_LARGE_EQL MY_RANK1 && your_shi_num >= 1){
		if(StoY(yma) MY_SMALL_EQL MY_RANK5 && !bit_is_set(EV_MY_XBIT,yma)){
			if(StoX(yk) != 0x4 && PB90(XYtoS(StoX(yk),MY_RANK2)) != your_shi){
				if(StoY(mpawn1) == MY_RANK0){
					if(StoY(mpawn2) MY_SMALL_EQL MY_RANK2){
						RETRUN_MUL(8);
					}
				}
				if(StoY(mpawn2) == MY_RANK0){
					if(StoY(mpawn1) MY_SMALL_EQL MY_RANK2){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 3a1k3/4a4/b8/3P1P3/4N2n1/6B2/9/8B/4AK3/9 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
			RETRUN_MUL(8);
		}
	}



    // fen 3k1a3/4a1P2/8b/7P1/4N4/4n4/9/9/4K4/9 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		RETRUN_MUL(8);
	}

	// fen 4P4/4aP3/4k4/9/3nN4/9/9/9/9/3K5 b - - 0 1
	if(your_shi_num >= 1 && StoY(yk) == MY_RANK2 && !have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
		if(have_bit(bb_my_pawn,RankBB_A[MY_RANK0])){
			if(StoY(yma) MY_SMALL_EQL MY_RANK5){
				RETRUN_MUL(8);
			}
		}
	}
}


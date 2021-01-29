#ifndef END_my_m_MT_R_1ma2pawn_B_1pao1pawn
#define END_my_m_MT_R_1ma2pawn_B_1pao1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1马2兵对1炮1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



void my_m_MT_R_1ma2pawn_B_1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);
	Square ypawn  = S90_from_piecelist(POSITION,your_pawn,0);
	Square mma    = S90_from_piecelist(POSITION,my_ma,0);
	Square ypao   = S90_from_piecelist(POSITION,your_pao,0);

	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_MaPawn_To_PaoPawnByShi[your_shi_num]);

	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_MaPawn_To_PaoPawnByShi[my_shi_num]);
	
	if((my_shi_num + my_xiang_num) >= 3){
		EV_MY_SAFE = TRUE;
	}

	// fen 4ka3/1c2a4/b8/5PP2/9/6B2/3N5/4K4/3p5/3A1AB2 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1 && EV_YOUR_CAN >= 1 
		&& StoY(yk) MY_SMALL_EQL MY_RANK1){
		if (StoY(ypao) MY_SMALL_EQL MY_RANK2){
			MY_EV_SUB(64);
			if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK2])){
				MY_EV_SUB(32);
			}
		}
	}

	int mcan = EV_MY_CAN;
	int ycan = EV_YOUR_CAN;

	// fen 9/3P1k3/3abC3/5n3/9/2B6/9/3K2p2/4A1p2/3A5 w - - 0 1
	Bitboard mpp = m_and(bb_my_pawn, MyUpBB[MY_RANK3]);
	if (your_shi_num == 2 && count_1s(mpp) == 2){
		if (have_bit(mpp, MyUpBB[MY_RANK2])){
			if (StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi){
				if (!have_bit(mpp, RightBB[0x3])){
					MY_EV_SUB(64);
				}
			}
			if (StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi){
				if (!have_bit(mpp, LeftBB[0x5])){
					MY_EV_SUB(64);
				}
			}
		}
	}

	// fen 9/1N1kaP3/4b4/3P3c1/2b6/9/9/3K1A3/2p1A4/6B2 w - - 0 1
	if (your_shi_num >= 1 && your_xiang_num == 2 && StoY(ypao) == MY_RANK3){
		Bitboard mp2  = m_and(bb_my_pawn, MyUpBB[MY_RANK2]);
		if (StoX(yk) == 0x3 && have_bit(mp2, RightBB[0x4])){
			if (MY_SQ0A == mma && PB90(MY_SQ1E) == my_pawn && StoX(ypao) >= 0x5){
				MY_EV_SUB(80);
			}
		}
		if (StoX(yk) == 0x5 && have_bit(mp2, LeftBB[0x4])){
			if (MY_SQ10 == mma && PB90(MY_SQ20) == my_pawn && StoX(ypao) <= 0x3){
				MY_EV_SUB(80);
			}
		}
	}



	// fen 3a5/4ak1N1/b6c1/9/4P4/1p6P/9/9/3K5/9 w - - 0 1
	if(EV_MY_CAN == 2){
		MY_EV_ADD(EV_MY_CAN * 32);
		if((your_shi_num + your_xiang_num) <= 3){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
		if(!bit_is_set(EV_YOUR_XBIT,mma) && StoY(mma) MY_SMALL_EQL MY_RANK4){
			MY_EV_ADD(EV_MY_CAN * 16);
		}		
	}

	//fen 2bk1a3/4a4/c1P1b1P2/9/9/9/9/8N/4K1p2/9 b - - 0 1
	if (StoY(ypawn) MY_LARGE StoY(mk)){
		MY_EV_ADD(32);
		MY_EV_ADD(EV_MY_CAN * 16);
	}



	// fen 3k5/1PP1a1N2/5ac2/9/2b6/9/9/B4A3/3p5/2BAK4 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1 
		&& !have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
		MY_EV_SUB(64);
		if (StoX(yk) == 0x3 && !have_bit(bb_your_shi, LeftBB[0x4])){
			if (StoX(mpawn1) <= 0x2 && StoX(mpawn2) <= 2
				&& have_bit(bb_my_xiang, LeftBB[0x5])){
				MY_EV_SUB(96);
			}
		}
		if (StoX(yk) == 0x5 && !have_bit(bb_your_shi, RightBB[0x4])){
			if (StoX(mpawn1) >= 0x6 && StoX(mpawn2) >= 6
				&& have_bit(bb_my_xiang, RightBB[0x3])){
				MY_EV_SUB(96);
			}
		}
	}

	// fen 2c2k3/4a1PP1/3a5/9/2b3b2/2N6/9/2p6/4K4/9 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1){
		if (my_shi_num == 0 && my_xiang_num == 0 && EV_YOUR_CAN >= 1){
			MY_EV_SUB(80);
			if (!have_bit(bb_my_pawn, MyLowBB[MY_RANK2])){
				MY_EV_SUB(32);
			}
		}
	}

	// fen 5P3/3P5/3kb4/2N6/9/6B2/9/B3c4/3pAK3/3A5 b - - 122 122
	if(mcan == 0){
		EV_YOUR_SAFE = TRUE;
	}

	if(EV_YOUR_CAN == 0){
		EV_MY_SAFE = TRUE;
	}

	if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1]) && StoY(yk) == MY_RANK2){
		if(StoY(mpawn1) == MY_RANK0 || StoY(mpawn2) == MY_RANK0){
			EV_YOUR_SAFE = TRUE;
		}
	}

	// fen 3a5/3Pa4/4k4/9/2b3b2/9/4Cn3/4BA3/2p1Ap3/3K5 w - - 0 1
    if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(!IsOnSameSide(mpawn1,mpawn2)){
			if(StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi){
				MY_EV_SUB(64);
			}
			if(StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi){
				MY_EV_SUB(64);
			}
			if(EV_YOUR_CAN >= 1){
				MY_EV_SUB(64);
			}
			if(StoY(ypao) MY_SMALL_EQL MY_RANK4){
				MY_EV_SUB(32);
			}
		}
	}



	//Square ypao = S90_from_piecelist(POSITION,your_pao,0);

	// fen 9/2P1a1P2/3a1k3/4PN3/2b3b2/9/4c4/B3B4/4Ap3/3AK4 w - - 121 121
	//２兵到底，马不能动了，也是和棋
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK2){
		Bitboard low = m_and(bb_my_pawn,MyUpBB[MY_RANK3]);
		bool ok = false;
		if(count_1s(low) == 3){		
			ok = true;
		}
		else if(count_1s(low) == 2){	
			//找到另外一个兵，在卒线，且不在将一边
			low = m_and(bb_my_pawn,RankBB_A[MY_RANK3]);
			if(count_1s(low) == 1){
				int p = pop_1st_bit_sq(low);
				if(!IsOnSameSide(p,yk)){
					ok = true;
				}
			}
		}
		if(ok == true){
			if(PB90(MY_SQ55) == my_king && PB90(MY_SQ43) == my_xiang){
				if(isStringByPao(POSITION,ypao,Square(MY_SQ4C),Square(MY_SQ55))){
					if(PB90(MY_SQ54) == my_shi && PB90(MY_SQ4D) == your_pawn 
						&& PB90(MY_SQ20) == my_ma && PB90(MY_SQ17) == your_king){
							RETRUN_MUL(2);
					}
					if(PB90(MY_SQ56) == my_shi && PB90(MY_SQ4B) == your_pawn 
						&& PB90(MY_SQ1E) == my_ma && PB90(MY_SQ15) == your_king){
							RETRUN_MUL(2);
					}
				}
			}
		}
	}	

	//兵在二边,得加分
	// fen 5P3/3P5/3kb4/2N6/9/6B2/9/B3c4/3pAK3/3A5 b - - 122 122 
	if(StoY(mpawn1) MY_SMALL StoY(yk) && StoY(mpawn2) MY_SMALL StoY(yk)){
		if(ycan == 0){
			RETRUN_MUL(2);
		}

		if((my_shi_num + my_xiang_num) >= 2){
			RETRUN_MUL(2);
		}

		if(your_shi_num == 0){
			RETRUN_MUL(2);
		}
	}

	// fen 3k1a3/4a4/8c/5P3/8p/6N2/8P/B4A3/4K4/5AB2 w - - 0 1
	if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(EV_MY_CAN <= 1){
		    if(StoY(mpawn1) MY_LARGE_EQL MY_RANK5 && abs(StoX(mpawn1) - 0x4) == 4){
				if(bit_is_set(ei.attacked_by(your_pao),mpawn1)){
					RETRUN_MUL(2);
				}
			}
			if(StoY(mpawn2) MY_LARGE_EQL MY_RANK5 && abs(StoX(mpawn2) - 0x4) == 4){
				if(bit_is_set(ei.attacked_by(your_pao),mpawn2)){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 5kb2/4a4/3ab4/5P3/9/2P1c4/9/4B4/4Np3/2BAKA3 w - - 0 1
	//我方的马给闷宫了
	if(your_shi_num >= 1){
		if(MY_SQ4C == mma && MY_SQ55 == mk && PB90(MY_SQ43) == my_xiang){
			if(PB90(MY_SQ54) == my_shi && PB90(MY_SQ56) == my_shi){
				if(StoX(ypao) == 0x4 && bit_is_set(ei.attacked_by(your_pao),mma)){
					if(StoX(ypawn) > 0x4 && have_bit(bb_my_pawn,FileBB_A[0x5])){
						RETRUN_MUL(2);
					}
					if(StoX(ypawn) < 0x4 && have_bit(bb_my_pawn,FileBB_A[0x3])){
						RETRUN_MUL(2);
					}
				}
			}
		}
	}


	if(!IsOnSameSide(mpawn1,mpawn2)){
		MY_EV_ADD(64);
	}

	// fen 4k4/3P3P1/3a1a3/3Nc4/2b6/9/9/9/4AK3/9 b - - 122 122
	if((your_shi_num + your_xiang_num) >= 3){
		if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){	
			if(IsOnSameSide(mpawn1,mpawn2)){
				if(PB90(MY_SQ15) == your_shi && PB90(MY_SQ17) == your_shi){
					RETRUN_MUL(4);
				}
			}
		}
	}

	//如果对方的炮保着自己的兵,而且我方的另一个兵底于对方的兵,也可能是和棋
	if(your_shi_num >= 1 && your_xiang_num == 2){
		if(PB90(ypawn MY_ADD 18) == my_pawn || PB90(ypawn MY_ADD 27) == my_pawn){
			if(StoX(ypao) == StoX(ypawn) && StoY(ypao) MY_LARGE_EQL MY_RANK6){
				if(StoY(mpawn1) MY_SMALL StoY(ypawn) || StoY(mpawn2) MY_SMALL StoY(ypawn)){
					RETRUN_MUL(4);
				}
			}
		}
	}



	// fen 4k4/3P5/3ab4/3N5/p1b6/9/P8/3A2c1B/5K3/2B6 b - - 120 120
	if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 || StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
			if(mcan <= 1){
				RETRUN_MUL(4);
			}
		}
		// fen 5k3/4a4/b3ba3/8p/6n2/1p4B1P/9/3AB4/8C/4K4 b - - 0 0
		//顶死一个兵,炮还在打那个兵,有可能是难胜
		Square sq = SQ_END90;
		if(PB90(MY_SQ36) == my_pawn && PB90(MY_SQ24) == your_pawn){
			sq = MY_SQ36;
		}
		if(PB90(MY_SQ3E) == my_pawn && PB90(MY_SQ2C) == your_pawn){
			sq = MY_SQ3E;
		}
		if(sq != SQ_END90){
			Bitboard b1 = POSITION.Pao_Eat_bb(ypao);
			if(bit_is_set(b1,sq)){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 6b2/3ka4/5a3/4P4/6b2/6B2/4Cn3/3AB4/2p2p3/4K4 w - - 145 145
	if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
			if(PB90(yk MY_ADD 18) != your_shi){
				if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
					if(abs(StoX(mpawn1) - StoX(mpawn2)) >= 3){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 4k4/4aPP2/3cba3/2N6/2b6/9/9/4BA3/2p1A4/3K5 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
				if(StoX(mpawn1) > 0x4 && StoX(mpawn2) > 0x4 && PB90(MY_SQ17) == your_shi){
					RETRUN_MUL(4);
				}
				if(StoX(mpawn1) < 0x4 && StoX(mpawn2) < 0x4 && PB90(MY_SQ15) == your_shi){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 3k1a3/4a4/8c/4P4/8p/6N2/8P/B4A3/4K4/5AB2 b - - 0 1
	if(EV_MY_SAFE){
		if(EV_MY_CAN <= 1){
			if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
				if(StoY(mpawn1) MY_SMALL_EQL MY_RANK3 || StoY(mpawn2) MY_SMALL_EQL MY_RANK3){
					Bitboard mp = m_and(bb_my_pawn,ei.attacked_by(your_pao));
					if(m_have_bit(mp)){
						Square mn = pop_1st_bit_sq(mp);
						if(abs(StoX(mn) - 0x4) == 4 && StoY(mn) MY_LARGE_EQL MY_RANK5){
							RETRUN_MUL(4);
						} 
					}
				}
			}
		}
	}


	// fen 3k4c/4a4/5a3/8P/7Np/2B6/8P/9/4A4/2B1KA3 b - - 0 1
	if(your_shi_num == 2 && EV_MY_CAN <= 1){
		if(StoY(ypao) MY_SMALL_EQL MY_RANK1){
			if(StoX(ypao) == 0x8 && PB90(MY_SQ2C) == your_pawn 
				&& PB90(MY_SQ3E) == my_pawn){
					RETRUN_MUL(4);
			}
			if(StoX(ypao) == 0x0 && PB90(MY_SQ24) == your_pawn 
				&& PB90(MY_SQ36) == my_pawn){
					RETRUN_MUL(4);
			}
		}
	}

	// fen 4k4/3PacN2/4b4/5P3/2b6/6B2/4p4/5A3/3KA4/9 b - - 0 1
	// 看死一个r兵
	if (your_shi_num >= 1 && your_xiang_num == 2 && MY_SQ04 == yk) {
		if (have_bit(bb_your_pawn, RankBB_A[MY_RANK6])) {
			if (have_bit(bb_my_pawn, MyLowBB[MY_RANK1])) {
				if (PB90(MY_SQ0E) == your_pao && PB90(MY_SQ0F) == my_ma) {
					if (have_bit(bb_my_pawn, m_and(LeftBB[0x4], RankBB_A[MY_RANK1]))) {
						RETRUN_MUL(4);
					}
				}
				if (PB90(MY_SQ0C) == your_pao && PB90(MY_SQ0B) == my_ma) {
					if (have_bit(bb_my_pawn, m_and(RightBB[0x4], RankBB_A[MY_RANK1]))) {
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 5kb2/3Pa4/3a5/2N4c1/4P4/2B6/9/3KBA3/5p3/3A5 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(EV_YOUR_CAN >= 1 && StoY(yk) == MY_RANK0){
			if((StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi) 
				|| (StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi)){
					if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && !IsOnSameSide(mpawn1,yk)){
						if(StoY(mpawn2) MY_LARGE_EQL MY_RANK3){
							RETRUN_MUL(6);
						}
					}
					if(StoY(mpawn2) MY_SMALL_EQL MY_RANK1 && !IsOnSameSide(mpawn2,yk)){
						if(StoY(mpawn1) MY_LARGE_EQL MY_RANK3){
							RETRUN_MUL(6);
						}
					}
			}
		}
	}

	

	//如果对方是二仕一相,也是和棋
	//如果不是左右一兵控制着将
	// fen 1P2ka3/2P1a1c2/b8/3N5/9/9/9/4B4/3K1p3/9 r  //这个不和
	if(PB90(MY_SQ0C) == my_pawn && PB90(MY_SQ0E) == my_pawn && PB90(MY_SQ04) == your_king){

	}
	// fen 2bak4/4a4/9/4P4/8p/6B2/P3cN3/9/9/2BA1K3 b - - 0 1
	else if(your_shi_num == 2 && your_xiang_num >= 1){
		if((my_shi_num + my_xiang_num) >= 2){
			RETRUN_MUL(6);
		}
	}

	// fen 2bk1a3/4a4/c1P1b1P2/9/9/9/9/8N/4K1p2/9 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2){
		if ((my_shi_num + my_xiang_num) <= 1){
			if (StoY(mk) MY_SMALL_EQL StoY(ypawn)){
				RETRUN_MUL(6);
			}
		}
	}

	// fen 3a1ab2/3k1P3/b8/9/n8/C8/9/4B4/2p1Ap3/4K1B2 b - - 120 120
    if(your_shi_num >= 1 && your_xiang_num == 2){
		if (my_shi_num >= 1 || my_xiang_num >= 1){
			if (StoY(mma) MY_LARGE_EQL MY_RANK5){
				RETRUN_MUL(8);
			}
		}
	}
	// fen 5k2C/9/3a5/9/6p2/8P/9/4B1n2/3p5/3AK1B2 b - - 0 0
	if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(mcan <= 1 && ycan >= 1){
			RETRUN_MUL(8);
		}
	}

	// fen 5k2C/9/3a5/9/6p2/8P/9/4B1n2/3p5/3AK1B2 b - - 0 0   
	// fen 5k2C/9/3a5/9/6p2/8P/9/4B1n2/3p5/3AK1B2 b - - 0 0 
	if(your_shi_num == 2 && mcan <= 1){
		if(StoY(mpawn1) == MY_RANK0 || StoY(mpawn2) == MY_RANK0){
			RETRUN_MUL(8);
		}
	}
	// fen 4k4/4a4/3a5/6P2/2b3b2/4p4/2n6/5A3/1p2AC3/4K4 b - - 0 1
	if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(ypawn) == MY_RANK6){
			if(abs(StoX(mpawn1) - 0x4) >= 2 || abs(StoX(mpawn2) - 0x4) >= 2){
				MY_EV_SUB(64);
				RETRUN_MUL(8);
			}
		}
	}




	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn1) MY_SMALL_EQL MY_RANK1 && StoY(mpawn2) MY_SMALL_EQL MY_RANK1){
			if(StoX(mpawn1) > 0x4 && StoX(mpawn2) > 0x4 && PB90(MY_SQ17) == your_shi){
				RETRUN_MUL(8);
			}
			if(StoX(mpawn1) < 0x4 && StoX(mpawn2) < 0x4 && PB90(MY_SQ15) == your_shi){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4k4/4aPP2/3cba3/2N6/2b6/9/9/4BA3/2p1A4/3K5 w - - 0 1
    if(EV_MY_SAFE){
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
			if(PB90(MY_SQ17) == your_shi && !have_bit(LeftBB[0x5],bb_my_pawn)){
				RETRUN_MUL(8);
			}
			if(PB90(MY_SQ15) == your_shi && !have_bit(RightBB[0x3],bb_my_pawn)){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3kca3/4a4/4P4/2N1P4/9/2B6/2p6/5A3/4AK3/9 b - - 0 1
	if(your_shi_num == 2 && StoY(ypawn) == MY_RANK6 && abs(StoX(ypawn) - 0x4) <= 2){
		if(PB90(MY_SQ16) == my_pawn && bit_is_set(YOUR_ATTACK,MY_SQ16)){
			RETRUN_MUL(8);
		}
	}

	// fen 3k1a3/4a4/8c/5P3/8p/6N2/8P/B4A3/4K4/5AB2 w - - 0 1
	if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(EV_MY_CAN <= 1){
			RETRUN_MUL(8);
		}
	}

	//  fen 1c3k3/4a1PP1/3a5/9/2b1N4/9/9/B8/3K2p2/9 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1) {
		if (!have_bit(bb_my_pawn, MyLowBB[MY_RANK1])) {
			if (!have_bit(bb_my_pawn, LeftBB[0x6])) {
				RETRUN_MUL(8);
			}
			if (!have_bit(bb_my_pawn, RightBB[0x2])) {
				RETRUN_MUL(8);
			}
		}
	}



}

//// fen 2b1c4/3k5/3ab4/5NP2/2p6/4P4/9/B2AB4/2p6/3A1K3 b - - 0 1
//if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK2){
//	if(EV_YOUR_CAN >= 1){
//		if(PB90(MY_SQ31) == my_pawn && bit_is_set(ei.attacked_by(your_pao),MY_SQ31)){
//			RETRUN_MUL(8);
//		}
//		if(PB90(MY_SQ3A) == my_pawn && bit_is_set(ei.attacked_by(your_pao),MY_SQ3A)){
//			RETRUN_MUL(8);
//		}
//	}
//}
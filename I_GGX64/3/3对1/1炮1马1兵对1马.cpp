#ifndef END_my_m_MT_R_1pao1ma_1pawn_B_1ma
#define END_my_m_MT_R_1pao1ma_1pawn_B_1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马1兵对1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//还有就是马过河了

void my_m_MT_R_1pao1ma_1pawn_B_1ma(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao1MaXPawn_1Ma[your_shi_num]);
	
	//马炮方另外加分
    //MY_EV_ADD(MaPaoXPawn_Ma);

	// fen 4k3C/4aP3/3ab2Nn/9/6b2/9/9/B4A3/9/2BK1A3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(168);
	}

	//
	Square mma   = S90_from_piecelist(POSITION,my_ma,0);
	Square yma   = S90_from_piecelist(POSITION,your_ma,0);
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpao  = S90_from_piecelist(POSITION,my_pao,0);

	//1, 我方的马要过河
	if(StoY(mma) MY_SMALL MY_RANK5){
		MY_EV_ADD(MaPaoXPawn_Vs_Ma_PaoMao_Over_River);
	}
	

	//兵到底, 对方有1仕2相以上, 炮方没有仕相, 没有铁门栓.
	// fen 7P1/5k3/b2ab1N2/9/9/9/3n5/9/9/4KC3 w - - 27 27
	if((my_shi_num + my_xiang_num) == 0 && StoY(mpawn) == MY_RANK0){
		if(your_xiang_num == 2 && your_shi_num >= 1){
			Bitboard super = POSITION.Pao_Super_bb(yk);
			if(!bit_is_set(super,mpao)){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 9/9/4kc2b/5N3/9/9/5n3/B3B4/5K3/3p5 b - - 0 162
	if(your_xiang_num == 2 && StoY(mpawn) == MY_RANK0){
		if(my_shi_num == 0){
			RETRUN_MUL(4);
		}
	}

	// fen 2b1k4/4aP3/4ba3/1N1nC4/9/9/9/4B4/4A4/3K2B2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && abs(StoY(yma) - MY_RANK2) <= 1){
			if(StoX(mpawn) > 0x4 && PB90(MY_SQ17) == your_shi && StoX(mpao) == 0x4){
				RETRUN_MUL(8);
			}
			if(StoX(mpawn) < 0x4 && PB90(MY_SQ15) == your_shi && StoX(mpao) == 0x4){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4k4/9/8b/9/4N4/2B6/9/B2A5/3pAK3/cn7 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if (StoY(mpawn) MY_SMALL_EQL MY_RANK1 && my_shi_num == 0){
			if (StoX(yk) == 0x3 && StoX(mpawn) >= 0x5
				&& !have_bit(bb_your_shi, LeftBB[0x4])){
				if (StoX(mpao) > 0x4 || StoX(mma) >= 0x6){
					RETRUN_MUL(8);
				}
			}
			if (StoX(yk) == 0x5 && StoX(mpawn) <= 0x3
				&& !have_bit(bb_your_shi, RightBB[0x4])){
				if (StoX(mpao) < 0x4 || StoX(mma) <= 0x2){
					RETRUN_MUL(8);
				}
			}
		}
	}
	
}


#ifndef END_my_m_MT_R_1pao1ma2pawn_B_1pao1ma1pawn
#define END_my_m_MT_R_1pao1ma2pawn_B_1pao1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1炮1马2兵对1炮1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//马炮二兵对一马一炮一兵
void my_m_MT_R_1pao1ma2pawn_B_1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn, MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao1MaXPawn_1Pao1Ma_ByPawnShi[your_shi_num]);

	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn, MyUpBB[StoY(mk)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1Pao1MaXPawn_1Pao1Ma_ByPawnShi[my_shi_num]);

	Square mpawn1 = S90_from_piecelist(POSITION, my_pawn, 0);
	Square mpawn2 = S90_from_piecelist(POSITION, my_pawn, 1);

	Square mma = S90_from_piecelist(POSITION, my_ma, 0);
	Square ypawn = S90_from_piecelist(POSITION, your_pawn, 0);
	Square ypao = S90_from_piecelist(POSITION, your_pao, 0);
	Square mpao = S90_from_piecelist(POSITION, my_pao, 0);
	Square yma = S90_from_piecelist(POSITION, your_ma, 0);

	if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		EV_MY_SAFE = true;
	}
	// fen 2bk5/2N1a1P2/5a3/3P5/3nC1b2/4c1B2/9/4BA3/3pA4/4K4 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(EV_YOUR_CAN * 16);

		MY_EV_SUB(32);
		//  fen 4kab2/4a4/9/C5P1p/2b3n2/P1N6/9/2c2A3/4A4/2B1K4 b - - 0 1
		if ((my_shi_num + my_xiang_num) <= 3) {
			MY_EV_SUB(32);
			if (have_bit(bb_my_pawn, m_or(FileBB_A[0x0], FileBB_A[0x8]))) {
				MY_EV_SUB(32);
			}
		}
	}


	//  fen 2bak4/4a4/bN7/C3p4/8P/6c2/P8/5A3/2n1A4/3K5 b - - 0 1
	if (StoY(ypawn) MY_SMALL_EQL MY_RANK5) {
		MY_EV_ADD(32);
		if (my_shi_num == 2) {
			MY_EV_ADD(32);
		}
		MY_EV_ADD(EV_MY_CAN * 16);
	}


	// fen 9/2P6/C3k4/5n1c1/2N6/9/4p4/B1p6/4A4/2BA1K3 w - - 0 1
	if (StoY(ypawn) MY_LARGE_EQL StoY(mk)){
		MY_EV_ADD(EV_MY_CAN * 16);
		if (count_1s(bmp, MyUpBB[MY_RANK5]) == 2){
			MY_EV_ADD(32);
		}
	}

	// fen 4kn3/4a4/b1C2a1N1/p3P3p/9/2B6/4c4/9/4A4/2BAK4 w - - 0 1
	if ((my_shi_num + my_xiang_num) >= 3) {
		if (StoY(mk) == MY_RANK9) {
			MY_EV_ADD(32);
		}
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	//  fen 4kab2/4a4/9/C5P1p/2b3n2/P1N6/9/2c2A3/4A4/2B1K4 b - - 0 1



	// fen 4k1b2/4a4/3a5/3PP4/9/9/2n6/2CK1N3/4p4/2Bc5 w - - 0 1
	if (StoY(ypawn) MY_LARGE_EQL StoY(mk)){
		MY_EV_ADD(EV_MY_CAN * 32);
		if (StoY(ypao) MY_LARGE_EQL MY_RANK5){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	// fen 4kab2/4a4/4b4/7N1/4P4/p4c3/4n3P/9/4A1C2/3A1K3 b - - 0 1
	if (my_shi_num == 2 && abs(StoX(ypawn) - 0x4) >= 3){
		MY_EV_ADD(EV_MY_CAN * 16);
		if (!IsOnSameSide(ypawn, mk)){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 5a3/3Pa4/b3k3b/7C1/8p/4n1P2/9/4B2c1/4K2N1/3A1A3 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && EV_YOUR_CAN >= 1){
		MY_EV_SUB(32);
		if (have_bit(bb_my_pawn, MyUpBB[StoY(yk)])){
			MY_EV_SUB(32);
			if (StoY(mma) MY_LARGE_EQL MY_RANK8){
				MY_EV_SUB(32);
				if (PB90(MY_SQ33) == my_pawn || PB90(MY_SQ2F) == my_pawn){
					if (MY_SQ31 == yma){
						MY_EV_SUB(32);
					}
				}
			}
		}
	}


	// fen 2b3b2/4ak3/6N2/4C4/5P3/4c1B2/P2n3p1/9/4AK3/9 b - - 0 1
	//if(my_shi_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
	//	MY_EV_ADD(EV_MY_CAN * 32);
	//}

	// fen 2bk5/2N1a1P2/5a3/3P5/3nC1b2/4c1B2/9/4BA3/3pA4/4K4 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		Bitboard nousePawn = m_and(bb_my_pawn, MyUpBB[MY_RANK3]);
		if (StoX(yk) == 0x3 && PB90(MY_SQ17) == your_shi){
			if (have_bit(nousePawn, RightBB[0x4])){
				MY_EV_SUB(32);
			}
		}
		if (StoX(yk) == 0x5 && PB90(MY_SQ15) == your_shi){
			if (have_bit(nousePawn, LeftBB[0x4])){
				MY_EV_SUB(32);
			}
		}
	}

	// fen 4k4/3c2PP1/3aba3/4n4/9/2B1N4/3p5/3AB4/C3A4/3K5 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if (StoY(ypawn) == MY_RANK6){
			MY_EV_SUB(16);
		}
		if (!have_bit(bb_my_pawn, MyLowBB[MY_RANK1])){
			if (!have_bit(bb_your_shi, RankBB_A[MY_RANK0])){
				MY_EV_SUB(16);
			}
			if (!have_bit(bb_my_pawn, LeftBB[0x6])){
				MY_EV_SUB(16);
			}
			if (!have_bit(bb_my_pawn, RightBB[0x2])){
				MY_EV_SUB(16);
			}
			if (StoY(ypao) MY_SMALL_EQL MY_RANK1){
				MY_EV_SUB(16);
			}
		}
	}

	// fen 4kab2/4a4/4b4/8p/P3P4/2n4Cc/9/6N2/4A4/5K3 w - - 0 1
	if (my_shi_num >= 1){
		if (abs(StoX(ypawn) - 0x4) >= 3){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
		if (StoY(ypawn) MY_SMALL_EQL MY_RANK6){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 5k3/8c/b4N3/9/P8/2P6/9/3Ap4/3C5/4K2n1 w - - 0 1
	if ((my_xiang_num + my_shi_num) <= 1){
		if (StoY(ypawn) MY_LARGE_EQL MY_RANK7 && StoY(ypawn) MY_SMALL_EQL StoY(mk)){
			if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK4])){
				MY_EV_SUB(64);
				if (EV_MY_CAN <= 1){
					MY_EV_SUB(32);
				}
				if (!have_bit(bb_my_pawn, m_and(LeftBB[0x6], RightBB[0x2]))){
					MY_EV_SUB(32);
				}
			}
		}
	}
	// fen 2bak4/9/4ba3/C8/3N5/P1B6/4p3P/5c3/6n2/2BA1K3 b - - 0 1
	if (my_shi_num >= 1 && my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		MY_EV_ADD(EV_MY_CAN * 16);
		if (StoY(ypawn) MY_SMALL_EQL MY_RANK6){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 2bak4/4a4/4b4/4P3P/5c2N/9/4C4/9/3pA1n2/2BA1K3 w - - 0 1
	if (my_shi_num == 2 && StoY(ypawn) MY_LARGE_EQL MY_RANK8) {

		MY_EV_ADD(32);

		if (StoX(ypawn) < 0x4 && !have_bit(bb_my_shi, RightBB[0x4])) {
			MY_EV_ADD(EV_MY_CAN * 32);
		}
		if (StoX(ypawn) > 0x4 && !have_bit(bb_my_shi, LeftBB[0x4])) {
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	// fen 1C2k4/4a4/4b4/p3N3p/4c4/6B2/P7n/4B4/4A4/3K1A3 b - - 0 1
	if (EV_MY_CAN >= 1 && EV_YOUR_CAN == 0) {
		MY_EV_ADD(EV_MY_CAN * 16);
	}

	// fen 2bak1b2/4a4/9/p4P3/9/6B2/PC7/1n2BA3/1N2A4/1c2K4 w - - 0 1
	if ((my_shi_num + my_xiang_num) >= 3 && StoY(mk) MY_LARGE_EQL MY_RANK8) {
		if (EV_YOUR_CAN == 0) {
			EV_MY_SAFE = true;
		}
	}

	// fen 3k1a3/4a4/n3b4/p8/9/4C1P2/4P3P/4BKN2/c8/9 w - - 0 1
	if (StoY(ypawn) MY_SMALL_EQL MY_RANK4) {
		MY_EV_ADD(EV_MY_CAN * 16);
	}

	// fen 3a1k3/4a4/b5c1b/9/4p4/6B2/1C2P1n1P/4B1N2/4A4/4KA3 w - - 0 1
	if (EV_MY_SAFE) {
		if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1) {
			if (EV_MY_CAN <= 1) {
				MY_EV_SUB(32);
				if (PB90(MY_SQ38) == your_ma && PB90(MY_SQ41) == my_ma && PB90(MY_SQ36) == my_pawn) {
					RETRUN_MUL(4);
				}
				if (PB90(MY_SQ3C) == your_ma && PB90(MY_SQ45) == my_ma && PB90(MY_SQ3E) == my_pawn) {
					RETRUN_MUL(4);
				}
			}
		}		
	}

	// fen 3ak4/4a4/4b4/9/6b2/2B5p/P1n1P3c/2N1B4/2C1A4/3AK4 w - - 4 4
	//2兵方的二个兵给马守住了, 也基本是和棋
	if ((my_shi_num + my_xiang_num) >= 3) {
		if (your_shi_num == 2 && your_xiang_num == 2 && PB90(MY_SQ3A) == my_pawn) {
			if (PB90(MY_SQ38) == your_ma && PB90(MY_SQ41) == my_ma && PB90(MY_SQ36) == my_pawn) {
				RETRUN_MUL(8);
			}
			if (PB90(MY_SQ3C) == your_ma && PB90(MY_SQ45) == my_ma && PB90(MY_SQ3E) == my_pawn) {
				RETRUN_MUL(8);
			}
		}
	}
	// fen 3akab2/9/9/4p3p/1N7/P4n3/5c3/3C1A3/9/2BAK1B2 b - - 0 1
	if (my_shi_num == 2 && my_xiang_num >= 1) {
		MY_EV_ADD(EV_MY_CAN * 16);
	}

	//MY_EV_ADD(EV_MY_CAN * 8);

	// fen 5a3/4a1P2/b4k2b/4P4/4c4/4N4/5p3/B8/2C1n4/3K5 b - - 0 1
	// 对方的将的所有步给我方的将控制住了.
	//if(StoY(yk) != MY_RANK0){
	//	//print_bb(ei.attacked_by(your_king));
	//	if(!m_have_bit(_mm_andnot_si128(ei.pi->pawnshi_attacks(MY_COLOR),ei.attacked_by(your_king)))){
	//		MY_EV_ADD(64);
	//	}
	//}

	// fen 1P7/4k4/9/7N1/6b2/3cp3P/1n7/1C7/4A4/3K1A3 w
	//我方一个兵到底，一个兵还在 Y3X2之外
	if (StoY(mpawn1) == MY_RANK0) {
		MY_EV_SUB(32);
		if (abs(StoX(mpawn2) - 0x4) >= 3 && StoY(mpawn2) MY_LARGE_EQL MY_RANK3) {
			MY_EV_SUB(64);
		}
	}
	if (StoY(mpawn2) == MY_RANK0) {
		MY_EV_SUB(32);
		if (abs(StoX(mpawn1) - 0x4) >= 3 && StoY(mpawn1) MY_LARGE_EQL MY_RANK3) {
			MY_EV_SUB(64);
		}
	}

	// fen 3k2b2/2NcC4/4b4/5P3/9/9/2p5P/3n5/9/5K3 w - - 0 1
	if (my_shi_num == 0 && my_xiang_num == 0 && StoY(ypawn) MY_SMALL StoY(mk)) {
		MY_EV_SUB(48);
	}

	// fen 4ka3/4a4/4b4/2C1p4/c1b6/4n1P1P/9/4B4/4AN3/2BAK4 w - - 0 1
	if ((my_xiang_num + my_shi_num) >= 3 && StoY(ypawn) MY_SMALL_EQL MY_RANK6) {
		if (EV_MY_CAN <= 1 && !have_bit(bb_my_pawn, MyUpBB[MY_RANK5])) {
			if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0) {
				RETRUN_MUL(8);
			}
		}
	}


	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0) {
		if (EV_MY_SAFE) {
			if (EV_MY_CAN <= 1) {
				MY_EV_SUB(64);

				// fen 2bak1b2/4a4/9/p4P3/9/6B2/PC7/1n2BA3/1N2A4/1c2K4 w - - 0 1
				if (StoY(mma) MY_LARGE_EQL MY_RANK7) {
					RETRUN_MUL(8);
				}
				// fen 3k1ab2/4a4/4b4/1N1C5/p2P5/8c/Pn7/4B4/4A4/4KAB2 b - - 0 1
				if (StoY(yma) MY_LARGE_EQL MY_RANK3 && !have_bit(bb_my_pawn,MyUpBB[MY_RANK3])) {
					RETRUN_MUL(8);
				}
			}
		}
	}



	//	// fen 2bk5/2N1a1P2/5a3/3P5/3nC1b2/4c1B2/9/4BA3/3pA4/4K4 w - - 0 1
	if (EV_MY_SAFE){
		if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			Bitboard nousePawn = m_and(bb_my_pawn, MyUpBB[MY_RANK3]);
			if (StoX(yk) == 0x3 && PB90(MY_SQ17) == your_shi){
				if (have_bit(nousePawn, RightBB[0x4]) && StoX(mpao) != 0x3){
					RETRUN_MUL(12);
				}
			}
			if (StoX(yk) == 0x5 && PB90(MY_SQ15) == your_shi){
				if (have_bit(nousePawn, LeftBB[0x4]) && StoX(mpao) != 0x5){
					RETRUN_MUL(12);
				}
			}
		}
	}

	// fen 2b2k3/4a4/2Nab4/3P5/7c1/2P5p/1n2C4/4B4/4A4/2BK5 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if (have_bit(bb_my_pawn, MyLowBB[MY_RANK4])){
			if ((my_shi_num + my_xiang_num) >= 3){
				RETRUN_MUL(12);
			}
		}
	}
}


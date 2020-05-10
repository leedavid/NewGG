#ifndef END_my_m_MT_R_1ma1pao1pawn_B_1ma1pao
#define END_my_m_MT_R_1ma1pao1pawn_B_1ma1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1炮1马1兵对1炮1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


// 我方 马炮兵 对方 马炮

void my_m_MT_R_1ma1pao1pawn_B_1ma1pao(typePOS &POSITION, EvalInfo &ei) {

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Square ypao = S90_from_piecelist(POSITION, your_pao, 0);
	Square yma = S90_from_piecelist(POSITION, your_ma, 0);
	// ADD
	Bitboard bmp = m_and(bb_my_pawn, MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1Pao1MaXPawn_1Pao1Ma_ByPawnShi[your_shi_num]);

	Square mpawn = S90_from_piecelist(POSITION, my_pawn, 0);
	Square mpao = S90_from_piecelist(POSITION, my_pao, 0);

	// fen 4k4/4a4/5a3/3P5/4N1bc1/4n1B2/3C5/3AB4/4A4/4K4 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0) {
		if (StoY(mpawn) MY_LARGE_EQL MY_RANK3 && abs(StoY(yma) - MY_RANK4) <= 2) {
			MY_EV_SUB(32);
		}
	}

	// fen 1P7/3k5/b2ac4/4N4/4n4/2B6/9/3AB4/3C5/4K4 b - - 0 1
	if ((my_xiang_num + my_shi_num) >= 3) {
		EV_MY_SAFE = true;
	}

	// fen 3a1a3/5k3/9/3c3C1/9/9/3n2p2/3N4B/4A4/4K4 b - - 0 1
	if (your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if (StoY(mpawn) == MY_RANK3){
			if (StoX(mpawn) <= 0x2 && MY_SQ17 == yma){
				MY_EV_SUB(64);
			}
			if (StoX(mpawn) >= 0x6 && MY_SQ15 == yma){
				MY_EV_SUB(64);
			}
		}
	}

	// fen 1P7/3k5/b2ac4/4N4/4n4/2B6/9/3AB4/3C5/4K4 b - - 0 1
	if (StoY(mpawn) == MY_RANK0) {
		MY_EV_SUB(32);
		if (your_shi_num >= 1 && your_xiang_num >= 1) {
			MY_EV_SUB(32);
		}
		if (StoY(ypao) MY_SMALL_EQL MY_RANK2) {
			MY_EV_SUB(32);
		}
	}

	//
	if((my_shi_num + my_xiang_num) >= 2){
		MY_EV_ADD(32);
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	// fen 3k5/5P3/3a1a3/3Nc1n2/6b2/9/5C3/3AB4/4A4/4K1B2 r
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && !IsOnSameSide(yk,mpawn)){
			if(abs(StoX(mpawn) - StoX(yk)) >= 2){
				MY_EV_SUB(32);
			}
		}
	}

	// fen 2bk5/2c1a4/2Na5/5P3/9/6B2/3nC4/3AB4/4A4/4K4 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			if(abs(StoX(mpawn) - StoX(yk)) >= 2){
				MY_EV_SUB(32);
			}
			if(StoY(ypao) MY_SMALL_EQL MY_RANK2){
				MY_EV_SUB(32);
			}
			if(abs(StoY(yma) - MY_RANK4) <= 2){
				MY_EV_SUB(32);
			} 
		}
	}

	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(ypao) MY_SMALL_EQL MY_RANK4 && StoY(yma) MY_SMALL_EQL MY_RANK4){
			RETRUN_MUL(2);
		}
		RETRUN_MUL(4);
	}

	

	// fen 5k3/2N2c3/9/9/9/9/5p1n1/3A5/C3A4/4K4 w - - 0 1
	if(StoY(mpawn) == MY_RANK3){
		MY_EV_ADD(32);
	}

	// fen 3k5/4a4/4b4/5cC2/4N1b2/2B3P2/7n1/3AB4/4K4/9 w - - 98 98
	if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
			if(StoX(mpawn) == 0x2 || StoX(mpawn) == 0x6){
				RETRUN_MUL(4);
			}
		}
	}
	
	// fen C3k4/2P1ac3/4ba3/3N5/4n4/9/9/3AB3B/4A4/4K4 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) == MY_RANK1 && abs(StoX(mpawn) - 0x4) >= 2){
			if(bit_is_set(ei.attacked_by(your_pao),mpawn)){
				RETRUN_MUL(4);
			}
		}
	}
	
	// fen 5k3/4a4/4bc3/4P4/2bN5/6B2/3n5/4BA3/3CA4/4K4 b - - 0 1
	if(your_xiang_num == 2 && StoY(mpawn) MY_LARGE_EQL MY_RANK3 && StoY(yk) == MY_RANK0){
		if(StoY(ypao) MY_SMALL_EQL MY_RANK4){
			RETRUN_MUL(4);
		}
	}

	// fen 5k3/3na4/b4a1c1/CP7/5N3/9/9/3AB4/9/4KAB2 b - - 0 1
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(abs(StoX(mpawn) - 0x4) >= 3){
			RETRUN_MUL(4);
		}
	}

	//Square yma   = S90_from_piecelist(POSITION,your_ma,0);
	//Square ypao  = S90_from_piecelist(POSITION,your_pao,0);

	// fen 5a3/4ak3/9/9/2bc2b2/6B2/3n5/3NB3C/4K4/3p5 w - - 120 120
	if(your_xiang_num == 2 && StoY(mpawn) == MY_RANK0){
		if(StoY(yma) == MY_RANK2 && StoY(ypao) == MY_RANK2){
			RETRUN_MUL(4);
		}
		RETRUN_MUL(6);
	}	

	// fen 5k3/4a4/1c1aP4/9/3N1n3/2B6/9/9/4A4/3KC1B2 w - - 0 1
	if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if(StoX(yk) != StoX(mk) && MY_SQ16 == mpawn && StoY(yma) MY_SMALL_EQL MY_RANK4){
			if(!bit_is_set(EV_MY_XBIT,yma) && StoY(ypao) == MY_RANK2){
				if(PB90(MY_SQ15) == your_shi && StoX(ypao) < 0x3){
					RETRUN_MUL(6);
				}
				if(PB90(MY_SQ17) == your_shi && StoX(ypao) > 0x5){
					RETRUN_MUL(6);
				}
			}
		}
	}

	// fen 5k3/2N1a1P2/3ab4/9/2b6/2B2cB2/C8/3A5/4A1n2/5K3 b - - 29 29
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		RETRUN_MUL(6);
	}

	if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		RETRUN_MUL(6);
	}

	// fen 3a1a3/9/b3k1P2/2Nc5/2b2n3/2B6/9/3AB4/3C5/3AK4 w - - 0 1
	if((your_shi_num + your_xiang_num) == 4 && StoY(mpawn) MY_SMALL_EQL StoY(yk)){
		RETRUN_MUL(8);
	}

	// fen 5ab2/1N1ka4/9/3P5/9/9/n8/5A3/C1c6/4KA3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			if(StoY(mpao) MY_LARGE_EQL MY_RANK7){
				if(PB90(MY_SQ36) == your_ma && StoX(mpao) <= 0x1){
					RETRUN_MUL(8);
				}
				if(PB90(MY_SQ3E) == your_ma && StoX(mpao) >= 0x7){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 1P7/3k5/b2ac4/4N4/4n4/2B6/9/3AB4/3C5/4K4 b - - 0 1
	if (EV_MY_SAFE) {
		if (StoY(mpawn) == MY_RANK0) {
			if (your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) != MY_RANK0) {
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3k5/3ca1P2/5a3/9/3n5/4N1B2/9/4B1C2/9/4KA3 w - - 0 1

	// fen 1N3a3/4aC3/3k1c2b/1P7/4n4/9/9/4B4/4A4/2B1KA3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(StoY(ypao) MY_SMALL_EQL MY_RANK3){
			if(!bit_is_set(EV_MY_XBIT,yma) && StoY(mpawn) MY_LARGE_EQL MY_RANK3){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3k1P3/9/5a3/4cN3/5n3/6B2/3C5/4B4/9/5K3 b - - 0 1
	if(my_shi_num == 0 && StoY(mpawn) == MY_RANK0){
		if((your_shi_num + your_xiang_num) >= 1){
			RETRUN_MUL(8);
		}
	}

	// fen 9/1P1k5/n3b1c2/9/N1b6/9/9/B3BA3/4A3C/4K4 b - - 0 1
	if(your_xiang_num == 2 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_SMALL_EQL StoY(yk)){
			if(abs(StoX(mpawn) - 0x4) >= 3){
				if(StoY(yma) MY_SMALL_EQL MY_RANK4){
					MY_EV_SUB(64);
				}
				RETRUN_MUL(8);
			}
		}
	}


	// fen 4k4/4a4/5a3/6P2/7n1/4N3c/9/4B4/4AC3/3K5 r
    if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK2){
			MY_EV_SUB(96);
		}

		// fen 3k5/3ca1P2/5a3/9/3n5/4N1B2/9/4B1C2/9/4KA3 w - - 0 1
		if(StoY(mpawn) == MY_RANK1){
			if(abs(StoX(mpawn) - 0x4) >= 2 || abs(StoX(mpawn) - StoX(yk)) >= 2){
				if(StoY(ypao) == MY_RANK1 && bit_is_set(ei.attacked_by(your_pao),mpawn)){
					RETRUN_MUL(8);
				}
			}
		}

		RETRUN_MUL(10);
	}

	// fen 5ab2/4a1N1C/3k5/4P4/6b2/2B1n4/3c5/9/3KA4/6B2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			RETRUN_MUL(10);
		}
	}

}


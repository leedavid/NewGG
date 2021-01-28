#ifndef END_my_m_MAT_R_1ma1pao2pawn_B_1ma1pao
#define END_my_m_MAT_R_1ma1pao2pawn_B_1ma1pao
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮1马2兵对1炮1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//马炮二兵对一马一炮
void my_m_MT_R_1ma1pao2pawn_B_1ma1pao(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Square yk = your_king_pos;
	Square yma = S90_from_piecelist(POSITION, your_ma, 0);
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	Square mma = S90_from_piecelist(POSITION, my_ma, 0);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1Pao1MaXPawn_1Pao1Ma_ByPawnShi[your_shi_num]);
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);

	// fen 2bk5/2N1a1P2/4ba3/3P5/5c3/3n5/3C5/9/9/5K3 w - - 0 1
	if(my_shi_num == 0 && my_xiang_num == 0){
		MY_EV_SUB(64);
	}

	// fen 4kab2/4aC3/4b4/3c2P2/P2N5/9/3n5/9/9/4K4 b - - 0 1
	if (EV_MY_CAN == 2){
		if (count_1s(bb_my_pawn, MyUpBB[MY_RANK5]) == 2){
			MY_EV_ADD(32);
		}
		if (StoY(mma) MY_SMALL_EQL MY_RANK4){
			MY_EV_ADD(32);
		}
	}

	// fen 2bk5/2N1a1P2/4ba3/3P5/5c3/3n5/3C5/9/9/5K3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(have_bit(bb_your_shi,RankBB_A[MY_RANK2])){
			//      Bitboard upb = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
			if(my_shi_num == 0 && my_xiang_num == 0){
				MY_EV_SUB(32);
			}
		}

		// fen 3k5/9/9/5N3/2b1p4/6B2/3n5/1p1A2cC1/4A4/2BK5 b - - 0 1
		if ((my_shi_num + my_xiang_num) <= 1){
			MY_EV_SUB(32);
			if (StoY(yma) MY_LARGE_EQL MY_RANK4){
				MY_EV_SUB(32);
			}
			if (have_bit(bb_my_pawn, MyLowBB[MY_RANK4])){
				MY_EV_SUB(32);
			}
		}

		// fen 3akcb2/3PaC3/b8/4N4/4n4/2P6/9/3AB4/4A4/2B1K4 b - - 0 1
		if (EV_MY_CAN <= 1){
			MY_EV_SUB(64);
			if (abs(StoY(yma) - MY_RANK4) <= 2){
				MY_EV_SUB(32);
			}
		}
		if (have_bit(bb_my_pawn, MyLowBB[MY_RANK4])){
			MY_EV_SUB(32);
		}

		// fen 3k1a3/2N1a4/2c1b4/7PP/2b6/5n3/9/5A2B/3CA4/5K3 b - - 0 1
		if (StoY(ypao) == MY_RANK2 && IsOnSameSide(mma, ypao)){
			MY_EV_SUB(64);
			if (StoY(yma) MY_LARGE_EQL MY_RANK3){
				
				if (StoX(mma) <= 0x2 && !have_bit(bb_my_pawn, LeftBB[0x5])){
					MY_EV_SUB(64);
				}
				if (StoX(mma) >= 0x6 && !have_bit(bb_my_pawn, RightBB[0x3])){
					MY_EV_SUB(64);
				}
			}
		}

	}

	



	// fen 3ak4/4a4/b3b4/9/2c6/2C3B2/P1n1P4/2N6/4A4/4KAB2 w - - 0 0
	//对方的马正好管住了我方的二个兵一个马
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(PB90(MY_SQ41) == my_ma && PB90(MY_SQ38) == your_ma){
			if(PB90(MY_SQ36) == my_pawn && PB90(MY_SQ3A) == my_pawn){
				RETRUN_MUL(4);
			}
		}
		if(PB90(MY_SQ45) == my_ma && PB90(MY_SQ3C) == your_ma){
			if(PB90(MY_SQ3E) == my_pawn && PB90(MY_SQ3A) == my_pawn){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4k1b2/4a4/4ba3/9/9/9/2cN4n/1pp1BC3/9/2BAKA3 w - - 0 1
	if(your_xiang_num == 2 && your_shi_num == 2 && yk == MY_SQ04){
		if(StoY(ypao) == MY_RANK2){
			if(PB90(MY_SQ18) == my_pawn && PB90(MY_SQ19) == my_pawn){
				if(PB90(MY_SQ20) == your_ma && StoX(ypao) < 0x4){
					RETRUN_MUL(8);
				}
			}
			if(PB90(MY_SQ14) == my_pawn && PB90(MY_SQ13) == my_pawn){
				if(PB90(MY_SQ1E) == your_ma && StoX(ypao) > 0x4){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 4k4/2c1aPP2/4ba3/9/1n4b2/1N7/7C1/9/4A4/5K3 w - - 0 1
	if(your_xiang_num == 2 && your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
			if(!have_bit(bb_my_pawn,LeftBB[0x5]) && StoX(yk) <= 4){
				if(StoX(ypao) < 0x4 && PB90(MY_SQ03) != your_shi && PB90(MY_SQ17) == your_shi){
					RETRUN_MUL(8);
				}
			}
			if(!have_bit(bb_my_pawn,RightBB[0x3]) && StoX(yk) >= 4){
				if(StoX(ypao) > 0x4 && PB90(MY_SQ05) != your_shi && PB90(MY_SQ15) == your_shi){
					RETRUN_MUL(8);
				}
			}
		}
	}
}


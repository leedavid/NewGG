#ifndef END_my_m_MT_R_2pao1pawn_B_1pao1ma1pawn
#define END_my_m_MT_R_2pao1pawn_B_1pao1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮1兵对1炮1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//2炮1兵对1炮1马1兵
//int _2Pao4SX_Add = 96;

void my_m_MT_R_2pao1pawn_B_1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2PaoXPawn_1Pao1Ma_ByPawn[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1Pao1MaXPawn_2Pao_ByPawnShi[my_shi_num]);
	
	//MY_EV_SUB(64);


	//Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	Square ypao = S90_from_piecelist(POSITION,your_pao,0);

	// fen 3k1a3/9/3a5/5cC2/9/5N2P/9/3A1c2B/3pA4/5K3 b - - 0 1
	if (your_shi_num >= 1){
		MY_EV_SUB(32);
		if (EV_YOUR_CAN >= 1){
			MY_EV_SUB(32);
		}
	}

	// fen 4ka3/2Nc5/6P2/9/3C5/9/9/B4K3/4p4/4c1B2 b - - 0 0 这个是红方好。

	if(StoY(mpawn) == MY_RANK3){
		MY_EV_ADD(32);
	}

	if(StoY(ypawn) MY_LARGE_EQL StoY(mk) && !IsOnSameSide(ypawn,mk)){
		MY_EV_ADD(32);
	}

	// fen 2bk2b2/4a4/1N6c/9/3P5/2p6/9/3A1C3/4A4/2c1K4 b - - 0 1
	if ((my_shi_num + my_xiang_num) <= 3){
		MY_EV_SUB(EV_MY_CAN * 16);
	}

	// fen 3ak4/4a4/4b3b/5P1C1/4c4/6B2/3p5/5An1B/4AC3/3K5 w - - 0 1
	if ((your_shi_num + your_xiang_num) == 4){
		MY_EV_SUB(32);
	}


	// fen 9/C3a1P2/4k4/9/2n6/9/3p1c3/3AB4/4A4/2BC1K3 w - - 0 1
	if (StoY(mpawn) MY_SMALL_EQL StoY(yk)){
		MY_EV_SUB(32);
		if (EV_YOUR_CAN >= 1){
			MY_EV_SUB(24);
		}
	}

	// fen 9/5P3/3k5/4c4/3N5/2B3B2/9/3A1A3/2c2p3/3CK4 b - - 0 1
	if(EV_YOUR_CAN >= 1){
		if(StoY(mpawn) MY_SMALL StoY(yk)){
			MY_EV_SUB(32);
		}
	}

	// fen 6b2/5P3/3kb4/4c4/9/6B2/9/9/3p1CnC1/3AKA3 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num >= 1 && MY_SQ55 == mk){
		if(StoY(ypawn) MY_LARGE_EQL MY_RANK8){
			if(StoX(ypawn) < 0x4 && PB90(MY_SQ4D) == my_pao && PB90(MY_SQ4E) == your_ma){
				if(PB90(MY_SQ4F) == my_pao || PB90(MY_SQ50) == my_pao){
					RETRUN_MUL(4);
				}
			}
			if(StoX(ypawn) > 0x4 && PB90(MY_SQ4B) == my_pao && PB90(MY_SQ4A) == your_ma){
				if(PB90(MY_SQ49) == my_pao || PB90(MY_SQ48) == my_pao){
					RETRUN_MUL(4);
				}
			}
		}
	}

	//如果2炮方是仕相全,也要平衡一下分数
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
			if(StoY(ypawn) MY_SMALL MY_RANK5){
				RETRUN_MUL(4);
			}			
		}
		RETRUN_MUL(8);
	}

	// fen 4kab2/4a4/4b4/8C/1P7/9/6n2/1C1Ap4/4A4/4K3c b - - 0 0</
	if(my_shi_num == 2 && StoY(mk) == MY_RANK9){
		if(PB90(MY_SQ43) == your_pawn){
			if(PB90(MY_SQ42) == my_shi || PB90(MY_SQ44) == my_shi){
				Bitboard peat = POSITION.Pao_Eat_bb(Square(MY_SQ43));
				if(m_have_bit(m_and(peat,bb_my_pao))){
					MY_EV_ADD(256);
					RETRUN_MUL(8);
				}
			}
		}
	}


	MY_EV_SUB(EV_YOUR_CAN * 32);
	// fen 9/6P2/5k3/4cn3/2b3b2/1C1C5/6p2/4B4/4A4/4KA3 b
	if(your_xiang_num >= 1 && StoY(mpawn) MY_SMALL_EQL StoY(yk)){
		MY_EV_SUB(32);
		MY_EV_SUB(EV_YOUR_CAN * 32);
	}

	// fen 2bCk2P1/3P5/4b4/9/7c1/4n4/9/2CA5/5p3/3K5 b - - 0 1
	if(your_xiang_num == 2){
		if(have_bit(bb_my_pawn,RankBB_A[MY_RANK0])){ // 有一个底兵
			if(PB90(MY_SQ04) == your_king){
				if(PB90(MY_SQ03) == my_pao && PB90(MY_SQ0C) == my_pawn && PB90(MY_SQ02) == your_xiang){
					MY_EV_SUB(64);
				}
				if(PB90(MY_SQ05) == my_pao && PB90(MY_SQ0E) == my_pawn && PB90(MY_SQ06) == your_xiang){
					MY_EV_SUB(64);
				}
			}
		}
	}
	// fen 3a1a3/2P6/5k3/3c5/2b6/3C5/3p5/B4A3/4A1n2/3KC4 r
	if(my_shi_num == 2 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9){
		if(your_shi_num >= 1 || StoY(yk) MY_LARGE_EQL StoY(mpawn)){
			Bitboard mp = m_and(bb_my_pao,MyLowBB[MY_RANK4]);
			if(count_1s(mp) == 2 && StoY(ypawn) MY_SMALL_EQL MY_RANK6){
				if (have_bit(bb_my_pao, RankBB_A[MY_RANK9])) {
					RETRUN_MUL(8);
				}
			}
		}
	}

	// 对方的兵给我方打着呢
	// fen 4k4/3Pa1cC1/5a3/4N4/9/4c4/9/4B4/3pA4/4KAB2 b - - 0 1
	if(my_shi_num == 2 && StoY(mk) == MY_RANK9 && StoY(ypawn) == MY_RANK8 && EV_MY_CAN >= 1){
		if(bit_is_set(ei.attacked_by(my_pao),ypawn)){
			RETRUN_MUL(8);
		}
	}

	// fen 3a2b2/4a1P2/4k3b/c1C6/9/C5B2/4n4/8B/3p5/3A1K3 w - - 0 1
	if(my_shi_num >= 1 && my_xiang_num == 2){
		if(StoY(ypawn) MY_LARGE_EQL MY_RANK8){
			if((StoX(ypawn) < 0x4 && PB90(MY_SQ54) == my_shi)
			  ||(StoX(ypawn) > 0x4 && PB90(MY_SQ56) == my_shi)){
				MY_EV_ADD(64);
				if(StoY(ypao) MY_SMALL_EQL MY_RANK4 && abs(StoX(ypao) - 0x4) >= 2){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 5a3/4a4/3c1k3/1P7/9/7C1/9/2n1CA3/3KA1p2/9 b - - 0 1
	if(my_shi_num == 2 && StoY(ypawn) MY_LARGE_EQL StoY(mk) && !IsOnSameSide(mk,ypawn)){
		if(your_shi_num == 2 && EV_MY_CAN >= 1){
			RETRUN_MUL(8);
		}
	}

	if(my_shi_num == 2 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9){
		if(EV_MY_CAN){
			if(StoY(ypao) == MY_RANK9){
				if(count_1s(bb_my_pao,RankBB_A[MY_RANK8]) == 2){
					if(StoY(ypawn) MY_SMALL_EQL MY_RANK7){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 3a1a3/5P3/3k4b/4c4/4C1b2/2BC5/9/3p5/4A2n1/3AK4 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9){
		if(EV_MY_CAN >= 1){
			if(StoY(ypawn) MY_LARGE_EQL MY_RANK7){
				if(!IsOnSameSide(ypawn,mk)){
					if(StoX(ypawn) < 0x4 && !have_bit(bb_my_shi,RightBB[0x4])){
						RETRUN_MUL(8);
					}
					if(StoX(ypawn) > 0x4 && !have_bit(bb_my_shi,LeftBB[0x4])){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 3k1ab2/4a4/4b4/5Cc1C/8p/9/8P/6n1B/4AK3/2BA5 b - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(your_shi_num == 2 && your_xiang_num == 2){
			if(EV_MY_CAN == 0 && EV_YOUR_CAN == 0){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 5P3/4k4/5c3/9/2b6/9/2nC5/B2A1C3/4A1p2/5K3 w - - 0 1
	if(your_shi_num == 0 && StoY(mpawn) MY_SMALL_EQL StoY(yk)){
		if(my_shi_num == 2 && my_xiang_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			if(have_bit(bb_my_shi,RankBB_A[MY_RANK7])){
				if(abs(StoX(ypawn) - 0x4) >= 2){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 4k4/3Pa2C1/4ba3/9/4Ccb2/9/1n3p3/3A5/4A4/4K4 b - - 0 1
	if(my_shi_num == 2 && StoY(mk) == MY_RANK9 && my_xiang_num >= 1){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK6 || abs(StoX(ypawn) - StoX(mk)) >= 2){
			RETRUN_MUL(8);
		}
		if(PB90(MY_SQ43) == your_pawn && have_bit(bb_my_shi,RankBB_A[MY_RANK7])){
			RETRUN_MUL(8);
		}
	}

	// fen 4kab2/4a4/2P1b4/4c4/9/4C4/4n4/B1p2A3/4A1C2/3K5 w - - 0 1
	if ((your_shi_num + your_xiang_num) >= 3){
		if ((my_shi_num + my_xiang_num) >= 3 && StoY(mk) == MY_RANK9){
			if (have_bit(bb_my_pao, MyLowBB[MY_RANK7])){
				RETRUN_MUL(8);
			}
		}
	}
}


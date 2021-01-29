#ifndef END_my_m_MT_R_1ma1pao1pawn_B_2pao
#define END_my_m_MT_R_1ma1pao1pawn_B_2pao
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮1马1兵对2炮.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 




void my_m_MT_R_1ma1pao1pawn_B_2pao(typePOS &POSITION, EvalInfo &ei){


	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao1MaXPawn_2Pao_ByPawnShi[your_shi_num]);

	Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	Square mma  = S90_from_piecelist(POSITION,my_ma,0);
	Square mpawn= S90_from_piecelist(POSITION,my_pawn,0);

	if(StoY(mpawn) == MY_RANK0 && StoY(yk) != MY_RANK0){
		MY_EV_SUB(96);
		if((your_shi_num + your_xiang_num) >= 1){
			MY_EV_SUB(64);
		}
		//fen 3P5/5k3/C4c3/3Nc4/6b2/9/9/4B4/4A4/2BAK4 b - - 0 1
		if (your_xiang_num >= 1){
			MY_EV_SUB(32);
		}
	}

	// fen 4P4/4ak3/6c2/6N2/6c2/9/9/4K3B/4A4/3A1C3 b - - 0 1
	//if(StoY(mpawn) == 

	// 对方二个炮在家里
	if(!have_bit(bb_your_pao,MyLowBB[MY_RANK4])){
		MY_EV_SUB(64);
	}

	// fen 2bak4/4a4/b8/6P2/c7c/N5B2/9/3AB4/3CA4/4K4 w - - 0 0
	//炮方是仕相全,且将是安全的
	if(StoY(yk) == MY_RANK0){
		if((your_shi_num + your_xiang_num) == 4){
			//如果没有中炮,就是和棋, 如果马或炮一个在家里,就是和棋
			if(StoY(mpao) MY_LARGE_EQL MY_RANK5 || StoY(mma) MY_LARGE_EQL MY_RANK5){
				RETRUN_MUL(2);
			}
		}
	}

	

	int mcan = EV_MY_CAN;

	// fen 4k4/4a4/b2ac4/2Nc5/9/2P3B2/9/4CA3/4A4/3K5 b - - 120 120
	//要想办法过兵哇
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
        if(mcan == 0){
			RETRUN_MUL(2);
		}
	}

	// fen 5c3/9/3k5/9/5C3/5n3/4C4/5K3/4p4/2B6 w - - 132 132
	if(StoY(mpawn) MY_SMALL StoY(yk)){
		if(my_shi_num == 0 && my_xiang_num == 0){
			if((your_shi_num + your_xiang_num) >= 1){
				RETRUN_MUL(4);
			}
		}
	}


	// fen 3k5/3caP3/4ba1c1/5C1N1/9/2B6/9/4BA3/4A4/4K4 b - - 0 0
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		//我方的兵给自己的炮保护和对方的炮攻击
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
		    Bitboard peat = POSITION.Pao_Eat_bb(mpawn);
			peat = m_and(peat,m_or(bb_my_pao,bb_your_pao));
			if(count_1s(peat) == 2){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4kab1C/1c1ca4/4P4/5N3/6b2/9/9/3AB3B/4K4/9 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
		if(PB90(MY_SQ16) == my_pawn 
			&& count_1s(bb_your_pao,RankBB_A[MY_RANK1]) == 2){
            if(MY_SQ20 == mma && !have_bit(bb_your_pao,RightBB[0x4])){
				RETRUN_MUL(4);
			}
			if(MY_SQ1E == mma && !have_bit(bb_your_pao,LeftBB[0x4])){
				RETRUN_MUL(4);
			}
		}

	}

	// fen 3k1ab2/9/5a3/9/9/9/9/4C4/3p1KC2/1n4c2 b - - 0 1
    if(StoY(mpao) == MY_RANK0 && StoY(mma) == MY_RANK0){
		if(StoY(yk) == MY_RANK1 && StoY(mpawn) == MY_RANK1){
			if(MY_SQ0E == mpawn && MY_SQ07 == mma){
				if(StoX(mpao) < 0x7){
					RETRUN_MUL(4);
				}
			}
			if(MY_SQ0C == mpawn && MY_SQ01 == mma){
				if(StoX(mpao) > 0x1){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 2b1k4/3PacC2/4ca3/4N4/9/2B6/9/4BA3/4A4/3K5 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(!have_bit(bb_your_pao,MyLowBB[MY_RANK3])){
			if(StoY(mpawn) == MY_RANK1 && PB90(MY_SQ0D) == your_shi && StoY(yk) == MY_RANK0){
				Bitboard ybmp = m_and(bb_your_pao,RankBB_A[MY_RANK1]);
				if(StoX(mpawn) <= 0x3 && have_bit(ybmp,RightBB[0x4]) && StoX(mpao) >= 0x6 && PB90(MY_SQ05) != your_shi){
					RETRUN_MUL(4);
				}
				if(StoX(mpawn) >= 0x5 && have_bit(ybmp,LeftBB[0x4]) && StoX(mpao) <= 0x2 && PB90(MY_SQ03) != your_shi){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 3k1a3/9/4ba3/9/6b2/5p3/nC2c4/B3C4/4A4/4KAB2 w - - 13 13
	if(StoY(yk) == MY_RANK0){
		if((your_shi_num + your_xiang_num) == 4){

			if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
				MY_EV_SUB(32);
			}
			MY_EV_SUB(64);

			// fen 2ba1k3/2P1a1N2/4bc3/1c7/4C4/2B6/9/4B4/4A4/3K1A3 b - - 0 1
			if(!IsOnSameSide(mpawn,yk)){
				MY_EV_SUB(64);
			}

			RETRUN_MUL(8);
		}
	}

	// fen 2b6/2NkaP3/3ab4/4c4/9/9/3c5/B2CB4/4A4/4KA3 b - - 121 121
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		// fen 1Cba1k3/4a4/5c3/4PN3/2b6/2B3B2/4c4/9/4A4/4K4 w - - 0 1
		

		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && !IsOnSameSide(mpawn,yk)){
			RETRUN_MUL(8);
		}
	}
	


	// fen 4k4/4a4/b2ac4/2Nc5/9/2P3B2/9/4CA3/4A4/3K5 b - - 120 120
	// fen 3k5/4ac3/5a2b/8C/2N1c1b2/2B5P/9/5A3/5K3/5A3 w - - 121 121
	//要想办法过兵哇
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
			RETRUN_MUL(8);
		}
		// fen 5k3/3ca1c2/2P1baN2/4C4/9/2B3B2/9/9/4A4/4K4 w - - 0 110 
		if(!IsOnSameSide(mpawn,yk)){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK2){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 5k3/2P1acCc1/3ab4/1N7/9/9/9/8B/9/2B1K4 b - - 205 205
	//我方的兵到了第二线,且不能接近9宫,也是和棋
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(StoY(yk) == MY_RANK0 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(abs(StoX(mpawn) - 0x4) >= 2){
				MY_EV_SUB(96);
				if(my_shi_num == 0){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 3k1ab2/4a4/9/9/9/9/3p5/2nAB2C1/3KAC1c1/6B2 b
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			if(count_1s(bb_your_pao,MyUpBB[MY_RANK3]) == 2 && StoY(mpao) MY_SMALL_EQL MY_RANK1){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 1N7/2P1k4/3a2c2/3c5/9/9/9/4B4/C8/3K5 w - - 0 1
	if(my_shi_num == 0 && your_shi_num >= 1){
		MY_EV_SUB(64);
	}

	// fen 2b2c3/5k3/4b3N/9/9/2B3P2/4c2C1/4BA3/4A4/3K5 b - - 0 1
    if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(EV_MY_CAN == 0){
			RETRUN_MUL(8);  
		}
	}

	// fen C4P3/3k1N3/c3c4/9/9/9/9/3A5/9/2BAK4 b - - 0 1
    if(StoY(mpawn) == MY_RANK0 && yk != MY_SQ04){
		if(!have_bit(bb_your_pao,MyLowBB[MY_RANK4])){
			RETRUN_MUL(8);
		}
	}

	// fen 3k4C/4a1P2/4ba2N/5c3/3c5/9/9/4B4/4A4/4K1B2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && !IsOnSameSide(mpawn,yk)){
			if(abs(StoX(mpawn) - StoX(yk)) >= 2){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 2b1k4/4ac3/bc7/4P4/4C2N1/9/9/4B4/4A4/2BK5 b - - 0 1
	if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){		
		if(your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk) == MY_RANK0){
			MY_EV_SUB(64);
			if(!have_bit(bb_your_pao,MyLowBB[MY_RANK3])){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4k4/4a4/4Pac2/1c7/5C3/2B6/9/3ABN3/4K4/9 w - - 0 1
	if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if(PB90(MY_SQ16) == my_pawn && have_bit(bb_your_shi,RankBB_A[MY_RANK2])){
			if(bit_is_set(YOUR_ATTACK,Square(MY_SQ16))){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 9/4akN2/3a3P1/4C4/2b2c3/2c6/9/3A5/5K3/3A5 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(have_bit(bb_your_shi,RankBB_A[MY_RANK2])){
			if(abs(StoX(mpawn) - 0x4) >= 2){
				RETRUN_MUL(8);
			}
		}
	}

}


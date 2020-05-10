#ifndef END_my_m_MT_R_2pao1pawn_B_2pao
#define END_my_m_MT_R_2pao1pawn_B_2pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2ез1╠Ь╤т2ез.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 




void my_m_MT_R_2pao1pawn_B_2pao(typePOS &POSITION, EvalInfo &ei){
	
	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2PaoXPawn_2Pao_ByPawnShi[your_shi_num]);

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	// fen 2P6/9/5k3/9/9/9/C3c4/3CB4/4A4/c1BAK4 b - - 0 1
	if(StoY(mpawn) == MY_RANK0){
		MY_EV_SUB(32);
		if(StoY(yk) != MY_RANK0){
			MY_EV_SUB(32);
		}
	}

	if (my_shi_num == 0){
		MY_EV_SUB(64);
	}

	// fen 2ba1ab2/c3k4/9/4C4/4P4/4C4/7c1/9/9/2BAKAB2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 
		&& StoY(yk) MY_SMALL_EQL MY_RANK1){
			MY_EV_SUB(64);
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
				MY_EV_SUB(32);
			}
	}

	if(your_shi_num == 2 && your_xiang_num == 2){
		RETRUN_MUL(4);
	}

	// fen 2b2k3/4a4/3a5/3P5/C8/3c2B2/C8/9/4A4/2c1K4 b - - 0 1
	if(your_xiang_num >= 1 && your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			RETRUN_MUL(4);
		}
	}

	// fen 3k5/3ca4/1cCaP4/9/9/2B6/9/3AB4/4A4/2C1K4 b - - 0 1
	if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if(MY_SQ16 == mpawn && have_bit(RankBB_A[MY_RANK2],bb_your_shi)){
			if(have_bit(RankBB_A[MY_RANK2],bb_my_pao) 
				&& have_bit(RankBB_A[MY_RANK2],bb_your_pao)){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 5a3/6P2/4k4/9/9/2B6/4c4/4B4/3Kc4/2C1C4 w - - 0 1
	if(my_shi_num == 0 && StoY(mpawn) MY_SMALL_EQL StoY(yk)){
		RETRUN_MUL(4);
	}

	if(StoY(mpawn) == MY_RANK0){

		// fen 2P6/9/5k3/9/9/9/C3c4/3CB4/4A4/c1BAK4 b - - 0 1
		Bitboard B = m_and(POSITION.Pao_Super_bb(mk),bb_your_pao);

		if(count_1s(B) == 2){
			RETRUN_MUL(4);
		}

		RETRUN_MUL(8);
	}

	// fen 9/9/3ak4/9/9/9/4C4/4p4/4A3c/4KABcC b - - 0 1
	if((your_shi_num + your_xiang_num) >= 3){
		RETRUN_MUL(8);
	}

	// fen 2bk5/9/9/4P4/2bc5/3c2B2/4C4/6C2/9/5K3 w - - 0 1
	if (your_xiang_num == 2 && my_shi_num == 0){
		if (abs(StoY(mpawn) - StoY(yk)) >= 2){
			RETRUN_MUL(8);
		}
	}

	// fen 2bk3c1/1cC6/1C2bP3/9/9/9/9/9/4K4/9 r
	if(your_xiang_num == 2){
		if(my_shi_num == 0){
			if(abs(StoX(mpawn) - StoX(yk)) >= 2 && abs(StoY(mpawn) - StoY(yk)) >= 2){
				RETRUN_MUL(8);
			}
		}
	}
}


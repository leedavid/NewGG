#ifndef END_my_m_MT_R_1pao1ma_1pawn_B_1che
#define END_my_m_MT_R_1pao1ma_1pawn_B_1che
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮1马1兵对1车.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



void my_m_MT_R_1pao1ma_1pawn_B_1che(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao1MaXPawn_To_1Che_PawnByShi[your_shi_num]);


	//Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square mk    = my_king_pos;
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	//Square yk    = your_king_pos;
	Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	// fen 5kb2/3P5/3a1a3/9/2b6/6B2/4r4/3NBA3/1C2AK3/9 w - - 0 0
	if(StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(my_shi_num == 2){
			EV_MY_SAFE = TRUE;
		}
		if(my_xiang_num == 2){
			EV_MY_SAFE = TRUE;
		}
	}

	if(my_shi_num <= 1){
		if(your_shi_num >= 1 && your_xiang_num >= 1){
			MY_EV_ADD(64);
		}
	}

	if((your_shi_num + your_xiang_num) >= 3){
		EV_YOUR_SAFE = TRUE;
	}

	int mcan = EV_MY_CAN;
	Square mma  = S90_from_piecelist(POSITION,my_ma,0);
	
	// fen 3c2bn1/3ka2R1/4ba3/9/6p2/9/9/3AB4/4A4/2B1K3p b - - 121 121
	if(StoY(mma) == MY_RANK9 && PB90(mma MY_SUB 0x9) == your_che){ //PB90(mma MY_SUB 0x9] 
		MY_EV_SUB(196);
	}

	// fen 3Rk1b2/9/4b4/9/6p2/9/9/3K1n2B/5c3/3A5 b - - 36 36
	if(my_shi_num == 0){
		MY_EV_SUB(128);
	}

	if(mcan == 0){
		MY_EV_SUB(96);
	}

	// fen 2b1ka3/4a4/9/9/2b3c2/p8/nR7/3A5/4A4/4K4 w - - 0 1
	if(your_shi_num == 2 || your_xiang_num == 2){
		MY_EV_SUB(96);
	}
	// fen 2b1ka3/4a4/9/9/2b3c2/p8/nR7/3A5/4A4/4K4 w - - 0 1
	if(abs(StoX(mma) - 0x4) == 4 && bit_is_set(ei.attacked_by(your_che),mma)){
		MY_EV_SUB(80);
		if(EV_MY_SAFE){
			RETRUN_MUL(8);
		}
	}

	if((your_shi_num + your_xiang_num) >= 2 && mcan == 0){
		if(EV_MY_SAFE){
			RETRUN_MUL(8);
		}
	}

	// fen 1P3ab2/3k5/5a3/9/6b2/9/5N3/5K3/9/5C2r w - - 0 1
	if(StoX(mpao) == StoX(mk) && StoY(mpao) MY_LARGE StoY(mk)){
		if(StoX(mma) == StoX(mk) && StoY(mma) MY_SMALL StoY(mk)){
			RETRUN_MUL(8);
		}
	}

	// fen 3k5/3r1NP2/5a3/9/6b2/9/9/4BA3/4KC3/2B6 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num >= 1 && your_xiang_num >= 1){
			if(abs(StoX(yk) - StoX(mpawn)) >= 2){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4ka3/4a4/4b4/9/3PN1b2/9/7r1/3C5/4A4/4K4 w - - 0 1
	if (my_shi_num >= 1 && MY_SQ55 == mk){
		if (StoY(mpao) MY_LARGE_EQL MY_RANK7){
			if (StoY(mpawn) == MY_RANK4 || StoY(mpawn) == MY_RANK3){
				if (abs(StoX(mpawn) - 0x4) <= 1){
					if (StoY(mma) MY_LARGE_EQL MY_RANK4){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}
}


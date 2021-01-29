#ifndef END_my_m_MT_R_1che2pawn_B_1che1ma
#define END_my_m_MT_R_1che2pawn_B_1che1ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车2兵对1车1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//const PanwAdd = 32;

void my_m_MT_R_1che2pawn_B_1che1ma(typePOS &POSITION, EvalInfo &ei){


	// ADD
	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Square mche = S90_from_piecelist(POSITION, my_che, 0);
	Square yche = S90_from_piecelist(POSITION, your_che, 0);
	Square yma = S90_from_piecelist(POSITION, your_ma, 0);
	Bitboard bmp = m_and(bb_my_pawn, MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePawn_To_CheMa_By_PawnByShi[your_shi_num]);

	// fen 3ak1b2/4a4/1n6b/7P1/9/P2R5/9/3KB4/1r2A4/5AB2 b - - 0 1
	if (your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		EV_YOUR_SAFE = TRUE;
	}
	if ((your_shi_num + your_xiang_num) >= 2){
		if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK2])){
			EV_YOUR_SAFE = TRUE;
		}
	}

	if (your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0) {
		if (have_bit(bb_my_pawn, MyLowBB[MY_RANK2])) {
			EV_YOUR_SAFE = TRUE;
		}
	}

	// fen 3aka3/9/9/3P1P3/6b2/9/9/5A3/4AKR2/6nr1 b - - 0 1
	if (my_shi_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if (your_xiang_num <= 1){
			if (count_1s(bmp, MyUpBB[MY_RANK4]) == 2){
				MY_EV_ADD(32);
				if (IsOnSameSide(yma, mche)){
					MY_EV_ADD(32);
				}
			}
		}
	}

	//  fen 3ak1b2/4a4/9/6P1P/6b2/3r5/3n5/3R5/9/3K5 w - - 0 1
	
	if (StoX(mche) == StoX(yche) && isStringByChe(POSITION, mche, yma, yche)) {
		MY_EV_ADD(64);
		if (StoX(mche) == StoX(mk) && StoY(mche) MY_SMALL StoY(mk)) {
			MY_EV_ADD(64);
			if (have_bit(bb_my_pawn, RankBB_A[MY_RANK3])) {
				MY_EV_ADD(32);

				if (EV_YOUR_SAFE) {
					RETRUN_MUL(2);
				}
			}
		}
	}

	if ((my_shi_num + my_xiang_num) >= 3 && StoY(mk) MY_LARGE_EQL MY_RANK8) {
		MY_EV_ADD(32);
		// fen 3ak1b2/4a4/4b4/9/9/P8/4P1nrP/2R6/4A4/2BK1A3 b - - 0 1
		MY_EV_ADD(EV_MY_CAN * 32);
	}


	if(my_shi_num == 2 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9){
		if(your_shi_num == 2){
			RETRUN_MUL(2);
		}
		// fen 9/5P3/4k4/R1n6/2r6/P8/9/4B4/4A4/3AK4 w - - 0 1 can not mul 4
		if(your_shi_num >= 1){
		    RETRUN_MUL(4);
		}
	}

	int isstr = isStringByChe(POSITION,mche,yma,yche);


	// fen 5a3/1P2a1P2/5k3/7r1/2b3b2/9/7n1/7R1/4A4/4K4 w - - 28 28
	if(isstr){
		if(StoY(mk) == MY_RANK9 && (my_shi_num + my_xiang_num) >= 1){
			EV_MY_SAFE = TRUE;
		}
		MY_EV_ADD(96);
	}

	Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);

	if(StoY(mpawn1) MY_SMALL StoY(yk) && StoY(mpawn2) MY_SMALL StoY(yk)){
		if((your_shi_num + your_xiang_num) >= 2){
			EV_YOUR_SAFE = TRUE;
		}
	}

	if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		EV_YOUR_SAFE = TRUE;
	}

	// fen 3ak1b2/2P6/5R3/8P/9/9/9/3nB4/5K3/6r2 b - - 0 1
	if(my_xiang_num >= 1 && !IsOnSameSide(mk,yma) && StoY(mk) != MY_RANK7){
		if(your_shi_num <= 1 && your_xiang_num <= 1){
			if(have_bit(bb_my_pawn,RankBB_A[MY_RANK1]) && EV_MY_CAN == 2){
				MY_EV_ADD(EV_MY_CAN * 32);
				if(StoX(mche) == StoX(mk)){
					MY_EV_ADD(128);
				}
			}
		}
	}

	// fen 9/4k4/r8/4PP3/9/9/3R5/9/3K2n2/9 w - - 0 1
	if(your_shi_num == 0 && your_xiang_num == 0){
		if(StoY(mpawn1) MY_SMALL_EQL MY_RANK3 && StoY(mpawn1) != MY_RANK0){
			if(StoY(mpawn2) MY_SMALL_EQL MY_RANK3 && StoY(mpawn2) != MY_RANK0){
				MY_EV_ADD(32);
				if(!IsOnSameSide(mk,yma)){
					MY_EV_ADD(32);
				}
			}
		}
	}

	
	//如果兵方一个子也没有了
	if((my_shi_num + my_xiang_num) <= 1){
		MY_EV_SUB(196);
	}
	// fen 2bak4/9/3a5/9/2b6/6B1P/PR7/3ABn3/8r/3K5 w - - 0 1
	if(EV_YOUR_SAFE){
		if((my_shi_num + my_xiang_num) >= 3){
			if(StoY(mk) MY_LARGE_EQL MY_RANK8){
				RETRUN_MUL(4);
			}
		}
	}




	// fen 4k4/9/4b3b/3N2r2/3R5/7pp/9/4B4/4A4/3AK4 w - - 7 7
	if(StoY(mk) MY_LARGE_EQL MY_RANK8 && my_xiang_num == 2){
		if(your_shi_num == 2){
			RETRUN_MUL(8);
		}
	}
	//如果所有兵在兵线上	
	// fen 2b1k4/9/4b4/9/P1P1R3P/9/2r6/3An4/4A4/3K5 b - - 3 3
	if(my_xiang_num == 0 && StoY(yma) MY_LARGE_EQL MY_RANK5){
		Bitboard p = m_and(bb_my_pawn,MyLowBB[MY_RANK4]);
		if(count_1s(p) == 2){
			MY_EV_SUB(168);
		}
	}
	// fen 4k1b2/4a4/2P1b4/5R1P1/9/2B6/r8/4Bn3/9/5K3 b - - 0 1
	if(EV_MY_CAN == 2 && your_shi_num <= 1){
		if(my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			MY_EV_ADD(128);
		}
		if(my_shi_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			MY_EV_ADD(32);
		}
	}


	// fen 3ak1b2/4a4/1n6b/7P1/9/P2R5/9/3KB4/1r2A4/5AB2 b - - 0 1
	if(EV_YOUR_SAFE){
		if(my_shi_num == 2 && my_xiang_num == 2){
			if(StoY(yma) MY_SMALL_EQL MY_RANK4){
			   RETRUN_MUL(8);
			}
		}
	}

	// fen 2b1ka3/4a4/b8/9/3PP4/2Bn5/4r4/5R3/4A4/4K4 b - - 0 1
	if(EV_YOUR_SAFE){
		if((my_shi_num + my_xiang_num) >= 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			Bitboard lp = My_get_connect_Pawn(POSITION);
			if(bit_is_set(lp,MY_SQ28) || bit_is_set(lp,MY_SQ1F)){
				RETRUN_MUL(8);
			}
		}
	}

}


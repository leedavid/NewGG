#ifndef END_my_m_MT_R_1che3pawn_B_1che2pawn
#define END_my_m_MT_R_1che3pawn_B_1che2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车3兵对1车2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1che3pawn_B_1che2pawn(typePOS &POSITION, EvalInfo &ei){


	// fen 9/4k4/4b4/p3r3p/9/P6RP/9/4B4/4Ap3/2B1KA3 b - - 246 246
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_ChePawn_To_ChePawnByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_ChePawn_To_ChePawnByShi[my_shi_num]);

	int ycan = EV_YOUR_CAN;
	int mcan = EV_MY_CAN;

	if(ycan == 0){
		//if(my_shi)
	}

	
	//黑方安全
	if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if(mcan <= 1){
			EV_YOUR_SAFE = TRUE;
		}
	}

	if(my_shi_num == 2 && StoY(mk) == MY_RANK9){
	   if(ycan <= 1){
		   EV_MY_SAFE = TRUE;
	   }
	}

	int malr = My_pawn_already_over_river(POSITION);
	int yalr = Your_pawn_already_over_river(POSITION);

	//1, 红方只有一个兵可过河． 2,且只过河了一个兵 3,黑方只有一个兵可过河，就是和棋
	// fen 2bak4/4a4/2P1b4/p6rp/4p4/2R5P/P5P2/4B4/9/3AKAB2 w - - 3 3
	if(mcan <= 1 && malr <= 1){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			EV_YOUR_SAFE = TRUE;
		}
	}

	if(yalr <= 1){
		if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
			EV_MY_SAFE = TRUE;
		}
	}

	// fen 3ak1b2/9/4b4/p8/2r5p/6P2/P3R3P/4B4/9/4K4 b - - 0 1
	if(my_xiang_num >= 1){
		if(EV_YOUR_CAN == 0){
			if(PB90(MY_SQ3A) == my_che 
				&& PB90(MY_SQ36) == my_pawn && PB90(MY_SQ3E) == my_pawn){
					EV_MY_SAFE = TRUE;
			}
		}
	}
	if(your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(EV_MY_CAN <= 1 && malr == 0){
			EV_YOUR_SAFE = TRUE;
		}
	}


	Square yche = S90_from_piecelist(POSITION,your_che,0);
	Square mche = S90_from_piecelist(POSITION,my_che,0);


	// fen 2baka3/9/4b4/2P4rp/P8/9/8P/4p4/4A1R2/3AK4 b - - 0 1
	if (EV_MY_SAFE) {
		MY_EV_ADD(64);
		if (my_shi_num == 2 && StoY(mk) == MY_RANK9) {
			MY_EV_ADD(32);
			if (EV_YOUR_CAN <= 1) {
				MY_EV_ADD(64);
			}
			if (count_1s(bb_my_pawn, MyUpBB[MY_RANK5]) >= 2) {
				MY_EV_ADD(32);
			}
		}
		
	}

	// fen 4kab2/4a4/4b4/pr7/6p1p/9/P3R3P/4B4/4A4/4K1B2 w - - 4 4
	if(mcan == 0 && malr == 0){
		if(StoY(yche) == MY_RANK3){
			if(your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk) == MY_RANK0){
				Bitboard ratt = POSITION.Rook_attacks_bb(yche);
				ratt = m_and(ratt,bb_your_pawn);
				if(count_1s(ratt) == 2){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 1R4b2/4k4/4b4/r7p/6p2/6B1P/P5P2/9/4A4/3AK1B2 w - - 123 123
	if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(ycan == 0 && mcan <= 1){
			if(StoY(yche) == MY_RANK3 || StoY(yche) == MY_RANK4){
				if(PB90(MY_SQ36) == my_pawn && StoX(yche) == 0x0){
					RETRUN_MUL(2);
				}
				if(PB90(MY_SQ3E) == my_pawn && StoX(yche) == 0x8){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 3k1a3/4a4/8b/4P4/p2r2b1p/9/P3R3P/9/9/4K4 w - - 142 142
	if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1 && mcan <= 1){
		// 顶死二个兵
		if(StoY(mche) == MY_RANK6){
			Bitboard b1 = m_and(bb_my_pawn,RankBB_A[MY_RANK6]);
			if(count_1s(b1) == 2){
				if(ycan == 0){
					RETRUN_MUL(4);
				}
			}
		}
	}
	

	// fen 2b1ka3/4aR3/4b4/4P4/1r7/2P1P4/9/9/4A1pp1/3AK4 w - - 58 58
	if(my_shi_num == 2 && PB90(MY_SQ55) == my_king){
		Bitboard b1 = m_and(bb_your_pawn,MyLowBB[MY_RANK7]);
		if(count_1s(b1) == 2){
			Bitboard b2 = m_and(b1,LeftBB[0x4]);
			if(count_1s(b2) == 2){
				MY_EV_ADD(128);
			}
			b2 = m_and(b1,RightBB[0x4]);
			if(count_1s(b2) == 2){
				MY_EV_ADD(128);
			}
		}
	}


	// fen 1R1ak1b2/4a4/4b4/p4P2p/4r4/6P2/8P/4B4/4A4/3AK1B2 w - - 3 3
	//我方只可过二兵,
	if(EV_MY_SAFE){
		if(mcan <= 2 && malr <= 1){
			if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
				if(count_1s(bmp,MyUpBB[MY_RANK3]) == 0){
					RETRUN_MUL(4);
				}
				RETRUN_MUL(8);
			}
		}
	}

	

}


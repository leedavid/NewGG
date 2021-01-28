#ifndef END_my_m_MT_R_1che3pawn_B_1che1pawn
#define END_my_m_MT_R_1che3pawn_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车3兵对1车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int PanwAdd = 32;

void my_m_MT_R_1che3pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){
	
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

	int mcan = EV_MY_CAN;
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	int ycan = EV_YOUR_CAN;

	Square mche = S90_from_piecelist(POSITION,my_che,0);
	Square yche = S90_from_piecelist(POSITION,your_che,0);

	if(EV_YOUR_CAN == 0){
		EV_MY_SAFE = TRUE;
	}
	if(StoY(mk) MY_LARGE_EQL MY_RANK8 && my_shi_num == 2){
		EV_MY_SAFE = TRUE;
	}

	// fen 3akab2/9/4b4/9/P2P4p/4P1r2/4R3P/9/4K4/9 b - - 0 1
	if(EV_YOUR_CAN == 0){
		MY_EV_ADD(EV_MY_CAN * 16);
	}

	// fen 4kab2/4a4/9/3P1P2P/6b2/9/9/3A1R3/3p1K3/7r1 b - - 0 1
	if (my_shi_num >= 1 && StoY(ypawn) MY_LARGE_EQL MY_RANK8){
		if (StoX(ypawn) <= 0x3 && StoX(mk) == 0x5){
			MY_EV_ADD(32);
			if (PB90(MY_SQ42) == my_shi && StoX(mche) == 0x5){
				MY_EV_ADD(32);
				if (EV_MY_CAN >= 3){
					MY_EV_ADD(64);
				}
			}
		}
		if (StoX(ypawn) >= 0x5 && StoX(mk) == 0x3){
			MY_EV_ADD(32);
			if (PB90(MY_SQ44) == my_shi && StoX(mche) == 0x3){
				MY_EV_ADD(32);
				if (EV_MY_CAN >= 3){
					MY_EV_ADD(64);
				}
			}
		}
	}

	if (my_shi_num == 0 && StoY(ypawn) MY_SMALL_EQL MY_RANK8) {
		MY_EV_SUB(64);
	}

	// fen 5a3/3k5/b2a5/9/r8/4P1P2/8P/2p1B4/9/3RKAB2 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1) {
		Bitboard mp = m_and(bb_my_pawn, MyLowBB[MY_RANK4]);
		MY_EV_SUB((sint16)count_1s(mp) * 32);
	}

	// fen 2baka3/9/4b4/9/1P7/2B1P4/1R6P/3r2p2/4A4/4K4 b - - 0 1
	if (my_shi_num >= 1 && my_xiang_num >= 1) {
		MY_EV_ADD(EV_MY_CAN * 16);
		if (abs(StoX(ypawn) - 0x4) >= 2) {
			MY_EV_ADD(64);
		}
		if (StoY(ypawn)  MY_SMALL_EQL MY_RANK7) {
			MY_EV_ADD(32);
		}
	}

	int malr = My_pawn_already_over_river(POSITION);
	//如果红方三个兵都没有过河,红方是仕相全,就是和棋
	// fen 4k1b2/4a4/4ba3/9/2p3p1p/9/4R3P/4B4/4A3r/2B1KA3 w - - 0 0
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if(mcan == 0){
			if(ycan == 0 || my_shi_num >= 1){
				RETRUN_MUL(2);
			}
		}
		if(mcan == 1){			
			if(ycan == 0 || my_shi_num >= 1){
				RETRUN_MUL(2);
			}			
		}
		//只有2个兵能过河, 但对方的兵都在家里
		if(mcan == 2){			
			if(ycan == 0 || my_shi_num >= 1){
				if(malr == 0){
					RETRUN_MUL(2);
				}
			}			
		}

		// fen 4kab2/4a4/4b4/r3P4/8p/9/P3R3P/4B4/9/2BAKA3 w - - 9 9
		//车兵兵对车组成了一个十字,且另一个兵成对头
		if(mcan <= 2){
			int x1 = XYtoS(StoX(mche),StoY(yche));
			int x2 = XYtoS(StoX(yche),StoY(mche));
			if(PB90(x1) == my_pawn && PB90(x2) == my_pawn){
				if(StoX(x1) == 0x4 && (StoX(x2) == 0x0 || StoX(x2) == 0x8)){
					RETRUN_MUL(2);
				}
				if(StoX(x2) == 0x4 && (StoX(x1) == 0x0 || StoX(x1) == 0x8)){
					RETRUN_MUL(2);
				}
			}
		}
	}		
	// fen 5ab2/3ka4/4b4/9/p3r4/2P6/PR6P/4B4/4A4/4KAB2 w - - 1 1
	if((your_shi_num + your_xiang_num) == 4){
		if(StoY(yk) MY_SMALL_EQL MY_RANK1){
		   if(malr == 0 && StoY(ypawn) == StoY(yche) && StoY(mche) == MY_RANK6){
			   if(PB90(MY_SQ24) == your_pawn && PB90(MY_SQ36) == my_pawn && PB90(MY_SQ2F) == my_pawn){
				   RETRUN_MUL(2);
			   }
			   if(PB90(MY_SQ2C) == your_pawn && PB90(MY_SQ3E) == my_pawn && PB90(MY_SQ33) == my_pawn){
				   RETRUN_MUL(2);
			   }
		   }
		}
	}	

	// fen 2b1k4/4a4/9/p4P2p/9/1p7/r8/4B4/3R5/3AKAB2 w - - 0 0
	if(my_shi_num >= 1 && your_xiang_num >= 1 && StoY(mk) == MY_RANK9){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK6){
			MY_EV_ADD(mcan * 32);
		}
	}

	// fen 4ka3/4aP3/4b3b/9/1r2PR3/6P2/5p3/4B4/4A4/3A1KB2 w - - 
	if(mcan <= 2 && malr <= 2){
		if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
			if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
				if(abs(StoX(ypawn) - 0x4) <= 1 && StoY(yche) == StoY(mche)){
					if((StoX(mche) >= 0x4 && PB90(MY_SQ05) == your_shi)
						||(StoX(mche) <= 0x4 && PB90(MY_SQ03) == your_shi)){
							if(StoY(yche) == MY_RANK4){
								Bitboard be = m_and(BetweenBB[mche][yche],BitboardOCC);
								if(count_1s(be) == 1){
									int sq = pop_1st_bit_sq(be);
									if(PB90(sq) == my_pawn){
										RETRUN_MUL(4);
									}
								}
							}
					}					
				}
			}
		}
	}

	// fen 4kab2/4a4/9/8p/1rb2P3/P1R5P/9/4B4/4A4/3AK4 w - - 0 1
	if (EV_MY_SAFE){
		if ((your_shi_num + your_xiang_num) == 4){
			if (EV_MY_CAN <= 2){
				if ((count_1s(bb_my_pawn, RankBB_A[MY_RANK5])) >= 2
					&& StoY(mche) == MY_RANK5){
					RETRUN_MUL(4);
				}
			}
		}
	}



	// fen 4k1b2/4a4/4b4/p8/2r6/6P1P/P3R4/4B4/4K4/9 b - - 0 1 
	if(my_xiang_num >= 1 || my_shi_num >= 1){
		if(EV_YOUR_CAN == 0){
			MY_EV_ADD(48);
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}
	// fen 4ka3/4a4/r8/3P5/9/3R5/9/1pp1B4/2p6/2BAKA3 b - - 0 1
    if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			Bitboard mp = m_and(bb_my_pawn,MyUpBB[MY_RANK3]);
			if(count_1s(LeftBB[0x3],mp) == 3){
				if(StoX(yk) >= 0x4){
					RETRUN_MUL(8);
				}
			}
			if(count_1s(RightBB[0x5],mp) == 3){
				if(StoX(yk) <= 0x4){
					RETRUN_MUL(8);
				}
			}
		}
	}




	// fen 2b6/4ak3/b4a3/6R1p/9/9/P3P1P1r/9/4A4/3AK1B2 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			MY_EV_SUB(64);
			if (EV_YOUR_CAN >= 1) {
				if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK5])) {
					RETRUN_MUL(8);
				}

				if (EV_MY_CAN <= 2 && count_1s(bb_my_pawn, MyLowBB[MY_RANK4]) >= 2) {
					RETRUN_MUL(8);
				}
			}
		}
	}


}


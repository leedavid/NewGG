#ifndef END_my_m_MT_R_1che1ma1pawn_B_1che2pawn
#define END_my_m_MT_R_1che1ma1pawn_B_1che2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1马1兵对1车2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che1ma1pawn_B_1che2pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_CheMaXPawn_VS_1Che2Pawn_ByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1Che2Pawn_VS_CheMaXPawn_ByShi[my_shi_num]);

	int mcan = EV_MY_CAN;
	int ycan = EV_YOUR_CAN;
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	// fen 3ak1b2/4a4/4b4/1N1R5/2r5p/2B6/8P/5A3/2p6/4KA3 b - - 0 1
	if(my_shi_num == 2 && EV_YOUR_CAN <= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		EV_MY_SAFE = TRUE;
	}

	// fen 4k1b2/4a4/3ab4/9/4r4/1p4P1p/7R1/3NBA3/9/4KAB2 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2){
		EV_MY_SAFE = TRUE;
	}


	
	// fen 3ak1bN1/4a1r2/4b4/8p/6p2/R7P/9/8B/4A4/4KA3 b - - 0 0
	// fen 2b2k3/2R6/2N1b4/p1r6/8p/P5B2/8p/9/4A4/4KAB2 w - - 0 0
	Square mche = S90_from_piecelist(POSITION,my_che,0);
	Square yche = S90_from_piecelist(POSITION,your_che,0);
	Square mma  = S90_from_piecelist(POSITION,my_ma,0);
	bool isSma = isStringByChe(POSITION,mche,mma,yche);

	// fen 5a3/5k3/6R2/P8/9/5r3/3p5/N1p5B/4K4/2B6 w - - 0 1
	if(my_shi_num == 0 && EV_YOUR_CAN == 2){
		if(have_bit(bb_your_pawn,MyUpBB[StoY(mk)]) 
			&& !have_bit(bb_your_pawn,MyUpBB[MY_RANK5])){
				if(StoY(mma) MY_LARGE_EQL MY_RANK6){
					MY_EV_SUB(32);
				}
				if(abs(StoX(mpawn) - 0x4) == 4){
					MY_EV_SUB(32);
				}
		}
	}


	if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
		if(EV_MY_CAN == 0){
			if(StoY(mma) MY_LARGE_EQL MY_RANK6){
				MY_EV_SUB(EV_YOUR_CAN * 16);
				if(StoY(yche) == MY_RANK4){
					MY_EV_SUB(EV_YOUR_CAN * 16);
				}
			}
		}

		// fen 2bak4/4a4/4b4/P3R4/4N4/8p/2p1r4/9/4A4/2BK1AB2 w - - 0 1
		if (isStringByChe(POSITION, mche, mma, yche)){
			MY_EV_SUB(64);
			MY_EV_SUB(EV_YOUR_CAN * 16);
			if (StoY(mpawn) MY_LARGE_EQL MY_RANK3){
				MY_EV_SUB(32);
			}
		}

		// fen 3ak1b2/4a4/9/8R/6b2/1p3p2P/8r/B2N5/4A4/4KA3 w - - 0 1
		if (abs(StoX(mpawn) - 0x4) >= 4){
			MY_EV_SUB(32);
			if (StoY(mma) MY_LARGE_EQL MY_RANK7){
				MY_EV_SUB(32);				
			}
			if (Your_pawn_already_over_river(POSITION) >= 2){
				MY_EV_SUB(32);
			}
			
		}
	}

	if((your_shi_num + your_xiang_num) == 4 && MY_SQ04 == yk){
		if(mcan == 0 && StoY(yche) MY_SMALL_EQL MY_RANK3){
			if(PB90(MY_SQ07) == my_ma && PB90(MY_SQ06) == your_xiang){
				if(StoX(yche) == 0x6){
					MY_EV_SUB(196);
				}
			}
			if(PB90(MY_SQ01) == my_ma && PB90(MY_SQ02) == your_xiang){
				if(StoX(yche) == 0x2){
					MY_EV_SUB(196);
				}
			}
		}
	}
	
	// fen 3ak4/9/3ab4/9/p5p2/9/P5R2/B4AN2/6r2/3AK4 w - - 0 0
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
		if(mcan == 0 && isSma){
			MY_EV_SUB(ycan * 64);
		}
	}

	// fen 4kab2/4a1P2/4b4/2p6/4nr3/2P1R4/9/4BA3/4A4/4K1B2 b - - 48 48
	if(my_shi_num >= 1){
        if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
			if(StoY(mma) MY_LARGE_EQL MY_RANK5){
				if(PB90(MY_SQ26) == your_pawn && PB90(MY_SQ38) == my_pawn){
					RETRUN_MUL(4);
				}
				if(PB90(MY_SQ2A) == your_pawn && PB90(MY_SQ3C) == my_pawn){
					RETRUN_MUL(4);
				}
			}
		}
	}

	int yalr = Your_pawn_already_over_river(POSITION);
	// fen 4ka3/2NRa4/b8/p3p3p/2r6/9/6P2/B8/9/4K4 w - - 0 0
	if(yalr == 0){
		MY_EV_ADD((4 - your_shi_num - your_xiang_num) * 80);
	}

	// fen 2b1kab2/4a4/3P5/8p/R3N1p2/9/8r/9/3K5/9 b - - 0 1
	if(StoY(mpawn) MY_SMALL_EQL MY_RANK3 && StoY(mma) MY_SMALL_EQL MY_RANK4){
		if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK4])){
			MY_EV_ADD(64);
		}
	}

	// fen 3ak1b2/4a4/4b4/1N1R5/2r5p/2B6/8P/5A3/2p6/4KA3 b - - 0 1
	if(EV_MY_SAFE){
		if(EV_MY_CAN == 0){
			if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
				if(EV_YOUR_CAN >= 1){
					if(StoY(yche) == MY_RANK4){
						if(StoY(mpawn) == MY_RANK6 && PB90(mpawn MY_SUB 18) == your_pawn){
							RETRUN_MUL(8);
						}
					}
				}
			}
		}
	}

	// fen 3k1a3/3r2NR1/5a3/p8/2b6/8p/P8/4B4/5K3/2B2A3 w - - 0 1
	if(EV_MY_CAN == 0){
		if(EV_YOUR_CAN <= 1 && my_xiang_num >= 1){
			if(isSma){
				MY_EV_SUB(64);
				if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) MY_SMALL_EQL MY_RANK1){
					if(!IsOnSameSide(yk,mma)){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 3ak4/9/3ab1rNb/7P1/5R3/4pp3/9/9/4A4/4KA3 b - - 0 1
	if(my_shi_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			Bitboard lp = Your_get_connect_Pawn(POSITION);
			if(bit_is_set(lp,MY_SQ31) || bit_is_set(lp,MY_SQ3A)){
				MY_EV_SUB(64);
				if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
					if(IsOnSameSide(yche,mma)){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 4k1b2/4a4/3ab4/9/4r4/1p4P1p/7R1/3NBA3/9/4KAB2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
		if(EV_MY_CAN == 0 && StoY(mma) MY_LARGE_EQL MY_RANK6){
			if(count_1s(bb_your_pawn,MyUpBB[StoY(mma)]) == 2){
				if(my_shi_num == 2){
				   RETRUN_MUL(8);
				}
			}
		}
	}

}


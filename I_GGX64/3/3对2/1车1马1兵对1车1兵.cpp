#ifndef END_my_m_MT_R_1che1ma1pawn_B_1che1pawn
#define END_my_m_MT_R_1che1ma1pawn_B_1che1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1马1兵对1车1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1che1ma1pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square mma   = S90_from_piecelist(POSITION,my_ma,0);
	Square yk = your_king_pos;
	Square mche = S90_from_piecelist(POSITION,my_che,0);
	Square yche = S90_from_piecelist(POSITION,your_che,0);
	Square mk  = my_king_pos;

	if(my_shi_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		EV_MY_SAFE = TRUE;
	}
	if(StoY(ypawn) == MY_RANK9){
		EV_MY_SAFE = TRUE;
	}

	if(my_shi_num == 0 && my_xiang_num == 0 && EV_MY_CAN == 0){
		if((your_shi_num + your_xiang_num) >= 2 && StoY(yk) == MY_RANK0){
			MY_EV_SUB(64);
		}
	}

	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(yche) MY_SMALL_EQL MY_RANK4){
			MY_EV_SUB(96);
		}
	}
	//  fen 5a3/1R2a4/3kb3b/1Nr6/9/2P3B2/9/3A4B/5p3/4K4 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(mche) MY_SMALL_EQL MY_RANK2) {
		
		if (EV_MY_CAN == 0) {
			MY_EV_SUB(32);

			if (MY_SQ1C == mma && MY_SQ1D == yche) {
				MY_EV_SUB(64);
			}
			if (MY_SQ22 == mma && MY_SQ21 == yche) {
				MY_EV_SUB(64);
			}
		}
	}


	// fen 3a5/4ak3/1P2R3b/5N3/9/9/9/r4p3/4K4/9 w - - 0 1
	if (my_shi_num == 0 && my_xiang_num == 0){
		if ((your_shi_num + your_xiang_num) >= 3 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if (abs(StoX(mpawn) - 0x4) >= 2 && !IsOnSameSide(mpawn, yk)){
				MY_EV_SUB(32);				
			}
			if (abs(StoY(ypawn) - StoY(mk)) == 1 && StoY(ypawn) MY_SMALL StoY(mk)){
				MY_EV_SUB(32);
				if (abs(StoX(ypawn) - StoX(mk)) <= 1){
					MY_EV_SUB(32);
				}
			}
		}
	}

	//  fen 3ak1b2/1rNRa4/9/p8/9/P8/9/4B4/9/3A1KB2 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1 && EV_MY_CAN == 0 && StoY(yk) == MY_RANK0) {
		if (StoY(mpawn) MY_LARGE_EQL MY_RANK5) {
			if (MY_SQ0B == mma && MY_SQ0C == mche) {
				if (MY_SQ09 == yche || MY_SQ0A == yche) {
					if (PB90(MY_SQ05) != your_shi) {
						RETRUN_MUL(4);
					}
				}
			}
			if (MY_SQ0F == mma && MY_SQ0E == mche) {
				if (MY_SQ10 == yche || MY_SQ11 == yche) {
					if (PB90(MY_SQ03) != your_shi) {
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 4k4/4a4/4b4/p3r4/9/P8/9/7R1/4N4/3AKA3 b - - 0 1
	if((your_shi_num + your_xiang_num) >= 1){
		if(my_xiang_num == 0 && EV_MY_CAN == 0){
			if(MY_SQ55 == mk && MY_SQ4C == mma && PB90(MY_SQ54) == my_shi && PB90(MY_SQ56) == my_shi){
				if(isStringByChe(POSITION,yche,mma,mk)){
					if(StoY(ypawn) == StoY(yche)){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 4k1b2/4a4/4ra2b/9/4N3p/9/4R3P/3A1A3/9/4K4 w - - 0 1
	if(EV_MY_CAN == 0 && your_shi_num == 2 
		&& your_xiang_num == 2 && StoX(yk) == 0x4){
			if(StoX(mma) == 0x4 && StoY(mma) MY_SMALL_EQL MY_RANK6){
				if(StoY(mche) MY_LARGE StoY(yche)){
					if(StoX(mche) == StoX(yche) && StoX(mche) == 0x4){
						RETRUN_MUL(4);
					}
				}
			}
	}

	// fen 2bak4/4a4/4b4/9/PNr1p4/2BR5/9/5A3/9/2B1KA3 w - - 0 1
	if ((your_xiang_num + your_shi_num) == 4 && StoY(yk) == MY_RANK0) {
		if (StoY(ypawn) MY_SMALL_EQL MY_RANK4 && StoY(yche) == MY_RANK4) {
			if (MY_SQ24 == mpawn && MY_SQ25 == mma) {
				RETRUN_MUL(4);
			}
			if (MY_SQ2C == mpawn && MY_SQ2B == mma) {
				RETRUN_MUL(4);
			}
		}
	}

	

	// fen 2b1kab2/4a4/9/9/9/9/P2R5/3A5/4Ap3/r2NK4 w - - 13 13
	if((your_xiang_num + your_shi_num) >= 3 && StoY(yk) == MY_RANK0){
		if(StoY(ypawn) MY_LARGE_EQL MY_RANK5 && StoY(ypawn) MY_SMALL_EQL MY_RANK8){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
				if(PB90(XYtoS(StoX(yche),StoY(mche))) == my_pawn){
					if(StoY(mma) MY_LARGE_EQL MY_RANK8 && my_xiang_num == 0){
						if(isStringByChe(POSITION,yche,mma,mk)){
							RETRUN_MUL(8);
						}
					}
				}
			}
		}
	}
	// fen 2bak4/4a4/4b4/R8/P1r6/1p7/9/3N1A2B/4A4/4K1B2 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if(abs(StoX(mpawn) - 0x4) == 4 && StoX(mche) == StoX(mpawn) && StoY(mche) MY_SMALL StoY(mpawn)){
				if(StoY(yche) == StoY(mpawn)){
					MY_EV_SUB(64);
					if(StoY(mma) MY_LARGE_EQL MY_RANK5){
						MY_EV_SUB(64);
						if(StoY(ypawn) MY_SMALL_EQL StoY(mma)){
							MY_EV_SUB(32);
						}
						RETRUN_MUL(8);
					}
				}
			}

			// fen 4k1b2/4a4/3ab4/2rN5/9/3R2P2/9/4BA3/2p6/3AK1B2 b - - 0 1
			if (StoY(mpawn) MY_LARGE_EQL MY_RANK5 && abs(StoX(mpawn) - 0x4) == 2){
				RETRUN_MUL(8);
			}
		}
	}

	int yalr = Your_pawn_already_over_river(POSITION);
	// fen 4ka3/2NRa4/b8/p3p3p/2r6/9/6P2/B8/9/4K4 w - - 0 0
	if(yalr == 0){
		MY_EV_ADD((4 - your_shi_num - your_xiang_num) * 80);
	}
	
	//int ycan = EV_YOUR_CAN;
	int mcan = EV_MY_CAN;

	// fen 3ak4/9/3ab4/9/p5p2/9/P5R2/B4AN2/6r2/3AK4 w - - 0 0
	if((your_xiang_num + your_shi_num) >= 3 && StoY(yk) == MY_RANK0){
		if(mcan == 0 && isStringByChe(POSITION,mche,mma,yche)){
			RETRUN_MUL(8);
		}
	}

	// fen 9/9/4k4/p1r1p4/9/8R/Pn6P/4B4/4A4/3AK1B2 w - - 0 1
	// 黑方二个兵都在家里,要扣分
	//ymp = m_and(bb_your_pawn, MyUpBB[MY_RANK4]);
	//MY_EV_ADD(64 * count_1s(ymp));
	if(StoY(ypawn) MY_SMALL_EQL MY_RANK4){
		MY_EV_ADD(64);
	}

	// fen 3ak4/3Pa4/4b2r1/5R1N1/6b2/9/9/B8/4A1p2/3A1K3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(StoX(mpawn) < 0x4 && !have_bit(bb_your_shi,RightBB[0x4])){
				MY_EV_SUB(64);
				if(StoY(mma) MY_LARGE_EQL MY_RANK3){
					MY_EV_SUB(64);
				}
				if(StoX(yche) > 0x4){
					RETRUN_MUL(8);
				}
			}
			if(StoX(mpawn) > 0x4 && !have_bit(bb_your_shi,LeftBB[0x4])){
				MY_EV_SUB(64);
				if(StoY(mma) MY_LARGE_EQL MY_RANK3){
					MY_EV_SUB(64);
				}
				if(StoX(yche) < 0x4){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 2b2k3/4a4/5a3/R6Nr/2b6/8P/9/3A5/2p6/3K1A3 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
				if(isStringByChe(POSITION,mche,mma,yche)){
					MY_EV_SUB(32);
					if(bit_is_set(ei.attacked_by(your_che),mpawn)){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 4ka3/4aP3/1r2b4/1N1R5/2b6/2B6/9/B2A1A3/3K1p3/9 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if(StoX(mpawn) > 0x4 && PB90(MY_SQ05) == your_shi){
				RETRUN_MUL(8);
			}
			if(StoX(mpawn) < 0x4 && PB90(MY_SQ03) == your_shi){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3ak1b2/3Pa4/4b4/2N2R3/3r5/9/9/4B4/3pA4/3AK1B2 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if(StoX(mpawn) < 0x4 && !have_bit(bb_your_shi,RightBB[0x4])){
				RETRUN_MUL(8);
			}
			if(StoX(mpawn) > 0x4 && !have_bit(bb_your_shi,LeftBB[0x4])){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 2bak4/9/3ab4/9/6p2/2R5P/1n7/3AB4/4A3r/3K2B2 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if (!IsOnSameSide(mche, yk) && StoY(yche) == MY_RANK4){
			if (MY_SQ2F == mpawn && MY_SQ24 == ypawn){
				RETRUN_MUL(8);
			}
			if (MY_SQ33 == mpawn && MY_SQ2C == ypawn){
				RETRUN_MUL(8);
			}
		}
	}
		

	// fen 2b1k4/4a4/4b4/5N3/p8/9/P2R5/6r2/9/3K5 w - - 0 1
	if(my_shi_num == 0 && my_xiang_num == 0 && EV_MY_CAN == 0){
		if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
			RETRUN_MUL(12);
		}
	}



}


#ifndef END_my_m_MT_R_1che1ma1pawn_B_1che1ma
#define END_my_m_MT_R_1che1ma1pawn_B_1che1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1马1兵对1车1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int B2shi2xiang = 80;


//我方1车1马1兵，对方1车1马
void my_m_MT_R_1che1ma1pawn_B_1che1ma(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_CheMaPawn_CheMa_ByPawnByShi[your_shi_num]);
	
	int mcan = EV_MY_CAN;
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square yma   = S90_from_piecelist(POSITION,your_ma,0);
	Square mma   = S90_from_piecelist(POSITION,my_ma,0);
	Square yche  = S90_from_piecelist(POSITION,your_che,0);
	Square mche  = S90_from_piecelist(POSITION,my_che,0);

	// fen 2ba1k3/4a4/4b4/9/9/2N5P/P1n2r3/3A2R2/4K4/3A5 w - - 0 1
	if(my_shi_num == 2 || my_xiang_num == 2){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			MY_EV_ADD(EV_MY_CAN * 32);
			if(StoY(mche) MY_LARGE_EQL MY_RANK5){
				MY_EV_ADD(EV_MY_CAN * 16);
			}
		}
	}

	// fen 4k4/4a4/5n3/5N3/9/2B6/6r2/4BR3/4A1p2/4K4 b - - 0 1
	if (my_shi_num >= 1 && StoY(mk) == MY_RANK9){
		if (your_shi_num <= 1){
			if (abs(StoY(mpawn) - StoY(yk)) <= 1){
				MY_EV_ADD(48);
				if (abs(StoX(mpawn) - 0x4) <= 2){
					MY_EV_ADD(32);
				}
			}
		}
	}

	// fen 4kab2/1N2a4/R7n/3r5/9/2B5P/9/4BA3/9/3AK4 w - - 0 1
	if((your_shi_num + your_xiang_num) >= 3 && MY_SQ04 == yk){
		MY_EV_SUB(64);
	}

	if(my_shi_num == 2 || my_xiang_num == 2){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			EV_MY_SAFE = TRUE;
		}
	}

	// fen 2R6/3kaP3/4ba3/9/3r1N3/9/9/5An2/4K4/6B2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(!IsOnSameSide(yk,mpawn) && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			MY_EV_SUB(32);
			if(!IsOnSameSide(yk,mma)){
				MY_EV_SUB(16);
				if(!have_bit(FileBB_A[StoX(yk)],bb_your_shi)){
					MY_EV_SUB(32);
				}
			}
		}
	}

	if(my_shi_num >= 1 && mk == MY_SQ55){
		MY_EV_ADD(32);
	}

	if(my_shi_num == 2 || my_xiang_num == 2){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			MY_EV_ADD(32);
			if(!IsOnSameSide(mk,yma)){
				MY_EV_ADD(32);
			}
		}
	}

	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0 ){
		
		MY_EV_SUB(32);
		
		if(!bit_is_set(EV_MY_XBIT,yma)){
			if(mcan == 0){
				EV_YOUR_SAFE = TRUE;
			}
			// fen 4kab2/4a4/4br3/n8/9/2B6/4N1R1P/9/4A4/2BAK4 b - - 0 0
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK2){
				// fen 3ak4/9/5a3/4n4/5r3/4p1B2/7R1/8B/4AN3/3A1K3 w - - 0 1
				// 还要对方的马不是被牵制的
				EV_YOUR_SAFE = TRUE;			
			}
		}
	}

	if(my_shi_num == 2 || my_xiang_num == 2){
		if(StoY(mk) == MY_RANK9){
			EV_MY_SAFE = TRUE;
		}

		if(StoY(yma) MY_SMALL_EQL MY_RANK2){
			EV_MY_SAFE = TRUE;
		}
	}	
	// fen 9/4k2N1/5a3/4R4/9/p1n2r3/9/9/4A4/4KA3 b - - 0 86
	if((your_shi_num == 2 || your_xiang_num == 2) && StoY(yk) == MY_RANK0){
		if((my_shi_num + my_xiang_num) <= 1){
			MY_EV_SUB(64);
		}
	}

	// fen 4kab2/9/4ba3/9/2r6/P8/2NR4P/3A5/3KA4/7n1 w - - 0 1
	if (EV_MY_SAFE) {
		MY_EV_ADD(64);
		MY_EV_ADD(EV_MY_CAN * 32);
	}



	if((my_shi_num == 2 || my_shi_num == 2) && StoY(yma) MY_SMALL_EQL MY_RANK4){
		MY_EV_ADD(32);
	}

	// fen 3ak4/9/3ar4/9/6n2/2R1P1B2/9/B4N3/4A4/4KA3 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 || your_xiang_num == 2){
			if(StoY(yk) MY_SMALL_EQL MY_RANK1){
				if(MY_SQ31 == mpawn && bit_is_set(ei.attacked_by(your_ma), mpawn)){
					if(bit_is_set(ei.attacked_by(your_che),mpawn) && StoY(mma) MY_LARGE_EQL MY_RANK5){
						RETRUN_MUL(2);
					}
				}
			}
		}
	}

	// fen 2ba1k3/9/3ab4/9/5r3/9/2R6/5N3/1pn1AK3/3A2B2 w - - 120 120
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(IsOnSameSide(yma,yk) && IsOnSameSide(mma,mpawn) && !IsOnSameSide(yma,mma)){
			if(PB90(MY_SQ0D) == your_shi && StoY(mpawn) MY_SMALL_EQL MY_RANK1 
				&& abs(StoX(mpawn) - 0x4) >= 3){
					if(PB90(MY_SQ15) == your_ma && PB90(MY_SQ02) == your_xiang){
						RETRUN_MUL(4);
					}
					if(PB90(MY_SQ17) == your_ma && PB90(MY_SQ06) == your_xiang){
						RETRUN_MUL(4);
					}
			}
		}
	}



	// fen 2b1k4/1R2a4/1n5r1/1N2P4/9/2B6/9/4BA3/9/4KA3 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num >= 1 && MY_SQ04 == yk){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3  && StoY(yche) == MY_RANK2){
			if(StoY(mma) MY_LARGE_EQL MY_RANK3 && StoY(mche) MY_SMALL_EQL MY_RANK1){
				if(StoX(mche) < 0x4 && PB90(MY_SQ02) == your_xiang && MY_SQ13 == yma){
					RETRUN_MUL(4);
				}
				if(StoX(mche) > 0x4 && PB90(MY_SQ06) == your_xiang && MY_SQ19 == yma){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 4ka3/4a4/3n5/4r4/8R/2B1P4/9/4BN3/9/3AKA3 w - - 0 1
    if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if(MY_SQ31 == mpawn && StoX(yche) == 0x4 && StoY(yche) MY_SMALL_EQL MY_RANK3){
			if(MY_SQ15 == yma || MY_SQ17 == yma){
				RETRUN_MUL(4);
			}
		}
	}
	
	
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		// fen 2b1ka3/4a4/3n5/9/4p1b2/3r5/4R4/4BN3/4A4/3AK4 w - - 46 46
		if(PB90(MY_SQ31) == my_pawn && PB90(MY_SQ1F) == your_che){
			if(PB90(MY_SQ17) == your_ma || PB90(MY_SQ15) == your_ma){
				RETRUN_MUL(4);
			}
		}
		// fen 2b1k4/4a4/4ba3/9/9/1p3r3/1nR6/5N3/4A4/2B1KA3 w - - 230 230
		if(PB90(mma MY_ADD 9) == my_pawn){
			if(PB90(MY_SQ1C) == my_ma && PB90(MY_SQ1D) == your_che){
				RETRUN_MUL(4);
			}
			if(PB90(MY_SQ22) == my_ma && PB90(MY_SQ21) == your_che){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3k5/4aP3/3ab3b/9/6n2/9/r2NR4/9/9/3AK4 b - - 0 149
	if(mcan >= 1 && my_shi_num >= 1 && StoY(mk) == MY_RANK9){
		if(StoY(yma) MY_SMALL_EQL MY_RANK4){
			MY_EV_ADD(32);
		}
	}
    // fen 3ak4/9/5a3/4n4/5r3/4p1B2/7R1/8B/4AN3/3A1K3 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
				RETRUN_MUL(4);
			}
		}
	}


	

	// fen 9/4k4/5R3/9/9/9/9/3r1p3/4A4/4K4 w - - 0 1
	if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){

		// fen 3ak4/9/4b4/4r4/R5n2/6N2/8P/4BA3/4A4/4K1B2 b - - 0 1
		if(EV_MY_SAFE && StoY(mma) MY_LARGE_EQL MY_RANK5){
			if(StoY(yche) == MY_RANK3 && PB90(MY_SQ16) == your_xiang){
				if(PB90(MY_SQ3E) == my_pawn && PB90(MY_SQ2A) == your_ma){
					RETRUN_MUL(4);
				}
				if(PB90(MY_SQ36) == my_pawn && PB90(MY_SQ26) == your_ma){
					RETRUN_MUL(4);
				}
			}
		}

		if(StoY(mma) MY_LARGE_EQL MY_RANK4){
			if(PB90(MY_SQ26) == your_ma && PB90(MY_SQ36) == my_pawn){
				RETRUN_MUL(8);
			}
			if(PB90(MY_SQ2A) == your_ma && PB90(MY_SQ3E) == my_pawn){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4kab2/4a4/4b4/5R3/6rNP/9/9/9/2n1AK3/3A5 b - - 0 1
	if(EV_YOUR_SAFE){
		if(my_shi_num == 2 && StoY(mk) MY_SMALL_EQL MY_RANK8){
			if(!IsOnSameSide(mk,yma)){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4kab2/1N2a4/R7n/3r5/9/2B5P/9/4BA3/9/3AK4 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num >= 1 && MY_SQ04 == yk){
			if(!have_bit(MyUpBB[MY_RANK5],bb_my_pawn)){
				if(MY_SQ0A == mma && StoX(yche) == 0x3){
					RETRUN_MUL(8);
				}
				if(MY_SQ10 == mma && StoX(yche) == 0x5){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 2b1kab2/9/5a3/9/4P4/9/9/5N1R1/1r2A3n/4K4 r
	if(EV_YOUR_SAFE){
		if(my_shi_num >= 1 && MY_SQ55 == mk){
			if(StoY(mpawn) == MY_RANK3 || StoY(mpawn) == MY_RANK4){
				if(abs(StoX(yma) - 0x4) == 0x4){
					RETRUN_MUL(8);
				}
			}
		}
	}

	

	// fen 4k1b2/4a4/9/9/P1b6/3rn4/4R4/3NB4/4A4/2B1KA3 b - - 0 1
	if(EV_MY_SAFE){
		if(your_xiang_num == 2 && your_shi_num >= 1 && MY_SQ04 == yk){
			if(StoY(mpawn) MY_SMALL_EQL MY_RANK4){
				RETRUN_MUL(8);
			}
			if(abs(StoX(mpawn) - 0x4) >= 3){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 2bk5/4a4/3a4b/5P3/5n3/9/7R1/9/4A1rN1/4K4 b - - 0 1
	if(EV_YOUR_SAFE){
		if(my_shi_num >= 1 && MY_SQ55 == mk){
			if(StoY(mpawn) == MY_RANK3 && StoY(mma) MY_LARGE_EQL MY_RANK5){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4ka3/4a4/9/9/4nr3/2B5P/6R2/4B4/2N1A4/4KA3 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK5 && abs(StoX(mpawn) - 0x4) == 4){
				if(StoY(mma) MY_LARGE_EQL MY_RANK5){
                  if(!isStringByChe(POSITION,mche,yma,yche)){
					  RETRUN_MUL(8);
				  }
				}
			}
		}
	}

	// fen 5a3/3ka4/3rNn3/4P4/5R3/9/9/3A5/4A4/4K4 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && PB90(MY_SQ16) == my_ma && PB90(MY_SQ1F) == my_pawn){
			if(PB90(MY_SQ15) == your_che && PB90(MY_SQ17) == your_ma && StoX(yk) <= 0x4){
				RETRUN_MUL(8);
			}
			if(PB90(MY_SQ17) == your_che && PB90(MY_SQ15) == your_ma && StoX(yk) >= 0x4){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3ak4/4a4/9/8R/6b1P/4nrN2/9/4B4/4A4/2B1KA3 w - - 0 1
	if(EV_MY_SAFE){
		if((your_shi_num + your_xiang_num) >= 3 && MY_SQ04 == yk){
			if(StoY(mk) MY_LARGE_EQL MY_RANK3){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 2b1k4/1R2a4/1n5r1/1N2P4/9/2B6/9/4BA3/9/4KA3 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num >= 1 && your_xiang_num >= 1 && MY_SQ04 == yk){
			if(StoY(yche) == MY_RANK2 && StoY(mpawn) MY_LARGE_EQL MY_RANK3 && StoY(mche) MY_SMALL_EQL MY_RANK1){
				if(PB90(MY_SQ13) == your_ma && StoX(mche) <= 0x2 && PB90(MY_SQ02) == your_xiang){
					RETRUN_MUL(8);
				}
				if(PB90(MY_SQ19) == your_ma && StoX(mche) >= 0x6 && PB90(MY_SQ06) == your_xiang){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 3ak4/4a4/9/8R/6b1P/4nrN2/9/4B4/4A4/2B1KA3 w - - 0 1
	if(EV_MY_SAFE){
		if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
			if(StoY(mma) MY_LARGE_EQL MY_RANK5){
				if(StoY(mpawn) MY_LARGE_EQL MY_RANK4 || abs(StoX(mpawn) - 0x4) == 4){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 3a1k3/4a4/9/5r1N1/P2n2b2/7R1/9/9/4A4/2B1KA3 b - - 0 1
	if(EV_MY_SAFE){
		if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
			 if(StoY(mpawn) MY_LARGE_EQL MY_RANK4 || abs(StoX(mpawn) - 0x4) == 4){
				 RETRUN_MUL(8);
			 } 
		}
	}

	// fen 9/3k1P3/b2a1a3/9/2bRnN3/4r4/9/B7B/4A4/3K1A3 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && !IsOnSameSide(mpawn,yk)){
				if(!IsOnSameSide(mma,yk)){
					RETRUN_MUL(8);
				}
			}
		}
	}



	// fen 3ak4/4a4/2r6/9/P5R2/3N2n2/9/9/4A4/3AK4 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK3 || abs(StoX(mpawn) - 0x4) >= 3){
				RETRUN_MUL(12);
			}
		}
	}
}


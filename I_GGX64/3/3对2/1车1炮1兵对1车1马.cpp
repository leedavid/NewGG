#ifndef END_my_m_MT_R_1che1pao1pawn_B_1che1ma
#define END_my_m_MT_R_1che1pao1pawn_B_1che1ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1炮1兵对1车1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

// fen 4kab2/4a4/8b/1r1CP4/8n/6B2/5R3/9/4A4/2BAK4 w - - 0 1
void my_m_MT_R_1che1pao1pawn_B_1che1ma(typePOS &POSITION, EvalInfo &ei){


	if((my_shi_num + my_xiang_num) == 0){
		MY_EV_SUB(32);
	}

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_ChePaoPawn_CheMa_ByPawnByShi[your_shi_num]);

	Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	Square yma  = S90_from_piecelist(POSITION,your_ma,0);
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square mk    = my_king_pos;

	// fen 4ka3/n3aP3/4b3b/3R5/9/4r4/9/4C4/4A4/3K1AB2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(StoX(mpawn) > 0x4 && !have_bit(bb_your_shi,LeftBB[0x4])){
				MY_EV_SUB(64);
			}
			if(StoX(mpawn) < 0x4 && !have_bit(bb_your_shi,RightBB[0x4])){
				MY_EV_SUB(64);
			}
		}
	}

	// fen 3nka2r/4a4/4bR3/9/4C4/4P4/9/4B4/4A4/3A1KB2 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num >= 1 && MY_SQ04 == yk){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
				MY_EV_SUB(64);
			}
		}
	}

	if(my_shi_num <= 1 && StoY(yma) MY_LARGE_EQL MY_RANK5){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK4 && your_shi_num == 2){
			MY_EV_SUB(64);
		}
	}

	// fen 2b1k4/4a4/b8/2P6/9/4R4/9/5C3/2n1AK3/7r1 b - - 0 1
	if(my_shi_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(StoY(mpao) MY_LARGE_EQL MY_RANK7){
			MY_EV_ADD(64);
		}
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	// fen 3k1ab2/4a4/4b4/C3R4/1r7/P8/8P/3A5/3KA1n2/9 b - - 0 1
	if(my_shi_num == 2 || my_xiang_num == 2){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			MY_EV_ADD(EV_MY_CAN * 16);
			if(!IsOnSameSide(yma,mk)){
				MY_EV_ADD(EV_MY_CAN * 16);
			}
		}
	}

	// fen 4k4/2R1a1P2/4b3b/9/3rn4/9/9/9/4A3C/4K4 w - - 0 1
	if(my_shi_num >= 1 && MY_SQ55 == mk){
		if(your_shi_num <= 1 && StoY(mpawn) == MY_RANK1){
			MY_EV_ADD(64);
		}
	}

	//Square yma = S90_from_piecelist(POSITION,your_ma,0);
	if((my_shi_num + my_xiang_num) <= 1 && StoY(yma) MY_LARGE_EQL MY_RANK4){
		MY_EV_SUB(32);
	}

	// fen 9/4k2N1/5a3/4R4/9/p1n2r3/9/9/4A4/4KA3 b - - 0 86
	if((your_shi_num == 2 || your_xiang_num == 2) && StoY(yk) == MY_RANK0){
		if((my_shi_num + my_xiang_num) <= 2){
			MY_EV_SUB(16);
			if((my_shi_num + my_xiang_num) <= 1){
			   MY_EV_SUB(32);
			}
		}
	}
	// fen 3ak4/R1P1a4/4b3b/9/9/9/1r7/2nAB4/4A4/2C1K1B2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
		if(StoY(mpao) MY_LARGE_EQL MY_RANK8 && StoY(yma) MY_LARGE_EQL MY_RANK2){
			MY_EV_SUB(96);
		}
	}


	
	//如果车马方是仕相全,则也难胜
	if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		EV_MY_SAFE = TRUE;
	}
	
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
			EV_YOUR_SAFE = TRUE;
		}
	}
	Square mche = S90_from_piecelist(POSITION,my_che,0);
	Square yche = S90_from_piecelist(POSITION,your_che,0);
	//Square mpao = S90_from_piecelist(POSITION,my_pao,0);

	if(my_xiang_num == 2 && my_shi_num == 0){
		if(StoX(mche) == StoX(mk)){
			MY_EV_ADD(16);
		}
	}

	// fen 3ak4/3Pa4/4b4/5R3/9/n3r4/9/7C1/4A4/5K3 b - - 0 1
	if(my_shi_num >= 1 && StoY(mk) == MY_RANK9){
		if(EV_MY_CAN >= 1){
			MY_EV_ADD(32);
		}
	}

	// fen 3ak1b2/9/4ba3/3R5/3c5/3r5/9/3N1A3/3K1p3/3A5 b - - 0 0
	if(your_shi_num == 2 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
		if(PB90(MY_SQ0E) == your_king && StoX(mpawn) < 0x4 && StoY(mpao) MY_SMALL_EQL MY_RANK6){
			if(PB90(MY_SQ17) == your_ma 
				&& StoX(mche) == 0x5 && StoX(mpao) == 0x5 && StoX(yche) == 0x5){
					if(StoY(mche) MY_LARGE MY_RANK3 && StoY(mpao) MY_LARGE StoY(mche)
						&& StoY(yche) MY_LARGE StoY(mpao)){
							RETRUN_MUL(4);
					}
			}		
		}
		if(PB90(MY_SQ0C) == your_king && StoX(mpawn) > 0x4 && StoY(mpao) MY_SMALL_EQL MY_RANK6){
			if(PB90(MY_SQ15) == your_ma 
				&& StoX(mche) == 0x3 && StoX(mpao) == 0x3 && StoX(yche) == 0x3){
					if(StoY(mche) MY_LARGE MY_RANK3 && StoY(mpao) MY_LARGE StoY(mche)
						&& StoY(yche) MY_LARGE StoY(mpao)){
							RETRUN_MUL(4);
					}
			}		
		}
	}

	// fen 3k2b2/1P2a4/4ba3/4r4/9/9/9/4n4/3CR4/4K4 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(my_shi_num == 0 && my_xiang_num == 0){
			if(PB90(MY_SQ4C) == my_che && PB90(MY_SQ43) == your_ma && isStringByChe(POSITION,mche,yma,yche)){
				MY_EV_ADD(96);
				if(MY_SQ55 == mk && StoY(mpao) == MY_RANK8){
					RETRUN_MUL(4);
				}
			}
		}
	}



	// fen 9/5k3/3ab3b/9/5N3/6B2/9/2p2A3/2cRAK3/4r4 b - - 120 120
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK2){
				RETRUN_MUL(4);
			}
            // fen 4ka3/n3aP3/4b3b/3R5/9/4r4/9/4C4/4A4/3K1AB2 b - - 0 1
			if(StoX(mpawn) > 0x4 && !have_bit(bb_your_shi,LeftBB[0x4])){
				RETRUN_MUL(6);
			}
			if(StoX(mpawn) < 0x4 && !have_bit(bb_your_shi,RightBB[0x4])){
				RETRUN_MUL(6);
			}
			RETRUN_MUL(8);
		}

		// fen 4k1b2/4a4/4b4/4r4/1n7/6P2/6R2/4C3B/4A4/3AK1B2 b - - 0 1
		if (your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk) == MY_RANK0){
			if (StoY(mpawn) MY_LARGE_EQL MY_RANK5){
				MY_EV_SUB(32);
				if (EV_MY_CAN == 0 && StoY(yche) MY_SMALL_EQL MY_RANK4){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 9/5k3/3ab3b/9/5N3/6B2/9/2p2A3/2cRAK3/4r4 b - - 120 120
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK1){
		if(StoY(mche) == MY_RANK0 && IsOnSameSide(yche,yk) == FALSE){
			if(StoY(yche) == MY_RANK1 && StoY(yche) == StoY(mpao) && PB90(mpao MY_ADD 9) == my_pawn){
				if(StoX(mpao) < StoX(yche) && StoX(yche) < StoX(yk)){
					RETRUN_MUL(8);
				}
				if(StoX(mpao) > StoX(yche) && StoX(yche) > StoX(yk)){
					RETRUN_MUL(8);
				}
			}
		}
	}

	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			if(my_shi_num == 2 || my_xiang_num == 2){
				if(StoY(mk) MY_LARGE_EQL MY_RANK8){
					RETRUN_MUL(8);
				}
			}
		}
	} //2b1ka3/4a4/2n1b4/8p/7n1/p1P3N2/1R2P1r1P/3CB1N2/c3A4/2BAK4 b - - 0 31

	// fen 4k1b2/9/4b4/5R3/9/6P2/3r1n3/5C2B/4A4/3AK1B2 b - - 0 1
	if (EV_MY_SAFE){
		if (your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1 && StoY(mche) != MY_RANK6){
			if (PB90(MY_SQ33) == my_pawn && MY_SQ3B == yma){
				RETRUN_MUL(8);
			}
			if (PB90(MY_SQ2F) == my_pawn && MY_SQ39 == yma){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3k1a3/4a4/2P6/4R4/3r5/9/7n1/5A3/4K2C1/9 b - - 0 66
	if((my_shi_num + my_xiang_num) >= 1){
		if(EV_MY_CAN >= 1){
			if(your_xiang_num == 0 && your_shi_num == 2){
				MY_EV_ADD(96);
			}
		}
	}

	// fen 3k5/4a4/1c7/9/4R3N/9/3r5/4B4/4Ap3/4KA3 w - - 0 1
    if(my_shi_num >= 1){
		if(StoY(yk) == MY_RANK0 && StoX(mche) == StoX(mk)){
			if(PB90(MY_SQ0C) == my_pawn && StoX(mche) == 0x5){
				MY_EV_ADD(64);
			}
			if(PB90(MY_SQ0E) == my_pawn && StoX(mche) == 0x3){
				MY_EV_ADD(64);
			}
		}
	}

	// fen 3R5/4k4/4rc3/9/5N3/9/7p1/9/9/3K5 b - - 0 1
    if(your_shi_num == 0 && your_xiang_num == 0 && EV_MY_CAN >= 1){
		MY_EV_ADD(64);
		if(StoX(mche) == 0x4 && StoY(mche) MY_SMALL StoY(mk)){
			MY_EV_ADD(64);
		}
	}

	// fen 4k4/3Pa4/3a5/9/9/9/2rn5/3R5/C8/3K5 b - - 0 1
	if(EV_MY_CAN >= 1 && your_xiang_num == 0){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8 && StoY(mche) == MY_RANK7){
			if(StoY(yma) MY_SMALL_EQL MY_RANK6){
				MY_EV_ADD(64);
			}
			if(StoY(mpao) MY_LARGE_EQL MY_RANK7){
				MY_EV_ADD(64);
			}
		}
	}

	// fen 1R1ak4/8P/3an4/6r2/6b2/9/9/5A3/4A4/4CKB2 w - - 0 1
    if(EV_MY_SAFE){
		if((your_shi_num + your_xiang_num) >= 3){
			if(MY_SQ04 == yk && abs(StoX(mpawn) - 0x4) >= 3){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 5k2C/4a1R2/3a5/3P5/9/9/2r6/8n/4A4/4KA3 w - - 0 1
   if(my_xiang_num == 0 && StoY(mk) MY_LARGE_EQL MY_RANK8 && my_shi_num == 2){
	   if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		   if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			   if(!IsOnSameSide(yk,mpawn) && StoY(yma) MY_LARGE_EQL MY_RANK3){
				    RETRUN_MUL(8);
			   }
		   }
	   }
   }

   // fen C2k1a3/4a1P2/4b4/4n4/r8/1R7/9/9/4A4/3AK4 w - - 0 1
   if(my_shi_num == 2 || my_xiang_num == 2){
	   if(StoY(mk) == MY_RANK9){
		   if(your_shi_num == 2 && your_xiang_num >= 1 && !IsOnSameSide(mpawn,yk)){
			   if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && abs(StoY(yma) - MY_RANK2) <= 1){
				   RETRUN_MUL(8);
			   }
		   }
	   }
   }

   // fen 2baka3/5P3/9/9/6b2/9/1R7/1nCK1A3/1r2A4/9 w - - 0 1
   if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
	   if(my_shi_num == 2 && StoY(mk) MY_SMALL_EQL MY_RANK8 && IsOnSameSide(mk,yma)){
		   if(StoY(yma) == MY_RANK7 && IsOnSameSide(mpao,yma)){
			   RETRUN_MUL(8);
		   }
	   }
   }

   // fen 3nka2r/4a4/4bR3/9/4C4/4P4/9/4B4/4A4/3A1KB2 b - - 0 1
   if(EV_MY_SAFE){
	   if(your_shi_num == 2 && your_xiang_num >= 1 && MY_SQ04 == yk){
		   if(PB90(MY_SQ16) == your_xiang && StoY(mpawn) MY_LARGE_EQL MY_RANK5){
		       if(PB90(MY_SQ03) == your_ma || PB90(MY_SQ05) == your_ma){
				   RETRUN_MUL(8);
			   }
		   }
	   }
   }

   // fen 2b1ka1rC/4aP2R/4b4/3n5/9/9/9/9/9/3K1AB2 b - - 0 1
   if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
	   if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && StoY(yma) MY_SMALL_EQL MY_RANK3){
		   if(MY_SQ08 == mpao && MY_SQ07 == yche){
			   if(StoX(mpawn) > 0x4 && StoX(mpawn) < 0x7){
				   RETRUN_MUL(8);
			   }
		   }
		   if(MY_SQ00== mpao && MY_SQ01 == yche){
			   if(StoX(mpawn) > 0x1 && StoX(mpawn) < 0x4){
				   RETRUN_MUL(8);
			   }
		   }
	   }
   }

   // fen 2R2a3/3ka2P1/9/9/9/1r7/6n2/3C5/4A4/4KAB2 w - - 0 1
   if(EV_MY_SAFE){
	   if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		   if(!IsOnSameSide(yk,mpawn) && abs(StoX(mpawn) - StoX(yk)) >= 2){
			   if((my_shi_num + my_xiang_num) <= 3 && !bit_is_set(EV_MY_XBIT,yma)){
				   RETRUN_MUL(12);
			   }
		   }
	   }
   }

   // fen 3ak4/3Pa4/4b4/9/2b3n2/r8/4R4/1C7/4A4/3AK4 b - - 0 1
   if(your_shi_num == 2 && your_xiang_num == 2 && yk == MY_SQ04){
	   if((my_shi_num == 2 || my_xiang_num == 2) && StoY(mk) MY_LARGE_EQL MY_RANK8){
		   RETRUN_MUL(12);
	   }
   }

   // fen 4ka3/4a2P1/9/4n4/9/2R6/6r2/3AB4/4A4/2B1K1C2 b - - 0 1
   if(EV_MY_SAFE){
	   if(your_shi_num == 2 && abs(StoX(mpawn) - 0x4) >= 3 && StoY(yk) == MY_RANK0){
		   if(!IsOnSameSide(mpawn,yk) && abs(StoY(yma) - MY_RANK4) <= 2){
			   RETRUN_MUL(12);
		   }
	   }
   }

}


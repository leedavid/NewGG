#ifndef END_my_m_MT_R_1che1ma1pawn_B_1che1pao
#define END_my_m_MT_R_1che1ma1pawn_B_1che1pao
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1马1兵对1车1炮.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



//车马1兵对车炮
// fen 4kab2/4a4/4b4/2rC3R1/2n6/9/3p5/B8/4A4/2BAK4 b - - 0 0
// fen 2ck1ab2/9/b2a5/2R3PN1/9/9/9/9/4K4/3A2r2 w - - 180 180

void my_m_MT_R_1che1ma1pawn_B_1che1pao(typePOS &POSITION, EvalInfo &ei){
	
	// ADD_MY
	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_CheMaPawn_ChePao_ByPawnByShi[your_shi_num]);

	Square mpawn  = S90_from_piecelist(POSITION,my_pawn,0);
	Square ypao   = S90_from_piecelist(POSITION,your_pao,0);
	Square yche   = S90_from_piecelist(POSITION,your_che,0);
	Square mche   = S90_from_piecelist(POSITION,my_che,0);
	Square mma    = S90_from_piecelist(POSITION,my_ma,0);
	if(my_shi_num == 0 && my_xiang_num == 0){
		MY_EV_SUB(32 * your_shi_num);
	}

	if(StoY(mpawn) MY_LARGE_EQL MY_RANK1){
		MY_EV_ADD(32);
	}

	bool isPaoStr = isStringByChe(POSITION, yche, ypao, mche);

	// fen 2b1ka3/4a4/4b4/9/3P5/1N1R5/8r/5K3/4A4/3A2c2 b - - 0 1
	if(my_shi_num == 2 || my_xiang_num == 2){
		if(StoY(mpawn) == MY_RANK4 || StoY(mpawn) == MY_RANK3){
			MY_EV_ADD(32);
			if(StoY(mma) MY_SMALL_EQL MY_RANK5){
				MY_EV_ADD(32);
			}
		}
	}

	// fen 4ka3/4a4/b2c4b/7r1/9/6BN1/4R3P/9/4A4/3AK1B2 w - - 0 1
	if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		MY_EV_ADD(32);
		MY_EV_ADD(EV_MY_CAN * 32);
	}


	// fen 4ka3/1N2a4/9/7c1/9/P8/3r5/4B3B/2R1A4/3AK4 w - - 0 1
	if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if(abs(StoX(mpawn) - 0x4) >= 3){
			MY_EV_SUB(64);
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK4){
				MY_EV_SUB(32);
			}
		}
	}

	// fen 2b1ka3/4a4/4b4/9/3P5/1N1R5/8r/5K3/4A4/3A2c2 b - - 0 1
	if(StoY(ypao) MY_LARGE_EQL MY_RANK5){
		MY_EV_ADD(32);
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK4){
			MY_EV_ADD(32);
		}
	}

	if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		EV_MY_SAFE = TRUE;
	}
	// fen 2b1ka3/4a4/1cr6/1N2R4/5P3/9/9/9/4K4/3A5 w - - 0 1
	if((my_shi_num + my_xiang_num) >= 1 && StoY(mpawn) MY_SMALL_EQL MY_RANK4 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		MY_EV_ADD(16);
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3 && abs(StoY(mma) - MY_RANK3) <= 2){
			MY_EV_ADD(32);
		}
	}

	// fen 2Rc2b2/4akN2/3a5/7P1/9/9/9/4B4/3r5/2B1KA3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		MY_EV_SUB(16);
		if(StoY(ypao) MY_SMALL_EQL MY_RANK2){
			MY_EV_SUB(32);
			if((my_shi_num + my_xiang_num) <= 3){
				MY_EV_SUB(32);
			}
		}
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			MY_EV_SUB(32);
		}
	}

	//if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0 && StoY(mpawn) MY_LARGE_EQL MY_RANK3){
	//	MY_EV_SUB(64);
	//}

	// fen 2b6/4a4/bPNk1a3/3c5/3R5/9/9/9/9/2r2K3 w - - 120 120
	if(StoY(yk) MY_LARGE_EQL MY_RANK2){
		MY_EV_ADD(64);
	}
	// fen 2b1ck3/4a4/4ba1N1/9/3r5/2P6/9/4B4/4A4/2B1K1R2 w - - 0 1
	if(my_shi_num >= 1 && my_xiang_num == 2){
		MY_EV_ADD(32);
	}


	// fen 3ak4/3ca2r1/4b3P/6RN1/9/9/9/4B4/4A4/4KAB2 b - - 0 1
	if((your_xiang_num + your_shi_num) >= 3 && MY_SQ04 == yk){
		MY_EV_SUB(64);
	}
	// fen 3ck1b2/4a4/4ba3/3PR4/9/r8/9/3N5/4A4/3K1A3 r
	if(my_shi_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(StoY(mpawn) == MY_RANK3){
			MY_EV_ADD(64);
			if(PB90(MY_SQ42) == my_ma || PB90(MY_SQ44) == my_ma){
				MY_EV_ADD(64);
			}
		}
	}



	// fen 3ak4/3ca2r1/4b3P/6RN1/9/9/9/4B4/4A4/4KAB2 b - - 0 1
	if(EV_MY_SAFE){
		if((your_xiang_num + your_shi_num) >= 3 && MY_SQ04 == yk){
			if(abs(StoX(mpawn) - 0x4) == 4){
				if(StoY(ypao) MY_SMALL_EQL MY_RANK2 && StoY(yche) MY_SMALL_EQL MY_RANK4){
					RETRUN_MUL(6);
				}
			}
		}
	}

	// fen 4ka3/1N2a4/9/7c1/9/P8/3r5/4B3B/2R1A4/3AK4 w - - 0 1
	if (your_shi_num == 2 && StoY(yk) == MY_RANK0 && !isPaoStr){
		if(abs(StoX(mpawn) - 0x4) >= 3 || StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			if((my_shi_num + my_xiang_num) >= 3){		
				RETRUN_MUL(6);
			}
		}
	}

	// fen 2ba5/4kcR2/bN1r1a3/1P7/9/9/9/3AB4/4A4/3K2B2 w - - 0 1
	if (EV_MY_SAFE && !isPaoStr){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK3 && abs(StoX(mma) - 0x4) >= 3){
				if(IsOnSameSide(mma,yche)){
					RETRUN_MUL(6);
				}
				RETRUN_MUL(8);
			}
		}
	}
	

	// fen 3ak1b2/4a4/4br3/6R2/3N3c1/9/4P4/4B4/9/3AKAB2 w - - 7 7
	//Square bk = PieceListStart(board,BKING);
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(StoY(yk) == MY_RANK0){
			
			MY_EV_SUB(32);
			if((my_shi_num + my_xiang_num) >= 2){
				RETRUN_MUL(8);
			}
		}
	}
	// fen 4R4/5k3/4b4/2n6/7r1/9/9/p2A5/4A4/3KC1B2 b - - 0 1
	if(my_shi_num == 0 && my_xiang_num <= 1 && your_shi_num == 2){
		if(StoX(yche) == 0x4 && StoY(ypao) MY_SMALL_EQL MY_RANK2){
			MY_EV_SUB(64);
		}
	}

	// fen 3a1kb2/4acN2/9/4PR3/9/9/4r4/9/3K5/9 b - - 0 1
	if(my_shi_num == 0 && my_xiang_num == 0 && StoY(mpawn) == MY_RANK3){
		if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoY(ypao) MY_SMALL_EQL MY_RANK2){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 2b1ka3/5c3/br7/4P4/3R5/4N4/9/4B4/4A4/4KAB2 w - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(ypao) MY_SMALL_EQL MY_RANK2 && StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			RETRUN_MUL(8);
		}
	}

	// fen 5k3/4a4/5ac2/3P1r3/8R/2N6/9/4BA3/9/4KAB2 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK1){
				if(!isStringByChe(POSITION,yche,ypao,mche)){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 2Pak4/4a4/5c3/9/5R1r1/9/9/5N3/4A4/3A1K3 w - - 0 1
	if(StoY(mpawn) == MY_RANK0 && your_shi_num == 2){
		if(my_shi_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			if(StoY(mche) MY_SMALL_EQL MY_RANK6){
			   if(PB90(MY_SQ44) == my_ma || PB90(MY_SQ42) == my_ma){
				   RETRUN_MUL(8);
			   }
			}
		}
	}

	// fen 3ak1b2/9/1r3a3/1NP2R3/2b6/9/9/9/9/c4K3 w - - 0 1
	if((my_shi_num + my_xiang_num) <= 1){
		if(StoY(mpawn) == MY_RANK3 && StoY(mma) == MY_RANK3 && abs(StoX(mpawn) - 0x4) <= 2){
			if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) MY_SMALL_EQL MY_RANK1){
				RETRUN_MUL(8);
			}
		}
	}


	// fen 3ak1b2/3ca4/9/3P5/2r6/4N1B2/1R7/4B4/4A4/4K4 b - - 0 1
	if((your_shi_num + your_xiang_num) >= 3){
		if(StoY(yk) == MY_RANK0 && StoY(ypao) MY_SMALL_EQL MY_RANK2){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
				MY_EV_SUB(96);
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3a5/2P1a4/b2kc4/9/9/9/3r5/4B4/4N4/R2AKAB2 b - - 0 1
	if(PB90(MY_SQ4C) == my_ma && PB90(MY_SQ43) == my_xiang){
		if(StoY(mpawn) == MY_RANK1 && IsOnSameSide(yk,mpawn) && StoY(yk) == MY_RANK2){
			if(my_shi_num == 2 && my_xiang_num >= 1 && StoX(ypao) == 0x4 && your_xiang_num <= 1){
				if(StoX(yk) <= 0x3 && StoX(mche) <= 0x3){
					RETRUN_MUL(8);
				}
				if(StoX(yk) >= 0x5 && StoX(mche) >= 0x5){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 2b1ka3/4a4/4b4/5P2c/3N1R3/9/9/5A3/4K4/6r2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if((my_shi_num + my_xiang_num) >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
             if(StoY(mpawn) == MY_RANK3){
				 RETRUN_MUL(8);
			 }
		}
	}

	// fen 1c2k1b2/4aP3/3a4b/9/4NR3/4r4/9/9/5K3/9 w - - 0 1
	if((my_shi_num + my_xiang_num) <= 1){
		if((your_shi_num + your_xiang_num) == 4 && StoY(mpawn) == MY_RANK1){
			if(StoX(mche) == StoX(mk)){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4kab2/4a4/8r/6PR1/9/2B3N1c/9/8B/4K4/9 w - - 0 1
	if((my_shi_num + my_xiang_num) <= 2 && StoY(mpawn) MY_LARGE_EQL MY_RANK3){
		if(MY_SQ04 == yk && your_shi_num == 2 && your_xiang_num >= 1){
			RETRUN_MUL(8);
		}
	}

	// fen 4ka3/3caP3/4b4/1R4N2/2b6/8r/9/9/9/5K3 w - - 0 1
	if((my_shi_num + my_xiang_num) <= 1){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if(StoY(mpawn) == MY_RANK1 && StoY(mma) MY_SMALL_EQL MY_RANK5){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 9/2Ncak3/5a3/6r2/4P4/7R1/9/3AB4/4A4/2B1K4 r
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK4 && !IsOnSameSide(mma,yk)){
				RETRUN_MUL(12);
			}
		}
	}



}

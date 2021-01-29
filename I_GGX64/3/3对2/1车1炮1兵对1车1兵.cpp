#ifndef END_my_m_MT_R_1che1pao1pawn_B_1che1pawn
#define END_my_m_MT_R_1che1pao1pawn_B_1che1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1炮1兵对1车1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int ADD_Rpao_Cannot_Move = 196;

void my_m_MT_R_1che1pao1pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_ChePaoPawn_ChePao_ByPawnByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_ChePaoPawn_ChePao_ByPawnByShi[my_shi_num]);

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square mche  = S90_from_piecelist(POSITION,my_che,0);
	Square yche  = S90_from_piecelist(POSITION,your_che,0);

	// fen 2ba1k3/2Cra4/2P6/9/9/9/9/B8/6R2/1p1AKA3 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(!IsOnSameSide(mpawn,yk) && abs(StoX(mpawn) - 0x4) >= 2){
				MY_EV_SUB(96);
			}
		}
	}

	//  fen 4k4/9/3Rba2b/6r2/P8/9/9/4p4/1C7/3K5 b - - 0 1
	if (my_shi_num == 0 && my_xiang_num == 0) {
		if (EV_YOUR_CAN >= 1) {
			MY_EV_SUB(32);
			if (abs(StoY(ypawn) - StoY(mk)) <= 2) {
				MY_EV_SUB(32);
			}
			if (abs(StoX(mpawn) - 0x4) == 4) {
				MY_EV_SUB(32);
			}
		}
	}


	// fen 4kc3/9/4P3R/9/9/9/4r4/8B/5K3/4p4 w - - 0 1
	if (StoY(mpawn) == MY_RANK0){
		MY_EV_SUB(32);
		if (my_shi_num == 0 && my_xiang_num == 0){
			if (MY_SQ43 == ypawn){
				MY_EV_SUB(64);
				if (your_xiang_num >= 1){
					MY_EV_SUB(32);
				}
			}
		}
	}

	// fen 4kc3/9/4PR3/9/9/4r4/9/9/3K5/5p3 w - - 0 1
	if (StoY(mpawn) == MY_RANK0){
		if (my_shi_num == 0 && my_xiang_num == 0){
			if (abs(StoY(ypawn) - StoY(mk)) <= 2 && StoY(ypawn) MY_SMALL StoY(mk)){
				MY_EV_SUB(32);
				if (abs(StoX(ypawn) - StoX(mk)) <= 1){
					MY_EV_SUB(64);
				}
			}
		}
	}

	// fen 4kab2/4a4/4b4/9/8p/2B6/8P/8R/4A4/2rCKA3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
		if(EV_MY_CAN == 0 && abs(StoX(mpawn) - 0x4) == 4){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
				if(StoY(yche) MY_LARGE_EQL MY_RANK5){
					MY_EV_SUB(64);
				}
				if(bit_is_set(ei.attacked_by(your_che),mpawn)){
					MY_EV_SUB(64);
				}
			}
		}
	}

	// fen 3ak1b2/4a4/4b4/4r4/9/2C6/2P6/4B1R2/1p7/4K4 b - - 0 1
	if((my_shi_num + my_xiang_num) >= 1){
		MY_EV_ADD(64);
		if(abs(StoX(ypawn) - 0x4) >= 3){
			MY_EV_ADD(64);
		}
	}
	// fen 4kab2/9/3a5/9/6b2/6P2/9/7R1/3p1K1Cr/9 w - - 0 1	
	if(bit_is_set(ei.attacked_by(my_pao),ypawn)){
		MY_EV_ADD(96);
		if(EV_MY_CAN){
			MY_EV_ADD(64);
		}
	}
	

	int mcan = EV_MY_CAN;
	int ycan = EV_YOUR_CAN;

	if(ycan == 0 || my_shi_num >= 1){
		EV_MY_SAFE = TRUE;
	}


	Square mpao  = S90_from_piecelist(POSITION,my_pao,0);

	bool IstringPao = isStringByChe(POSITION,mche,mpao,yche);
	// fen 5k3/4a1P2/3ab4/9/2b6/9/3Rcr3/4BAp2/3KA4/6B2 b - - 29 29
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(StoY(yche) == StoY(mche) && StoY(yche) MY_LARGE_EQL MY_RANK3){
		    if(IstringPao){
				if(StoX(yk) < 0x4){
					if(StoX(yche) <= 0x3 && StoX(mche) > 0x4){
						if(StoY(mpawn) MY_SMALL_EQL MY_RANK2 && StoX(mpawn) > 0x4){
							EV_YOUR_SAFE = TRUE;
						}
					}
				}
				if(StoX(yk) > 0x4){
					if(StoX(yche) >= 0x5 && StoX(mche) < 0x4){
						if(StoY(mpawn) MY_SMALL_EQL MY_RANK2 && StoX(mpawn) < 0x4){
							EV_YOUR_SAFE = TRUE;
						}
					}
				}
			}
		}
	}

	// fen 3k5/4a4/4ba3/9/4R1b1p/9/3rC3P/4BA3/4A4/5K3 b - - 130 130
	//炮给对方垂直牵制了
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(StoX(mche) == StoX(mpao) && mcan == 0){
			if(StoY(yche) == StoY(mpao) && (StoY(yche) == StoY(mpawn))){
				if(StoX(mpawn) == 0x0 || StoX(mpawn) == 0x8){
					EV_YOUR_SAFE = TRUE;
				}
			}
		}
	}

    //兵顶住了, 车炮给牵制住了,也是和棋
	if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
		// fen 4ka3/4a4/1r2b3b/pC7/9/P1B3B2/9/9/4A4/1R1AK4 w - - 5 5
		//兵顶住了, 车炮给牵制住了,也是和棋
		if(mcan == 0){
			if(IstringPao){
				EV_YOUR_SAFE = TRUE;
			}
		}
		// fen 3k5/4a4/3a4b/8p/7P1/9/7rc/4B4/4A4/2BAK3R w - - 120 120
		if(StoY(mpao) == StoY(mche) && StoX(mpao) == StoX(mpawn)){
			if(StoX(yche) == StoX(mpao) && isStringByChe(POSITION,yche,mpao,mpawn)){
				if(PB90(MY_SQ3E) == my_pawn && PB90(MY_SQ34) == your_pawn){
					RETRUN_MUL(4);
				}
				if(PB90(MY_SQ36) == my_pawn && PB90(MY_SQ2E) == your_pawn){
					RETRUN_MUL(4);
				}
			}
		}
		// fen 4k4/4a4/3a5/8p/6bP1/9/2r1c3R/4B4/4A4/2BAK4 b - - 0 0
		if(mcan == 0 && IstringPao){
			RETRUN_MUL(4);
		}
		// fen 4kab2/4a4/4b4/2r1C4/p8/9/P3R4/4B4/4AK3/3A5 b - - 120 120
		if(PB90(XYtoS(StoX(mpao),StoY(yche))) == my_pao){
			if(PB90(ypawn MY_ADD 18) == my_pawn || PB90(ypawn MY_ADD 27) == my_pawn){
				RETRUN_MUL(4);
			}
		}
	}

	// fen CR1ak4/4a4/4b4/r7p/9/6B1P/9/9/4A4/2BA1K3 b - - 0 1
    if(EV_MY_CAN == 0 && your_shi_num == 2 && your_xiang_num >= 1 && PB90(MY_SQ0D) == your_shi){
		if(MY_SQ04 == yk && StoY(mpao) == MY_RANK0 && StoY(mche) == MY_RANK0){
			if(StoX(yche) == StoX(mpao)){
				if(StoX(mpao) < StoX(mche) && StoX(mche) <= 0x2 && PB90(MY_SQ03) == your_shi){
					RETRUN_MUL(4);
				}
				if(StoX(mpao) > StoX(mche) && StoX(mche) >= 0x6 && PB90(MY_SQ05) == your_shi){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 4kab2/4a4/4b4/9/8p/2B6/8P/8R/4A4/2rCKA3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
		if(EV_MY_CAN == 0 && abs(StoX(mpawn) - 0x4) == 4){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK5 && StoX(mche) == StoX(mpawn)){
				if(bit_is_set(ei.attacked_by(your_che),mpawn)){
					RETRUN_MUL(4);
				}	
			}
		}
	}

	// fen 3k1c3/9/2r6/2p6/4R4/2P6/9/3A1A3/3K5/9 w - - 8 8
	if(my_shi_num == 0 && my_shi_num == 0){
		if(your_shi_num == 2 || your_xiang_num == 2){
			if(StoY(yk)  MY_SMALL_EQL MY_RANK1){
			   if(StoY(yche) == MY_RANK5 && StoY(mche) MY_LARGE_EQL MY_RANK7){
				   if(StoX(mpawn) != 0x4 && StoX(mpawn) == StoX(ypawn)){
					   if(StoY(ypawn) == MY_RANK4 && StoY(mpawn) == MY_RANK6){
						   MY_EV_SUB(64);
						   RETRUN_MUL(8);
					   }
				   }
			   }
			}
		}
	}
	
	// fen 3k5/9/3a1a3/9/4r3p/9/8P/9/2R1C4/3AK4 b - - 0 1
	if(your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1 && my_xiang_num <= 1 && my_xiang_num == 0){
		if(EV_MY_CAN == 0 && StoY(ypawn) MY_SMALL_EQL MY_RANK4 && StoY(yche) == StoY(ypawn)){
			if(StoX(mpawn) == StoX(ypawn) && StoY(mpawn) MY_LARGE_EQL StoY(ypawn) && StoX(mpawn) != 0x4){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 2bak4/4a4/4b4/r3C3p/4R4/9/4P4/9/4AK3/5A3 b - - 5 5
	//红方的车炮兵一个也不能动了,要扣分哇
	if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5 && StoX(mpawn) == 0x4){
			if(StoX(mpao) == 0x4 && StoX(mche) == 0x4){
				if(StoY(mpao) MY_SMALL StoY(mche) && StoY(mche) MY_SMALL StoY(mpawn)){
					if(StoY(yche) == StoY(mpao)){
						MY_EV_SUB(196);
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 3ak1b2/4a4/4b4/4r4/9/2C6/2P6/4B1R2/1p7/4K4 b - - 0 1
    if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
			if(abs(StoX(ypawn) - 0x4) >= 3){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4kab2/9/3a5/9/6b2/6P2/9/7R1/3p1K1Cr/9 w - - 0 1
	if(my_shi_num == 0 && my_xiang_num == 0){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL MY_RANK1){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){
				if(StoY(ypawn) == MY_RANK8 && StoY(mpao) == MY_RANK8){
					if(bit_is_set(ei.attacked_by(my_pao),ypawn)){
						MY_EV_ADD(96);
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 2ba1k3/2Cra4/2P6/9/9/9/9/B8/6R2/1p1AKA3 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(!IsOnSameSide(yk,mpao)){
				if(PB90(MY_SQ14) == my_pawn && PB90(MY_SQ0B) == my_pao 
					&& PB90(MY_SQ0C) == your_che){
						RETRUN_MUL(8);
				}
				if(PB90(MY_SQ18) == my_pawn && PB90(MY_SQ0F) == my_pao 
					&& PB90(MY_SQ0E) == your_che){
						RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 4kc3/9/4P3R/9/9/9/4r4/8B/5K3/4p4 w - - 0 1
	if (StoY(mpawn) == MY_RANK0){
		if (my_shi_num == 0 && my_xiang_num == 0){
			if (MY_SQ43 == ypawn){
				if (your_xiang_num >= 1){
					if (StoY(yche) == StoY(ypawn)){
						if (StoX(yche) <= 0x2 && StoX(yk) <= 4 && StoX(mpao) < 0x4){
							RETRUN_MUL(8);
						}
						if (StoX(yche) >= 0x6 && StoX(yk) >= 4 && StoX(mpao) > 0x4){
							RETRUN_MUL(8);
						}
					}
				}
			}
		}
	}
}


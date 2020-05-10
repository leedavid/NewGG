#ifndef END_my_m_MT_R_1pao1ma1pawn_B_2ma1pawn
#define END_my_m_MT_R_1pao1ma1pawn_B_2ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1ÅÚ1Âí1±ø¶Ô2Âí1±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1pao1ma1pawn_B_2ma1pawn(typePOS &POSITION, EvalInfo &ei){
	
	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1pao1maXpawn_To_2ma1pawn_ByPs[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1pao1maXpawn_To_2ma1pawn_ByPs[my_shi_num]);

	MY_EV_ADD(ADD_1pao1maXpawn_To_2ma1pawn);	

	//Square mma = S90_from_piecelist(POSITION,my_ma,0);

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);


	// fen 4P4/3k5/9/9/9/3nN1B2/9/5KC2/4p4/4n1B2 b - - 0 1
	if(my_xiang_num >= 1 && StoY(mk) MY_SMALL StoY(ypawn)){
		MY_EV_ADD(64);
	}

	// fen 3a5/7C1/b4k3/3P5/5N3/4n1B1n/9/9/3pA4/4K4 w - - 0 1
	if(StoY(mpawn) MY_SMALL_EQL MY_RANK3){
		if((your_shi_num + your_xiang_num) <= 3){
			MY_EV_ADD(16);
			if(my_shi_num >= 1){
				MY_EV_ADD(16);
			}
		}
	}

	//  fen 3a1k3/4a4/b8/2P3N2/2C6/6B2/4np3/2nA5/9/2B1K4 w - - 0 1
	if ((your_shi_num + your_xiang_num) <= 4) {
		MY_EV_ADD(32);
		if (StoY(mpawn) MY_SMALL_EQL MY_RANK3) {
			MY_EV_ADD(32);
		}
	}


	// fen 5k3/2N1a4/4Pa1n1/9/9/3n2B2/5p3/3A4B/4A4/3K3C1 b - - 0 1
	if (your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if (StoY(ypawn) == MY_RANK6){
			MY_EV_SUB(64);
			if (abs(StoX(ypawn) - StoX(yk)) <= 1){
				MY_EV_SUB(32);
			}
		}
	}

	if(my_shi_num == 2 && my_xiang_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK7){
			EV_MY_SAFE = TRUE;
		}
	}
	
	// fen 2b2k3/2N1a2P1/b4a3/9/4n4/6B1n/9/2p1BA3/4AC3/3K5 w - - 0 1
	if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
		if((your_shi_num + your_xiang_num) == 4){
			if(abs(StoX(mpawn) - StoX(yk)) >= 2){
				MY_EV_SUB(32);
			}
		}
	}

	// fen 3akab2/5n3/3cN4/7P1/9/3p2N2/9/4BA3/4A4/2B1K4 b - - 0 0
	if(my_shi_num == 2){
		MY_EV_ADD(32);
	}	

	if(StoY(ypawn) == MY_RANK9){
		if((my_shi_num + my_xiang_num) >= 3){
			EV_MY_SAFE = TRUE;
		}
	}
	if(EV_YOUR_CAN == 0){
		if((my_shi_num + my_xiang_num) >= 2){
			EV_MY_SAFE = TRUE;
		}
	}

	// fen 2b2N3/4P4/b4k3/9/9/5n3/4p2n1/3A1A3/3K5/5C3 b - - 129 129
	if(your_xiang_num == 2 && StoY(yk) MY_LARGE StoY(mpawn)){
		if(my_xiang_num == 0 && my_shi_num == 2){
			if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
				if(abs(StoX(ypawn) - 0x4) <= 1){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 4k4/4a1P2/3a5/9/9/3nN1B2/7n1/2p1BA3/4AC3/4K4 w - - 0 1
	if(EV_MY_SAFE){
		if(StoY(yk) MY_SMALL_EQL MY_RANK1 && your_shi_num == 2){
			if(abs(StoX(yk) - StoX(mpawn)) >= 2 && EV_MY_CAN >= 1){
                RETRUN_MUL(8);
			}
		}
	}

	if((your_shi_num + your_xiang_num) == 4){
		if((my_shi_num + my_xiang_num) == 4){
			if(StoY(yk) MY_SMALL_EQL MY_RANK1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
				if(StoY(mpawn) MY_LARGE StoY(yk) && StoY(ypawn) MY_SMALL StoY(mk)){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 5k3/2N1a4/4Pa1n1/9/9/3n2B2/5p3/3A4B/4A4/3K3C1 b - - 0 1
	if (EV_MY_SAFE){
		if (your_shi_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if (StoY(ypawn) == MY_RANK6 && abs(StoX(ypawn) - StoX(yk)) <= 1){
				if (MY_SQ16 == mpawn){
					RETRUN_MUL(8);
				}
			}
		}
	}


	// fen 4k1b2/4a4/9/3N5/3n5/4P4/3n5/4BA3/2p1A1C2/5K3 w - - 120 120
	if((my_shi_num + my_xiang_num) >= 2 && (your_shi_num + your_xiang_num) >= 2){
		if(StoY(yk) MY_SMALL_EQL MY_RANK1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK5 && StoY(ypawn) MY_LARGE_EQL MY_RANK5){
				RETRUN_MUL(8);
			}
		}
	}

	// 
	if(StoY(mpawn) == MY_RANK0 && StoY(yk) != MY_RANK0){
		MY_EV_SUB(80);
	}

	// fen 2b6/2Nka1P2/b2a5/4n4/9/2B6/3n5/5A3/3CA4/1p3K3 w - - 0 1
    if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
				if(abs(StoX(mpawn) - 0x4) >= 2 && !IsOnSameSide(mpawn,yk)){
					RETRUN_MUL(8);
				}
			}
		}
	}
	// fen 3k5/2P3N1C/4b4/2n6/9/6B2/2n6/9/4Ap3/4KA3 w - - 0 1
	if(your_xiang_num >= 1){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(!have_bit(bb_your_ma,MyUpBB[MY_RANK2])){
				if(StoX(mpawn) <= 0x2 
					&& bit_is_set(ei.attacked_by(your_ma),mpawn+1)
					&& StoX(yk) == 0x3){
					MY_EV_SUB(64);
					if((my_shi_num + my_xiang_num) >= 3){
						RETRUN_MUL(8);
					}
				}
				if(StoX(mpawn) >= 0x6 
					&& bit_is_set(ei.attacked_by(your_ma),mpawn-1)
					&& StoX(yk) == 0x5){
					MY_EV_SUB(64);
					if((my_shi_num + my_xiang_num) >= 3){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}	
	// fen 4k4/n2Pa2C1/4ba3/1n2N4/2b6/6B2/9/3ABK3/2p1A4/9 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if((my_shi_num + my_xiang_num) >= 3 ){
			RETRUN_MUL(8);
		}
	}

	// fen 4k4/4a1P2/3a4b/4n4/2p1N4/9/6C2/4BAn2/4A4/3K2B2 w - - 0 1
	if(EV_MY_SAFE){
		if((your_shi_num + your_xiang_num) >= 3){
			if(abs(StoX(mpawn) - 0x4) >= 2 || StoY(mpawn) MY_LARGE_EQL MY_RANK3){
				RETRUN_MUL(8);
			}
		}
	}

	if(my_xiang_num >= 1 && StoY(mk) MY_SMALL StoY(ypawn)){
		if(StoY(mpawn) == MY_RANK0 && my_shi_num == 0){
			RETRUN_MUL(8);
		}
	}

    // fen 5k3/4a4/5a3/C7p/4N4/n5B2/7nP/9/4A4/2B2K3 b - - 0 1
	if(EV_MY_CAN == 0 && EV_YOUR_CAN == 0){
		if((your_shi_num == 2 || your_xiang_num == 2) && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(my_shi_num <= 1){
				RETRUN_MUL(12);
			}
		}
	}

	// fen 5kb2/4an3/3n5/4N4/8p/9/8P/5A3/9/2BAKCB2 b - - 0 1
	if (EV_MY_SAFE){
		if (EV_MY_CAN == 0){
			if (your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK2){
				MY_EV_SUB(64);
				if (count_1s(bb_your_ma, MyUpBB[MY_RANK4]) == 2){
					RETRUN_MUL(12);
				}
			}
		}
	}
}



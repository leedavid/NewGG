#ifndef END_my_m_MT_R_2pao1pawn_B_2ma1pawn
#define END_my_m_MT_R_2pao1pawn_B_2ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮1兵对2马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



//2炮1兵对2马1兵

void my_m_MT_R_2pao1pawn_B_2ma1pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2PaoXPawn_2Ma_ByPawnShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_2MaXPawn_2Pao_ByPawnShi[my_shi_num]);

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mpawn = S90_from_piecelist(POSITION, my_pawn, 0);
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		EV_YOUR_SAFE = true;
	}


	
	// fen 3a5/1C1Pa4/b4k3/9/2b6/6B2/1n2p1n2/9/3CA4/3AK4 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK7){
			MY_EV_ADD(64);
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	// fen 4k4/3Pa4/3ab4/7n1/3C5/4C4/3n5/4p4/4A4/4KA3 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1){
		if (StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if (StoX(mpawn) < 0x4 && PB90(MY_SQ15) == your_shi){
				MY_EV_SUB(32);
			}
			if (StoX(mpawn) > 0x4 && PB90(MY_SQ17) == your_shi){
				MY_EV_SUB(32);
			}
		}
	}

	// fen 5k3/2P6/3a5/5N1c1/6bN1/9/7p1/9/4K4/2BA1A1c1 b - - 0 1
	// 黑马给看死了
	if (my_xiang_num >= 1){
		if (PB90(MY_SQ2E) == your_ma && PB90(MY_SQ2F) == my_xiang){
			if (PB90(MY_SQ37) == my_pao && PB90(MY_SQ1C) == my_pawn){
				MY_EV_ADD(118);
			}			
		}
		if (PB90(MY_SQ34) == your_ma && PB90(MY_SQ33) == my_xiang){
			if (PB90(MY_SQ3D) == my_pao && PB90(MY_SQ22) == my_pawn){
				MY_EV_ADD(118);
			}
		}
	}

     

	// fen 9/5P3/5k3/9/2b3b2/9/1n7/3A5/2pnAC3/3K2C2 w - - 124 124
	
	if(StoY(mpawn) MY_SMALL StoY(yk)){
		MY_EV_SUB(64);
		EV_YOUR_SAFE = TRUE;
	}

	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_LARGE_EQL StoY(mpawn)){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			EV_YOUR_SAFE = TRUE;
		}
	}

	int ycan = EV_YOUR_CAN;

	// fen 4k1b2/4a1c2/9/4P1N2/5Np2/4c2p1/9/p3B4/4A4/4KAB2 w - - 0 0
	if(my_shi_num <= 1 && ycan >= 1){
		MY_EV_SUB(ycan * (4- (my_shi_num + my_xiang_num)) * 80);
	}

	// fen 9/3Pa4/3abk2b/9/9/3n5/6CC1/4pAn2/4A4/4K4 w - - 0 1
	if(EV_YOUR_SAFE){
		if(my_shi_num == 2 && StoY(mk) == MY_RANK9){
			if(PB90(MY_SQ43) == your_pawn){
				//
				if(PB90(MY_SQ42) == my_shi && StoX(mk) != 0x3){
					RETRUN_MUL(8);
				}
				if(PB90(MY_SQ44) == my_shi && StoX(mk) != 0x5){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 4k4/3Pa4/3a5/9/2b3b2/3n5/5C3/4pAn2/4A4/3KC4 b - - 0 1
	if(my_shi_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(PB90(MY_SQ43) == your_pawn){
			if(StoX(mk) <= 0x4 && PB90(MY_SQ42) != my_shi){
				Bitboard ym = m_and(LeftBB[0x4],bb_your_ma);
				if(count_1s(ym) <= 1){
					MY_EV_ADD(64);
					if((your_shi_num + your_xiang_num) == 4){
						RETRUN_MUL(8);
					}
				}
			}
			if(StoX(mk) >= 0x4 && PB90(MY_SQ44) != my_shi){
				Bitboard ym = m_and(RightBB[0x4],bb_your_ma);
				if(count_1s(ym) <= 1){
					MY_EV_ADD(64);
					if((your_shi_num + your_xiang_num) == 4){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 4k4/3Pa4/b2a5/1C7/2b6/9/1n5p1/4BA1n1/4C4/4KAB2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2){
		MY_EV_SUB(64);
		if(my_shi_num == 2 && my_xiang_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			RETRUN_MUL(8);
		}
	}
	// fen 4kab2/4a4/4b3n/5C3/6P2/5nC2/4p4/9/4A4/3AK4 w - - 0 1
	if(EV_YOUR_SAFE){
		if(my_shi_num == 2 && StoY(mk) == MY_RANK9){
			RETRUN_MUL(8);
		}
	}

	// fen 3k1abC1/4a4/9/6C2/6P2/7p1/n7n/4B4/4A4/4KAB2 w - - 0 1
	if (my_shi_num == 2 && StoY(ypawn) MY_SMALL_EQL MY_RANK7 && StoY(mk) MY_LARGE_EQL MY_RANK8) {
		if (your_shi_num == 2 && your_xiang_num >= 1 
			&& StoY(mpawn) MY_LARGE_EQL MY_RANK2 && StoY(yk) MY_SMALL_EQL MY_RANK1) {
			RETRUN_MUL(8);
		}
	}


}


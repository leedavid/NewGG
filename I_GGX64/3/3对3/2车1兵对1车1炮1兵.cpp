
#ifndef END_my_m_MT_R_2che1pawn_B_1che1pao1pawn
#define END_my_m_MT_R_2che1pawn_B_1che1pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2车1兵对1车1炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_2che1pawn_B_1che1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok *  ADD_2CheXPawn_1Che1Pao1Pawn_ByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1Che1PaoXPawn__2Che1Pawn_ByShi[my_shi_num]);

	
	int ycan = EV_YOUR_CAN;
	int mcan = EV_MY_CAN;

	// fen 3a5/3ck4/3a4b/p8/6b2/9/P2R2R2/9/3K5/4r4 b - - 0 1
	if(EV_YOUR_CAN <= 0){
		MY_EV_ADD(64);
	}

	//2车方安全
	// fen 3a5/3ck4/3a4b/p8/6b2/9/P2R2R2/9/3K5/4r4 b - - 0 1
	if(ycan == 0 && (my_shi_num + my_xiang_num) >= 1){
		EV_MY_SAFE = TRUE;
	}

	if(my_shi_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		EV_MY_SAFE = TRUE;
	}

	Square ypao = S90_from_piecelist(POSITION,your_pao,0);
	//炮不在家
	if(StoY(ypao) MY_LARGE MY_RANK2){
		MY_EV_ADD(96);
	}

	Square yche = S90_from_piecelist(POSITION,your_che,0);
	// fen 3ak1b2/4a4/4b4/9/9/PR4B2/r8/4B4/c3A1p2/R3KA3 w - - 46 46
	if(your_shi_num == 2 && your_xiang_num == 2 
		&& MY_SQ04 == yk && StoY(yche) MY_LARGE MY_RANK5){
		if(PB90(MY_SQ51) == my_che && PB90(MY_SQ2D) == my_pawn 
			&& StoX(yche) == 0x0 && PB90(MY_SQ48) == your_pao){
				RETRUN_MUL(2);
		}
		if(PB90(MY_SQ59) == my_che && PB90(MY_SQ35) == my_pawn 
			&& StoX(yche) == 0x8 && PB90(MY_SQ50) == your_pao){
				RETRUN_MUL(2);
		}
	}
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mpawn  = S90_from_piecelist(POSITION,my_pawn,0);
	// fen 3cka3/4a4/9/8r/6R1p/4R4/8P/4B4/9/2BAKA3 w - - 0 0
	if(your_shi_num == 2 && PB90(MY_SQ04) == your_king && PB90(MY_SQ0D) == your_shi){
		if(PB90(ypawn MY_ADD 18) == my_pawn || PB90(ypawn MY_ADD 27) == my_pawn){
			if(StoY(yche) MY_SMALL_EQL MY_RANK3){
				if((StoX(ypawn) == 0x0 || StoX(ypawn) == 0x8) && StoX(ypawn) == StoX(yche)){
					if(PB90(MY_SQ03) == your_shi && PB90(MY_SQ05) == your_pao){
						RETRUN_MUL(2);
					}
					if(PB90(MY_SQ05) == your_shi && PB90(MY_SQ03) == your_pao){
						RETRUN_MUL(2);
					}
				}
			}
		}
	}
	

	// fen 3akab2/9/4b4/R8/8p/2P3BR1/c8/4B4/9/1r1AKA3 b - - 8 8
	if(mcan == 0 && EV_MY_SAFE == TRUE){
		if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
			RETRUN_MUL(4);
		}
	}

	// fen 2bk1a3/2P1a2R1/4b4/9/1R3c3/3r2p2/9/3A5/4A4/4K4 b - - 0 1
    if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(abs(StoX(mpawn) - 0x4) >= 2 || StoY(mpawn) MY_LARGE_EQL MY_RANK2){
			if(StoX(mpawn) <= 0x2 && StoX(yche) == 0x3){
				RETRUN_MUL(8);
			}
			if(StoX(mpawn) >= 0x6 && StoX(yche) == 0x5){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3a5/3ck4/3a4b/p8/6b2/9/P2R2R2/9/3K5/4r4 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && EV_YOUR_CAN == 0){
		if(EV_MY_CAN == 0 && (my_shi_num + my_xiang_num) == 0){
			if(have_bit(EV_YOUR_XBIT,bb_my_che)){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3cka3/1R1R1P3/b1ra5/9/2b6/9/9/B4A3/3pA4/2B2K3 b - - 0 1
	if(EV_MY_SAFE){
		 if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
			 if(StoY(ypao) == MY_RANK0 && abs(StoX(ypao) - 0x4) <= 1){
				 if((StoX(mpawn) > 0X4 && StoX(ypao) < 0X4) ||
					 (StoX(mpawn) < 0X4 && StoX(ypao) > 0X4)){
						 if(StoY(yche) MY_SMALL_EQL MY_RANK4){
							 RETRUN_MUL(8);
						 }
				 }
			 }
		 }
	}


}



#ifndef END_my_m_MT_R_2che1pawn_B_1che1ma1pawn
#define END_my_m_MT_R_2che1pawn_B_1che1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2车1兵对1车1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int MAT_R_2che1pawn_B_1che1ma1pawn_MaSafe = 256;

void my_m_MT_R_2che1pawn_B_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2CheXPawn_1Che1Ma1Pawn_ByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1Che1MaXPawn__2Che1Pawn_ByShi[my_shi_num]);

	int mcan = EV_MY_CAN;
	Square yche  = S90_from_piecelist(POSITION,your_che,0);
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square yma   = S90_from_piecelist(POSITION,your_ma,0);
	// fen 4kab2/4aR3/4R4/4n1r2/9/9/9/4B4/9/2BAKA3 w - - 0 0
	// 红方二个车一个也不能动了,也是和棋, 红方的兵不能过河

	// fen 3nkab2/3Ra4/4b4/4R4/r3p4/2P6/9/4B4/4A4/3AK1B2 b - - 0 1
	if ((your_shi_num + your_xiang_num) == 4 && MY_SQ04 == yk){
		if (mcan == 0 && StoY(mpawn) MY_LARGE_EQL MY_RANK5){
			MY_EV_SUB(64);
		}
	}

	//fen 3nkab2/3Ra4/4b4/4R4/r3p4/2P6/9/4B4/4A4/3AK1B2 b - - 0 1
	if (my_shi_num == 2){
		if (StoY(yma) MY_SMALL_EQL MY_RANK4){
			EV_MY_SAFE = true;
		}
	}

	if(mcan == 0){
		if(your_xiang_num >= 1 && your_shi_num == 2 && StoY(yk) == MY_RANK0){
			if(PB90(MY_SQ1F) == your_ma && PB90(MY_SQ16) == my_che){
				Bitboard che = POSITION.Rook_attacks_bb(yche);
				if(bit_is_set(che,MY_SQ1F)){
					if(PB90(MY_SQ02) == your_xiang && PB90(MY_SQ0C) == my_che){
						EV_YOUR_SAFE = TRUE;
					}
					if(PB90(MY_SQ06) == your_xiang && PB90(MY_SQ0E) == my_che){
						EV_YOUR_SAFE = TRUE;
					}
				}
			}
		}
	}


	if(EV_YOUR_SAFE){
		MY_EV_SUB(pyok * ADD_CheMaPawn_2Che_MaSafe_ByPawn[my_shi_num]);
	}


    // fen 4ka3/4a4/4b4/8R/2b5P/5p3/8r/4B4/2n1K2R1/2BA1A3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
		if(abs(StoX(mpawn) - 0x4) == 4 && StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			MY_EV_SUB(128);
			if(StoY(mk) != MY_RANK9 && StoY(yma) MY_LARGE_EQL MY_RANK5){
				MY_EV_SUB(64);
			}
		}
	}

	if (EV_MY_SAFE){
		// fen 3nkab2/3Ra4/4b4/4R4/r3p4/2P6/9/4B4/4A4/3AK1B2 b - - 0 1
		if ((your_shi_num + your_xiang_num) == 4 && MY_SQ04 == yk){
			if (StoY(mpawn) MY_LARGE_EQL MY_RANK5 && abs(StoX(mpawn) - 0x4) == 2){
				if (mcan == 0 || StoY(yche) == MY_RANK4){
					RETRUN_MUL(8);
				}
			}
		}
	}

}


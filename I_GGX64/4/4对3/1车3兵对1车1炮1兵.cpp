#ifndef END_my_m_MT_R_1che3pawn_B_1che1pao1pawn
#define END_my_m_MT_R_1che3pawn_B_1che1pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车3兵对1车1炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che3pawn_B_1che1pao1pawn(typePOS &POSITION, EvalInfo &ei){
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_CheXPawn_To_1Che1Pao1Pawn_ByPawn[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1Che1Pao1Pawn_To_CheXPawn_ByPawn[my_shi_num]);

	Square ypawn = S90_from_piecelist(POSITION, your_pawn, 0);
	Square mche = S90_from_piecelist(POSITION, my_che, 0);
	Square yche = S90_from_piecelist(POSITION, your_che, 0);

	Bitboard lp = My_get_connect_Pawn(POSITION);

	// fen 1Cbak4/r1P1a4/4b4/2R6/9/9/4pp1p1/9/4A4/2BAK4 w - - 0 1
	if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if (abs(StoX(ypawn) - 0x4) >= 2){
			MY_EV_ADD(32);
		}
		
		if (have_bit(lp, RankBB_A[MY_RANK3])){
			MY_EV_ADD(64);
		}
		if (abs(StoX(ypawn) - 0x4) >= 2){
			if (StoY(mche) == StoY(ypawn) && StoX(yche) == StoX(ypawn)){
				MY_EV_ADD(32);
			}
		}
	}

	// fen 3ak4/4a4/4c4/r1PP5/p8/4R4/P8/4B3B/9/3AK4 b - - 0 1
	if (my_shi_num >= 1 && my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if (your_xiang_num == 0 && EV_YOUR_CAN == 0){
			MY_EV_ADD(32);
			if (have_bit(lp, RankBB_A[MY_RANK3])){
				MY_EV_ADD(64);
				if (StoY(yche) MY_SMALL_EQL MY_RANK3){
					MY_EV_ADD(32);
				}
			}
		}
	}

	// fen 4ka3/4a4/4P3c/P1R6/9/8r/9/4B4/4A4/2B1KA3 w - - 0 1
	if(your_shi_num == 2 && MY_SQ04 == yk){
		MY_EV_SUB(64);
		if(have_bit(bb_my_pawn,MyLowBB[MY_RANK2])){
			MY_EV_SUB(64);
		}
	}
	
	
	// fen 2b2a3/6P2/3ack3/9/2p6/5r3/P1P6/4B4/4A4/2BAK1R2 w
	int ycan = EV_YOUR_CAN;
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if(ycan == 0){
			if(PB90(MY_SQ16) == your_pao){
				if(PB90(MY_SQ17) == your_king && PB90(MY_SQ0F) == my_pawn){
					if(StoX(mche) > 0x4){
					   RETRUN_MUL(4);
					}
				}
				if(PB90(MY_SQ15) == your_king && PB90(MY_SQ0B) == my_pawn){
					if(StoX(mche) < 0x4){
					    RETRUN_MUL(4);
					}
				}
			}
		}
	}

}


#ifndef END_my_m_MT_R_3pawn_B_1pao1pawn
#define END_my_m_MT_R_3pawn_B_1pao1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "3兵对1炮1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_3pawn_B_1pao1pawn(typePOS &POSITION, EvalInfo &ei){
	
	Square yk = your_king_pos;
	Square mk = my_king_pos;

	Square ypawn = S90_from_piecelist(POSITION, your_pawn, 0);
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_3pawn_PaoXPawn_ShiAdd[your_shi_num]);

	// fen 9/1P2k2P1/9/9/9/P8/9/9/4p4/2Bc1K3 w - - 0 1
	if(StoY(yk) MY_LARGE_EQL MY_RANK1){
		if(pmok <= 1){
			MY_EV_SUB((3 - pmok) * 64);
			EV_YOUR_SAFE = TRUE;
		}
	}

	//  fen 3ak1b2/4a4/4b4/6P2/9/P8/1c4P2/9/3p5/3AKA3 w - - 0 1
	if (my_shi_num == 2 && StoY(mk) == MY_RANK9) {
		if (StoY(ypawn) MY_LARGE_EQL MY_RANK8) {
			MY_EV_ADD(128);
			if (have_bit(bb_my_pawn, RankBB_A[MY_RANK3])) {
				MY_EV_ADD(64);
				MY_EV_ADD(EV_MY_CAN * 64);
			}
		}
	}

	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1PaoXPawn_3pawn_ShiAdd[my_shi_num]);

	

	MY_EV_SUB(ADD_1PaoXPawn_3Pawn);

	if(your_shi_num == 2){
		MY_EV_SUB(64);
	}

	if(your_shi_num == 2){
		EV_YOUR_SAFE = true;
	}

	Bitboard lp = My_get_connect_Pawn(POSITION);
	// fen 3k5/4P4/9/9/9/9/2p6/3C5/2pp1K3/3A1A3 w - - 0 1
	if (EV_YOUR_SAFE){
		if (m_have_bit(m_and(lp, RankBB_A[MY_RANK1]))){
			if (have_bit(bb_my_pawn, RankBB_A[MY_RANK3])){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 9/4aPP2/3ak4/9/9/9/5c2P/9/4p4/5K3 b - - 0 1
	if (your_xiang_num == 0 && EV_MY_CAN == 3){
		if (StoY(ypawn) MY_LARGE_EQL MY_RANK7 && abs(StoY(ypawn) - StoY(mk)) <= 1){
			if (have_bit(lp, MyLowBB[MY_RANK0])){
				if (have_bit(lp, FileBB_A[0x5]) && StoX(mk) == 0x5){
					MY_EV_ADD(256);
					MY_EV_ADD(EV_MY_CAN * 32);
				}
				if (have_bit(lp, FileBB_A[0x3]) && StoX(mk) == 0x3){
					MY_EV_ADD(256);
					MY_EV_ADD(EV_MY_CAN * 32);
				}
			}
		}
	}

	// fen 3k5/4P4/9/9/9/9/2p6/3C5/2pp1K3/3A1A3 w - - 0 1
	//if (EV_YOUR_SAFE){
	//	if (abs(StoY(ypawn) - StoY(mk)) <= 1 && StoY(ypawn) MY_LARGE_EQL MY_RANK7){
	//		if (have_bit(bb_my_pawn, RankBB_A[MY_RANK3])){
	//			if ()
	//		}
	//	}
	//}

	// fen 3k1Cb2/4P4/9/9/8p/9/9/9/1p2K2p1/9 b - - 0 1
	if(your_shi_num == 0 && mk != MY_SQ55){
		MY_EV_ADD(96);
		if(StoY(ypawn) MY_LARGE_EQL MY_RANK7 && abs(StoY(ypawn) - StoY(mk)) <= 1){
			MY_EV_ADD(96);
			MY_EV_ADD(EV_MY_CAN * 64);
			if(EV_YOUR_SAFE){
				RETRUN_MUL(8);
			}
		} 
	}


	// fen 9/4aPP2/3ak4/9/9/9/5c2P/9/4p4/5K3 b - - 0 1
	if(StoY(ypawn) MY_LARGE_EQL MY_RANK7 && abs(StoY(ypawn) - StoY(mk)) <= 1 && EV_MY_CAN >= 3){
		if(StoX(mk) == 0x5 && bit_is_set(lp,MY_SQ0E)){
			RETRUN_MUL(8);
		}
		if(StoX(mk) == 0x3 && bit_is_set(lp,MY_SQ0C)){
			RETRUN_MUL(8);
		}
	}

	//  fen 3ak1b2/4a4/4b4/6P2/9/P8/1c4P2/9/3p5/3AKA3 w - - 0 1
	if (EV_YOUR_SAFE) {
		if (my_shi_num >= 1 && StoY(ypawn) == MY_RANK9) {
			if (count_1s(bb_my_pawn, RankBB_A[MY_RANK3]) >= 2) {
				RETRUN_MUL(8);
			}
		}
	}

	//  fen 3ak1b2/4a4/4b4/6P2/9/P8/1c4P2/9/3p5/3AKA3 w - - 0 1
	if (EV_YOUR_SAFE) {
		if (my_shi_num == 2 && StoY(mk) == MY_RANK9) {
			if (StoY(ypawn) MY_LARGE_EQL MY_RANK8) {
				if (have_bit(bb_my_pawn, RankBB_A[MY_RANK3])) {
					if (EV_MY_CAN >= 2) {
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

}


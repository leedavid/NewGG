#ifndef END_my_m_MT_R_2pao2pawn_B_2ma1pawn
#define END_my_m_MT_R_2pao2pawn_B_2ma1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2炮2兵对2马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_2pao2pawn_B_2ma1pawn(typePOS &POSITION, EvalInfo &ei){
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2PaoXPawn_2Ma_ByPawnShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_2PaoXPawn_2Ma_ByPawnShi[my_shi_num]);
	
	// fen 4k4/4a4/5a3/p8/4pN3/9/2c1P3c/2N1B4/9/3AKAB2 w - - 7 7
	int ycan = EV_YOUR_CAN;
	int mcan = EV_MY_CAN;

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	// fen 2bak4/9/3ab4/C7p/5n3/P1P6/5n3/4B4/4A2C1/2BAK4 b - - 0 1
	if ((my_shi_num + my_xiang_num) >= 3){
		EV_MY_SAFE = true;
	}

	if(ycan == 0){
		MY_EV_ADD(mcan * 32);
	}
	// fen 3k1a3/9/3C5/9/5P3/2B3n1P/p8/3n5/3C5/4K1B2 w - - 0 1
	if((my_shi_num + my_xiang_num) >= 2 && EV_MY_CAN >= 2){
		if(abs(StoX(ypawn) - 0x4) >= 3){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	// fen 4kab2/4a4/1CP6/6CP1/9/6B2/5n3/p3B4/4n4/4K4 b - - 0 1
	if(my_shi_num == 2 || my_xiang_num == 2){
		MY_EV_ADD(32);
		if(abs(StoX(ypawn) - 0x4) >= 3){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	// fen 2b2k3/2Nca4/3a5/p5Ncp/2b6/6B2/P8/9/4A4/2BAK4 w - - 0 1
	if (EV_MY_SAFE) {
		if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0) {
			MY_EV_SUB(32);

			Bitboard p = m_and(bb_my_pawn, 
				m_and(MyLowBB[MY_RANK4], m_or(FileBB_A[0x0], FileBB_A[0x8])));

			MY_EV_SUB(48 * count_1s(p));
		}
	}

	//int ycan = EV_YOUR_CAN;

	// fen 4k1b2/4a1c2/9/4P1N2/5Np2/4c2p1/9/p3B4/4A4/4KAB2 w - - 0 0
	if(my_shi_num <= 1 && ycan >= 1){
		MY_EV_SUB(ycan * (4- (my_shi_num + my_xiang_num)) * 80);
	}

	// fen 2b1k4/4a4/3ab4/9/1C6p/2P3B2/7nP/2n1BA3/3KA4/8C b - - 143 143
	if(mcan == 0 && ycan == 0){
		RETRUN_MUL(8);
	}

	// fen 2bak4/9/3ab4/C7p/5n3/P1P6/5n3/4B4/4A2C1/2BAK4 b - - 0 1
	if (EV_MY_SAFE){
		if (your_shi_num == 2 && your_xiang_num == 2){
			if (EV_MY_CAN <= 1){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 2bak4/4a4/4b4/8p/3P5/4CnB1P/9/4B1Cn1/4AK3/9 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(EV_MY_CAN <= 1){
			MY_EV_SUB(32);
			if(EV_YOUR_CAN == 0){
				if((my_shi_num + my_xiang_num) >= 2){
					RETRUN_MUL(12);
				}
			}
		}		
	}
	
}



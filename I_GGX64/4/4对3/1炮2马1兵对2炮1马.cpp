#ifndef END_my_m_MT_R_1pao2ma1pawn_B_2pao1ma
#define END_my_m_MT_R_1pao2ma1pawn_B_2pao1ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮2马1兵对2炮1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 




void my_m_MT_R_1pao2ma1pawn_B_2pao1ma(typePOS &POSITION, EvalInfo &ei){
	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao2MaXpawn_To_2Pao1Ma_ByPawn[your_shi_num]);

	Square mk = my_king_pos;
	if((my_shi_num + my_xiang_num) >= 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		MY_EV_ADD(32);
	}

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	// fen 2ba1k3/4a4/4b1c2/1P6c/9/2C3nC1/9/5A2N/4A4/4K4 b - - 0 1
	if(my_shi_num == 2 || my_xiang_num == 2){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			MY_EV_ADD(EV_MY_CAN * 32);
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK1){
				MY_EV_ADD(32);
			}
		}
	}

	// fen 5a3/4a4/5k2b/9/N8/9/4P4/n4A3/N1cCAK3/c8 b - - 0 0
	if(StoY(yk) != MY_RANK0){
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	// fen 3k2b2/1P2a4/3ab4/5N3/2c1N4/n5B2/1c7/3AB4/1C2A4/5K3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		//if(abs(StoX(mpawn) - 0x4) >= 3){
		//	MY_EV_SUB(128);
		//}
		MY_EV_SUB((abs(StoX(mpawn) - 0x4)) * 16);
	}

	// fen 3k1ab2/2c1a4/4b4/2N1cN3/9/8P/9/6n2/5K3/2BAC4 b - - 0 1
	if((my_shi_num + my_xiang_num) >= 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		MY_EV_ADD(EV_MY_CAN * 32);
	}
	
}


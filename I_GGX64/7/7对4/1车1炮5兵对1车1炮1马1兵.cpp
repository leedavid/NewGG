#ifndef END_my_m_MT_R_1che1pao5pawn_B_1che1pao1ma1pawn
#define END_my_m_MT_R_1che1pao5pawn_B_1che1pao1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1炮5兵对1车1炮1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1che1pao5pawn_B_1che1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Square yma  = S90_from_piecelist(POSITION,your_ma,0);
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);
	//
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[your_shi_num]);
	//
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[my_shi_num]);

	// fen 2baka3/9/2n1b4/2C2PP2/P1P5p/9/8P/1r2B2R1/4A4/3AK3c b - - 0 1
	//if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) MY_LARGE_EQL MY_RANK8){
	//	if(StoY(yma) MY_SMALL_EQL MY_RANK2 && EV_YOUR_CAN == 0){
	//		MY_EV_ADD(EV_MY_CAN * 16);
	//	}
	//}

	// fen 3a1k3/nR2a4/rP2b4/3PC3p/4PP3/9/8P/9/c3K4/9 b - - 0 1
	if(EV_YOUR_CAN == 0){
		if(StoY(yma) MY_SMALL_EQL MY_RANK2){

			if(abs(StoX(yma) - 0x4) == 4){
				MY_EV_ADD(EV_MY_CAN * 16);
			}

			MY_EV_ADD(EV_MY_CAN * 16);
			if((my_shi_num + my_xiang_num) >= 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
				MY_EV_ADD(EV_MY_CAN * 16);
			}

			if(StoY(ypao) MY_LARGE_EQL MY_RANK5){
				MY_EV_ADD(EV_MY_CAN * 8);
			}
		}
	}
}




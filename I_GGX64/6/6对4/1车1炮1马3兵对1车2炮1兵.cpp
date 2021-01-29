#ifndef END_my_m_MT_R_1che1pao1ma3pawn_B_1che2pao1pawn
#define END_my_m_MT_R_1che1pao1ma3pawn_B_1che2pao1pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车1炮1马3兵对1车2炮1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



void my_m_MT_R_1che1pao1ma3pawn_B_1che2pao1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	//
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[your_shi_num]);
	//
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[my_shi_num]);

	Square mk    = my_king_pos;
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mma   = S90_from_piecelist(POSITION,my_ma,0);

	// fen 4kab2/4aC3/N3c3b/3R5/1P2P3p/2r3P2/8c/3AB4/9/4K4 b - - 0 1
	// fen 3ak4/4a3R/P2cbn3/8p/2p1p4/8r/9/4B4/2C1A1C2/2BAK4 b
	// fen 3ak4/4a4/4b3b/p3R4/5c3/5r2C/P1N1P3P/9/4K4/c1BA1A3 b - - 0 1
	if(my_shi_num >= 1 && my_xiang_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(abs(StoX(ypawn) - 0x4) == 4 || EV_YOUR_CAN == 0){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}
	// fen 5ab2/3ka4/4b4/p6NC/3r5/2R6/P3P3P/9/4AK3/c5c2 w - - 0 1
	if(EV_YOUR_CAN == 0 && abs(StoX(ypawn) - 0x4) == 4){
		MY_EV_ADD(EV_MY_CAN * 16);
		if(StoY(mma) MY_SMALL_EQL MY_RANK5){
			MY_EV_ADD(32);
		}
	}

	// fen 1c2kabC1/4a4/4Nr3/2P6/4R3p/9/4P3P/9/2c1K4/9 w - - 0 1
	if(EV_YOUR_CAN == 0){
		MY_EV_ADD(EV_MY_CAN * 16);
		if((your_shi_num + your_xiang_num) <= 3){
			if(StoY(mma) MY_SMALL_EQL MY_RANK4){
				MY_EV_ADD(EV_MY_CAN * 16);
			}
		}
	}
}


#ifndef END_my_m_MT_R_2ma_B_1pao1pawn
#define END_my_m_MT_R_2ma_B_1pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2马对1炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2ma_B_1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square ypao  = S90_from_piecelist(POSITION,your_pao,0);
	Square mk    = my_king_pos;

	if(StoY(ypawn) MY_SMALL StoY(mk)){
		MY_EV_SUB(ADD_2MaXPawn_1Ma[my_shi_num]);
	}
	// fen 3k5/4a4/b2a1c3/3N1N3/2b6/9/9/3AB4/4K4/2p6 b - - 25 25
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) != MY_RANK2){
		RETRUN_MUL(2);
	}

	// fen 5k3/2P6/3a5/4n4/9/2B6/6n2/4B4/9/3K1C3 b - - 0 1
	if(your_xiang_num == 2 && EV_MY_CAN == 1){
		RETRUN_MUL(2);
	}
	if(your_xiang_num == 2){
		RETRUN_MUL(4);
	}
	// fen 1c1k2b2/4a3N/N4a3/9/9/2B6/9/3ABK3/6p2/5A3 b - - 0 1
	if(StoY(ypao) MY_SMALL_EQL MY_RANK2){
		MY_EV_SUB(64);
	}

	// fen 9/4k4/3aCa3/2N1c4/9/9/1p7/9/4A4/2B2K3 b - - 0 1
	if(EV_YOUR_CAN >= 1){
		if(PB90(MY_SQ16) == my_ma && PB90(MY_SQ15) == your_shi && PB90(MY_SQ17) == your_shi){
			if(PB90(MY_SQ1F) == your_pao && StoX(yk) == 0x4){
				RETRUN_MUL(4);
			}
		}

		if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(8);
		}
	}
}


#ifndef END_my_m_MT_R_1pao5pawn_B_5pawn
#define END_my_m_MT_R_1pao5pawn_B_5pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮5兵对5兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};


void my_m_MT_R_1pao5pawn_B_5pawn(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	//
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1PaoXPawn_3pawn_ShiAdd[your_shi_num]);

	int ycan = EV_YOUR_CAN;

	if(ycan >= 2){
		//
		Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
		MY_EV_SUB((sint16)count_1s(ymp) * ADD_3pawn_PaoXPawn_ShiAdd[my_shi_num]);
	}

	MY_EV_ADD(ADD_1PaoXPawn_3Pawn);  //炮兵方的别外加分
}


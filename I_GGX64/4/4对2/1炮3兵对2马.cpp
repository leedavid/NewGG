#ifndef END_my_m_MT_R_1pao3pawn_B_2ma
#define END_my_m_MT_R_1pao3pawn_B_2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮3兵对2马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



// 1炮3兵对2马
void my_m_MT_R_1pao3pawn_B_2ma(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_PaoXPawn_To_2MaByShi[your_shi_num]);

	//  fen 2ba5/4ak3/4b4/P7P/P6C1/9/7n1/2n1BA3/3KA4/6B2 b - - 0 1
	if (EV_MY_CAN >= 3) {
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	if ((my_shi_num + my_xiang_num) >= 2) {
		MY_EV_ADD(EV_MY_CAN * 16);
	}
}

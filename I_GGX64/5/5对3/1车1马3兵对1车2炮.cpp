#ifndef END_my_m_MT_R_1che1ma3pawn_B_1che2pao
#define END_my_m_MT_R_1che1ma3pawn_B_1che2pao
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车1马3兵对1车2炮.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


// fen 2b1kab2/4a4/3rcc3/6P2/5R3/P8/4P3P/4B1N2/4A4/2BAK4 b - - 1

void my_m_MT_R_1che1ma3pawn_B_1che2pao(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheMaPawn_ChePao1pawn_ByPawnByShi[your_shi_num]);

	// fen 2b1kab2/4a4/3rcc3/6P2/5R3/P8/4P3P/4B1N2/4A4/2BAK4 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		MY_EV_ADD(EV_MY_CAN * 16);
	}

}


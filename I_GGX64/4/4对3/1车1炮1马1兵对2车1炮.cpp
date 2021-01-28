#ifndef END_my_m_MT_R_1che1pao1ma1pawn_B_2che1pao
#define END_my_m_MT_R_1che1pao1ma1pawn_B_2che1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1炮1马1兵对2车1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che1pao1ma1pawn_B_2che1pao(typePOS &POSITION, EvalInfo &ei){

	//// ADD_MY
	//Square yk = your_king_pos;
	//Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	//int pmok = (int)count_1s(bmp);
	//MY_EV_ADD(pmok * ADD_1che1pao1ma1pawn_1che2pao_ByShi[your_shi_num]);

	// fen 2b1kab2/4a4/n3c4/4R4/p8/6R2/6N2/9/4AK3/8r b - - 0 1
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
		MY_EV_SUB(64);
	}
}
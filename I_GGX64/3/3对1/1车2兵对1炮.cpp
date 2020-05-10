#ifndef END_my_m_MT_R_1che_2pawn_B_1pao
#define END_my_m_MT_R_1che_2pawn_B_1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车2兵对1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//车2兵对1炮
void my_m_MT_R_1che_2pawn_B_1pao(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheXPawn_To1Pao_ByPawnShi[your_shi_num]);

	MY_EV_ADD(ADD_CheXPawn_To1Pao);
}

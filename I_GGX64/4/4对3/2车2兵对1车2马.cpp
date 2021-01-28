#ifndef END_my_m_MT_R_2che2pawn_B_1che2ma
#define END_my_m_MT_R_2che2pawn_B_1che2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2车2兵对1车2马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 




void my_m_MT_R_2che2pawn_B_1che2ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2CheXPawn_1Che2Ma_ByPawnShi[your_shi_num]);
	

}


#ifndef END_my_m_MT_R_1pao2ma3pawn_B_2pao1ma
#define END_my_m_MT_R_1pao2ma3pawn_B_2pao1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮2马3兵对2炮1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 




void my_m_MT_R_1pao2ma3pawn_B_2pao1ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao2MaXpawn_To_2Pao1Ma_ByPawn[your_shi_num]);
}


#ifndef END_my_m_MT_R_1che2pawn_B_1ma1pawn
#define END_my_m_MT_R_1che2pawn_B_1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车2兵对1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


// fen 9/3P5/4k4/9/2b3b2/6B2/9/3AB4/r3Ap3/C3K4 w - - 44 44

//const int ADD_PaoXPawn_To_ChePawnByShi_WpaoSafe[3]  =  { 80, 48, 16};  //炮兵对车兵,炮方安全后,有兵的加分 

//车兵对马兵
void my_m_MT_R_1che2pawn_B_1ma1pawn(typePOS &POSITION, EvalInfo &ei){


	// fen 5a3/3P5/b2ak4/9/6b2/5r3/9/4C3B/3pA4/3AK1B2 w - - 14 14
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_CheXPawn_To_MaPawn_PawnByShi[your_shi_num]);

	MY_EV_ADD(ADD_CheXPawn_To_MaPawn);


}


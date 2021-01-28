#ifndef END_my_m_MT_R_1ma5pawn_B_2pawn
#define END_my_m_MT_R_1ma5pawn_B_2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马5兵对2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int  ADD_1MaXPawn_2Pawn                       = 128;              //1马x兵对2兵的加分 
//const int  ADD_1MaXPawn_To_2Pawn_ByMaPawn[3]        = {96,  64, 32};
//const int  ADD_1MaXPawn_To_2Pawn_ByPawnSide[3]      = {80,  48, 16};


void my_m_MT_R_1ma5pawn_B_2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1MaXPawn_To_2Pawn_ByPawnSide[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1MaXPawn_To_2Pawn_ByMaPawn[my_shi_num]);

	MY_EV_ADD(ADD_1MaXPawn_2Pawn);
}


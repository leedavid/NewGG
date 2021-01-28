#ifndef END_my_m_MT_R_2che4pawn_B_2che
#define END_my_m_MT_R_2che4pawn_B_2che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2车4兵对2车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//
//const int const_Shi_add[3] = { 128, 48, 0};
//const int const_Pawn_add   = 64;


//2车4兵对2车
void my_m_MT_R_2che4pawn_B_2che(typePOS &POSITION, EvalInfo &ei){
	

	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2车x兵对2车_byPawn[your_shi_num]);
}

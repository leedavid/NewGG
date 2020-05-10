#ifndef END_my_m_MT_B_1pao1ma3pawn_R_2ma2pawn
#define END_my_m_MT_B_1pao1ma3pawn_R_2ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1ÅÚ1Âí3±ø¶Ô2Âí2±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1pao1ma3pawn_B_2ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[my_shi_num]);

	//int mcan = EV_MY_CAN;
	// fen 2ba1k3/4a4/4b4/p4C3/9/P1P3Pp1/3n5/N3B4/4A1n2/2BAK4 w - - 0 0
	MY_EV_ADD(64);
	
	// fen 2ba1k3/3P5/9/9/p3pNb2/8p/P1c6/2N1BA3/4A1n2/2BK5 w - - 10 10
	if(my_shi_num >= 1 && EV_YOUR_CAN <= 1){
		MY_EV_ADD(EV_MY_CAN * 16);
	}
}
//
//void  m_MT_R_1pao1ma3pawn_B_2ma2pawn(typePOS &POSITION, EvalInfo &ei){
//
//	//
//	//Square rk = PieceListStart(board,RKING);
//	//Square bk = PieceListStart(board,BKING);
//
//	//return 16;
//}
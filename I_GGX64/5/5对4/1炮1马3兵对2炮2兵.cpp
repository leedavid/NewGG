#ifndef END_my_m_MT_B_1pao1ma3pawn_R_2pao2pawn
#define END_my_m_MT_B_1pao1ma3pawn_R_2pao2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1ÅÚ1Âí3±ø¶Ô2ÅÚ2±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void  my_m_MT_R_1pao1ma3pawn_B_2pao2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[my_shi_num]);

	// fen 4kabC1/3Pa4/4b4/2p1n4/p8/2P1C2p1/4c4/B2A1A3/9/5K3 b - - 0 1
	if(EV_YOUR_CAN <= 1){
		MY_EV_ADD(EV_MY_CAN * 16);
	}
	MY_EV_ADD(EV_MY_CAN * 16);
}

//void  m_MT_R_1pao1ma3pawn_B_2pao2pawn(typePOS &POSITION, EvalInfo &ei){
//
//	//
//	//Square rk = PieceListStart(board,RKING);
//	//Square bk = PieceListStart(board,BKING);
//
//	//return 16;
//}
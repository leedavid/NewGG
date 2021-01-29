#ifndef END_my_m_MT_R_2pao1ma2pawn_B_2pao1ma2pawn
#define END_my_m_MT_R_2pao1ma2pawn_B_2pao1ma2pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2炮1马2兵对2炮1马2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_2pao1ma2pawn_B_2pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1MaXPawn_3pawn_ShiAdd[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1MaXPawn_3pawn_ShiAdd[my_shi_num]);
}

//void m_MT_B_2pao1ma2pawn_R_2pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//   int rcan = RpawnCanOverLiver(board);
//   int bcan = BpawnCanOverLiver(board);
//
//   if(rcan == 0){
//	   board->mulScore -= bcan * ADD_2Pao1Ma_To_2Pao1Ma_By_PawnCan;
//   }
//
//   if(bcan == 0){
//	   board->mulScore += rcan * ADD_2Pao1Ma_To_2Pao1Ma_By_PawnCan;
//   }
//
//	*/
//}

//const int ADD_2Pao1Ma_To_2Pao1Ma_By_PawnCan         = 64;
//const int ADD_2Pao1Ma_To_1Pao2Ma_By_PawnCan         = 64;
//const int ADD_1Pao2Ma_To_1Pao2Ma_By_PawnCan         = 64;

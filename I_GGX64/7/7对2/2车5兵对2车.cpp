#ifndef END_my_m_MT_R_2che5pawn_B_2che
#define END_my_m_MT_R_2che5pawn_B_2che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2车5兵对2车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2che5pawn_B_2che(typePOS &POSITION, EvalInfo &ei){
  


	Square yk = your_king_pos;
	//
   Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
   MY_EV_ADD((sint16)count_1s(bmp) * ADD_2车x兵对2车_byPawn[your_shi_num]);


}

//void m_MT_B_2che5pawn_R_2che(typePOS &POSITION, EvalInfo &ei){
///*
//	//uint16 Info16 = board->pMat->sixiangInfo8;
//
//	//if(Info16 & CK_R_2s){
//	//	board->mulScore += 128;
//	//}
//	//else if(Info16 & CK_R_1s){
//	//	board->mulScore += 48;
//	//}
//
//
//	//if(Info16 & CK_B_2s){
//	//	board->mulScore -= 128;
//	//}
//	//else if(Info16 & CK_B_1s){
//	//	board->mulScore -= 48;
//	//}
//
//	const int const_Shi_Add[3] = {0, 48, 128};
//
//	board->mulScore += const_Shi_Add[board->R_shi];
//	board->mulScore -= const_Shi_Add[board->B_shi];
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > 0x3){
//			board->mulScore -= 64;
//		}
//	}
//
//
//	*/
//}

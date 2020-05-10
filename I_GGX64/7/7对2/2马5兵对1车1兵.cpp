#ifndef END_my_m_MT_R_2ma5pawn_B_1che1pawn
#define END_my_m_MT_R_2ma5pawn_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2马5兵对1车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByShi

// 红方马炮兵,黑方车兵
void my_m_MT_R_2ma5pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	//
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * Add_MAT_B_2ma1pawn_R_1che1pawn_ByShi[your_shi_num]);
	//
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * Add_MAT_B_1che1pawn_R_2ma1pawn_ByShi[my_shi_num]);

	//if(Your_pawn_can_over_river(POSITION) == 0){
	//	MY_EV_ADD(My_pawn_can_over_river(POSITION) * Add_2ma1pawn_1che1pawn_MaPawnCan);
	//}
}

// 黑方马炮兵,红方车兵
//void m_MT_B_2ma5pawn_R_1che1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rpawn = PieceListStart(board,RPAWN);
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	int rcan = RpawnCanOverLiver(board);
//	int bcan = BpawnCanOverLiver(board);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -=  Add_MAT_B_2ma1pawn_R_1che1pawn_ByShi[board->R_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += Add_MAT_B_1che1pawn_R_2ma1pawn_ByShi[board->B_shi];
//		}
//	}
//
//
//	//如果黑方的兵不能过河,要减分
//	//if((board->B_shi + board->B_xiang) >= 3){
//	//	if(rcan == 0){
//	//		board->mulScore -= Add_2ma1pawn_1che1pawn_chePawnCan0;
//	//	}
//	//}
//	// fen 3k1ab2/9/4ba3/9/4p4/5N3/P3P1r1P/3AB1N2/9/2B1K4 w - - 1 1
//	if(rcan == 0){
//		board->mulScore -= bcan * Add_2ma1pawn_1che1pawn_MaPawnCan;
//	}
//
//	*/
//}


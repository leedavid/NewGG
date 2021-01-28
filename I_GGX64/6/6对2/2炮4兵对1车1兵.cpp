#ifndef END_my_m_MT_R_2pao4pawn_B_1che1pawn
#define END_my_m_MT_R_2pao4pawn_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮4兵对1车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



//Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByShi

// 红方2炮兵,黑方车兵
void my_m_MT_R_2pao4pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * Add_MAT_B_2pao1pawn_R_1che1pawn_ByShi[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * Add_MAT_B_1che1pawn_R_2pao1pawn_ByShi[my_shi_num]);
}

//// 黑方2炮兵,红方车兵
//void m_MT_B_2pao4pawn_R_1che1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rpawn = PieceListStart(board,RPAWN);
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -=  Add_MAT_B_2pao1pawn_R_1che1pawn_ByShi[board->R_shi];
//		}
//	}	
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += Add_MAT_B_1che1pawn_R_2pao1pawn_ByShi[board->B_shi];
//		}
//	}
//
//	*/
//}
//

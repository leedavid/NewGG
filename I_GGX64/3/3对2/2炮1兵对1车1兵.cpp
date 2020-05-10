#ifndef END_my_m_MT_R_2pao1pawn_B_1che1pawn
#define END_my_m_MT_R_2pao1pawn_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮1兵对1车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByShi

// 红方2炮兵,黑方车兵
void my_m_MT_R_2pao1pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * Add_MAT_B_1che1pawn_R_2pao1pawn_ByShi[my_shi_num]);

	MY_EV_SUB(64);

}

// 黑方2炮兵,红方车兵
//void m_MT_B_2pao1pawn_R_1che1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bpawn = PieceListStart(board,BPAWN);
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	if(StoY(bpawn) < StoY(rk)){
//		board->mulScore -=  Add_MAT_B_2pao1pawn_R_1che1pawn_ByShi[board->R_shi];
//	}
//
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += Add_MAT_B_1che1pawn_R_2pao1pawn_ByShi[board->B_shi];
//		}
//	}
//
//	*/
//}


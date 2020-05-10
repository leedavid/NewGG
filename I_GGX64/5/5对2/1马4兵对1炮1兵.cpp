#ifndef END_my_m_MT_R_1ma4pawn_B_1pao1pawn
#define END_my_m_MT_R_1ma4pawn_B_1pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1鎮4條勤1蘿1條.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//1鎮5條勤蘿條
void my_m_MT_R_1ma4pawn_B_1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_MaPawn_To_PaoPawnByShi[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_MaPawn_To_PaoPawnByShi[my_shi_num]);
}

//1鎮5條勤蘿條
//void m_MT_B_1ma4pawn_R_1pao1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_MaPawn_To_PaoPawnByShi[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_MaPawn_To_PaoPawnByShi[board->R_shi];
//		}
//	}
//
//	*/
//}
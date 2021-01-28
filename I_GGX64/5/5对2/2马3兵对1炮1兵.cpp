#ifndef END_my_m_MT_R_2ma3pawn_B_1pao1pawn
#define END_my_m_MT_R_2ma3pawn_B_1pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2马3兵对1炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 




void my_m_MT_R_2ma3pawn_B_1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2MaXPawn_2Ma_ByPawnShi[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_2MaXPawn_2Ma_ByPawnShi[my_shi_num]);
}

//void m_MT_B_2ma3pawn_R_1pao1pawn(typePOS &POSITION, EvalInfo &ei){
///*	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= 96;
//		}
//
//	}
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > 0x3){
//			board->mulScore += 96;
//		}
//
//	}
//
//	*/
//}
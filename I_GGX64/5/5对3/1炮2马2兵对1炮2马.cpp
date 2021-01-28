#ifndef END_my_m_MT_R_1pao2ma2pawn_B_1pao2ma
#define END_my_m_MT_R_1pao2ma2pawn_B_1pao2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮2马2兵对1炮2马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1pao2ma2pawn_B_1pao2ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao2MaXpawn_To_1Pao2Ma_ByPawn[your_shi_num]);

	// fen 3a1kb2/3ca4/4b4/2PC5/9/N3n4/8P/3A2N2/3K5/n4A3 w - - 0 1
	if((my_shi_num == 2 || my_xiang_num == 2)){
		MY_EV_ADD(EV_MY_CAN * 16);
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}
	// fen 2bak4/4a4/4c3b/N7C/9/7NP/6P2/4cA3/1n1K5/5A3 w - - 0 1

}

//void m_MT_B_1pao2ma2pawn_R_1pao2ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_1Pao2Ma_To_1Pao2MaXpawn_ByPawn[board->B_shi];
//		}
//
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1Pao2MaXpawn_To_1Pao2Ma_ByPawn[board->R_shi];
//		}
//	}
//
//
//
//	*/
//}
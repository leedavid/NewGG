#ifndef END_my_m_MT_R_2pao3pawn_B_2pao1pawn
#define END_my_m_MT_R_2pao3pawn_B_2pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮3兵对2炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//ADD_2PaoXPawn_2Pao1Pawn_ByPawnShi


void my_m_MT_R_2pao3pawn_B_2pao1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2PaoXPawn_2Pao1Pawn_ByPawnShi[your_shi_num]);

	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_2Pao1Pawn_2PaoXPawn_ByPawnShi[my_shi_num]);

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	// fen 3k1ab2/4a4/9/9/3P4p/1C4C2/P3c4/9/4c4/5KB2 b - - 0 1
	if((my_shi_num + my_xiang_num) >= 1){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK4){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
		MY_EV_ADD(EV_MY_CAN * 16);
	}

	MY_EV_ADD(EV_MY_CAN * 16);
}

//void m_MT_B_2pao3pawn_R_2pao1pawn(typePOS &POSITION, EvalInfo &ei){
//	/*
//    Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_2Pao1Pawn_2PaoXPawn_ByPawnShi[board->B_shi];
//		}
//	}
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2PaoXPawn_2Pao1Pawn_ByPawnShi[board->R_shi];
//		}
//	}
//
//	*/
//}
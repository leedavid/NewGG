#ifndef END_my_m_MT_R_2pao4pawn_B_2ma1pawn
#define END_my_m_MT_R_2pao4pawn_B_2ma1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2炮4兵对2马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_2pao4pawn_B_2ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2PaoXPawn_2Ma_ByPawnShi[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_2PaoXPawn_2Ma_ByPawnShi[my_shi_num]);

	int ycan = EV_YOUR_CAN;

	// fen 4k1b2/4a1c2/9/4P1N2/5Np2/4c2p1/9/p3B4/4A4/4KAB2 w - - 0 0
	if(my_shi_num <= 1 && ycan >= 1){
		MY_EV_SUB(ycan * (4- (my_shi_num + my_xiang_num)) * 80);
	}
}

//void m_MT_B_2pao4pawn_R_2ma1pawn(typePOS &POSITION, EvalInfo &ei){
//	/*
//    Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_2PaoXPawn_2Ma_ByPawnShi[board->B_shi];
//		}
//	}
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2PaoXPawn_2Ma_ByPawnShi[board->R_shi];
//		}
//	}
//
//	*/
//}
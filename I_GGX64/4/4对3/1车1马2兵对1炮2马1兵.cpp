#ifndef END_my_m_MT_R_1che1ma2pawn_B_1pao2ma1pawn
#define END_my_m_MT_R_1che1ma2pawn_B_1pao2ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1马2兵对1炮2马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1che1ma2pawn_B_1pao2ma1pawn(typePOS &POSITION, EvalInfo &ei){
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_CheMaXPawn_To_1Pao2Ma_ByPawn[your_shi_num]);
	
	
	// fen 2b6/4ak3/4ba3/9/1P7/6N1n/4PR3/3K4p/4A2c1/8c w - - 0 1
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	if(abs(StoX(ypawn) - 0x4) >= 3){
		MY_EV_ADD(16);
		MY_EV_ADD(EV_MY_CAN * 16);
	}
}

//void m_MT_B_1che1ma2pawn_R_1pao2ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	int bcan = BpawnCanOverLiver(board);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_CheMaXPawn_To_1Pao2Ma_ByPawn[board->R_shi];
//		}
//	}
//
//	if(board->B_shi == 2 && board->B_xiang == 2 && StoY(bk) == 0x3){
//		if(bcan >= 2){
//			if(Is_B_PawnControl_R_Ma(board)){
//				board->mulScore -= ADD_Che2PawnCan_PawnControlMa;
//			}
//		}
//	}
//
//
//	*/
//}



#ifndef END_my_m_MT_R_1pao2ma2pawn_B_2pao1ma1pawn
#define END_my_m_MT_R_1pao2ma2pawn_B_2pao1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮2马2兵对2炮1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int ADD_2Pao1MaXpawn_To_1Pao2Ma1Pawn_ByPawn[3]     = { 96, 64, 32};   //
//const int ADD_2Pao1Ma1pawn_To_1Pao2MaXPawn_ByPawn[3]     = { 96, 64, 32};   //


void my_m_MT_R_1pao2ma2pawn_B_2pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[my_shi_num]);

	// fen 2bak4/4a4/4b4/p1N4c1/4P4/5N3/2C1P4/3K5/6n2/2BA1A1c1 w - - 24 24
	int malr  = My_pawn_already_over_river(POSITION);
	int yalr  = Your_pawn_already_over_river(POSITION);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	MY_EV_ADD((malr - yalr) * 16);

	// fen 3k1ab2/4a4/9/3C2N2/4P1b2/2Bc4P/3N5/2n1K4/3p5/1c1A1AB2 w - - 0 1
	if(StoY(ypawn) MY_LARGE StoY(mk)){
		MY_EV_ADD(EV_MY_CAN * 16);
		if((my_shi_num + my_xiang_num) >= 3){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 4kab2/4ac3/4b4/3P1C3/7P1/6B2/1n7/1N2BA3/c3Ap3/4K2N1 b - - 0 1
	if (my_xiang_num == 2 && EV_MY_CAN == 2){
		if (abs(StoX(ypawn) - 0x4) == 4 && StoY(ypawn) MY_SMALL_EQL MY_RANK6){
			MY_EV_ADD(32);
		}
	}

	// fen 4kab2/4ac3/4b4/3P1C3/7P1/6B2/1n7/1N2BA3/c3Ap3/4K2N1 b - - 0 1
	if(EV_MY_CAN >= 2){
		if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
			if(StoY(ypawn) MY_LARGE_EQL MY_RANK8){
				if(StoX(ypawn) > 0x4 && PB90(MY_SQ44) == my_shi){
					MY_EV_ADD(32);
				}
				if(StoX(ypawn) < 0x4 && PB90(MY_SQ42) == my_shi){
					MY_EV_ADD(32);
				}
			}
		}
	}
}

//void m_MT_B_1pao2ma2pawn_R_2pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	Square rpawn = PieceListStart(board,RPAWN);
//	int bcan = BpawnCanOverLiver(board);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_2Pao1Ma1pawn_To_1Pao2MaXPawn_ByPawn[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1Pao2MaXpawn_To_2Pao1Ma1Pawn_ByPawn[board->R_shi];
//		}
//	}
//
//	// fen 2bak4/4a4/4b4/p1N4c1/4P4/5N3/2C1P4/3K5/6n2/2BA1A1c1 w - - 24 24
//	if(StoY(rpawn) >= 0x8 && bcan >= 0 && BpawnAlreadyRiver(board) >= 1){
//		board->mulScore -= bcan * 16;
//	}
//
//	*/
//}
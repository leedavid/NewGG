#ifndef END_my_m_MT_R_2pao2pawn_B_2pao1pawn
#define END_my_m_MT_R_2pao2pawn_B_2pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
#include "..\\..\\bitboard.h"
#include "..\\..\\endgame\mat.h"
#include "2ÅÚ2±ø¶Ô2ÅÚ1±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//ADD_2PaoXPawn_2Pao1Pawn_ByPawnShi


void my_m_MT_R_2pao2pawn_B_2pao1pawn(tipo_posizione *POSIZIONE, EvalInfo *ei){
	/*
	int rk = PieceListStart(board,RKING);
	int bk = PieceListStart(board,BKING);

	int rcan = RpawnCanOverLiver(board);
	int bcan = BpawnCanOverLiver(board);

	
	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
		if(StoY(from) > StoY(bk)){
			board->mulScore += ADD_2PaoXPawn_2Pao1Pawn_ByPawnShi[board->B_shi];
		}
	}

	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
		if(StoY(from) < StoY(rk)){
			board->mulScore -= ADD_2Pao1Pawn_2PaoXPawn_ByPawnShi[board->R_shi];
		}
	}

	//fen 3k5/4a4/4ba3/2p2C2c/2b1C1p2/2P5c/9/3A4B/4A4/3K2B2 b - - 120 120
	if(rcan <= 1 && bcan <= 1){
		if(board->B_shi == 2 && board->B_xiang == 2){
			if(board->R_shi == 2 && board->R_xiang == 2){
				return 4;
			}
		}
	}

	return 16;/*/
}

//void m_MT_B_2pao2pawn_R_2pao1pawn(tipo_posizione *POSIZIONE, EvalInfo *ei){
//	/*
//    int rk = PieceListStart(board,RKING);
//	int bk = PieceListStart(board,BKING);
//
//	int rcan = RpawnCanOverLiver(board);
//	int bcan = BpawnCanOverLiver(board);
//
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
//	//fen 3k5/4a4/4ba3/2p2C2c/2b1C1p2/2P5c/9/3A4B/4A4/3K2B2 b - - 120 120
//	if(bcan <= 1 && rcan <= 1){
//		if(board->B_shi == 2 && board->B_xiang == 2){
//			if(board->R_shi == 2 && board->R_xiang == 2){
//				return 4;
//			}
//		}
//	}
//
//	return 16;/*/
//}
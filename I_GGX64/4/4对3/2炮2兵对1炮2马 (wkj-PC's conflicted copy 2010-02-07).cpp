#ifndef END_my_m_MT_R_2pao2pawn_B_1pao2ma
#define END_my_m_MT_R_2pao2pawn_B_1pao2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
#include "..\\..\\bitboard.h"
#include "..\\..\\endgame\mat.h"
#include "2炮2兵对1炮2马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//ADD_1PaoXPawn_1PaoXPawn_ByShi

void my_m_MT_R_2pao2pawn_B_1pao2ma(tipo_posizione *POSIZIONE, EvalInfo *ei){
/*
	int rk = PieceListStart(board,RKING);
	int bk = PieceListStart(board,BKING);

	//int rcan = RpawnAlreadyRiver(board);
	//int bcan = BpawnAlreadyRiver(board);
	
	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
		if(StoY(from) > StoY(bk)){
			board->mulScore += ADD_1pao2ma_2paoXpawn_ByShi[board->B_shi];
		}
	}

	//for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
	//	if(StoY(from) < StoY(rk)){
	//		board->mulScore -= ADD_2pao1ma_2pao1pawn_ByShi[board->R_shi];
	//	}
	//}

	//board->mulScore += rcan * 64;
	//board->mulScore -= bcan * 64;

	return 16;/*/
}

//void m_MT_B_2pao2pawn_R_1pao2ma(tipo_posizione *POSIZIONE, EvalInfo *ei){
///*
//	int rk = PieceListStart(board,RKING);
//	int bk = PieceListStart(board,BKING);
//
//	//int rcan = RpawnAlreadyRiver(board);
//	//int bcan = BpawnAlreadyRiver(board);
//	//
//	//for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//	//	if(StoY(from) > StoY(bk)){
//	//		board->mulScore += ADD_2pao1ma_2pao1pawn_ByShi[board->B_shi];
//	//	}
//	//}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1pao2ma_2paoXpawn_ByShi[board->R_shi];
//		}
//	}
//
//
//	//board->mulScore += rcan * 64;
//	//board->mulScore -= bcan * 64;
//
//	return 16;/*/
//}
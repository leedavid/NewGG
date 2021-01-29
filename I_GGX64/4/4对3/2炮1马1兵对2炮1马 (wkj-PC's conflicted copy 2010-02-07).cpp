#ifndef END_my_m_MT_R_2pao1ma1pawn_B_2pao1ma
#define END_my_m_MT_R_2pao1ma1pawn_B_2pao1ma
#include "../../chess.h"
#include "../../preGen.h"
#include "../../bitboard.h"
#include "../../endgame/mat.h"
#include "2炮1马1兵对2炮1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



void my_m_MT_R_2pao1ma1pawn_B_2pao1ma(tipo_posizione *POSIZIONE, EvalInfo *ei){
/*
	int rk = PieceListStart(board,RKING);
	int bk = PieceListStart(board,BKING);
	
	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
		if(StoY(from) > StoY(bk)){
			board->mulScore += ADD_2Pao1MaXpawn_To_2Pao1Ma_ByPawn[board->B_shi];
		}

	}

	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
		if(StoY(from) < StoY(rk)){
			board->mulScore -= ADD_2Pao1Ma_To_2Pao1MaXpawn_ByPawn[board->R_shi];
		}
	}

	//fen 4k4/2c1a4/3ab4/N7N/2b6/8P/1n3C3/4B4/4AK3/1cBA5 b - - 4 4
	if(board->R_xiang == 2 && board->R_shi == 2 && StoY(rk) >= 0xb){
		board->mulScore += 64;
	}




	return 16;/*/
}

//void m_MT_B_2pao1ma1pawn_R_2pao1ma(tipo_posizione *POSIZIONE, EvalInfo *ei){
///*
//	int rk = PieceListStart(board,RKING);
//	int bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_2Pao1Ma_To_2Pao1MaXpawn_ByPawn[board->B_shi];
//		}
//
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2Pao1MaXpawn_To_2Pao1Ma_ByPawn[board->R_shi];
//		}
//	}
//
//	if(board->B_xiang == 2 && board->B_shi == 2 && StoY(bk) <= 0x4){
//		board->mulScore -= 64;
//	}
//
//
//
//	return 16;/*/
//}
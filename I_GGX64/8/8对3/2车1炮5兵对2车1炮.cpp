#ifndef END_my_m_MT_R_2che1pao5pawn_B_2che1pao
#define END_my_m_MT_R_2che1pao5pawn_B_2che1pao
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2车1炮5兵对2车1炮.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

#pragma warning(disable : 4100) 
void my_m_MT_R_2che1pao5pawn_B_2che1pao(typePOS &POSITION, EvalInfo &ei){
/*
	Square rk = PieceListStart(board,RKING);
	Square bk = PieceListStart(board,BKING);
	
	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
		if(StoY(from) > StoY(bk)){
			board->mulScore += ADD_MT_2che1pao1pawn_2che1pao_ByShi[board->B_shi];
		}
	}

	*/
}

//void m_MT_B_2che1pao5pawn_R_2che1pao(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_MT_2che1pao1pawn_2che1pao_ByShi[board->R_shi];
//		}
//	}
//
//	*/
//}
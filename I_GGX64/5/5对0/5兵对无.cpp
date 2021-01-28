#ifndef END_my_m_MT_R_5pawn
#define END_my_m_MT_R_5pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "5兵对无.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//我方3兵，对方 0 attacker
void my_m_MT_R_5pawn(typePOS &POSITION, EvalInfo &ei){

	BothOnlyPawnEval(POSITION,ei);
}

//我方3兵，对方 0 attacker
//void m_MT_B_5pawn(typePOS &POSITION, EvalInfo &ei){
///*
//    BothOnlyPawnEval(board);
//	int UpKing = 0;
//
//	Square rk = PieceListStart(board,RKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			UpKing ++;
//			board->mulScore -=  ADD_Only_Pawn_NoCheMaPaoByShi[board->R_shi];
//		}
//	}
//
//	if(UpKing == 0){
//		if(board->R_xiang != 0){
//			board->mulScore = 0;
//			return 1;
//		}
//	}
//
//	*/
//}
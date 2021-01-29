#ifndef END_my_m_MT_R_1ma1pao4pawn_B_1pao1pawn
#define END_my_m_MT_R_1ma1pao4pawn_B_1pao1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1马1炮4兵对1炮1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//
//const int  ADD_MAPAO_Xpawn_To_PAO1Pawn[3]           = {96, 64, 32};            //马炮对炮的优势分
//const int  ADD_PAO1Pawn_To_MAPAO_Xpawn[3]           = {96, 64, 32};            //马炮对炮的优势分


void my_m_MT_R_1ma1pao4pawn_B_1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_MAPAO_Xpawn_To_PAO1Pawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_PAO1Pawn_To_MAPAO_Xpawn[my_shi_num]);

	MY_EV_ADD(64);
}

//void m_MT_B_1ma1pao4pawn_R_1pao1pawn(typePOS &POSITION, EvalInfo &ei){
///*	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= ADD_MAPAO_Xpawn_To_PAO1Pawn[board->R_shi];
//		}
//
//	}
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > 0x3){
//			board->mulScore += ADD_PAO1Pawn_To_MAPAO_Xpawn[board->B_shi];
//		}
//
//	}
//
//	//board->mulScore -= ADD_MAPAO_Xpawn_To_PAO1Pawn ;
//
//	*/
//}
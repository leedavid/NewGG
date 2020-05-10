#ifndef END_my_m_MT_R_1pao_1ma4pawn_B_1pao
#define END_my_m_MT_R_1pao_1ma4pawn_B_1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1ÅÚ1Âí4±ø¶Ô1ÅÚ.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 





void my_m_MT_R_1pao_1ma4pawn_B_1pao(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao1MaXPawn_TO_PaoByPawnShi[your_shi_num]);

	MY_EV_ADD(ADD_MAPAO_Xpawn_To_PAO);
}

//void m_MT_B_1pao_1ma4pawn_R_1pao(typePOS &POSITION, EvalInfo &ei){
//	/*
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= ADD_1Pao1MaXPawn_TO_PaoByPawnShi[board->R_shi];
//		}
//	}
//	board->mulScore -= ADD_MAPAO_Xpawn_To_PAO ;
//	*/
//}
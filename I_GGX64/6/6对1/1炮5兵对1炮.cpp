#ifndef END_my_m_MT_R_1pao5pawn_B_1pao
#define END_my_m_MT_R_1pao5pawn_B_1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1ез5╠Ь╤т1ез.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//1ез3╠Ь╤т1ез
void my_m_MT_R_1pao5pawn_B_1pao(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1PaoXPawn_1Pao_ByPawn[your_shi_num]);

}

//void m_MT_B_1pao5pawn_R_1pao(typePOS &POSITION, EvalInfo &ei){
///*
//	int    rk      = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -=  ADD_1PaoXPawn_1Pao_ByPawn[board->R_shi];
//		}
//	}
//
//	//premat_t* pMat = board->pMat;
//	//uint16 Info16  = pMat->sixiangInfo8;
//	
//
//	//if((Info16 & CK_R_2s) && (Info16 & CK_R_2x)){
//	//	return 16;
//	//}
//
//	//if(board->R_shi == 2 && board->R_xiang == 2){
//	//	return 12;
//	//}
//
//	*/
//}
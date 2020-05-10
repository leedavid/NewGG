#ifndef END_my_m_MT_R_1PAO3PAWN_B_1PAO
#define END_my_m_MT_R_1PAO3PAWN_B_1PAO
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1ез3╠Ь╤т1ез.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//1ез3╠Ь╤т1ез
void my_m_MT_R_1PAO3PAWN_B_1PAO(typePOS &POSITION, EvalInfo &ei){

	Square yk   = your_king_pos;
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1PaoXPawn_1Pao_ByPawn[your_shi_num]);

	// fen C1bak4/4c4/3ab4/9/3P5/8P/P8/9/4A4/4KAB2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK2])){
			MY_EV_SUB(96);
		}
		if(StoY(ypao) MY_SMALL_EQL MY_RANK2){
			MY_EV_SUB(64);
		}
	}
}

//void m_MT_B_1PAO3PAWN_R_1PAO(typePOS &POSITION, EvalInfo &ei){
///*
//	int    rk      = PieceListStart(board,RKING);
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
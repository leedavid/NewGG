#ifndef END_my_m_MT_R_1pao5pawn_B_1ma
#define END_my_m_MT_R_1pao5pawn_B_1ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮5兵对1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//炮4兵对1马
void my_m_MT_R_1pao5pawn_B_1ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1PaoXPawn_1Ma_ByPawn[your_shi_num]);
}

//void m_MT_B_1pao5pawn_R_1ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -=  ADD_1PaoXPawn_1Ma_ByPawn[board->R_shi];
//		}
//
//	}
//
//	//premat_t* pMat = board->pMat;
//	//uint16 Info16  = pMat->sixiangInfo8;
//	//int    rk      = PieceListStart(board,BKING);
//
//	//if((Info16 & CK_R_2s) && (Info16 & CK_R_2x)){
//	//	return 14;
//	//}
//
//	*/
//}
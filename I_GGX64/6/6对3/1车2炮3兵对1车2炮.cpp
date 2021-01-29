#ifndef END_my_m_MT_R_1che2pao3pawn_B_1che2pao
#define END_my_m_MT_R_1che2pao3pawn_B_1che2pao
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车2炮3兵对1车2炮.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1che2pao3pawn_B_1che2pao(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1che2pao1pawn_1che2pao_ByShi[your_shi_num]);

	// fen 3k1ab2/4a2c1/4c3b/3r5/2C4C1/2R1P1P2/P8/4B4/4K4/2B2A3 b - - 0 1
	if(my_xiang_num == 2){
		MY_EV_ADD(EV_MY_CAN * 16);
	}
	MY_EV_ADD(EV_MY_CAN * 16);
}

//void m_MT_B_1che2pao3pawn_R_1che2pao(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);	
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1che2pao1pawn_1che2pao_ByShi[board->R_shi];
//		}
//	}
//
//
//
//	*/
//}
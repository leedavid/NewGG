#ifndef END_my_m_m_MT_R_1che2ma3pawn_B_1che1pao1ma1pawn 
#define END_my_m_m_MT_R_1che2ma3pawn_B_1che1pao1ma1pawn 
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车2马3兵对1车1炮1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1che2ma3pawn_B_1che1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){
	////
	//Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	//MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[your_shi_num]);
	////
	//Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	//MY_EV_SUB((sint16)count_1s(ymp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[my_shi_num]);

	// fen 2b1k4/4ac3/4ba3/9/6r1p/P1P2N3/2R5P/4B1N2/n3A4/2BAK4 w - - 0 0
	// 二个马同时给对方攻击了
	if(!m_have_bit(_mm_andnot_si128(YOUR_ATTACK,bb_my_ma))){
		//print_bb(YOUR_ATTACK);
		//print_bb(bb_my_ma);
		MY_EV_SUB(80);		
	}
}

//void m_MT_B_1che1pao4pawn_R_1pao2ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[board->R_shi];
//		}
//	}
//
//	*/
//}



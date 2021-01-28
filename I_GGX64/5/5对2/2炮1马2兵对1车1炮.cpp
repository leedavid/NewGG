#ifndef END_my_m_MT_R_2pao1ma2pawn_B_1che1pao
#define END_my_m_MT_R_2pao1ma2pawn_B_1che1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮1马2兵对1车1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2pao1ma2pawn_B_1che1pao(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2Pao1MaXPawn_1Che1Pao_To_ByPawn[your_shi_num]);



	// fen 3ak4/4a4/8b/9/5cb2/1N7/P3P4/B7C/3rA4/2CAK1B2 b - - 0 0
	// 兵方二个兵都在家，要扣分哇

	if((your_shi_num + your_xiang_num) >= 3){
		int malr = My_pawn_already_over_river(POSITION);
		if(malr == 0){
			MY_EV_SUB(96);
		}
	}

	
}

//void m_MT_B_2pao1ma2pawn_R_1che1pao(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2Pao1MaXPawn_1Che1Pao_To_ByPawn[board->R_shi];
//		}
//	}
//
//	Square bpawn1 = PieceListStart(board,BPAWN);
//	Square bpawn2 = NextPiece(board,bpawn1);
//
//	// fen 3ak4/4a4/8b/9/5cb2/1N7/P3P4/B7C/3rA4/2CAK1B2 b - - 0 0
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//		if(StoY(bpawn1) <= 0x7 && StoY(bpawn2) <= 0x7){
//			board->mulScore += 96;
//		}
//	}
//
//
//	*/
//}




//m_MT_R_2pao1ma1pawn_B_1che1pao(
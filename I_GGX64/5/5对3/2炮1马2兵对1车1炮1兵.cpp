#ifndef END_my_m_MT_R_2pao1ma2pawn_B_1che1pao1pawn
#define END_my_m_MT_R_2pao1ma2pawn_B_1che1pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮1马2兵对1车1炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_2pao1ma2pawn_B_1che1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoXPawn_To_2Pao1Ma_ByPawn[your_shi_num]);

	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_ChePaoXPawn_To_2Pao1Ma_ByPawn[my_shi_num]);

	// 如果多方没有兵过河，要减分
	// fen 1C2ka3/9/3ab4/C1p6/5c1r1/2P6/P4N3/4B4/4A4/2BAK4 w - - 0 1
	if(!have_bit(MyUpBB[MY_RANK5],bb_my_pawn)){
		MY_EV_SUB(32);
		if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			MY_EV_SUB(32);
		}
	}

}
//
//void m_MT_B_2pao1ma2pawn_R_1che1pao1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_ChePaoXPawn_To_2Pao1Ma_ByPawn[board->R_shi];
//		}
//	}
//
//	*/
//}



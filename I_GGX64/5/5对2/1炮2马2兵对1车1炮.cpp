#ifndef END_my_m_MT_R_1pao2ma2pawn_B_1che1pao
#define END_my_m_MT_R_1pao2ma2pawn_B_1che1pao
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮2马2兵对1车1炮.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



void my_m_MT_R_1pao2ma2pawn_B_1che1pao(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao2MaXPawn_1Che1Pao_To_ByPawn[your_shi_num]);

	// fen 4k4/4a4/4ba3/PN7/2b6/2Nr5/1c2P4/4B1C2/4A4/4KAB2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(64);
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
			MY_EV_SUB(64);
		}
		if(have_bit(bb_my_ma,MyLowBB[MY_RANK4])){
			MY_EV_SUB(32);
		}
	}
}

//void m_MT_B_1pao2ma2pawn_R_1che1pao(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1Pao2MaXPawn_1Che1Pao_To_ByPawn[board->R_shi];
//		}
//	}
//
//	*/
//}




//m_MT_R_2pao1ma1pawn_B_1che1pao(
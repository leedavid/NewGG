#ifndef END_my_m_MT_R_2ma_1pawn_B_1pao
#define END_my_m_MT_R_2ma_1pawn_B_1pao
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2马1兵对1炮.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



void my_m_MT_R_2ma_1pawn_B_1pao(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2MaXPawn_1Pao[your_shi_num]);

	// fen 5kb2/2N1a1P2/5a1Nb/9/5c3/2B6/9/3ABA3/9/4K4 b - - 124 124
	if((your_xiang_num + your_shi_num) == 4 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(96);
		if(your_king_pos != MY_SQ04){
			RETRUN_MUL(8);
		}
	}
}

//void m_MT_B_2ma_1pawn_R_1pao(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2MaXPawn_1Pao[board->R_shi];
//		}
//	}
//
//	// fen 5kb2/2N1a1P2/5a1Nb/9/5c3/2B6/9/3ABA3/9/4K4 b - - 124 124
//	if(board->R_shi == 2 && board->R_xiang == 2){
//		if(StoY(rk) == 0xc && board->b256[0xc7] != RKING){
//			return 8;
//		}
//	}
//
//	*/
//}
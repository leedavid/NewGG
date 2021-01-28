#ifndef END_my_m_MT_R_2pao_1pawn_B_1pao
#define END_my_m_MT_R_2pao_1pawn_B_1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h" 
#include "..\\..\\endgame\mat.h"
#include "2炮1兵对1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_2pao_1pawn_B_1pao(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2PaoXPawn_1Pao[your_shi_num]);

	Square mpawn = S90_from_piecelist(POSITION, my_pawn, 0);
	Square ypao = S90_from_piecelist(POSITION, your_pao, 0);
	

	// fen 2b2P3/4k2c1/8b/9/9/2B6/4C4/4BA3/9/3AKC3 b - - 0 1
	if(StoY(mpawn) == MY_RANK0){
		if(your_xiang_num == 2 && StoY(yk) != MY_RANK0){
			RETRUN_MUL(4);
		}
	}

	// fen 4k4/3P2c2/b4a2b/9/9/9/4C4/5C3/9/3K5 b - - 0 1
	if (my_shi_num == 0 && my_xiang_num == 0) {
		if (your_shi_num >= 1 && your_xiang_num >= 1) {
			if (StoY(mpawn) MY_SMALL_EQL MY_RANK1) {
				if (!IsOnSameSide(mpawn, ypao) && StoY(ypao) == MY_RANK1) {
					RETRUN_MUL(8);
				}
			}
		}
	}


}

//void m_MT_B_2pao_1pawn_R_1pao(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2PaoXPawn_1Pao[board->R_shi];
//		}
//
//	}
//
//	*/
//}

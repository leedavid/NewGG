#ifndef END_my_m_MT_R_1che1pao1ma1pawn_B_1che2pao
#define END_my_m_MT_R_1che1pao1ma1pawn_B_1che2pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮1马1兵对1车2炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che1pao1ma1pawn_B_1che2pao(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	Square mma = S90_from_piecelist(POSITION,my_ma,0);
	Square mpawn = S90_from_piecelist(POSITION, my_pawn, 0);
	MY_EV_ADD(pmok * ADD_1che1pao1ma1pawn_1che2pao_ByShi[your_shi_num]);

	if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) == MY_RANK9){
		MY_EV_ADD(16);
		if(StoY(mma) MY_SMALL_EQL MY_RANK5){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	// fen 3k2b2/9/3ab3c/4C4/4P2r1/2N6/9/3A2R2/4K3c/9 b - - 0 1
	if (StoY(mpawn) MY_SMALL_EQL MY_RANK4){
		MY_EV_ADD(32);
		if ((your_shi_num + your_xiang_num) <= 3){
			MY_EV_ADD(32);
			if (StoY(mma) MY_SMALL_EQL MY_RANK5){
				MY_EV_ADD(32);
			}
		}
	}
	
}

//void m_MT_B_1che1pao1ma1pawn_R_1che2pao(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);	
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1che1pao1ma1pawn_1che2pao_ByShi[board->R_shi];
//		}
//	}
//
//
//
//	*/
//}
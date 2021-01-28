#ifndef END_my_m_MT_R_1che1ma3pawn_B_1che1pao
#define END_my_m_MT_R_1che1ma3pawn_B_1che1pao
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1马3兵对1车1炮.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



void my_m_MT_R_1che1ma3pawn_B_1che1pao(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mma = S90_from_piecelist(POSITION, my_ma, 0);
	Square ypao = S90_from_piecelist(POSITION, your_pao, 0);
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheMaPawn_ChePao_ByPawnByShi[your_shi_num]);

	// fen 5k3/9/9/p4r2p/3R5/n1B6/5p3/2C6/4A4/2B1KA3 b - - 0 1
	if((my_shi_num + my_xiang_num) == 0){
		if((your_shi_num + your_xiang_num) >= 1){
		    MY_EV_SUB(64);
		}
	}

	// fen 2bak1b2/4a4/9/8R/4P4/7NP/P8/9/c3K4/8r b - - 0 1
	if (StoY(mma) MY_SMALL_EQL MY_RANK5){
		if (have_bit(bb_my_pawn, MyUpBB[MY_RANK5])){
			if (StoY(ypao) MY_LARGE_EQL MY_RANK4){
				MY_EV_ADD(EV_MY_CAN * 16);
			}
		}
	}
    

	// fen 3ak1b2/4a4/4b4/4R4/8P/P5P2/4c4/4r4/4N4/3AKA3 b
//	Square ypao =  S90_from_piecelist(POSITION,your_pao,0);
	if(bit_is_set(ei.attacked_by(my_che),ypao) && bit_is_set(ei.attacked_by(your_che),ypao)){
		MY_EV_ADD(EV_MY_CAN * 64);
	}

	//fen 2bak1b2/4a4/9/8R/4P4/7NP/P8/9/c3K4/8r b - - 0 1
	if (StoY(ypao) MY_LARGE_EQL MY_RANK4){
		MY_EV_ADD(EV_MY_CAN * 8);
		if (StoY(mma) MY_SMALL_EQL MY_RANK5){
			MY_EV_ADD(16);
		}
	}
}

//void m_MT_B_1che1ma3pawn_R_1che1pao(typePOS &POSITION, EvalInfo &ei){
//	/*
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= ADD_CheMaPawn_ChePao_ByPawnByShi[board->R_shi];
//		}
//
//	}
//
//	*/
//}

// fen 3a1kb2/9/5c2b/3NP1R2/9/8P/P1r6/9/5K3/9 b - - 12 12 
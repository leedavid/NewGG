#ifndef END_my_m_MT_R_4pawn_B_3pawn
#define END_my_m_MT_R_4pawn_B_3pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "4兵对3兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_4pawn_B_3pawn(typePOS &POSITION, EvalInfo &ei){
    
	BothOnlyPawnEval(POSITION,ei);

	// fen 3ak4/9/4ba3/p1p5p/6b2/P1Pp4P/9/B3B4/3KA4/5A3 b - - 11 11
	int mcan = EV_MY_CAN;
	int ycan = EV_YOUR_CAN;

	if((your_shi_num + your_xiang_num) == 4 && ycan == 0 && mcan <= 1){
		Bitboard bb = m_and(RankBB_A[MY_RANK4],bb_your_pawn);
		if(count_1s(bb) == 3){			
			bb = m_and(MyUpBB[MY_RANK5],bb_my_pawn);
			if(count_1s(bb) <= 1){
				RETRUN_MUL(2);
			}
		}
	}
}

//void m_MT_B_4pawn_R_3pawn(typePOS &POSITION, EvalInfo &ei){
///*	BothOnlyPawnEval(board);
//
//	// fen 3ak4/9/4ba3/p1p5p/6b2/P1Pp4P/9/B3B4/3KA4/5A3 b - - 11 11
//	if(board->b256[0x63] == BPAWN && board->b256[0x83] == RPAWN
//		//&& board->b256[0x65] == BPAWN && board->b256[0x85] == RPAWN
//		&& board->b256[0x6b] == BPAWN && board->b256[0x8b] == RPAWN){
//			if(board->R_xiang == 2 && board->b256[0xa7] == RXIANG){
//				if(board->b256[0x84] != BPAWN && board->b256[0x8a] != BPAWN){
//					if((board->b256[0x65] == BPAWN && board->b256[0x85] == RPAWN)
//						|| (board->b256[0x69] == BPAWN && board->b256[0x89] == RPAWN)){
//					return 2;
//					}
//				}
//			}
//	}
//	
//	*/
//}
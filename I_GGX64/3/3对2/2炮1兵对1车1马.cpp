#ifndef END_my_m_MT_R_2pao1pawn_B_1che1ma
#define END_my_m_MT_R_2pao1pawn_B_1che1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮1兵对1车1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//2炮1兵对车炮
void my_m_MT_R_2pao1pawn_B_1che1ma(typePOS &POSITION, EvalInfo &ei){


	// fen 3a1kb2/2N1a4/5c2b/2R6/6p1c/9/9/3AB4/4A4/5K3 b - - 122 122
	if((my_shi_num + my_xiang_num) == 4 && StoY(my_king_pos) == MY_RANK9){
		Square mpao1 = S90_from_piecelist(POSITION,my_pao,0);
		Square mpao2 = S90_from_piecelist(POSITION,my_pao,1);

		if(StoY(mpao1) MY_LARGE_EQL MY_RANK5 && StoY(mpao2) MY_LARGE_EQL MY_RANK5){
			if(PB90(MY_SQ56) == my_shi && PB90(MY_SQ42) == my_pao){
				if(PB90(MY_SQ53) == my_xiang && PB90(MY_SQ3F) == my_xiang){
					RETRUN_MUL(4);
				}
			}
			if(PB90(MY_SQ54) == my_shi && PB90(MY_SQ44) == my_pao){
				if(PB90(MY_SQ57) == my_xiang && PB90(MY_SQ47) == my_xiang){
					RETRUN_MUL(4);
				}
			}
		}
	}
}

//void m_MT_B_2pao1pawn_R_1che1ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//	int bpao1 = PieceListStart(board,BPAO);
//	int bpao2 = NextPiece(board,bpao1);
//
//	// fen 3a1kb2/2N1a4/5c2b/2R6/6p1c/9/9/3AB4/4A4/5K3 b - - 122 122
//	if(board->B_shi == 2 && board->B_xiang == 2 && StoY(bk) == 0x3){
//		if(StoY(bpao1) <= 0x7 && StoY(bpao2) <= 0x7){
//		    if(board->b256[0x36] == BSHI && board->b256[0x58] == BPAO 
//				&& board->b256[0x39] == BXIANG && board->b256[0x5b] == BXIANG){
//					return 4;
//			}
//			if(board->b256[0x38] == BSHI && board->b256[0x56] == BPAO 
//				&& board->b256[0x35] == BXIANG && board->b256[0x53] == BXIANG){
//					return 4;
//			}
//		}
//	}
//
//	*/
//}

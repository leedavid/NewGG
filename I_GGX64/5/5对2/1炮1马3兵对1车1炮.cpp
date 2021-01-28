#ifndef END_my_m_MT_R_1ma1pao3pawn_B_1che1pao
#define END_my_m_MT_R_1ma1pao3pawn_B_1che1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马3兵对1车1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1ma1pao3pawn_B_1che1pao(typePOS &POSITION, EvalInfo &ei){
	
	// fen 2baka3/9/2n1b4/p3p4/2p4c1/9/6RC1/4BA3/9/2BAK4 w - - 0 0
	if((my_shi_num + my_xiang_num) == 4 && PB90(MY_SQ55) == my_king){
		Square ypao = S90_from_piecelist(POSITION,your_pao,0);
		Square mpao = S90_from_piecelist(POSITION,my_pao,0);
		if(StoY(ypao) != MY_RANK9 && PB90(MY_SQ3A) == my_pawn){
			if(PB90(MY_SQ3E) == my_pawn && PB90(MY_SQ33) == my_pawn){
				if(PB90(MY_SQ45) == my_ma && StoX(mpao) <= 0x4){
					RETRUN_MUL(4)
				}
			}
			if(PB90(MY_SQ36) == my_pawn && PB90(MY_SQ2F) == my_pawn){
				if(PB90(MY_SQ41) == my_ma && StoX(mpao) >= 0x4){
					RETRUN_MUL(4)
				}
			}
		}
	}
}
//
//void m_MT_B_1ma1pao3pawn_R_1che1pao(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk   = PieceListStart(board,BKING);
//    int rpao = PieceListStart(board,RPAO);
//	int bpao = PieceListStart(board,BPAO);
//
//    // fen 2baka3/9/2n1b4/p3p4/2p4c1/9/6RC1/4BA3/9/2BAK4 w - - 0 0
//	if(board->B_shi == 2 && board->B_xiang == 2 && bk == 0x37){
//		if(StoY(rpao) != 0x3 && board->b256[0x67] == BPAWN && StoY(bpao) <= 0x7 && StoY(bpao) < StoY(rpao)){
//			if(board->b256[0x55] == BMA && board->b256[0x63] == BPAWN && board->b256[0x75] == BPAWN){
//				if(StoX(bpao) > 0x7){
//					return 4;
//				}
//			}
//
//			if(board->b256[0x59] == BMA && board->b256[0x6b] == BPAWN && board->b256[0x79] == BPAWN){
//				if(StoX(bpao) < 0x7){
//					return 4;
//				}
//			}
//		}
//	}
//
//	//
//	*/
//}
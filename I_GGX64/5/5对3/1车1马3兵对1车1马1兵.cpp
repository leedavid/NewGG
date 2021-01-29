#ifndef END_my_m_MT_R_1che1ma3pawn_B_1che1ma1pawn
#define END_my_m_MT_R_1che1ma3pawn_B_1che1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1马3兵对1车1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

void my_m_MT_R_1che1ma3pawn_B_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheMaPawn_CheMa1pawn_ByPawnByShi[your_shi_num]);

	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_CheMaPawn_CheMa1pawn_ByPawnByShi[my_shi_num]);
	

	Square yma = S90_from_piecelist(POSITION,your_ma,0);

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) == MY_RANK9){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK7){
			MY_EV_ADD(EV_MY_CAN * 24);
		}
	}

	// fen 4kab2/4a4/2R1b4/9/r5p2/2P6/4P1n1P/4B1N2/4A4/3AK1B2 w - - 0 0
	if(My_pawn_already_over_river(POSITION) == 0){
		if((your_shi_num + your_xiang_num) == 4 
			&& StoY(yk) == MY_RANK0){
				if(PB90(MY_SQ45) == my_ma && PB90(MY_SQ3C) == your_ma){
					if(PB90(MY_SQ3A) == my_pawn && PB90(MY_SQ3E) == my_pawn){
						RETRUN_MUL(4);
					}
				}
				if(PB90(MY_SQ41) == my_ma && PB90(MY_SQ38) == your_ma){
					if(PB90(MY_SQ3A) == my_pawn && PB90(MY_SQ36) == my_pawn){
						RETRUN_MUL(4);
					}
				}
		}
	}

	// fen 2baka3/9/4b4/4nr2p/P8/4R3P/6P2/3A4N/9/3AK4 b - - 0 1
	if(my_shi_num == 2 || my_xiang_num == 2){
		if(StoY(mk) == MY_RANK9){
			if(EV_YOUR_CAN == 0){
				MY_EV_ADD(32);
				if(StoY(yma) MY_SMALL_EQL MY_RANK4){
					MY_EV_ADD(32);
				}
			}
		}
	}
}
//
//void m_MT_B_1che1ma3pawn_R_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_CheMaPawn_CheMa1pawn_ByPawnByShi[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_CheMaPawn_CheMa1pawn_ByPawnByShi[board->R_shi];
//		}
//	}
//
//	// fen 4kab2/4a4/2R1b4/9/r5p2/2P6/4P1n1P/4B1N2/4A4/3AK1B2 w - - 0 0
//	if(BpawnAlreadyRiver(board) == 0){
//		if(board->R_shi == 2 && board->R_xiang == 2){
//			if(board->b256[0x59] == BMA && board->b256[0x69] == RMA){
//				if(board->b256[0x67] == BPAWN && board->b256[0x6b] == BPAWN){
//					return 4;
//				}
//			}
//			if(board->b256[0x55] == BMA && board->b256[0x65] == RMA){
//				if(board->b256[0x67] == BPAWN && board->b256[0x63] == BPAWN){
//					return 4;
//				}
//			}
//		}
//	}
//
//
//
//	*/
//}
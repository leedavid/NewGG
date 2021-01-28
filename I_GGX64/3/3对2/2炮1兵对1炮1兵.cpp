#ifndef END_my_m_MT_R_2pao1pawn_B_1pao1pawn
#define END_my_m_MT_R_2pao1pawn_B_1pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮1兵对1炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_2pao1pawn_B_1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2PaoXPawn_1Pao1Ma_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_2PaoXPawn_1Pao1Ma_ByPawn[my_shi_num]);
	
	//Square yk = your_king_pos;
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	
	int ycan = EV_YOUR_CAN;

	
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){

		// fen 3ak4/Cc3P3/b2a5/9/9/2B6/4c4/4BA3/4Ap3/4K4 b - - 120 120
		if((StoX(mpawn) < 0x4 && PB90(MY_SQ15) == your_shi)
			|| (StoX(mpawn) > 0x4 && PB90(MY_SQ17) == your_shi)){
				if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
					if(ycan >= 1){
						RETRUN_MUL(4);
					}
				}
		}

		// fen 3k1ab2/4c4/3a5/4C4/2b1p4/9/c3P4/4B4/4A4/4KAB2 w - - 4 4
		if(PB90(MY_SQ31) == my_pawn && PB90(MY_SQ1F) == your_pawn){
			if(PB90(MY_SQ3A) == your_pao){
				RETRUN_MUL(4);
			}
		}

		// fen 5k3/4a4/b2ab4/3P5/3c5/6B2/4p3C/4BA3/4A2C1/4K4 w - - 65 65
		if(StoY(ypawn) == MY_RANK6){
			MY_EV_SUB(196);
		}
	}

	/*

	// fen 3k1ab2/4c4/3a5/4C4/2b1p4/9/c3P4/4B4/4A4/4KAB2 w - - 4 4
	if(board->B_shi == 2 && board->B_xiang == 2 && StoY(bk) <= 0x4){
		if(bpawn == 0x67 && rpawn == 0x87 && board->b256[0x97] == BPAO){
			return 4;
		}
	} */

}

//void m_MT_B_2pao1pawn_R_1pao1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bpawn = PieceListStart(board,BPAWN);
//	Square rpawn = PieceListStart(board,RPAWN);
//	Square rk = PieceListStart(board,RKING);
//
//	int bpao1 = PieceListStart(board,BPAO);
//	int bpao2 = NextPiece(board,bpao1);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > 0x3){
//			board->mulScore += 96;
//		}
//
//	}
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= 96;
//		}
//
//	}
//
//	// fen 3ak4/Cc3P3/b2a5/9/9/2B6/4c4/4BA3/4Ap3/4K4 b - - 120 120
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//		if((board->b256[0xa6] == RSHI && StoX(bpawn) <= 0x6)
//			|| (board->b256[0xa8] == RSHI && StoX(bpawn) >= 0x8)){
//			if(StoY(bpawn) >= 0xb){
//				if(StoY(rpawn) <= 0x7 && StoY(rpawn) > 0x3){
//					return 4;
//				}
//			}
//		}
//	}
//
//	// fen 3k1ab2/4c4/3a5/4C4/2b1p4/9/c3P4/4B4/4A4/4KAB2 w - - 4 4
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) >= 0xb){
//		if(bpawn == 0x77 && rpawn == 0x97 && board->b256[0x67] == RPAO){
//			return 4;
//		}
//	}
//
//	*/
//}
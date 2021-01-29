#ifndef END_my_m_MT_R_1ma2pawn_B_1pawn
#define END_my_m_MT_R_1ma2pawn_B_1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1马2兵对1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



void my_m_MT_R_1ma2pawn_B_1pawn(typePOS &POSITION, EvalInfo &ei){
	
	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1MaXPawn_1Pawn_ByPawnShi[your_shi_num]);

	MY_EV_ADD(ADD_1MaXPawn_1Pawn);

	// fen 5a3/4k1P2/2n1ba3/9/6b2/9/9/9/9/3K2p1p b - - 0 0
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mma = S90_from_piecelist(POSITION, my_ma, 0);


	if (StoY(ypawn) MY_LARGE_EQL MY_RANK5){
		if (count_1s(bb_my_pawn, RankBB_A[MY_RANK0]) == 2){
			RETRUN_MUL(1);
		}
	}

	// fen 5a3/2P1a2P1/3k4b/9/6b2/6B2/9/3NB4/4p4/3K5 w - - 0 1
	if (my_shi_num == 0 && StoY(mk) == MY_RANK9 && MY_SQ4C == ypawn){
		if (count_1s(_mm_and_si128(MyUpBB[StoY(yk)], bb_my_pawn)) == 2){
			if (your_xiang_num >= 1 && isStringByChe(POSITION, mk, mma, yk)){
				RETRUN_MUL(2);
			}
		}
	}

	if (StoY(ypawn) MY_LARGE_EQL MY_RANK5){

		// fen 4k4/1N2aP3/b2ab4/9/9/2P6/9/B7B/4K2p1/9 b - - 0 1
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(EV_MY_CAN <= 1){
				MY_EV_SUB(96);
				if(count_1s(bb_my_pawn,MyUpBB[MY_RANK2]) == 1){
					RETRUN_MUL(4);
				}
			}
		}
	}

	

}

//void m_MT_B_1ma2pawn_R_1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	//
//	Square rk = PieceListStart(board,RKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -=  ADD_1MaXPawn_1Pawn_ByPawnShi[board->R_shi];
//		}
//	}
//
//
//	board->mulScore -= ADD_1MaXPawn_1Pawn;
//
//	*/
//}
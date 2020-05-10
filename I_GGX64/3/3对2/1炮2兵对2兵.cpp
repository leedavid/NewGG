#ifndef END_my_m_MT_R_1pao2pawn_B_2pawn
#define END_my_m_MT_R_1pao2pawn_B_2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮2兵对2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1pao2pawn_B_2pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1PaoXPawn_To_2Pawn_ByPaoPawn[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1PaoXPawn_To_2Pawn_ByPawnSide[my_shi_num]);

	MY_EV_ADD(ADD_1PaoXPawn_2Pawn);

	

	if(my_shi_num >= 1){
		EV_MY_SAFE = true;
	}

	// fen 3P5/5P3/4k4/9/2b6/9/2p2p3/B2A5/4A4/3C1K3 b - - 0 35
	if (EV_MY_SAFE){
		if (your_xiang_num >= 1){
			if (count_1s(bb_my_pawn, MyUpBB[StoY(yk)]) == 2){
				if (have_bit(bb_my_pawn, RankBB_A[MY_RANK0])){
					if (count_1s(bb_your_pawn, RankBB_A[MY_RANK6]) == 2){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 4k1PP1/4aC3/b2ab4/9/p8/9/p8/5A3/9/4KAB2 w - - 0 1
	if(EV_MY_SAFE){
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK0])){
			if(your_shi_num == 2 && your_xiang_num == 2 && have_bit(bb_your_pawn,RankBB_A[MY_RANK6])){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 2P1k4/4a4/9/5P3/6b2/3C5/5p1p1/4B4/4A4/3AK4 w - - 0 7
	if (EV_MY_SAFE){
		if (your_xiang_num >= 1 && your_shi_num >= 1){
			if (count_1s(bb_your_pawn, RankBB_A[MY_RANK6]) == 2){
				if (have_bit(bb_my_pawn, RankBB_A[MY_RANK0])){
					MY_EV_SUB(128);
					if (have_bit(bb_my_pawn, LowBB[MY_RANK2])){
						RETRUN_MUL(8);
					}
					if (have_bit(LeftBB[0x4], bb_my_pawn) && have_bit(RightBB[0x4], bb_my_pawn)){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}
	
}


//void m_MT_B_1pao2pawn_R_2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore +=  ADD_1PaoXPawn_To_2Pawn_ByPawnSide[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -=  ADD_1PaoXPawn_To_2Pawn_ByPaoPawn[board->R_shi];
//		}
//	}
//
//
//	board->mulScore -= ADD_1PaoXPawn_2Pawn;
//
//	*/
//}



//const int  ADD_1PaoXPawn_2Pawn                      = 128;              //1炮x兵对2兵的加分
//const int  ADD_1PaoXPawn_To_2Pawn_ByPaoPawn[3]      = {96,  64, 32};
//const int  ADD_1PaoXPawn_To_2Pawn_ByPawnSide[3]     = {80,  48, 16};
#ifndef END_my_m_MT_R_1ma2pawn_B_3pawn
#define END_my_m_MT_R_1ma2pawn_B_3pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马2兵对3兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1ma2pawn_B_3pawn(typePOS &POSITION, EvalInfo &ei){
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1MaXPawn_3pawn_ShiAdd[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_3pawn_MaXPawn_ShiAdd[my_shi_num]);

	MY_EV_ADD(ADD_1MaXPawn_3Pawn);

	if (my_shi_num >= 1) {
		EV_MY_SAFE = true;
	}

	// fen 3ak4/4aP3/4b4/5P3/2b6/9/4N4/B8/1pp1p4/2B2K3 b - - 0 1
	MY_EV_ADD(EV_MY_CAN * 32);

	if(count_1s(bb_your_pawn,m_and(LeftBB[0x6],RightBB[0x2])) <= 1){
		MY_EV_ADD(EV_MY_CAN * 64);
	}

	//  fen 2b1ka3/4a4/4b4/2P6/8p/5N3/4p1p1P/3A5/9/2BAK4 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1) {
		if (EV_MY_CAN <= 1) {
			if (PB90(MY_SQ3E) == my_pawn && PB90(MY_SQ2C) == your_pawn) {
				if (PB90(MY_SQ3C) == your_pawn) {
					RETRUN_MUL(4);
				}
			}
			if (PB90(MY_SQ36) == my_pawn && PB90(MY_SQ24) == your_pawn) {
				if (PB90(MY_SQ38) == your_pawn) {
					RETRUN_MUL(4);
				}
			}
		}
	}
}

//void m_MT_B_1ma2pawn_R_3pawn(typePOS &POSITION, EvalInfo &ei){
//	/*
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore +=  ADD_3pawn_MaXPawn_ShiAdd[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1MaXPawn_3pawn_ShiAdd[board->R_shi];
//		}
//	}
//
//	board->mulScore -= ADD_1MaXPawn_3Pawn;    //马兵方的别外加分
//
//	*/
//
//}

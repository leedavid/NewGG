#ifndef END_my_m_MT_R_2pao2pawn_B_2ma2pawn
#define END_my_m_MT_R_2pao2pawn_B_2ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2ÅÚ2±ø¶Ô2Âí2±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_2pao2pawn_B_2ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2Pao2Pawn_To_2MaxPawn_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_2Pao2Pawn_To_2MaxPawn_ByPawn[my_shi_num]);


	// fen 2ba4C/4ak3/4b4/p8/3n5/2P2p3/P3P3n/4B4/4A1C2/2BAK4 b - - 0 1
	if(EV_MY_CAN == 0){
		MY_EV_SUB(EV_YOUR_CAN * 32);
	}

	// fen 5P3/4k4/b4P3/9/3n1C3/9/3p1n3/4C1p1B/4A4/3K1A3 b - - 0 1
	if (have_bit(bb_my_pawn, RankBB_A[MY_RANK0])){
		MY_EV_SUB(32);
		if (StoY(yk) != MY_RANK0){
			MY_EV_SUB(32);
		}
		if (EV_YOUR_CAN == 2){
			MY_EV_SUB(32);
		}
		if (have_bit(bb_your_pawn, RankBB_A[MY_RANK6])){
			MY_EV_SUB(32);
		}
	}


	// fen 4k3C/3Pa4/b3ban2/p7p/9/6B1P/9/3AB4/4An3/4KC3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && EV_MY_CAN <= 1){
		if(my_shi_num == 2 && my_xiang_num == 2 && EV_YOUR_CAN <= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			RETRUN_MUL(8);
		}
	}
}

//void m_MT_B_2pao2pawn_R_2ma2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_2Pao2Pawn_To_2MaxPawn_ByPawn[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2Pao2Pawn_To_2MaxPawn_ByPawn[board->R_shi];
//		}
//	}
//
//
//	*/
//}

//const int ADD_2Pao2Pawn_To_2PaoxPawn_ByPawn[3]           = { 96, 64, 32};
//const int ADD_2Pao2Pawn_To_1Pao1MaxPawn_ByPawn[3]        = { 96, 64, 32};
//const int ADD_2Pao2Pawn_To_2MaxPawn_ByPawn[3]            = { 96, 64, 32};
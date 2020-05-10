#ifndef END_my_m_MT_R_1pao1ma3pawn_B_1che2pawn
#define END_my_m_MT_R_1pao1ma3pawn_B_1che2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马3兵对1车2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int ADD_Che2Pawn_To_1Pao1MaXPawn_ByPawn[3]    =  { 96, 64, 32};  //车2兵,对1炮1马X兵
//const int ADD_1Pao1MaXPawn_To_Che2Pawn_ByPawn[3]    =  { 96, 64, 32};  //车2兵,对1炮1马X兵

void my_m_MT_R_1pao1ma3pawn_B_1che2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao1MaXPawn_To_Che2Pawn_ByPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_Che2Pawn_To_1Pao1MaXPawn_ByPawn[my_shi_num]);



	// fen 4kab2/9/4ba1n1/4p3p/p1p6/c4R3/4P3P/4B4/4A4/2BAK4 w - - 2 2
	//如果车方的二个兵都不能过河,就要减分哇

	int ycan = EV_YOUR_CAN;
	if(ycan == 0){
		MY_EV_ADD(ADD_Che2Pawn_Can0);
	}
	// fen 2ba1k3/3Pa1N2/4b4/5P2p/p8/9/5r2P/4B4/4A4/4K2C1 r
	if(EV_YOUR_CAN <= 1 && EV_MY_CAN >= 2){
		if(my_shi_num >= 1 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9){
			if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK4])){
				Bitboard mp = m_and(bb_my_pawn,MyUpBB[MY_RANK4]);
				if(count_1s(mp) >= 2){
					MY_EV_ADD(EV_MY_CAN * 32);
					if(StoX(yk) != 0x4){
						MY_EV_ADD(32);
					}
				}
			}
		}
	}

	// fen 4kab2/9/4ba1n1/4p3p/p1p6/c4R3/4P3P/4B4/4A4/2BAK4 w - - 2 2
}

//void m_MT_B_1pao1ma3pawn_R_1che2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//    Square rk    = PieceListStart(board,RKING);
//	Square bk    = PieceListStart(board,BKING);
//
//	int rcan  = RpawnCanOverLiver(board);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1Pao1MaXPawn_To_Che2Pawn_ByPawn[board->R_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_Che2Pawn_To_1Pao1MaXPawn_ByPawn[board->B_shi];
//		}
//	}
//
//	// fen 3ak1b2/4a4/6n2/p3p3p/4c1b2/3R5/P7P/4B4/4A4/4KAB2 w - - 0 0
//	//马炮方仕相全,车方的兵没有办法过河,
//	if(rcan == 0 && board->B_shi == 2 && board->B_xiang == 2 && StoY(bk) == 0x3){
//		return 8;
//	}
//
//	*/
//}




//m_MT_R_1che3pawn_B_3pawn
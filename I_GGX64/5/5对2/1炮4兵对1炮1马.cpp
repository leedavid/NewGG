#ifndef END_my_m_MT_R_1pao4pawn_B_1pao1ma
#define END_my_m_MT_R_1pao4pawn_B_1pao1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮4兵对1炮1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


// 炮4兵对炮马
void my_m_MT_R_1pao4pawn_B_1pao1ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_PaoXPawn_To_1Pao1Ma_ByShi[your_shi_num]);

	// fen 3a5/4ak3/2P6/4P4/2b6/9/5C3/B4An2/3KA4/2B5c b - - 126 126
    //如果炮方是仕相全，且炮在二线以下，就要加分
	if((my_shi_num + my_xiang_num) == 4 && StoY(my_king_pos) MY_LARGE_EQL MY_RANK8){
		MY_EV_ADD(ADD_MAPAO_Xpawn_To_PAO2PawnNoSafe);
		// fen 2bk1a3/4a4/4b4/9/P2n4C/2P6/8P/4B4/4A4/4KABc1 b - - 0 1
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	// fen 5a3/4a1C2/3kc3b/9/2P6/8P/P3n1P2/4B4/4A4/4KAB2 w - - 0 1
	if((your_shi_num + your_xiang_num) >= 3){
		Bitboard mlowp = m_and(bb_my_pawn,MyLowBB[MY_RANK3]);
		MY_EV_SUB((sint16)count_1s(mlowp) * 32);
	}
}

//void m_MT_B_1pao4pawn_R_1pao1ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_PaoXPawn_To_1Pao1Ma_ByShi[board->R_shi];
//		}
//	}
//
//	if(board->B_shi == 2 && board->B_xiang == 2){
//		if(StoY(bk) <= 0x4){
//			board->bsafe = TRUE;
//		}
//	}
//
//	if(board->bsafe == FALSE){
//		board->mulScore += ADD_MAPAO_Xpawn_To_PAO2PawnNoSafe;
//	}
//	*/
//}
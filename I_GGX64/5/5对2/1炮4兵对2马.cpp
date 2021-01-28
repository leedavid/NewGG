
#ifndef END_my_m_MT_R_1pao4pawn_B_2ma
#define END_my_m_MT_R_1pao4pawn_B_2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮4兵对2马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



// 1炮4兵对2马
void my_m_MT_R_1pao4pawn_B_2ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_PaoXPawn_To_2MaByShi[your_shi_num]);

	//  fen 2ba5/4ak3/4b4/P7P/P6C1/9/7n1/2n1BA3/3KA4/6B2 b - - 0 1
	if (EV_MY_CAN >= 3) {
		MY_EV_ADD(EV_MY_CAN * 32);
	}
}

//void m_MT_B_1pao4pawn_R_2ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_PaoXPawn_To_2MaByShi[board->R_shi];
//		}
//	}
//	*/
//}
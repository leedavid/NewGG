#ifndef END_my_m_MT_R_1ma3pawn_B_2ma
#define END_my_m_MT_R_1ma3pawn_B_2ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1马3兵对2马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//


// 马兵对2马
void my_m_MT_R_1ma3pawn_B_2ma(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_MaPawn_To_2Ma_ByShi[your_shi_num]); 

	// fen 3k1ab2/9/9/2n6/6n2/2B3N2/P3P3P/3A1A3/9/2B1K4 b - - 0 1
	if (your_shi_num >= 1 && your_xiang_num >= 1){
		if (My_pawn_already_over_river(POSITION) <= 1){
			MY_EV_SUB(64);
		}
	}

	// 对方安全
	// fen 5a3/3P1P3/b2ak4/9/2b6/2Nn2B2/2n1P4/3K1A3/4A4/9 b - - 0 1

	if(count_1s(bb_my_pawn,MyUpBB[StoY(yk)]) == 2){
		if(my_shi_num == 2 && my_xiang_num >= 1 && PB90(MY_SQ3A) == my_pawn){
			RETRUN_MUL(8);
		}
	}
}
//
//void m_MT_B_1ma3pawn_R_2ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_MaPawn_To_2Ma_ByShi[board->R_shi];
//		}
//	}
//
//	*/
//}
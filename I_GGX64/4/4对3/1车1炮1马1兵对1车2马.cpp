#ifndef END_my_m_MT_R_1che1pao1ma1pawn_B_1che2ma
#define END_my_m_MT_R_1che1pao1ma1pawn_B_1che2ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1炮1马1兵对1车2马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1che1pao1ma1pawn_B_1che2ma(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1che1pao1ma1pawn_1che2ma_ByShi[your_shi_num]);


	// fen r3k1b2/2R1a4/4bC3/6n2/9/6N2/4Pn3/3A5/4A4/2BK5 w - - 0 1
	if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) == MY_RANK9){
		if((your_shi_num + your_xiang_num) <= 3){
			MY_EV_ADD(16);
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}
}

//void m_MT_B_1che1pao1ma1pawn_R_1che2ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);	
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1che1pao1ma1pawn_1che2ma_ByShi[board->R_shi];
//		}
//	}
//
//
//
//	*/
//}
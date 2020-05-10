#ifndef END_my_m_MT_R_1ma2pawn_B_2ma
#define END_my_m_MT_R_1ma2pawn_B_2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马2兵对2马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//


// 马2兵对2马
void my_m_MT_R_1ma2pawn_B_2ma(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_MaPawn_To_2Ma_ByShi[your_shi_num]);
	

	if(your_shi_num == 2){
		EV_YOUR_SAFE = TRUE;
	}

	if(your_shi_num >= 1 && your_xiang_num == 2){
		EV_YOUR_SAFE = TRUE;
	}

	if(my_shi_num >= 1 && my_xiang_num == 2 && StoY(my_king_pos) MY_LARGE_EQL MY_RANK8){
		EV_MY_SAFE = TRUE;
	}

	

	// fen 4k4/1P1P5/b2a1a3/9/9/9/7n1/3AB1nN1/4AK3/9 b - - 120 120
	if((my_shi_num + my_xiang_num) >= 3 && StoY(my_king_pos) MY_LARGE_EQL MY_RANK8){
		EV_MY_SAFE = TRUE;
	}
	
}

//void m_MT_B_1ma2pawn_R_2ma(typePOS &POSITION, EvalInfo &ei){
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
//	if(board->R_shi == 2){
//		board->rsafe = TRUE;
//	}
//
//	if(board->R_shi >= 1 && board->R_xiang == 2){
//		board->rsafe = TRUE;
//	}
//
//	if(board->B_shi >= 1 && board->B_xiang == 2 && StoY(bk) <= 0x4){
//		board->bsafe = TRUE;
//	}
//
//	// fen 4k4/1P1P5/b2a1a3/9/9/9/7n1/3AB1nN1/4AK3/9 b - - 120 120
//	if((board->B_shi  + board->B_xiang) >= 3){
//		if(StoY(bk) <= 0x4){
//			board->bsafe = TRUE;
//		}
//	}
//
//
//	*/
//}
#ifndef END_my_m_MT_R_1pao2pawn_B_2ma
#define END_my_m_MT_R_1pao2pawn_B_2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮2兵对2马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


// 1炮2兵对2马
void my_m_MT_R_1pao2pawn_B_2ma(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_PaoXPawn_To_2MaByShi[your_shi_num]);	

	Square mk = my_king_pos;

	// fen 3k5/4ac3/9/1N7/p1b2Nb2/2B3B2/9/3AK4/5p3/3A5 w - - 121 
	if(my_shi_num >= 1 && my_xiang_num == 2){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			EV_MY_SAFE = TRUE;
		}
	}
	
	if(your_shi_num == 2 || (your_shi_num + your_xiang_num) >= 3){
		EV_YOUR_SAFE = TRUE;
	}

	if(pmok <= 1){
		EV_YOUR_SAFE = TRUE;
	}
}

//void m_MT_B_1pao2pawn_R_2ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	Square bpawn1 = PieceListStart(board,BPAWN);
//	Square bpawn2 = NextPiece(board,bpawn1);
//
// 
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_PaoXPawn_To_2MaByShi[board->R_shi];
//		}
//	}
//
//	if(board->B_shi >= 1 && board->B_xiang == 2 ){
//
//		if(StoY(bk) <= 0x4){
//		  board->bsafe = TRUE;
//		}
//
//		//if(StoY(bpawn1) > StoY(rk) || StoY(bpawn2) > StoY(rk)){
//		//	 board->bsafe = TRUE;
//		//}
//	}
//
//	if(board->R_shi == 2 || (board->R_xiang + board->R_shi) >= 3){
//		board->rsafe = TRUE;
//	}
//
//	if(StoY(bpawn1) > StoY(rk) && StoY(bpawn2) > StoY(rk)){
//		board->rsafe = TRUE;
//	}
// 
//	*/
//}
#ifndef END_my_m_MT_R_1pao3pawn_B_1che1pawn
#define END_my_m_MT_R_1pao3pawn_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮3兵对1车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//1炮2兵对1车1兵, 炮马方要加分

void my_m_MT_R_1pao3pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	//如果没有过河,或者马炮方有仕
	if((my_shi_num + my_xiang_num) == 4 && PB90(MY_SQ55) == my_king){
		EV_MY_SAFE = TRUE;
	}



	if(EV_MY_SAFE){
		// ADD_MY
		Square yk = your_king_pos;
		Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
		int pmok = (int)count_1s(bmp);
		MY_EV_ADD(pmok * ADD_PaoXPawn_To_ChePawnByShi_WpaoSafe[your_shi_num]);

		RETRUN_MUL(4);
	}

	
}
//
//
//void m_MT_B_1pao3pawn_R_1che1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	//如果没有过河,或者马炮方有仕
//    bool isSafe = FALSE;
//
//	int  bpao = PieceListStart(board,BPAO);
//	int  rk   = PieceListStart(board,RKING);
//
//	if(board->B_shi == 2 && board->B_xiang == 2){
//		if(board->b256[0x57] == BXIANG){
//			isSafe = TRUE;
//		}
//	}
//
//
//	if(isSafe){
//
//		for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//			if(StoY(from) < StoY(rk)){
//				board->mulScore -= ADD_PaoXPawn_To_ChePawnByShi_WpaoSafe[board->R_shi];
//			}
//		}
//
//		return 1;
//	}
//
//	*/
//}



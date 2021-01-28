#ifndef END_my_m_MT_R_1pao4pawn_B_1che1pawn
#define END_my_m_MT_R_1pao4pawn_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮4兵对1车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



//1炮2兵对1车1兵, 炮马方要加分

void my_m_MT_R_1pao4pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	//如果没有过河,或者马炮方有仕
	if((my_shi_num + my_xiang_num) == 4 && PB90(MY_SQ55) == my_king){
		EV_MY_SAFE = TRUE;
	}

	if(EV_MY_SAFE){
		// ADD
		Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
		MY_EV_ADD((sint16)count_1s(bmp) * ADD_PaoXPawn_To_ChePawnByShi_WpaoSafe[your_shi_num]);
	}

	// fen 3ak1b2/4a4/4b4/rC4p1P/9/6P2/P3P4/8B/9/3AKA3 w - - 16 16
	if(my_shi_num == 2 && my_xiang_num >= 1 && PB90(MY_SQ55) == my_king){
		Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
		Square yche  = S90_from_piecelist(POSITION,your_che,0);
		if(StoY(ypawn) == MY_RANK3 && StoY(yche) MY_SMALL_EQL MY_RANK4){
			RETRUN_MUL(4);
		}
	}

}


//void m_MT_B_1pao4pawn_R_1che1pawn(typePOS &POSITION, EvalInfo &ei){
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
//	// fen 3ak1b2/4a4/4b4/rC4p1P/9/6P2/P3P4/8B/9/3AKA3 w - - 16 16
//	if(board->B_xiang >= 1 && board->B_shi == 2 && board->b256[0x37] == BKING){
//		if(board->b256[0x99] == RPAWN && board->b256[0x9a] == BPAWN
//			&& board->b256[0x79] == BPAWN){
//            return 4;
//		}
//		if(board->b256[0x95] == RPAWN && board->b256[0x94] == BPAWN
//			&& board->b256[0x75] == BPAWN){
//            return 4;
//		}
//	}
//
//	*/
//}



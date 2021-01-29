#ifndef END_my_m_MT_R_1ma4pawn_B_1ma2pawn
#define END_my_m_MT_R_1ma4pawn_B_1ma2pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1马4兵对1马2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//1马3兵对1炮2兵 //ADD_1PaoXPawn_1MaXPawn_ByShi

void my_m_MT_R_1ma4pawn_B_1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1MaXPawn_1MaXPawn_ByShi[your_shi_num]);

	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1MaXPawn_1MaXPawn_ByShi[my_shi_num]);

}

//void m_MT_B_1ma4pawn_R_1ma2pawn(typePOS &POSITION, EvalInfo &ei){	
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore +=  ADD_1MaXPawn_1MaXPawn_ByShi[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -=  ADD_1MaXPawn_1MaXPawn_ByShi[board->R_shi];;
//		}
//	}
//
//	//int a = rcan;
//	//int b = bcan;
//
//	//if(board->B_shi == 2 && board->B_xiang == 2){
//	//	if(board->R_shi == 2 && board->R_xiang == 2){
//	//		//if(StoY(rk) > 0xa && StoY(bk) < 0x
//	//		// fen 3akab2/9/4b4/p8/8p/2B1n4/P7P/2N1BA3/4Ap3/3K5 w - - 0 0
//	//		if(rcan <= 1 && bcan <= 1){
//	//			return 1;
//	//		}
//	//	}
//	//}
//
//	*/
//}
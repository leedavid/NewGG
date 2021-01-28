#ifndef END_my_m_MT_R_1che4pawn_B_2pawn
#define END_my_m_MT_R_1che4pawn_B_2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车4兵对2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1che4pawn_B_2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheXPawn_To_2PawnByShi[your_shi_num]);

	MY_EV_ADD(ADD_CheXPawn_To_2Pawn);
}

//void m_MT_B_1che4pawn_R_2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	//Square bk = PieceListStart(board,BKING);
//	//Square rk = PieceListStart(board,RKING);
//
//	////兵方要仕相全, 且兵连成线了
//	//if(board->R_shi == 2 && board->R_xiang == 2){
//	//	if(board->b256[0xa7] == RXIANG && StoY(rk) == 0xc){
//	//		//再看一下有没有连兵 在5线 
//	//		//再看一下 黑方有没有连兵 在5线 
//	//		for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//	//			if(StoX(from) == 0x7 && StoY(from) > StoY(bk)){
//	//				if(board->b256[from+1] == RPAWN || board->b256[from-1] == RPAWN){
//	//					return 1;
//	//				}
//	//			}
//	//		}
//
//	//	}
//	//}
//
//    Square rk = PieceListStart(board,RKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -=  ADD_CheXPawn_To_2PawnByShi[board->R_shi];
//		}
//	}
//
//	board->mulScore -= ADD_CheXPawn_To_2Pawn;
//
//	*/
//}
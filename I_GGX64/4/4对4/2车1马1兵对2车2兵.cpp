#ifndef END_my_m_MT_R_2che2pawn_B_2che2pawn
#define END_my_m_MT_R_2che2pawn_B_2che2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2车1马1兵对2车2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int ADD_2CheXPawn_1Che1Pao1Ma1Pawn_ByPawnShi[3]    = {96, 64, 32};            //2车x兵对1车1炮1马1兵, 兵方的加分
//const int ADD_1Che1Pao1Ma1Pawn_2CheXPawn_ByPawnShi[3]    = {96, 64, 32};            //1车1炮1马1兵对2车x兵, 兵方的加分

void my_m_MT_R_2che2pawn_B_2che2pawn(typePOS &POSITION, EvalInfo &ei){

	// fen 2b1ka3/4a4/4b1r2/6NRR/p5r2/9/P3p4/4B4/4A4/2B1KA3 b - - 0 0
	Square yk  = your_king_pos;
	Square mma = S90_from_piecelist(POSITION,my_ma,0);
	if(your_shi_num == 2 && yk == MY_SQ04 && EV_MY_CAN == 0){
		if(StoY(mma) == MY_RANK3){
			if(PB90(mma - 0x9) == your_che && PB90(mma + 0x9) == your_che){
				MY_EV_SUB(96);
			}
		}
	}

}

//void m_MT_B_2che2pawn_R_1che1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_1Che1Pao1Ma1Pawn_2CheXPawn_ByPawnShi[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2CheXPawn_1Che1Pao1Ma1Pawn_ByPawnShi[board->R_shi];
//		}
//	}
//
//	*/
//}
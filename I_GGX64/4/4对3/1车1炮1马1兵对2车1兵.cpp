#ifndef END_my_m_MT_R_1che1pao1ma1pawn_B_2che1pawn
#define END_my_m_MT_R_1che1pao1ma1pawn_B_2che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮1马1兵对2车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int ADD_2CheXPawn_1Che1Pao1Ma1Pawn_ByPawnShi[3]    = {96, 64, 32};            //2车x兵对1车1炮1马1兵, 兵方的加分
//const int ADD_1Che1Pao1Ma1Pawn_2CheXPawn_ByPawnShi[3]    = {96, 64, 32};            //1车1炮1马1兵对2车x兵, 兵方的加分

void my_m_MT_R_1che1pao1ma1pawn_B_2che1pawn(typePOS &POSITION, EvalInfo &ei){
	
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1Che1Pao1Ma1Pawn_2CheXPawn_ByPawnShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_2CheXPawn_1Che1Pao1Ma1Pawn_ByPawnShi[my_shi_num]);

	if(my_shi_num == 2 && mk == MY_SQ55){
	   int ycan = EV_YOUR_CAN;
	   if(ycan == 0){
		   MY_EV_ADD(EV_MY_CAN * ADD_1che1ma1paoXpawn_2che1pawnByCan);
	   }
	}
}

//void m_MT_B_1che1pao1ma1pawn_R_2che1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	int rcan = RpawnCanOverLiver(board);
//	int bcan = BpawnCanOverLiver(board);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_2CheXPawn_1Che1Pao1Ma1Pawn_ByPawnShi[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1Che1Pao1Ma1Pawn_2CheXPawn_ByPawnShi[board->R_shi];
//		}
//	}
//
//	if(board->B_shi == 2 && StoY(bk) == 0x3){
//		if(rcan == 0){
//			board->mulScore -= bcan*ADD_1che1ma1paoXpawn_2che1pawnByCan;
//		}
//	}
//
//	*/
//}
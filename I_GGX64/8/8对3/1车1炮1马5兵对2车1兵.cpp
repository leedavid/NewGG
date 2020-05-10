#ifndef END_my_m_MT_R_1che1pao1ma5pawn_B_2che1pawn
#define END_my_m_MT_R_1che1pao1ma5pawn_B_2che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮1马5兵对2车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


// fen 3k1a1R1/4a4/2n6/p1p5p/4p1R2/2P6/3rc4/4B4/4A4/2BA1K3 b - - 0 0
void my_m_MT_R_1che1pao1ma5pawn_B_2che1pawn(typePOS &POSITION, EvalInfo &ei){

	int mcan = EV_MY_CAN;
	int ycan = EV_YOUR_CAN;

	if(my_shi_num == 2 && StoY(my_king_pos) == MY_RANK9){
		if(ycan == 0){
			MY_EV_ADD(mcan * ADD_1che1ma1paoXpawn_2che1pawnByCan);
		}
	}
}

//void m_MT_B_1che1pao1ma5pawn_R_2che1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	int rcan = RpawnCanOverLiver(board);
//	int bcan = BpawnCanOverLiver(board);
//
//	Square bk = PieceListStart(board,BKING);
//
//	if(board->B_shi == 2 && StoY(bk) == 0x3){
//		if(rcan == 0){
//			board->mulScore -= bcan*ADD_1che1ma1paoXpawn_2che1pawnByCan;
//		}
//	}
//
//	*/
//}
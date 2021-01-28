#ifndef END_my_m_MT_R_1che1pao2pawn_B_2pao2ma
#define END_my_m_MT_R_1che1pao2pawn_B_2pao2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮2兵对2炮2马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1che1pao2pawn_B_2pao2ma(typePOS &POSITION, EvalInfo &ei){

	if((my_xiang_num + my_shi_num) >= 3){
		MY_EV_ADD(EV_MY_CAN * 32);
	}
}
//
//void m_MT_B_1che1pao2pawn_R_2pao2ma(typePOS &POSITION, EvalInfo &ei){
///*
//	int bcan = BpawnCanOverLiver(board);
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//
//
//	// fen 3ak1c2/3c2n2/3ab4/2R5N/2n2P1P1/2B6/9/9/4A4/4KA3 b - - 0 0
//	if((board->B_shi + board->B_xiang) >= 3){
//		board->mulScore -= bcan * 32;
//	}
//
//	if(board->B_shi == 2 && board->B_xiang == 2 && StoY(bk) == 0x3){
//		if(bcan >= 2){
//			if(Is_B_PawnControl_R_Ma(board)){
//				board->mulScore -= ADD_Che2PawnCan_PawnControlMa;
//			}
//		}
//	}
//
//
//	*/
//}
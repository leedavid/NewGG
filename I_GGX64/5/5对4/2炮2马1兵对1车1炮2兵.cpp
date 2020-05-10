#ifndef END_my_m_MT_R_2pao2ma1pawn_B_1che1pao2pawn
#define END_my_m_MT_R_2pao2ma1pawn_B_1che1pao2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2ÅÚ2Âí1±ø¶Ô1³µ1ÅÚ2±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};


void my_m_MT_R_2pao2ma1pawn_B_1che1pao2pawn(typePOS &POSITION, EvalInfo &ei){


	//Square yk = your_king_pos;
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	// fen C3ka3/2c1a4/4b4/5r3/6b2/P3p4/3p2N2/C3B1N2/4A4/2BAK4 b - - 0 1
    MY_EV_SUB(EV_YOUR_CAN * 16);
	if(!have_bit(bb_my_ma,MyUpBB[MY_RANK5])){
		MY_EV_SUB(EV_YOUR_CAN * 16);
	}
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(mpawn) MY_LARGE_EQL MY_RANK4){
		MY_EV_SUB(32);
	}

}

//void m_MT_B_2pao2ma1pawn_R_1che1pao2pawn(typePOS &POSITION, EvalInfo &ei){
//
//	/*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//
//	int rcan = RpawnCanOverLiver(board);
//
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//		if(rcan >= 2){
//			if(Is_R_PawnControl_B_Ma(board)){
//				board->mulScore += ADD_Che2PawnCan_PawnControlMa;
//			}
//		}
//	}
//	
//
//	*/
//
//}


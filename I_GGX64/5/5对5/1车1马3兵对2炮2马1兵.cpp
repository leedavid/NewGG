#ifndef END_my_m_MT_R_1che1ma3pawn_B_2pao2ma1pawn
#define END_my_m_MT_R_1che1ma3pawn_B_2pao2ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1马3兵对2炮2马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che1ma3pawn_B_2pao2ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;

	// fen 1c1k1a3/3na4/4bc3/1NPR5/6b1p/2P6/6n1P/4B4/4A4/2BAK4 w - - 0 1
	if((my_shi_num + my_xiang_num) == 4 && StoY(mk) == MY_RANK9){
		if(EV_YOUR_CAN == 0){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

}


//void m_MT_B_1che1ma3pawn_R_2pao2ma1pawn(typePOS &POSITION, EvalInfo &ei){
//
//	/*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	int bcan = BpawnCanOverLiver(board);
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
//
//}



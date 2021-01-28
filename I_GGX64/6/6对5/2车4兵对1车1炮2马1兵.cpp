#ifndef END_my_m_MT_R_2che4pawn_B_1che1pao2ma1pawn
#define END_my_m_MT_R_2che4pawn_B_1che1pao2ma1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2车4兵对1车1炮2马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan      =  32;                     //2车方有兵可过河，


void my_m_MT_R_2che4pawn_B_1che1pao2ma1pawn(typePOS &POSITION, EvalInfo &ei){
	int ycan = EV_YOUR_CAN;
	if(ycan == 0){
		if(my_shi_num == 2 && my_xiang_num == 2 && StoY(my_king_pos) == MY_RANK9){
			MY_EV_ADD(EV_MY_CAN * ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan);
		}
	}
}

//
//void m_MT_B_2che4pawn_R_1che1pao2ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//    Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//
//	int rcan = RpawnCanOverLiver(board);
//	int bcan = BpawnCanOverLiver(board);
//
//	if(rcan == 0){
//		if(board->B_shi == 2 && board->B_xiang == 2 && StoY(bk) == 0x3){
//			board->mulScore -= bcan * ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan;
//		}
//	}
//
//	*/
//}

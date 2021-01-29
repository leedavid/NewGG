#ifndef END_my_m_MT_R_1che1pao2ma1pawn_B_2che2pawn
#define END_my_m_MT_R_1che1pao2ma1pawn_B_2che2pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1炮2马1兵对2车2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//const int ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan      =  32;                     //2车方有兵可过河，


void my_m_MT_R_1che1pao2ma1pawn_B_2che2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
    int mcan = EV_MY_CAN;
	if(mcan == 0){
		if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
			int ycan = EV_YOUR_CAN;
			MY_EV_SUB(ycan * ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan);
		}
	}
}
//
//void m_MT_B_1che1pao2ma1pawn_R_2che2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//    Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//
//	int rcan = RpawnCanOverLiver(board);
//	int bcan = BpawnCanOverLiver(board);
//
//	if(bcan == 0){
//		if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//			board->mulScore += rcan * ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan;
//		}
//	}
//
//	*/
//}
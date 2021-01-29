#ifndef END_my_m_MT_R_1pao2ma3pawn_B_1che1pao1pawn
#define END_my_m_MT_R_1pao2ma3pawn_B_1che1pao1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮2马3兵对1车1炮1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 
#pragma warning(disable : 4100) 
void my_m_MT_R_1pao2ma3pawn_B_1che1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	//Square yche = S90_from_piecelist(POSITION,your_che,0);
	//int ycan = EV_YOUR_CAN;
	//if(ycan == 0){
	//	if(my_xiang_num == 2 && my_shi_num >=1 && StoY(my_king_pos) MY_LARGE_EQL MY_RANK8){
	//		if(StoY(yche) MY_SMALL_EQL MY_RANK4){
	//			MY_EV_ADD(My_pawn_can_over_river(POSITION) * ADD_3PaoMaTo1Che1PaoMa1PawnByPaoMaCan);
	//		}
	//	}
	//}
}

//void m_MT_B_1pao2ma3pawn_R_1che1pao1pawn(typePOS &POSITION, EvalInfo &ei){
//	/*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	int bcan = BpawnCanOverLiver(board);
//	int rcan = RpawnCanOverLiver(board);
//
//	int rche = PieceListStart(board,RCHE);
//
//	if(rcan == 0){
//		if(board->B_xiang == 2 && board->B_shi >= 1 && StoY(bk) <= 0x4){
//			if(StoY(rche) >= 0x8){
//				board->mulScore -= bcan * ADD_3PaoMaTo1Che1PaoMa1PawnByPaoMaCan;
//			}
//		}
//	}
//	
//	*/
//}


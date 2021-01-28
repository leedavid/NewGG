#ifndef END_my_m_MT_R_2pao1ma3pawn_B_1che1pao1pawn
#define END_my_m_MT_R_2pao1ma3pawn_B_1che1pao1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2炮1马3兵对1车1炮1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_2pao1ma3pawn_B_1che1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	int mcan = EV_MY_CAN;
	int ycan = EV_YOUR_CAN;

	if(my_xiang_num == 2 && my_shi_num >= 1 && StoY(my_king_pos) == MY_RANK9){
		if(ycan == 0){
			MY_EV_ADD(mcan * ADD_3PaoMaTo1Che1PaoMa1PawnByPaoMaCan);
		}
	}
}

//void m_MT_B_2pao1ma3pawn_R_1che1pao1pawn(typePOS &POSITION, EvalInfo &ei){
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


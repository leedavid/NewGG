#ifndef END_my_m_MT_R_2pao1ma3pawn_B_1che1ma1pawn
#define END_my_m_MT_R_2pao1ma3pawn_B_1che1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮1马3兵对1车1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_2pao1ma3pawn_B_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){
	int mcan = EV_MY_CAN;
	int ycan = EV_YOUR_CAN;

	Square yche = S90_from_piecelist(POSITION,your_che,0);

	// fen 4kab2/3Na4/2r6/C2P5/P7p/2C6/5n2P/3AB4/4A4/3K5 b - - 0 1
	if((my_xiang_num + my_shi_num) >= 3 && StoY(my_king_pos) == MY_RANK9){
		if(ycan == 0){
			MY_EV_ADD(mcan * ADD_3PaoMaTo1Che1PaoMa1PawnByPaoMaCan);
		}
		if(StoY(yche) MY_SMALL_EQL MY_RANK3){
			MY_EV_ADD(32);
		}
	}
}

//void m_MT_B_2pao1ma3pawn_R_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){
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


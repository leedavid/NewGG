#ifndef END_my_m_MT_R_1che2pao4pawn_B_1che1pao2ma
#define END_my_m_MT_R_1che2pao4pawn_B_1che1pao2ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车2炮4兵对1车1炮2马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

#pragma warning(disable : 4100) 
void my_m_MT_R_1che2pao4pawn_B_1che1pao2ma(typePOS &POSITION, EvalInfo &ei){
	
	//Square mk   = my_king_pos;

	////int mcan = EV_MY_CAN;
	////int malr = My_pawn_already_over_river(POSITION);

	//if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) == MY_RANK9){
	//	if(count_1s(
	//		m_and(bb_your_ma,MyUpBB[MY_RANK3])) == 2){
	//			if(My_pawn_already_over_river(POSITION) >= 1){
	//				MY_EV_ADD(My_pawn_can_over_river(POSITION) * ADD_1che1pao1maXpawn_B_1che1pao2ma_MaHome);
	//			}
	//	}
	//}
}


//void m_MT_B_1che2pao4pawn_R_1che1pao2ma(typePOS &POSITION, EvalInfo &ei){
///*
//
//	int rma1 = PieceListStart(board,RMA);
//	int rma2 = NextPiece(board,rma1);
//
//	
//	Square bk = PieceListStart(board,BKING);
//	int bcan = BpawnCanOverLiver(board);
//    int bal  = BpawnAlreadyRiver(board);
//
//
//	if((board->B_shi+board->B_xiang) >= 3 && StoY(bk) == 0x3){
//
//		if(StoY(rma1) >= 0xa && StoY(rma2) >= 0xa){
//			if(bal >= 1){
//				board->mulScore -= bcan * ADD_1che2paoXpawn_B_1che1pao2ma_MaHome;
//			}
//		}
//	}
//
//	*/
//}
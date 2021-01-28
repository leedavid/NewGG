#ifndef END_my_m_MT_R_1che2pao3pawn_B_1che1pao2ma
#define END_my_m_MT_R_1che2pao3pawn_B_1che1pao2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车2炮3兵对1车1炮2马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1che2pao3pawn_B_1che1pao2ma(typePOS &POSITION, EvalInfo &ei){
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

	Square mche = S90_from_piecelist(POSITION,my_che,0);

	// fen 2ba1ab2/4k4/9/4C3P/C2n1P3/5c3/P1c6/3AB4/2R6/1rB1KA3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
			MY_EV_SUB(32);
		}
		if(StoY(mche) MY_LARGE_EQL MY_RANK7){
			MY_EV_SUB(32);
		}
	}
}


//void m_MT_B_1che2pao3pawn_R_1che1pao2ma(typePOS &POSITION, EvalInfo &ei){
//
///*
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
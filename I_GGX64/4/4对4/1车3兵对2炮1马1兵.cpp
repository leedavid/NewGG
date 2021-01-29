#ifndef END_my_m_MT_R_1che3pawn_B_2pao1ma1pawn
#define END_my_m_MT_R_1che3pawn_B_2pao1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车3兵对2炮1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1che3pawn_B_2pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;

	// fen 2b1k4/4a4/4ba1N1/4pN3/1r7/C3P4/2p3p2/4B4/4A4/3AK1B2 w - - 50 50
	int mcan = EV_MY_CAN;
	int ycan = EV_YOUR_CAN;
	if((my_shi_num + my_xiang_num) >= 3 && StoY(my_king_pos) MY_LARGE_EQL MY_RANK8){
		if(mcan >= 2 && ycan == 0){
			MY_EV_ADD(mcan * ADD_1CheMore2Pawn_To_2Pao1ma1Pawn);
		}
	}

	// fen 2b2ab2/3ka4/c8/5Rn1p/9/7c1/P3P3P/4B4/4A4/2BAK4 b - - 0 1
	if(EV_YOUR_CAN == 0 && StoY(yk) != MY_RANK0){
		if((my_shi_num + my_xiang_num) >= 3){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	//  fen 4kabC1/C3a4/6P2/4r4/6b1N/p8/p4p3/4B4/4A4/3AK1B2 w - - 0 1
	if (EV_MY_CAN >= 2) {
		MY_EV_ADD(EV_MY_CAN * 16);
		
		Bitboard mgp = m_and(bb_my_pawn, MyUpBB[MY_RANK5]);
		MY_EV_ADD(count_1s(mgp) * 32);
	}
}
//
//void m_MT_B_1che3pawn_R_2pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//
//	int rcan = RpawnCanOverLiver(board);
//	int bcan = BpawnCanOverLiver(board);
//
//	// fen 2b1k4/4a4/4ba1N1/4pN3/1r7/C3P4/2p3p2/4B4/4A4/3AK1B2 w - - 50 50
//	if((board->B_shi + board->B_xiang) >= 3 && StoY(bk) <= 0x4){
//		if(bcan >= 2 && rcan == 0){
//			board->mulScore -= bcan * ADD_1CheMore2Pawn_To_2Pao1ma1Pawn;
//		}
//	}
//
//	*/
//}


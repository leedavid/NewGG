#ifndef END_my_m_MT_R_1che3pawn_B_1pao2ma1pawn
#define END_my_m_MT_R_1che3pawn_B_1pao2ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车3兵对1炮2马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che3pawn_B_1pao2ma1pawn(typePOS &POSITION, EvalInfo &ei){

	// fen 2b1k4/4a4/4ba1N1/4pN3/1r7/C3P4/2p3p2/4B4/4A4/3AK1B2 w - - 50 50
	int mcan = EV_MY_CAN;
	int ycan = EV_YOUR_CAN;

	//Square yk = your_king_pos;
	if((my_shi_num + my_xiang_num) >= 3 && StoY(my_king_pos) MY_LARGE_EQL MY_RANK8){
		if(mcan >= 2 && ycan == 0){
			MY_EV_ADD(mcan * ADD_1CheMore2Pawn_To_2Pao1ma1Pawn);
		}
	}

	// fen 2b2ab2/3ka4/c8/5Rn1p/9/7c1/P3P3P/4B4/4A4/2BAK4 b - - 0 1
	if(EV_YOUR_CAN == 0 ){
		if((my_shi_num + my_xiang_num) >= 3){
			MY_EV_ADD(EV_MY_CAN * 32);
		}

		// fen 3akab2/9/4b4/c3n3p/2P6/4P4/8P/B3B4/n1R1A4/3K1A3 w - - 0 1
		//if(EV_MY_CAN >= 2){
		//	MY_EV_ADD(32);
		//}

		//如果有边马，且被攻击了
		Bitboard bm = m_and(bb_your_ma,m_or(LeftBB[0x1],RightBB[0x7]));
		if(have_bit(bm,MY_ATTACK)){
			MY_EV_ADD(32);
		}
	}

}

//void m_MT_B_1che3pawn_R_1pao2ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//
//	int rcan = RpawnCanOverLiver(board);
//	int bcan = BpawnCanOverLiver(board);
//
//	// fen 2b1k4/4a4/4ba1N1/4pN3/1r7/C3P4/2p3p2/4B4/4A4/3AK1B2 w - - 50 50
//	if((board->B_shi + board->B_xiang) >= 3 && StoY(bk) <= 0x4){
//		if(bcan >= 2 && rcan == 0){
//			board->mulScore -= bcan * ADD_1CheMore2Pawn_To_1Pao2ma1Pawn;
//		}
//	}
//
//	*/
//}
//

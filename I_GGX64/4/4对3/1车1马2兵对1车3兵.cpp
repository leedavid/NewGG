#ifndef END_my_m_MT_R_1che1ma2pawn_B_1che3pawn
#define END_my_m_MT_R_1che1ma2pawn_B_1che3pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1马2兵对1车3兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1che1ma2pawn_B_1che3pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	int mcan = EV_MY_CAN;

	Square yche = S90_from_piecelist(POSITION,your_che,0);
	Square mma  = S90_from_piecelist(POSITION,my_ma,0);

	// fen 3ak1bN1/4a4/4b4/6r1p/p5p2/7RP/P8/8B/4A4/4KA3 b - - 120 120
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if(mcan == 0 && StoY(yche) MY_SMALL_EQL MY_RANK3 && IsOnSameSide(yche,mma)){
			if(PB90(MY_SQ07) == my_ma && PB90(MY_SQ06) == your_xiang){
				if(StoX(yche) == 0x6){
					MY_EV_SUB(168);
				}
			}
			if(PB90(MY_SQ01) == my_ma && PB90(MY_SQ02) == your_xiang){
				if(StoX(yche) == 0x2){
					MY_EV_SUB(168);
				}
			}
		}

		if (mcan == 0 && StoY(mma) MY_LARGE_EQL MY_RANK7){
			MY_EV_SUB(32);
			if (have_bit(bb_my_pawn, LeftBB[0x1])
				&& have_bit(bb_my_pawn, RightBB[0x7])){
				MY_EV_SUB(64);
			}
		}
	}

	// fen 2ba5/4k4/3ab4/8R/9/4pp2P/P1pr5/3N5/4A4/2BAK4 w - - 0 1
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK4])){
			if(EV_YOUR_CAN == 3 && StoY(mma) MY_LARGE_EQL MY_RANK7){
				if(count_1s(bb_my_pawn,MyLowBB[MY_RANK4]) >= 2){
					MY_EV_SUB(EV_YOUR_CAN * 32);
				}
			}
		}

	}
}

//void m_MT_B_1che1ma2pawn_R_1che3pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	int rche = PieceListStart(board,RCHE);
//	int bche = PieceListStart(board,BCHE);
//
//	int bcan = BpawnCanOverLiver(board);
//
//	// fen 3ak1bN1/4a4/4b4/6r1p/p5p2/7RP/P8/8B/4A4/4KA3 b - - 120 120
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//		if(bcan == 0 && StoY(rche) >= 0x9){
//			if(board->b256[0xca] == BMA && board->b256[0xc9] == RXIANG){
//				if(StoX(rche) == 0x9 ){
//					board->mulScore += 256;
//				}
//			}
//			if(board->b256[0xc4] == BMA && board->b256[0xc5] == RXIANG){
//				if(StoX(rche) == 0x5 ){
//					board->mulScore += 256;
//				}
//			}
//		}
//	}
//
//    */
//}
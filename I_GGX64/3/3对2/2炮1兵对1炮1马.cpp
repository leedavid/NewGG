#ifndef END_my_m_MT_R_2pao1pawn_B_1pao1ma
#define END_my_m_MT_R_2pao1pawn_B_1pao1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮1兵对1炮1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2pao1pawn_B_1pao1ma(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2PaoXPawn_1Pao1Ma_ByPawn[your_shi_num]);
	Square yma = S90_from_piecelist(POSITION, your_ma, 0);
 
	// fen 4kab2/4a4/1c7/C8/6b2/9/n7P/4B4/2C6/2BAKA3 w - - 0 0
	if((your_shi_num + your_xiang_num) >= 3 && (my_shi_num + my_xiang_num) >= 2){
		RETRUN_MUL(2;)
	}

	if((your_shi_num + your_xiang_num) == 4){
		EV_YOUR_SAFE = TRUE;
	}

	if((my_shi_num + my_xiang_num) >= 2){
		EV_MY_SAFE = TRUE;
	}

	int mcan = EV_MY_CAN;
	if(mcan == 0){
		EV_YOUR_SAFE = TRUE;
	}

	// fen 4ka3/2c1a3c/4N4/9/6p2/4C4/9/4B4/4A4/2BAK4 b - - 0 0
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);


	// fen 4k4/9/5a3/9/9/2n5c/6P2/4C4/3CA4/4KAB2 b - - 0 1
	if (your_shi_num >= 1 || your_xiang_num >= 1){
		if (StoY(yma) MY_LARGE_EQL MY_RANK4){
			MY_EV_SUB(32);
		}
		if (StoY(mpawn) MY_LARGE MY_RANK4 && your_shi_num >= 1){
			MY_EV_SUB(64);
		}
	}

	// fen 4cN3/8C/3k1c3/9/9/2B6/9/4BA3/4A1p2/4K4 w - - 0 80
	if(EV_YOUR_SAFE && StoY(mpawn) MY_LARGE_EQL MY_RANK1){
		RETRUN_MUL(4);
	}

	// fen 3k5/3ca1P2/5a3/9/1C7/6B2/6n2/5A2B/4A1C2/3K5 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2){
			if(abs(StoX(mpawn) - StoX(yk)) >= 2 || abs(StoY(mpawn) - StoY(yk)) >= 2){
				RETRUN_MUL(4);
			}
		}
	}
}

//void m_MT_B_2pao1pawn_R_1pao1ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	int bcan = BpawnCanOverLiver(board);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2PaoXPawn_1Pao1Ma_ByPawn[board->R_shi];
//		}
//	}
//
// 
//	//if(board->R_shi == 2 && board->R_xiang == 2){
//	//	if((board->B_shi + board->B_xiang) >= 2){
//	//		return 1;
//	//	}
//	//}
//
//	if(board->R_shi == 2 && board->R_xiang == 2){
//		board->rsafe = TRUE;
//	}
//	if((board->B_shi + board->B_xiang) >= 2){
//		board->bsafe = TRUE;
//	}
//
//	if(bcan == 0){
//		board->rsafe = TRUE;
//	}
//
//	// fen 4ka3/2c1a3c/4N4/9/6p2/4C4/9/4B4/4A4/2BAK4 b - - 0 0
// 
//	*/
//}
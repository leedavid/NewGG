#ifndef END_my_m_MT_R_3pawn_B_1ma
#define END_my_m_MT_R_3pawn_B_1ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "3兵对1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int PawnShiAdd[3] = {96,48,0};

void my_m_MT_R_3pawn_B_1ma(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;

	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_XPawnToMa_ByPawnShi[your_shi_num]);

	//所有的兵在对方的将下面了,也是和了
	if(pmok == 0){
		RETRUN_MUL(2);
	}

	int mcan = EV_MY_CAN;

	// fen 4k4/9/3aba3/9/2b3p2/2B6/4N4/3AB2p1/2p1A4/5K3 b - - 128 128
	//如果黑方是仕相全,我方只有二个以下的兵可以过河,也是和棋
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(mcan <= 2){
			RETRUN_MUL(2);
		}
	}


	// fen 3k2b2/4a4/4ba3/9/2p3p2/9/9/3NBA2B/6p2/4K4 b - - 0 0
	if(mcan <= 1){
		if((your_shi_num + your_xiang_num) >= 3){
			RETRUN_MUL(2);
		}
	}

	// fen 4k4/2P2P3/b2aba3/9/9/P5B2/1n7/4BA3/9/3K1A3 w - - 55 55
	if((your_shi_num + your_xiang_num) == 4){
		RETRUN_MUL(2);
	}

	// fen 3k5/4a4/3ab4/9/2b1N4/6B2/6p2/3A5/2p1A1p2/5K3 w - - 120 120

	if((your_shi_num + your_xiang_num) >= 3){
		RETRUN_MUL(4);
	}

	// fen 3a5/2P2k3/5a3/6n2/9/4P3P/9/4B4/4K4/6B2 b - - 0 1
	if(your_shi_num == 2 && count_1s(bb_my_pawn,MyUpBB[MY_RANK5]) <= 1){
		RETRUN_MUL(4);
	}

	//fen 4k4/4aPP2/3a5/9/9/P5B2/1n7/9/4A4/3K2B2 w - - 0 1
	if (your_shi_num == 2){
		if (have_bit(bb_my_pawn, MyLowBB[MY_RANK4])){
			Bitboard upp = m_and(bb_my_pawn, MyUpBB[MY_RANK2]);
			if (count_1s(upp) == 2){
				if ((count_1s(upp, LeftBB[0x4])) == 2){
					RETRUN_MUL(4);
				}
				if ((count_1s(upp, RightBB[0x4])) == 2){
					RETRUN_MUL(4);
				}
			}
			RETRUN_MUL(8);
		}
	}

}

//void m_MT_B_3pawn_R_1ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	int bcan = BpawnCanOverLiver(board);
//
//	bool AllpawnBlowKing = TRUE;
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= ADD_XPawnToMa_ByPawnShi[board->R_shi];
//
//			if(StoY(from) <= StoY(rk)){
//				AllpawnBlowKing = FALSE;
//			}
//		}
//	}
//
//	if(AllpawnBlowKing == TRUE){   //所有的兵在对方的将下面了,也是和了
//		board->mulScore = 0;
//		return 1;
//	}
//
//	// fen 4k4/9/3aba3/9/2b3p2/2B6/4N4/3AB2p1/2p1A4/5K3 b - - 128 128
//	//如果黑方是仕相全,我方只有二个以下的兵可以过河,也是和棋
//	if(board->R_shi == 2 && board->R_xiang >= 1){
//		if(bcan <= 2){
//			return 1;
//		}
//	}
//
//	// fen 3k2b2/4a4/4ba3/9/2p3p2/9/9/3NBA2B/6p2/4K4 b - - 0 0
//	if(bcan <= 1){
//		if((board->R_shi + board->R_xiang) >= 3){
//			return 1;
//		}
//	}
//
//	// fen 4k4/2P2P3/b2aba3/9/9/P5B2/1n7/4BA3/9/3K1A3 w - - 55 55
//	if(board->R_shi == 2 && board->R_xiang == 2){
//		return 2;
//	}
//
//	// fen 3k5/4a4/3ab4/9/2b1N4/6B2/6p2/3A5/2p1A1p2/5K3 w - - 120 120
//	if(board->R_shi == 2 && board->R_xiang >= 1){
//		return 4;
//	}
//
//
//	//if(board->R_shi == 2){
//	//	board->mulScore /= 8;
//	//	return 1;
//	//}
//	//else if(board->R_shi == 1){
//	//	board->mulScore /= 4;
//	//	return 1;
//	//}
//
//
//	return 16;	/*/
//}
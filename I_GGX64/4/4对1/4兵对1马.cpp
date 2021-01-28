#ifndef END_my_m_MT_R_4pawn_B_1ma
#define END_my_m_MT_R_4pawn_B_1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "4兵对1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int PawnShiAdd[3] = {96,48,0};

void my_m_MT_R_4pawn_B_1ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int count = (int)count_1s(bmp);

	MY_EV_ADD(count * ADD_XPawnToMa_ByPawnShi[your_shi_num]);


	if(count == 0){   //所有的兵在对方的将下面了,也是和了
		RETRUN_MUL(2);
	}

	int mcan = EV_MY_CAN;
	//如果能过河的兵只有一个,也是和棋
	if(mcan <= 1){
      if(your_shi_num >= 1 || your_xiang_num >= 1){
		  RETRUN_MUL(2)
	  }
	}

	// fen 3k2b2/4a4/4ba3/9/2p3p2/4N4/4p4/B4A2B/4A1p2/4K4 b - - 79 79
	if(mcan <= 2){
		if(your_shi_num == 2 || your_xiang_num >= 1){
			RETRUN_MUL(2)
		}
	}


	//*/
}

//void m_MT_B_4pawn_R_1ma(typePOS &POSITION, EvalInfo &ei){
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
//	// fen 5a3/4k4/3a5/9/1N7/9/1p7/3A1K2B/2pp5/1p7 w - - 123 123
//	//如果能过河的兵只有一个,也是和棋
//	if(bcan <= 1){
//		if(board->R_shi != 0 || board->R_xiang != 0){
//			return 1;
//		}
//	}
//
//    // fen 3k2b2/4a4/4ba3/9/2p3p2/4N4/4p4/B4A2B/4A1p2/4K4 b - - 79 79
//	if(bcan <= 2){
//		if(board->R_shi == 2 && board->R_xiang == 2){
//			return 1;
//		}
//	}
//
//
//	return 16;	/*/
//}
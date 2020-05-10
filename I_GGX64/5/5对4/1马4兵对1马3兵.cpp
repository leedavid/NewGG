#ifndef END_my_m_MT_R_1ma4pawn_B_1ma3pawn
#define END_my_m_MT_R_1ma4pawn_B_1ma3pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马4兵对1马3兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


// fen 3akab2/9/4b4/p8/4p3p/2B6/P1n1P3P/2N1BA3/4Ap3/3K5 b - - 10 10
void my_m_MT_R_1ma4pawn_B_1ma3pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1MaXPawn_3pawn_ShiAdd[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1MaXPawn_3pawn_ShiAdd[my_shi_num]);


	if (EV_YOUR_CAN <= 1) {
		if (my_shi_num == 2) {
			EV_MY_SAFE = true;
		}
	}


	//  fen 4k4/4a4/3ab4/p8/3np3p/P1PN5/4P3P/3ABA3/9/2B1K4 w - - 0 1
	if (EV_MY_SAFE) {
		if (your_shi_num == 2 && your_xiang_num >= 1) {
			if (EV_MY_CAN == 0) {
				RETRUN_MUL(4);
			}
		}
	}


	// fen 5k3/3Pa4/3ab1n2/p3p1N1p/6b2/P3P4/8P/4B4/9/2BAKA3 w
	if((your_shi_num + your_xiang_num) == 4){
		int mcan = EV_MY_CAN;
		int ycan = EV_YOUR_CAN;
		if(mcan <= 1 && ycan <= 1){
			RETRUN_MUL(8);
		}
	}



/*
   //如果双方是仕相全,且多兵方只有一个兵过河,就也基本是和棋

    Square rk = PieceListStart(board,RKING);
	Square bk = PieceListStart(board,BKING);
	int rcan = RpawnCanOverLiver(board);
    int bcan = BpawnCanOverLiver(board);

	if(board->B_shi == 2 && board->B_xiang == 2){
		if(board->R_shi == 2 && board->R_xiang == 2){
			//if(StoY(rk) > 0xa && StoY(bk) < 0x
			//// fen 3akab2/9/4b4/p8/4p3p/2B6/P1n1P3P/2N1BA3/4Ap3/3K5 b - - 10 10
			if(rcan <= 1 && bcan <= 1){
				return 1;
			}
		}
	}
	
	*/
}
//
//void m_MT_B_1ma4pawn_R_1ma3pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	int rcan = RpawnCanOverLiver(board);
//    int bcan = BpawnCanOverLiver(board);
//
//	if(board->R_shi == 2 && board->R_xiang == 2){
//		if(board->B_shi == 2 && board->B_xiang == 2){
//			//if(StoY(rk) > 0xa && StoY(bk) < 0x
//			if(bcan <= 1 && rcan <= 1){
//				return 1;
//			}
//		}
//	}
//
//	*/
//}

#ifndef END_my_m_MT_R_1che2pao2pawn_B_2che2pawn
#define END_my_m_MT_R_1che2pao2pawn_B_2che2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车2炮2兵对2车2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

// fen 2b1ka3/4a4/3cb4/p5p1R/6r2/2P5c/PR7/4B4/9/2BAKA3 b - - 0 0
void my_m_MT_R_1che2pao2pawn_B_2che2pawn(typePOS &POSITION, EvalInfo &ei){

	if((my_shi_num + my_xiang_num) == 4 && PB90(MY_SQ55) == my_king){
		int ycan = EV_YOUR_CAN;
		int yalr = Your_pawn_already_over_river(POSITION);

		if(ycan == 0 && yalr == 0){
			MY_EV_ADD(96);
		}
	}
}
//
//// fen 2b1ka3/4a4/3cb4/p5p1R/6r2/2P5c/PR7/4B4/9/2BAKA3 b - - 0 0
//void m_MT_B_1che2pao2pawn_R_2che2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//
//
//	if(board->B_shi == 2 && board->B_xiang == 2 && StoY(bk) == 0x3){
//		int rcan  = RpawnCanOverLiver(board);
//		int rover = RpawnAlreadyRiver(board);
//
//		if(rcan == 0 && rover == 0){
//			board->mulScore -= 96;
//		}
//	}
//
//
//	*/
//}
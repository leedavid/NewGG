#ifndef END_my_m_MT_R_2pao2ma2pawn_B_1che1ma3pawn
#define END_my_m_MT_R_2pao2ma2pawn_B_1che1ma3pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮2马2兵对1车1马3兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2pao2ma2pawn_B_1che1ma3pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;
	// fen 2b1kab2/2c1a4/9/p3p3p/1C7/1N2P4/P2N1r2P/4K2C1/4A4/2BA2B2 b - - 0 1
	if(StoY(mk) == MY_RANK7){
		MY_EV_SUB(64);
	}
}

//void m_MT_B_2pao2ma2pawn_R_1che1ma3pawn(typePOS &POSITION, EvalInfo &ei){
//  /*
//	int rcan =  RpawnCanOverLiver(board);
//	int bcan =  BpawnCanOverLiver(board);
//
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//		if(bcan == 0 && rcan >= 1){
//			board->mulScore += ADD_ChePawnCan_noChePawnNotcan * rcan;
//		}
//	}
//
//	*/
//}
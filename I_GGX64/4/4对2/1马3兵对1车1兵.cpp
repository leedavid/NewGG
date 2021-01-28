
#ifndef END_my_m_MT_R_1ma3pawn_B_1che1pawn
#define END_my_m_MT_R_1ma3pawn_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马3兵对1车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1ma3pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	//int rcan = RpawnCanOverLiver(board);

	// fen 2baka3/9/4b4/1P7/9/2R1pp1p1/6n2/4B4/4A4/2B1KA3 w - - 10 10
	if(my_shi_num == 2 && PB90(MY_SQ55) == my_king){
		Bitboard lp = My_get_connect_Pawn(POSITION);
		if(m_have_bit(m_and(lp,MyLowBB[MY_RANK2]))){
			int mcan = EV_MY_CAN;
			MY_EV_ADD(mcan * 64);
			MY_EV_ADD(64);
		}
	}
}
//
//void m_MT_B_1ma3pawn_R_1che1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	//Square bk = PieceList
//	int bcan = BpawnCanOverLiver(board);
//
//	// fen 2baka3/9/4b4/1P7/9/2R1pp1p1/6n2/4B4/4A4/2B1KA3 w - - 10 10
//	if(board->B_shi == 2 && board->B_xiang == 2 && board->b256[0x37] == BKING){
//		int l = B_PawnConnect_0x7(board);
//		if(StoX(l) == 0x7 && (StoY(l) == 0x8 || StoY(l) == 0x9)){
//			board->mulScore -= bcan * 32;
//			board->mulScore -= 64;
//		}
//	}
//
//	*/
//}
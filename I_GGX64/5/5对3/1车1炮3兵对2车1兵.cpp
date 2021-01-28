#ifndef END_my_m_MT_R_1che1pao3pawn_B_2che1pawn
#define END_my_m_MT_R_1che1pao3pawn_B_2che1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1炮3兵对2车1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

void my_m_MT_R_1che1pao3pawn_B_2che1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1che1paoXpawn_To_2che1pawn_ByShi[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_2che1pawn_To_1pao1paoXpawn_ByShi[my_shi_num]);


	// fen 2b1ka3/4a4/4b4/3R5/p1rc5/4pp3/P6R1/4B4/4A4/2BAK4 b - - 25 25
	int ycan = EV_YOUR_CAN;
	if(ycan == 0 && (my_shi_num + my_xiang_num) == 4 && PB90(MY_SQ4C) == my_shi){
		if(StoY(my_king_pos) == MY_RANK9){
			MY_EV_ADD(128);
		}
	}

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	// fen Cr1ak4/4a4/9/R1pP4p/P8/2P5r/9/4B4/4A4/3AK4 w - - 0 1
	if(my_shi_num == 2 && StoY(mk) == MY_RANK9){
		if(StoY(ypawn) MY_SMALL_EQL MY_RANK5){
			if(your_xiang_num  <= 1 && have_bit(EV_MY_XBIT,bb_your_che)){
				MY_EV_ADD(32);
				MY_EV_ADD(EV_MY_CAN * 16);
			}
		}
	}

}

//void m_MT_B_1che1pao3pawn_R_2che1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	//return 16;
//
//
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	int rcan = RpawnCanOverLiver(board);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_2che1pawn_To_1pao1paoXpawn_ByShi[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1che1paoXpawn_To_2che1pawn_ByShi[board->R_shi];
//		}
//	}
//
//	// fen 2b1ka3/4a4/4b4/3R5/p1rc5/4pp3/P6R1/4B4/4A4/2BAK4 b - - 25 25
//	if(rcan == 0){
//		if(board->B_shi == 2 && board->B_xiang == 2 && StoY(bk) == 0x3){
//			board->mulScore -= ADD_1che1paoXpawn_To_2che1pawn_ByPsafe;	
//		}
//	}
//
//
//
//	*/
//}
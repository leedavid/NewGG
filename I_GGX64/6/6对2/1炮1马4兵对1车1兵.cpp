#ifndef END_my_m_MT_R_1ma1pao4pawn_B_1che1pawn
#define END_my_m_MT_R_1ma1pao4pawn_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马4兵对1车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByShi

// 红方马炮兵,黑方车兵
void my_m_MT_R_1ma1pao4pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;

	your_m_MT_R_1che1pawn_B_1pao1ma(POSITION,ei);	

	if(ei.mul <= 2){
		ei.rsafe = TRUE;
	}
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByShi[your_shi_num]);

	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * Add_MAT_B_1che1pawn_R_1ma1pao1pawn_ByShi[my_shi_num]);

	Bitboard lp = My_get_connect_Pawn(POSITION);
	// fen 5k3/r5PP1/9/4PP3/2P6/5N3/6C2/9/4Ap3/4KA3 w
	// fen 5k3/r5PP1/9/4PP3/2P6/5N3/3C5/9/4Ap3/4KA3 w
	//print_bb(lp);
	if(m_have_bit(m_and(lp,MyLowBB[MY_RANK2]))){
		//print_bb(m_and(lp,MyLowBB[MY_RANK2]));
		MY_EV_ADD(Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByConPawn);
	}
}

// 黑方马炮兵,红方车兵
//void m_MT_B_1ma1pao4pawn_R_1che1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rpawn = PieceListStart(board,RPAWN);
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//
//	//board->mulScore = 0;  //要复位一下
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += Add_MAT_B_1che1pawn_R_1ma1pao1pawn_ByShi[board->B_shi];
//		}
//	}
//
//	// fen 3nkab2/4a1P2/4b4/7R1/8c/1p7/9/4B4/4A4/4KAB2 w - - 4 4
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			//board->mulScore -=  Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByShi[board->R_shi];
//			int bonus = Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByShi[board->R_shi];
//			if(board->bsafe){
//				//bonus *= 2;
//			}
//			board->mulScore -=  bonus;
//		}
//	}
//
//    int rcan = RpawnCanOverLiver(board);
//	if(rcan == 0 ){
//		board->mulScore -= ADD_Che2Pawn_Can0;
//	}
//
//		//如果红方有联兵，也要加分
//	// fen 3akab2/9/9/2N1C4/3PP4/P5p2/6r2/9/9/3AKA3 w - - 2 2
//	if(B_PawnConnect_0x7(board) && board->B_shi == 2){
//		board->mulScore -= Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByConPawn;
//	}
//
//
//
//
//	*/
//}


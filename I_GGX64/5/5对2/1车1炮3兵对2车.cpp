#ifndef END_my_m_MT_R_1che1pao3pawn_B_2che
#define END_my_m_MT_R_1che1pao3pawn_B_2che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮3兵对2车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//#define ADD_车炮兵对二车_by_Pawn_Safe   32             //车炮兵对二车,炮方安全时兵的加分



//红方车炮2兵 对 黑方2车
void my_m_MT_R_1che1pao3pawn_B_2che(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	//your_m_MT_R_2CHE_B_1CHE1PAO(POSITION,ei);

	//if(ei.mul <= 2){
	//	EV_MY_SAFE = TRUE;
	//}

	// fen 3ak1b2/4a4/4b4/2r6/7r1/3CR3P/2P1P4/9/4A4/4KA3 w - - 0 1
	if(my_shi_num == 2 && MY_SQ55 == mk){
		MY_EV_ADD(EV_MY_CAN * 32);
		if(StoY(mpao) MY_LARGE_EQL MY_RANK5){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	// ADD 
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	if(EV_MY_SAFE){
		MY_EV_ADD((sint16)count_1s(bmp) * ADD_车炮兵对二车_by_Pawn__Safe_Shi[your_shi_num] * 3/2);
	}
	else{
		MY_EV_ADD((sint16)count_1s(bmp) * ADD_车炮兵对二车_by_Pawn__Safe_Shi[your_shi_num]);
	}

	

	// fen 3ak1b2/4a4/4b4/2r6/7r1/3CR3P/2P1P4/9/4A4/4KA3 w - - 0 1
	if(my_shi_num == 2 && MY_SQ55 == mk){

		if (StoY(mpao) MY_LARGE_EQL MY_RANK7){
			MY_EV_ADD(32);
			if (StoX(mpao) > 0x4 && PB90(MY_SQ56) != my_shi){
				MY_EV_ADD(32);
			}
			if (StoX(mpao) < 0x4 && PB90(MY_SQ54) != my_shi){
				MY_EV_ADD(32);
			}
			MY_EV_ADD(EV_MY_CAN * 32);
		}

		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(4);
		}
	}

}

//void m_MT_B_1che1pao3pawn_R_2che(typePOS &POSITION, EvalInfo &ei){
///*
//
//	if(m_MT_R_2CHE_B_1CHE1PAO(board) == 1){
//		board->bsafe = TRUE;
//	}
//
//
//	// fen 3ak1b2/3Ra4/4b1c2/4p3p/5r3/2R6/9/4B4/9/3AKAB2 w - - 0 0
//	for(int pawn = PieceListStart(board,BPAWN); pawn > 0x32; pawn = NextPiece(board,pawn)){
//		if(StoY(pawn) != 0xc){
//			//board->mulScore -= ADD_车炮兵对二车_by_Pawn__Safe_Shi[board->R_shi];
//			int bonus = ADD_车炮兵对二车_by_Pawn__Safe_Shi[board->R_shi];
//			if(board->bsafe) {
//				bonus *= 2;
//			}
//			board->mulScore -= bonus;
//		}
//	}
//
//
//
// 
//    */
//}
#ifndef END_my_m_MT_R_1che1pao2pawn_B_2che
#define END_my_m_MT_R_1che1pao2pawn_B_2che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮2兵对2车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



//红方车炮2兵 对 黑方2车
void my_m_MT_R_1che1pao2pawn_B_2che(typePOS &POSITION, EvalInfo &ei){
	
	//my_m_MT_R_1che1pao1pawn_B_2che(POSITION,ei);

	Square mk = my_king_pos;
	Square mpao = S90_from_piecelist(POSITION, my_pao, 0);

	// fen 4kab2/4a4/4br3/6R2/9/6P2/8P/3C5/9/2BAKAr2 b - - 0 1
	
	if(my_shi_num == 2 && MY_SQ55 == mk){
		EV_MY_SAFE = TRUE;
		MY_EV_ADD(32);
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
	}	

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_车炮兵对二车_by_Pawn__Safe_Shi[your_shi_num]);

	// fen 3ak1b2/4a4/4b4/2r6/7r1/3CR3P/2P1P4/9/4A4/4KA3 w - - 0 1
	if(my_shi_num == 2 && MY_SQ55 == mk){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			RETRUN_MUL(4);
		}
	}

	// fen 2bk1a3/9/4ba3/4R4/8P/6Cr1/3r2P2/4B4/4A4/2BAK4 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && EV_MY_CAN <= 1){
			if(StoY(yk) MY_SMALL_EQL MY_RANK1){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 9/3k5/9/3R5/2r6/5CP1P/5r3/4B4/4A4/2B1KA3 b - - 0 1
	if(EV_MY_SAFE){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
			if(have_bit(bb_your_che,RankBB_A[MY_RANK4])){
				RETRUN_MUL(8);
			}
		}
	}

}

//void m_MT_B_1che1pao2pawn_R_2che(typePOS &POSITION, EvalInfo &ei){
//
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
//	if((board->R_shi + board->R_xiang) >= 2){
//		board->rsafe = TRUE;
//	}
//
//
//
//	
//    */
//}
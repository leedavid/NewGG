
#ifndef END_my_m_MT_R_1ma1pao1pawn_B_1che1pawn
#define END_my_m_MT_R_1ma1pao1pawn_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马1兵对1车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByShi

// 红方马炮兵,黑方车兵
void my_m_MT_R_1ma1pao1pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByShi[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * Add_MAT_B_1che1pawn_R_1ma1pao1pawn_ByShi[my_shi_num]);

	MY_EV_SUB(64);

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mpao = S90_from_piecelist(POSITION, my_pao, 0);

	// fen 2bak4/4a4/4b4/9/P8/2NrC4/4Pp3/4B4/4A4/2BAK4 b - - 0 1
	if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		MY_EV_ADD(32);
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	// fen 3k1ab2/4a4/4b4/2p6/5N1Cr/2P1P4/P8/4B4/9/2B1K4 w - - 0 1
	if (my_xiang_num == 2){
		if (PB90(MY_SQ2F) == my_pawn && PB90(MY_SQ1D) == your_pawn){
			MY_EV_ADD(64);
		}
		else if (PB90(MY_SQ33) == my_pawn && PB90(MY_SQ21) == your_pawn){
			MY_EV_ADD(64);
		}
	}

	// fen 9/3kaP3/9/4r4/9/1N5p1/9/4C4/9/3AKAB2 w - - 0 1
	if((my_shi_num + my_xiang_num) <= 3){
		MY_EV_SUB(32);
		if(StoY(mpawn) MY_SMALL_EQL StoY(yk)){
			MY_EV_SUB(32);
		}
		if(StoY(ypawn) MY_LARGE_EQL MY_RANK5){
			MY_EV_SUB(16);
		}
		// fen 3ak4/4a4/4N4/p8/9/P8/6r2/6C2/4A4/2BAK4 w - - 0 1
		if(abs(StoX(mpawn) - 0x4) >= 3){
			MY_EV_SUB(32);
		}
	}

	// fen 3k5/4N4/4b1P2/p8/9/r1B6/9/4B4/9/5KC2 b - - 0 1
	if(my_shi_num == 0 && EV_YOUR_CAN >= 1){
		MY_EV_SUB(64);
		if(abs(StoX(mpawn) - StoX(yk)) >= 2){
			MY_EV_SUB(32);
		}
	}

	if((my_shi_num + my_xiang_num) == 4 && StoY(my_king_pos) == MY_RANK9){
		EV_MY_SAFE = TRUE;
	}

	if((your_shi_num + your_xiang_num) >= 2){
		EV_YOUR_SAFE = TRUE;
	}

	// fen 3k1ab2/4a4/4b4/2p6/5N1Cr/2P1P4/P8/4B4/9/2B1K4 w - - 0 1
	if (my_xiang_num == 2 && StoY(mpao) MY_LARGE_EQL MY_RANK5){
		if (PB90(MY_SQ2F) == my_pawn && PB90(MY_SQ1D) == your_pawn){
			RETRUN_MUL(8);
		}
		else if (PB90(MY_SQ33) == my_pawn && PB90(MY_SQ21) == your_pawn){
			RETRUN_MUL(8);
		}
	}
}

// 黑方马炮兵,红方车兵
//void m_MT_B_1ma1pao1pawn_R_1che1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rpawn = PieceListStart(board,RPAWN);
//	Square rk = PieceListStart(board,RKING);
//
//
//	// fen 3nkab2/4a1P2/4b4/7R1/8c/1p7/9/4B4/4A4/4KAB2 w - - 4 4
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			//board->mulScore -=  Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByShi[board->R_shi];
//			int bonus = Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByShi[board->R_shi];
//			//if(board->bsafe){
//			//	bonus *= 2;
//			//}
//			board->mulScore -=  bonus;
//		}
//	}
//
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += Add_MAT_B_1che1pawn_R_1ma1pao1pawn_ByShi[board->B_shi];
//		}
//	}
//
//	if((board->R_shi + board->R_xiang) >= 2){
//		board->rsafe = TRUE;
//	}
//
//
//	*/
//}


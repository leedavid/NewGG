#ifndef END_my_m_MT_R_1pao2ma1pawn_B_1che1ma
#define END_my_m_MT_R_1pao2ma1pawn_B_1che1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮2马1兵对1车1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1pao2ma1pawn_B_1che1ma(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1Pao2MaXPawn_1Che1Ma_To_ByPawn[your_shi_num]);

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square yma   = S90_from_piecelist(POSITION,your_ma,0);

	if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		EV_MY_SAFE = TRUE;
	}

	// fen 2ba1kb2/r1N1a4/9/3N5/CP7/6B2/3n5/4BA3/3KA4/9 w - - 0 1
	if(StoY(mk) != MY_RANK9){
		MY_EV_SUB(64);
	}

	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(32);
	}
	if(StoY(yma) MY_LARGE_EQL MY_RANK5){
		MY_EV_SUB(32);
	}

	// fen 2bk5/9/3rb4/4n4/1N2NC3/2P6/9/3AB4/4A4/2B1K4 b - - 0 1
	if(EV_MY_CAN == 0){
		MY_EV_SUB(64);
	}

	if(your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(32);
	}

	// fen 4k4/4a4/5a3/9/1N7/2N3P2/3r3n1/3ABC3/4A4/2BK5 b - - 0 1
	if(EV_MY_SAFE){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK5){
			if((your_shi_num == 2 || your_xiang_num == 2) && StoY(yk) MY_SMALL_EQL MY_RANK1){
				RETRUN_MUL(8);
			}
		}
	}

}
//
//void m_MT_B_1pao2ma1pawn_R_1che1ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1Pao2MaXPawn_1Che1Ma_To_ByPawn[board->R_shi];
//		}
//	}
//
//	*/
//}




//m_MT_R_2pao1ma1pawn_B_1che1pao(
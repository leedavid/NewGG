#ifndef END_my_m_MT_R_2ma_B_1ma1pawn
#define END_my_m_MT_R_2ma_B_1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2Âí¶Ô1Âí1±ø.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_2ma_B_1ma1pawn(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mk    = my_king_pos;

	if(StoY(ypawn) MY_SMALL StoY(mk)){
		MY_EV_SUB(ADD_2MaXPawn_1Ma[my_shi_num]);
	}

	Square yma = S90_from_piecelist(POSITION,your_ma,0);

	if(StoY(yk) MY_SMALL_EQL MY_RANK1){
		if((your_shi_num + your_xiang_num) == 4){
			RETRUN_MUL(2);
		}
	}

	// fen 2ba1k3/7P1/3ab4/9/9/9/2n6/4Bn3/9/3K1N3 w - - 165 165
	if(your_xiang_num >= 1 && StoY(ypawn) MY_LARGE_EQL MY_RANK5){
		if(StoY(yma) MY_SMALL_EQL MY_RANK4){
			RETRUN_MUL(4);
		}
	}

	// fen 2bk5/4a4/4b4/1N2p2N1/9/2B6/4n4/8B/4A4/4KA3 b - - 0 1
	if(your_xiang_num == 2 && your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(EV_YOUR_CAN >= 1){
			RETRUN_MUL(4);
		}
	}

	if((your_xiang_num + your_shi_num) >= 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		RETRUN_MUL(8);
	}
	
}

//void m_MT_B_2ma_R_1ma1pawn(typePOS &POSITION, EvalInfo &ei){
//	/*
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > 0x3){
//			board->mulScore +=  96;
//		}
//	}
//
//	Square rk     = PieceListStart(board,RKING);
//	Square rpawn  = PieceListStart(board,RPAWN);
//
//	// fen 2ba1k3/7P1/3ab4/9/9/9/2n6/4Bn3/9/3K1N3 w - - 165 165
//	if(board->R_xiang != 0 && StoY(rpawn) <= 0x7){
//		return 4;
//	}
//   
//
//	if(StoY(rk) == 0xc){		
//		if(board->R_xiang == 2 && board->R_shi == 2){
//			return 1;
//		}
//	}
//
//	return 8;/*/
//}
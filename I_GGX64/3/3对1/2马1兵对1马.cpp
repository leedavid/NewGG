#ifndef END_my_m_MT_R_2ma_1pawn_B_1ma
#define END_my_m_MT_R_2ma_1pawn_B_1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2马1兵对1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 




void my_m_MT_R_2ma_1pawn_B_1ma(typePOS &POSITION, EvalInfo &ei){

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square yk = your_king_pos;

	if(StoY(mpawn) MY_LARGE StoY(yk)){
		MY_EV_ADD(ADD_2MaXPawn_1Ma[your_shi_num]);
	}

	// fen 2bak4/9/5a3/9/2b1n4/9/4Nn3/5Ap1B/3KA4/6B2 w - - 120 120
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(abs(StoX(mpawn) - StoX(yk)) >= 2 && !IsOnSameSide(mpawn,yk)){
			if(StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi){
				RETRUN_MUL(8);
			}
			if(StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi){
				RETRUN_MUL(8);
			}
		}
	}
}

//void m_MT_B_2ma_1pawn_R_1ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//
//	Square bpawn = PieceListStart(board,BPAWN);
//
//	if(StoY(bpawn) < StoY(rk)){
//		board->mulScore -= ADD_2MaXPawn_1Ma[board->R_shi];;
//	}
//
//
//	// fen 2bak4/9/5a3/9/2b1n4/9/4Nn3/5Ap1B/3KA4/6B2 w - - 120 120
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) >= 0xb){
//		if(abs(StoX(bpawn) - StoX(rk)) >= 2){
//			if(StoX(rk) == 0x6 && board->b256[0xa6] != RSHI){
//				return 4;
//			}
//			if(StoX(rk) == 0x8 && board->b256[0xa8] != RSHI){
//				return 4;
//			}
//		}
//	}
//
//	*/
//}
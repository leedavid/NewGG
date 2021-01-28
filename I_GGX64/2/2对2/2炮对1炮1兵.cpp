#ifndef END_my_m_MT_R_2pao_B_1pao1pawn
#define END_my_m_MT_R_2pao_B_1pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮对1炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2pao_B_1pao1pawn(typePOS &POSITION, EvalInfo &ei){
	
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mk    = my_king_pos;
	Square yk    = your_king_pos;

	if(StoY(ypawn) MY_SMALL StoY(mk)){
		MY_EV_SUB(ADD_1PaoXPawn_2Pao_ByPawnShi[my_shi_num]);
	}
	
	// fen 4kab2/4a4/4b4/4c4/2p6/6B2/2C5C/9/9/3AKAB2 b - - 0 0
	if((your_shi_num + your_xiang_num) == 4){
		RETRUN_MUL(2);
	}

	// fen 3a1k3/9/b8/1c7/2bC5/5C3/6p2/4B4/4A4/4KAB2 w - - 14 14
	if(your_xiang_num == 2 && StoY(yk) != MY_RANK2){
		EV_YOUR_SAFE = TRUE;
	}

	if(my_xiang_num != 0 || my_xiang_num != 0){
		EV_MY_SAFE = TRUE;
	}

	//还有一个情况,我方的炮被困住了,不能动了,也是和棋
    // fen C1bCk4/3c5/4b4/9/9/6B2/2p6/5A3/9/2B1KA3 b - - 120 120
	if(your_xiang_num != 0){
		if(PB90(MY_SQ03) == my_pao){
			if(MY_SQ04 == yk && PB90(MY_SQ02) == your_xiang && PB90(MY_SQ0C) == your_pao){
				RETRUN_MUL(2);
			}
		}

		if(PB90(MY_SQ05) == my_pao){
			if(MY_SQ04 == yk && PB90(MY_SQ06) == your_xiang && PB90(MY_SQ0E) == your_pao){
				RETRUN_MUL(2);
			}
		}
	}


	// fen 2b1k4/4a4/4b4/9/4C4/4c4/9/3AC4/5K3/3p5 w - - 0 1
	if(my_xiang_num == 0 && my_shi_num <= 1){
		if(your_xiang_num == 2 && your_shi_num >= 1){
			RETRUN_MUL(4);
		}
	}


}

//void m_MT_B_2pao_R_1pao1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_1PaoXPawn_2Pao_ByPawnShi[board->B_shi];
//		}
//
//	}
//
//	if(board->R_shi == 2 && board->R_xiang == 2){
//		return 1;
//	}
//
//	if(board->R_xiang != 0){
//		if(board->b256[0xc6] == BPAO){
//			if(board->b256[0xc7] == RKING && board->b256[0xc5] == RXIANG && board->b256[0xb6] == RPAO){
//				return 1;
//			}
//		}
//		if(board->b256[0xc8] == BPAO){
//			if(board->b256[0xc7] == RKING && board->b256[0xc9] == RXIANG && board->b256[0xb8] == RPAO){
//				return 1;
//			}
//		}
//	}
//
//	// fen 3a1k3/9/b8/1c7/2bC5/5C3/6p2/4B4/4A4/4KAB2 w - - 14 14
//	if(board->R_xiang == 2 && StoY(rk) >= 0xb){
//		board->rsafe = TRUE;
//	}
//
//	if(board->B_shi != 0 || board->B_xiang != 0){
//		board->bsafe = TRUE;
//	}
//
//
//	*/
//}
#ifndef END_my_m_MT_R_1che_1pao_1pawn_B_1che
#define END_my_m_MT_R_1che_1pao_1pawn_B_1che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮1兵对1车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che_1pao_1pawn_B_1che(typePOS &POSITION, EvalInfo &ei){

	Square yk    = your_king_pos;
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square yche  = S90_from_piecelist(POSITION,your_che,0);
	Square mche  = S90_from_piecelist(POSITION,my_che,0);
	Square mpao  = S90_from_piecelist(POSITION,my_pao,0);
	
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		// fen 4k1b2/4a4/3ab4/6r1P/9/2B6/9/3AB4/4A4/3CK3R w - - 32 32
		if(StoX(mche) == StoX(mpawn) && StoY(yche) == StoY(mpawn)){
			if(StoX(mpawn) == 0x0 && PB90(MY_SQ02) == your_xiang){
				RETRUN_MUL(4);
			}
			if(StoX(mpawn) == 0x8 && PB90(MY_SQ06) == your_xiang){
				RETRUN_MUL(4);
			}
		}
		int mcan = EV_MY_CAN;
		if(mcan == 0){
			if(isStringByChe(POSITION,mche,mpao,yche)){
				RETRUN_MUL(4);
			}
		}

		// fen 3ak1b2/3Pa4/4b4/5rCR1/9/9/9/9/4A4/3AK4 w - - 0 1
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(isStringByChe(POSITION,yche,mpao,mche)){
				if(StoX(mpawn) < 0x4 && StoX(mpao) > 0x4 && StoX(mche) > 0x4){
					RETRUN_MUL(4);
				}
				if(StoX(mpawn) > 0x4 && StoX(mpao) < 0x4 && StoX(mche) < 0x4){
					RETRUN_MUL(4);
				}
			}
		}

		// fen 3k1a3/4a4/4b3b/3rC1R2/9/6P2/9/9/4A4/2BAK1B2 b - - 22 22
		// fen 2b1k4/4a4/b4a3/9/9/2PR2B2/9/B1r2A3/4A4/3K1C3 b - - 120 120
		if(mcan == 0){
			RETRUN_MUL(8);
		}
	}

	// fen 3a1kb2/4a4/4b4/4P4/3R5/6B2/9/8B/9/3KCr3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(my_shi_num == 0){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK3){				
				RETRUN_MUL(8);				
			}
		}
	}

	// fen 2ba1kb2/R3a4/9/P8/9/r8/9/4BA3/4A4/2BC1K3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(abs(StoX(mpawn) - 0x4) == 4){
			if(StoY(mche) MY_SMALL StoY(mpawn) && isStringByChe(POSITION,mche,mpawn,yche)){
				RETRUN_MUL(8);
			}
		} 
	}

	// fen 2bk1a3/4a1P2/4b4/9/9/9/1R7/9/9/3rCK3 w - - 0 1
	if(my_shi_num == 0 && my_xiang_num == 0 && StoY(yk) MY_SMALL_EQL MY_RANK1){

		// fen 1P2k4/7r1/b4a3/9/9/4C4/4R4/9/9/4K4 b - - 0 1
		if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(mpawn) == MY_RANK0){

			MY_EV_SUB(96);

			if(abs(StoX(mpawn) - StoX(yk)) >= 2){
				RETRUN_MUL(8);
			}
		}
		// fen 3k1ab2/4aP3/b8/9/C3R4/9/9/9/3r5/4K4 w - - 0 1
		if(your_shi_num == 2 && your_xiang_num == 2){
			if(!IsOnSameSide(yk,mpawn) && abs(StoX(mpawn) - StoX(yk)) >= 2){
				RETRUN_MUL(8);
			}
		}

		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && abs(StoX(mpawn) - StoX(yk)) >= 2){
			if(IsOnSameSide(yk,mpawn) == false){
				RETRUN_MUL(12);
			}
		}
	}
}

//void m_MT_B_1che_1pao_1pawn_R_1che(typePOS &POSITION, EvalInfo &ei){
///*
//	//兵不能过河,马被牵制了,对方是仕相全,也是和棋
//    // fen 2b1kab2/9/3a5/9/6p2/2B4R1/7n1/4B4/3KA2r1/5A3 w - - 120 120
//
//	int bche  = PieceListStart(board,BCHE);
//    int bpao  = PieceListStart(board,BPAO);
//	Square bpawn = PieceListStart(board,BPAWN);
//
//	int rche  = PieceListStart(board,RCHE);
//	Square rk    = PieceListStart(board,RKING);
//	int bcan  = BpawnCanOverLiver(board);
//
//	// fen 4k1b2/4a4/3ab4/6r1P/9/2B6/9/3AB4/4A4/3CK3R w - - 32 32
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//		if(StoY(bpawn) >= 0x8 && StoY(bche) < StoY(bpawn) && StoX(bche) == StoX(bpawn)){
//			if(StoY(rche) == StoY(bpawn)){
//				if(StoX(bpawn) == 0xb && board->b256[0xc9] == RXIANG){
//					return 4;
//				}
//				if(StoX(bpawn) == 0x3 && board->b256[0xc5] == RXIANG){
//					return 4;
//				}
//			}
//		}
//	}
//
//	// fen 3k1a3/4a4/4b3b/3rC1R2/9/6P2/9/9/4A4/2BAK1B2 b - - 22 22
//	if(bcan == 0 && StoY(bpawn) <= 0x7){
//		if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//			if(IsStringByChe(board,rche,bpao,bche)){
//				if(StoX(bche) >= 0x7 && board->b256[0xc8] == RSHI){
//					return 4;
//				}
//				if(StoX(bche) <= 0x7 && board->b256[0xc6] == RSHI){
//					return 4;
//				}
//			}
//		}
//	}
//
//	*/
//}
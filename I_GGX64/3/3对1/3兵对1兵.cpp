
#ifndef END_my_m_MT_R_3pawn_B_1pawn
#define END_my_m_MT_R_3pawn_B_1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "3兵对1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//3兵对1兵
void my_m_MT_R_3pawn_B_1pawn(typePOS &POSITION, EvalInfo &ei){

	BothOnlyPawnEval(POSITION,ei); //vv 

	int mcan = EV_MY_CAN;

	Square ypawn = S90_from_piecelist(POSITION, your_pawn, 0);
	Square yk = your_king_pos;
	
	if(mcan == 0){
		RETRUN_MUL(2);
	}


	//  fen 5P3/3k5/b8/3P5/2b1p4/9/4P4/B3B3B/9/3AKA3 b - - 0 1
	if (EV_MY_CAN <= 1) {
		if (your_xiang_num == 2 && have_bit(bb_my_pawn, RankBB_A[MY_RANK0])) {
			if (count_1s(m_and(bb_my_pawn, MyUpBB[MY_RANK4])) == 2) {
				if (StoY(ypawn) == MY_RANK4) {
					if (PB90(ypawn MY_ADD 18) == my_pawn) {
						RETRUN_MUL(2);
					}
				}
			}
		}
	}	

	// fen 5kb2/3Pa1P2/3a5/9/6b1p/9/8P/B7B/9/3AKA3 b - - 0 1
	if (mcan <= 2){
		if (your_shi_num == 2 && your_xiang_num == 2){
			MY_EV_SUB(96);
			if (count_1s(bb_my_pawn, MyUpBB[MY_RANK2]) == 2){
				MY_EV_SUB(64);				
			}
			if (StoX(yk) == 0x5 && !have_bit(bb_your_shi, RightBB[0x4])){
				MY_EV_SUB(64);
			}
			if (StoX(yk) == 0x3 && !have_bit(bb_your_shi, LeftBB[0x4])){
				MY_EV_SUB(64);
			}
		}
	}

	// fen 3k5/2P1aP1P1/5a3/9/9/9/9/3A5/9/2p2K3 b - - 0 1
	if (your_shi_num == 2){
		Bitboard mp = m_and(bb_my_pawn, MyUpBB[MY_RANK2]);
		if (count_1s(mp) == 3){
			if (StoX(yk) == 0x3 
				&& PB90(MY_SQ15) != your_shi && PB90(MY_SQ17) == your_shi){
				if (count_1s(m_and(mp, LeftBB[0x5])) <= 1){
					RETRUN_MUL(2);
				}
			}
			if (StoX(yk) == 0x5
				&& PB90(MY_SQ17) != your_shi && PB90(MY_SQ15) == your_shi){
				if (count_1s(m_and(mp, RightBB[0x3])) <= 1){
					RETRUN_MUL(2);
				}
			}
		}
	}


	// fen 9/4PP3/3P1k3/9/6b2/9/9/9/4Ap3/3AK1B2 w - - 0 1
	if(EV_YOUR_CAN >= 1 && your_xiang_num >= 1 && StoY(yk) == MY_RANK2){
		// 有二个兵在将下面
		Bitboard bmp = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
		if(count_1s(bmp) == 3) RETRUN_MUL(2);
		if(count_1s(bmp) == 2){
			bmp = m_and(bb_my_pawn,RankBB_A[MY_RANK2]);
			if(count_1s(bmp) == 1){
				Square mp = pop_1st_bit_sq(bmp);
				if(!IsOnSameSide(mp,yk)){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 5P3/5P3/4k3b/9/p1b6/9/P8/3A1K3/9/2B2A3 b - - 0 1
	if (EV_MY_CAN <= 1 && your_xiang_num >= 1){
		Bitboard upp = m_and(bb_my_pawn, MyUpBB[StoY(yk)]);
		if (count_1s(upp) == 2){
			if (StoY(ypawn) MY_SMALL_EQL MY_RANK4){
				if (PB90(ypawn MY_ADD 18) == my_pawn){
					RETRUN_MUL(2);
				}
				if (PB90(ypawn MY_ADD 27) == my_pawn){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 2bk2b2/2P1a4/2P6/9/6p2/6B2/6P2/3AB4/9/5K3 w - - 0 1
	if (your_xiang_num == 2 && your_shi_num >= 1 && EV_MY_CAN <= 2){
		if (have_bit(bb_my_pawn, MyLowBB[MY_RANK4])){
			Bitboard upp = m_and(bb_my_pawn, MyUpBB[MY_RANK3]);
			if (count_1s(upp) == 2){
				if (StoX(yk) == 0x3 && !have_bit(bb_your_shi, LeftBB[0x4])){
					if (count_1s(upp, LeftBB[0x3]) == 2){
						RETRUN_MUL(2);
					}
				}
				if (StoX(yk) == 0x5 && !have_bit(bb_your_shi, RightBB[0x4])){
					if (count_1s(upp, RightBB[0x5]) == 2){
						RETRUN_MUL(2);
					}
				}
			}
		}
	}

	// fen 4P4/3ka4/2P1b4/9/6p2/9/6P2/4B4/9/4KAB2 w - - 0 1
	if (your_xiang_num >= 1 && your_shi_num >= 1 && EV_MY_CAN <= 1){
		Bitboard upp = m_and(bb_my_pawn, m_and(MyUpBB[MY_RANK3], MyLowBB[MY_RANK1]));
		if (count_1s(upp) == 1){
			if (StoX(yk) == 0x3 && !have_bit(bb_your_shi, LeftBB[0x4])){
				if (count_1s(upp, LeftBB[0x3]) == 1){
					RETRUN_MUL(2);
				}
			}
			if (StoX(yk) == 0x5 && !have_bit(bb_your_shi, RightBB[0x4])){
				if (count_1s(upp, RightBB[0x5]) == 1){
					RETRUN_MUL(2);
				}
			}
		}
	}
	

	// fen 3k1a3/2P1aP3/4b3b/7P1/9/2B6/3p5/5A2B/4A4/3K5 w - - 120 120
	if((your_shi_num + your_xiang_num) == 4){
		if(PB90(MY_SQ03) == your_king && PB90(MY_SQ05) == your_shi){
			RETRUN_MUL(2);
		}
		if(PB90(MY_SQ05) == your_king && PB90(MY_SQ03) == your_shi){
			RETRUN_MUL(2);
		}
		if(StoY(ypawn) == MY_RANK6 && StoX(ypawn) == StoX(yk)){
			RETRUN_MUL(2);
		}
	}

    // fen 3a1a3/2P6/4k4/9/9/2B6/9/4BA3/2p2p3/p2K5 w - - 224 224
	if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(ypawn) MY_LARGE_EQL MY_RANK5 && StoX(yk) != 0x4){
		if(    (StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi)
			|| (StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi)
			|| your_shi_num == 2){
			if(mcan <= 2){
				RETRUN_MUL(2);
			}
		}
	}
	
	// fen 4ka3/9/5a3/p8/6b2/P8/3p5/3AB3B/4Ap3/4K4 b - - 120 120
	//过了二个兵,另一兵给顶住了
	if((your_shi_num + your_xiang_num) == 4){
		if(PB90(ypawn MY_ADD 18) == my_pawn || PB90(ypawn MY_ADD 27) == my_pawn){
			Bitboard bp = m_and(bb_my_pawn,MyUpBB[StoY(ypawn)]);
			if(count_1s(bp) == 2){
				RETRUN_MUL(2);
			}
		}
	}
	
	// fen 2b1k4/4a4/bP3a3/9/1P2p4/6B2/4P4/3AB4/4A4/5K3 w - - 45 45
	if((your_shi_num + your_xiang_num) == 4){
		if(PB90(MY_SQ28) == your_pawn && PB90(MY_SQ3A) == my_pawn){
			if(PB90(MY_SQ27) == my_pawn || PB90(MY_SQ29) == my_pawn){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 3k5/2P2P3/5a2b/9/2b5p/6B2/8P/9/9/3AKA3 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2 && EV_MY_CAN <= 2){
		if(have_bit(bb_my_pawn,MyLowBB[MY_RANK4])){
			Bitboard p2 = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
			if(count_1s(p2) == 2 
				&& have_bit(LeftBB[0x4],bb_my_pawn) 
				&& have_bit(RightBB[0x4],bb_my_pawn)){
				if(StoX(yk) < 0x4 && PB90(MY_SQ17) == your_shi){
					RETRUN_MUL(2);
				}
				if(StoX(yk) > 0x4 && PB90(MY_SQ15) == your_shi){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 3k1a3/2P1aP3/6P2/9/2b6/9/5p3/B2A5/5K3/2BA5 b - - 120 120
	if(your_shi_num == 2 && your_xiang_num >= 1 && MY_SQ04 != yk){
		if(StoY(ypawn) == MY_RANK6 && abs(StoX(ypawn) - StoX(yk)) <= 1){
			RETRUN_MUL(2);
		}
	}
	// fen 4k2P1/4aP3/4b1P2/9/2b6/9/4p4/3A5/9/3K1A3 w - - 29 29
	if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(ypawn) == MY_RANK6){
		if(EV_MY_CAN <= 2){
			// 看一下是不是全在一边, 
			Bitboard p = m_and(bb_my_pawn, MyUpBB[MY_RANK3]);
			if(count_1s(p,LeftBB[0x4]) == 3){
				RETRUN_MUL(2);
			}
			if(count_1s(p,RightBB[0x4]) == 3){
				RETRUN_MUL(2);
			}
			RETRUN_MUL(4);
		}
	}
	// fen 3P2b2/4P4/3k5/4P4/9/9/3p5/4B4/4A4/3K2B2 w - - 0 1
	if(your_xiang_num >= 1 && StoY(yk) == MY_RANK2){
		if(StoY(ypawn) == MY_RANK6 || StoY(ypawn) == MY_RANK7){
			if(have_bit(bb_my_pawn,RankBB_A[MY_RANK0])){
				if(count_1s(bb_my_pawn,MyUpBB[StoY(yk)])){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 4ka3/4a4/4b4/4P4/6b1p/4P4/8P/4B4/4A4/3AK4 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && EV_MY_CAN <= 2){
		if(PB90(MY_SQ2C) == your_pawn && PB90(MY_SQ3E) == my_pawn){
			if(PB90(MY_SQ2B) != my_pawn){
				RETRUN_MUL(4);
			}
		}
		if(PB90(MY_SQ24) == your_pawn && PB90(MY_SQ36) == my_pawn){
			if(PB90(MY_SQ25) != my_pawn){
				RETRUN_MUL(4);
			}
		}
	}


	// fen 1P7/4aP3/3k1a3/9/2b1p4/6B2/4P4/B8/9/4K4 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(EV_MY_CAN <= 1){
			if(StoY(ypawn) MY_SMALL_EQL MY_RANK4 && PB90(ypawn + 18) == my_pawn){
				if(count_1s(bb_my_pawn,MyUpBB[StoY(ypawn)]) == 2){
					RETRUN_MUL(4);
				}
			}
		}
	} 

	// fen 3a5/3k5/4b4/8P/2b1p4/8P/4P4/B8/4A4/2BAK4 b - - 0 1
	if (your_xiang_num == 2 && your_shi_num >= 1) {
		if (EV_MY_CAN <= 2) {
			MY_EV_SUB(64);
			if (StoY(yk) != MY_RANK0) {
				MY_EV_SUB(64);
				if (MY_SQ28 == ypawn && PB90(MY_SQ3A) == my_pawn) {
					if (have_bit(bb_my_pawn, MyUpBB[MY_RANK4])) {
						Bitboard tp = m_and(RankBB_A[MY_RANK4],m_and(LeftBB[0x7], RightBB[0x1]));
						if (!have_bit(bb_my_pawn, tp)) {
							RETRUN_MUL(4);
						}
					}
				}
				RETRUN_MUL(8);
			}
		}
	}

}

//3兵对1兵
//void m_MT_B_3pawn_R_1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	BothOnlyPawnEval(board);
//	
//	Square rpawn = PieceListStart(board,RPAWN);
//	Square rk    = PieceListStart(board,RKING);
//	Square bk    = PieceListStart(board,BKING);
//	int bcan = BpawnCanOverLiver(board);
//
//	if(bcan == 0){
//		return 1;
//	}
//
//	if(board->R_shi == 2 && board->R_xiang == 2){
//		if(board->b256[0xb7] == RSHI){
//			if(board->b256[0xc6] == RKING && board->b256[0xc8] == RSHI){
//				return 1;
//			}
//			if(board->b256[0xc8] == RKING && board->b256[0xc6] == RSHI){
//				return 1;
//			}
//		}
//		if(StoY(rpawn) == 0x6 && StoX(rpawn) == StoX(rk)){
//			return 1;
//		}
//	}
//
//	// fen 3a1a3/2P6/4k4/9/9/2B6/9/4BA3/2p2p3/p2K5 w - - 224 224
//	if(board->R_shi >= 1 && board->R_xiang >= 1 && StoY(rpawn) <= 7){ //兵过河了
//		//1, 有一个兵到底线了,
//		//2, 其它二个兵在二线
//		//3, 我方的将不在原位
//
//		if(    (StoX(rk) == 0x6 && board->b256[0xa6] != RSHI)
//			|| (StoX(rk) == 0x8 && board->b256[0xa8] != RSHI) 
//			|| board->R_shi == 2){
//
//              bool isOneDi   = FALSE;
//			  int  num2Layer = 0;
//			  for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//				  if(StoY(from) == 0xc){
//					  isOneDi = TRUE;
//				  }
//				  if(StoY(from) >= 0xb){
//					  num2Layer ++;
//				  }
//			  }
//			  if(isOneDi && num2Layer == 3){
//				  return 1;
//			  }
//		}
//	}
//
//	// fen 4ka3/9/5a3/p8/6b2/P8/3p5/3AB3B/4Ap3/4K4 b - - 120 120
//	//过了二个兵,另一兵给顶住了
//	if(board->R_shi == 2 && board->R_xiang == 2){
//		if(board->b256[rpawn - 0x20] == BPAWN || board->b256[rpawn - 0x30] == BPAWN){
//			int blow = 0;
//			for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//				if(StoY(from) > StoY(rpawn)){
//					blow ++;
//				}
//			}
//			if(blow >= 2){
//				return 1;
//			}
//		}
//	}
//
//	// fen 2b1k4/4a4/bP3a3/9/1P2p4/6B2/4P4/3AB4/4A4/5K3 w - - 45 45
//	if(StoY(rpawn) == 0x8 && board->b256[rpawn-0x20] == BPAWN){
//		if(board->R_shi == 2 && board->R_xiang == 2){
//			if(abs(StoX(rpawn) - 0x7) <= 2){
//				return 2;
//			}
//		}
//	}
//
//	// fen 3k1a3/2P1aP3/6P2/9/2b6/9/5p3/B2A5/5K3/2BA5 b - - 120 120
//	if(board->R_shi == 2 && board->R_xiang >= 1 && rk != 0xc7 && board->b256[rk - 0x20] != RSHI){
//		if(StoY(rpawn) == 0x6 && abs(StoX(rpawn) - StoX(bk)) <= 2){
//			return 2;
//		}
//	}
//
//
//	*/
//}
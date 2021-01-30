#ifndef END_my_m_MT_R_3pawn
#define END_my_m_MT_R_3pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "3兵对无_nook.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//我方3兵，对方 0 attacker
void my_m_MT_R_3pawn(typePOS &POSITION, EvalInfo &ei){

	BothOnlyPawnEval(POSITION,ei);
	
	Square yk = your_king_pos;
	//Square mk = my_king_pos;
	if(your_shi_num >= 1 && your_xiang_num == 2){
		MY_EV_SUB(64);
	}

	if (your_shi_num == 2 && your_xiang_num == 2) {
		MY_EV_SUB(128);
	}

	//fen 3a1k3/3Pa1P2/4b1P2/9/2b6/6B2/9/5A3/9/3K2B2 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if (!have_bit(bb_my_pawn, MyLowBB[MY_RANK2])){
			if (PB90(MY_SQ0D) == your_shi){
				if (PB90(MY_SQ03) == your_shi && MY_SQ05 == yk){
					if (count_1s(bb_my_pawn, LeftBB[0x4]) == 1
						&& count_1s(bb_my_pawn, RightBB[0x5]) == 2){
						RETRUN_MUL(1);
					}
				}
				if (PB90(MY_SQ05) == your_shi && MY_SQ03 == yk){
					if (count_1s(bb_my_pawn, LeftBB[0x3]) == 2
						&& count_1s(bb_my_pawn, RightBB[0x4]) == 1){
						RETRUN_MUL(1);
					}
				}
			}
		}

		// fen 3ak4/2P1a4/b8/4P4/6b2/2P6/9/4B4/4A4/3K5 w - - 0 1
		if (EV_MY_CAN <= 2 && have_bit(bb_my_pawn, MyUpBB[MY_RANK3])){
			if (StoX(yk) <= 0x4 && !have_bit(bb_your_shi, LeftBB[0x4])){
				RETRUN_MUL(1);
			}
			if (StoX(yk) >= 0x4 && !have_bit(bb_your_shi, RightBB[0x4])){
				RETRUN_MUL(1);
			}
		}
	}
	


	
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(EV_MY_CAN <= 1){
			RETRUN_MUL(2);
		}
		// fen 5k3/9/4b4/9/6b2/6B2/9/4B1p2/2p1A1p2/3K1A3 w - - 120 120
		//2个兵到了二线,另一个兵也在一边
		//如果没有高兵了,且对方的将在外面,就一般是和棋,我方没有
		Bitboard P = m_and(bb_my_pawn,MyUpBB[MY_RANK3]);
		if(count_1s(P) == 3){
			if(StoX(yk) < 4 && PB90(MY_SQ15) != your_shi){
				if(count_1s(P,LeftBB[0x4]) <= 1){
					RETRUN_MUL(2);
				}
			}
			if(StoX(yk) > 4 && PB90(MY_SQ17) != your_shi){
				if(count_1s(P,RightBB[0x4]) <= 1){
					RETRUN_MUL(2);
				}
			}
		}
		// fen 3k1a3/1PP1aP3/4b4/9/6b2/2B6/9/3AB4/9/3AK4 b - - 0 1
		if(StoY(yk) == MY_RANK0){
			P = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
			if(count_1s(P) == 3 && PB90(MY_SQ16) == your_xiang){
				if(yk == MY_SQ03 && PB90(MY_SQ15) == NO_PIECE){
					P = m_and(P,LeftBB[0x4]);
					if(count_1s(P) == 2){
						RETRUN_MUL(2);
					}
				}
				if(yk == MY_SQ05 && PB90(MY_SQ17) == NO_PIECE){
					P = m_and(P,RightBB[0x4]);
					if(count_1s(P) == 2){
						RETRUN_MUL(2);
					}
				}
			}
		}
	}

	//  fen 5k3/2PPa4/3a4b/6P2/2b6/9/9/9/9/4K4 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2) {
		Bitboard P = m_and(bb_my_pawn, MyUpBB[MY_RANK2]);

		if (StoX(yk) == 0x5 && count_1s(m_and(P, LeftBB[0x4])) == 2) {
			if (PB90(MY_SQ15) == your_shi && PB90(MY_SQ17) != your_shi) {
				RETRUN_MUL(2);
			}
		}
		if (StoX(yk) == 0x3 && count_1s(m_and(P, RightBB[0x4])) == 2) {
			if (PB90(MY_SQ17) == your_shi && PB90(MY_SQ15) != your_shi) {
				RETRUN_MUL(2);
			}
		}
	}

	// fen 5P3/4P4/b2Pbk3/9/9/2B6/9/3A1A3/9/2B1K4 b - - 0 1
    if(StoY(yk) == MY_RANK2 && your_xiang_num == 2){
		Bitboard P = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
		if(count_1s(P) == 2){
			P = m_and(bb_my_pawn,RankBB_A[MY_RANK2]);
			if(StoX(yk) == 0x5 && have_bit(P,LeftBB[0x4])){
				RETRUN_MUL(2);
			}
			if(StoX(yk) == 0x3 && have_bit(P,RightBB[0x4])){
				RETRUN_MUL(2);
			}
		}
	} 

	// fen 5k3/2PPa4/4ba3/9/9/2P6/9/9/4K4/2B3B2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && EV_MY_CAN <= 2){
		Bitboard bp = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
		if(count_1s(bp) == 2 && PB90(MY_SQ16) == your_xiang){
			if(!have_bit(bb_my_pawn,LeftBB[0x4]) || !have_bit(bb_my_pawn,RightBB[0x4])){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 3k5/1PP1a4/2P1ba3/9/2b6/6B2/9/9/5K3/3A1AB2 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2) {
		if (!have_bit(bb_my_pawn, MyLowBB[MY_RANK2])) {
			if (MY_SQ03 == yk && PB90(MY_SQ15) != your_shi 
				&& !(PB90(MY_SQ12) == your_xiang && PB90(MY_SQ26) == your_xiang)){
				if (!have_bit(bb_my_pawn, RightBB[0x2])) {
					RETRUN_MUL(2);
				}
			}
			if (MY_SQ05 == yk && PB90(MY_SQ17) != your_shi 
				&& !(PB90(MY_SQ1A) == your_xiang && PB90(MY_SQ2A) == your_xiang)) {
				if (!have_bit(bb_my_pawn, LeftBB[0x6])) {
					RETRUN_MUL(2);
				}
			}
		}
	}

	//  fen 2P2k3/1P2a4/2P2a3/9/2b6/6B2/9/8B/4K4/3A1A3 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1) {
		if (!have_bit(bb_my_pawn, MyLowBB[MY_RANK2]) && have_bit(bb_my_pawn,RankBB_A[MY_RANK0])) {
			if (StoX(yk) >= 0x4 && !have_bit(bb_your_shi, LeftBB[0x4])) {
				if (!have_bit(bb_my_pawn, RightBB[0x3])) {
					RETRUN_MUL(2);
				}
			}
			if (StoX(yk) <= 0x4 && !have_bit(bb_your_shi, RightBB[0x4])) {
				if (!have_bit(bb_my_pawn, LeftBB[0x5])) {
					RETRUN_MUL(2);
				}
			}
		}
	}

 	// fen 3a1a3/4k4/9/9/9/9/9/1p3A2B/4App2/3K5 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1){
		Bitboard P = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
		if(count_1s(P) >= 2){
			if(StoX(yk) == 0x5 && PB90(MY_SQ17) != your_shi){
				Bitboard p1 = m_and(P,LeftBB[0x4]);
				if(count_1s(p1) == 2){
					Bitboard p2 = m_and(bb_my_pawn,RightBB[0x4]);
					if(have_bit(MyUpBB[MY_RANK3],p2)){
						RETRUN_MUL(4);
					}
				}
			}
			if(StoX(yk) == 0x3 && PB90(MY_SQ15) != your_shi){
				Bitboard p1 = m_and(P,RightBB[0x4]);
				if(count_1s(p1) == 2){
					Bitboard p2 = m_and(bb_my_pawn,LeftBB[0x4]);
					if(have_bit(MyUpBB[MY_RANK3],p2)){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 4k4/1PPPa4/5a2b/9/9/6B2/9/3A4B/9/3A1K3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
			if(!have_bit(bb_my_pawn,RightBB[0x4])){
				if(PB90(MY_SQ05) != your_shi){
					RETRUN_MUL(4);
				}
			}
			if(!have_bit(bb_my_pawn,LeftBB[0x4])){
				if(PB90(MY_SQ03) != your_shi){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 3akab2/3P5/4b2P1/9/9/2B3P2/9/8B/9/5K3 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if (EV_MY_CAN <= 2){
			if (have_bit(bb_my_pawn, MyLowBB[MY_RANK4])){
				Bitboard upp = m_and(bb_my_pawn, MyUpBB[MY_RANK3]);
				if (count_1s(upp) == 2){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 3akab2/3P5/4b2P1/9/9/2B3P2/9/8B/9/5K3 b - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0) {
		if (!have_bit(bb_my_pawn, MyLowBB[MY_RANK2])) {
			if (!have_bit(bb_my_pawn, LeftBB[0x6])) {
				RETRUN_MUL(8);
			}
			if (!have_bit(bb_my_pawn, RightBB[0x2])) {
				RETRUN_MUL(8);
			}
		}
	}

	// fen 5a3/3k5/4ba3/9/2b6/9/3p5/4B3B/3KAp3/5p3 w - - 253 253
	// fen 9/5k3/4b4/9/6b2/6B2/9/4B4/3pAp3/4KAp2 w - - 0 0
}

//我方3兵，对方 0 attacker
//void m_MT_B_3pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	BothOnlyPawnEval(board);
//	int bcan = BpawnCanOverLiver(board);
//	
//	int UpKing = 0;
//
//	int L1 = 0;
//	int L2 = 0;  //大于2线的兵
//	int L3 = 0;  //大于3线的兵
//
//	Square rk = PieceListStart(board,RKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			UpKing ++;
//			board->mulScore -=  ADD_Only_Pawn_NoCheMaPaoByShi[board->R_shi];
//		}
//
//		if(StoY(from) < 0xa){
//			L3 ++;
//		}
//		if(StoY(from) == 0xb){
//			L2 ++;
//		}
//		if(StoY(from) == 0xc){
//			L1 ++;
//		}
//	}
//
//	if(UpKing == 0){
//		if(board->R_xiang != 0){
//			//board->mulScore = 0;
//			return 1;
//		}
//	}
//
//	// fen 5k3/9/4b4/9/6b2/6B2/9/4B1p2/2p1A1p2/3K1A3 w - - 120 120
//	//二个兵到了二线,另一个兵也在一边
//	//如果没有高兵了,且对方的将在外面,就一般是和棋,我方没有
//	if(board->R_shi == 2 && board->R_xiang == 2){
//
//		if(bcan <= 1){
//			return 1;
//		}
//
//		if(L3 == 0){
//			if(board->b256[0xc7] != RKING && board->b256[0xa6] != RSHI && board->b256[0xa8] != RSHI){
//				return 1;
//			}
//		}
//	}
//
//	// fen 5a3/3k5/4ba3/9/2b6/9/3p5/4B3B/3KAp3/5p3 w - - 253 253
//	if(board->R_xiang == 2 && board->R_shi >= 1 && StoY(rk) == 0xb){
//		if(L3 <= 1){
//			if(L1 >= 1 && (L1+L2) >= 2){
//				int k = 0;
//				if(StoX(rk) == 0x6){
//					for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//						if(StoX(from) <= 0x7 && StoY(from) <= 0xb){
//							k++;
//						}
//					}
//				}
//				if(StoX(rk) == 0x8){
//					for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//						if(StoX(from) >= 0x7 && StoY(from) <= 0xb){
//							k++;
//						}
//					}
//				}
//				if(k <= 1){
//					return 1;
//				}
//			}
//		}
//	}
//
//	*/
//}
#ifndef END_my_m_MT_R_1ma3pawn_B_1ma1pawn
#define END_my_m_MT_R_1ma3pawn_B_1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马3兵对1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//只有2个兵可过河
//const int PawnOnlyCanTwo = 256;

//1马3兵对马兵
void my_m_MT_R_1ma3pawn_B_1ma1pawn(typePOS &POSITION, EvalInfo &ei){
	
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_MaPawn_To_MaPawnByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_MaPawn_To_MaPawnByShi[my_shi_num]);

	Square mma = S90_from_piecelist(POSITION, my_ma, 0);

	// fen 2b1k4/4a4/3ab4/6P2/N5p2/2P6/P8/4B3n/4K4/2B6 b
	if(EV_YOUR_CAN == 0){
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	if(StoY(ypawn) MY_LARGE_EQL StoY(mk)){
		MY_EV_ADD(32);
		MY_EV_ADD(EV_MY_CAN * 32);
		if(abs(StoX(ypawn) - StoX(mk)) >= 3){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}



	// fen 4k4/4a2P1/b3b4/9/9/2P1n1P2/4N4/5K3/2p1A4/9 b - - 0 1
	if (EV_MY_CAN <= 1){
		if (your_xiang_num == 2 && your_shi_num >= 1){
			MY_EV_SUB(32);
			if (my_xiang_num == 0){
				Bitboard mp = m_and(bb_my_pawn, MyLowBB[MY_RANK4]);
				mp = m_and(mp, m_or(FileBB_A[0x2], FileBB_A[0x6]));
				if (count_1s(mp) == 2){
					MY_EV_SUB(32);
					if (StoY(mma)  MY_LARGE_EQL MY_RANK6){
						MY_EV_SUB(32);
					}
				}
			}
		}
	}

	// fen 5kb2/4a1PP1/3ab1P2/3N5/9/6B2/9/1n1KB4/4Ap3/5A3 b - - 122 122
	//三个兵在一边, 且没有一个是在肋道的, 也是和棋
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		Bitboard p = m_and(bb_my_pawn,MyUpBB[MY_RANK3]);
		if(count_1s(p) == 3){
			Bitboard p1 = m_and(p,MyUpBB[MY_RANK2]);
			if(count_1s(p1) >= 2){
				Bitboard p2 = m_and(p,LeftBB[0x4]);
				if(count_1s(p2) == 3 && PB90(MY_SQ0C) != my_pawn){
					RETRUN_MUL(2);
				}
				p2 = m_and(p,RightBB[0x4]);
				if(count_1s(p2) == 3 && PB90(MY_SQ0E) != my_pawn){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 2b6/4a3N/3kb4/8p/5np2/8P/9/3AB4/2p1A4/5KB2 w - - 121 121
	//只有一个兵可过河,对方仕相全,也是和棋
	int mcan = EV_MY_CAN;
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if(mcan <= 1){
			RETRUN_MUL(2);
		}

		// fen 3a1k3/9/3a4b/p3p4/2n6/2N3B2/P8/4B4/4A1p2/4KA3 w - - 120 120
		//顶死一个兵, 另二个兵不能过河
		Bitboard p = m_and(bb_my_pawn,MyUpBB[MY_RANK4]);
		if(count_1s(p) >= 1 && PB90(MY_SQ3A) == my_pawn){
			if(PB90(MY_SQ2A) == your_ma && PB90(MY_SQ23) == your_pawn){
				if(PB90(MY_SQ3E) == my_pawn){
					RETRUN_MUL(2);
				}
			}
			if(PB90(MY_SQ26) == your_ma && PB90(MY_SQ1B) == your_pawn){
				if(PB90(MY_SQ36) == my_pawn){
					RETRUN_MUL(2);
				}
			}
		}
	}
	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	
	// fen 3k5/4P4/2nN5/9/2p6/9/9/4B4/5K1p1/2B5p b - - 151 151
	if(mcan <= 1){
		Bitboard p = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
		if(count_1s(p) >= 2 && StoY(yk) MY_LARGE_EQL MY_RANK1){
			if(my_shi_num == 0 && PB90(MY_SQ4C) == your_pawn && StoX(yk) != StoX(yma)){
			   if(PB90(MY_SQ44) == your_ma && PB90(MY_SQ45) == my_ma && PB90(MY_SQ56) == my_king){
				   RETRUN_MUL(4);
			   }
			   if(PB90(MY_SQ42) == your_ma && PB90(MY_SQ41) == my_ma && PB90(MY_SQ54) == my_king){
				   RETRUN_MUL(4);
			   }
			}
		}
	}

	// fen 4k4/4aP3/3ab3b/9/P1pn5/2B1N4/2P6/5A3/9/2B1K4 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && EV_MY_CAN <= 2){
		if (PB90(MY_SQ38) == my_pawn && PB90(MY_SQ26) == your_pawn){
			if (bit_is_set(YOUR_ATTACK, MY_SQ38)){
				RETRUN_MUL(4);
			}
		}
		if (PB90(MY_SQ3C) == my_pawn && PB90(MY_SQ2A) == your_pawn){
			if (bit_is_set(YOUR_ATTACK, MY_SQ3C)){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 2bk5/4a4/2P1b4/9/5n2p/2P2N3/8P/5A3/4A4/2B1K1B2 b - - 0 1
    if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(EV_MY_CAN <= 1){
			Bitboard mp = m_and(bb_my_pawn,MyUpBB[MY_RANK3]);
			if(count_1s(mp) == 1){
				Square po = pop_1st_bit_sq(mp);
				if(abs(StoX(po) - 0x4) >= 2 || abs(StoX(po) - StoX(mk)) >= 2){
					RETRUN_MUL(8);
				}
			}
		}
	}
		
	//如果有一个兵不能过河,也要降一些分
	// fen 2N2k3/3P2P2/3a1a2b/9/4n3p/2B6/8P/3AB4/4A4/4K4 w - - 125 125
	if(your_shi_num == 2 && your_xiang_num >= 1){
		if(mcan <= 2){
			RETRUN_MUL(8);
		}
	}
	//如果对方是仕相全,也要减一些分界线
	// fen 2b1k4/4a4/2Pab1P2/P2N5/9/9/5n3/3pB4/5K3/2B6 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		//RETRUN_MUL(8);
	}
}

//1马3兵对马兵
//void m_MT_B_1ma3pawn_R_1ma1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	Square bpawn1 = PieceListStart(board,BPAWN);
//	Square bpawn2 = NextPiece(board,bpawn1);
//	Square bpawn3 = NextPiece(board,bpawn2);
//	int bcan = BpawnCanOverLiver(board);
//
//	int pawnTo2line = 0;   //兵到了二线
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_MaPawn_To_MaPawnByShi[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_MaPawn_To_MaPawnByShi[board->R_shi];
//		}
//
//		if(StoY(from) >= 0xb){
//			pawnTo2line ++;
//		}
//	}
//
//	// fen 5kb2/4a1PP1/3ab1P2/3N5/9/6B2/9/1n1KB4/4Ap3/5A3 b - - 122 122
//	//三个兵在一边, 且没有一个是在肋道的, 也是和棋
//	if(board->R_shi == 2 && board->R_xiang == 2){
//		if(StoY(rk) == 0xc){
//			//有几个兵到了底线
//			//for(int 
//			//三个兵在一边
//			if(FALSE){
//			}
//			else if(StoX(bpawn1) > 0x7 && StoX(bpawn2) > 0x7 && StoX(bpawn2) > 0x7){
//				if(board->b256[0xb8] == BPAWN){
//				}
//				else{
//					if(pawnTo2line >= 2){
//						return 1;
//					}
//				}
//			}
//			else if(StoX(bpawn1) < 0x7 && StoX(bpawn2) < 0x7 && StoX(bpawn2) < 0x7){
//				if(board->b256[0xb6] == BPAWN){
//				}
//				else{
//					if(pawnTo2line >= 2){
//						return 1;
//					}
//				}
//			}
//		}
//	}
//
//	// fen 2b6/4a3N/3kb4/8p/5np2/8P/9/3AB4/2p1A4/5KB2 w - - 121 121
//	//只有一个兵可过河,对方仕相全,也是和棋
//	if(board->R_shi == 2 && board->R_xiang == 2){
//		if(StoY(rk) == 0xc){
//			if(bcan <= 1){
//				return 1;
//			}
//		}
//	}
//
//	// fen 3a1k3/9/3a4b/p3p4/2n6/2N3B2/P8/4B4/4A1p2/4KA3 w - - 120 120
//    //顶死一个兵, 另二个兵不能过河
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//		//黑方有一个兵已到了三线以上
//		if(StoY(bpawn1) >= 0xa || StoY(bpawn2) >= 0xa || StoY(bpawn3) >= 0xa){
//			if(board->b256[0x67] == BPAWN){
//				if(board->b256[0x85] == RMA && board->b256[0x75] == BMA){
//					if(board->b256[0x93] == RPAWN && board->b256[0x63] == BPAWN){
//						return 1;
//					}
//				}
//				if(board->b256[0x89] == RMA && board->b256[0x79] == BMA){
//					if(board->b256[0x9b] == RPAWN && board->b256[0x6b] == BPAWN){
//						return 1;
//					}
//				}
//			}
//		}
//	}
//
//	int pblow = 0;	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) == 0xc || (StoY(from) == 0xb && StoY(rk) <= 0xb)){
//			pblow ++;
//		}
//	}
//	// fen 3k5/4P4/2nN5/9/2p6/9/9/4B4/5K1p1/2B5p b - - 151 151
//	if(board->b256[0x47] == RPAWN && board->B_shi == 0 && board->R_xiang == 2){
//		if(board->b256[0x56] == RMA && board->b256[0x36] == BKING && StoX(rk) != 0x6){
//			if(board->b256[0x55] == BMA || board->b256[0x63] == BMA){
//				if(board->b256[0x75] == BPAWN || board->b256[0x79] == BPAWN){
//					if(pblow == 2) return 1;
//				}
//			}
//		}
//		if(board->b256[0x58] == RMA && board->b256[0x38] == BKING && StoX(rk) != 0x8){
//			if(board->b256[0x59] == BMA || board->b256[0x6b] == BMA){
//				if(board->b256[0x75] == BPAWN || board->b256[0x79] == BPAWN){
//					if(pblow == 2) return 1;
//				}
//			}
//		}
//	}
// 
//
//
//	//如果有一个兵不能过河,也要降一些分
//	// fen 2N2k3/3P2P2/3a1a2b/9/4n3p/2B6/8P/3AB4/4A4/4K4 w - - 125 125
//	if(board->R_shi == 2 && board->R_xiang >= 1){
//		if(bcan <= 2){
//			//board->mulScore += PawnOnlyCanTwo;
//			return 8;
//		}
//	}
//
//	//如果对方是仕相全,也要减一些分界线
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//		return 8;
//	}
//
//	*/
//}
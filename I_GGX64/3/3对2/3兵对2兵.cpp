#ifndef END_my_m_MT_R_3pawn_B_2pawn
#define END_my_m_MT_R_3pawn_B_2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "3兵对2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//3兵对1兵
void my_m_MT_R_3pawn_B_2pawn(typePOS &POSITION, EvalInfo &ei){

	BothOnlyPawnEval(POSITION,ei);
	Square mk = my_king_pos;
	Square yk = your_king_pos;

	//如果一个兵过去了, 但二个兵顶住了,也是和棋
	// fen 5a3/3kaP3/8b/p7p/6b2/P7P/9/4B4/9/2BAKA3 b - - 0 0
	// fen 5a3/3ka4/8b/p7p/6b2/P7P/4P4/4B4/9/2BAKA3 b

	// 求红方可过兵的数量
	// 求我方的兵是不是可能吃对方的兵, 能吃一个,则加一个过兵的数量
	// 求黑方可过兵的数量

	// fen 4k4/3Pa4/3aP4/8p/9/2B5P/4p4/3A5/4A4/2B2K3 b - - 0 1
	if(your_shi_num == 2 && EV_MY_CAN <= 2){
		MY_EV_SUB(80);
	}


	// fen 4k4/3Pa4/4b4/9/p5b1p/2P3B2/8P/9/4A4/4K4 b - - 0 0
    //兵对兵对的加分
    // fen 2bak4/4a4/9/p2P5/6b2/P3P3p/9/4B4/4A4/5K3 w - - 4 4
	if(my_shi_num == 2){
		EV_MY_SAFE = TRUE;
	}
	if(my_shi_num >= 1 && EV_YOUR_CAN <= 1){
		EV_MY_SAFE = TRUE;
	}

	if((your_shi_num + your_xiang_num) == 4){
		Bitboard ghp = m_and(bb_your_pawn,
			m_or(RankBB_A[MY_RANK5],RankBB_A[MY_RANK6])); // 兵线有兵，可起挡将的作用
		if(m_have_bit(ghp)){
			EV_YOUR_SAFE = TRUE;
		}
	}

	// fen 9/3ka4/2Pab4/2PP5/6b2/9/9/3AB4/1p4p2/3AK4 b - - 0 1
	if ((your_shi_num + your_xiang_num) == 4){
		if (EV_YOUR_CAN >= 2){
			MY_EV_SUB(32);
			if (StoX(mk) != StoX(yk)){
				MY_EV_SUB(64);
			}
		}
	}

	// fen 3a5/5PP2/3kba3/9/p1p3b2/6B2/P8/4BA3/9/3AK4 b - - 0 1
	if(EV_MY_SAFE){
		if(your_xiang_num == 2 && your_shi_num >= 1){
			if(EV_MY_CAN <= 2){
			    Bitboard bmp = m_and(bb_my_pawn,MyUpBB[StoY(yk)]);
				if(count_1s(bmp) == 2){
					RETRUN_MUL(2);
				}
			}
		}
	}

	//
	// fen 4k4/9/3a1a3/p7p/2b3b2/P3p3P/9/4BA3/9/2B1KA3 b - - 0 0
	if(your_xiang_num == 2 && PB90(MY_SQ16) == your_xiang){
		if(PB90(MY_SQ24) == your_pawn && PB90(MY_SQ36) == my_pawn
			&& PB90(MY_SQ25) != my_pawn){
				if(PB90(MY_SQ2C) == your_pawn && PB90(MY_SQ3E) == my_pawn
					&& PB90(MY_SQ2B) != my_pawn){
						RETRUN_MUL(2);
				}
		}
	}

	// fen 3k1a3/4aP3/4b4/1P3P3/9/9/4p4/5A3/2p1K4/3A2B2 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(have_bit(bb_your_pawn,RankBB_A[MY_RANK6])){
				RETRUN_MUL(4);
			}
		}
	}


	// fen 4k4/3Pa4/3aP4/8p/9/2B5P/4p4/3A5/4A4/2B2K3 b - - 0 1
	if(EV_MY_SAFE){
		if(EV_MY_CAN <= 2 && EV_YOUR_CAN >= 1){
			if(count_1s(bb_my_pawn,MyUpBB[MY_RANK3]) == 2){
				if(have_bit(bb_your_pawn,RankBB_A[MY_RANK6])){
					RETRUN_MUL(4);
				}
				RETRUN_MUL(8);
			}
		}

	}

	int ycan = EV_YOUR_CAN;

	// fen 4k4/3PaP3/3ab4/3P5/2b6/9/9/B4A3/3p1p3/3AK4 w - - 35 35
	if(my_shi_num >= 1){
		if(ycan == 2 && your_shi_num == 2 && your_xiang_num == 2){
			RETRUN_MUL(8);
		}
	}
}

//3兵对1兵
//void m_MT_B_3pawn_R_2pawn(typePOS &POSITION, EvalInfo &ei){
//	/*
//    BothOnlyPawnEval(board);
//
//	Square rpawn1 = PieceListStart(board,RPAWN);
//	Square rpawn2 = NextPiece(board,rpawn1);
//
//
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//
//	if(board->B_shi != 0){
//		board->bsafe = TRUE;
//	}
//
//	// fen 2bak4/4a4/9/p2P5/6b2/P3P3p/9/4B4/4A4/5K3 w - - 4 4	
//	if((StoY(rpawn1) < 0x8 && StoY(rpawn1) > 0x5)
//		|| (StoY(rpawn2) < 0x8 && StoY(rpawn2) > 0x5)){
//			if(board->R_shi == 2 && board->R_xiang == 2){
//				board->rsafe = TRUE;
//			}
//	}
//
//	// fen 4k4/9/3a1a3/p7p/2b3b2/P3p3P/9/4BA3/9/2B1KA3 b - - 0 0
//	if(board->R_xiang == 2 && board->b256[0xa7] == RXIANG){
//		if(board->b256[0x63] == BPAWN && board->b256[0x83] == RPAWN
//			&& board->b256[0x6b] == BPAWN && board->b256[0x8b] == RPAWN){
//				if(board->b256[0x84] != BPAWN && board->b256[0x8a] != BPAWN){
//					return 2;
//				}
//		}
//	}
//
//	// fen 4k4/3PaP3/3ab4/3P5/2b6/9/9/B4A3/3p1p3/3AK4 w - - 35 35
//	if(board->B_shi >= 1){
//		if(StoY(rpawn1) > StoY(bk) && StoY(rpawn2) > StoY(bk)){
//			if(board->R_shi == 2 && board->R_xiang == 2 && rk == 0xc7){
//				return 8;
//			}
//		}
//	}
//
//   
//
//	*/
//}
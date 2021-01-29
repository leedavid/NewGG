#ifndef END_my_m_MT_R_1MA1PAWN_B_2PAWN
#define END_my_m_MT_R_1MA1PAWN_B_2PAWN
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1马1兵对2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//void my_m_MT_R_1MA1PAWN_B_1PAWN(board_t *board)

//const int MaPawnAdd = 96;
//const int KingMid   = 24;

//我方马兵，对方2兵
void my_m_MT_R_1MA1PAWN_B_2PAWN(typePOS &POSITION, EvalInfo &ei){
	

	MY_EV_ADD(96);

	Square mk    = my_king_pos;
	Square yk    = your_king_pos;
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square mma   = S90_from_piecelist(POSITION,my_ma,0);

	int ycan  = EV_YOUR_CAN;
	int mcan  = EV_MY_CAN;

	if (my_shi_num == 2){
		EV_MY_SAFE = true;
	}
	
	Bitboard ylp = m_and(bb_your_pawn, MyLowBB[StoY(mk)]);
	if (count_1s(ylp) == 2){
		EV_MY_SAFE = true;
	}
	if (EV_YOUR_CAN <= 1){
		EV_MY_SAFE = true;
	}

	if(StoX(mk) == 0x4){
		MY_EV_ADD(64);
	}
	// 我方的兵到底了
	if(StoY(mpawn) == MY_RANK0){
		RETRUN_MUL(2);
	}
	// fen 4k4/3Pa4/3a5/9/6N2/7p1/2p6/B3B4/4A4/3A1K3 w - - 0 1
	if(your_xiang_num == 0 && StoY(yk) == MY_RANK0){
		if(MY_SQ0C == mpawn && StoX(mk) == 0x5 && PB90(MY_SQ15) == your_shi){
			if(!have_bit(bb_your_pawn,FileBB_A[0x5])){
				RETRUN_MUL(16);
			}
		}
		if(MY_SQ0E == mpawn && StoX(mk) == 0x3 && PB90(MY_SQ17) == your_shi){
			if(!have_bit(bb_your_pawn,FileBB_A[0x3])){
				RETRUN_MUL(16);
			}
		}
	}
	
	// fen 3a5/3k1P3/9/6N2/9/9/3p5/9/9/4K4 w - - 0 0 
	// 卒士弈和馬低兵，須弈成本局士在將底，即“太公坐椅”形式互相保護，士藏將底，紅無法可勝，最後用卒走閑。倘若兵位於三線以上，即屬必勝。
	if(your_shi_num >= 1){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK2){
			if(StoX(mpawn) > 0x4 && PB90(MY_SQ03) == your_shi && StoX(yk) == 0x3){
				RETRUN_MUL(2);
			}
			if(StoX(mpawn) < 0x4 && PB90(MY_SQ05) == your_shi && StoX(yk) == 0x5){
				RETRUN_MUL(2);
			}
		}
	}

	//fen 2b6/3k3P1/3N5/9/6b2/2B6/9/3K4B/2p1Ap3/5A3 b - - 0 1
	if (EV_MY_SAFE){
		if (StoY(mpawn) MY_SMALL_EQL StoY(yk) && !IsOnSameSide(mpawn,yk)){
			if (your_xiang_num >= 1 || EV_YOUR_CAN >= 1){
				if (isStringByChe(POSITION, mk, mma, yk) && StoY(mma) MY_SMALL_EQL MY_RANK2){
					if (abs(StoY(mma) - StoY(yk)) <= 1){
						RETRUN_MUL(2);
					}
				}
			}
		}
	}

	// fen 4k4/4aP3/3a5/9/9/9/9/2n1p4/3KA4/5A3 w - - 127 127 
	if(ycan >= 1 && your_shi_num == 2){
		if(MY_SQ16 == mpawn && PB90(MY_SQ0D) == your_shi){
			RETRUN_MUL(2);
		}

       if(count_1s(bb_your_pawn, m_or(RankBB_A[MY_RANK5],RankBB_A[MY_RANK6])) >= 1){
		   RETRUN_MUL(2);
	   }
	}

	// fen 4k4/4a4/9/9/p8/4n1P2/P8/9/4A4/2BA1K3 w - - 120 120
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(ycan >= 1 && mcan == 0){
			RETRUN_MUL(4);
		}
	}

	my_m_MT_R_1MA1PAWN_B_NO(POSITION,ei);

	// fen 3ak4/3Pa4/9/9/p1N6/6B2/9/3A5/6p2/3A1KB2 b - - 0 1
	if(your_shi_num == 2 && EV_YOUR_CAN >= 1 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
		if(StoY(mma) MY_LARGE_EQL MY_RANK4){
			if(StoX(mpawn) < 0x4 && PB90(MY_SQ03) == your_shi){
				RETRUN_MUL(8);
			}
			if(StoX(mpawn) > 0x4 && PB90(MY_SQ05) == your_shi){
				RETRUN_MUL(8);
			}
		}
	}
	
	// fen 2ba5/4ak3/b8/2P6/9/1pP1n4/9/4BA3/4A4/2BK5 b
}

//我方马兵，对方2兵
//void m_MT_B_1MA1PAWN_R_2PAWN(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk     = PieceListStart(board,BKING);
//	Square rk     = PieceListStart(board,RKING);
//	Square bpawn  = PieceListStart(board,BPAWN);
//
//	Square rpawn1  = PieceListStart(board,RPAWN);
//	Square rpawn2  = NextPiece(board,rpawn1);
//
//	//其它的棋子的信息
//	//uint16 OthInfo = Info16 & (CK_R_2x + CK_R_1x + CK_R_2s + CK_R_1s);
//	board->mulScore -= MaPawnAdd;
//
//	if(StoX(bk) == 0x7){
//		board->mulScore -= KingMid;
//	}
//
//	//我方的兵到底了
//	if(bpawn > 0xc0){
//		board->mulScore /= 8;
//		return 1;
//	}
//
//	if(board->R_shi != 0){
//		if(StoY(bpawn) > 0xa){
//			//	// fen 3a5/3k1P3/9/6N2/9/9/3p5/9/9/4K4 w - - 0 0 
//			//	//卒士弈和馬低兵，須弈成本局士在將底，即“太公坐椅”形式互相保護，士藏將底，紅無法可勝，最後用卒走閑。倘若兵位於三線以上，即屬必勝。
//			if((StoX(bpawn) > 0x7 && board->b256[0xc6] == RSHI && StoX(rk) == 0x6)
//				||(StoX(bpawn) < 0x7 && board->b256[0xc8] == RSHI && StoX(rk) == 0x8)){
//					return 1;
//			}
//		}
//	}
//
//	//马高兵对卒双仕的一个和型
//	// fen 4k4/4aP3/3a5/9/9/9/9/2n1p4/3KA4/5A3 w - - 127 127 
//	if(board->R_shi == 2){
//		//红兵给二个仕控制住了
//		if(bpawn == 0xa7 && board->b256[0xb7] == RSHI){
//			return 1;
//		}
//
//		// fen 4k4/3Pa4/3a5/9/9/9/6N2/5K2B/4A3p/3A3p1 w - - 51 51
//
//		//如果黑兵过河了
//		if(rpawn1 < 0x80 && StoY(rpawn1) >= 0x6){
//			return 1;
//		}
//
//		//如果黑兵过河了
//		if(rpawn2 < 0x80 && StoY(rpawn2) >= 0x6){
//			return 1;
//		}
//	}
//
//	int bcan = BpawnCanOverLiver(board);
//	int rcan = RpawnCanOverLiver(board);
//
//	// fen 4k4/4a4/9/9/p8/4n1P2/P8/9/4A4/2BA1K3 w - - 120 120
//	if(board->R_shi == 2 && board->R_xiang >= 1 && StoY(rk) >= 0xb){
//		if(rcan >= 1 && bcan == 0){
//			return 4;
//		}
//	}
//
//   return m_MT_B_1MA1PAWN_R_NO(board);/*/
//
//}
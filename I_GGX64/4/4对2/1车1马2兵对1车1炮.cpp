#ifndef END_my_m_MT_R_1che1ma2pawn_B_1che1pao
#define END_my_m_MT_R_1che1ma2pawn_B_1che1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1马2兵对1车1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int const_Pawn_Add = 32;

void my_m_MT_R_1che1ma2pawn_B_1che1pao(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_CheMaPawn_ChePao_ByPawnByShi[your_shi_num]);

	//如果对方是仕相全，则

	Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);
	Square ypao   = S90_from_piecelist(POSITION,your_pao,0);
	Square mma = S90_from_piecelist(POSITION, my_ma, 0);
	// fen 8r/9/4k4/1R6p/4C4/p4n3/9/4B4/4A4/2BAK4 b - - 0 0
	if(my_shi_num == 0 && my_xiang_num == 0){
		if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
			if(StoY(mpawn1) MY_LARGE_EQL MY_RANK4 && StoY(mpawn2) MY_LARGE_EQL MY_RANK4){
				if(abs(StoX(mpawn1) - StoX(mpawn2)) >= 5){
					MY_EV_SUB(96);
				}
			}
		}
	}
	//红方有连兵要加分
	// fen 3k1ab2/4a4/6c1b/3PP4/6r2/4R4/4N4/9/4K4/9 w - - 0 1
	Bitboard mlp = My_get_connect_Pawn(POSITION);
	if(have_bit(mlp,RankBB_A[MY_RANK3])){
		MY_EV_ADD(64);
	}

	// fen 3ck1b2/4a4/5a3/9/4P3P/6RN1/9/9/4K4/5r3 b - - 0 1
	if ((your_shi_num + your_xiang_num) <= 3){
		MY_EV_ADD(32);
		if (count_1s(bb_my_pawn, MyUpBB[MY_RANK5]) >= 2){
			MY_EV_ADD(32);
			if (StoY(mma) MY_SMALL_EQL MY_RANK5){
				MY_EV_ADD(32);
			}
		}
	}

	// fen 2bak1b2/4a4/9/8R/4P4/7NP/P8/9/c3K4/8r b - - 0 1
	if (StoY(mma) MY_SMALL_EQL MY_RANK5){
		if (have_bit(bb_my_pawn, MyUpBB[MY_RANK5])){
			if (StoY(ypao) MY_LARGE_EQL MY_RANK4){
				MY_EV_ADD(EV_MY_CAN * 16);
			}
		}
	}

	// fen 2b2k3/4a4/4ba3/PN7/1r7/4P1B2/9/4B4/1c7/1R1AKA3 b - - 72 72
	int malr = My_pawn_already_over_river(POSITION);
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if(malr <= 1){
			if((my_shi_num + my_xiang_num) >= 2){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3ckab2/4aP3/1R2b4/9/3rNP3/9/9/4BA3/4A4/2B2K3 b
	//对方组成了有效防守
	if((your_shi_num + your_xiang_num) == 4 && yk == MY_SQ04){
		if(PB90(MY_SQ28) == my_ma && StoY(ypao) == MY_RANK0){
		    Bitboard pb = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
			if(StoX(ypao) < 0x4){
				if(PB90(MY_SQ29) == my_pawn && PB90(MY_SQ27) == your_che){
					//看一下右边二一线上是不是有我方的兵
					if(count_1s(pb,RightBB[0x4]) == 1){
						MY_EV_SUB(256);
					}
				}
			}
			if(StoX(ypao) > 0x4){
				if(PB90(MY_SQ27) == my_pawn && PB90(MY_SQ29) == your_che){
					//看一下右边二一线上是不是有我方的兵
					if(count_1s(pb,LeftBB[0x4]) == 1){
						MY_EV_SUB(256);
					}
				}
			}
		}
	}

	// fen 5k3/9/9/p4r2p/3R5/n1B6/5p3/2C6/4A4/2B1KA3 b - - 0 1
	if((my_shi_num + my_xiang_num) == 0){
		if((your_shi_num + your_xiang_num) >= 1){
			MY_EV_SUB(64);
		}
	}

}

//void m_MT_B_1che1ma2pawn_R_1che1pao(typePOS &POSITION, EvalInfo &ei){
//	/*
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= ADD_CheMaPawn_ChePao_ByPawnByShi[board->R_shi];
//		}
//	}
//
//	//如果对方是仕相全，则
//
//	//premat_t* pMat = board->pMat;
//	//uint16 cInfo16 = pMat->sixiangInfo8;
//
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//
//	Square bpawn1 = PieceListStart(board,BPAWN);
//	Square bpawn2 = NextPiece(board,bpawn1);
//
//
//	// fen 8r/9/4k4/1R6p/4C4/p4n3/9/4B4/4A4/2BAK4 b - - 0 0
//	if(board->B_shi == 0 && board->B_xiang == 0){
//		if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//			if(StoY(bpawn1) <= 0x8 && StoY(bpawn2) <= 0x8){
//				if(abs(StoX(bpawn1) - StoX(bpawn2)) >= 0x5){
//					board->mulScore += 32;
//				}
//			}
//		}
//	}
//
//		// fen 2b2k3/4a4/4ba3/PN7/1r7/4P1B2/9/4B4/1c7/1R1AKA3 b - - 72 72
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//		if(BpawnAlreadyRiver(board) <= 1 && (board->B_xiang + board->B_shi) >= 2){
//			return 8;
//		}
//	}
//
//	//if((cInfo16 & CK_R_2s) && (cInfo16 & CK_R_2x)){		//对方仕相全
//	if(board->R_shi == 2 && board->R_xiang == 2 && (board->B_xiang + board->B_shi) >= 2){
//		if(rk == 0xc7){
//			return 8;
//		}
//	}	
//
//	*/
//}


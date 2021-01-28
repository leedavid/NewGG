#ifndef END_my_m_MT_R_3pawn_B_1pao
#define END_my_m_MT_R_3pawn_B_1pao
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "3兵对1炮.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//const int _3pawn1pao_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_3pawn_B_1pao(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;

	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pok = (int)count_1s(bmp);
	MY_EV_ADD(pok * ADD_XPawnToPao_ByPawnShi[your_shi_num]);

	//Square yk   = your_king_pos;
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);
	//Square mk   = my_king_pos;

	// fen 3a1kb2/1P5P1/3a5/4P4/9/2B3B2/6c2/9/3K5/9 b - - 62 62
	if(your_xiang_num == 2 && your_xiang_num >= 1 && StoX(yk) != MY_RANK0){
		EV_YOUR_SAFE = TRUE;
	}

	if(your_shi_num == 0){ //对方也没有仕,就和了
		EV_MY_SAFE = TRUE;
	}

	if(my_shi_num == 2 || my_xiang_num == 2){
		EV_MY_SAFE = TRUE;
	}

	// fen 9/4aPP2/3a1k3/9/8P/9/9/9/1c7/4K4 w - - 0 1
	if (my_shi_num == 0 && my_xiang_num == 0){
		if (your_shi_num == 2){
			MY_EV_SUB(64);
			if (count_1s(bb_my_pawn, MyUpBB[StoY(yk)]) >= 2){
				MY_EV_SUB(128);
			}
		}
	}

	// fen 5k3/1P4PP1/3a5/9/2b6/2c6/9/9/9/4K4 w - - 0 1
	if(your_shi_num >= 1 && your_xiang_num >= 1){
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
			MY_EV_SUB(64);
			if(StoX(yk) != 0x4){
				MY_EV_SUB(64);
				if(have_bit(LeftBB[0x2],bb_my_pawn)){
					MY_EV_SUB(64);
				}
				if(have_bit(bb_my_pawn,RightBB[0x6])){
					MY_EV_SUB(64);
				}
			}
		}
	}


	// fen 9/3k5/4b4/3C5/9/6B2/9/3A5/2p2p1p1/4K4 w - - 182 182
	if(your_shi_num >= 1 && your_xiang_num >= 1){
		Bitboard ptm = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
		if(count_1s(ptm) == 3){
			if(StoX(yk) == 0x4){
				if(PB90(MY_SQ15) == your_shi && PB90(MY_SQ0C) != your_pawn && StoX(ypao) == 0x3){
					RETRUN_MUL(2);
				}
				if(PB90(MY_SQ17) == your_shi && PB90(MY_SQ0E) != your_pawn && StoX(ypao) == 0x5){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 2P1k4/4aPP2/3a5/9/9/9/7c1/B3K4/4A4/6B2 b - - 0 1
	if(your_shi_num == 2){
		Bitboard ybmp = m_and(bb_my_pawn,MyUpBB[MY_RANK1]);
		if(count_1s(ybmp) >= 1){
			if(StoX(yk) == 0x4){
				RETRUN_MUL(4);
			}			
		}
		RETRUN_MUL(8);
	}

	// fen 3k1P3/2P2P3/5a2b/3c5/9/9/9/9/3K5/5A3 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num >= 1 && !have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
		if(have_bit(bb_my_pawn,MyUpBB[MY_RANK1])){  // 有底线兵
			//if(StoX(ypao) == StoX(mk)){
			//if(StoX(yk) != 0x4){
				if(StoX(yk) == 0x3 && count_1s(bb_my_pawn,RightBB[0x4]) == 2){
					 RETRUN_MUL(8);
				}
				if(StoX(yk) == 0x5 && count_1s(bb_my_pawn,LeftBB[0x4]) == 2){
					RETRUN_MUL(8);
				}
			//}
		}
	}

}

//void m_MT_B_3pawn_R_1pao(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	int rpao = PieceListStart(board,RPAO);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -=  ADD_XPawnToPao_ByPawnShi[board->R_shi];
//
//			//if(StoX(from) == 0x7){  //兵在中线
//			//	if(board->b256[from+1] == RPAWN || board->b256[
//			//}
//		}
//	}
//
//
//
//	// fen 3a1kb2/1P5P1/3a5/4P4/9/2B3B2/6c2/9/3K5/9 b - - 62 62
//	if(board->R_shi == 2 && board->R_xiang >= 1){
//		//如果将在外面,则是和棋
//		if(StoY(rk) == 0xc){
//			board->rsafe = TRUE;
//		}
//	}
//
//	if(board->R_shi == 0){						//对方也没有仕,就和了
//		board->bsafe = TRUE;
//	}
//
//	if(board->B_shi == 2 || board->B_xiang == 2){
//		board->bsafe = TRUE;
//	}
//
//
//	// fen 9/3k5/4b4/3C5/9/6B2/9/3A5/2p2p1p1/4K4 w - - 182 182
//	Square bpawn1 = PieceListStart(board,BPAWN);
//	Square bpawn2 = NextPiece(board,bpawn1);
//	Square bpawn3 = NextPiece(board,bpawn2);
//
//	if(StoY(bpawn1) >= 0xb && StoY(bpawn2) >= 0xb && StoY(bpawn3) >= 0xb){
//		if(StoY(rk) == 0xa){
//			board->rsafe = TRUE;
//		}
//		if(board->b256[0xc7] == RKING && StoY(rpao) < 0xa){
//			if(board->b256[0xa6] == RSHI && board->b256[0xb6] != BPAWN && StoX(rpao) == 0x6){
//				return 1;
//			}
//			if(board->b256[0xa8] == RSHI && board->b256[0xb8] != BPAWN && StoX(rpao) == 0x8){
//				return 1;
//			}
//		}
//	}
//    
//
//
//
//
//	*/
//}
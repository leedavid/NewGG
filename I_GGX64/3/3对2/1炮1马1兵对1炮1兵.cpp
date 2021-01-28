#ifndef END_my_m_MT_R_1ma1pao1pawn_B_1pao1pawn
#define END_my_m_MT_R_1ma1pao1pawn_B_1pao1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮1马1兵对1炮1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//
//const int  ADD_MAPAO_Xpawn_To_PAO1Pawn[3]           = {96, 64, 32};            //马炮对炮的优势分
//const int  ADD_PAO1Pawn_To_MAPAO_Xpawn[3]           = {96, 64, 32};            //马炮对炮的优势分


void my_m_MT_R_1ma1pao1pawn_B_1pao1pawn(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_MAPAO_Xpawn_To_PAO1Pawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_PAO1Pawn_To_MAPAO_Xpawn[my_shi_num]);

	MY_EV_ADD(64);

	Square ypao  = S90_from_piecelist(POSITION,your_pao,0);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	//Square yk = your_king_pos;

	Square mpao  = S90_from_piecelist(POSITION,my_pao,0);
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square mma   = S90_from_piecelist(POSITION,my_ma,0);

	//如果黑方的马炮都不能动了, 也是和棋.
	// fen 3aka3/4nP3/4b4/9/2b2c3/9/9/4C4/6p2/3A1K3 b - - 0 0
	if(PB90(MY_SQ55) == my_king && PB90(MY_SQ54) == my_shi && PB90(MY_SQ56) == my_shi){
		if(PB90(MY_SQ4C) == my_ma && isStringByPao(POSITION,ypao,Square(MY_SQ4C),Square(MY_SQ55))){
			if(StoX(mpao) == StoX(ypawn) && ((your_shi_num + your_xiang_num) >= 1)){
				if(PB90(MY_SQ4B) == your_pawn){
					RETRUN_MUL(2);
				}
				if(PB90(MY_SQ4D) == your_pawn){
					RETRUN_MUL(2);
				}
			}
		}
	}
	// fen 1P2k4/4a4/b2ac4/6N2/2bC5/9/5p3/3AB4/4A4/4K4 w - - 123 123
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
			if(StoY(mpawn) == MY_RANK0 && abs(StoX(mpawn) - 0x4) >= 3){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 5kb2/P1N1a4/4ba3/9/9/5c3/4pC3/9/4K4/3A5 w - - 0 1
    if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(ypawn) == MY_RANK6){
			MY_EV_SUB(64);
			if(abs(StoX(mpawn) - 0x4) >= 3 && !IsOnSameSide(mpawn,yk)){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3k2b2/4a4/2P1ba3/9/9/2c3Bp1/C8/5N2B/9/4K4 b - - 0 1 减一些分
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(ypawn) == MY_RANK5 || StoY(ypawn) == MY_RANK6){
			MY_EV_SUB(64);
			if(StoY(mma) MY_LARGE_EQL MY_RANK5){
				RETRUN_MUL(12);
			}
		}
	}

}

//void m_MT_B_1ma1pao1pawn_R_1pao1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	int rpao   = PieceListStart(board,RPAO);
//	int bpao   = PieceListStart(board,BPAO);
//	Square bpawn  = PieceListStart(board,BPAWN);
//	Square rpawn  = PieceListStart(board,RPAWN);
//
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= ADD_MAPAO_Xpawn_To_PAO1Pawn[board->R_shi];
//		}
//
//	}
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > 0x3){
//			board->mulScore += ADD_PAO1Pawn_To_MAPAO_Xpawn[board->B_shi];
//		}
//
//	}
//
//	//如果黑方的马炮都不能动了, 也是和棋.
//	// fen 3aka3/4nP3/4b4/9/2b2c3/9/9/4C4/6p2/3A1K3 b - - 0 0
//	if(board->b256[0x37] == BKING && board->b256[0x36] == BSHI && board->b256[0x38] == BSHI){
//		if(board->b256[0x47] == BMA && IsStringByPao(board,rpao,0x47,0x37)){
//			if(StoY(bpawn) >= 0xb){
//				if(StoX(bpao) == StoX(rpawn) && (board->R_shi + board->R_xiang) != 0){
//					if(board->b256[0x48] == RPAWN && StoX(rk) == 0x8){
//						return 1;
//					}
//					if(board->b256[0x46] == RPAWN && StoX(rk) == 0x6){
//						return 1;
//					}
//				}
//			}
//		}
//	}
//
//	// fen 1P2k4/4a4/b2ac4/6N2/2bC5/9/5p3/3AB4/4A4/4K4 w - - 123 123
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//		if(StoY(rpawn) <= 0x7 && StoY(rpawn) >= 0x6){
//			if(StoY(bpawn) == 0xc && abs(StoX(bpawn) - 0x7) >= 3){
//				return 4;
//			}
//		}
//	}
//
//	*/
//}



//
//#include "../../chess.h"
//#include "../../preGen.h"
//
//#include "../../endgame/mat.h"
////
////const int  ADD_MAPAO_Xpawn_To_PAO1Pawn[3]           = {96, 64, 32};            //马炮对炮的优势分
////const int  ADD_PAO1Pawn_To_MAPAO_Xpawn[3]           = {96, 64, 32};            //马炮对炮的优势分
//
//
//void my_m_MT_R_1ma1pao2pawn_B_1pao1pawn(typePOS &POSITION, EvalInfo &ei){
//
//	int rpao   = PieceListStart(board,RPAO);
//	int bpao   = PieceListStart(board,BPAO);
//	Square rpawn1 = PieceListStart(board,RPAWN);
//	Square rpawn2 = NextPiece(board,rpawn1);
//	Square bpawn  = PieceListStart(board,BPAWN);
//
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > 0x3){
//			board->mulScore += ADD_MAPAO_Xpawn_To_PAO1Pawn[board->B_shi];
//		}
//
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= ADD_PAO1Pawn_To_MAPAO_Xpawn[board->R_shi];
//		}
//	}
//
//	//如果黑方的马炮都不能动了, 也是和棋.
//	// fen 3aka3/4nP3/4b4/9/2b1Cc3/9/9/9/3pA1p2/3A1K3 w - - 68 68
//	if(board->b256[0xc7] == RKING && board->b256[0xc6] == RSHI && board->b256[0xc8] == RSHI){
//		if(board->b256[0xb7] == RMA && IsStringByPao(board,bpao,0xb7,0xc7)){
//			if(StoY(rpawn1) <= 0x4 && StoY(rpawn2) <= 0x4 && IsOnSameSide(rpawn1,rpawn2) == FALSE){
//				if(StoX(rpao) == StoX(bpawn) && board->B_shi == 2){
//					if(board->b256[0xb8] == BPAWN && board->b256[0x38] == BKING){
//						return 1;
//					}
//					if(board->b256[0xb6] == BPAWN && board->b256[0x36] == BKING){
//						return 1;
//					}
//				}
//			}
//		}
//	}
//
//
//	return 16;
//}
//
//void m_MT_B_1ma1pao2pawn_R_1pao1pawn(typePOS &POSITION, EvalInfo &ei){
//
//	int rpao   = PieceListStart(board,RPAO);
//	int bpao   = PieceListStart(board,BPAO);
//	Square bpawn1 = PieceListStart(board,BPAWN);
//	Square bpawn2 = NextPiece(board,bpawn1);
//	Square rpawn  = PieceListStart(board,RPAWN);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= ADD_MAPAO_Xpawn_To_PAO1Pawn[board->R_shi];
//		}
//
//	}
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > 0x3){
//			board->mulScore += ADD_PAO1Pawn_To_MAPAO_Xpawn[board->B_shi];
//		}
//	}
//
//	//如果黑方的马炮都不能动了, 也是和棋.
//	// fen 3aka3/4nP3/4b4/9/2b1Cc3/9/9/9/3pA1p2/3A1K3 w - - 68 68
//	if(board->b256[0x37] == BKING && board->b256[0x36] == BSHI && board->b256[0x38] == BSHI){
//		if(board->b256[0x47] == BMA && IsStringByPao(board,rpao,0x47,0x37)){
//			if(StoY(bpawn1) >= 0xb && StoY(bpawn2) >= 0xb && IsOnSameSide(bpawn1,bpawn2) == FALSE){
//				if(StoX(bpao) == StoX(rpawn) && board->R_shi == 2){
//					if(board->b256[0x48] == RPAWN && board->b256[0xc8] == RKING){
//						return 1;
//					}
//					if(board->b256[0x46] == RPAWN && board->b256[0xc6] == RKING){
//						return 1;
//					}
//				}
//			}
//		}
//	}
//
//
//	//board->mulScore -= ADD_MAPAO_Xpawn_To_PAO1Pawn ;
//
//	return 16;
//}
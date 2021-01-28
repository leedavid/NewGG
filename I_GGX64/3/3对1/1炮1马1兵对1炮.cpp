#ifndef END_my_m_MT_R_1pao1ma_1pawn_B_1pao
#define END_my_m_MT_R_1pao1ma_1pawn_B_1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马1兵对1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 




void my_m_MT_R_1pao1ma_1pawn_B_1pao(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao1MaXPawn_TO_PaoByPawnShi[your_shi_num]);

	MY_EV_ADD(ADD_MAPAO_Xpawn_To_PAO);

	//Square mma   = S90_from_piecelist(POSITION,my_ma,0);
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);	
	Square ypao  = S90_from_piecelist(POSITION,your_pao,0);

	// fen 3aka3/4n4/4b1c2/9/2b1C4/9/9/5A3/4Ap3/3K5 w - - 44 44
	if(PB90(MY_SQ55) == my_king && PB90(MY_SQ4C) == my_ma 
		&& PB90(MY_SQ54) == my_shi && PB90(MY_SQ56) == my_shi){
		Bitboard super = POSITION.Pao_Super_bb(Square(MY_SQ55));
		if(bit_is_set(super,ypao)){
			MY_EV_SUB(258);
			if(your_shi_num == 2 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 5k3/4a4/5a3/9/2b6/9/9/4BA2B/2nCAp3/4K2c1 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
		if(StoY(mpawn) == MY_RANK1 && StoY(ypao) == MY_RANK1){
			if(StoX(mpawn) <= 0x3 && StoX(ypao) >= 0x5){
				if(PB90(MY_SQ15) == your_shi){
					RETRUN_MUL(6);
				}
			}
			if(StoX(mpawn) >= 0x5 && StoX(ypao) <= 0x3){
				if(PB90(MY_SQ17) == your_shi){
					RETRUN_MUL(6);
				}
			}
		}
		if(StoY(mpawn) == MY_RANK0){
			MY_EV_SUB(96);
		}
	}
	// fen 1P2k4/2Nca4/4ba2b/9/9/2B1C4/9/4B4/9/5K3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) == MY_RANK0 && StoY(ypao) MY_SMALL_EQL MY_RANK2){
			if(StoX(mpawn) < 0x3 && PB90(MY_SQ17) == your_shi){
				RETRUN_MUL(8);
			}
			if(StoX(mpawn) > 0x5 && PB90(MY_SQ15) == your_shi){
				RETRUN_MUL(8);
			}
		}
	}

	////被闷宫了,也可能是和棋
	//if(board->b256[0xc7] == RKING && board->b256[0xb7] == RMA && board->b256[0xc6] == RSHI && board->b256[0xc8] == RSHI){
	//	if(IsStringByPao(board,bpao,0xb7,0xc7)){
	//		if(board->B_shi == 2 && StoY(rpawn) <= 0x5){
	//			if(board->b256[0x56] == BSHI || board->b256[0x58] == BSHI){
	//				return 1;
	//			}
	//		}
	//	}
	//}


	//*/
}

//void m_MT_B_1pao1ma_1pawn_R_1pao(typePOS &POSITION, EvalInfo &ei){
//	/*
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -= ADD_1Pao1MaXPawn_TO_PaoByPawnShi[board->R_shi];
//		}
//	}
//	board->mulScore -= ADD_MAPAO_Xpawn_To_PAO ;
//
//	int rpao  = PieceListStart(board,RPAO);
//	Square bpawn = PieceListStart(board,BPAWN);
//
//	// fen 3aka3/4n4/4b1c2/9/2b1C4/9/9/5A3/4Ap3/3K5 w - - 44 44
//	//被闷宫了,也可能是和棋
//	if(board->b256[0x37] == BKING && board->b256[0x47] == BMA && board->b256[0x36] == BSHI && board->b256[0x38] == BSHI){
//		if(IsStringByPao(board,rpao,0x47,0x37)){
//			if(board->R_shi == 2 && StoY(bpawn) >= 0xa){
//				if(board->b256[0xa6] == RSHI || board->b256[0xa8] == RSHI){
//					return 1;
//				}
//			}
//		}
//	}
//
//
//	*/
//}
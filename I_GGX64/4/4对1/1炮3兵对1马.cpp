#ifndef END_my_m_MT_R_1PAO3PAWN_B_1MA
#define END_my_m_MT_R_1PAO3PAWN_B_1MA
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮3兵对1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//1炮3兵对1马
void my_m_MT_R_1PAO3PAWN_B_1MA(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1PaoXPawn_1Ma_ByPawn[your_shi_num]);

   
	//Square yk   = your_king_pos;
	int mcan = EV_MY_CAN;
	Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	Square yma  = S90_from_piecelist(POSITION,your_ma,0);
	

	// fen 3a5/2PPa1P2/b2k5/9/2b6/9/7n1/8B/4K4/3C5 b - - 0 1
	if((your_shi_num + your_xiang_num) == 4){
		if(count_1s(MyUpBB[StoY(yk)],bb_my_pawn) == 3 && my_shi_num == 0){
			if(StoY(yma) MY_LARGE_EQL StoY(yk)){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 2b2P3/3k1PP2/9/9/3C5/9/5n3/9/9/3K5 b - - 0 1
	if (my_shi_num == 0 && my_xiang_num == 0){
		if (your_xiang_num >= 1 && have_bit(bb_my_pawn, RankBB_A[MY_RANK0])){
			if (!have_bit(bb_my_pawn, MyLowBB[MY_RANK1]) && StoY(yk) != MY_RANK0){
				if (StoX(mk) != 0x4){
					RETRUN_MUL(2);
				}
			}
		}
	}

	///////////////////////////////////////////////////////////////////////////
	///
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		
		//马方是仕相全,且兵方只有一个兵可过河,就是和棋
		// fen 3k5/2P1a4/b3ba3/9/9/2P3P2/1n7/3ABA3/5K3/5CB2 w - - 121 121
		if(mcan <= 1){
			RETRUN_MUL(2);
		}
		// fen 3k1a3/9/3ab4/9/2b3p2/5Nc2/5p1p1/4B3B/4A4/4KA3 w - - 120 120
		//三个兵一个炮都卡死了
		if(PB90(MY_SQ16) == your_xiang){
			if(PB90(MY_SQ1C) == my_pawn && PB90(MY_SQ1E) == my_pawn && PB90(MY_SQ2F) == my_pawn){
				if(PB90(MY_SQ26) == my_pao && PB90(MY_SQ27) == your_ma && PB90(MY_SQ12) == your_xiang){
					RETRUN_MUL(2);
				}
			}
			if(PB90(MY_SQ22) == my_pawn && PB90(MY_SQ20) == my_pawn && PB90(MY_SQ33) == my_pawn){
				if(PB90(MY_SQ2A) == my_pao && PB90(MY_SQ29) == your_ma && PB90(MY_SQ1A) == your_xiang){
					RETRUN_MUL(2);
				}
			}
		}

		// fen 5k3/9/9/7N1/8p/9/5p3/4BAp2/4A4/c3K1B2 w - - 124 124
		if(your_shi_num == 0 && your_xiang_num == 0){
			if(count_1s(bb_my_pawn,MyLowBB[MY_RANK4]) <= 2){
				RETRUN_MUL(6);
			}
		}
	}

	///////////////////////////////////////////////////////////////////////////
	/// fen 4k4/3P5/3ab3b/8C/8P/2B3B1P/6n2/3A5/4A4/5K3 w - - 0 
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){	
		if(PB90(MY_SQ35) == my_pawn && PB90(MY_SQ2C) == my_pawn){
			if(bit_is_set(ei.attacked_by(your_ma),Square(MY_SQ35)) && StoX(mpao) == 0x8){
				RETRUN_MUL(6);
			}
		}
		if(PB90(MY_SQ2D) == my_pawn && PB90(MY_SQ24) == my_pawn){
			if(bit_is_set(ei.attacked_by(your_ma),Square(MY_SQ2D)) && StoX(mpao) == 0x0){
				RETRUN_MUL(6);
			}
		}
	}

	// fen 3a5/2PPa1P2/b2k5/9/2b6/9/7n1/8B/4K4/3C5 b - - 0 1
	if((your_shi_num + your_xiang_num) == 4){
		if(count_1s(MyUpBB[StoY(yk)],bb_my_pawn) == 3 && my_shi_num == 0){
			RETRUN_MUL(8);
		}
	}
}

//void m_MT_B_1PAO3PAWN_R_1MA(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	int bcan = BpawnCanOverLiver(board);
//	int rma = PieceListStart(board,RMA);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -=  ADD_1PaoXPawn_1Ma_ByPawn[board->R_shi];;
//		}
//	}
//
//	//premat_t* pMat = board->pMat;
//	//uint16 Info16  = pMat->sixiangInfo8;
//	//int    rk      = PieceListStart(board,BKING);
//
//	//if(board->R_shi == 2 && board->R_xiang == 2){
//	//	return 12;
//	//}
//
//	if(board->R_shi == 2 && board->R_xiang == 2){
//		if(StoY(rk) == 0xc){
//			if(bcan <= 1){
//				return 1;
//			}
//		}
//	}
//
//	// fen 3k1a3/9/3ab4/9/2b3p2/5Nc2/5p1p1/4B3B/4A4/4KA3 w - - 120 120
//	//三个兵一个炮都卡死了
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//		if(board->b256[0xa7] == RXIANG){
//			if(board->b256[0x75] == BPAWN || board->b256[0x79] == BPAWN){
//				if(board->b256[0x88] == RMA && board->b256[0x89] == BPAO && board->b256[0xab] == RXIANG){
//					if(board->b256[0x98] == BPAWN && board->b256[0x9a] == BPAWN){
//						return 1;
//					}
//				}
//				if(board->b256[0x86] == RMA && board->b256[0x85] == BPAO && board->b256[0xa3] == RXIANG){
//					if(board->b256[0x96] == BPAWN && board->b256[0x94] == BPAWN){
//						return 1;
//					}
//				}
//			}
//		}
//	}
//
//
//	// fen 5k3/9/9/7N1/8p/9/5p3/4BAp2/4A4/c3K1B2 w - - 124 124
//	if(board->B_shi == 0 && board->B_xiang == 0){
//		if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//			if(board->b256[0x7b] == BPAWN){
//				if(IsMaCanToOrAt(board,rma,0x8b)){
//					return 4;
//				}
//			}
//			if(board->b256[0x73] == BPAWN){
//				if(IsMaCanToOrAt(board,rma,0x83)){
//					return 4;
//				}
//			}
//		}
//	}
//
//	*/
//}
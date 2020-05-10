#ifndef END_my_m_MT_R_2pao_1pawn_B_1ma
#define END_my_m_MT_R_2pao_1pawn_B_1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2ÅÚ1±ø¶Ô1Âí.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2pao_1pawn_B_1ma(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2PaoXPawn_1Ma[your_shi_num]);

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	//fen 5P3/4k4/9/9/9/1n7/4C4/4K4/9/6C2 w - - 0 1
	if (my_shi_num == 0 && my_xiang_num == 0 && StoY(mpawn) == MY_RANK0){
		if (StoY(yk) != MY_RANK0){
			RETRUN_MUL(2);
		}
	}

	// fen 3k5/4aP3/b4a3/3C5/6b2/9/8n/4B4/6C2/3K5 b - - 0 1
	if(my_shi_num == 0){
		MY_EV_SUB(128);
		if(your_shi_num == 2 && your_xiang_num == 2){
			if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
				if(StoX(mpawn) > 0x4 && PB90(MY_SQ17) == your_shi){
					RETRUN_MUL(4);
				}
				if(StoX(mpawn) < 0x4 && PB90(MY_SQ15) == your_shi){
					RETRUN_MUL(4);
				}
			}
		}
	}



	// fen 3k5/3c5/9/4c4/5N3/9/9/B3BA3/4A1p2/4K4 w - - 40 40
	if((my_shi_num + my_xiang_num) == 0){
		if((your_xiang_num + your_shi_num) == 4){
			if(PB90(MY_SQ15) == your_shi || PB90(MY_SQ17) == your_shi){
				if(StoY(yk) == MY_RANK0){
					RETRUN_MUL(2);
				}
				RETRUN_MUL(4);
			}
			RETRUN_MUL(8);
		}
	}

	// fen 2b2k3/3P5/5a3/2n6/9/9/9/9/3K5/3CC4 w - - 0 1
	if(my_shi_num == 0 && your_shi_num >= 1 && my_xiang_num == 0){
		if(your_xiang_num >= 1 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(abs(StoX(mpawn) - StoX(yk)) >= 2){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 2b1c4/4ac3/1N1k1a3/9/9/2B3B2/9/9/4K4/5p3 w - - 0 1
	if(StoY(mpawn) == MY_RANK0 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(your_xiang_num == 2){
			RETRUN_MUL(8);
		}
	}
}

//void m_MT_B_2pao_1pawn_R_1ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2PaoXPawn_1Ma[board->R_shi];;
//		}
//	}
//	// fen 3k5/3c5/9/4c4/5N3/9/9/B3BA3/4A1p2/4K4 w - - 40 40
//	if(board->B_shi == 0 && board->B_xiang == 0){
//		if(board->R_shi == 2 && board->R_xiang == 2){
//			if(board->b256[0xa6] == RSHI || board->b256[0xa8] == RSHI){
//				if(StoY(rk) == 0xc){
//					return 2;
//				}
//				else{
//					return 4;
//				}
//			}
//		}
//	}
//
//
//
//	*/
//}
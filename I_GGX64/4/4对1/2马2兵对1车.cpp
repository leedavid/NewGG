#ifndef END_my_m_MT_R_2ma_2pawn_B_1che
#define END_my_m_MT_R_2ma_2pawn_B_1che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2Âí2±ø¶Ô1³µ.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_2ma_2pawn_B_1che(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2MaXPawn_To_1Che_PawnByShi[your_shi_num]);

	Square mk = my_king_pos;
	//Square yk = your_king_pos;

	if(my_shi_num == 2 || my_xiang_num == 2){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			EV_MY_SAFE = TRUE;
		}
	}

	Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);



	if(EV_MY_SAFE && EV_YOUR_CAN <= 1){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){

			// fen 3a1kb2/4a4/4b4/2P5r/4N4/6N2/8P/B3BA3/9/3K1A3 w - - 122 122
			if(StoY(mpawn1) MY_LARGE_EQL MY_RANK5 || StoY(mpawn2) MY_LARGE_EQL MY_RANK5){
			    RETRUN_MUL(4);
			}

			// fen 5k3/4a4/1PP1ba3/9/6b2/2r1N4/2N6/5A3/9/3A1K3 w - - 120 120			
			if(!have_bit(bb_my_ma,MyUpBB[MY_RANK5])){

				if(abs(StoX(mpawn1) - 0x4) >= 2 && abs(StoX(mpawn2) - 0x4) >= 2){
					RETRUN_MUL(4);
				}
			}				
		}
	}

	int mcan = EV_MY_CAN;
	//// fen 3k1ab2/4a4/4b4/8R/2p6/9/2n1p4/B8/1n2A4/4K4 w - - 45 45
	if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if(mcan <= 1){
			MY_EV_SUB(256);
		}
		if(EV_MY_SAFE){
			RETRUN_MUL(8);
		}
	}
}


//void m_MT_B_2ma_2pawn_R_1che(typePOS &POSITION, EvalInfo &ei){
//
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	Square bpawn1 = PieceListStart(board,BPAWN);
//	Square bpawn2 = NextPiece(board,bpawn1);
//
//	int bma1 = PieceListStart(board,BMA);
//	int bma2 = NextPiece(board,bma1);
//
//	int bcan = BpawnCanOverLiver(board);
//
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2MaXPawn_To_1Che_PawnByShi[board->R_shi];
//		}
//	}
//
//	if(board->B_xiang == 2 || board->B_shi == 2){
//		if(StoY(bk) <= 0x4){
//			board->bsafe = TRUE;
//		}
//	}
//
//	if(board->bsafe == TRUE){
//		// fen 3a1kb2/4a4/4b4/2P5r/4N4/6N2/8P/B3BA3/9/3K1A3 w - - 122 122
//		if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) >= 0xb){
//			if(StoY(bpawn1) <= 0x7 || StoY(bpawn2) <= 0x7){
//				return 4;
//			}
//
//			// fen 5k3/4a4/1PP1ba3/9/6b2/2r1N4/2N6/5A3/9/3A1K3 w - - 120 120
//			if(StoY(bma1) <= 0x7 && StoY(bma2) <= 0x7){
//				if(abs(StoX(bpawn1) - 0x7) >= 0x2 && abs(StoX(bpawn2) - 0x7) >= 0x2){
//					return 4;
//				}
//			}			
//		}
//	}
//
//	if(board->R_shi >= 1 && board->R_xiang >= 1 && StoY(rk) == 0xc){
//		if(bcan <= 1) board->mulScore += 256;
//		if(board->bsafe == TRUE) return 8;
//	}
//
//
// 
//	*/
//}


#ifndef END_my_m_MT_R_1pao2pawn
#define END_my_m_MT_R_1pao2pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮2兵对无.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1pao2pawn(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;

	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao1MaXPawn_1Pawn[your_shi_num]);

	Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);

	if(my_shi_num == 0){
		// fen 3P5/4P4/4bk3/3C5/2b6/9/9/9/9/4K4 w - - 133 133
		if(StoY(mpawn1) == MY_RANK0 && StoY(mpawn2) == MY_RANK0){
			RETRUN_MUL(1);
		}

		if(StoY(mpawn1) == MY_RANK0 || StoY(mpawn2) == MY_RANK0){
			if(StoY(yk) MY_LARGE StoY(mpawn1) && StoY(yk) MY_LARGE StoY(mpawn2)){
				if(your_xiang_num == 2){
					RETRUN_MUL(1);
				}
			}
		}
	}

	// fen 1P4b1P/3ka4/3a4b/9/9/9/9/3A5/3CA4/5K3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) != MY_RANK0){
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK0])){
			RETRUN_MUL(2);
		}
	}

	// fen 4k2P1/3Pa4/4ba2b/9/9/9/9/4C3B/9/5KB2 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(my_shi_num == 0){
			if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1]) && !IsOnSameSide(mpawn1,mpawn2)) {
				if(StoY(mpawn1) == MY_RANK0){
					if(StoX(mpawn1) >= 0x6 && PB90(MY_SQ17) == your_shi){
						RETRUN_MUL(4);
					}
					if(StoX(mpawn1) <= 0x2 && PB90(MY_SQ15) == your_shi){
						RETRUN_MUL(4);
					}
				}
				if(StoY(mpawn2) == MY_RANK0){
					if(StoX(mpawn2) >= 0x6 && PB90(MY_SQ17) == your_shi){
						RETRUN_MUL(4);
					}
					if(StoX(mpawn2) <= 0x2 && PB90(MY_SQ15) == your_shi){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}


	//// fen 3P5/4P4/4bk3/3C5/2b6/9/9/9/9/4K4 w - - 133 133
	//if(board->R_xiang == 0 && board->R_shi == 0){
	//	if(StoY(rpawn1) == 0x3 || StoY(rpawn2) == 0x3){
	//		if(StoY(bk) > StoY(rpawn1) && StoY(bk) > StoY(rpawn2)){
	//			if(board->B_xiang == 2){
	//				return 1;
	//			}
	//		}
	//	}
	//}



	//*/
}

//void m_MT_B_1pao2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bpawn1 = PieceListStart(board,BPAWN);
//	Square bpawn2 = NextPiece(board,bpawn1);
//
//	Square rk = PieceListStart(board,RKING);
//
//
//	// fen 3P5/4P4/4bk3/3C5/2b6/9/9/9/9/4K4 w - - 133 133
//	if(board->B_xiang == 0 && board->B_shi == 0){
//		if(StoY(bpawn1) == 0xc || StoY(bpawn2) == 0xc){
//			if(StoY(rk) < StoY(bpawn1) && StoY(rk) < StoY(bpawn2)){
//				if(board->R_xiang == 2){
//					return 1;
//				}
//			}
//		}
//	}
//
//	// fen 4PPb2/5k3/9/9/9/9/9/4B4/6C2/2BK5 b - - 0 0
//	if(board->B_shi == 0 && StoY(bpawn1) == 0xc && StoY(bpawn2) == 0xc){
//		return 1;
//	}
//
//
//	*/
//}
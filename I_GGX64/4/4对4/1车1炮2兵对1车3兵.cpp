#ifndef END_my_m_MT_R_1che1pao2pawn_B_1che3pawn
#define END_my_m_MT_R_1che1pao2pawn_B_1che3pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1车1炮2兵对1车3兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 
void my_m_MT_R_1che1pao2pawn_B_1che3pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk   = your_king_pos;
	Square mk   = my_king_pos;
	Square mche = S90_from_piecelist(POSITION, my_che, 0);
	Square yche = S90_from_piecelist(POSITION, your_che, 0);
	Square mpao = S90_from_piecelist(POSITION, my_pao, 0);

	// fen 9/3ka4/9/9/2p1p4/9/2P1P1R1C/4K4/9/2r2p3 w - - 0 1
	if (EV_MY_CAN == 0){
		if (my_shi_num == 0 && my_xiang_num == 0){
			if (your_shi_num >= 1){
				if (have_bit(bb_your_pawn, MyLowBB[MY_RANK6])){
					MY_EV_SUB(64);
				}
			}
		}
	}

	// fen 9/3k5/3a1a3/p8/8p/6p2/P1P6/9/3K5/2B2r1CR w - - 0 1
	if (my_shi_num == 0){
		if (have_bit(bb_your_pawn, MyLowBB[MY_RANK4])){
			MY_EV_SUB(32);
			if (isStringByChe(POSITION, yche, mpao, mche)){
				MY_EV_SUB(32);
				if (EV_YOUR_CAN >= 2){
					MY_EV_SUB(32);
				}
			}
		}
	}

	// fen 9/4k4/9/2R1P3p/2b1PP3/p1r6/9/9/5K3/c8 w - - 0 1
    if(my_shi_num == 0){
        if(EV_YOUR_CAN >= 2){
			Bitboard bmp = m_and(bb_my_pawn,MyLowBB[MY_RANK3]);
			bmp = m_and(bmp,m_or(LeftBB[0x3],RightBB[0x5]));
			if(count_1s(bmp) == 2){ // 炮方没有一个兵过河。
				Bitboard ymp = m_and(bb_your_pawn,MyLowBB[MY_RANK5]);
				ymp = m_and(ymp,m_and(RightBB[0x2],LeftBB[0x6]));
				MY_EV_SUB((sint16)count_1s(ymp) * 64);
			}
		}
	}

	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if(EV_MY_CAN == 0){
			if(PB90(MY_SQ4A) == your_pawn && MY_SQ42 == mk){
				RETRUN_MUL(8);
			}
			if(PB90(MY_SQ4E) == your_pawn && MY_SQ44 == mk){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 2ba1k3/9/4b4/p3P3p/4P1p2/3c5/7RP/4B4/4K4/2B2r3 w - - 0 1
	if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1 && my_shi_num <= 1){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
			Bitboard yp = m_and(bb_your_pawn,MyLowBB[MY_RANK4]);
			MY_EV_SUB((sint16)count_1s(yp) * 32 * (2 - my_shi_num));
		}
	}

}
//
//void m_MT_B_1che1pao2pawn_R_1che3pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	// fen 2b2a3/6P2/3ack3/9/p1p6/5r3/P1P6/4B4/4A4/2BAK1R2 w - - 122 122
//	int bcan = BpawnCanOverLiver(board);
//	if(board->R_shi == 2 && board->R_xiang == 2 && StoY(rk) == 0xc){
//		if(bcan == 0){
//			if(board->b256[0x57] == BPAO){
//				if(board->b256[0x58] == BKING && board->b256[0x49] == RPAWN){
//					return 8;
//				}
//				if(board->b256[0x56] == BKING && board->b256[0x45] == RPAWN){
//					return 8;
//				}
//			}
//		}
//	}
//
//	*/
//}



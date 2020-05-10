#ifndef END_my_m_MT_R_1che1ma3pawn_B_1che1pao1pawn
#define END_my_m_MT_R_1che1ma3pawn_B_1che1pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1马3兵对1车1炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1che1ma3pawn_B_1che1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mma = S90_from_piecelist(POSITION, my_ma, 0);

	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheMaPawn_ChePao1pawn_ByPawnByShi[your_shi_num]);

	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_ChePaoPawn_ChePao1pawn_ByPawnByShi[my_shi_num]);


	// fen 3ak1b2/4a4/4b4/4R4/8P/P5P2/4c4/4r4/4N4/3AKA3 b
	Square ypao =  S90_from_piecelist(POSITION,your_pao,0);
	if(bit_is_set(ei.attacked_by(my_che),ypao) && bit_is_set(ei.attacked_by(your_che),ypao)){
		MY_EV_ADD(EV_MY_CAN * 64);
	}

	//  fen 3ak1b2/4a4/4b4/4R4/5r3/2P5P/4P4/4B1N2/2p1A1c2/3AK4 b - - 0 1
	if (my_shi_num == 2 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9) {
		if (abs(StoX(ypawn) - 0x4) >= 2) {
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	

	// fen 2b1ka3/4a2c1/4b4/pN1R5/9/P3P4/8P/4B4/1r7/4K4 b - - 0 1
	if(EV_YOUR_CAN == 0){
		if((my_shi_num + my_xiang_num) >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			if(StoY(mma) == MY_RANK3){
				MY_EV_ADD(EV_MY_CAN * 16);
			}
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 3akab2/9/4b1n2/p3p4/2r5p/P2R5/9/4BC3/4A4/2B1KA3 w - - 0 1
	// 如果对方4SX,我方只有2can, 且没有一个兵过河,要减一下分
	// Square yk = your_king_pos;
	 if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		 if(EV_MY_CAN <= 2){
			 bmp = m_and(bb_my_pawn, MyUpBB[MY_RANK5]);
			 if(count_1s(bmp) == 0){
				 MY_EV_SUB(64);
			 }
		 }
	 }

	 // fen 2b1k4/4a4/3ab4/p4N3/7PP/P2R5/4r4/3A5/1c1K5/9 b - - 0 1
	 if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0) {
		 if ((my_shi_num + my_xiang_num) <= 1) {
			 if (EV_MY_CAN <= 2) {
				 MY_EV_SUB(32);
				 if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK4])) {
					 MY_EV_SUB(16);
				 }
			 }
		 }
	 }

	 // fen 2b1ka3/9/4b4/5PP2/1R7/P3p4/4cr3/4B4/4N4/2BAKA3 w - - 0 1
	 if(count_1s(bb_my_pawn,RankBB_A[MY_RANK3]) >= 2){
		 if((my_shi_num + my_xiang_num) == 4 && StoY(ypawn) MY_SMALL_EQL MY_RANK5){
			 MY_EV_ADD(EV_MY_CAN * 32);
		 }
	 }
}

//void m_MT_B_1che1ma3pawn_R_1che1pao1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//	
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_ChePaoPawn_ChePao1pawn_ByPawnByShi[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_CheMaPawn_ChePao1pawn_ByPawnByShi[board->R_shi];
//		}
//	}
//
//
//
//	*/
//}
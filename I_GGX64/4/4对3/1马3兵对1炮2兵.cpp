#ifndef END_my_m_MT_R_1ma3pawn_B_1pao2pawn
#define END_my_m_MT_R_1ma3pawn_B_1pao2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马3兵对1炮2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//1马3兵对1炮2兵 //ADD_1PaoXPawn_1MaXPawn_ByShi

void my_m_MT_R_1ma3pawn_B_1pao2pawn(typePOS &POSITION, EvalInfo &ei){	
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1PaoXPawn_1MaXPawn_ByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1PaoXPawn_1MaXPawn_ByShi[my_shi_num]);

	// fen 3ak4/4a4/4P3b/p8/8p/P2N5/8P/3K5/4A4/c1B2A3 b - - 0 1
    if(EV_YOUR_CAN == 0 && (my_shi_num + my_xiang_num) >= 2){
		EV_MY_SAFE = TRUE;
	}


	// fen 4k4/3P1PP2/3aba2b/4c4/9/2B1N4/5p3/9/3pA4/2BA1K3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(have_bit(bb_your_pawn,RankBB_A[MY_RANK6])){
			 MY_EV_SUB(64);
			if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
			   MY_EV_SUB(128);
			}
		}
	}

	if(EV_MY_SAFE){
		if(your_shi_num == 2 && StoY(yk) == MY_RANK0 && your_xiang_num >= 1){
			if(PB90(MY_SQ16) == my_pawn && EV_MY_CAN <= 1){
				RETRUN_MUL(4);
			}
		}
	}


	if (EV_MY_SAFE) {
		//  fen 4kab2/4a4/4b4/p2P4p/9/P4c3/2N5P/4B4/9/2BAKA3 w - - 0 1
		if (your_shi_num == 2 && your_xiang_num == 2 && EV_MY_CAN <= 1) {
			MY_EV_SUB(32);
		}

		//  如果有二个边兵，且暂不能过河
		if (EV_MY_CAN <= 1) {
			
			Bitboard p = m_and(m_and(m_or(FileBB_A[0], FileBB_A[0x8]),
				bb_my_pawn), MyLowBB[MY_RANK4]);
			if (count_1s(p) == 2) {
				RETRUN_MUL(8);
			}			
		}
	}

}

//void m_MT_B_1ma3pawn_R_1pao2pawn(typePOS &POSITION, EvalInfo &ei){	
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore +=  ADD_1PaoXPawn_1MaXPawn_ByShi[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -=  ADD_1PaoXPawn_1MaXPawn_ByShi[board->R_shi];;
//		}
//	}
//
//	*/
//}
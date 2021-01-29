#ifndef END_my_m_MT_R_2pao_2pawn_B_1che
#define END_my_m_MT_R_2pao_2pawn_B_1che
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2炮2兵对1车.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

void my_m_MT_R_2pao_2pawn_B_1che(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2PaoXPawn_To_1Che_PawnByShi[your_shi_num]);
	// fen 3aka3/9/b1C1b4/P8/4r4/6B1P/9/9/4A4/2BAKC3 b - - 0 45
	if((your_shi_num + your_xiang_num) >= 3){
		MY_EV_SUB(80);
	}

	// fen 3ak4/9/5a3/1r7/6b2/P1P1C4/8P/4B1C2/4A4/3AK1B2 w - - 0 1
	//我方的兵全在家，且对方有三个以上的仕相
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
		bmp = m_and(bmp,MyLowBB[MY_RANK4]);
		MY_EV_SUB((sint16)count_1s(bmp) * 64);	
	}

	// fen 3cka3/9/9/8p/4p4/R8/1c7/4B4/4A4/2BAK4 b - - 7 0
	if(my_shi_num >= 1 && StoY(mk) == MY_RANK9){
		MY_EV_ADD(32);
		if((your_shi_num + your_xiang_num) >= 3){
		  bmp = m_and(bmp,MyLowBB[MY_RANK2]);
		  if(count_1s(bmp) == 2){
			  MY_EV_SUB(96);
		  }
		   RETRUN_MUL(8);
		}
	}

	// fen 3k5/4a4/4ba3/1PC1CP3/2b6/3r5/9/4B4/4K4/9 w - - 0 1
	if (my_xiang_num >= 1){
		Bitboard m2p = m_and(bb_my_pawn, RankBB_A[MY_RANK3]);
		if (count_1s(m2p) == 2){
			if (count_1s(bb_my_pao, RankBB_A[MY_RANK3]) == 2){
				RETRUN_MUL(8);
			}
		}
	}

	

}


//void m_MT_B_2pao_2pawn_R_1che(typePOS &POSITION, EvalInfo &ei){
///*
//
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2PaoXPawn_To_1Che_PawnByShi[board->R_shi];
//		}
//	}
//
//	// fen 3cka3/9/9/8p/4p4/R8/1c7/4B4/4A4/2BAK4 b - - 7 0
//	if(board->B_shi != 0){
//		board->mulScore -= 128;
//	}
//
//
//	*/
//}


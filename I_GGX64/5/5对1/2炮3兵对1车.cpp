#ifndef END_my_m_MT_R_2pao_3pawn_B_1che
#define END_my_m_MT_R_2pao_3pawn_B_1che
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2炮3兵对1车.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

void my_m_MT_R_2pao_3pawn_B_1che(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_2PaoXPawn_To_1Che_PawnByShi[your_shi_num]);
	// fen 4k4/4a4/9/8p/3cp4/p8/c5R2/4B4/4A4/2BAK4 w - - 1 1
	if(my_shi_num >= 1){
		MY_EV_ADD(64);
	}

	// fen 3ak4/9/5a3/1r7/6b2/P1P1C4/8P/4B1C2/4A4/3AK1B2 w - - 0 1
    //我方的兵全在家，且对方有三个以上的仕相
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
		bmp = m_and(bmp,MyLowBB[MY_RANK4]);
		MY_EV_SUB((sint16)count_1s(bmp) * 96);	
	}
	// fen 3aC1b2/4a2P1/5k3/6r2/C8/P1P6/9/4B4/4A4/3AK1B2 b - - 0 1
	if((your_shi_num + your_xiang_num) >= 3 && PB90(MY_SQ04) == my_pao){
		MY_EV_SUB(128);
	}

}


//void m_MT_B_2pao_3pawn_R_1che(typePOS &POSITION, EvalInfo &ei){
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
//	// fen 4k4/4a4/9/8p/3cp4/p8/c5R2/4B4/4A4/2BAK4 w - - 1 1
//	if(board->B_shi != 0){
//		board->mulScore -= 128;
//	}
//   
//
//
//	
//	*/
//}


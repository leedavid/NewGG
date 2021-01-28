#ifndef END_my_m_MT_R_1pao1ma2pawn_B_2ma2pawn
#define END_my_m_MT_R_1pao1ma2pawn_B_2ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马2兵对2马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1pao1ma2pawn_B_2ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao1Ma2Pawn_To_2MaxPawn[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1Pao1Ma2Pawn_To_2MaxPawn[my_shi_num]);

	int mcan = EV_MY_CAN;
	int ycan = EV_YOUR_CAN;
	Square mma = S90_from_piecelist(POSITION, my_ma, 0);

	if(EV_YOUR_CAN == 0){
		EV_MY_SAFE = TRUE;
	}

	// fen C3k1b2/4a4/4ba3/p1N6/6n2/2P6/P1n6/4B4/4A1p2/2BA1K3 b - - 0 1
	if (EV_YOUR_CAN <= 1) {
		if (my_shi_num == 2 && my_xiang_num == 2) {
			MY_EV_ADD(32);
		}
	}

	if(mcan == 0){
		MY_EV_SUB(ycan * 32);
	}
	//if(ycan == 0){
	MY_EV_ADD(mcan * 32);
	//}
	//if(mcan >= 1 && my_shi_num == 2){
	//	MY_EV_ADD(mcan * 32);
	//}

	// fen 2b1kab2/4a4/6n2/p2C4p/2N6/4P4/P8/7n1/4A4/2B1K1B2 b - - 0 1
	if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK4])){
		MY_EV_ADD(EV_MY_CAN * 32);
		if((my_shi_num + my_xiang_num) >= 3){
			MY_EV_ADD(32);
		}
	}
	// 有边兵也要减分
    if(have_bit(bb_your_pawn,LeftBB[0x1])){
		MY_EV_ADD(16);
	}
	if(have_bit(bb_your_pawn,RightBB[0x7])){
		MY_EV_ADD(16);
	}

	// fen C4kb2/3Pa4/4ba3/2P6/8p/2B1n4/4p4/N8/4A4/4KAn2 w - - 0 1
	if (StoY(mk) MY_LARGE_EQL MY_RANK8 && my_shi_num == 2){
		if (count_1s(bb_my_pawn, MyUpBB[MY_RANK5]) == 2){
			MY_EV_ADD(32);
			if (StoY(mma) MY_SMALL_EQL MY_RANK5){
				MY_EV_ADD(16);
			}
		}
	}


	// fen 3k2b2/4a4/5a3/5P2p/p2Nn4/4N4/4c3P/4B4/4A4/3K1AB2 w - - 0 1
	if (my_shi_num == 2 && EV_YOUR_CAN <= 1){
		MY_EV_ADD(32);
		if (EV_MY_CAN >= 1){
			MY_EV_ADD(32);
		}
	}

	// fen 4k1b2/9/3a5/p1p1n3N/6b2/2P6/P7c/2N1B4/9/3AKAB2 w - - 0 0
	if(ycan == 0 && my_shi_num >=1 && my_xiang_num == 2){
		MY_EV_ADD(32 * (2 - your_shi_num));
	}

	//MY_EV_ADD(32);

	// fen 2ba1k3/3P5/9/9/p3pNb2/8p/P1c6/2N1BA3/4A1n2/2BK5 w - - 10 10
	//if(my_shi_num >= 1 && EV_YOUR_CAN <= 1){
	//	MY_EV_ADD(EV_MY_CAN * 16);
	//}

	//2ba1k3/4a4/2n1b4/2C6/1P1N4p/2B6/1n6P/9/4Ap3/3K1A3 b - - 0 1 
	if(my_shi_num == 2 && EV_YOUR_CAN <= 1){
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	// fen 2bak4/1C2a4/2P1b4/8P/5N3/5n3/3p1n3/B3p3B/4AK3/3A5 b - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && EV_MY_CAN >= 2){
		if(have_bit(bb_your_pawn,MyUpBB[MY_RANK7])){
			if(PB90(MY_SQ43) == your_pawn){
				MY_EV_ADD(64);
			}
		}
	}

	// fen 3aknbC1/4a4/2n1b4/p3p4/5N3/P3P4/9/3AB4/9/4KAB2 b - - 0 1
	if(EV_MY_SAFE){
		if(EV_MY_CAN == 0){
			if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
				RETRUN_MUL(8);
			}
		}

		// fen 9/4k4/3a5/4p2N1/p8/2B6/P3PCn2/4BA3/2n1A4/3K5 b - - 0 1
		if (your_shi_num >= 1){
				RETRUN_MUL(12);
		}
	}
}

//void m_MT_B_1pao1ma2pawn_R_2ma2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//
//	int rcan =  RpawnCanOverLiver(board);
//	int bcan =  BpawnCanOverLiver(board);
//
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_1Pao1Ma2Pawn_To_2MaxPawn[board->B_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1Pao1Ma2Pawn_To_2MaxPawn[board->R_shi];
//		}
//	}
//
//	if(rcan == 0){
//		board->mulScore -= bcan * 64;
//	}
//	if(bcan == 0){
//		board->mulScore += rcan * 64;
//	}
//
//	// fen 2b1kab2/4a4/9/7N1/p2Np2P1/8P/1n7/9/4A4/c1BAK1B2 b - - 10 10
//	if(bcan >= 1 && board->B_shi == 2){
//		board->mulScore -= bcan * 32;
//	}
//
//	// fen 4k1b2/9/3a5/p1p1n3N/6b2/2P6/P7c/2N1B4/9/3AKAB2 w - - 0 0
//	if(rcan == 0 && board->B_shi >=1 && board->B_xiang == 2){
//		board->mulScore -= 48 * ( 4 - board->R_shi);
//	}
//
//
//
//	*/
//}

//const int ADD_2Pao2Pawn_To_2PaoxPawn_ByPawn[3]           = { 96, 64, 32};
//const int ADD_2Pao2Pawn_To_1Pao1MaxPawn_ByPawn[3]        = { 96, 64, 32};
//const int ADD_2Pao2Pawn_To_2MaxPawn_ByPawn[3]            = { 96, 64, 32};
#ifndef END_my_m_MAT_R_1pao1ma2pawn_B_2pao1pawn_s
#define END_my_m_MAT_R_1pao1ma2pawn_B_2pao1pawn_s
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马2兵对2炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1pao1ma2pawn_B_2pao1pawn(typePOS &POSITION, EvalInfo &ei){
	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1pao1maXpawn_To_2pao1pawn_ByPs[your_shi_num]);

	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1pao1maXpawn_To_2pao1pawn_ByPs[my_shi_num]);

	MY_EV_ADD(ADD_1pao1maXpawn_To_2pao1pawn);

	Square mma = S90_from_piecelist(POSITION, my_ma, 0);

	//  fen 3k5/4a4/4ba2b/p8/4C4/P5P2/c8/Nc2B4/4A4/2BA1K3 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2) {
		if (EV_MY_CAN == 0) {
			MY_EV_SUB(32);
			if (have_bit(bb_my_pawn, m_or(FileBB_A[0x0], FileBB_A[0x8]))) {
				MY_EV_SUB(32);				
			}
		}
		if (StoY(mma) MY_LARGE_EQL MY_RANK7) {
			MY_EV_SUB(64);
		}
	}

	//if(my_shi_num >= 1){
	//	MY_EV_ADD(EV_MY_CAN)
	// fen 4kab2/4a4/4b4/N7p/3C5/P8/4P3c/4cA3/9/3AK4 b - - 0 34
	// fen 4kab2/4a4/4b4/N7p/3C5/P8/4P3c/4cA3/9/3AK4 b - - 0 1
	MY_EV_ADD(EV_MY_CAN * 16);

	// fen 3k1a3/4ac3/8b/3C1P3/P8/2c3N2/9/4pA3/5K3/3A5 b - - 0 1
	if(EV_MY_CAN >= 2){
		MY_EV_ADD(EV_MY_CAN * 16);
	}

	if(my_shi_num == 2){
		MY_EV_ADD(EV_MY_CAN * 16);
	}


}

//void m_MAT_B_1pao1ma2pawn_R_2pao1pawn(typePOS &POSITION, EvalInfo &ei){
//	/*
//	Square rk = PieceListStart(pos,RKING);
//	Square bk = PieceListStart(pos,BKING);
//	
//	for(int from = PieceListStart(pos,RPAWN); from > 0x32; from = NextPiece(pos,from)){
//		if(StoY(from) > StoY(bk)){
//			pos.mulScore += ADD_1pao1maXpawn_To_2pao1pawn_ByPs[pos.B_shi];
//		}
//
//	}
//
//	for(int from = PieceListStart(pos,BPAWN); from > 0x32; from = NextPiece(pos,from)){
//		if(StoY(from) < StoY(rk)){
//			pos.mulScore -= ADD_1pao1maXpawn_To_2pao1pawn_ByPs[pos.R_shi];
//		}
//	}
//
//	pos.mulScore -= ADD_1pao1maXpawn_To_2pao1pawn;
//
//	*/
//}
#ifndef END_my_m_MT_R_1pao1ma2pawn_B_1che2pawn
#define END_my_m_MT_R_1pao1ma2pawn_B_1che2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1马2兵对1车2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int ADD_Che2Pawn_To_1Pao1MaXPawn_ByPawn[3]    =  { 96, 64, 32};  //车2兵,对1炮1马X兵
//const int ADD_1Pao1MaXPawn_To_Che2Pawn_ByPawn[3]    =  { 96, 64, 32};  //车2兵,对1炮1马X兵

void my_m_MT_R_1pao1ma2pawn_B_1che2pawn(typePOS &POSITION, EvalInfo &ei){
	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao1MaXPawn_To_Che2Pawn_ByPawn[your_shi_num]);

	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_Che2Pawn_To_1Pao1MaXPawn_ByPawn[my_shi_num]);

	// fen 2b2kb2/4a1N2/5PP2/9/9/5p3/1p3r3/4B2C1/4A4/4KAB2 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		MY_EV_SUB(EV_YOUR_CAN * 16);
		if(EV_YOUR_CAN == 2){
			MY_EV_SUB(32);
		}
		if(PB90(MY_SQ17) == my_pawn && PB90(MY_SQ18) == my_pawn && MY_SQ05 == yk){
			MY_EV_SUB(64);
		}
		if(PB90(MY_SQ15) == my_pawn && PB90(MY_SQ14) == my_pawn && MY_SQ03 == yk){
			MY_EV_SUB(64);
		}
	}
}

//void m_MT_B_1pao1ma2pawn_R_1che2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//    Square rk    = PieceListStart(board,RKING);
//	Square bk    = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_1Pao1MaXPawn_To_Che2Pawn_ByPawn[board->R_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_Che2Pawn_To_1Pao1MaXPawn_ByPawn[board->B_shi];
//		}
//	}
//
//	*/
//}




//m_MT_R_1che3pawn_B_3pawn
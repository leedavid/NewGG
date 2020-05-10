#ifndef END_my_m_MT_R_1che1pao1ma3pawn_B_1che2pao2pawn
#define END_my_m_MT_R_1che1pao1ma3pawn_B_1che2pao2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1炮1马3兵对1车2炮2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1che1pao1ma3pawn_B_1che2pao2pawn(typePOS &POSITION, EvalInfo &ei){

	//Square yk = your_king_pos;
	////
	//Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	//MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[your_shi_num]);
	////
	//Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	//MY_EV_SUB((sint16)count_1s(ymp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[my_shi_num]);

	// fen 2bakc3/2n1a4/4b4/9/p4N3/2P6/P3P1R1P/4B3C/4Ap1r1/2B1KA3 w - - 0 29
	//Square mk  = my_king_pos;
	//Square yma   = S90_from_piecelist(POSITION,your_ma,0);
	//if((my_shi_num + my_xiang_num) == 4 && StoY(mk) == MY_RANK9){
	//	//if(EV_YOUR_CAN <= 1){
	//	//	MY_EV_ADD(EV_MY_CAN * 16);
	//	//}
	//	if(StoY(yma) MY_SMALL_EQL MY_RANK3){
	//		MY_EV_ADD(EV_MY_CAN * 16);
	//	}
	//}

	Square mma = S90_from_piecelist(POSITION,my_ma,0);

	// fen 2b1ka3/1Nc1a4/4b4/p3C3p/1P2R4/8P/r3P4/9/9/2B1KAB1c b - - 0 1
	if(EV_YOUR_CAN == 0){
		if(my_xiang_num == 2){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
		if(StoY(mma) MY_SMALL_EQL MY_RANK5){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}
}


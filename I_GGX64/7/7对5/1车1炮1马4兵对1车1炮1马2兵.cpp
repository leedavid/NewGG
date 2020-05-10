#ifndef END_my_m_MT_R_1che1pao1ma4pawn_B_1che1pao1ma2pawn
#define END_my_m_MT_R_1che1pao1ma4pawn_B_1che1pao1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1炮1马4兵对1车1炮1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_1che1pao1ma4pawn_B_1che1pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	//Square yk = your_king_pos;
	////
	//Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	//MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[your_shi_num]);
	////
	//Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	//MY_EV_SUB((sint16)count_1s(ymp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[my_shi_num]);

	// fen 2bakc3/2n1a4/4b4/9/p4N3/2P6/P3P1R1P/4B3C/4Ap1r1/2B1KA3 w - - 0 29
	Square mk  = my_king_pos;
	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	Square mma = S90_from_piecelist(POSITION,my_ma,0);
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);
	if((my_shi_num + my_xiang_num) == 4 && StoY(mk) == MY_RANK9){
		if(EV_YOUR_CAN <= 1){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
		if(StoY(yma) MY_SMALL_EQL MY_RANK3){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 2bak4/4a4/4b1n2/8p/p1P1PP3/1C1R5/2N5P/7r1/9/2BAK3c w - - 0 1
	// 对方的马在家，我方有连兵，且对方没有兵过河
	if(EV_YOUR_CAN <= 1 && !have_bit(bb_your_pawn,MyLowBB[MY_RANK4])){
		if(StoY(yma) MY_SMALL_EQL MY_RANK2){
			MY_EV_ADD(EV_MY_CAN * 4);
			Bitboard lp = My_get_connect_Pawn(POSITION);
			if(have_bit(lp,FileBB_A[0x4])){
				MY_EV_ADD(16);
			}
			if(StoY(mma) MY_SMALL_EQL MY_RANK7){
				MY_EV_ADD(16);
			}
		}
	}

	// fen 3k1a3/4a4/4b1n2/p4NC2/6P1p/2P4R1/P7P/3r5/4K4/5A2c w - - 0 1
	if(StoY(yma) MY_SMALL_EQL MY_RANK2 && !have_bit(bb_your_pawn,MyLowBB[MY_RANK4]) && EV_YOUR_CAN <= 1){
		if(StoY(mma) MY_SMALL_EQL MY_RANK5){
		   MY_EV_ADD(EV_MY_CAN * 16);
		}
		// 对方都是边兵
		if(!have_bit(bb_your_pawn,m_and(LeftBB[0x8],RightBB[0x0]))){
			MY_EV_ADD(EV_MY_CAN * 16);
		}		

		if(StoY(ypao) MY_LARGE_EQL MY_RANK4){
			MY_EV_ADD(32);
		}
	}
}


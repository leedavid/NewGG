#ifndef END_my_m_MT_R_1che1pao4pawn_B_1che1pao1ma
#define END_my_m_MT_R_1che1pao4pawn_B_1che1pao1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1炮4兵对1车1炮1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1che1pao4pawn_B_1che1pao1ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	Square ypao = S90_from_piecelist(POSITION, your_pao, 0);
	//
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[your_shi_num]);
	//
	//Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	//MY_EV_SUB((sint16)count_1s(ymp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[my_shi_num]);

	// fen 2baka3/9/2n1b4/2C2PP2/P1P5p/9/8P/1r2B2R1/4A4/3AK3c b - - 0 1
	if((my_shi_num + my_xiang_num) >= 2){
		if(StoY(yma) MY_SMALL_EQL MY_RANK2){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 3ck2r1/4a4/2n2a3/9/4PP3/2P5C/1R6P/4B4/4K4/9 b - - 0 1
	if(my_xiang_num >= 1 || my_shi_num >= 1){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			Bitboard lp = My_get_connect_Pawn(POSITION);
			if(have_bit(lp,FileBB_A[0x4])){
				MY_EV_ADD(64);
				if(StoY(yma) MY_SMALL_EQL MY_RANK2){
					MY_EV_ADD(32);
					MY_EV_ADD(EV_MY_CAN * 16);
				}
			}
		}
	}

	if(StoY(yma) MY_LARGE_EQL MY_RANK4){
		MY_EV_SUB(32);
	}
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
			MY_EV_SUB(32);
		}
		if(count_1s(bb_my_pawn,MyLowBB[MY_RANK4]) >= 3){
			MY_EV_SUB(32);
		}
	}

	//fen 3ak4/4a4/4bc3/p5r2/2b3p2/2N4R1/9/3AB4/4C4/4KAB2 w - - 0 1
	if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if (StoY(yma) MY_SMALL_EQL MY_RANK4){
			MY_EV_ADD(32);
		}
		if (StoY(ypao)MY_SMALL_EQL MY_RANK4){
			MY_EV_ADD(32);
		}
		MY_EV_ADD(EV_MY_CAN * 16);
	}
}

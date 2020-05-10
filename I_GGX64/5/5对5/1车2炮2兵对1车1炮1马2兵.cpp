#ifndef END_my_m_MT_R_1che2pao2pawn_B_1che1pao1ma2pawn
#define END_my_m_MT_R_1che2pao2pawn_B_1che1pao1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车2炮2兵对1车1炮1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che2pao2pawn_B_1che1pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk  = your_king_pos;
	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	Square mche = S90_from_piecelist(POSITION, my_che, 0);

	if(your_shi_num == 2 && your_xiang_num == 2 && yk == MY_SQ04){
		MY_EV_SUB(EV_YOUR_CAN * 16);
		if(EV_MY_CAN <= 1 && !have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
			MY_EV_SUB(EV_YOUR_CAN * 16);
		}
		if(StoY(yma) MY_LARGE_EQL MY_RANK5){
			MY_EV_SUB(16);
		}
	}

	// fen 3aka3/9/5R3/8p/9/1r5n1/4P1C1P/4B4/6p2/1cCAKAB2 b - - 0 1
    if(your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
			MY_EV_SUB(EV_YOUR_CAN * 16);

			//我方的一个炮在底线，给对方控制了
			if(have_bit(bb_my_pao,m_and(MyLowBB[MY_RANK7],EV_YOUR_XBIT))){
				MY_EV_SUB(32);
				// fen R4a3/3ka4/9/8p/9/1r7/4PnC1P/4B1p2/9/1cCAKAB2 w - - 0 1
				if(have_bit(bb_your_pawn,MyLowBB[MY_RANK6])){
					MY_EV_SUB(32);
				}
			}
		}
	}

	// fen 2b2C1R1/4k4/3ab4/p3p4/5rc2/2P6/P1n1P4/8C/4A4/3AK1B2 w - - 0 1
	if (EV_MY_CAN == 0){
		if ((my_shi_num + my_xiang_num) <= 3){
			if (your_xiang_num == 2){
				MY_EV_SUB(16);
				if (StoY(yma) MY_LARGE_EQL MY_RANK5 && StoY(mche) MY_SMALL_EQL MY_RANK2){
					MY_EV_SUB(32);
				}
			}
		}
	}

	//  fen 3ak4/4a4/4b1n1b/4p1C1p/P2R5/9/4P4/B3B1r2/4A4/1c2KAC2 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0) {
		if (EV_MY_CAN <= 1 && !have_bit(bb_my_pawn, MyUpBB[MY_RANK3])) {
			MY_EV_SUB(32);
			MY_EV_SUB(EV_YOUR_CAN * 16);
		}
	}

	// fen 2Ca5/3Rak3/2n1C4/p3p4/9/P1B1P4/9/9/1r6c/3K2B2 w - - 0 1
	if(your_shi_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(my_shi_num == 0){
			MY_EV_SUB(32);
		}

		// 对方的宫中有我方的炮
		if(have_bit(bb_my_pao,m_and(MyUpBB[MY_RANK3],m_and(LeftBB[0x6],RightBB[0x2])))){
			MY_EV_SUB(32);
		}
	}

	//  fen 2baka3/9/4b4/p2n4p/1rC3c2/P4R2P/9/4B4/2C6/3AKAB2 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && yk == MY_SQ04) {
		MY_EV_SUB(16);
		if (EV_MY_CAN == 0) {
			MY_EV_SUB(16);
		}
		if (StoY(yma) MY_LARGE_EQL MY_RANK3) {
			MY_EV_SUB(16);
		}
	}


	//// fen R4a3/3ka4/9/8p/9/1r7/4PnC1P/4B1p2/9/1cCAKAB2 w - - 0 1
	//if()


}

#ifndef END_my_m_MT_R_2pao2pawn_B_1pao1ma2pawn
#define END_my_m_MT_R_2pao2pawn_B_1pao1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2炮2兵对1炮1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

// fen 2b1ka3/9/5a3/p3p4/6C2/2P1Pc3/8n/4B1C2/4A4/2BAK4 w - - 0 0

void my_m_MT_R_2pao2pawn_B_1pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	//int rcan = RpawnCanOverLiver(baord

	if((your_shi_num + your_xiang_num) >= 3){
		MY_EV_SUB(32);
	}
	//if(your_shi_num >= 1 && your_xiang_num = 1){
	//	MY_EV_SUB(64);
	//}
	Square mk = my_king_pos;

	// fen 2bk1a3/4a4/4b4/p5p2/4C2P1/P3c4/9/3A4C/4K4/2Bn2B2 b - - 3 3
	if(my_shi_num >= 1 && my_xiang_num == 2 && EV_YOUR_CAN == 0){
		if(PB90(MY_SQ54) == your_ma || PB90(MY_SQ56) == your_ma){
		   MY_EV_ADD(64);
		}
	}

	// fen 3nka3/4a4/4b3b/4p4/8P/P1p6/4c4/2C1B1C2/4A4/2B1KA3 w - - 0 1
	if ((your_shi_num + your_xiang_num) == 4) {
		MY_EV_SUB(32);
	}

	// fen 5k3/4P1nC1/b5C2/8p/6b2/5p2P/5c3/3A5/9/4K4 w - - 0 1
	if (your_xiang_num == 2) {
		if (EV_MY_CAN <= 1 && my_shi_num <= 1) {
			MY_EV_SUB(EV_YOUR_CAN * 32);
			if (my_xiang_num == 0) {
				if (have_bit(bb_my_pawn, RankBB_A[MY_RANK5]) && 
					have_bit(bb_your_pawn, RankBB_A[MY_RANK5])) {
					MY_EV_SUB(64);
				}
			}
		}
	}

	// fen 2bak4/4a4/4b4/4c2Cp/3P3n1/2C5P/5p3/4B4/4A4/4KAB2 b - - 0 1
	if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9) {
		MY_EV_ADD(32);
		if (EV_YOUR_CAN <= 1) {
			MY_EV_ADD(32);
			if (have_bit(bb_my_pawn, RankBB_A[MY_RANK4]) || have_bit(bb_my_pawn, RankBB_A[MY_RANK3])) {
				MY_EV_ADD(32);
			}
		}
	}

	// fen 3ak4/3c5/3ab4/1c2PP3/2b6/4N4/1pp5C/3AB4/4A4/4K1B2 b - - 0 1
	if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		Bitboard lp = My_get_connect_Pawn(POSITION);
		if (have_bit(lp, MyLowBB[MY_RANK2])){
			MY_EV_ADD(32);
		}
		if (!have_bit(bb_my_pao, MyUpBB[MY_RANK5])){
			MY_EV_ADD(32);
		}
	}

	// fen 2bak4/4a4/b8/4P4/C7p/P8/2p2n2c/4BC3/4AK3/2BA5 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2){
		MY_EV_SUB(EV_YOUR_CAN * 32);
	}

	// fen 4ka3/9/3a3P1/6n2/2b6/2BC4P/p4p3/7C1/4A4/1c1K1AB2 b - - 0 1
	if ((your_shi_num + your_xiang_num) >= 3){
		if (My_pawn_already_over_river(POSITION) <= 1){
			MY_EV_SUB(32);
		}
		if (Your_pawn_already_over_river(POSITION) >= 2){
			MY_EV_SUB(32);
		}
	}

	// fen 3k1a3/4a4/4b4/4C4/p3P2cp/9/P3N4/B8/9/5K2c w - - 0 0
    //如果红方有兵过河,黑方没有兵过河,或过河兵少于1个, 要减分.
	int malr = My_pawn_already_over_river(POSITION);
	int yalr = Your_pawn_already_over_river(POSITION);

    if(malr <= 1 && yalr >= 1){
		if((my_shi_num + my_xiang_num) <= 3){
			MY_EV_SUB(64);
		}
	}
	// fen 2ba1k3/4a4/4b4/8p/9/2N5P/P2p5/4B4/3Kc4/2B2AC1c b - - 0 1
	if(EV_MY_CAN <= 1){
		MY_EV_SUB(EV_YOUR_CAN * 32);
	}

	// fen 3kc4/4a4/5a2b/4P1PCp/2b6/2N6/1pp5c/8B/9/2BAKA3 b - - 0 1
	if(EV_YOUR_CAN >= 2 && (your_shi_num + your_xiang_num) == 4){
		// 我方还有兵没有过河
		Bitboard b = m_and(bb_my_pawn,MyLowBB[MY_RANK4]);
		MY_EV_SUB((sint16)count_1s(b) * 16);
	}

	if (your_shi_num == 2 && your_xiang_num == 2){
		if (EV_MY_CAN <= 1){
			EV_YOUR_SAFE = true;
		}
	}

	// fen 4kab2/1c2a4/c3b4/p8/4P1p2/9/P7C/2N1B4/4A4/4KAB2 w - - 0 1
	if (EV_YOUR_SAFE){
		if (EV_YOUR_CAN <= 1){
			if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
				RETRUN_MUL(12);
			}
		}
	}

}
//
//void m_MT_B_2pao2pawn_R_1pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	if(board->R_shi == 2 && board->R_xiang >= 1){
//		board->mulScore += 64;
//	}
//
//	// fen 2bk1a3/4a4/4b4/p5p2/4C2P1/P3c4/9/3A4C/4K4/2Bn2B2 b - - 3 3
//	if(board->B_shi >= 1 && board->B_xiang == 2){
//		if(board->b256[0x36] == RMA || board->b256[0x38] == RMA){
//			board->mulScore -= 96;
//		}
//	}
//
//	
//	int rover = RpawnAlreadyRiver(board);
//	int bover = BpawnAlreadyRiver(board);
//	
//	int rcan  = RpawnCanOverLiver(board);
//	int bcan  = BpawnCanOverLiver(board);
//
//	// fen 3k1a3/4a4/4b4/4C4/p3P2cp/9/P3N4/B8/9/5K2c w - - 0 0
//    //如果红方有兵过河,黑方没有兵过河,或过河兵少于1个, 要减分.
//	if(bover <= 1 && rover >= 1 && rcan >= 2){
//		if((board->B_shi + board->B_xiang) <= 3){
//		   board->mulScore += rcan * 32;
//		}
//	}
//
//	
//
//
//	*/
//}


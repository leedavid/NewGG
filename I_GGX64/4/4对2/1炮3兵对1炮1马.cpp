#ifndef END_my_m_MT_R_1pao3pawn_B_1pao1ma
#define END_my_m_MT_R_1pao3pawn_B_1pao1ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮3兵对1炮1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


// 炮3兵对炮马
void my_m_MT_R_1pao3pawn_B_1pao1ma(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_PaoXPawn_To_1Pao1Ma_ByShi[your_shi_num]);
	Square mk = my_king_pos;
	// fen 3a5/4ak3/2P6/4P4/2b6/9/5C3/B4An2/3KA4/2B5c b - - 126 126
    //如果炮方是仕相全，且将在二线以下，就要加分
	if((my_shi_num + my_xiang_num) == 4 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		EV_MY_SAFE = TRUE;
		// fen 2bk1a3/4a4/4b4/9/P2n4C/2P6/8P/4B4/4A4/4KABc1 b - - 0 1
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	// fen 5a3/4a1C2/3kc3b/9/2P6/8P/P3n1P2/4B4/4A4/4KAB2 w - - 0 1
	if((your_shi_num + your_xiang_num) >= 3){
		Bitboard mlowp = m_and(bb_my_pawn,MyLowBB[MY_RANK3]);
		MY_EV_SUB((sint16)count_1s(mlowp) * 32);
	}

	if(EV_MY_SAFE == FALSE){
		MY_EV_SUB(ADD_MAPAO_Xpawn_To_PAO2PawnNoSafe);
	}

	// fen 9/3k5/9/6N2/8c/9/4C4/4K4/5ppp1/2B6 b - - 0 1
	// 如果多方的兵全在对方的将下面,要大大的减分
	if(pmok == 0){
		MY_EV_SUB(128);
	}

	// fen 3k1a3/4a4/9/3N4p/9/6p2/9/p3CA3/2c2K3/9 b - - 0 1
	if (your_shi_num >= 1){
		if (my_xiang_num == 0){
			MY_EV_SUB(32);			
		}
		if (have_bit(bb_my_pawn, LeftBB[0x1])){
			MY_EV_SUB(64);
		}
		if (have_bit(bb_my_pawn, RightBB[0x7])){
			MY_EV_SUB(64);
		}
	}

	Bitboard lp = My_get_connect_Pawn(POSITION);
	if (have_bit(lp, MyLowBB[MY_RANK2])){
		MY_EV_ADD(64);
	}

	//  fen 3ak1b2/4a4/b2c5/9/P8/2C2n3/4P3P/4B4/9/3AKAB2 b - - 0 1
	if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9) {
		MY_EV_ADD(EV_MY_CAN * 32);
	}


	// fen 2bak1b2/4a4/9/3PPP3/5c3/6B2/3n5/3CB4/9/4K4 b - - 0 1
	if((your_shi_num + your_xiang_num) >= 3){
		if(my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			if(count_1s(bb_my_pawn,RankBB_A[MY_RANK3]) == 3){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 2bk1a3/4a4/4b4/9/P2n4C/2P6/8P/4B4/4A4/4KABc1 b - - 0 1
	if(EV_MY_SAFE){
		if((your_shi_num + your_xiang_num) >= 3){
			RETRUN_MUL(8);
		}
	}
}
//
//void m_MT_B_1pao3pawn_R_1pao1ma(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rk = PieceListStart(board,RKING);
//	Square bk = PieceListStart(board,BKING);
//	
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_PaoXPawn_To_1Pao1Ma_ByShi[board->R_shi];
//		}
//	}
//
//	if(board->B_shi == 2 && board->B_xiang == 2){
//		if(StoY(bk) <= 0x4){
//			board->bsafe = TRUE;
//		}
//	}
//
//	if(board->bsafe == FALSE){
//		board->mulScore += ADD_MAPAO_Xpawn_To_PAO2PawnNoSafe;
//	}
//
//	*/
//}
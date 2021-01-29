#ifndef END_my_m_MT_R_1pao1ma1pawn_B_1pao2pawn
#define END_my_m_MT_R_1pao1ma1pawn_B_1pao2pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮1马1兵对1炮2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 





void my_m_MT_R_1pao1ma1pawn_B_1pao2pawn(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1pao1maXpawn_To_1pao2pawn_ByPs[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_1pao1maXpawn_To_1pao2pawn_ByPs[my_shi_num]);

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	//Square ypao  = S90_from_piecelist(POSITION,your_pao,0);
	Square mma   = S90_from_piecelist(POSITION,my_ma,0);
	Square mpao  = S90_from_piecelist(POSITION,my_pao,0);

	//Square yk = your_king_pos;
	MY_EV_ADD(EV_MY_CAN * 32);

	// fen 3k2b2/4a1N2/4ba3/5P3/9/6B2/4pp3/B8/3CA4/1c2KA3 b - - 0 1
	Bitboard lp = Your_get_connect_Pawn(POSITION);

	// fen 4k4/2P1a4/3ab4/3c1N3/2b1C4/2B6/3p1p3/3A5/4A4/5K3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoX(mpawn) < 0x4 && PB90(MY_SQ05) != your_shi){
			MY_EV_SUB(64);
		}
		if(StoX(mpawn) > 0x4 && PB90(MY_SQ03) != your_shi){
			MY_EV_SUB(64);
		}
		//
		Bitboard yp = m_and(bb_your_pawn,RankBB_A[MY_RANK6]);
		if(count_1s(yp) == 2){
			MY_EV_SUB(128);
		}
	}

	// fen 2b1Ca3/2N1ak3/4b4/2p6/9/2P5p/9/9/4K4/3c1A3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(EV_MY_CAN == 0){
			MY_EV_SUB(32);
			if(MY_SQ04 == mpao){
				if(PB90(MY_SQ05) == your_shi && PB90(MY_SQ02) == your_xiang){
					MY_EV_SUB(128);
				}
				if(PB90(MY_SQ03) == your_shi && PB90(MY_SQ06) == your_xiang){
					MY_EV_SUB(128);
				}
			}
		}
	}

	// fen 4kab2/4a4/9/3PP4/9/2B6/3n5/4BC3/4Acp2/3A1K3 w - - 28 28
	if((your_shi_num + your_xiang_num) == 4 && PB90(MY_SQ0D) == your_shi){
		if(my_shi_num >= 1 && StoY(yk) == MY_RANK0){
			if(PB90(MY_SQ03) == your_king && PB90(MY_SQ0C) == my_pao 
				&& PB90(MY_SQ0B) == my_pawn && PB90(MY_SQ15) == your_pao){
					RETRUN_MUL(4);
			}
			if(PB90(MY_SQ05) == your_king && PB90(MY_SQ0E) == my_pao 
				&& PB90(MY_SQ0F) == my_pawn && PB90(MY_SQ17) == your_pao){
					RETRUN_MUL(4);
			}
		}
	}

	// fen C2k5/3N5/5a2c/9/8p/4p4/8P/4BA3/9/3K1AB2 w - - 0 1
	if(EV_MY_CAN == 0 && EV_YOUR_CAN >= 1 && your_shi_num >= 1){
		if(bit_is_set(EV_YOUR_XBIT,mma) && bit_is_set(ei.attacked_by(your_king),mma)){
			RETRUN_MUL(4);
		}
	}

	// fen 4k1b2/4a4/4ba3/3PP4/9/3c2B2/2Cn5/3AB4/3K5/1p7 b - - 0 1
	if(your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpawn) == MY_RANK0){ //print_bb(RankBB_A[MY_RANK6]); print_bb(ymp);
			if(count_1s(ymp,RankBB_A[MY_RANK6]) == 2){
				RETRUN_MUL(8);
			}
		}
	}

	if(EV_YOUR_CAN == 2){
		if((my_shi_num + my_xiang_num) == 0){
			MY_EV_SUB(96);
		}
	}



    // fen 2ba1k2C/4c4/3ab4/9/8N/p8/8P/2p6/9/3K1A3 w - - 0 1
	if(my_shi_num >= 1){
		if(have_bit(bb_your_pawn,MyUpBB[MY_RANK6])){
			MY_EV_ADD(32);
		}
		if(have_bit(bb_your_pawn,LeftBB[0x2])){
			MY_EV_ADD(32);
		}
		if(have_bit(bb_your_pawn,RightBB[0x6])){
			MY_EV_ADD(32);
		}
	}

	// fen 4k4/1N2aP3/3abc3/9/2b1C4/9/3pp4/4B4/4A4/3K1AB2 b - - 0 1
	//Bitboard lp = Your_get_connect_Pawn(POSITION);
	if(bit_is_set(lp,Square(MY_SQ31)) || bit_is_set(lp,Square(MY_SQ3A))){
		MY_EV_SUB(64);
		if(your_shi_num == 2 && your_xiang_num == 2){
			RETRUN_MUL(8);
		}
	}
}


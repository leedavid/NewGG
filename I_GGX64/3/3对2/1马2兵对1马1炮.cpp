#ifndef END_my_m_MT_R_1ma2pawn_B_1pao1ma
#define END_my_m_MT_R_1ma2pawn_B_1pao1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马2兵对1马1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



//
////const int ADD_MAT_R_1ma2pawn_B_1pao1ma = 96;


// 1马2兵对炮马
void my_m_MT_R_1ma2pawn_B_1pao1ma(typePOS &POSITION, EvalInfo &ei){
	// ADD
	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Square mpawn1 = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpawn2 = S90_from_piecelist(POSITION,my_pawn,1);
	Square yma = S90_from_piecelist(POSITION,your_ma,0);

	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_MaPawn_To_1Pao1Ma_ByShi[your_shi_num]);

	MY_EV_SUB(32);

	// fen 2bk5/4P4/4b3c/4N4/9/P5B2/1n7/9/4K4/5A3 b - - 0 1
	if((my_shi_num + my_xiang_num) <= 2){
		MY_EV_SUB(32);
		if(have_bit(bb_my_pawn,MyLowBB[MY_RANK4])){
			MY_EV_SUB(32);
			if(your_xiang_num == 2){
				MY_EV_SUB(32);
			}
		}
	}

	if(EV_MY_CAN <= 1){
		MY_EV_SUB(64);
		if(your_shi_num >= 1){
			MY_EV_SUB(64);
		}
	}

	// fen 9/3k1N3/9/9/4n4/2B6/6p2/6p2/8C/4K4 b - - 40 40
	if(my_shi_num == 0 && my_xiang_num == 0){
		MY_EV_SUB(96);
	}

	if((my_shi_num + my_xiang_num) <= 2){
		if(your_shi_num >= 1){
			MY_EV_SUB(96);
		}
	}

	// fen 3k1abC1/4a4/4b4/9/4pN3/p8/2n6/9/4A4/2BAK1B2 b - - 0 0
	if((your_shi_num + your_xiang_num) >= 3){
		EV_YOUR_SAFE = TRUE;
	}
	// fen 4k4/4a4/4N4/9/9/4C4/n2pp4/9/4A4/4KAB2 b - - 0 1
	if(EV_YOUR_SAFE || your_shi_num == 2){
		//if((my_shi_num + my_xiang_num) >= 1) {
			if(count_1s(RankBB_A[MY_RANK3],bmp) == 2 
				&& m_have_bit(My_get_connect_Pawn(POSITION))){
				if(bit_is_set(bmp,MY_SQ1F)){
					RETRUN_MUL(2);
				}
				RETRUN_MUL(4);
			}
		//}
	}

	// fen 2b1k4/4a2N1/9/3PP4/9/4n3c/9/9/9/5K3 w - - 0 1
	if(your_shi_num >= 1 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		Bitboard lp = My_get_connect_Pawn(POSITION);
		if(bit_is_set(lp,MY_SQ1F) || bit_is_set(lp,MY_SQ28)){
			RETRUN_MUL(4);
		}
	}


	// fen 4k4/4a4/3a5/9/2b6/6B1p/5pn2/3A2N2/4A4/2BKC4 w - - 121 121
	if(my_shi_num == 2 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9){
		if(StoY(mpawn1) MY_SMALL_EQL MY_RANK4 && StoY(mpawn2) MY_SMALL_EQL MY_RANK4){
			if(StoY(mpawn1) MY_LARGE StoY(yma) && StoY(mpawn2) MY_LARGE StoY(yma)){
				if(IsOnSameSide(mpawn1,yma) && IsOnSameSide(mpawn2,yma)){
					MY_EV_ADD(96);
					RETRUN_MUL(8);
				}
			}
		}
	}

	int mcan = EV_MY_CAN;
	// fen 3k1abC1/4a4/4b4/9/4pN3/p8/2n6/9/4A4/2BAK1B2 b - - 0 0
	if(my_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if(EV_YOUR_SAFE){
			if(mcan == 2 && StoY(mpawn1) MY_LARGE MY_RANK2 && StoY(mpawn2) MY_LARGE MY_RANK2){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3k5/9/C8/9/9/4nN3/5p3/9/4AK3/4p4 b - - 0 1
    if(my_xiang_num == 0 && my_shi_num <= 1){
		if(StoY(mpawn1) == MY_RANK3 && abs(StoX(mpawn1) - 0x4) <= 1){
			RETRUN_MUL(8);
		}
		if(StoY(mpawn2) == MY_RANK3 && abs(StoX(mpawn2) - 0x4) <= 1){
			RETRUN_MUL(8);
		}
	}

	// fen 7P1/2P1a4/3a1k3/9/3c1N3/5n3/9/9/4K4/9 b - - 0 1
    if(your_xiang_num == 0 && your_shi_num >= 1){
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK4])){  // 二个兵都过河了
			if(have_bit(bb_my_pawn,RankBB_A[MY_RANK1])){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4k4/4a4/6N1b/2PP5/4n4/9/8c/3A1A3/9/3K5 b - - 0 1
	if(your_shi_num <= 1){

		Bitboard lp = My_get_connect_Pawn(POSITION);
		if(have_bit(lp,RankBB_A[MY_RANK3])){
			MY_EV_ADD(64);
			RETRUN_MUL(8);
		}

	}

}

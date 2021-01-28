#ifndef END_my_m_MT_R_1pao2pawn_B_1pao1ma
#define END_my_m_MT_R_1pao2pawn_B_1pao1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮2兵对1炮1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


// 炮2兵对炮马
void my_m_MT_R_1pao2pawn_B_1pao1ma(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_PaoXPawn_To_1Pao1Ma_ByShi[your_shi_num]);

	Square mk   = my_king_pos;
	Square mpao = S90_from_piecelist(POSITION,my_pao,0);

	// fen 3k5/6P1P/b4a3/5c3/9/9/9/9/5Cn2/4K4 w - - 0 1
	if(your_shi_num <= 1 && your_xiang_num <= 1 && EV_MY_CAN == 2){
		if(StoX(mk) == 0x4){
			MY_EV_ADD(32);
		}
		if(count_1s(bb_my_pawn,RankBB_A[MY_RANK1]) == 2){
			MY_EV_ADD(64);
		}
		if(StoY(mpao) MY_LARGE_EQL MY_RANK8){
			MY_EV_ADD(32);
		}
	}

	//  fen 3ak1b2/4a4/b2c5/9/P8/2C2n3/4P3P/4B4/9/3AKAB2 b - - 0 1
	if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9) {
		MY_EV_ADD(EV_MY_CAN * 32);
	}

	// fen 5a3/4a1C2/3kc3b/9/2P6/8P/P3n1P2/4B4/4A4/4KAB2 w - - 0 1
	if((your_shi_num + your_xiang_num) >= 3){
		Bitboard mlowp = m_and(bb_my_pawn,MyLowBB[MY_RANK3]);
		MY_EV_SUB((sint16)count_1s(mlowp) * 32);
	}

	// fen 3a5/4ak3/2P6/4P4/2b6/9/5C3/B4An2/3KA4/2B5c b - - 126 126
    //如果炮方是仕相全，且炮在二线以下，就要加分
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if(StoY(mpao) MY_LARGE_EQL MY_RANK5){
		   EV_MY_SAFE = TRUE;
		}
	}
	// fen 1P5P1/4a4/3k5/4c4/9/4C1B2/9/3A2n2/4A4/4K1B2 b - - 0 1
	if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK0])){
		EV_YOUR_SAFE = TRUE;
	}


	if(EV_MY_SAFE == FALSE){
		MY_EV_SUB(ADD_MAPAO_Xpawn_To_PAO2PawnNoSafe);
	}
	Bitboard lp = My_get_connect_Pawn(POSITION);
	// fen 2ba1k3/4a4/9/3PP4/2b6/2B1n4/4C2c1/5A2B/4A4/4K4 b - - 120 120
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){		
		//有连兵,就要加分
		if(m_have_bit(lp)){
			MY_EV_ADD(128);
		}
	}

	if((your_shi_num + your_xiang_num) >= 2){
		EV_YOUR_SAFE = TRUE;
	}

	// fen 2bak4/4a4/4b4/3PPC3/5c3/9/3n5/9/9/4KA3 b - - 0 1
	if(EV_YOUR_SAFE){
		if(bit_is_set(lp,MY_SQ28) || bit_is_set(lp,MY_SQ1F)){
			if(((my_shi_num + my_xiang_num) >= 1) && StoY(mk) MY_LARGE_EQL MY_RANK8){
				RETRUN_MUL(2);
			}			
		}
	}

	// fen 4k4/4ac3/3a5/9/3N5/6B2/2pp5/4B4/4A4/3AK1C2 b - - 120 120
	if(EV_YOUR_SAFE){
		if(my_shi_num == 2 && StoY(mk) == MY_RANK9){
			if(m_have_bit(m_and(
				lp,MyLowBB[MY_RANK2]))){
					RETRUN_MUL(4);
			}
		}
	}  

	// fen 4kc3/4a4/4ba3/9/2b1PP3/2BnC4/9/9/9/4K4 b - - 121 121
	if(EV_YOUR_SAFE){
		if(my_xiang_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			if(m_have_bit(m_and(
				lp,MyLowBB[MY_RANK2]))){
					RETRUN_MUL(4);
			}
		}
	}

	// fen 2bak4/4a4/4b4/2PP3c1/9/9/5n3/9/5C3/4K4 w - - 0 1
	if(EV_YOUR_SAFE){
		if(have_bit(lp,RankBB_A[MY_RANK3]) && StoY(mpao) MY_LARGE_EQL MY_RANK3){
			RETRUN_MUL(4);
		}
	}


	// fen 9/3k5/9/6N2/8c/9/4C4/4K4/5ppp1/2B6 b - - 0 1
	// 如果多方的兵全在对方的将下面,要大大的减分
	if(pmok == 0){
		MY_EV_SUB(128);
	}

	// fen 2bk5/4a4/4ba3/3PP4/3c5/9/2n6/3K5/4A4/7C1 w - - 0 131
	//我方有二个兵相连
	if(m_have_bit(lp) && (PB90(MY_SQ1F) == my_pawn || PB90(MY_SQ28) == my_pawn)){
		if(my_shi_num >= 1 || my_xiang_num >= 1){
			RETRUN_MUL(4);
		}
	}

	// fen 3akab2/9/9/C6P1/6b2/3c5/P8/4B4/2n1A4/2BK1A3 w - - 0 1
	if(EV_YOUR_SAFE){
		if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
			RETRUN_MUL(4);
		}
	}

	// fen 3k5/4a4/9/3P1P3/2b1c4/6n2/9/3C5/9/5K3 b - - 0 1
	if(your_shi_num <= 1){
		if(count_1s(bb_my_pawn,RankBB_A[MY_RANK3]) == 2){
			if(!have_bit(bb_my_pawn,LeftBB[0x2]) && !have_bit(bb_my_pawn,RightBB[0x6])){
				RETRUN_MUL(4);
			}
		}

	}

	// fen 2b1kab2/9/3a5/4PP3/5cC2/9/9/6n2/5K3/9 w - - 0 1
	if(bit_is_set(lp,Square(MY_SQ28)) || bit_is_set(lp,Square(MY_SQ1F))){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8){
			RETRUN_MUL(4);
		}
	}

	// fen 3k5/4a4/9/3P1P3/2b1c4/6n2/9/3C5/9/5K3 b - - 0 1
	if(your_shi_num <= 1){
		if(count_1s(bb_my_pawn,RankBB_A[MY_RANK3]) == 2){
			RETRUN_MUL(8);
		}
	}

	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		RETRUN_MUL(8);
	}
}


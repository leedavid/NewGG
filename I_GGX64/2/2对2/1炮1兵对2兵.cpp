#ifndef END_my_m_MT_R_1pao1pawn_B_2pawn
#define END_my_m_MT_R_1pao1pawn_B_2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮1兵对2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//void my_m_MT_R_1MA1PAWN_B_1PAWN(board_t *board)

//const int absPPscore[10] =  {104,96,80,72,64,56,48,32,24,8};
//const int PaoXsamePawn   =   32;

//我方炮兵，对方2兵
void my_m_MT_R_1pao1pawn_B_2pawn(typePOS &POSITION, EvalInfo &ei){
	
	Square mpao     = S90_from_piecelist(POSITION,my_pao,0);
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	Square ypawn1 = S90_from_piecelist(POSITION,your_pawn,0);
	Square ypawn2 = S90_from_piecelist(POSITION,your_pawn,1);

	Square mk = my_king_pos;
	Square yk = your_king_pos;

	if(my_shi_num >= 1){
		EV_MY_SAFE = true;
	}


	//  fen 3ak1b2/4a4/4b4/6P2/9/P8/1c4P2/9/3p5/3AKA3 w - - 0 1
	if (your_shi_num == 2 && StoY(yk) == MY_RANK0) {
		if (StoY(mpawn) MY_SMALL_EQL MY_RANK1) {
			MY_EV_SUB(128);
			if (have_bit(bb_your_pawn, RankBB_A[MY_RANK6])) {
				MY_EV_SUB(64);
				MY_EV_SUB(EV_YOUR_CAN * 64);
			}
		}
	}

	// fen 9/5P3/3kba3/9/9/9/2p1C1p2/9/9/4KAB2 w - - 0 1 
	if (your_shi >= 1 && your_xiang_num >= 1 && StoY(mpawn) MY_SMALL_EQL StoY(yk)){
		MY_EV_SUB(32);
		if (my_shi_num <= 1){
			MY_EV_SUB(32);
			if (count_1s(bb_your_pawn, RankBB_A[MY_RANK6]) == 2){
				MY_EV_SUB(32);
			}
			// fen 9/4P4/3kba1C1/9/9/9/4p4/5A3/3p5/4K1B2 b - - 0 1
			Bitboard yp = m_and(bb_your_pawn, m_and(MyUpBB[MY_RANK9], MyLowBB[MY_RANK5]));
			if (count_1s(yp, m_and(LeftBB[0x6], RightBB[0x2]))){
				MY_EV_SUB(64);
			}
		}
	}

	// fen 9/3kaP3/4ba3/9/2b6/2B6/9/5K2B/2pp1C3/9 w - - 0 1
	MY_EV_ADD((sint16)count_1s(bb_your_pawn, MyLowBB[StoY(mk)]) * 80);

	// fen 4k4/3P5/b8/9/9/9/3p5/4Cp3/9/3K2B2 w - - 0 1
	if(my_shi_num == 0 && EV_YOUR_CAN >= 2){
		if(StoY(ypawn1) MY_SMALL StoY(mk)){
			MY_EV_SUB(64);
		}
		if(StoY(ypawn2) MY_SMALL StoY(mk)){
			MY_EV_SUB(64);
		}
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK2){
			MY_EV_SUB(64);
		}
		if(abs(StoY(mpawn) - StoY(yk)) <= 1){
			MY_EV_SUB(64);
		}
	}

	if(StoY(ypawn1) MY_SMALL StoY(mk) && StoY(ypawn2) MY_SMALL StoY(mk)){
		MY_EV_SUB(2 * ADD_x_Pawn_To_PaoPawnByShi[my_shi_num]);
	}

	if(my_shi_num != 0){
		EV_MY_SAFE = TRUE;
	}

	// fen 5k3/4P4/4b4/9/2b6/9/5C3/3KB4/2pp5/5A3 w - - 0 1
	if (StoY(mpawn) MY_SMALL_EQL MY_RANK2 && abs(StoY(yk) - StoY(mpawn)) <= 1){
		if (my_shi_num <= 1 && your_xiang_num >= 1){
			Bitboard lp = Your_get_connect_Pawn(POSITION);
			if (have_bit(lp, RankBB_A[MY_RANK8]) 
				&& have_bit(bb_my_shi, MyLowBB[MY_RANK8])){
					RETRUN_MUL(2);
			}
		}
	}


	// fen 4k4/5P3/3ab4/9/2b6/6B2/C2pp4/9/3KA4/5A3 w - - 120 120
	if(your_shi_num >= 1 && your_xiang_num >= 1 
		&& StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(StoY(ypawn1) == StoY(ypawn2) && abs(StoX(ypawn1) - StoX(ypawn2))){
				if(StoY(ypawn1) MY_SMALL_EQL MY_RANK6){
					Bitboard psuper = POSITION.Pao_Super_bb(mpao);
					if(bit_is_set(psuper,yk) && StoX(mpao) == 0x4){
					}
					else{
						if(my_shi_num >= 1){
							RETRUN_MUL(2);
						}
						RETRUN_MUL(4);
					}
				}
			}
	}

	// fen 4k4/4aP3/b4a3/9/9/9/5p3/4B4/3KC4/5p3 w - - 0 1
	if(my_shi_num == 0 && my_xiang_num <= 1){
		if(your_shi_num == 2 && your_xiang_num >= 1 && have_bit(bb_your_pawn,RankBB_A[MY_RANK6])){
			if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
				if(StoX(mpawn) < 0x4 && PB90(MY_SQ15) == your_shi){
					RETRUN_MUL(4);
				}
				if(StoX(mpawn) > 0x4 && PB90(MY_SQ17) == your_shi){
					RETRUN_MUL(4);
				}
			}
		}
	}

	if(StoY(mpawn) MY_LARGE MY_RANK2 && your_xiang_num == 0){
		// fen 3a1a3/9/5k3/p8/9/4P4/9/C7p/9/4K4 w r can win
		if(StoY(ypawn1) MY_LARGE_EQL MY_RANK7 && StoY(ypawn2) MY_SMALL_EQL MY_RANK4){
			MY_EV_ADD(96);
		}
		if(StoY(ypawn2) MY_LARGE_EQL MY_RANK7 && StoY(ypawn1) MY_SMALL_EQL MY_RANK4){
			MY_EV_ADD(96);
		}
	}

	// fen 3k5/4aP3/5a3/9/9/6C2/3pp4/4B4/4A4/2B1KA3 b - - 0 1
	if(your_shi_num == 2){
		if(PB90(MY_SQ15) == your_shi || PB90(MY_SQ17) == your_shi){
			Bitboard lp = Your_get_connect_Pawn(POSITION);
			if(bit_is_set(lp,Square(MY_SQ3A)) || bit_is_set(lp,Square(MY_SQ31))){
				MY_EV_SUB(96);
				RETRUN_MUL(4);
			}
		}
	}

	// fen 5a3/3P5/3a1k3/9/9/4C1B2/2p1p4/5A3/4A4/2BK5 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && StoY(mpawn) MY_SMALL_EQL StoY(mk)){
			Bitboard fp2 = m_and(bb_your_pawn,RankBB_A[MY_RANK6]);
			if(count_1s(fp2) == 2){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 5k3/9/b2P5/9/9/9/3pp4/9/C3A4/3K2B2 r
	if(StoY(yk) == MY_RANK0 && PB90(MY_SQ0D) == my_pawn){
	}
	else{
		if(your_xiang_num >= 1 && my_shi_num <= 1){
			Bitboard lp = Your_get_connect_Pawn(POSITION);
			if(bit_is_set(lp,MY_SQ3A) || bit_is_set(lp,Square(MY_SQ31))){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4k2P1/9/4b4/9/9/9/3pp4/5A3/3K1C3/2B2A3 w - - 0 1
	if(StoY(mpawn) == MY_RANK0){
		if(your_xiang_num >= 1 || your_shi_num == 2){
			if(StoY(ypawn1) == StoY(ypawn2)){
				if(StoY(ypawn1) == MY_RANK5 || StoY(ypawn1) == MY_RANK6){
					if(abs(StoX(ypawn1) - StoX(ypawn2)) <= 2){
                        if(PB90(MY_SQ3A) == your_pawn || PB90(MY_SQ31) == your_pawn){
							RETRUN_MUL(4);
						}
					}
				}
			}
		}
	}


	// fen 4k1PP1/4aC3/b2ab4/9/p8/9/p8/5A3/9/4KAB2 w - - 0 1
	if(EV_MY_SAFE){
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK0])){
			if(your_shi_num == 2 && your_xiang_num == 2 && have_bit(bb_your_pawn,RankBB_A[MY_RANK6])){
				RETRUN_MUL(4);
			}
		}
	}

	
	// fen 9/5k3/9/4P2P1/9/9/9/6p2/4K1c2/9 w - - 0 0
	if(my_shi_num == 0 && my_xiang_num == 0){		

		if(StoY(ypawn1) MY_SMALL StoY(mk) && StoY(ypawn2) MY_SMALL StoY(mk)){
			MY_EV_SUB(128);
		}
		if(abs(StoX(ypawn1) - 0x4) >= 3 || abs(StoX(ypawn2) - 0x4) >= 3){
			RETRUN_MUL(8);
		}
	}

	// fen P8/3k5/9/9/9/9/9/3p5/3p4C/4K4 w - - 0 0 
	// 这个不和
	if(StoY(mpawn) MY_SMALL_EQL StoY(yk)){
		if((my_shi_num + my_xiang_num) == 0){
			if(PB90(MY_SQ4C) != your_pawn){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 5k3/4P4/2c1b4/5P3/9/9/9/4K4/1p2A4/3A5 w - - 0 1
	if(my_shi_num == 0 && my_xiang_num >= 1){
		if(StoY(mpawn) MY_SMALL_EQL StoY(yk) || EV_MY_CAN == 0){
			if(EV_YOUR_CAN == 2){
				if(StoY(ypawn1) MY_SMALL_EQL MY_RANK6 || StoY(ypawn2) MY_SMALL_EQL MY_RANK6 ){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 4k4/3P5/b8/9/9/9/3p5/4Cp3/9/3K2B2 w - - 0 1
	if(EV_MY_CAN >= 1 && EV_YOUR_CAN == 2){
		if(my_shi_num == 0){
			RETRUN_MUL(8);
		}
	}
	
}


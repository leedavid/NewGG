#ifndef END_my_m_MT_R_1che1pao1pawn_B_1che1ma1pawn
#define END_my_m_MT_R_1che1pao1pawn_B_1che1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮1兵对1车1马1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int  AD_Che_CanNotMove = 256;

void my_m_MT_R_1che1pao1pawn_B_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_ChePaoPawn_ChePao1pawn_ByPawnByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_CheMaPawn_ChePao1pawn_ByPawnByShi[my_shi_num]);

	Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	Square yma  = S90_from_piecelist(POSITION,your_ma,0);
	Square yche = S90_from_piecelist(POSITION,your_che,0);

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	// CR1ak1b2/4a4/1P2b4/1r7/3n5/9/4p4/4B4/4A4/2BAK4 w
	// 车兵对对方牵制住了。
	//if(your_shi_num == 2 && your_xiang_num == 2 && !IsOnSameSide(yche,mk)){
	//	//if(is)
	//}



	// fen 2bk5/5R3/4b4/9/C8/6P2/8P/4BKn2/8r/3p2B2 w - - 0 1
	if(my_shi_num == 0){
		if(StoY(yma) MY_LARGE_EQL MY_RANK5){
			MY_EV_SUB(32);
		}
		if(have_bit(bb_your_pawn,MyLowBB[MY_RANK4])){
			MY_EV_SUB(32);
		}
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
			MY_EV_SUB(32);
		}
	}

	//  fen 2bak4/4a4/4b4/6RC1/9/P3p1Br1/1n6P/9/4A4/2BK1A3 w - - 0 1
	if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9) {
		MY_EV_ADD(32 * EV_MY_CAN);
	}

	// fen 2C6/3ka4/3a5/9/p7P/9/r4n3/4B4/1R7/4K1B2 w - - 0 1
	if(my_shi_num == 0){
		if(EV_YOUR_CAN >= 1){
			MY_EV_SUB(32);
		}
		if(abs(StoX(mpawn) - 0x4) == 4){
			MY_EV_SUB(16);
		}
	}

	// fen 2bak4/4a4/4b4/7RC/6n2/6B1P/5p3/4r4/4A4/4KA3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_LARGE_EQL MY_RANK4){
			EV_YOUR_SAFE = true;
		}
	}

	//  fen 3a1k3/4a4/9/9/3P5/1p6N/6R2/B8/5r3/c3K1B2 b - - 0 1
	if ((my_xiang_num + my_xiang_num) <= 2 && StoY(mpawn) MY_LARGE_EQL MY_RANK4) {
		if (StoY(yma) MY_LARGE_EQL MY_RANK4) {
			MY_EV_SUB(32);
			if (StoY(ypawn) MY_LARGE_EQL MY_RANK5) {
				MY_EV_SUB(16);
			}
		}
	}


	// fen 2bak4/4a4/4b4/9/P6P1/9/3np4/B2C3r1/1R2A4/4KA3 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9){
		if(StoY(mpao) MY_LARGE_EQL MY_RANK7 && StoY(ypawn) MY_SMALL_EQL MY_RANK6){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	// fen 3aknbC1/4a2P1/4b1r2/8R/9/6B2/9/5Ap1B/4A4/4K4 r
	if(your_shi_num == 2 && your_xiang_num == 2 && yk == MY_SQ04 && StoY(mpao) == MY_RANK0){
		if(PB90(MY_SQ05) == your_ma && StoX(mpao) >= 0x7 && StoX(mpawn) >= 0x7 && IsOnSameSide(yche,mpawn)){
			EV_YOUR_SAFE = true;
		}
		if(PB90(MY_SQ03) == your_ma && StoX(mpao) <= 0x1 && StoX(mpawn) <= 0x1 && IsOnSameSide(yche,mpawn)){
			EV_YOUR_SAFE = true;
		}
	}

	

	// fen 3aknbC1/4a2P1/4b4/5R3/6r2/6B2/9/5Ap1B/4A4/4K4 b - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if(StoY(yma) MY_SMALL_EQL MY_RANK2){
			if(StoY(ypawn) MY_SMALL_EQL MY_RANK7 || abs(StoX(ypawn) - 0x4) >= 2){
				EV_MY_SAFE = true;
			}
		}
	}


	// fen 3ak4/9/3ab4/5R3/6b2/2P1N4/9/3AB4/3KApc2/5r3 w - - 60 60
	//红方的车给自己搞死了。
	if(PB90(MY_SQ0D) == your_shi && your_xiang_num >= 1 && StoY(mpao) == MY_RANK1){
		if(PB90(MY_SQ0E) == my_pawn && PB90(MY_SQ05) == my_che && PB90(MY_SQ0C) == your_king){
			if(StoX(yche) == 0x5){				
				Bitboard matt = POSITION.ma_to_king_attacks_bb(yma);
				if(bit_is_set(matt,yche)){
					MY_EV_SUB(196);
				}
			}
		}
		if(PB90(MY_SQ0C) == my_pawn && PB90(MY_SQ03) == my_che && PB90(MY_SQ0E) == your_king){
			if(StoX(yche) == 0x3){				
				Bitboard matt = POSITION.ma_to_king_attacks_bb(yma);
				if(bit_is_set(matt,yche)){
					MY_EV_SUB(196);
				}
			}
		}
	}

	int mcan = EV_MY_CAN;
	int ycan = EV_YOUR_CAN;

	// fen 2bakc3/4a4/9/p7r/3R5/2N6/P8/4B4/4A4/3AK1B2 b - - 2 2
	if(mcan == 0 && ycan == 0){
		if(StoY(yk) == MY_RANK0 && StoY(mk) == MY_RANK9){
			if(your_shi_num == 2 && your_xiang_num == 2){
				if((my_shi_num + my_xiang_num) >= 3){
					RETRUN_MUL(8);
				}
			}
		}
	}


	// fen 4ka3/4a4/b3c4/p8/2b6/2N1r4/P8/B4R3/4K4/2B6 w - - 0 1
	if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(EV_YOUR_CAN == 0){
			EV_MY_SAFE = true;
		}
	}


	// fen 2bk2b2/4a4/3a5/9/p6P1/1R4N2/3r3c1/3AB4/4A4/2B1K4 b - - 0 1
	if((your_shi_num + your_xiang_num) == 4 && (my_xiang_num + my_shi_num) == 4){
		if(StoY(mk) == MY_RANK9 && StoY(yk) == MY_RANK0){
			if(StoY(mpawn) MY_LARGE_EQL MY_RANK2 && StoY(ypawn) MY_SMALL_EQL MY_RANK7){
				RETRUN_MUL(8);
			}
		}
	}

	
	// fen 3a2R2/4k4/5a3/9/3r2n1p/P8/9/B2AB4/3K5/5C3 w - - 0 1
	if(your_xiang_num == 0 && StoY(ypawn) MY_SMALL_EQL MY_RANK4){
		if(my_xiang_num == 2 && my_shi_num >= 1){
			if(StoY(mpao) MY_LARGE_EQL MY_RANK7){
				MY_EV_ADD(64);
			}
		}
	}

	// fen 2b2k3/1Nr1a4/c4a3/9/p5b2/9/PR7/3ABA3/9/5K3 b - - 0 1
	if(EV_YOUR_SAFE){
		if(EV_MY_CAN == 0){
			if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
				RETRUN_MUL(8);
			}
		}
	}

    // fen 2bak4/4a4/4b4/7RC/6n2/6B1P/5p3/4r4/4A4/4KA3 b - - 0 1
	if(EV_YOUR_SAFE){
		if(my_shi_num == 2 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9){
			if(StoY(yma) MY_SMALL_EQL MY_RANK4){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3aknbC1/4a2P1/4b4/5R3/6r2/6B2/9/5Ap1B/4A4/4K4 b - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if(abs(StoX(mpawn) - 0x4) >= 3){
				RETRUN_MUL(8);
			}
		}
	}
	// fen 4kab2/4a4/4b4/p2R5/2n3P2/r8/9/9/4A4/3AKC3 b - - 0 1
	if(EV_YOUR_SAFE){
		if(my_shi_num == 2 && StoY(mk) == MY_RANK9 && StoY(mpao) MY_LARGE_EQL MY_RANK7){
			if(!IsOnSameSide(mk,yma) && StoY(ypawn) MY_SMALL_EQL MY_RANK4){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3ak1b2/4a4/8b/5P3/9/9/1r7/3A2p2/5Rn2/3CKAB2 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num >= 1 ){
		if (my_shi_num == 2 && my_xiang_num >= 1 && StoY(mpao) MY_LARGE_EQL MY_RANK7){
			if (StoY(mk) == MY_RANK9){
				if (PB90(MY_SQ4D) == my_che && PB90(MY_SQ4E) == your_ma && MY_SQ45 == ypawn){
					if (StoX(mpao) < 0x4){
						RETRUN_MUL(8);
					}
				}
				if (PB90(MY_SQ4B) == my_che && PB90(MY_SQ4A) == your_ma && MY_SQ41 == ypawn){
					if (StoX(mpao) > 0x4){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}
	 
	// fen R2akab2/9/4b4/9/9/4p4/P7r/4B4/2nCK4/3A1AB2 w - - 0 1
	if (EV_YOUR_SAFE){
		if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mpao) MY_LARGE_EQL MY_RANK5){
			if (StoY(mk) MY_LARGE_EQL MY_RANK8 && StoY(ypawn) MY_SMALL_EQL MY_RANK6){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3aka3/9/4b4/4R4/6b2/P8/3r3n1/B3C4/4A1p2/2B1KA3 b - - 0 1
	if (EV_YOUR_SAFE) {
		if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9) {
			RETRUN_MUL(8);
		}
	}


	// fen 6b2/4k4/3r4b/8p/4R1n2/6B2/8P/4C3B/4A4/3AK4 b - - 0 1
	if(EV_MY_SAFE){
		if(your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(yma == MY_SQ2A && PB90(MY_SQ23) == your_pawn && PB90(MY_SQ3E) == my_pawn){
				RETRUN_MUL(8);
			}
			if(yma == MY_SQ26 && PB90(MY_SQ1B) == your_pawn && PB90(MY_SQ36) == my_pawn){
				RETRUN_MUL(8);
			}
			if(EV_MY_CAN == 0){
				RETRUN_MUL(12);
			}
		}
	}


	// fen 4k4/4a4/4ba2b/3P1R3/9/1r7/5np2/9/4A4/3CKAB2 b - - 0 1
	if (your_shi_num >= 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
		if (StoY(mpawn) MY_LARGE_EQL MY_RANK3){
			if (my_shi_num == 2 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9){
				if (StoY(ypawn) MY_SMALL_EQL MY_RANK6 && StoY(mpao) MY_LARGE_EQL MY_RANK7){
					RETRUN_MUL(12);
				}
			}
		}
	}
}

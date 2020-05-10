#ifndef END_my_m_MT_R_1che1pao2pawn_B_1che1pao1pawn
#define END_my_m_MT_R_1che1pao2pawn_B_1che1pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1炮2兵对1车1炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che1pao2pawn_B_1che1pao1pawn(typePOS &POSITION, EvalInfo &ei) {

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn, MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_ChePaoPawn_ChePao1pawn_ByPawnByShi[your_shi_num]);
	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn, MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * ADD_ChePaoPawn_ChePao1pawn_ByPawnByShi[my_shi_num]);

	int mcan = EV_MY_CAN;
	int ycan = EV_YOUR_CAN;



	Square ypao = S90_from_piecelist(POSITION, your_pao, 0);
	//Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	Square mche = S90_from_piecelist(POSITION, my_che, 0);
	Square yche = S90_from_piecelist(POSITION, your_che, 0);
	Square ypawn = S90_from_piecelist(POSITION, your_pawn, 0);

	// fen 4k1b2/4a4/4b4/C8/4P3p/2P3R2/P3cr3/3A5/4K4/6B2 w - - 0 1
	if (StoY(ypawn) MY_SMALL_EQL MY_RANK4) {
		MY_EV_ADD(EV_MY_CAN * 16);
	}
	if (abs(StoX(ypawn) - 0x4) == 4) {
		MY_EV_ADD(EV_MY_CAN * 16);
	}

	// fen 2b1ka3/4a4/4b4/p2P5/6c1R/9/6r1P/3C4B/4A4/2BA1K3 b - - 0 1
	if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9) {
		if (StoY(ypawn) MY_SMALL_EQL MY_RANK7) {
			EV_MY_SAFE = true;
		}
	}


    // fen C3k4/4a4/9/P3R4/4P4/9/4r2p1/3K5/9/3A2c2 w - - 0 1
	if(your_shi_num >= 1 && yk == MY_SQ04){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
			if(my_shi_num <= 1 && StoY(mk) != MY_RANK9){
				if(PB90(MY_SQ28) == my_pawn && StoX(mche) == 0x4){
					if(StoX(yche) == 0x4){
						MY_EV_SUB(64);
						if(StoY(ypawn) MY_LARGE_EQL MY_RANK6){
							MY_EV_SUB(32);
						}
					}
				}
			}
		}
	}

	// fen 4kab2/4a4/4b4/9/2c3p2/2C1R3P/4P4/1r7/4A4/3AK4 b - - 0 1
	if(my_shi_num == 2 || my_xiang_num == 2){
		if(StoY(mk) MY_LARGE_EQL MY_RANK8 && StoY(ypawn) MY_SMALL_EQL MY_RANK4){
			MY_EV_ADD(EV_MY_CAN * 16);

			if(bit_is_set(ei.attacked_by(MY_COLOR),ypawn MY_ADD 0x9)){
				MY_EV_ADD(EV_MY_CAN * 16);
			}
		}
	}

	// fen 3k2b2/4a4/4ba3/6r1p/3PC4/3R4P/9/5A3/3KA4/8c b - - 127 127
	if(ycan == 0 && mcan >= 1 && StoY(ypao) MY_LARGE MY_RANK5){
		if((my_shi_num + my_xiang_num) >= 2){
			MY_EV_ADD(mcan * 16);
		}
	}

	// fen 4k4/4ac3/3Cb4/R8/2r6/4P4/8P/B8/2p1A4/3A1KB2 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		MY_EV_ADD(EV_MY_CAN * 16);
		if((StoX(ypawn) < 0x4 && PB90(MY_SQ56) != my_shi) 
			||(StoX(ypawn) > 0x4 && PB90(MY_SQ54) != my_shi)){
				MY_EV_ADD(16);
		}
	}

	// fen 4kab2/4a4/4b4/4p4/4c4/2P6/P3R4/4B4/4A4/r2CKAB2 w - - 7 7
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if(My_pawn_already_over_river(POSITION) == 0){
			MY_EV_SUB(96);
		}
	}

	// fen 3ak4/9/3ab4/9/p4P2p/2R6/1rC6/3ABA3/4K4/c5B2 w - - 0 51
	MY_EV_ADD(EV_MY_CAN * 16);

	// fen 2b2k3/5c3/9/8p/5R3/5C2P/5r3/9/2p1A4/2B1KAB2 w - - 0 1
	//如果我的车炮被牵制了，且没有兵可过河，就要减分。
	if(isStringByChe(POSITION,mche,ypao,yche)){
		if(!bit_is_set(_mm_andnot_si128(ei.attacked_by(your_che),YOUR_ATTACK),ypao)){
			MY_EV_ADD(32);
			if(EV_YOUR_CAN == 0){
				MY_EV_ADD(32);
			}
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 2b1kacC1/4a4/4b4/8p/R8/4P3P/P8/3A5/3K5/5r3 w - - 0 1
	if(EV_YOUR_CAN == 0){
		if(bit_is_set(EV_MY_XBIT,ypao) && StoY(ypao) == MY_RANK0){
			MY_EV_ADD(EV_MY_CAN * 32);
		}
	}

	// fen 3k1a3/4aP3/4b4/p3r2cR/6b2/P1B6/9/3A5/4A2C1/2B1K4 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && EV_MY_CAN <= 1){

		if(StoY(yk) == MY_RANK0){
			MY_EV_SUB(64);
		}

		if(isStringByChe(POSITION,yche,ypao,mche)){
			if(abs(StoX(mche) - 0x4) == 4){
				MY_EV_SUB(64);
				//得到我方的过河兵，
				Bitboard ghp = m_and(bb_my_pawn,MyUpBB[MY_RANK2]);
				if(count_1s(ghp) == 1){
					Square mp = pop_1st_bit_sq(ghp);
					if(StoX(mp) > 0x4 && PB90(MY_SQ03) != your_shi){
						if(StoX(mche) == 0x8){
							MY_EV_SUB(96);
						}
					}
					if(StoX(mp) < 0x4 && PB90(MY_SQ05) != your_shi){
						if(StoX(mche) == 0x0){
							MY_EV_SUB(96);
						}
					}
				}
			}
		}		
	}

	// fen R2ak4/4a4/4b3c/6r2/2p6/9/2P5P/4BC3/4A4/4KAB2 w - - 0 1
	if(EV_YOUR_CAN == 0 && EV_MY_CAN <= 1){
		if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK4])){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 2b1ka3/4a4/4b4/p2P5/6c1R/9/6r1P/3C4B/4A4/2BA1K3 b - - 0 1
	if (EV_MY_SAFE) {
		if ((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0) {
			MY_EV_SUB(EV_YOUR_CAN * 64);
			if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK3])) {
				Bitboard l2b = m_and(MyLowBB[MY_RANK4], m_or(LeftBB[0x1], RightBB[0x7]));
				if (have_bit(bb_my_pawn, l2b)) {
					RETRUN_MUL(8);
				}
			}
		}
	}

}

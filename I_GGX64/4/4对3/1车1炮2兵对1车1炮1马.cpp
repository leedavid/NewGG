#ifndef END_my_m_MT_R_1che1pao2pawn_B_1che1pao1ma
#define END_my_m_MT_R_1che1pao2pawn_B_1che1pao1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

//#include "..\\..\\endgame\mat.h"
#include "1车1炮2兵对1车1炮1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

void my_m_MT_R_1che1pao2pawn_B_1che1pao1ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	Square ypao = S90_from_piecelist(POSITION, your_pao, 0);
	Square mpao = S90_from_piecelist(POSITION, my_pao, 0);
	//
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_ChePaoXPawn_To_1Pao2Ma_ByPawn[your_shi_num]);

	//fen 3ak1b2/4a4/4b4/4c4/1r4n2/2P3B2/4R3P/4B4/4A4/2C1KA3 w - - 0 1
	if (your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if (!have_bit(bb_my_pawn, MyUpBB[MY_RANK3]) 
			&& (EV_MY_CAN <= 1 || !have_bit(bb_my_pawn,MyUpBB[MY_RANK3]))){
			EV_YOUR_SAFE = true;
		}
	}

	// fen 3k2b2/2R2C3/4ba3/9/7c1/4P1P2/P3r4/4B3B/4A3n/4KA3 w - - 0 1
	if((your_shi_num + your_xiang_num) >= 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		Bitboard mp = m_and(bb_my_pawn,MyLowBB[MY_RANK4]);
		MY_EV_SUB((sint16)count_1s(mp) * 16);
	}

	if(StoY(yma) MY_LARGE_EQL MY_RANK4){
		MY_EV_SUB(32);
	}
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
			MY_EV_SUB(32);
		}
		if(count_1s(bb_my_pawn,MyLowBB[MY_RANK4]) >= 2){
			MY_EV_SUB(32);
		}
	}


	// fen 3ak4/4a4/4bc3/p5r2/2b3p2/2N4R1/9/3AB4/4C4/4KAB2 w - - 0 1
	if (my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if (StoY(yma) MY_SMALL_EQL MY_RANK4){
			MY_EV_ADD(32);
		}
		if (StoY(ypao)MY_SMALL_EQL MY_RANK4){
			MY_EV_ADD(32);
		}
		MY_EV_ADD(EV_MY_CAN * 16);
		if (StoY(mpao) MY_LARGE_EQL MY_RANK7){
			MY_EV_ADD(32);
		}

		// fen 3ak1b2/4a4/4b4/4c4/1r4n2/2P3B2/4R3P/4B4/4A4/2C1KA3 w - - 0 1
		if (StoY(mpao) == MY_RANK9){
			MY_EV_ADD(64);
			if (StoX(mpao) < 0x4 && PB90(MY_SQ54) != my_shi){
				MY_EV_ADD(32);
			}
			if (StoX(mpao) > 0x4 && PB90(MY_SQ56) != my_shi){
				MY_EV_ADD(32);
			}
			if (EV_YOUR_SAFE ){
				if (EV_MY_CAN <= 1 || !have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
					RETRUN_MUL(8);
				}
				RETRUN_MUL(12);
			}
		}
	}



}
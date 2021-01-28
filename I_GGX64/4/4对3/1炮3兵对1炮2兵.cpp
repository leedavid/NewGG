#ifndef END_my_m_MT_R_1pao3pawn_B_1pao2pawn
#define END_my_m_MT_R_1pao3pawn_B_1pao2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮3兵对1炮2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int RBcanByPawnAdd = 48;


void my_m_MT_R_1pao3pawn_B_1pao2pawn(typePOS &POSITION, EvalInfo &ei){	
	// ADD
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1PaoXPawn_1PaoXPawn_ByShi[your_shi_num]);

	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1PaoXPawn_1PaoXPawn_ByShi[my_shi_num]);

	//一个和型

	int mcan = EV_MY_CAN;
	int ycan = EV_YOUR_CAN;

	// fen 4kab2/4a4/4b4/p3P3p/7c1/6C2/4P3P/5A3/9/3K1A3 w - - 0 1
	if(EV_YOUR_CAN == 0){
		EV_MY_SAFE = TRUE;
	}

	if(EV_YOUR_CAN <= 1){
		if(my_shi_num >= 1){
			EV_MY_SAFE = TRUE;
		}
	}

	// fen 1c7/5k3/9/9/5P3/3C5/P3p3P/2p6/4K4/2B6 b - - 0 1
	if (my_shi_num == 0 && my_xiang_num <= 1){
		if (count_1s(bb_your_pawn, MyLowBB[MY_RANK5]) == 2 && EV_YOUR_CAN == 2){
			MY_EV_SUB(16);
			if (count_1s(bb_my_pawn, MyLowBB[MY_RANK4]) >= 2){
				MY_EV_SUB(16);
				if (count_1s(bb_my_pawn, m_or(LeftBB[0x1], RightBB[0x7])) >= 2){
					MY_EV_SUB(16);
				}
			}
		}
	}

	//如果黑方小于一个兵过河,红方有二个以上的兵过河,则红方要加分
	if(mcan >= 2 && ycan <= 1){
		MY_EV_ADD(48 * mcan);
	}
	
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);

	// fen 3k5/4a4/4ba3/1C2P4/p1b4P1/5p3/P3c4/3AB4/4A4/4K1B2 b - - 31 31
	if((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if(StoY(ypao) == MY_RANK6){
			Bitboard p = m_and(bb_your_pawn,
				m_or(RankBB_A[MY_RANK5],RankBB_A[MY_RANK6]));
			if(m_have_bit(p)){
				if(PB90(MY_SQ24) == your_pawn && PB90(MY_SQ36) == my_pawn){
					RETRUN_MUL(4);
				}
				if(PB90(MY_SQ2C) == your_pawn && PB90(MY_SQ3E) == my_pawn){
					RETRUN_MUL(4);
				}
			}
		}
		
	}


	if(EV_MY_CAN == 3){
		if((my_shi_num + my_xiang_num) == 4 && StoY(mk) MY_LARGE_EQL MY_RANK8){
			MY_EV_ADD(EV_MY_CAN * 16);
		}
	}

	// fen 4ka3/2PC5/5a2b/p7p/2b6/9/c3P3P/9/4A4/2BAK1B2 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			if(EV_MY_CAN <= 2 && StoY(ypao) MY_SMALL_EQL MY_RANK6){
				if(count_1s(bb_my_pawn,MyUpBB[MY_RANK4]) <= 1){
					RETRUN_MUL(6);
				}
			}
		}
	}

	// fen 4kab2/4a4/4b4/p3P3p/7c1/6C2/4P3P/5A3/9/3K1A3 w - - 0 1
	if(EV_MY_SAFE){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
			if(EV_MY_CAN <= 2){
				Bitboard ngph = m_and(bb_my_pawn,MyLowBB[MY_RANK4]);
				if(count_1s(ngph) >= 2){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 3aka3/6C2/4b4/p7p/9/2P6/P7P/1c2B4/9/3A1KB2 w - - 0 1
	if (EV_MY_SAFE){
		if ((your_shi_num + your_xiang_num) >= 3){
			if (EV_MY_CAN == 0){
				RETRUN_MUL(8);
			}
		}
		if (EV_MY_CAN <= 1){
			if (count_1s(bb_my_pawn, MyLowBB[MY_RANK4]) == 3){
				RETRUN_MUL(8);
			}
		}
	}

}




#ifndef END_my_m_MT_R_1MA1PAWN_B_1CHE
#define END_my_m_MT_R_1MA1PAWN_B_1CHE
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马1兵对1车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


// void m_MT_B_1CHE_R_1MA(board_t *board);
// void my_m_MT_R_1CHE_B_1MA(board_t *board);

//我方一马一兵, 对方一车
void my_m_MT_R_1MA1PAWN_B_1CHE(typePOS &POSITION, EvalInfo &ei){

	Square mk    = my_king_pos;
	Square mma   = S90_from_piecelist(POSITION,my_ma,0);
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	
	
	//有一种和形
	// fen 4k4/9/4b4/4p4/2n4R1/9/9/9/9/4K4 w  例典: 一车例和马卒象 page
	if(my_xiang_num >= 1){
		if(MY_SQ3A == mpawn && PB90(MY_SQ43) == my_xiang && StoX(mk) == 0x4){			
			Bitboard matt = POSITION.ma_to_king_attacks_bb(mma);
			if(mma == MY_SQ2F || mma == MY_SQ33 
				|| bit_is_set(matt,Square(MY_SQ2F)) || bit_is_set(matt,Square(MY_SQ33))){
					RETRUN_MUL(2);
			}
		}
	}

	your_m_MT_R_1CHE_B_1MA(POSITION,ei);

	if(ei.mul <= 2){
		MY_EV_ADD( ADD_MaXPawn_To_CheByShi_WmaSafe[your_shi_num]);
	}

	// fen 3ak4/4a4/4n4/6p2/6b2/4R4/9/4B4/4K4/3A1AB2 b - - 0 1
	//兵保护着相
	if(my_shi_num == 2 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9){
		if(PB90(MY_SQ43) == my_ma){
			if(PB90(MY_SQ38) == my_pawn){
				if(PB90(MY_SQ2F) == my_xiang){
					RETRUN_MUL(2);
				}
				if(MY_SQ55 == mk && PB90(MY_SQ4C) == my_shi){
					if(PB90(MY_SQ3F) == my_xiang){
						RETRUN_MUL(2);
					}
				}
			}
			if(PB90(MY_SQ3C) == my_pawn){
				if(PB90(MY_SQ33) == my_xiang){
					RETRUN_MUL(2);
				}
				if(MY_SQ55 == mk && PB90(MY_SQ4C) == my_shi){
					if(PB90(MY_SQ47) == my_xiang){
						RETRUN_MUL(2);
					}
				}
			}
		}
	}

	// fen 2bk5/2N1a4/5a3/3P5/9/2B6/9/4B4/8r/4K4 b - - 0 1
	if(my_xiang_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(PB90(MY_SQ43) == my_xiang){
			if(StoY(mpawn) == MY_RANK3)
				if(abs(StoX(mpawn) - 0x4) <= 1){
					RETRUN_MUL(2);
				}
				RETRUN_MUL(4);
		}
	}

	// fen 3k1ab2/4a4/9/9/6b2/6N2/8P/4BA3/4K4/1r4B2 w - - 0 1
	if(my_xiang_num == 2 && my_shi_num >= 1 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if(MY_SQ33 == mma && PB90(MY_SQ44) == my_shi){
			RETRUN_MUL(4);
		}
		if(MY_SQ2F == mma && PB90(MY_SQ42) == my_shi){
			RETRUN_MUL(4);
		}
	}
	// fen 4k4/9/9/5P3/9/r8/9/5N3/4A4/3A1K3 b - - 0 1
	if (my_shi_num == 2 && StoY(mk) MY_LARGE_EQL MY_RANK8){
		if (StoY(mpawn) == MY_RANK3 && (StoY(mma) == MY_RANK7 || StoY(mma) == MY_RANK5)){
			if (PB90(MY_SQ54) == my_shi && StoX(mk) >= 0x4 && abs(StoX(mpawn) - 0x5) <= 1){
				if (abs(StoX(mma) - 0x5) <= 1 && PB90(MY_SQ44) != my_shi){
					RETRUN_MUL(4);
				}
			}
			if (PB90(MY_SQ56) == my_shi && StoX(mk) <= 0x4 && abs(StoX(mpawn) - 0x3) <= 1){
				if (abs(StoX(mma) - 0x3) <= 1 && PB90(MY_SQ42) != my_shi){
					RETRUN_MUL(4);
				}
			}
		}
	}
}


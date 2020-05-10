#ifndef END_my_m_MT_R_1che1pao1ma_B_2che
#define END_my_m_MT_R_1che1pao1ma_B_2che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮1马对2车.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int MAT_R_2che1pawn_B_1che1ma1pawn_MaSafe = 256;


void my_m_MT_R_1che1pao1ma_B_2che(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;
	Square yk = your_king_pos;
	Square mpao = S90_from_piecelist(POSITION,my_pao,0);

	if(StoY(mk) != MY_RANK9){
		MY_EV_SUB(64);
	}

	if (StoY(mk) == MY_RANK7){
		MY_EV_SUB(32);
	}

	// fen 4R4/3ka4/1N7/9/9/9/5r3/5C1rB/4AK3/3A5 b - - 0 1
	if ((your_shi_num + your_xiang_num) <= 1){
		if (my_shi_num == 2 && my_xiang_num >= 1){
			if (StoY(mk) MY_LARGE_EQL MY_RANK8){
				MY_EV_ADD(32);
			}
		}
	}

	// fen 2bak1r2/4a4/4b4/4C4/6r2/6N2/9/5R2B/4A4/3A1KB2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		MY_EV_SUB(64);
	}

	// fen 4R4/3ka4/1N7/9/9/9/5r3/5C1rB/4AK3/3A5 b - - 0 1

	// fen 4kab2/4a4/9/4R4/9/5r3/3r5/N8/4A4/1C2KA3 w - - 0 1
	if ((your_shi_num + your_xiang_num) >= 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if (my_shi_num == 2 && MY_SQ55 == mk && StoY(mpao) == MY_RANK9){
			if (StoX(mpao) < 0x4 && PB90(MY_SQ54) != my_shi){
				RETRUN_MUL(6);
			}
			if (StoX(mpao) > 0x4 && PB90(MY_SQ56) != my_shi){
				RETRUN_MUL(6);
			}
		}
	}

	// fen 2b2k3/4a4/4ba3/3N5/9/9/5R3/3Ar4/4A4/r2CK4 b - - 0 1
	if(my_shi_num == 2 && StoY(mk) == MY_RANK9){
		if(StoY(mpao) == MY_RANK9){
			if(abs(StoX(mpao) - 0x4) == 0x1){
				MY_EV_ADD(96);
				if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) MY_SMALL_EQL MY_RANK1){
					RETRUN_MUL(8);
				}
			}
		}
	}
	
	// fen 3akab2/9/4b4/R8/8c/3R5/9/4B4/nr2A4/3A1K3 b - - 2 2
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		MY_EV_SUB(128);
		if(my_shi_num == 2 && MY_SQ55 == mk){
			RETRUN_MUL(8);
		}
	}

	// fen 2bak1r2/4a4/4b4/4C4/6r2/6N2/9/5R2B/4A4/3A1KB2 w - - 0 1
	if(my_shi_num == 2 && StoY(mk) == MY_RANK9){
		if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
			RETRUN_MUL(8);
		}
	}
}

//void m_MT_B_1che1pao1ma_R_2che(typePOS &POSITION, EvalInfo &ei){
///*
//	Square bk = PieceListStart(board,BKING);
//	Square rk = PieceListStart(board,RKING);
//
//	if(StoY(bk) != 0x3){
//		board->mulScore += 128;
//	}
//
//	// fen 3akab2/9/4b4/R8/8c/3R5/9/4B4/nr2A4/3A1K3 b - - 2 2
//	if((board->R_shi + board->R_xiang) >= 3){
//		board->mulScore += 128;
//
//		if(board->B_shi == 2 && StoY(bk) == 0x3){
//			return 8;
//		}
//	}
//
//
//	*/
//}
#ifndef END_my_m_MT_R_2ma1pawn_B_2ma
#define END_my_m_MT_R_2ma1pawn_B_2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2马1兵对2马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2ma1pawn_B_2ma(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2MaXPawn_2Ma_ByPawnShi[your_shi_num]);
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	// fen 3a1a2N/3k5/b3b4/5n3/9/9/9/nN1A5/5p3/4KA3 b - - 0 1
    if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK1){
			if(StoX(mpawn) < 0x4 && PB90(MY_SQ05) != your_shi){
				RETRUN_MUL(4);
			}
			if(StoX(mpawn) > 0x4 && PB90(MY_SQ03) != your_shi){
				RETRUN_MUL(4);
			}
		}
	}

	

	//但如果黑方是仕相全,则要降一些分
	//Square yk = your_king_pos;
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		RETRUN_MUL(4);
	}
	// fen 4k4/4a3P/3a5/9/2b6/2N1n4/2n1N4/3KBA3/9/5AB2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) MY_SMALL_EQL MY_RANK1){
         MY_EV_SUB(32);

		 Bitboard bmma = m_and(bb_my_ma,MyLowBB[MY_RANK4]);
		 if(count_1s(bmma) == 2){
			 RETRUN_MUL(4);
		 }

		 RETRUN_MUL(6);
	}

	// fen 2b1k4/4a2N1/4b2n1/6N2/3n5/2P3B2/9/3AB4/4A4/4K4 w - - 0 
	if (your_shi_num >= 1 && your_xiang_num == 2 && StoY(yk) MY_SMALL_EQL MY_RANK1){
		if (EV_MY_CAN <= 1){
			RETRUN_MUL(6);
		}
	}

	if(your_shi_num == 2 && StoY(yk) == MY_RANK0){
		RETRUN_MUL(8);
	}
}


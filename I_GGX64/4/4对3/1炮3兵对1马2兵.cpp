#ifndef END_my_m_MT_R_1pao3pawn_B_1ma2pawn
#define END_my_m_MT_R_1pao3pawn_B_1ma2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1炮3兵对1马2兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1pao3pawn_B_1ma2pawn(typePOS &POSITION, EvalInfo &ei){	

	
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1PaoXPawn_1MaXPawn_ByShi[your_shi_num]);

	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	MY_EV_SUB((sint16)count_1s(ymp) * ADD_1PaoXPawn_1MaXPawn_ByShi[my_shi_num]);

	int mcan = EV_MY_CAN;
	int ycan = EV_YOUR_CAN;

	if(EV_YOUR_CAN <= 1){
		if(my_shi_num == 2){
			EV_MY_SAFE = true;
		}
	}

	// fen 4k1b2/4aPPP1/3a4b/9/9/5nB2/2p6/2p1B2C1/4A4/3K1A3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
			if(!have_bit(bb_my_pawn,LeftBB[0x4]) && PB90(MY_SQ03) != your_shi){
				MY_EV_SUB(EV_YOUR_CAN * 32);
			}
			if(!have_bit(bb_my_pawn,RightBB[0x4]) && PB90(MY_SQ05) != your_shi){
				MY_EV_SUB(EV_YOUR_CAN * 32);
			}
		}
	}

	// fen 4k1b2/4aPPP1/3a4b/9/9/5nB2/2p6/2p1B2C1/4A4/3K1A3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2){
		MY_EV_SUB(32);
		if(!have_bit(bb_my_pawn,MyLowBB[MY_RANK1])){
			if(!have_bit(bb_my_pawn,LeftBB[0x5]) 
				|| !have_bit(bb_my_pawn,RightBB[0x3])){
               MY_EV_SUB(64);
			   if(have_bit(bb_your_pawn,RankBB_A[MY_RANK6])){
				   MY_EV_SUB(64);
			   }
			}
		}
	}

	//  fen 3a2b2/1PP1a1P2/3kb4/2C6/9/9/7n1/3AB4/2p1A1p2/3K5 b - - 0 1
	if (count_1s(m_and(bb_my_pawn,MyUpBB[StoY(yk)])) == 3){
		MY_EV_SUB(32);
		MY_EV_SUB(EV_YOUR_CAN * 16);
	}


	// fen 4k1b2/4a4/3ab1n2/4p3p/9/2B1P1P1P/4C4/5A3/9/3AK1B2 w - - 0 0
	// fen 2ba1k3/4a4/4b4/8C/p7p/2P3B2/P7P/4B4/2n1A4/3K1A3 b - - 159 159
	if((your_shi_num + your_xiang_num) >= 3 && (my_shi_num + my_xiang_num) >= 3){
		if(mcan == 0 && ycan == 0){
			RETRUN_MUL(8);
		}
	}

	// fen 2bak4/4a4/4b4/5C3/4PP2p/4n4/3p4P/4B4/4A4/3AK1B2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(mcan <= 2 && my_shi_num >= 1 && ycan <= 1){
			if(count_1s(bb_my_pawn,MyUpBB[MY_RANK4]) <= 1){
				if(count_1s(RankBB_A[MY_RANK6],bb_your_pawn) >= 1
					&& count_1s(RankBB_A[MY_RANK6],bb_my_pawn) >= 1){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 2baka3/9/4b1P2/4p3p/9/P8/5n2P/4B2C1/4A4/3A1KB2 w - - 0 1
	if(EV_MY_SAFE){
		if(EV_MY_CAN <= 2){			
			MY_EV_SUB(32);
			if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
				MY_EV_SUB(EV_YOUR_CAN * 32);
				Bitboard mp = m_and(bb_my_pawn,MyLowBB[MY_RANK4]);
				if(count_1s(mp) >= 2){
					RETRUN_MUL(8);
				}
			}
		}
	}
}


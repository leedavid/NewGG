#ifndef END_my_m_MT_R_2pao1pawn_B_2ma
#define END_my_m_MT_R_2pao1pawn_B_2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2ÅÚ1±ø¶Ô2Âí.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



void my_m_MT_R_2pao1pawn_B_2ma(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2PaoXPawn_2Ma_ByPawnShi[your_shi_num]);

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	//Square yk    = your_king_pos;

	//fen 3C2b2/2P6/2n2k3/9/6b2/4n4/9/2CA5/3K5/5AB2 b - - 0 1
	if (StoY(mpawn) MY_SMALL StoY(yk)){
		MY_EV_SUB(64);
		if (your_xiang_num == 2){
			MY_EV_SUB(64);
		}
	}

	if(your_shi_num == 2 && your_xiang_num == 2){
		RETRUN_MUL(4);
	}
	// fen 4k4/4a4/P2ab1n2/9/9/2B6/1C1n5/3AB4/2C1A4/4K4 w - - 0 1
	if((my_shi_num + my_xiang_num) >= 1){
		if(your_shi_num == 2 && your_xiang_num >= 1 && StoY(yk) == MY_RANK0){
			if(abs(StoX(mpawn) - 0x4) >= 2){
				RETRUN_MUL(4);
			}
			RETRUN_MUL(8);
		}
	}

	if(my_shi_num >= 1 || my_xiang_num >= 1){
		if(StoY(mpawn) MY_SMALL StoY(yk)){
			if(your_shi_num == 2 || your_xiang_num == 2){
				RETRUN_MUL(8);
			}
		}
	}

}


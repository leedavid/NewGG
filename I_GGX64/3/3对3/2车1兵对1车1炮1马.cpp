#ifndef END_my_m_MT_R_2che1pawn_B_1che1pao1ma
#define END_my_m_MT_R_2che1pawn_B_1che1pao1ma
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2车1兵对1车1炮1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 




void my_m_MT_R_2che1pawn_B_1che1pao1ma(typePOS &POSITION, EvalInfo &ei){
	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_2CheXPawn_1Che1Pao1Ma_ByPawnShi[your_shi_num]);
	Square mk = my_king_pos;
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);

	// fen 1c2ka1R1/1R7/n3ba3/9/2b5P/9/r8/4B4/4A4/2B1KA3 w - - 0 1
	if((my_shi_num + my_xiang_num) >= 3 && StoY(mk) MY_LARGE_EQL MY_RANK8){
        if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
			if(abs(StoX(mpawn) - 0x4) >= 2 || abs(StoY(mpawn) - MY_RANK0) >= 2){
				RETRUN_MUL(8);
			}
		}
	}

}


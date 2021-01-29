#ifndef END_my_m_MT_R_1pao3pawn_B_2pao
#define END_my_m_MT_R_1pao3pawn_B_2pao
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮3兵对2炮.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 




void my_m_MT_R_1pao3pawn_B_2pao(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1PaoXPawn_2Pao_ByPawnShi[your_shi_num]);


	// fen 9/4k4/3aCa3/4p4/p8/8p/9/5A3/c3C4/2BAK1B2 b - - 0 1

	if (my_shi_num == 2){
		if (PB90(MY_SQ43) == your_pao && PB90(MY_SQ42) == my_shi && PB90(MY_SQ44) == my_shi){
			if (PB90(MY_SQ3A) == my_pawn){
				MY_EV_ADD(256);
			}
		}
	}
	
}

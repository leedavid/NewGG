#ifndef END_my_m_MT_R_2che1pawn_B_1che1ma
#define END_my_m_MT_R_2che1pawn_B_1che1ma
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "2车1兵对1车1马.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//2车1兵对2车
void my_m_MT_R_2che1pawn_B_1che1ma(typePOS &POSITION, EvalInfo &ei){
	
	Square yk = your_king_pos;
	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	
	// fen 4k4/4a1R2/b2abn3/6R1P/9/7r1/9/9/4A4/4KA3 w - - 0 1
    if(your_shi_num == 2 && your_xiang_num == 2 && MY_SQ04 == yk){
		if(MY_SQ15 == yma || MY_SQ17 == yma){
			//if(abs(StoX(mpawn) - 0x4)))
			MY_EV_SUB(64 * (abs(StoX(mpawn) - 0x4)));
		}
	}
}




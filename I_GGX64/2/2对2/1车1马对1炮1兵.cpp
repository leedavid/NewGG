#ifndef END_my_m_MT_R_1che1pawn_B_1pao1pawn
#define END_my_m_MT_R_1che1pawn_B_1pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1车1马对1炮1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//车兵对炮兵
void my_m_MT_R_1che1ma_B_1pao1pawn(typePOS &POSITION, EvalInfo &ei){
	
	// fen 4k4/4c4/9/8p/9/9/9/4R4/4N4/3AKA3 w - - 0 0
	//一个子也不能动了
	if(my_xiang_num == 0){
		if(PB90(MY_SQ55) == my_king && PB90(MY_SQ4C) == my_ma 
			&& PB90(MY_SQ54) == my_shi && PB90(MY_SQ56) == my_shi){
            Square ypao = S90_from_piecelist(POSITION,your_pao,0);
			Square mche = S90_from_piecelist(POSITION,my_che,0);
			//Square ypawn= S90_from_piecelist(POSITION,your_pawn,0);

			if(isStringByPao(POSITION,ypao,Square(MY_SQ4C),Square(MY_SQ55))){
				if(StoX(ypao) == 0x4 && StoX(mche) == 0x4 && StoY(mche)  MY_LARGE_EQL StoY(ypao)){
					MY_EV_SUB(1024);
				}
			}
		}
	}

}
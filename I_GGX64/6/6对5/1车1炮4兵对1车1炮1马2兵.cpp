#ifndef END_my_m_MT_R_1che1pao4pawn_B_1che1pao1ma2pawn 
#define END_my_m_MT_R_1che1pao4pawn_B_1che1pao1ma2pawn 
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车1炮4兵对1车1炮1马2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 



void my_m_MT_R_1che1pao4pawn_B_1che1pao1ma2pawn (typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	// fen 2baka1r1/4n4/4b4/pc2C3p/3P5/4P4/P4R2P/4BK3/4A4/9 b - - 0 1
	if(MY_SQ04 == yk && PB90(MY_SQ0D) == your_ma && PB90(MY_SQ03) == your_shi && PB90(MY_SQ05) == your_shi){
		//if(POSITION.color_of((Square)MY_SQ16) == YOUR_COLOR){
		if(color_of(POSITION.piece_on((Square)MY_SQ16)) == YOUR_COLOR){
			if(isStringByPao(POSITION,mpao,Square(MY_SQ0D),Square(MY_SQ04))){
				MY_EV_ADD(32);
				if(EV_YOUR_CAN == 0){
					MY_EV_ADD(EV_MY_CAN * 32);
				}
			}
		}
	}
}
#ifndef END_my_m_MT_R_1che2pao1ma1pawn_B_2che1ma1pawn
#define END_my_m_MT_R_1che2pao1ma1pawn_B_2che1ma1pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车2炮1马1兵对2车1马1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//const int ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan      =  32;                     //2车方有兵可过河，


void my_m_MT_R_1che2pao1ma1pawn_B_2che1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yma   = S90_from_piecelist(POSITION,your_ma,0);
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mk = my_king_pos;

	// fen 2bakr3/9/n2ab4/C5R2/8p/2N3P2/1r7/4BC3/4A4/2BAK4 w - - 0 1
    if(my_shi_num == 2 && my_xiang_num == 2 && StoY(mk) == MY_RANK9){
		if(StoY(yma) MY_SMALL_EQL MY_RANK2){
			MY_EV_ADD(32);
			if(StoY(ypawn) MY_SMALL_EQL MY_RANK5){
				MY_EV_ADD(16);
			}
			if(abs(StoX(ypawn) - 0x4) == 4){
				MY_EV_ADD(24);
			}
		}
	}

}

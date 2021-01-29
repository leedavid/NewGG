#ifndef ENDR_my_m_MT_R_1pao1ma3pawn_B_2ma3pawn
#define ENDR_my_m_MT_R_1pao1ma3pawn_B_2ma3pawn
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1炮1马3兵对2马3兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


void my_m_MT_R_1pao1ma3pawn_B_2ma3pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;

	MY_EV_ADD(32);
	// fen 2b1k1b2/4a4/5a3/2n2C2p/p3P4/6N2/P7P/2p6/4An3/2B1KA3 b - - 0 1
	if(EV_YOUR_CAN <= 1 && (my_shi_num + my_xiang_num) >= 2 && StoY(mk) == MY_RANK9){		
		MY_EV_ADD(32);		
	}

	// fen 2bak2C1/4a4/2n1b2N1/7P1/p1p2P3/4p4/Pn7/9/4A4/2BAK4 b - - 0 1
	if (EV_MY_CAN >= 2 && my_shi_num >= 2 && StoY(mk) == MY_RANK9){
		MY_EV_ADD(32);
	}

	// fen 4kab2/4a4/4b4/4p1p2/C7p/2P1PnP2/8n/4B2N1/9/2BAKA3 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2){
		if(EV_MY_CAN == 0){
			MY_EV_SUB(32);
			MY_EV_SUB(EV_MY_CAN * 16);
		}		
	}

	// fen 2bak4/4a4/4b4/p7p/2n2n3/P4N3/C5P1P/2p6/4A4/2BAK1B2 w - - 0 1
	if(my_shi_num == 2 && my_xiang_num == 2 && EV_YOUR_CAN <= 1){
		if(your_shi_num == 2 && your_xiang_num == 2 && EV_MY_CAN == 0){
			RETRUN_MUL(12);
		}
	}

}
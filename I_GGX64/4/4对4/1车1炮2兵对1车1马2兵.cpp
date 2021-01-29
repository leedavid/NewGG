#ifndef END_my_m_MT_R_1che1pao2pawn_B_1che1ma2pawns
#define END_my_m_MT_R_1che1pao2pawn_B_1che1ma2pawns
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车1炮2兵对1车1马2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 
void my_m_MT_R_1che1pao2pawn_B_1che1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square mk = my_king_pos;
	Square yk = your_king_pos;
	Square mpao = S90_from_piecelist(POSITION,my_pao,0);


	// fen 2b1k4/4a4/4ba3/8p/P8/2p3P2/2n4r1/2R6/4AC3/2BAK4 b - - 0 1
	if ((my_shi_num + my_xiang_num) >= 3) {
		MY_EV_ADD(32);
		if (!have_bit(bb_your_pawn, MyLowBB[MY_RANK5])) {
			MY_EV_ADD(32);
			if (StoY(mk) == MY_RANK9) {
				MY_EV_ADD(32);
			}
			if (StoY(mpao) MY_LARGE_EQL MY_RANK7) {
				MY_EV_ADD(32);
			}
		}
	}

	// fen 4kab2/4a4/4b4/p8/3np3P/P5B2/4r4/6R2/4A4/3AKC3 b - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && EV_MY_CAN <= 1){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3]) && StoY(yk) == MY_RANK0){
			if(my_shi_num == 2 && my_xiang_num >= 1 && StoY(mk) == MY_RANK9){
				if(StoY(mpao) MY_LARGE_EQL MY_RANK7 && EV_YOUR_CAN <= 1){
					if(!have_bit(bb_your_pawn,MyLowBB[MY_RANK6])){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

}
#ifndef END_my_m_MT_R_1che1pao2ma3pawn_B_2che1ma2pawns
#define END_my_m_MT_R_1che1pao2ma3pawn_B_2che1ma2pawns
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"
#include "1车1炮2马3兵对2车1马2兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che1pao2ma3pawn_B_2che1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk   = your_king_pos;
	//Square mche = S90_from_piecelist(POSITION,my_che,0);

	// fen 3akab2/7r1/b5nC1/N3p2Rp/9/6r2/P3P3P/4N4/9/2BAKAB2 w - - 0 1
	if(your_shi_num == 2 && your_xiang_num == 2 && StoY(yk) == MY_RANK0){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){   // 
			// 车炮被牵
			MY_EV_SUB(32);
			//for(int i = 0; i < pos.piece_count(your_che); i++){
			// Square s =  pos.piece_list(your_che,i);
			// i
			//}
		}
	}
}
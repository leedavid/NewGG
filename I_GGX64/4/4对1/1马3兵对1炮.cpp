#ifndef END_my_m_MT_R_1ma3pawn_B_1pao
#define END_my_m_MT_R_1ma3pawn_B_1pao
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1马3兵对1炮.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//1马3兵对黑1炮
void my_m_MT_R_1ma3pawn_B_1pao(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;

	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);

	int pok = (int)count_1s(bmp);
	MY_EV_ADD(pok * ADD_1马兵对1炮_by_Pawn_By_Shi[your_shi_num]);

	Square ypao = S90_from_piecelist(POSITION,your_pao,0);

    //如果有窝心马在,就可能是和棋
	// fen 3aka3/4n4/b3b4/9/9/4C1B2/9/5p3/2p1K4/3p5 w - - 14 14
	if(pok <= 1 && your_xiang_num >= 1 && StoY(yk) != MY_RANK0){
		if(PB90(MY_SQ4C) == my_ma && PB90(MY_SQ54) == my_shi && PB90(MY_SQ56) == my_shi){
			if(PB90(MY_SQ43) == my_xiang && isStringByPao(POSITION,ypao,Square(MY_SQ4C),my_king_pos)){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 3ak1b2/9/4ba3/p7p/5Cp2/P1B6/2n6/3AB4/4A4/4K4 w - - 0 45
	if((your_xiang_num + your_shi_num) == 4 && EV_MY_CAN <= 1){
		RETRUN_MUL(8);
	}	

	// fen 4k4/2PP1P3/b2a1a3/4cN3/2b6/9/9/4BA3/9/3K1AB2 b - - 0 1
	if ((your_shi_num + your_xiang_num) == 4 && StoY(yk) == MY_RANK0){
		if (!have_bit(MyUpBB[MY_RANK2], bb_my_shi)){
			if (PB90(MY_SQ15) == your_shi && PB90(MY_SQ17) == your_shi){
				RETRUN_MUL(8);
			}
		}
	}
}

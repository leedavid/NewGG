#ifndef END_m_MT_R_1che1pao1ma2pawn_B_1che2pao1ma
#define END_m_MT_R_1che1pao1ma2pawn_B_1che2pao1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
#include "..\\..\\endgame\mat.h"
#include "1车1炮1马2兵对1车2炮1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int ADD_2CheXPawn_1Che3PaoMa1Pawn_2ChePawnCan      =  32;                     //2车方有兵可过河，


void my_m_MT_R_1che1pao1ma2pawn_B_1che2pao1ma(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	Square mma = S90_from_piecelist(POSITION,my_ma,0);

	// fen 4ka3/2n1a4/9/P3P4/2b2cR2/5r3/9/3N5/4A4/3CKABc1 w - - 0 1
    if(my_xiang_num <=1){
		MY_EV_SUB(32);
		if((your_shi_num + your_xiang_num) >= 3){
			if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK3])){
				MY_EV_SUB(32);
			}
			// 如果有边兵
		    Bitboard sidepanw = m_and(bb_my_pawn,m_or(FileBB_A[0x0],FileBB_A[0x8]));
			MY_EV_SUB((sint16)count_1s(sidepanw) * 32);
		}
	}

	// fen 2bakn3/2n1a2c1/9/8R/2r6/C1N6/P3P4/4B4/9/2BAKA3 w - - 0 1
	if((your_shi_num + your_xiang_num) >= 3 && StoY(yk) == MY_RANK0){
		if(!have_bit(bb_my_pawn,MyUpBB[MY_RANK5])){
			MY_EV_SUB(32);
		}
		if(StoY(mma) MY_LARGE_EQL MY_RANK4){
			MY_EV_SUB(16);
		}
	}
}

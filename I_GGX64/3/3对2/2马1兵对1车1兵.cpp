#ifndef END_my_m_MT_R_2ma1pawn_B_1che1pawn
#define END_my_m_MT_R_2ma1pawn_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2马1兵对1车1兵.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



//Add_MAT_B_1ma1pao1pawn_R_1che1pawn_ByShi

// 红方马炮兵,黑方车兵
void my_m_MT_R_2ma1pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * Add_MAT_B_2ma1pawn_R_1che1pawn_ByShi[your_shi_num]);
	// SUB
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * Add_MAT_B_1che1pawn_R_2ma1pawn_ByShi[my_shi_num]);

	//如果黑方的兵不能过河,要减分
	//if((board->R_shi + board->R_xiang) >= 3){
	//	//if(bcan == 0){
	//	//	board->mulScore += Add_2ma1pawn_1che1pawn_chePawnCan0;
	//	//}
	//}
	int ycan = EV_YOUR_CAN;
	int mcan = EV_MY_CAN;

	if(ycan == 0){
		MY_EV_ADD(mcan * Add_2ma1pawn_1che1pawn_MaPawnCan);
	}

	// fen 4k4/9/3aba3/8p/6b2/6N1P/7r1/7N1/4AK3/3A5 b - - 121 121
	if(my_shi_num == 2 && StoY(my_king_pos) MY_LARGE_EQL MY_RANK8){
		if(PB90(MY_SQ23) == your_pawn && PB90(MY_SQ35) == my_pawn){
			if(PB90(MY_SQ33) == my_ma && PB90(MY_SQ46) == my_ma){
				RETRUN_MUL(4);
			}
		}
		if(PB90(MY_SQ1B) == your_pawn && PB90(MY_SQ2D) == my_pawn){
			if(PB90(MY_SQ2F) == my_ma && PB90(MY_SQ40) == my_ma){
				RETRUN_MUL(4);
			}
		}
	}
}


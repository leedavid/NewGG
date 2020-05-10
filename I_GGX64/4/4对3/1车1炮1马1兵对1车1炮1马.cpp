#ifndef END_my_m_MT_R_1che1pao1ma1pawn_B_1che1pao1ma
#define END_my_m_MT_R_1che1pao1ma1pawn_B_1che1pao1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1车1炮1马1兵对1车1炮1马.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che1pao1ma1pawn_B_1che1pao1ma(typePOS &POSITION, EvalInfo &ei){

	// ADD_MY
	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * ADD_1che1pao1ma1pawn_1che1pao1ma_ByShi[your_shi_num]);

	// fen 2bakc3/4a4/4b4/9/7r1/2P6/1C2PR2P/4B4/1nN1A4/4K4 b - - 0 1
	if((my_shi_num + my_xiang_num) >= 2 && StoY(mk) == MY_RANK9){
		MY_EV_ADD(EV_MY_CAN * 16);
	}

}


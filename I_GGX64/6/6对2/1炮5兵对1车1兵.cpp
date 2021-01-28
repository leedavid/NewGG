#ifndef END_my_m_MT_R_1pao5pawn_B_1che1pawn
#define END_my_m_MT_R_1pao5pawn_B_1che1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮5兵对1车1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//1炮2兵对1车1兵, 炮马方要加分

void my_m_MT_R_1pao5pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	if((my_shi_num + my_xiang_num) == 4 && PB90(MY_SQ55) == my_king){
		EV_MY_SAFE = TRUE;
	}

	if(EV_MY_SAFE){
		// ADD
		Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
		MY_EV_ADD((sint16)count_1s(bmp) * ADD_PaoXPawn_To_ChePawnByShi_WpaoSafe[your_shi_num]);
	}

	// fen 3ak1b2/4a4/4b4/rC4p1P/9/6P2/P3P4/8B/9/3AKA3 w - - 16 16
	if(my_shi_num == 2 && my_xiang_num >= 1 && PB90(MY_SQ55) == my_king){
		Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
		Square yche  = S90_from_piecelist(POSITION,your_che,0);
		if(StoY(ypawn) == MY_RANK3 && StoY(yche) MY_SMALL_EQL MY_RANK4){
			RETRUN_MUL(4);
		}
	}
}


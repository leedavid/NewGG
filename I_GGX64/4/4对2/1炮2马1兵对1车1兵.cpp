#ifndef END_my_m_MT_R_1pao_2ma1pawn_B_1che1pawn
#define END_my_m_MT_R_1pao_2ma1pawn_B_1che1pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "1炮2马1兵对1车1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//1炮2马1兵对1车, 炮马方要加分

void my_m_MT_R_1pao_2ma1pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	if(StoY(ypawn) MY_SMALL_EQL MY_RANK4 || my_shi_num == 2){
		MY_EV_ADD(Add_1炮2马对1车1兵);
	}

	// fen 3k2b2/2N1a4/4b4/1N7/9/2B2p3/9/4C3r/9/4KA3 w - - 0 1
	if(my_shi_num <= 1 && my_xiang_num <= 1){
		MY_EV_SUB(EV_YOUR_CAN * 64);
	}

	// fen 4k4/4a4/1N3a3/1N7/3C5/2B6/4p4/9/4K4/3r5 b - - 0 1
	if(StoY(ypawn) MY_SMALL_EQL MY_RANK6 && (my_shi_num >= 1 || my_xiang_num >= 1)){
		if((your_shi_num + your_xiang_num) <= 2){
			MY_EV_ADD(96);
			if(your_xiang_num == 0){
				MY_EV_ADD(32);
			}
		}
	}

	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * Add_1炮2马对1车1兵_byPawn_Shi[my_shi_num]);
}


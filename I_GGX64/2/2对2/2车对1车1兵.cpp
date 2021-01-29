#ifndef END_my_m_MT_R_2CHE_B_1CHE1PAWN
#define END_my_m_MT_R_2CHE_B_1CHE1PAWN
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "2车对1车1兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 
//我方2车，对方一车一兵
void my_m_MT_R_2CHE_B_1CHE1PAWN(typePOS &POSITION, EvalInfo &ei){

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	if(StoY(my_king_pos) == MY_RANK9 && MY_SQ4C == ypawn){

	}
	else{
		my_m_MT_R_2CHE_B_1CHE(POSITION,ei);
	}
}

//我方2车，对方一车一兵
//void m_MT_B_2CHE_R_1CHE1PAWN(typePOS &POSITION, EvalInfo &ei){
///*
//
//	Square rpawn = PieceListStart(board,RPAWN);
//
//	if(rpawn != 0x47){
//		return m_MT_B_2CHE_R_1CHE(board);
//	}
//
//	*/
//}
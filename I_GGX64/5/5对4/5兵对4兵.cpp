#ifndef END_my_m_MT_R_5pawn_B_4pawn
#define END_my_m_MT_R_5pawn_B_4pawn
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"
#include "5兵对4兵.cpp"
#include "../../white.h"
#else
#include "../../black.h"
#endif 


//5兵对1兵
void my_m_MT_R_5pawn_B_4pawn(typePOS &POSITION, EvalInfo &ei){
	BothOnlyPawnEval(POSITION,ei);


}

////5兵对1兵
//void m_MT_B_5pawn_R_4pawn(typePOS &POSITION, EvalInfo &ei){
//	//BothOnlyPawnEval(board);
//
//}
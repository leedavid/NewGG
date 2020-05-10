#ifndef END_my_m_MT_R_4pawn_B_1pawn
#define END_my_m_MT_R_4pawn_B_1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "4條勤1條.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//4條勤1條
void my_m_MT_R_4pawn_B_1pawn(typePOS &POSITION, EvalInfo &ei){
	BothOnlyPawnEval(POSITION,ei);
}

//4條勤1條
//void m_MT_B_4pawn_R_1pawn(typePOS &POSITION, EvalInfo &ei){
//	//BothOnlyPawnEval(board);
//	
//	//return 16;
//}
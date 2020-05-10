#ifndef END_my_m_MT_R_5pawn_B_1pawn
#define END_my_m_MT_R_5pawn_B_1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "5條勤1條.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 
//5條勤1條
void my_m_MT_R_5pawn_B_1pawn(typePOS &POSITION, EvalInfo &ei){
	
	BothOnlyPawnEval(POSITION,ei);

}
//
////5條勤1條
//void m_MT_B_5pawn_R_1pawn(typePOS &POSITION, EvalInfo &ei){
//	//BothOnlyPawnEval(board);
//
//}
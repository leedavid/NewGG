#ifndef END_my_m_MT_R_4pawn
#define END_my_m_MT_R_4pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "4兵对无.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//我方3兵，对方 0 attacker
void my_m_MT_R_4pawn(typePOS &POSITION, EvalInfo &ei){
	BothOnlyPawnEval(POSITION,ei);
}

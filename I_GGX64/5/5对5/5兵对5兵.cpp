
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"



//5兵对1兵
void m_MT_5pawn_TO_5pawn(typePOS &POSITION, EvalInfo &ei){
	BothOnlyPawnEval(POSITION,ei);
}


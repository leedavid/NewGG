
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"


// fen 3k1a3/9/5a3/p1nN4p/4p4/9/P3P3P/4B4/4A4/4KAB2 b - - 7 7
void m_MT_BR_1ma3pawn(typePOS &POSITION, EvalInfo &ei){

	int rcan = ei.rcan;
	int bcan = ei.bcan;

	if(RShi_num() == 2 && BShi_num() == 2){
		if(rcan == 0 && bcan == 0){
			RETRUN_MUL(2);
		}
	}
}
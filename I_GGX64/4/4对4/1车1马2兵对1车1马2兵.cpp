#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"

void m_MT_BR_1che1ma2pawn(typePOS &POSITION, EvalInfo &ei){

	Square rk = RKpos();
	Square bk = BKpos();
	
	// fen 4k1b2/4a4/3nb4/p6rp/5R3/4N3P/P8/4B4/4A4/2B1KA3 w - - 0 1
	if(RShi_num() == 2 && RXiang_num() == 2 && StoY(rk) > 0x8){
		if(ei.bcan == 0){
			if(BShi_num() >= 1 && BXiang_num() >= 2 && StoY(bk) == 0x0 && ei.rcan == 0){
                RETRUN_MUL(8);
			}
		}
	}
	if(BShi_num() == 2 && BXiang_num() == 2 && StoY(bk) < 0x1){
		if(ei.rcan == 0){
			if(RShi_num() >= 1 && RXiang_num() >= 2 && StoY(rk) == 0x9 && ei.bcan == 0){
				RETRUN_MUL(8);
			}
		}
	}
}



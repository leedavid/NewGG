
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"



void m_MT_BR_1pao1ma_B_1pao1ma(typePOS &POSITION, EvalInfo &ei){

	Square rk = RKpos();
	Square bk = BKpos();
	Square bpao = S90_from_piecelist(POSITION,BPAO,0);
	Square rpao = S90_from_piecelist(POSITION,RPAO,0);
	Square bma  = S90_from_piecelist(POSITION,BMA,0);
	Square rma  = S90_from_piecelist(POSITION,RMA,0);
	// fen 4k4/9/9/9/2b3b2/4Cc3/4Nn3/3AB4/4A4/2B1K4 w - - 0 97
	if((RShi_num() + RXiang_num()) >= 2 && (BShi_num() + BXiang_num()) >= 2){
		RETRUN_MUL(4);
	}
	// fen 3k5/5c3/4bN3/9/9/4C1B2/1n7/3AB4/4A4/3K5 b - - 0 1
	if((RShi_num() + RXiang_num()) >= 2){
		if(BXiang_num() >= 1 && StoY(bk) <= 1 && StoY(bpao) <= 3){
			RETRUN_MUL(4);
		}
	}
	if((BShi_num() + BXiang_num()) >= 2){
		if(RXiang_num() >= 1 && StoY(rk) >= 8 && StoY(rpao) >= 6){
			RETRUN_MUL(4);
		}
	}

	// fen 9/4k4/c2N5/9/9/3n2B2/9/B8/4A4/3K1C3 w - - 0 1
	if(!bit_is_set(ei.xray_bit[WHITE],bma) && StoY(bpao) <= 2){
		if((RShi_num() + RXiang_num()) >= 1 && StoY(rk) >= 8){
			RETRUN_MUL(6);
		}
	}
	if(!bit_is_set(ei.xray_bit[BLACK],rma) && StoY(rpao) >= 7){
		if((BShi_num() + BXiang_num()) >= 1 && StoY(bk) <= 1){
			RETRUN_MUL(6);
		}
	}

	RETRUN_MUL(8);
}
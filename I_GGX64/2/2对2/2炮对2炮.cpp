
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"


// fen 4k4/4a4/3ab4/3C5/2b6/9/9/4C4/2c1AK3/c8 w - - 210 210

void m_MT_R_2pao_B_2pao(typePOS &POSITION, EvalInfo &ei){

    Square rk = RKpos();
	Square bk = BKpos();

	if((RShi_num() + RXiang_num()) >= 2){
		ei.rsafe = TRUE;
	} 
	if((BShi_num() + BXiang_num()) >= 2){
		ei.bsafe = TRUE;
	} 

	if((RShi_num() + RXiang_num()) >= 1 && (BShi_num() + BXiang_num()) >= 1){
		RETRUN_MUL(2);
	}

	if((RShi_num() + RXiang_num()) == 0 && (BShi_num() + BXiang_num()) == 0){
		RETRUN_MUL(2);
	}


	// fen 2C2k3/9/9/1c7/9/2B6/3C5/3AB4/3KA4/c8 b - - 0 1
	if(ei.rsafe){
		if(StoY(bk) <= 1){
			RETRUN_MUL(4);
		}
	}
	if(ei.bsafe){
		if(StoY(rk) >= 8){
			RETRUN_MUL(4);
		}
	}

	//return 16;
}
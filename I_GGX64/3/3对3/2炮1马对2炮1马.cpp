
#include "../../chess.h"
#include "../../preGen.h"


void m_MT_BR_2pao1ma_B_2pao1ma(typePOS &POSITION, EvalInfo &ei){

	Square rk = RKpos();
	Square bk = BKpos();

	// fen 1Cbak4/4ac3/4c1N2/9/9/9/1n2C4/4B4/4A4/2BAK4 w - - 0 1
	if((RShi_num() + RXiang_num()) >= 3 && (BShi_num() + BXiang_num()) >= 3){
		if(StoY(rk) == 0x9 && StoY(bk) == 0x0){
			RETRUN_MUL(8);
		}
	}
}
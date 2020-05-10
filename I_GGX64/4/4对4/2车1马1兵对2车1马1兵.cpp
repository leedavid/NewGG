
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"

void m_MT_BR_2che1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	Square bk = BKpos();
	Square rk = RKpos();

	Square bma = S90_from_piecelist(POSITION,BMA,0);
	Square rma = S90_from_piecelist(POSITION,RMA,0);
	
   // fen 3ak1b2/4a4/9/1n4r1p/4r4/3R4P/7R1/3NB4/4A4/2B1KA3 b - - 0 1
   if(BShi_num() == 2 && BXiang_num() >= 1 && StoY(bk) == 0x0){
	   if(ei.rcan == 0 && StoY(rma) >= 0x5){
		   if(RShi_num() == 2 && RXiang_num() >= 1 && StoY(rk) == 0x9){
			   if(ei.bcan == 0 && StoY(bma) <= 0x4){
				   RETRUN_MUL(10);
			   }
		   }
	   }
   }
}

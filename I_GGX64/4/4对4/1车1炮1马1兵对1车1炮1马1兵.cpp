
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"


void m_MT_BR_1che1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	int rcan = ei.rcan;
	int bcan = ei.bcan;

	Square bk = BKpos();
	Square rk = RKpos();

	int rche = S90_from_piecelist(POSITION,RCHE,0);
	int bche = S90_from_piecelist(POSITION,BCHE,0);
	
	// fen Nnb1k4/1Cr1a4/3abc3/p8/9/P8/9/4B4/1R7/2BAKA3 w - - 29 29
	if((BShi_num() + BXiang_num()) == 4 && StoY(bk) == 0x0){
		if(rcan == 0){
			if(PB90(0x00) == RMA && PB90(0x01) == BMA){
				if(PB90(0x0A) == RPAO && PB90(0x0B) == BCHE){
					if(StoX(rche) == 0x1){
						ei.evscore -= 128;
					}
				}
			}
			if(PB90(0x08) == RMA && PB90(0x07) == BMA){
				if(PB90(0x10) == RPAO && PB90(0x0F) == BCHE){
					if(StoX(rche) == 0x7){
						ei.evscore -= 128;
					}
				}
			}
		}
	}

	if((RShi_num() + RXiang_num()) == 4 && StoY(rk) == 0x9){
		if(bcan == 0){
			if(PB90(0x51) == BMA && PB90(0x52) == RMA){
				if(PB90(0x49) == BPAO && PB90(0x4A) == RCHE){
					if(StoX(bche) == 0x1){
						ei.evscore += 128;
					}
				}
			}
			if(PB90(0x59) == BMA && PB90(0x58) == RMA){
				if(PB90(0x4F) == BPAO && PB90(0x4E) == RCHE){
					if(StoX(bche) == 0x7){
						ei.evscore += 128;
					}
				}
			}
		}
	}
}
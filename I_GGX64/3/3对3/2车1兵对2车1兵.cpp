#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"


void m_MT_R_B_2che1pawn(typePOS &POSITION, EvalInfo &ei){

	// fen 3ak1b2/4a4/4b4/9/5r3/3R4P/8r/4R4/4A4/1p2KA3 b - - 120 120

	// ADD_BR
	Square bk = BKpos();
	Bitboard bmp = m_and(bb_white_pawn,LowBB[StoY(bk)]);
	ei.evscore += (count_1s(bmp) * ADD_2CheXPawn_2Che1Pawn_ByShi[BShi_num()]);
	// SUB
	Square rk = RKpos();
	Bitboard ymp = m_and(bb_black_pawn,UpBB[StoY(rk)]);
	ei.evscore -= (count_1s(ymp) * ADD_2CheXPawn_2Che1Pawn_ByShi[RShi_num()]);	

	int  rpawn = S90_from_piecelist(POSITION,RPAWN,0);
	int  bpawn = S90_from_piecelist(POSITION,BPAWN,0);



	//ºì·½°²È«
	if(PB90(0x55) == RKING){
		if(RShi_num() == 2 && RXiang_num() == 2){
			if(StoY(bpawn) <= 0x6){
				ei.rsafe = TRUE;
			}
		}
		if(RShi_num() == 2){
			if(StoY(bpawn) == 0x9){
				if(abs(StoX(bpawn) - 0x4) > 0x2){
					ei.rsafe = TRUE;
				}
			}
		}
	}
	if(PB90(0x04) == BKING){
		if(BShi_num() == 2 && BXiang_num() == 2){
			if(StoY(rpawn) >= 0x3){
				ei.bsafe = TRUE;
			}
		}
		if(BShi_num() == 2){
			if(StoY(rpawn) == 0x0){
				if(abs(StoX(rpawn) - 0x4) > 0x2){
					ei.bsafe = TRUE;
				}
			}
		}
	}
	

	// fen 3akr2R/4a4/R8/4p4/9/7r1/P8/4B4/9/2BAKA3 w - - 3 3
	if(ei.rsafe){
		if(BShi_num() == 2 && PB90(0x04) == BKING){
			RETRUN_MUL(4);
		}
	}
	// fen 3akr2R/4a4/R8/4p4/9/7r1/P8/4B4/9/2BAKA3 w - - 3 3
	if(ei.bsafe){
		if(RShi_num() == 2 && PB90(0x55) == RKING){
			RETRUN_MUL(4);
		}
	}

	//  fen 4ka3/4a4/4b2r1/5RP1p/4R4/8r/9/4B4/4A4/3AK4 w - - 0 1
	if (RShi_num() == 2 && PB90(0x55) == RKING && RXiang_num() >= 1) {
		if (StoY(bpawn) <= 0x6) {
			if (BShi_num() == 2 && PB90(0x04) == BKING && BXiang_num() >= 1) {
				if (StoY(rpawn) >= 0x3) {
					RETRUN_MUL(8);
				}
			}
		}
	}

}
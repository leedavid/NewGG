
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"

const sint16 LackShiAdd[3] = {128,48,0};

//大家两个车， 少仕的一方差
void m_MT_2che_2che(typePOS &POSITION, EvalInfo &ei){

	Square rk = RKpos();
	Square bk = BKpos();

	ei.evscore += LackShiAdd[BShi_num()];
	ei.evscore -= LackShiAdd[RShi_num()];

	int rche1 = S90_from_piecelist(POSITION,RCHE,0);
	int rche2 = S90_from_piecelist(POSITION,RCHE,1);
	int bche1 = S90_from_piecelist(POSITION,BCHE,0);
	int bche2 = S90_from_piecelist(POSITION,BCHE,1);

	// fen 4ka3/4a4/4b4/2r6/2b6/4R1R2/4r4/4B4/9/2B1KA3 b - - 48 48
	if(RShi_num() >= 1 && RXiang_num() == 2 && 0x55 == rk){
		if(StoY(rche1) == StoY(rche2)){
			ei.rsafe = TRUE;
		}
	}
	if(BShi_num() >= 1 && BXiang_num() == 2 && 0x04 == bk){
		if(StoY(bche1) == StoY(bche2)){
			ei.bsafe = TRUE;
		}
	}
	
	if(BShi_num() == 2 && BXiang_num() == 2 && StoY(bk) == 0x0){
		ei.bsafe = TRUE;
	}
	if(RShi_num() == 2 && RXiang_num() == 2 && StoY(rk) == 0x9){
		ei.rsafe = TRUE;
	}

	// fen 2b1kab2/4a4/9/9/9/9/8r/5R3/4AK1R1/3A2r2 w - - 25 25
	if(RShi_num() == 2 && StoY(rk) >= 0x8){
        Bitboard ceat = POSITION.Rook_attacks_bb(rk);
		ceat = m_and(ceat,m_or(bb_white_che,bb_white_shi));

		if(count_1s(ceat) == 3){
			ei.rsafe = TRUE;
		}
	}
	if(BShi_num() == 2 && StoY(bk) <= 0x1){
		Bitboard ceat = POSITION.Rook_attacks_bb(bk);
		ceat = m_and(ceat,m_or(bb_black_che,bb_black_shi));

		if(count_1s(ceat) == 3){
			ei.bsafe = TRUE;
		}
	}

	// fen 4ka3/4a4/4R4/2r5r/9/9/4R4/9/4A4/3AK1B2 b - - 0 1
	if((RShi_num() == 2 && rk == 0x55) || ei.rsafe){
		if((BShi_num() == 2 && bk == 0x4) || ei.bsafe){
			RETRUN_MUL(4);
		}
	}
}


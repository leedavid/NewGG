#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"


void m_MT_BR_1pao1ma2pawn(typePOS &POSITION, EvalInfo &ei){
	
	// ADD
	Bitboard bmp = m_and(bb_white_pawn,LowBB[StoY(BKpos())]);
	ei.evscore += (count_1s(bmp) * ADD_1Pao1Ma2Pawn_To_1Pao1MaxPawn[BShi_num()]);
	// SUB
	Bitboard ymp = m_and(bb_black_pawn,UpBB[StoY(RKpos())]);
	ei.evscore -= (count_1s(ymp) * ADD_1Pao1Ma2Pawn_To_1Pao1MaxPawn[RShi_num()]);

	int rcan = ei.rcan;
	int bcan = ei.bcan;

	if(rcan == 0){
		ei.evscore -= (bcan * 32);
	}
	if(bcan == 0){
		ei.evscore += (rcan * 32);
	}

	Square bk = BKpos();
	Square rk = RKpos();

	// fen 3ak4/4a4/b8/9/p1b6/2B1P4/P4n3/3A1C3/4Ap3/1cBNK4 b - - 0 1
	if(BShi_num() == 2 && BXiang_num() == 2 && StoY(bk) <= 1){
		if(ei.rcan <= 1 && !have_bit(bb_white_pawn,UpBB[0x4])){
			ei.bsafe = true;
		}
	}
	if(RShi_num() == 2 && RXiang_num() == 2 && StoY(rk) >= 8){
		if(ei.bcan <= 1 && !have_bit(bb_black_pawn,LowBB[0x5])){
			ei.rsafe = true;
		}
	}

	// fen 3ak4/4a4/b8/9/p1b6/2B1P4/P4n3/3A1C3/4Ap3/1cBNK4 b - - 0 1
	if(ei.bsafe){
		if(ei.bcan <= 1){
			if(RShi_num() == 2 && RXiang_num() == 2 && StoY(rk) >= 8){
				RETRUN_MUL(8);
			}
		}
	}
	if(ei.rsafe){
		if(ei.rcan <= 1){
			if(BShi_num() == 2 && BXiang_num() == 2 && StoY(bk) <= 1){
				RETRUN_MUL(8);
			}
		}
	}
}
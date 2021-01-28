#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"

//ADD_1PaoXPawn_1PaoXPawn_ByShi

void m_MT_BR_1pao2pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Bitboard bmp = m_and(bb_white_pawn,LowBB[StoY(BKpos())]);
	ei.evscore += (count_1s(bmp) * ADD_1PaoXPawn_1PaoXPawn_ByShi[BShi_num()]);
	// SUB
	Bitboard ymp = m_and(bb_black_pawn,UpBB[StoY(RKpos())]);
	ei.evscore -= (count_1s(ymp) * ADD_1PaoXPawn_1PaoXPawn_ByShi[RShi_num()]);

	Square rk = RKpos();
	Square bk = BKpos();

	int rcan = ei.rcan;
	int bcan = ei.bcan;
	
	ei.evscore += rcan * 64;
	ei.evscore -= bcan * 64;

	// fen 2ba1k3/3P5/3a5/4P4/9/9/4c4/9/1C2Ap3/2p1K4 w - - 0 1
	if(have_bit(bb_black_pawn,RankBB_A[0x9])){
		ei.evscore += (64 * rcan);
	}
	if(have_bit(bb_white_pawn,RankBB_A[0x0])){
		ei.evscore -= (64 * bcan);
	}

	// fen 6P2/5k3/9/6P2/9/2B6/C4c3/3A5/2p1K1p2/6B2 w - - 0 1
	if (BShi_num() == 0 && BXiang_num() == 0 && RShi_num() >= 1) {
		if (have_bit(bb_white_pawn, LowBB[0x2])) {
			ei.evscore += 32 * rcan;

			if (StoY(rk) <= 0x8) {
				if (!have_bit(bb_black_pawn, UpBB[0x8])) {
					ei.evscore += 32 * rcan;
				}
			}
		}
	}

	if (RShi_num() == 0 && RXiang_num() == 0 && BShi_num() >= 1) {
		if (have_bit(bb_black_pawn, UpBB[0x7])) {
			ei.evscore -= 32 * bcan;

			if (StoY(bk) >= 0x1) {
				if (!have_bit(bb_white_pawn, LowBB[0x1])) {
					ei.evscore -= 32 * bcan;
				}
			}
		}
	}

	// fen 3akab2/9/9/4PP3/2b6/4c1B2/9/3AB4/3p1p3/4K2C1 w - - 125 125
	if(rcan == 2 && bcan == 2){
		if(BShi_num() >= 1 && BXiang_num() == 2 
			&& RShi_num() >= 1 && RXiang_num() == 2){
				RETRUN_MUL(8);
		}
	} 

	// fen 3akab2/3c5/9/C4P3/4p3p/9/4P4/4B4/4A4/4KAB2 w - - 0 1
	if(rcan == 1 && bcan == 1){
		if((RShi_num() + RXiang_num()) >= 3 && (BShi_num() + BXiang_num()) >= 3){
				RETRUN_MUL(8);
		}
	} 
	// fen 2bak4/2C1aP3/1P7/9/9/2p6/3c1p3/4B4/4A4/4KAB2 b - - 0 1
	if(rcan == 2 && bcan == 2){
		if((BShi_num() + BXiang_num()) >= 3 && (RShi_num() + RXiang_num()) >= 3){
			RETRUN_MUL(12);
		} 
	}
}
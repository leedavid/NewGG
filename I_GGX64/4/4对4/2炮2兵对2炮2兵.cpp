#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"

void m_MT_BR_2pao2pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Bitboard bmp = m_and(bb_white_pawn,LowBB[StoY(BKpos())]);
	ei.evscore += sint16(count_1s(bmp) * ADD_2Pao2Pawn_To_2PaoxPawn_ByPawn[BShi_num()]);
	// SUB
	Bitboard ymp = m_and(bb_black_pawn,UpBB[StoY(RKpos())]);
	ei.evscore -= sint16(count_1s(ymp) * ADD_2Pao2Pawn_To_2PaoxPawn_ByPawn[RShi_num()]);

	int rcan = ei.rcan;
	int bcan = ei.bcan;

	if(rcan == 0){
		ei.evscore -= sint16(bcan * 64);
	}
	if(bcan == 0){
		ei.evscore += sint16(rcan * 64);
	}

	//
	int rgh = count_1s(bb_white_pawn, UpBB[0x5]);
	int bgh = count_1s(bb_black_pawn, LowBB[0x4]);

	// fen 2ba1k3/3Pa1C2/4b4/9/4c4/P6p1/3p5/2C1B4/4A4/2BAK3c w - - 0 1
	if (rgh >= 2 && rcan >= 2) {
		ei.evscore += sint16(rcan * 32);
	}
	if (bgh >= 2 && bcan >= 2) {
		ei.evscore -= sint16(bcan * 32);
	}
}
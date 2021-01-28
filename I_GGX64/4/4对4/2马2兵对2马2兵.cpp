
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"


void m_MT_BR_2ma2pawn(typePOS &POSITION, EvalInfo &ei){
	
	// ADD
	Bitboard bmp = m_and(bb_white_pawn,LowBB[StoY(BKpos())]);
	ei.evscore += (count_1s(bmp) * ADD_2Ma2Pawn_To_2MaXPawn_ByPawn[BShi_num()]);
	// SUB
	Bitboard ymp = m_and(bb_black_pawn,UpBB[StoY(RKpos())]);
	ei.evscore -= (count_1s(ymp) * ADD_2Ma2Pawn_To_2MaXPawn_ByPawn[RShi_num()]);

	int rcan = ei.rcan;
	int bcan = ei.bcan;

	Square rk = RKpos();
	Square bk = BKpos();

	if(rcan == 0){
		ei.evscore -= (bcan * 64);
	}
	if(bcan == 0){
		ei.evscore += (rcan * 64);
	}

	// fen 2ba1k3/4a4/4b4/p2n4p/9/9/P2n4P/6N2/5N3/2BAKAB2 w - - 0 1
	if((RShi_num() + RXiang_num()) >= 3 && (BShi_num() + BXiang_num()) >= 3){
		if(ei.rcan == 0 && ei.bcan == 0 ){
			if(StoY(rk) >= 0x8 && StoY(bk) <= 0x1){
			     RETRUN_MUL(8);
			}
		}
	}

	// fen 3aka3/N8/b3b4/4p4/1n1P1n2p/5N3/8P/3ABA3/9/4K1B2 b - - 0 1
	if((RShi_num() + RXiang_num()) == 4 && (BShi_num() + BXiang_num()) == 4){
		if(ei.rcan <= 1 && ei.bcan <= 1){
			RETRUN_MUL(8);
		}
	}
}
#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"


//const int ADD_2Pao1MaXpawn_To_2Pao1Ma1Pawn_ByPawn[3]     = { 96, 64, 32};   //
//const int ADD_2Pao1Ma1pawn_To_2Pao1MaXPawn_ByPawn[3]     = { 96, 64, 32};   //

void m_MT_BR_2pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Bitboard bmp = m_and(bb_white_pawn,LowBB[StoY(BKpos())]);
	ei.evscore += (count_1s(bmp) * ADD_2Pao1MaXpawn_To_2Pao1Ma1Pawn_ByPawn[BShi_num()]);
	// SUB
	Bitboard ymp = m_and(bb_black_pawn,UpBB[StoY(RKpos())]);
	ei.evscore -= (count_1s(ymp) * ADD_2Pao1MaXpawn_To_2Pao1Ma1Pawn_ByPawn[RShi_num()]);


	// fen C1ba1k3/4a1P2/4b4/3n4p/3N1c3/9/4Cc3/4BA3/4A4/2B1K4 w - - 0 0
	//这个要降一些分
	int  rcan = ei.rcan;
	int  bcan = ei.bcan;
	if(rcan > 0 && bcan > 0){
		if(RShi_num() == 2 && RXiang_num() == 2 && StoY(RKpos()) == 0X9){
			if(BShi_num() == 2 && BXiang_num() == 2 && StoY(BKpos()) == 0X0){
				RETRUN_MUL(12);
			}
		}
	}
}


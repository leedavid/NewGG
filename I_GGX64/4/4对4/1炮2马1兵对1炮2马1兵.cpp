#include "../../chess.h"
#include "../../preGen.h"
 
#include "../../endgame/mat.h"


//const int ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[3]     = { 96, 64, 32};   //
//const int ADD_1Pao2Ma1pawn_To_1Pao2MaXPawn_ByPawn[3]     = { 96, 64, 32};   //

void m_MT_BR_1pao2ma1pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Bitboard bmp = m_and(bb_white_pawn,LowBB[StoY(BKpos())]);
	ei.evscore += (count_1s(bmp) * ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[BShi_num()]);
	// SUB
	Bitboard ymp = m_and(bb_black_pawn,UpBB[StoY(RKpos())]);
	ei.evscore -= (count_1s(ymp) * ADD_1Pao2MaXpawn_To_1Pao2Ma1Pawn_ByPawn[RShi_num()]);
}

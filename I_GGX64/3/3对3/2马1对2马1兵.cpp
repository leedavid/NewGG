#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"


//
//const int  ADD_2MaXPawn_2Pao1Pawn_ByPawn[3]         = {96, 64, 32};            //2马x兵对1炮2兵, 多兵的加分
//const int  ADD_2Pao1Pawn_2MaXPawn_ByPawn[3]         = {96, 64, 32};            //1炮2兵对2马x兵, 多兵的加分



void m_MT_BR_2ma1pawn(typePOS &POSITION, EvalInfo &ei){
	
	// ADD
	Bitboard bmp = m_and(bb_white_pawn,LowBB[StoY(BKpos())]);
	ei.evscore += (count_1s(bmp) * ADD_2Ma1Pawn_2MaXPawn_ByPawn[BShi_num()]);
	// SUB
	Bitboard ymp = m_and(bb_black_pawn,UpBB[StoY(RKpos())]);
	ei.evscore -= (count_1s(ymp) * ADD_2Ma1Pawn_2MaXPawn_ByPawn[RShi_num()]);

	Square rk = RKpos();
	Square bk = BKpos();

	Square rpawn = S90_from_piecelist(POSITION,RPAWN,0);
	Square bpawn = S90_from_piecelist(POSITION,BPAWN,0);

	// fen 4k4/4a4/8b/9/P4N3/3Nn3n/9/3pB4/4K4/2BA1A3 w - - 0 1
	if(RShi_num() == 2 && RXiang_num() == 2 && StoY(rk) >= 8){
		if((BShi_num() + BXiang_num()) >= 2 && StoY(rpawn) >= 0x3){
			RETRUN_MUL(8);
		}
		// fen 2b1ka3/4a1P2/2Nn5/9/3Nn4/1p7/9/4B4/4A4/2BA1K3 b - - 0 1
		if((BShi_num() + BXiang_num()) >= 3 && abs(StoX(rpawn) - StoX(bk)) >= 0x2){
			RETRUN_MUL(8);
		}
	}
	if(BShi_num() == 2 && BXiang_num() == 2 && StoY(bk) <= 1){
		if((RShi_num() + RXiang_num()) >= 2 && StoY(bpawn) <= 0x6){
			RETRUN_MUL(8);
		}

		if((RShi_num() + RXiang_num()) >= 3 && abs(StoX(bpawn) - StoX(rk)) >= 0x2){
			RETRUN_MUL(8);
		}
	}
}
#include "../../chess.h"
#include "../../preGen.h"
//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void BR_1che2pao1ma3pawn(typePOS &POSITION, EvalInfo &ei){

	Square rk = RKpos();
	Square rche = S90_from_piecelist(POSITION,RCHE,0);

	Square bk = BKpos();
	Square bche = S90_from_piecelist(POSITION,BCHE,0);

	// fen 4ka3/4a4/4b4/p3p1P2/2pn5/1c5r1/P1P1c4/3AC3B/2N1A4/1RB1K1C2 w - - 0 1
	if(ei.rcan <= 1){
		if(StoY(bk) == 0x0 && (BShi_num() + BXiang_num()) >= 3){
			if(!have_bit(UpBB[0x5],m_or(bb_white_pao,bb_white_ma))){
				if(StoY(rche) >= 0x7){
					ei.evscore -= 32;
				}
			}
		}
	}
	// fen 4ka3/4a4/4b4/p3p1P2/2pn5/1c5r1/P1P1c4/3AC3B/2N1A4/1RB1K1C2 w - - 0 1
	if(ei.bcan <= 1){
		if(StoY(rk) == 0x9 && (RShi_num() + RXiang_num()) >= 3){
			if(!have_bit(LowBB[0x4],m_or(bb_black_pao,bb_black_ma))){
				if(StoY(bche) <= 0x2){
					ei.evscore += 32;
				}
			}
		}
	}
}
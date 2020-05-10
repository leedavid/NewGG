#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"



void m_MT_BR_1che1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD
	Square bk = BKpos();
	Bitboard bmp = m_and(bb_white_pawn,LowBB[StoY(bk)]);
	ei.evscore += (count_1s(bmp) * ADD_ChePaoPawn_ChePao1pawn_ByPawnByShi[BShi_num()]);
	// SUB
	Square rk = RKpos();
	Bitboard ymp = m_and(bb_black_pawn,UpBB[StoY(rk)]);
	ei.evscore -= (count_1s(ymp) * ADD_ChePaoPawn_ChePao1pawn_ByPawnByShi[RShi_num()]);

	int rcan = ei.rcan;
	int bcan = ei.bcan;
	
	Square bpao = S90_from_piecelist(POSITION,BPAO,0);
	Square rpao = S90_from_piecelist(POSITION,RPAO,0);
	Square rche = S90_from_piecelist(POSITION,RCHE,0);
	Square bche = S90_from_piecelist(POSITION,BCHE,0);

	Square rpawn = S90_from_piecelist(POSITION,RPAWN,0);
	Square bpawn = S90_from_piecelist(POSITION,BPAWN,0);

	if(isStringByChe(POSITION,rche,rpao,bche)){
		ei.evscore -= 96;
	}
	if(isStringByChe(POSITION,rche,bpao,bche)){
		ei.evscore += 96;
	}

	//  fen 2b1ka3/9/1c2b4/4p4/5r3/1R6P/9/4BC3/9/3AKAB2 w - - 0 1
	if ((RShi_num() + RXiang_num()) == 4 && StoY(rk) == 0x9) {
		if (StoY(bpawn) <= 0x6) {
			ei.rsafe = true;
		}
	}

	if ((BShi_num() + BXiang_num()) == 4 && StoY(bk) == 0x0) {
		if (StoY(rpawn) >= 0x3) {
			ei.bsafe = true;
		}
	}

	// fen 9/4k4/b3b4/5c3/3R4C/9/8P/2p1B4/9/r2AK1B2 b - - 0 1
	if(BXiang_num() == 2 && StoY(rpawn) >= 0x5 && abs(StoX(rpawn) - 0x4) == 4){
		if(RShi_num() <= 1 && StoY(bpawn) >= 0x6){
			ei.evscore -= 64;
		}
	}
	if(RXiang_num() == 2 && StoY(bpawn) <= 0x4 && abs(StoX(bpawn) - 0x4) == 4){
		if(BShi_num() <= 1 && StoY(rpawn) <= 0x3){
			ei.evscore += 64;
		}
	}

	// fen 4kc3/4a4/b3r4/4C2R1/4p4/6B2/4P4/5A3/4A4/2BK5 w - - 120 120
	if(BShi_num() >= 1 && BXiang_num() >= 1 && StoY(bk) <= 0x1){
		if(PB90(0x16) == BCHE && PB90(0x1F) == RPAO && PB90(0x28) == BPAWN && PB90(0x3A) == RPAWN){
			if(StoY(bpao) == 0x0 && StoY(rche) == 0x3){
				ei.bsafe = TRUE;
			}
		}
	}
	if(RShi_num() >= 1 && RXiang_num() >= 1 && StoY(rk) >= 0x8){
		if(PB90(0x43) == RCHE && PB90(0x3A) == BPAO && PB90(0x31) == RPAWN && PB90(0x1F) == BPAWN){
			if(StoY(rpao) == 0x9 && StoY(bche) == 0x6){
				ei.rsafe = TRUE;
			}
		}
	}

	if((RShi_num() + RXiang_num()) == 4 && StoY(rk) >= 0x8){
		if(bcan == 0){
			ei.rsafe = TRUE;
		}
	}
	if((BShi_num() + BXiang_num()) == 4 && StoY(bk) <= 0x1){
		if(rcan == 0){
			ei.bsafe = TRUE;
		}
	}
	
	// fen 3a5/3Pa4/5k3/1c7/5rp2/4R4/9/3AB3B/2C1A4/4K4 b - - 0 1
	if(ei.rsafe == TRUE){
		if(BShi_num() == 2 && StoY(rpawn) < StoY(bk) && !IsOnSameSide(rpawn,bk)){
			RETRUN_MUL(8);
		}
	}
	if(ei.bsafe == TRUE){
		if(RShi_num() == 2 && StoY(bpawn) > StoY(rk) && !IsOnSameSide(bpawn,rk)){
			RETRUN_MUL(8);
		}
	}

	// fen 4ka2R/9/9/9/9/5c2P/5p3/4B4/4A4/2BAK1C1r r
	if(abs(StoX(rpawn) - 0x4) == 4 && BShi_num() >= 1){
		if(StoY(rche) < StoY(rpawn) && StoX(rpawn) == StoX(rche)){
			if(bit_is_set(ei.attacked_by(BCHE),rpawn)){
				ei.evscore -= 96;
			}
		}
	}
	if(abs(StoX(bpawn) - 0x4) == 4 && RShi_num() >= 1){
		if(StoY(bche) > StoY(bpawn) && StoX(bpawn) == StoX(bche)){
			if(bit_is_set(ei.attacked_by(RCHE),bpawn)){
				ei.evscore += 96;
			}
		}
	}

	// fen 2b1ka3/4a4/9/3P5/2b6/3R5/1r2c4/B4A3/2p1A4/3C1K3 w - - 0 1
    if(RShi_num() == 2 && StoY(rk) == 0x9 && StoY(rpao) == 0x9){
		if((StoX(bpawn) <= 0x2 && StoX(rche) == 0x3 && StoX(rpawn) == 0x3)
		   ||(StoX(bpawn) >= 0x6 && StoX(rche) == 0x5 && StoX(rpawn) == 0x5)){
			if((BShi_num() + BXiang_num()) >= 3 && StoY(bk) <= 0x1){
				if(StoY(rpawn) == 0x3){
					RETRUN_MUL(8);
				}
			}
		}
	}
	if(BShi_num() == 2 && StoY(bk) == 0x0 && StoY(bpao) == 0x0){
		if((StoX(rpawn) <= 0x2 && StoX(bche) == 0x3 && StoX(bpawn) == 0x3)
			||(StoX(rpawn) >= 0x6 && StoX(bche) == 0x5 && StoX(bpawn) == 0x5)){
				if((RShi_num() + RXiang_num()) >= 3 && StoY(rk) >= 0x8){
					if(StoY(bpawn) == 0x6){
						RETRUN_MUL(8);
					}
				}
		}
	}

	//  fen 2b1ka3/9/1c2b4/4p4/5r3/1R6P/9/4BC3/9/3AKAB2 w - - 0 1
	if (ei.rsafe) {
		if (BShi_num() >= 1 && BXiang_num() == 2 && StoY(bk) <= 0x1) {
			if (StoY(rpawn) >= 0x5) {
				RETRUN_MUL(12);
			}
			if (abs(StoX(rpawn) - 0x4) >= 0x4) {
				RETRUN_MUL(12);
			}
		}
	}

	if (ei.bsafe) {
		if (RShi_num() >= 1 && RXiang_num() == 2 && StoY(rk) >= 0x8) {
			if (StoY(bpawn) <= 0x4) {
				RETRUN_MUL(12);
			}
			if (abs(StoX(bpawn) - 0x4) >= 0x4) {
				RETRUN_MUL(12);
			}
		}
	}

}

#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"

void m_MT_BR_1che1ma1pawn(typePOS &POSITION, EvalInfo &ei){

	// ADD_BR
	Square bk = BKpos();
	Bitboard bmp = m_and(bb_white_pawn,LowBB[StoY(bk)]);
	ei.evscore += (count_1s(bmp) * ADD_CheMaXPawn_To_1Pao2Ma_ByPawn[BShi_num()]);
	// SUB
	Square rk = RKpos();
	Bitboard ymp = m_and(bb_black_pawn,UpBB[StoY(rk)]);
	ei.evscore -= (count_1s(ymp) * ADD_CheMaXPawn_To_1Pao2Ma_ByPawn[RShi_num()]);

	int rcan = ei.rcan;
	int bcan = ei.bcan;


	// fen 3ak4/4a4/1n2b4/1N3R3/1r7/2P6/9/4B4/6p2/2BAKA3 w - - 10 10
	if((BShi_num() + BXiang_num()) >= 3 && StoY(bk) == 0x0){
		ei.evscore -= bcan * 64;
	}
	if((RShi_num() + RXiang_num()) >= 3 && StoY(rk) == 0x9){
		ei.evscore += rcan * 64;
	}

	Square rche = S90_from_piecelist(POSITION,RCHE,0);
	Square bche = S90_from_piecelist(POSITION,BCHE,0);

	Square rma  = S90_from_piecelist(POSITION,RMA,0);
	Square bma  = S90_from_piecelist(POSITION,BMA,0);

	Square rpawn = S90_from_piecelist(POSITION,RPAWN,0);
	Square bpawn = S90_from_piecelist(POSITION,BPAWN,0);

	// fen 2b1k4/4a4/9/9/1n1NP1b2/9/7R1/5A3/3KAp3/2r6 b
	if(RShi_num() == 2 && StoY(bpawn) >= 0x8 && StoY(rk) >= 0x8
		&& !IsOnSameSide(rk,bma) && !IsOnSameSide(rk,bpawn)){
		if(StoX(bpawn) > 0x4 && PB90(0x44) == RSHI){
			ei.evscore += 64;
		}
		if(StoX(bpawn) < 0x4 && PB90(0x42) == RSHI){
			ei.evscore += 64;
		}
	}
	if(BShi_num() == 2 && StoY(rpawn) <= 0x1 && StoY(bk) <= 0x1
		&& !IsOnSameSide(bk,rma) && !IsOnSameSide(bk,rpawn)){
		if(StoX(rpawn) > 0x4 && PB90(0x17) == BSHI){
			ei.evscore -= 64;
		}
		if(StoX(rpawn) < 0x4 && PB90(0x15) == BSHI){
			ei.evscore -= 64;
		}
	}

	// fen 2bak4/4a4/4b4/8p/9/2Rnr1BNP/9/4BA3/5K3/3A5 b - - 0 1
	if(rcan == 0 && bcan == 0){
		if((BShi_num() + BXiang_num()) == 4 && (RShi_num() + RXiang_num()) == 4){
			if(StoY(rk) >= 0x8 && StoY(bk) <= 0x1){
				// 这个牵制了,也没有
				if(StoY(rche) == StoY(bche)){
					if(StoY(rche) == 0x5 || StoY(bche) == 0x4){
						RETRUN_MUL(8);
					}
				}
			}
		}
		// fen 2b1k4/4a4/4ba3/9/p5r2/2B2nN2/P5R2/9/4A4/5K3 w - - 0 0
		if(StoX(bche) == StoX(rche)){
			if((BShi_num() + BXiang_num()) >= 3 && StoY(bk) <= 1){ // b safe 
				if(RShi_num() >= 1 && RXiang_num() >= 1 && StoY(rk) == 0x9 && StoY(bche) <= 0x4){
					if(PB90(0x33) == RMA || PB90(0x2f) == RMA){
						RETRUN_MUL(8);
					}
				}
			}
			if((RShi_num() + RXiang_num()) >= 3 && StoY(rk) >= 8){ // b safe 
				if(BShi_num() >= 1 && BXiang_num() >= 1 && StoY(bk) == 0x0 && StoY(rche) >= 0x5){
					if(PB90(0x2a) == BMA || PB90(0x26) == BMA){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 4ka3/9/3a5/5r3/7P1/2N2p2R/5n3/3AB4/4A4/3K2B2 w - - 0 1
	if(RShi_num() == 2 && StoY(rk) == 0x9 && StoY(bpawn) <= 0x6){
		if(BShi_num() == 2 && StoY(bk) == 0x0 && StoY(rpawn) >= 0x3){
			RETRUN_MUL(8);
		}
	}

	// fen 3k1ab2/3na1N2/6P1b/3R5/9/3pr4/9/B3B4/4A4/4KA3 b - - 0 1
	if((RShi_num() + RXiang_num()) >= 3){
		if(StoY(rk) >= 0x8){
			if((BShi_num()  + BXiang_num() ) == 4 && StoY(bk) == 0x0){
				if(!IsOnSameSide(bk,rma) && !IsOnSameSide(bk,rpawn)){
                    if(StoY(bma) <= 0x2 && IsOnSameSide(bma,bk) && StoY(rpawn) <= 2){
						if(StoY(bpawn) >= 0x5 && StoY(bpawn) <= 0x7){
							RETRUN_MUL(8);
						}
					}
				}
			}
		}
	}
	if((BShi_num() + BXiang_num()) >= 3){
		if(StoY(bk) <= 0x1){
			if((RShi_num()  + RXiang_num() ) == 4 && StoY(rk) == 0x9){
				if(!IsOnSameSide(rk,bma) && !IsOnSameSide(rk,bpawn)){
					if(StoY(rma) >= 0x7 && IsOnSameSide(rma,rk) && StoY(bpawn) >= 7){
						if(StoY(rpawn) <= 0x4 && StoY(rpawn) >= 0x2){
							RETRUN_MUL(8);
						}
					}
				}
			}
		}
	}

	// fen 4k2r1/4a4/4b4/p6n1/4N1bR1/P8/9/9/4K4/5AB2 w - - 0 1
	if (ei.rcan == 0 && ei.bcan == 0){
		//if (0x28 == rma){
			if (BShi_num() >= 1 && BXiang_num() == 2 && StoY(bk) == 0x0){
				if (isStringByChe(POSITION, rche, bma, bche) && StoY(rche) > StoY(bche)){
					if (bma == 0x22){
						if (0x28 == rma || 0x21 == rma){
							RETRUN_MUL(8);
						}
					}
					if (bma == 0x1c){
						if (0x28 == rma || 0x1d == rma){
							RETRUN_MUL(8);
						}
					}
				}
			}
		//}
		//if (0x31 == bma){
			if (RShi_num() >= 1 && RXiang_num() == 2 && StoY(rk) == 0x9){
				if (isStringByChe(POSITION, rche, rma, bche) && StoY(rche) > StoY(bche)){
					if (rma == 0x37){
						if (0x31 == bma || 0x38 == bma){
							RETRUN_MUL(8);
						}
					}
					if (rma == 0x3d){
						if (0x31 == bma || 0x3c == bma){
							RETRUN_MUL(8);
						}
					}
				}
			}
		//}
	}

	//if(RShi_num() == 2 && RXiang_num() == 2 )

	//// fen 2b1k4/4a4/4ba3/9/p5r2/2B2nN2/P5R2/9/4A4/5K3 w - - 0 0
	//if(ei.rcan == 0 && ei.bcan == 0){

	//}

}
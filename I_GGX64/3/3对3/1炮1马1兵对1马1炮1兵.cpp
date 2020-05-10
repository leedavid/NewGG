
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"


void m_MT_1pao1ma1pawn_1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei) {



	Square rpawn = S90_from_piecelist(POSITION, RPAWN, 0);
	Square bpawn = S90_from_piecelist(POSITION, BPAWN, 0);

	Square rk = RKpos();
	Square bk = BKpos();

	// fen 5k1C1/4a4/3ab4/9/2b6/9/6nNP/9/1c1pA4/2BAK1B2 w - - 0 1
	if (BShi_num() == 2 && BXiang_num() == 2 && StoY(bk) <= 1) {
		if (StoY(rpawn) >= 0x5) {
			ei.bsafe = TRUE;
		}
	}
	if (RShi_num() == 2 && RXiang_num() == 2 && StoY(rk) >= 8) {
		if (StoY(bpawn) <= 0x4) {
			ei.rsafe = TRUE;
		}
	}

	//  fen 4k4/3Pa4/3a5/3cNn3/3C5/9/1p7/4B4/4A4/3A1K3 b - - 0 1
	if (StoY(rpawn) == 0x3) {
		ei.evscore += 64;
	}
	if (StoY(bpawn) == 0x6) {
		ei.evscore -= 64;
	}

	//  fen 5k3/4a4/b2a5/7N1/4pC3/2P3B2/9/4Bn3/4K3c/9 b - - 0 1
	if (RShi_num() == 0) {
		ei.evscore -= ei.bcan * 32;
	}
	if (BShi_num() == 0) {
		ei.evscore += ei.rcan * 32;
	}



	if(StoY(rpawn) < StoY(bk)){
		ei.evscore -= 96;
	}
	if(StoY(bpawn) > StoY(rk)){
		ei.evscore += 96;
	}

	if(StoY(rpawn) == 0){
		ei.evscore -= 32;
		if(StoY(bk) != 0x0){
			ei.evscore -= 32;
		}
	}

	if(StoY(bpawn) == 9){
		ei.evscore += 32;
		if(StoY(rk) != 0x9){
			ei.evscore += 32;
		}
	}

	// fen 5k3/2N1a4/5a2b/4n4/4Cc3/2B3P2/9/8p/4A4/2BAK4 b - - 36 36
	if(BShi_num() == 2 && BXiang_num() >= 1 && StoY(bk) == 0x0){
		if(RShi_num() == 2 && RXiang_num() >= 1 && StoY(rk) == 0x9){
			if(StoY(rpawn) < 0x5 && StoY(rpawn) > StoY(bk)){
				ei.evscore += 64;
			}
			if(StoY(bpawn) > 0x4 && StoY(bpawn) < StoY(rk)){
				ei.evscore -= 64;
			}
		}
	}

	// fen 4k4/4a4/5a3/3P5/9/c3N1B2/3n5/2C1B4/4A1p2/4KA3 w - - 0 1
	if(RShi_num() == 2 && RXiang_num() == 2 && StoY(rk) == 0x9 && StoY(bpawn) >= 0x8){
		if(StoX(bpawn) > 0x4 && !have_bit(bb_white_shi,LeftBB[0x4])){
			ei.rsafe = TRUE;
		}
		if(StoX(bpawn) < 0x4 && !have_bit(bb_white_shi,RightBB[0x4])){
			ei.rsafe = TRUE;
		}
	}
	if(BShi_num() == 2 && BXiang_num() == 2 && StoY(bk) == 0x0 && StoY(rpawn) <= 0x1){
		if(StoX(rpawn) > 0x4 && !have_bit(bb_black_shi,LeftBB[0x4])){
			ei.bsafe = TRUE;
		}
		if(StoX(rpawn) < 0x4 && !have_bit(bb_black_shi,RightBB[0x4])){
			ei.bsafe = TRUE;
		}
	}



	// fen 3a5/3Pa1N2/3k5/6c2/2b3b2/2B6/5C3/3A5/3pAK1n1/9 w - - 0 1
	if(RShi_num() == 2 && RXiang_num() >= 1){
		if(StoY(bpawn) >= 0x8){
			if(StoX(bpawn) < 0x4 && PB90(0x42) == RSHI){
				ei.evscore += 32;
			}
			if(StoX(bpawn) > 0x4 && PB90(0x44) == RSHI){
				ei.evscore += 32;
			}
		}
	}
	if(BShi_num() == 2 && BXiang_num() >= 1){
		if(StoY(rpawn) <= 0x1){
			if(StoX(rpawn) < 0x4 && PB90(0x15) == BSHI){
				ei.evscore -= 32;
			}
			if(StoX(rpawn) > 0x4 && PB90(0x17) == BSHI){
				ei.evscore -= 32;
			}
		}
	}

	// fen 5k1C1/4a4/3ab4/9/2b6/9/6nNP/9/1c1pA4/2BAK1B2 w - - 0 1
	if(ei.bsafe){
		if(RShi_num() == 2 && RXiang_num() == 2 && StoY(rk) == 9){
			if(StoY(bpawn) >= 0x8){
				if(StoX(bpawn) < 0x4 && !have_bit(bb_white_shi,RightBB[0x4])){
					RETRUN_MUL(4);
				}
				if(StoX(bpawn) > 0x4 && !have_bit(bb_white_shi,LeftBB[0x4])){
					RETRUN_MUL(4);
				}
			}
		}
	}
	if(ei.rsafe){
		if(BShi_num() == 2 && BXiang_num() == 2 && StoY(bk) == 0){
			if(StoY(rpawn) <= 0x1){
				if(StoX(rpawn) < 0x4 && !have_bit(bb_black_shi,RightBB[0x4])){
					RETRUN_MUL(4);
				}
				if(StoX(rpawn) > 0x4 && !have_bit(bb_black_shi,LeftBB[0x4])){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 5ab2/3ka4/4b4/4c2N1/8C/p4n3/8P/B2A5/9/4KAB2 b - - 0 1
	if(RShi_num() == 2 && RXiang_num() == 2 && StoY(rk) >= 0x8){
		if(BShi_num() == 2 && BXiang_num() == 2 && StoY(bk) <= 0x1){
			if(StoY(bpawn) <= 0x6 && StoY(rpawn) >= 0x3){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3a5/4ak3/8b/7Np/6n2/9/1C3c2P/4B4/4A4/4KAB2 w - - 0 1
	if(ei.rsafe){
		if(ei.rcan == 0){
			if((BShi_num() + BXiang_num()) >= 3 && StoY(bk) <= 1){
				RETRUN_MUL(6);
			}
		}
	}
	if(ei.bsafe){
		if(ei.bcan == 0){
			if((RShi_num() + RXiang_num()) >= 3 && StoY(rk) >= 8){
				RETRUN_MUL(6);
			}
		}
	}

	// fen 4kab2/4a4/2N1c4/4C4/8p/2P6/3n5/4B4/4A4/2BAK4 w - - 8 8
	if(BShi_num() == 2 && BXiang_num() >= 1 && StoY(bk) == 0x0){
		if(RShi_num() == 2 && RXiang_num() >= 1 && StoY(rk) == 0x9){
			//if(StoY(rpawn) >= 0x3 && StoY(bpawn) <= 0x6){
			//	RETRUN_MUL(8);
			//}
			if(ei.rcan >= 1 && ei.bcan >= 1){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4kabC1/3n5/5a3/8p/6bc1/4N4/8P/4B4/4A4/2BA1K3 w - - 0 1
	if(ei.rcan == 0 && ei.bcan == 0){
		if(RShi_num() == 2 && RXiang_num() == 2){
			if(BShi_num() == 2 && BXiang_num() == 2){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4k4/1cNna4/5a3/3P5/9/4C4/4p4/9/9/2BAKAB2 b - - 0 1
	if(RShi_num() == 2 && RXiang_num() == 2 && StoY(rk) >= 0x8){
		if(BShi_num() == 2 && have_bit(POSITION.pieces(BSHI),RankBB_A[0x2])){
			if(StoY(bpawn) == 0x6 && StoY(rpawn) >= 0x3 && StoY(bk) == 0x0){
				RETRUN_MUL(8);
			}
		}
	}
	if(BShi_num() == 2 && BXiang_num() == 2 && StoY(bk) <= 0x1){
		if(RShi_num() == 2 && have_bit(POSITION.pieces(RSHI),RankBB_A[0x7])){
			if(StoY(rpawn) == 0x3 && StoY(bpawn) <= 0x6 && StoY(rk) == 0x9){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3a1a3/9/4k3b/7NC/4p4/6P2/5c2n/4BA3/9/2BAK4 w - - 0 1
	if (ei.rsafe){
		if ((BShi_num() + BXiang_num()) >= 3){
			if (StoY(rpawn) >= 0x4){
				RETRUN_MUL(8);
			}
		}
	}
	if (ei.bsafe){
		if ((RShi_num() + RXiang_num()) >= 3){
			if (StoY(bpawn) <= 0x5){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3a5/3Pa1N2/3k5/6c2/2b3b2/2B6/5C3/3A5/3pAK1n1/9 w - - 0 1
	if((RShi_num() + RXiang_num()) >= 3 && StoY(rk) >= 0x8){
		if((BShi_num() + BXiang_num()) >= 3 && StoY(bk) <= 1){
			RETRUN_MUL(12); // fen 2bakab2/1c7/6P2/3N5/4C1p2/5n3/9/4B4/4K4/2BA5 w - - 0 1
		}
	}

	// fen 4k4/4a4/5a3/3P5/9/c3N1B2/3n5/2C1B4/4A1p2/4KA3 w - - 0 1
	if(ei.rsafe){
		if(BShi_num() == 2 && StoY(bk) == 0x0 && StoY(rpawn) >= 0x2){
			RETRUN_MUL(12);
		}
	}
	if(ei.bsafe){
		if(RShi_num() == 2 && StoY(rk) == 0x9 && StoY(bpawn) <= 0x7){
			RETRUN_MUL(12);
		}
	}

}
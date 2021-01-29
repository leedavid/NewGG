
#include "../../chess.h"
#include "../../preGen.h"

#include "../../endgame/mat.h"

//二兵对二兵
void m_MT_2pawn_TO_2pawn(typePOS &POSITION, EvalInfo &ei){


	BothOnlyPawnEval(POSITION,ei);

    if(RShi_num() == 2 && RXiang_num() >= 1){
		ei.rsafe = TRUE;
	}

	if(BShi_num() == 2 && BXiang_num() >= 1){
		ei.bsafe = TRUE;
	}



	Square rpawn1 = S90_from_piecelist(POSITION,RPAWN,0);
	Square rpawn2 = S90_from_piecelist(POSITION,RPAWN,1);

	Square bpawn1 = S90_from_piecelist(POSITION,BPAWN,0);
	Square bpawn2 = S90_from_piecelist(POSITION,BPAWN,1);

	Square bk = BKpos();
	Square rk = RKpos();

	if (StoY(rpawn1) == 0x0 || StoY(rpawn2) == 0x0){
		if (StoY(bk) != 0x0){
			ei.bsafe = true;
		}
	}
	if (StoY(bpawn1) == 0x9 || StoY(bpawn2) == 0x9){
		if (StoY(rk) != 0x9){
			ei.rsafe = true;
		}
	}

	// fen 9/3Pa4/3ak1P2/9/9/9/9/9/2p1A2p1/3K5 b - - 121 121
	// 二兵到二线，对方的将在一边 
	if(StoY(bpawn1) >= 0x8 && StoY(bpawn2) >= 0x8){
		if(RShi_num() >= 1 && StoX(bk) != 0x4){
			if(IsOnSameSide(bpawn1,bpawn2) == FALSE && PB90(0x4C) != BPAWN){
				ei.rsafe = TRUE;
			}
		}
	}
	if(StoY(rpawn1) <= 0x1 && StoY(rpawn2) <= 0x1){
		if(BShi_num() >= 1 && StoX(rk) != 0x4){
			if(IsOnSameSide(rpawn1,rpawn2) == FALSE && PB90(0x0D) != RPAWN){
				ei.bsafe = TRUE;
			}
		}
	}
	int rcan = ei.rcan;
	int bcan = ei.bcan;

	// fen 9/3Pa4/3ak1P2/9/9/9/9/9/2p1A2p1/3K5 b - - 121 121
	if(BShi_num() == 2 && rcan <= 1){
		ei.bsafe = TRUE;
	}
	if(RShi_num() == 2 && bcan <= 1){
		ei.rsafe = TRUE;
	}

	// fen 2b6/4k4/4b4/9/4P3p/9/8P/5A3/2p6/3K2B2 w - - 0 0
	if(bcan <= 1 && RShi_num() >= 1 && RXiang_num() >= 1){
		ei.rsafe = TRUE;
	}
	if(rcan <= 1 && BShi_num() >= 1 && BXiang_num() >= 1){
		ei.bsafe = TRUE;
	}

	// fen 9/7P1/4bk3/9/8p/9/8P/4BA3/4K4/5p3 w - - 0 1
	if(ei.rsafe){
		if(ei.rcan <= 1){
			if(have_bit(POSITION.pieces(RPAWN),UpBB[StoY(bk)])){
				if((BShi_num() + BXiang_num()) >= 1){
					RETRUN_MUL(2);
				}
			}
		}
	}
	if(ei.bsafe){
		if(ei.bcan <= 1){
			if(have_bit(POSITION.pieces(BPAWN),LowBB[StoY(rk)])){
				if((RShi_num() + RXiang_num()) >= 1){
					RETRUN_MUL(2);
				}
			}
		}
	}
	// fen 4k4/3P1P3/b2ab4/9/9/2B6/9/3A1A3/3p1p3/4K4 w - - 0 0
	if(ei.rsafe){
		if(BShi_num() >= 1 && BXiang_num() >= 1){
			if(PB90(0x15) == BSHI){
				if(StoX(bpawn1) == 0x5 && StoY(bpawn1) < StoY(rk)){
					RETRUN_MUL(4);
				}
				if(StoX(bpawn2) == 0x5 && StoY(bpawn2) < StoY(rk)){
					RETRUN_MUL(4);
				}
			}
			if(PB90(0x17) == BSHI){
				if(StoX(bpawn1) == 0x3 && StoY(bpawn1) < StoY(rk)){
					RETRUN_MUL(4);
				}
				if(StoX(bpawn2) == 0x3 && StoY(bpawn2) < StoY(rk)){
					RETRUN_MUL(4);
				}
			}
		}
	}

	if(ei.bsafe){
		if(RShi_num() >= 1 && RXiang_num() >= 1){
			if(PB90(0x42) == RSHI){
				if(StoX(rpawn1) == 0x5 && StoY(rpawn1) > StoY(bk)){
					RETRUN_MUL(4);
				}
				if(StoX(rpawn2) == 0x5 && StoY(rpawn2) > StoY(bk)){
					RETRUN_MUL(4);
				}
			}
			if(PB90(0x44) == RSHI){
				if(StoX(rpawn1) == 0x3 && StoY(rpawn1) > StoY(bk)){
					RETRUN_MUL(4);
				}
				if(StoX(rpawn2) == 0x3 && StoY(rpawn2) > StoY(bk)){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 9/3Pak3/3aP4/9/8p/2B6/9/B3pA3/4A4/4K4 w - - 0 1
	if(ei.rsafe){
		if(BShi_num() == 2){
			if(ei.bcan >= 1){
				RETRUN_MUL(4);
			}
		}
	}
	if(ei.bsafe){
		if(RShi_num() == 2){
			if(ei.rcan >= 1){
				RETRUN_MUL(4);
			}
		}
	}


	// fen 3k5/9/4b4/1P7/8p/9/8P/4K4/4A4/4p1B2 w - - 0 1
    if(ei.rsafe){
		if(ei.rcan <= 1){
			if(BXiang_num() >= 1){
			   if(have_bit(POSITION.pieces(RPAWN),UpBB[0x4])){
				   Bitboard op = m_and(POSITION.pieces(BPAWN),RankBB_A[0x4]);

				   Square yp;
				   while (pop_1st_bit_sq(op, yp)) {
					   if(PB90(yp + 18) == RPAWN) RETRUN_MUL(4);
				   }
			   }
			}
		}
	}
	// fen 2b1P4/4a4/4k4/p8/9/P8/7p1/4B4/9/5K3 b
	if(ei.bsafe){
		if(ei.bcan <= 1){
			if(RXiang_num() >= 1){
				if(have_bit(POSITION.pieces(BPAWN),LowBB[0x5])){
					Bitboard op = m_and(POSITION.pieces(RPAWN),RankBB_A[0x5]);

					Square yp;
					while (pop_1st_bit_sq(op, yp)) {
						if(PB90(yp - 18) == BPAWN) RETRUN_MUL(4);
					}
				}
			}
		}
	}


	if(ei.rsafe){
		if(BXiang_num() == 2){
			if(PB90(0x2c) == BPAWN && PB90(0x3e) == RPAWN){
				if(PB90(0x2a) != RPAWN && PB90(0x2b) != RPAWN){
					RETRUN_MUL(4);
				}
			}
			if(PB90(0x24) == BPAWN && PB90(0x36) == RPAWN){
				if(PB90(0x25) != RPAWN && PB90(0x26) != RPAWN){
					RETRUN_MUL(4);
				}
			}
		}
	}
	if(ei.bsafe){
		if(RXiang_num() == 2){
			if(PB90(0x2d) == RPAWN && PB90(0x1b) == BPAWN){
				if(PB90(0x2e) != BPAWN && PB90(0x2f) != BPAWN){
					RETRUN_MUL(4);
				}
			}
			if(PB90(0x35) == RPAWN && PB90(0x23) == BPAWN){
				if(PB90(0x33) != BPAWN && PB90(0x34) != BPAWN){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 9/4ak3/1P2P4/9/9/9/5p3/9/5K3/1p7 w - - 0 1
	if (ei.rsafe){
		if (BShi_num() >= 1){
			if (StoY(bpawn1) <= 0x6 && StoX(bpawn1) == StoX(rk)){
				RETRUN_MUL(8);
			}
			if (StoY(bpawn2) <= 0x6 && StoX(bpawn2) == StoX(rk)){
				RETRUN_MUL(8);
			}
		}
	}
	if (ei.bsafe){
		if (RShi_num() >= 1){
			if (StoY(rpawn1) >= 0x3 && StoX(rpawn1) == StoX(bk)){
				RETRUN_MUL(8);
			}
			if (StoY(rpawn2) >= 0x3 && StoX(rpawn2) == StoX(bk)){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 2bakab2/2P6/9/p3P4/8p/9/9/4B4/4A4/4K1B2 b - - 0 1
	if(ei.bsafe){
		if(RShi_num() >= 1 && RXiang_num() >= 1){
			if(have_bit(bb_white_pawn,RankBB_A[0x3])){
				RETRUN_MUL(8);
			}
		}
	}
	if(ei.rsafe){
		if(BShi_num() >= 1 && BXiang_num() >= 1){
			if(have_bit(bb_black_pawn,RankBB_A[0x6])){
				RETRUN_MUL(8);
			}
		}
	}

}
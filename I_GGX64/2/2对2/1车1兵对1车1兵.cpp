
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"

//const int ADD_byShi[3]   = {196,64,32};

//车兵对车兵
void m_MT_1CHE1PAWN_TO_1CHE1PAWN(typePOS &POSITION, EvalInfo &ei){

	Square rpawn = S90_from_piecelist(POSITION,RPAWN,0);
	Square bpawn = S90_from_piecelist(POSITION,BPAWN,0);

	Square rk = RKpos();
	Square bk = BKpos();

	Square rche = S90_from_piecelist(POSITION,RCHE,0);
	Square bche = S90_from_piecelist(POSITION,BCHE,0);

	int rcan = ei.rcan;
	int bcan = ei.bcan;

	bool isstrBpawn = isStringByChe(POSITION,rche,bpawn,bche);
	bool isstrRpawn = isStringByChe(POSITION,rche,rpawn,bche);
	bool isYstrBpawn = FALSE;
	bool isYstrRpawn = FALSE;

	if(StoY(rche) == StoY(bpawn) && StoX(bpawn) == StoX(bche)){
		if(StoY(bpawn) >= 0x5){
			isYstrBpawn = TRUE;
		}
	}
	if(StoY(bche) == StoY(rpawn) && StoX(rpawn) == StoX(rche)){
		if(StoY(rpawn) <= 0x4){
			isYstrRpawn = TRUE;
		}
	}

	//如果一方是低兵，则要减分
	if(StoY(bpawn) == 0x9){
		ei.evscore += 32;
	}
	if(StoY(rpawn) == 0x0){
		ei.evscore -= 32;
	}

	if(StoX(rk) == 0x4){
		ei.evscore += 32;
	}
	if(StoX(bk) == 0x4){
		ei.evscore -= 32;
	}

	if(StoX(rche) == 0x4){
		ei.evscore += 32;
	}
	if(StoX(bche) == 0x4){
		ei.evscore -= 32;
	}
	//如果一方的将与对方的兵在同一边,要减分
	if(King_4_Side(rk) == King_4_Side(bpawn)){
		if(StoY(bpawn) == 0x9){
			ei.evscore -= 24;
		}
		else{
			ei.evscore -= 64;
		}
	}
	if(King_4_Side(bk) == King_4_Side(rpawn)){
		if(StoY(rpawn) == 0x0){
			ei.evscore += 24;
		}
		else{
			ei.evscore += 64;
		}
	}
    // 双方都有两个仕
	if(BShi_num() == 2 && StoY(bk) <= 1){
		ei.bsafe = TRUE;
	}
	if(RShi_num() == 2 && StoY(rk) >= 8){
		ei.rsafe = TRUE;
	}

	// fen 3k5/2R2P3/r4a3/9/9/9/9/9/1p2A4/2B1K1B2 r
	if(RShi_num() >= 1 && RXiang_num() >= 1 && StoY(rk) >= 0x8){
		if(abs(StoX(bpawn) - 0x4) >= 2){
			ei.rsafe = TRUE;
		}
	}
	if(BShi_num() >= 1 && BXiang_num() >= 1 && StoY(bk) <= 0x1){
		if(abs(StoX(rpawn) - 0x4) >= 2){
			ei.bsafe = TRUE;
		}
	}

	// fen 3P5/5k3/9/9/4R4/9/9/3K5/1r3p3/9 b - - 0 1
	if (RShi_num() == 0 && BShi_num() == 0){
		if (StoX(rche) == 0x4){
			ei.evscore += 64;
			if (StoY(bpawn) >= StoY(rk)){
				ei.evscore += 64;
			}
		}
		if (StoX(bche) == 0x4){
			ei.evscore -= 64;
			if (StoY(rpawn) <= StoY(bk)){
				ei.evscore -= 64;
			}
		}
	}

	// fen 6R2/4ak3/4b1P2/9/6r2/2B6/9/9/4K4/3p5 w - - 0 1
	if(BShi_num() >= 1 && BXiang_num() >= 1 && PB90(0x0d) == BSHI && PB90(0x16) == BXIANG){
		if(StoX(rche) == StoX(rpawn) && StoY(rche) < StoY(rpawn)){
			if(0x18 == rpawn && 0x2a == bche){
				ei.evscore -= 168;
			}
			if(0x14 == rpawn && 0x26 == bche){
				ei.evscore -= 168;
			}
		}
	}
	if(RShi_num() >= 1 && RXiang_num() >= 1 && PB90(0x4c) == RSHI && PB90(0x43) == RXIANG){
		if(StoX(bche) == StoX(bpawn) && StoY(bche) > StoY(bpawn)){
			if(0x45 == bpawn && 0x33 == rche){
				ei.evscore += 168;
			}
			if(0x41 == bpawn && 0x2f == rche){
				ei.evscore += 168;
			}
		}
	}

	// fen 4k4/4a1P2/3ab4/9/2b2r3/9/4R4/4Bp3/4A4/3K2B2 w - - 0 0
	if(RXiang_num() == 2 && RShi_num() >= 1){
		if(StoY(bpawn) <= 0x7){
			if(StoX(rk) == 0x3){
				if(StoX(bpawn) > 0x4){
					ei.rsafe = TRUE;
				}
			}
			if(StoX(rk) == 0x5){
				if(StoX(bpawn) < 0x4){
					ei.rsafe = TRUE;
				}
			}
		}
	}
	if(BXiang_num() == 2 && BShi_num() >= 1){
		if(StoY(rpawn) >= 0x2){
			if(StoX(bk) == 0x3){
				if(StoX(rpawn) > 0x4){
					ei.bsafe = TRUE;
				}
			}
			if(StoX(bk) == 0x5){
				if(StoX(rpawn) < 0x4){
					ei.bsafe = TRUE;
				}
			}
		}
	}
	// fen 5Rb2/3k5/4b4/9/p3r4/6P2/9/3ABA3/9/2B1K4 w - - 71 71
	if(BXiang_num() == 2){
		if(StoY(rpawn) >= 0x5 && rcan == 0){
			ei.bsafe = TRUE;
		}
	}
	if(RXiang_num() == 2){
		if(StoY(bpawn) <= 0x4 && bcan == 0){
			ei.rsafe = TRUE;
		}
	}

	// fen 9/4k4/4b4/4R4/r3p4/2P6/9/B2A1K3/4A4/9 b - - 0 1
	if(RShi_num() == 2 && RXiang_num() >= 1 && StoY(bpawn) <= 4){
		ei.rsafe = TRUE;
	}
	if(BShi_num() == 2 && BXiang_num() >= 1 && StoY(rpawn) >= 5){
		ei.bsafe = TRUE;
	}

	if(StoY(rpawn) > StoY(bk)){
		ei.evscore += ADD_CheXPawn_To_Che_ByShi[BShi_num()];
	}
	if(StoY(bpawn) < StoY(rk)){
		ei.evscore -= ADD_CheXPawn_To_Che_ByShi[RShi_num()];
	}

	//如果双方的兵都没有过河,且在一条列线,则只要一方有车在保兵就是和棋 
	if(StoY(rpawn) > 0x4 && StoY(bpawn) < 0x5 && StoX(rpawn) == StoX(bpawn)){
		if(StoY(rche) == StoY(rpawn)){
			RETRUN_MUL(2);
		}
		if(StoY(bche) == StoY(bpawn)){
			RETRUN_MUL(2);
		}
	}

	// fen 4k4/4a4/4R4/4P1r2/9/2B6/9/3ABp3/9/4KA3 w - - 0 1
	if (ei.rsafe){
		if (BShi_num() >= 1){
			if (StoX(rche) == StoX(rpawn) && StoY(rche) < StoY(rpawn)){
				if (StoY(bche) == StoY(rpawn)){
					if (StoX(rche) == 0x4 && PB90(Square(0x0d)) == BSHI){
						RETRUN_MUL(2);
					}
				}
			}
		}
	}
	if (ei.bsafe){
		if (RShi_num() >= 1){
			if (StoX(bche) == StoX(bpawn) && StoY(bche) > StoY(bpawn)){
				if (StoY(rche) == StoY(bpawn)){
					if (StoX(bche) == 0x4 && PB90(Square(0x4c)) == RSHI){
						RETRUN_MUL(2);
					}
				}
			}
		}
	}

	//
	// fen 4k1b2/4a4/4b4/9/6r1p/2P1R4/9/9/9/2BAKAB2 w - - 1 1
	if(RShi_num() == 2 && RXiang_num() == 2){
		ei.rsafe = TRUE;
	}
	if(BShi_num() == 2 && BXiang_num() == 2){
		ei.bsafe = true;
	}

	if(BShi_num() >= 1 && BXiang_num() == 2){
		if(rcan == 0){
			ei.bsafe = true;
		}
	}
	if(RShi_num() >= 1 && RXiang_num()  == 2){
		if(bcan == 0){
			ei.rsafe = true;
		}
	}

	// fen 3ak4/4aP3/9/9/2b3b2/3R4p/9/4B4/3KA4/8r w - - 122 122
	if(RShi_num() >= 1 && RXiang_num()  >= 1){
		if(isYstrBpawn){
			if(StoY(bche) > StoY(bpawn)){
				if(StoX(bpawn) == 0x8 || StoX(bpawn) == 0x0){
					ei.rsafe = true;
				}
			}
		}
	}
	if(BShi_num() >= 1 && BXiang_num() >= 1){
		if(isYstrRpawn){
			if(StoY(rche) < StoY(rpawn)){
				if(StoX(rpawn) == 0x8 || StoX(rpawn) == 0x0){
					ei.bsafe = true;
				}
			}
		}
	}

	// fen 2R3b2/3ka4/9/2P6/2r6/4p1B2/9/9/4A4/3AK4 w - - 6 6
    //黑方也安全了,车兵被牵制了
	if(BShi_num() >= 1 && BXiang_num() >= 1){
		if(PB90(0x0D) == BSHI ){
			if(StoX(bche) == StoX(rche) && StoY(bche) > StoY(rche) && StoY(rpawn) <= 0x3){
				if(isstrRpawn){
					if(PB90(0x16) == BXIANG && PB90(0x26) == BCHE){
						ei.bsafe = true;
					}
					if(PB90(0x16) == BXIANG && PB90(0x2A) == BCHE){
						ei.bsafe = true;
					}
				}
			}
		}
	}
	// fen 2R6/3ka4/4b4/2P6/2r6/4p1B2/9/9/4A4/3AK4 w
	// fen 2R3b2/3ka4/9/2P6/2r6/4p1B2/9/9/4A4/3AK4 w - - 6 6
    //黑方也安全了,车兵被牵制了
	if(RShi_num() >= 1 && RXiang_num()  >= 1){
		if(PB90(0x4C) == RSHI ){
			if(StoX(bche) == StoX(rche) && StoY(bche) > StoY(rche) && StoY(bpawn) >= 0x6){
				if(isstrBpawn){
					if(PB90(0x43) == RXIANG && PB90(0x2F) == RCHE){
						ei.rsafe = true;
					}
					if(PB90(0x43) == RXIANG && PB90(0x33) == RCHE){
						ei.rsafe = true;
					}
				}
			}
		}
	}

	
	//**********************************
	// fen 4k4/4a4/4b4/9/4r4/2P3B1p/7R1/4B4/4A4/4KA3 w - - 0 0
	if(BShi_num() >= 1 && BXiang_num() >= 1){
		if(StoY(bk) == 0x0){
			if(rcan  == 0){
				ei.bsafe = true;
			}
			if(StoY(rpawn) >= 0x5){  //没有过河
				if(PB90(0x28) == BCHE){
					ei.bsafe = true;
				}
			}
		}
	}
	// fen 4k4/4a4/4b4/9/4r4/2P3B1p/7R1/4B4/4A4/4KA3 w - - 0 0
	if(RShi_num() >= 1 && RXiang_num()  >= 1){
		if(StoY(rk) == 0x9){
			if(bcan  == 0){
				ei.rsafe = true;
			}
			if(StoY(bpawn) <= 0x4){  //没有过河
				if(PB90(0x31) == RCHE){
					ei.rsafe = true;
				}
			}
		}		
	}
	
	//**********************************
	// fen 2b1k4/4a4/9/3R5/4r4/2P3B1p/9/4B4/4A4/4KA3 b - - 0 0
	// fen 3ak4/9/5a3/R8/p3r4/8P/9/9/4A4/5K3 w - - 128 128
	if(RShi_num() != 0){
		if(StoY(rk) >= 0x8){
			if(StoY(bpawn) <= 0x4){
				if(BXiang_num() == 0 || (StoX(bpawn) != 0x2 && StoX(bpawn) != 0x6)){
					if(StoY(bpawn) == StoY(bche) && StoX(bpawn) == StoX(rche)){
						ei.rsafe = true;
					}
				}
			}
		}
	}
	// fen 3ak4/9/5a3/R8/p3r4/8P/9/9/4A4/5K3 w - - 128 128
	if(BShi_num() != 0){
		if(StoY(bk) <= 0x1){
			if(StoY(rpawn) >= 0x5){
				if(RXiang_num()  == 0 || (StoX(rpawn) != 0x2 && StoX(rpawn) != 0x6)){
					if(StoY(rpawn) == StoY(rche) && StoX(rpawn) == StoX(bche)){
						ei.bsafe = true;
					}
				}
			}
		}
	}
	
	// fen 4kab2/3ra4/4b4/6P2/9/9/8R/3pB4/4A4/2B1K4 b - - 9 0
	if(RShi_num() >= 1 && RXiang_num()  == 2){
		if(StoY(rk) == 0x9){
			if(StoY(bpawn) <= 0x7){
				ei.rsafe = true;
			}
		}
	}
	if(BShi_num() >= 1 && BXiang_num() == 2){
		if(StoY(bk) == 0x0){
			if(StoY(rpawn) >= 0x2){
				ei.bsafe = true;
			}
		}
	}

	if(rcan == 0 && bcan == 0){
		if((RShi_num() + RXiang_num() ) > 0 && (BShi_num() + BXiang_num()) > 0){
			RETRUN_MUL(1);
		}
	}

	// fen 3ak4/9/5a3/R8/p3r4/8P/9/9/4A4/5K3 w - - 128 128
	if(StoY(bpawn) <= 0x4){
		if(StoX(bpawn) == 0x0 || StoX(bpawn) == 0x8){
			if(StoX(rche) == StoX(bpawn) && StoY(bche) == StoY(bpawn)){
				if(RShi_num() != 0 && StoY(rk) >= 0x8){
					ei.rsafe = true;
				}
			}
		}		
	}
	if(StoY(rpawn) >= 0x5){
		if(StoX(rpawn) == 0x0 || StoX(rpawn) == 0x8){
			if(StoX(bche) == StoX(rpawn) && StoY(rche) == StoY(rpawn)){
				if(BShi_num() != 0 && StoY(bk) <= 0x1){
					ei.bsafe = true;
				}
			}
		}		
	}

	// fen 4k1b1R/9/4b4/9/6r1P/6B2/9/4B4/4Ap3/4KA3 w - - 33 33
	if(BXiang_num() == 2 && StoY(bk) == 0x0){
		if(StoY(rche) < StoY(rpawn)){
			if(StoY(bche) == StoY(rpawn) && StoX(rche) == StoX(rpawn)){
				if(StoX(rpawn) == 0x8 && PB90(0x06) == BXIANG){
					ei.bsafe = true;
				}
				if(StoX(rpawn) == 0x0 && PB90(0x02) == BXIANG){
					ei.bsafe = true;
				}
			}
		}
	}
	if(RXiang_num()  == 2 && StoY(rk) == 0x9){
		if(StoY(bche) > StoY(bpawn)){
			if(StoY(rche) == StoY(bpawn) && StoX(bche) == StoX(bpawn)){
				if(StoX(bpawn) == 0x8 && PB90(0x57) == RXIANG){
					ei.rsafe = true;
				}
				if(StoX(bpawn) == 0x0 && PB90(0x53) == RXIANG){
					ei.rsafe = true;
				}
			}
		}
	}

	// fen 4kab2/3P3R1/9/9/6b2/9/3r2p2/3AB4/4A4/2B1K4 b - - 26 26
	if(BShi_num() >= 1 && BXiang_num() >= 1){
		if(PB90(0x04) == BKING 
			&& StoY(rche) == StoY(rpawn) && StoX(bche) == StoX(rpawn)){
			if(StoX(rpawn) <= 0x4 && StoX(rche) > 0x4){
				if(PB90(0x05) == BSHI){
					ei.bsafe = true;
				}
			}
			if(StoX(rpawn) >= 0x4 && StoX(rche) < 0x4){
				if(PB90(0x03) == BSHI){
					ei.bsafe = true;
				}
			}
		}
	}
	if(RShi_num() >= 1 && RXiang_num()  >= 1){
		if(PB90(0x55) == RKING 
			&& StoY(bche) == StoY(bpawn) && StoX(rche) == StoX(bpawn)){
			if(StoX(bpawn) <= 0x4 && StoX(bche) > 0x4){
				if(PB90(0x56) == RSHI){
					ei.rsafe = true;
				}
			}
			if(StoX(bpawn) >= 0x4 && StoX(bche) < 0x4){
				if(PB90(0x54) == RSHI){
					ei.rsafe = true;
				}
			}
		}
	}

	// fen 2bk2b2/4a4/3a5/4RP3/9/9/9/9/3p2r2/4KA3 w - - 120 120
	if(StoY(bpawn) == 0x8 && StoY(rpawn) == 0x3 && StoY(bche) == 0x8
		&& PB90(0x55) == RKING && StoY(rche) == StoY(rpawn)
		&& StoX(bpawn) == StoX(rche)){
			if(StoX(bpawn) < 0x4 && PB90(0x56) == RSHI){
				if(StoX(rpawn) > 0x4){
					ei.rsafe = true;
				}
			}
			if(StoX(bpawn) > 0x4 && PB90(0x54) == RSHI){
				if(StoX(rpawn) < 0x4){
					ei.rsafe = true;
				}
			}
	}

	// fen 2bk2b2/4a4/3a5/4RP3/9/9/9/9/3p2r2/4KA3 w - - 120 120
	// fen 2bk2b2/4a4/3a5/3R1P3/9/9/9/9/3p2r2/4KA3 b
	if(StoY(rpawn) == 0x1 && StoY(bpawn) == 0x6 && StoY(rche) == 0x1
		&& PB90(0x04) == BKING && StoY(bche) == StoY(bpawn)
		&& StoX(rpawn) == StoX(bche)){
			if(StoX(rpawn) < 0x4 && PB90(0x05) == BSHI){
				if(StoX(bpawn) > 0x4){
					ei.bsafe = true;
				}
			}
			if(StoX(rpawn) > 0x4 && PB90(0x03) == BSHI){
				if(StoX(bpawn) < 0x4){
					ei.bsafe = true;
				}
			}
	}


	// fen 3ak4/4a4/9/2P6/9/8r/9/B1R2A3/5p3/4K4 w - - 18 18
	if(RShi_num() >= 1 && RXiang_num()  >= 1){
		if(StoY(bpawn) >= 0x8 && StoY(rk) >= 0x8){
			if(StoY(rpawn) >= 0x3){
				if(StoX(bpawn) > 0x4 && PB90(0x44) == RSHI && StoX(rche) < 0x4){
					ei.rsafe = true;  
				}
				if(StoX(bpawn) < 0x4 && PB90(0x42) == RSHI && StoX(rche) > 0x4){
					ei.rsafe = true;  
				}
			}
		}
	}
	// fen 3ak4/4a4/9/2P6/9/8r/9/B1R2A3/5p3/4K4 w - - 18 18
	if(BShi_num() >= 1 && BXiang_num() >= 1){
		if(StoY(rpawn) <= 0x1  && StoY(bk) <= 0x1){
			if(StoY(bpawn) <= 0x6){
				if(StoX(rpawn) > 0x4 && PB90(0x17) == BSHI && StoX(bche) < 0x4){
					ei.bsafe = true;  
				}
				if(StoX(rpawn) < 0x4 && PB90(0x15) == BSHI && StoX(bche) > 0x4){
					ei.bsafe = true;  
				}
			}
		}
	}

	// fen 5a3/4k4/4b4/2R6/9/2P3B2/4r3p/9/4A4/4KAB2 w - - 1 1
    if(BShi_num() >= 1 && BXiang_num() >= 1){
		if(rcan == 0){
			ei.bsafe = true;
		}
		if(PB90(0x16) == BXIANG && StoY(rpawn) >= 0x5){
			if(StoX(rpawn) == 0x2 || StoX(rpawn) == 0x6){
				ei.bsafe = true;
			}
		}
	}
	if(RShi_num() >= 1 && RXiang_num()  >= 1){
		if(bcan == 0){
			ei.rsafe = true;
		}
		if(PB90(0x43) == RXIANG && StoY(bpawn) <= 0x4){
			if(StoX(bpawn) == 0x2 || StoX(bpawn) == 0x6){
				ei.rsafe = true;
			}
		}
	}

	// fen 4k1b2/9/4b4/8R/6p1P/6B2/8r/4B4/4A4/3AK4 w - - 2 2
	if(BXiang_num() == 2 && StoY(bk) == 0x0 && StoY(rche) < StoY(bche)){
		if(StoX(bche) == StoX(rche) && isstrRpawn){
			if(PB90(0x06) == BXIANG && StoX(rche) == 0x8){
				ei.bsafe = true;
			}
			if(PB90(0x02) == BXIANG && StoX(rche) == 0x0){
				ei.bsafe = true;
			}
		}
	}
	if(RXiang_num()  == 2 && StoY(rk) == 0x9 && StoY(bche) > StoY(rche)){
		if(StoX(bche) == StoX(rche) && isstrBpawn){
			if(PB90(0x57) == RXIANG && StoX(bche) == 0x8){
				ei.rsafe = true;
			}
			if(PB90(0x53) == RXIANG && StoX(bche) == 0x0){
				ei.rsafe = true;
			}
		}
	}


	// fen 4k4/4a4/4b4/3P5/1r7/9/9/4B4/2p1A4/3RKAB2 w - - 95 95
	if(BShi_num() >= 1 && BXiang_num() >= 1 && PB90(0x04) == BKING){
		if(PB90(0x0D) == BSHI && PB90(0x16) == BXIANG){
			if(StoY(rpawn) >= 0x3){
				ei.bsafe = true;
			}
		}

		// fen 3a5/3P1k3/b3ba3/9/9/4r4/1R2p4/9/4A4/4K1B2 w - - 126 126
		if(XYtoS(StoX(rche),StoY(bche)) == rpawn && StoY(rpawn) > 0x2){
			ei.bsafe = true;
		}
	}
	// fen 4k4/4a4/4b4/3P5/1r7/9/9/4B4/2p1A4/3RKAB2 w - - 95 95
	if(RShi_num() >= 1 && RXiang_num()  >= 1 && PB90(0x55) == RKING){
		if(PB90(0x4C) == RSHI && PB90(0x43) == RXIANG){
			if(StoY(bpawn) <= 0x6){
				ei.rsafe = true;
			}
		}

		// fen 3a5/3P1k3/b3ba3/9/9/4r4/1R2p4/9/4A4/4K1B2 w - - 126 126
		if(XYtoS(StoX(bche),StoY(rche)) == bpawn && StoY(bpawn) < 0x7){
			ei.rsafe = true;
		}
	}

	// fen 4kab1r/4a4/b8/6P2/9/5R2p/9/4B4/9/4K1B2 w - - 120 120
	if(RXiang_num()  == 2 && StoY(rk) >= 0x8 && StoY(bpawn) != 0x8){
		if(StoX(bpawn) == 0x0 || StoX(bpawn) == 0x8){
			if(StoY(rche) == StoY(bpawn)){
				ei.rsafe = true;
			}
		}
	}
	// fen 4kab1r/4a4/b8/6P2/9/5R2p/9/4B4/9/4K1B2 w - - 120 120
	if(BXiang_num() == 2 && StoY(bk) <= 0x1 && StoY(rpawn) != 0x1){
		if(StoX(rpawn) == 0x0 || StoX(rpawn) == 0x8){
			if(StoY(bche) == StoY(rpawn)){
				ei.bsafe = true;
			}
		}
	}

	// fen 9/4k4/4b4/9/9/P2R5/9/r3B2p1/4A4/3K1AB2 w - - 1 1
	if(ei.rsafe){
		if((BXiang_num() ) >= 1 && StoY(bk) <= 0x1){
			if(StoY(rpawn) >= 0x5 && StoX(bche) == StoX(rpawn) 
				&&  (StoY(rche) == StoY(rpawn) || StoX(rche) == StoX(rpawn))){
				if(StoX(rpawn) == 0x0 || StoX(rpawn) == 0x8){
					RETRUN_MUL(2);
				}
			}
		}
	}
	
	// fen 9/4k4/4b4/9/9/P2R5/9/r3B2p1/4A4/3K1AB2 w - - 1 1
	if(ei.bsafe){
		if((RXiang_num()  ) >= 1 && StoY(rk) >= 0x8){
			if(StoY(bpawn) <= 0x4 && StoX(rche) == StoX(bpawn)
				&& (StoY(bche) == StoY(bpawn) || StoX(bche) == StoX(bpawn))){
				if(StoX(bpawn) == 0x0 || StoX(bpawn) == 0x8){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 5k3/4P4/5a1r1/9/9/9/5R3/9/3KA1p2/5A3 w - - 0 0
	if(RShi_num() == 2){
		if(PB90(0x0d) == RPAWN && StoY(bche) == 0x2 && StoY(bpawn) == 0x8){
			if(PB90(0x17) == BSHI && StoX(rk) != 0x5 && StoX(bpawn) > 0x4){
				if(StoX(rche) == 0x5 && StoX(bche) > 0x6){
					RETRUN_MUL(2);
				}
			}
			if(PB90(0x15) == BSHI && StoX(rk) != 0x3 && StoX(bpawn) < 0x4){
				if(StoX(rche) == 0x3 && StoX(bche) < 0x2){
					RETRUN_MUL(2);
				}
			}
		}
	}
	if(BShi_num() == 2){
		if(PB90(0x4c) == BPAWN && StoY(rche) == 0x7 && StoY(rpawn) == 0x1){
			if(PB90(0x44) == RSHI && StoX(bk) != 0x5 && StoX(rpawn) > 0x4){
				if(StoX(bche) == 0x5 && StoX(rche) > 0x6){
					RETRUN_MUL(2);
				}
			}
			if(PB90(0x42) == RSHI && StoX(bk) != 0x3 && StoX(rpawn) < 0x4){
				if(StoX(bche) == 0x3 && StoX(rche) < 0x2){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 3ak4/4a4/2P6/5r3/2b6/9/5p3/9/4A4/4KR3 w - - 0 1
	if(ei.bsafe){
		if(ei.rcan && RShi_num() >= 1 && StoY(rk) == 0x9 && PB90(0x4C) == RSHI){
			if(StoX(rche) == 0x5 && 0x3B == bpawn && StoX(bche) == 0x5){
				RETRUN_MUL(2);
			}
			if(StoX(rche) == 0x3 && 0x39 == bpawn && StoX(bche) == 0x3){
				RETRUN_MUL(2);
			}
		}
	}
	if(ei.rsafe){
		if(ei.bcan && BShi_num() >= 1 && StoY(bk) == 0x0 && PB90(0x0d) == BSHI){
			if(StoX(bche) == 0x5 && 0x20 == rpawn && StoX(rche) == 0x5){
				RETRUN_MUL(2);
			}
			if(StoX(bche) == 0x3 && 0x1e == rpawn && StoX(rche) == 0x3){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 3ak4/4a4/2P6/5r3/2bR5/9/9/3A1p3/3K5/9 b - - 0 1
	if(ei.bsafe){
		if(StoY(bpawn) >= 0x7){
			if(StoX(rk) == 0x3 && PB90(0x42) == RSHI && StoX(rche) == 0x3 && StoX(bpawn) >= 0x4){
				RETRUN_MUL(2);
			}
			if(StoX(rk) == 0x5 && PB90(0x44) == RSHI && StoX(rche) == 0x5 && StoX(bpawn) <= 0x4){
				RETRUN_MUL(2);
			}
		}
	}
	if(ei.rsafe){
		if(StoY(rpawn) <= 0x2){
			if(StoX(bk) == 0x3 && PB90(0x15) == BSHI && StoX(bche) == 0x3 && StoX(rpawn) >= 0x4){
				RETRUN_MUL(2);
			}
			if(StoX(bk) == 0x5 && PB90(0x17) == BSHI && StoX(bche) == 0x5 && StoX(rpawn) <= 0x4){
				RETRUN_MUL(2);
			}
		}
	}

	// fen 3k1a3/9/3a5/5P3/2b6/9/9/9/1p2R4/3K2Br1 w - - 120 120

	if(ei.bsafe && StoY(bche) == 0x9 && StoY(rpawn) <= 0x4){
		if(RXiang_num()  >= 1 && StoY(rk) == 0x9 && StoY(bpawn) == 0x8 && StoY(rche) == 0x8){
			if(StoX(bche) >= 0x7 && StoX(bpawn) <= 0x2 && PB90(0x57) == RXIANG){
               RETRUN_MUL(4);
			}
			if(StoX(bche) <= 0x1 && StoX(bpawn) >= 0x6 && PB90(0x53) == RXIANG){
               RETRUN_MUL(4);
			}
		}
	}
	if(ei.rsafe && StoY(rche) == 0x0 && StoY(bpawn) >= 0x5){
		if(BXiang_num() >= 1 && StoY(bk) == 0x0 && StoY(rpawn) == 0x1 && StoY(bche) == 0x1){
			if(StoX(rche) >= 0x7 && StoX(rpawn) <= 0x2 && PB90(0x06) == BXIANG){
               RETRUN_MUL(4);
			}
			if(StoX(rche) <= 0x1 && StoX(rpawn) >= 0x6 && PB90(0x02) == BXIANG){
               RETRUN_MUL(4);
			}
		}
	}

    // fen 9/4k4/4b4/4r4/2b6/8P/1p3R3/8B/4A4/2BA1K3 w - - 0 0
	if(ei.rsafe){
		if(BXiang_num() == 2 && StoY(rpawn) >= 0x5){
			if(StoX(rpawn) == 0x0 || StoX(rpawn) == 0x8){
				RETRUN_MUL(4);
			}
		}
	}
	if(ei.bsafe){
		if(RXiang_num()  == 2 && StoY(bpawn) <= 0x4){
			if(StoX(bpawn) == 0x0 || StoX(bpawn) == 0x8){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3ak4/4a4/8b/9/5P2p/5R3/9/5A3/5K3/r8 b - - 39 39
	if(ei.bsafe){
		if(StoY(rpawn) <= 0x4 && StoY(rche) == 0x5 && StoY(bpawn) <= 0x4){
			if(RShi_num() >= 1 && StoY(rk) >= 0x8 && StoX(rk) == StoX(rche)){
				RETRUN_MUL(4);
			}
		}
	}
	if(ei.rsafe){
		if(StoY(bpawn) >= 0x5 && StoY(bche) == 0x4 && StoY(rpawn) >= 0x5){
			if(BShi_num() >= 1 && StoY(bk) <= 0x1 && StoX(bk) == StoX(bche)){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4k1b2/9/3aba3/8R/9/6P1p/9/3A5/8r/3K5 b - - 137 137
	if(RShi_num() >= 1 && StoY(rk) >= 0x8){
		if(abs(StoX(bpawn) - 0x4) >= 3 && StoY(bche) > StoY(bpawn)){
			if(isstrBpawn){
				if(ei.bsafe) RETRUN_MUL(4);
			}
		}
	}

	if(BShi_num() >= 1 && StoY(bk) <= 0x1){
		if(abs(StoX(rpawn) - 0x4) >= 3 && StoY(rche) < StoY(rpawn)){
			if(isstrRpawn){
				if(ei.rsafe) RETRUN_MUL(4);
			}
		}
	}

	// fen 4k1b2/4a4/9/4RP3/9/9/3p1r3/B7B/4A4/3AK4 w - - 0 1
	if(ei.rsafe){
		if(BShi_num() >= 1 && BXiang_num() >= 1 && StoY(bk) == 0x0){
			if(StoY(rpawn) >= 0x3 && StoY(bpawn) == 0x6){
				RETRUN_MUL(4);
			}
		}
	}
	if(ei.bsafe){
		if(RShi_num() >= 1 && RXiang_num() >= 1 && StoY(rk) == 0x9){
			if(StoY(bpawn) <= 0x6 && StoY(rpawn) == 0x3){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3ak4/4a4/9/2R1P4/9/9/9/9/1p1KA1r2/9 w - - 0 1
	if(ei.bsafe){
		if(RShi_num() >= 1 && StoY(rk) >= 0x8 && StoY(rpawn) == 0x3){
			if(abs(StoX(bpawn) - 0x4) >= 3 && !IsOnSameSide(bche,bpawn)){
				RETRUN_MUL(4);
			}
		}
	}
	if(ei.rsafe){
		if(BShi_num() >= 1 && StoY(bk) <= 0x1 && StoY(bpawn) == 0x6){
			if(abs(StoX(rpawn) - 0x4) >= 3 && !IsOnSameSide(rche,rpawn)){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 2b1ka3/4a4/4b4/7P1/9/9/5p3/4R4/4AK3/6r2 b - - 0 1
	if(ei.bsafe){
       if(RShi_num() >= 1 && StoY(rk) >= 0x8 && StoY(rpawn) == 0x3){
		   if(StoY(bpawn) <= 0x6 && StoX(rche) == 0x4){
			   RETRUN_MUL(4);
		   }
	   }
	}
	if(ei.rsafe){
		if(BShi_num() >= 1 && StoY(bk) <= 0x1 && StoY(bpawn) == 0x6){
			if(StoY(rpawn) >= 0x3 && StoX(bche) == 0x4){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4k4/4a4/5a2b/5P3/2b3p2/9/9/4B3R/3r1K3/9 w - - 0 1
	if(ei.bsafe){
		if(ei.bcan == 0){
			if(RXiang_num() >= 1 && StoY(rpawn) == 0x3 && StoY(rk) >= 0x8){
				RETRUN_MUL(4);
			}
		}
	}
	if(ei.rsafe){
		if(ei.rcan == 0){
			if(BXiang_num() >= 1 && StoY(bpawn) == 0x6 && StoY(bk) <= 0x1){
				RETRUN_MUL(4);
			}
		}
	}


	// fen 2b1k4/3R1P3/2ra5/9/9/5p3/9/B8/4A4/3AK1B2 w - - 123 123
	if(StoY(rpawn) <= 0x1 && BShi_num() >= 1 && BXiang_num() >= 1 && StoY(bk) == 0x0 && StoY(bche) == 0x2){
	     if(PB90(0x15) == BSHI && StoX(rpawn) > 0x4 && StoX(rche) < 0x4
			 && StoX(bche) < 0x4){
				 if(ei.rsafe) RETRUN_MUL(4);
		 }
		 if(PB90(0x17) == BSHI && StoX(rpawn) < 0x4 && StoX(rche) > 0x4
			 && StoX(bche) > 0x4){
				 if(ei.rsafe) RETRUN_MUL(4);
		 }
	}
	if(StoY(bpawn) >= 0xb && RShi_num() >= 1 && RXiang_num()  >= 1 && StoY(rk) == 0x9 && StoY(rche) == 0x7){
	     if(PB90(0x42) == RSHI && StoX(bpawn) > 0x4 && StoX(bche) < 0x4
			 && StoX(rche) < 0x4){
				 if(ei.bsafe) RETRUN_MUL(4);
		 }
		 if(PB90(0x44) == RSHI && StoX(bpawn) < 0x4 && StoX(bche) > 0x4
			 && StoX(rche) > 0x4){
				 if(ei.bsafe) RETRUN_MUL(4);
		 }
	}


	// fen 9/4ak3/2P2r3/2R6/9/2B6/5p3/8B/4A4/4KA3 w - - 55 55
	if(ei.rsafe && StoY(bpawn) >= 0x5 && StoY(rpawn) <= 0x4){
		if(BShi_num() >= 1 && StoY(bk) <= 0x1 && IsOnSameSide(rpawn,bk) == FALSE){
			if(XYtoS(StoX(rche),StoY(bche)) == rpawn){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 9/4ak3/2P2r3/2R6/9/2B6/5p3/8B/4A4/4KA3 w - - 55 55
	if(ei.bsafe && StoY(rpawn) <= 0x4 && StoY(bpawn) >= 0x5){
		if(RShi_num() >= 1 && StoY(rk) >= 0x8 && IsOnSameSide(bpawn,rk) == FALSE){
			if(XYtoS(StoX(bche),StoY(rche)) == bpawn){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3k5/9/3aP4/9/9/9/3rp4/2R6/4A4/2B1KAB2 w - - 140 140
	if(RShi_num() >= 1 && RXiang_num()  >= 1 && StoY(rk) >= 0x8){
		if(StoY(bpawn) == StoY(bche) && StoY(rpawn) <= 0x2 && StoX(bche) == StoX(bk)){
			if(StoY(bpawn) == 0x5 || StoY(bpawn) == 0x6){
				if(StoX(bk) == 0x3 && PB90(0x15) == BSHI){
                    if(StoX(rpawn) >= 0x4) RETRUN_MUL(4);
				}
				if(StoX(bk) == 0x5 && PB90(0x17) == BSHI){
					if(StoX(rpawn) <= 0x4) RETRUN_MUL(4);
				}
			}
		}
	}
	// fen 3k5/9/3aP4/9/9/9/3rp4/2R6/4A4/2B1KAB2 w - - 140 140
	if(BShi_num() >= 1 && BXiang_num() >= 1 && StoY(bk) <= 0x1){
		if(StoY(rpawn) == StoY(rche) && StoY(bpawn) >= 0x7 && StoX(rche) == StoX(rk)){
			if(StoY(rpawn) == 0x4 || StoY(rpawn) == 0x3){
				if(StoX(rk) == 0x3 && PB90(0x42) == RSHI){
                    if(StoX(bpawn) >= 0x4) RETRUN_MUL(4);
				}
				if(StoX(rk) == 0x5 && PB90(0x44) == RSHI){
					if(StoX(bpawn) <= 0x4) RETRUN_MUL(4);
				}
			}
		}
	} 
	// fen 5kb2/1P2a4/3a5/9/9/2r6/9/3R1A3/3K1p3/9 b - - 0 1
	if(ei.bsafe){
		if(StoY(bpawn) >= 0x8){
			if(StoX(bpawn) > 0x4 && PB90(0x44) == RSHI){
				if(StoX(rk) == 0x3){
					if(PB90(0x42) == RCHE){
						RETRUN_MUL(4);
					}
					if(bit_is_set(ei.attacked_by(RCHE),Square(0x42))){
						RETRUN_MUL(4);
					}
				}
			}
			if(StoX(bpawn) < 0x4 && PB90(0x42) == RSHI){
				if(StoX(rk) == 0x5){
					if(PB90(0x44) == RCHE){
						RETRUN_MUL(4);
					}
					if(bit_is_set(ei.attacked_by(RCHE),Square(0x44))){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}
	if(ei.rsafe){
		if(StoY(rpawn) <= 0x1){
			if(StoX(rpawn) > 0x4 && PB90(0x17) == BSHI){
				if(StoX(bk) == 0x3){
					if(PB90(0x15) == BCHE){
						RETRUN_MUL(4);
					}
					if(bit_is_set(ei.attacked_by(BCHE),Square(0x15))){
						RETRUN_MUL(4);
					}
				}
			}
			if(StoX(rpawn) < 0x4 && PB90(0x15) == BSHI){
				if(StoX(bk) == 0x5){
					if(PB90(0x17) == BCHE){
						RETRUN_MUL(4);
					}
					if(bit_is_set(ei.attacked_by(BCHE),Square(0x17))){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 5k3/3P2R2/b3ba3/9/8p/9/8r/8B/4A4/3AK4 w - - 0 1
	if(ei.rsafe){
		if(StoY(rpawn) <= 0x1 && BShi_num() >= 1 && BXiang_num() == 2){
			if(StoX(rpawn) <= 0x3 && PB90(0x17) == BSHI && StoX(rche) != 0x5){
				RETRUN_MUL(4);
			}
			if(StoX(rpawn) >= 0x5 && PB90(0x15) == BSHI && StoX(rche) != 0x3){
				RETRUN_MUL(4);
			}
		}
	}
	if(ei.bsafe){
		if(StoY(bpawn) >= 0x8 && RShi_num() >= 1 && RXiang_num() == 2){
			if(StoX(bpawn) <= 0x3 && PB90(0x44) == RSHI && StoX(bche) != 0x5){
				RETRUN_MUL(4);
			}
			if(StoX(bpawn) >= 0x5 && PB90(0x42) == RSHI && StoX(bche) != 0x3){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 3k2P2/4a4/3a4b/9/9/9/5r3/4BAR1B/3p5/5K3 w - - 0 1
	if(ei.bsafe){
		if(RShi_num() >= 1 && RXiang_num() >= 1 && StoY(rk) >= 0x8){
			if(StoY(bpawn) >= 0x8 && abs(StoX(bpawn) - 0x4) >= 1){
				if(!IsOnSameSide(bpawn,rk)){
					if(StoX(bpawn) < 0x4 && PB90(0x44) == RSHI && StoX(rche) > 0x4){
						RETRUN_MUL(4);
					}
					if(StoX(bpawn) > 0x4 && PB90(0x42) == RSHI && StoX(rche) < 0x4){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	if(ei.rsafe){
		if(BShi_num() >= 1 && BXiang_num() >= 1 && StoY(bk) <= 0x1){
			if(StoY(rpawn) <= 0x1 && abs(StoX(rpawn) - 0x4) >= 1){
				if(!IsOnSameSide(rpawn,bk)){
					if(StoX(rpawn) < 0x4 && PB90(0x17) == BSHI && StoX(bche) > 0x4){
						RETRUN_MUL(4);
					}
					if(StoX(rpawn) > 0x4 && PB90(0x15) == BSHI && StoX(bche) < 0x4){
						RETRUN_MUL(4);
					}
				}
			}
		}
	}

	// fen 9/3P1k3/5a3/7R1/5rb2/2B6/6p2/9/4A4/4KAB2 w - - 0 1
	if(ei.rsafe){
		if(BShi_num() >= 1 && StoY(rpawn) <= 1 && StoY(bche) >= 3){
			if(PB90(0x17) == BSHI && StoX(bche) == 0x5 && StoX(rpawn) <= 3){
				RETRUN_MUL(4);
			}
			if(PB90(0x15) == BSHI && StoX(bche) == 0x3 && StoX(rpawn) >= 5){
				RETRUN_MUL(4);
			}
		}
	}
	if(ei.bsafe){
		if(RShi_num() >= 1 && StoY(bpawn) >= 8 && StoY(rche) <= 6){
			if(PB90(0x44) == RSHI && StoX(rche) == 0x5 && StoX(bpawn) <= 3){
				RETRUN_MUL(4);
			}
			if(PB90(0x42) == RSHI && StoX(rche) == 0x3 && StoX(bpawn) >= 5){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 2b1ka3/4a4/4b4/7P1/9/9/5p3/4R4/4AK3/6r2 b - - 0 1
	if(ei.bsafe){
		if(StoY(rpawn) == 0x3){
			if(RShi_num() >= 1 && StoY(rk) >= 0x8){
				if(StoY(bpawn) <= 0x6 && StoX(rche) == 0x4){
					RETRUN_MUL(4);
				}
			}
		}
	}
	if(ei.rsafe){
		if(StoY(bpawn) == 0x6){
			if(BShi_num() >= 1 && StoY(bk) <= 0x1){
				if(StoY(rpawn) >= 0x3 && StoX(bche) == 0x4){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 9/4k4/4b4/4R4/1r2p4/2P6/9/3A5/9/2BAK4 w - - 0 1
	if(ei.rsafe){
		if(BXiang_num() >= 1 && PB90(0x16) == BXIANG){
			if(StoY(rpawn) >= 0x5 && abs(StoX(rpawn) - 0x4) == 2){
				if(StoY(bche) == 0x4 && PB90(0x28) == BPAWN 
					&& abs(StoX(bche) - StoX(rpawn)) <= 2){
					RETRUN_MUL(4);
				}
			}
		}
	}
	if(ei.bsafe){
		if(RXiang_num() >= 1 && PB90(0x43) == RXIANG){
			if(StoY(bpawn) <= 0x4 && abs(StoX(bpawn) - 0x4) == 2){
				if(StoY(rche) == 0x5 && PB90(0x31) == RPAWN 
					&& abs(StoX(rche) - StoX(bpawn)) <= 2){
						RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 3ak4/5P3/4ba2b/3R5/9/9/9/9/3p2r2/4KA3 b - - 0 1
	if(ei.bsafe){
		if(RShi_num() >= 1 && 0x55 == rk && StoY(bche) == StoY(bpawn) && StoY(bpawn) == 0x8){
			if(StoX(rche) == StoX(bpawn)){
				if(PB90(0x0e) == RPAWN && StoX(bche) > 0x4 && PB90(0x56) == RSHI){
					RETRUN_MUL(4);
				}
				if(PB90(0x0c) == RPAWN && StoX(bche) < 0x4 && PB90(0x54) == RSHI){
					RETRUN_MUL(4);
				}
			}
		}
	}
	if(ei.rsafe){
		if(BShi_num() >= 1 && 0x04 == bk && StoY(rche) == StoY(rpawn) && StoY(rpawn) == 0x1){
			if(StoX(bche) == StoX(rpawn)){
				if(PB90(0x4d) == BPAWN && StoX(rche) > 0x4 && PB90(0x05) == BSHI){
					RETRUN_MUL(4);
				}
				if(PB90(0x4b) == BPAWN && StoX(rche) < 0x4 && PB90(0x03) == BSHI){
					RETRUN_MUL(4);
				}
			}
		}
	}

	// fen 1R7/3k1P3/3a5/9/4r4/9/9/4B4/4Ap3/2B1KA3 w - - 0 1
	if(ei.rsafe && StoY(rpawn) <= 0x1 && BShi_num() >= 1){
		if(StoX(bk) == 0x3 && StoX(rpawn) >= 0x5 && PB90(0x15) == BSHI){
			if(StoX(rche) != 0x3 && StoY(bche) >= 0x3){
				RETRUN_MUL(4);
			}
		}
		if(StoX(bk) == 0x5 && StoX(rpawn) <= 0x3 && PB90(0x17) == BSHI){
			if(StoX(rche) != 0x5 && StoY(bche) >= 0x3){
				RETRUN_MUL(4);
			}
		}
	}
	if(ei.bsafe && StoY(bpawn) >= 0x8 && RShi_num() >= 1){
		if(StoX(rk) == 0x3 && StoX(bpawn) >= 0x5 && PB90(0x42) == RSHI){
			if(StoX(bche) != 0x3 && StoY(rche) <= 0x6){
				RETRUN_MUL(4);
			}
		}
		if(StoX(rk) == 0x5 && StoX(bpawn) <= 0x3 && PB90(0x44) == RSHI){
			if(StoX(bche) != 0x5 && StoY(rche) <= 0x6){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 6R2/5k3/4Pa3/9/5r3/9/9/4B2p1/4A4/2BAK4 w - - 0 1
	if(ei.rsafe && StoX(bche) == StoX(bk) && StoY(bche) > StoY(bk) && ei.bcan >= 1) {
		if(BShi_num() >= 1 && StoY(rpawn) <= 2 && 0x0D != rpawn){
			if(StoX(rpawn) <= 0x4 && StoX(bche) == 0x5 && PB90(0x17) == BSHI){
				RETRUN_MUL(8);
			}
			if(StoX(rpawn) >= 0x4 && StoX(bche) == 0x3 && PB90(0x15) == BSHI){
				RETRUN_MUL(8);
			}
		}
	}
	if(ei.bsafe && StoX(rche) == StoX(rk) && StoY(rche) < StoY(rk) && ei.rcan >= 1) {
		if(RShi_num() >= 1 && StoY(bpawn) >= 7 && 0x4C != bpawn){
			if(StoX(bpawn) <= 0x4 && StoX(rche) == 0x5 && PB90(0x44) == RSHI){
				RETRUN_MUL(8);
			}
			if(StoX(bpawn) >= 0x4 && StoX(rche) == 0x3 && PB90(0x42) == RSHI){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4ka3/9/4ba3/2P5R/9/2B6/9/B4K3/3p5/1r7 b - - 0 1
	if (ei.rsafe) {
		if (BXiang_num() == 2 && StoY(rpawn) <= 1 && StoY(bk) != 0) {
			if (StoY(bpawn) == 0x6) {
				RETRUN_MUL(8);
			}
		}
	}
	if (ei.bsafe) {
		if (RXiang_num() == 2 && StoY(bpawn) >= 8 && StoY(rk) != 9) {
			if (StoY(rpawn) == 0x3) {
				RETRUN_MUL(8);
			}
		}
	}

	// fen 2b1k4/2P1a4/5a2b/9/9/8R/9/5K3/4A1p2/3A2r2 b - - 0 1
	if(ei.rsafe){
		if(BShi_num() == 2 && StoY(rpawn) < StoY(bk)){
			RETRUN_MUL(8);
		}
	}
	if(ei.bsafe){
		if(RShi_num() == 2 && StoY(bpawn) > StoY(rk)){
			RETRUN_MUL(8);
		}
	}

	// fen 4ka3/9/4ba3/2P6/2b6/9/9/B3B4/5pr2/3AK3R b - - 0 1
	if(ei.bsafe){
		if(RXiang_num() == 2 && RShi_num() >= 1 && 0x55 == rk){
			if(StoY(rpawn) == 0x03 && abs(StoX(rpawn) - 0x4) <= 2){
				if(StoY(bpawn) == 0x08 && StoY(rche) == 0x9){
					if(StoX(bpawn) > 0x4 && StoX(rche) > 0x4 && PB90(0x54) == RSHI){
						RETRUN_MUL(8);
					}
					if(StoX(bpawn) < 0x4 && StoX(rche) < 0x4 && PB90(0x56) == RSHI){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}
	if(ei.rsafe){
		if(BXiang_num() == 2 && BShi_num() >= 1 && 0x04 == bk){
			if(StoY(bpawn) == 0x06 && abs(StoX(bpawn) - 0x4) <= 2){
				if(StoY(rpawn) == 0x01 && StoY(bche) == 0x0){
					if(StoX(rpawn) > 0x4 && StoX(bche) > 0x4 && PB90(0x03) == BSHI){
						RETRUN_MUL(8);
					}
					if(StoX(rpawn) < 0x4 && StoX(bche) < 0x4 && PB90(0x05) == BSHI){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 2ba1k3/4a4/4b4/4P4/r8/3R5/9/3KB4/6p2/3A2B2 b - - 0 1
    if(ei.bsafe){
		if(RShi_num() >= 1 && RXiang_num() >= 1 && StoY(rk) <= StoY(bpawn)){
			RETRUN_MUL(8);
		}
	}
	if(ei.rsafe){
		if(BShi_num() >= 1 && BXiang_num() >= 1 && StoY(bk) >= StoY(rpawn)){
			RETRUN_MUL(8);
		}
	}

	// fen 2b6/3k5/bP1a5/9/9/2r6/3R5/5A2B/2p6/3A1K3 b - - 0 1
	if(ei.rsafe){
		if(BShi_num() >= 1 && BXiang_num() == 2 && StoY(bk) <= 0x1 && StoY(rpawn) <= 2){
			if(StoX(rpawn) <= 0x1 && StoX(bche) == 0x2 && StoX(bpawn) < 0x4){
				RETRUN_MUL(8);
			}
			if(StoX(rpawn) >= 0x7 && StoX(bche) == 0x6 && StoX(bpawn) > 0x4){
				RETRUN_MUL(8);
			}
		}
	}
	if(ei.bsafe){
		if(RShi_num() >= 1 && RXiang_num() == 2 && StoY(rk) >= 0x8 && StoY(bpawn) >= 7){
			if(StoX(bpawn) <= 0x1 && StoX(rche) == 0x2 && StoX(rpawn) < 0x4){
				RETRUN_MUL(8);
			}
			if(StoX(bpawn) >= 0x7 && StoX(rche) == 0x6 && StoX(rpawn) > 0x4){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3ak4/4a4/2P6/5r3/2b6/9/5p3/9/4A4/4KR3 w - - 0 1
	if(ei.bsafe){
		if(RShi_num() >= 1 && StoY(rk) == 0x9 && StoY(bpawn) <= 0x6){
			RETRUN_MUL(8);
		}
	}
	if(ei.rsafe){
		if(BShi_num() >= 1 && StoY(bk) == 0x0 && StoY(rpawn) >= 0x3){
			RETRUN_MUL(8);
		}
	}

	// fen 3ak4/4a4/4P4/9/9/2R6/3r5/3A5/1p1K5/9 b - - 0 1
	if(ei.bsafe){
		if(RShi_num() >= 1 && StoY(rk) >= 0x8 && StoY(rpawn) > StoY(bk)){
			if(abs(StoX(bpawn) - 0x4) >= 3 ){
				RETRUN_MUL(8);
			}
		}
	}
	if(ei.rsafe){
		if(BShi_num() >= 1 && StoY(bk) <= 0x1 && StoY(bpawn) < StoY(rk)){
			if(abs(StoX(rpawn) - 0x4) >= 3 ){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 2ba4r/9/3k5/p8/9/9/R7P/3AB4/4K4/6B2 w - - 0 1
	if(ei.rsafe){
		if(StoY(rpawn) >= 0x5 && abs(StoX(rpawn) - 0x4) == 4 && StoY(rche) == StoY(rpawn)){
			if(BShi_num() >= 1 && BXiang_num() >= 1){
				if(bit_is_set(ei.attacked_by(BCHE),rpawn)){
					RETRUN_MUL(8);
				}
			}
		}
	}
	if(ei.bsafe){
		if(StoY(bpawn) <= 0x4 && abs(StoX(bpawn) - 0x4) == 4 && StoY(bche) == StoY(bpawn)){
			if(RShi_num() >= 1 && RXiang_num() >= 1){
				if(bit_is_set(ei.attacked_by(RCHE),bpawn)){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 3ak4/3P1R3/4b3b/9/9/6B2/3rp4/9/4A4/2BAK4 b - - 0 1
	if(ei.rsafe){
		if(StoY(bpawn) == 0x6 && BShi_num() >= 1 && bk == 0x4 && BXiang_num() == 2){
			if(StoX(bche) == StoX(rpawn) || StoX(bpawn) == StoX(rk)){
				RETRUN_MUL(8);
			}
		}
	}
	if(ei.bsafe){
		if(StoY(rpawn) == 0x3 && RShi_num() >= 1 && rk == 0x55 && RXiang_num() == 2){
			if(StoX(rche) == StoX(bpawn) || StoX(rpawn) == StoX(bk)){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 9/4ak3/9/5P3/4r4/9/8R/4B4/4A2p1/2B1KA3 b - - 0 1
	if(ei.rsafe && ei.bcan && StoY(bk) <= 0x1){
		if(BShi_num() >= 1 && StoX(bche) == 0x4 && StoY(rpawn) >= 0x3){
			RETRUN_MUL(8);
		} 
	}
	if(ei.bsafe && ei.rcan && StoY(rk) >= 0x8){
		if(RShi_num() >= 1 && StoX(rche) == 0x4 && StoY(bpawn) <= 0x6){
			RETRUN_MUL(8);
		} 
	}

	// fen 9/3k5/3a4b/3R1P3/1r7/9/4p4/9/9/2BAKAB2 b - - 0 1
	if(ei.rsafe){
		if(BShi_num() >= 1 && BXiang_num() >= 1){
			if(StoY(bpawn) == 0x6 && StoY(rpawn) >= 0x3 && StoY(bk) <= 1){
				RETRUN_MUL(8);
			}
		}
	}
	if (ei.bsafe){
		if (RShi_num() >= 1 && RXiang_num() >= 1){
			if (StoY(rpawn) == 0x3 && StoY(bpawn) <= 0x6 && StoY(rk) >= 8){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 9/3k5/4b4/2R6/p8/2P6/9/B8/4K4/3r1AB2 b - - 0 1
	if (ei.rsafe){
		if (BXiang_num() >= 1 && ei.rcan == 0){
			RETRUN_MUL(8);
		}
	}
	if (ei.bsafe){
		if (RXiang_num() >= 1 && ei.bcan == 0){
			RETRUN_MUL(8);
		}
	}
}


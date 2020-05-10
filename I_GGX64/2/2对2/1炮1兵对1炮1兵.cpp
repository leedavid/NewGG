#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"


void m_MT_PaoPawn_To_PaoPawn(typePOS &POSITION, EvalInfo &ei){
  
	Square rk = RKpos();
	Square bk = BKpos();
	Square rpawn = S90_from_piecelist(POSITION,RPAWN,0);
	Square bpawn = S90_from_piecelist(POSITION,BPAWN,0);
	int rpao  = S90_from_piecelist(POSITION,RPAO,0);
	int bpao  = S90_from_piecelist(POSITION,BPAO,0);

	int rcan = ei.rcan;
	int bcan = ei.bcan;
	// fen 4kc3/9/b2a5/C8/4p4/6B2/4P4/5A3/4A4/2BK5 w - - 0 0
	if(rcan == 0 && (BShi_num() + BXiang_num()) >= 2 && StoY(bk) <= 1){
		ei.bsafe = TRUE;
	}
	if(bcan == 0 && (RShi_num() + RXiang_num()) >= 2 && StoY(rk) >= 8){
		ei.rsafe = TRUE;
	}

	// fen 9/4P4/5k3/9/9/2B3B2/9/3A1A3/4K1c2/C1p6 w - - 1 1
	if((RShi_num() + RXiang_num()) >= 2 && StoY(rpawn) >= 0x3 && StoY(rpawn) <= 0x4){
        ei.rsafe = TRUE;
	}

	if((BShi_num() + BXiang_num()) >= 2 && StoY(bpawn) <= 0x6 && StoY(bpawn) >= 0x5){
		ei.bsafe = TRUE;
	}

	if(BShi_num() == 2 && StoY(bk) <= 1){
		ei.bsafe = TRUE;
	}

	if(RShi_num() == 2 && StoY(rk) >= 8){
		ei.rsafe = TRUE;
	}

	if(BShi_num() == 0 && (RShi_num() + RXiang_num()) >= 2){
		ei.rsafe = TRUE;
	}
	if(RShi_num() == 0 && (BShi_num() + BXiang_num()) >= 2){
		ei.bsafe = TRUE;
	}

	// fen 9/3Pa4/4k3b/5c3/6b2/9/9/3ABK3/3C5/4p4 w - - 0 1
	if (StoY(bpawn) == 0x9){
		if ((RShi_num() + RXiang_num()) >= 1 && StoY(rk) != 0x9){
			ei.rsafe = TRUE;
		}
	}
	if (StoY(rpawn) == 0x0){
		if ((BShi_num() + BXiang_num()) >= 1 && StoY(bk) != 0x0){
			ei.bsafe = TRUE;
		}
	}


	// fen 9/5k3/4P4/9/9/2B6/5c3/9/4p2C1/5KB2 b - - 0 0
	//把炮拉住就赢了
	if(RShi_num() == 0 && StoY(rpawn) <= 0x2 
		&& abs(StoY(rpawn) - StoY(bk)) <= 1 && StoX(bpao) !=  StoX(bk)){
			ei.bsafe = TRUE;
	}

	if(BShi_num() == 0 && StoY(bpawn) >= 0x7 
		&& abs(StoY(bpawn) - StoY(rk)) <= 1 && StoX(rpao) !=  StoX(rk)){
	      ei.rsafe = TRUE;
	}
	
	// fen 9/5k3/4P4/9/9/2B6/5c3/9/4p2C1/5KB2 b - - 0 0
	//把炮拉住就赢了
	if((RShi_num() + RXiang_num()) >= 2){
		if(BShi_num() == 0 && BXiang_num() == 0 && StoY(bpawn) >= 0x7){
			if(StoY(rpawn) > StoY(bk) && StoX(rpawn) == 0x4){
				if(StoX(bpao) == StoX(bk) && StoX(bpao) == StoX(rk)){
					ei.evscore += 96;
					if(StoX(bpawn) != 0x4){
						ei.evscore += 96;
						if(StoY(rpao) > StoY(rk)){
							ei.evscore += 96;
						}
					}
					if(StoY(rk) <= StoY(bpawn)){
						ei.evscore += 96;
					}
				}
			}
		}
	}// fen 9/5k3/4P4/9/9/2B6/5c3/9/7C1/5KB2 b
	if((BShi_num() + BXiang_num()) >= 2){
		if(RShi_num() == 0 && RXiang_num() == 0 && StoY(rpawn) <= 0x2){
			if(StoY(bpawn) < StoY(rk) && StoX(bpawn) == 0x4){
				if(StoX(rpao) == StoX(rk) && StoX(rpao) == StoX(bk)){
					ei.evscore -= 96;
					if(StoX(rpawn) != 0x4){
						ei.evscore -= 96;
						if(StoY(bpao) < StoY(bk)){
							ei.evscore -= 96;
						}
					}
					if(StoY(bk) >= StoY(rpawn)){
						ei.evscore -= 96;
					}
				}
			}
		}
	}

	// fen 3a1k3/3P5/4c4/9/2b3b2/2B6/9/4p4/5C3/2BK5 b - - 0 0
	if(BShi_num() == 1){
		if(PB90(0x03) == BSHI && PB90(0x0C) == RPAWN){
			ei.rsafe = TRUE;
		}
		if(PB90(0x05) == BSHI && PB90(0x0E) == RPAWN){
			ei.rsafe = TRUE;
		}
	}
	if(RShi_num() == 1){
		if(PB90(0x54) == RSHI && PB90(0x4B) == BPAWN){
			ei.bsafe = TRUE;
		}
		if(PB90(0x56) == RSHI && PB90(0x4D) == BPAWN){
			ei.bsafe = TRUE;
		}
	}

	// fen 4P4/4ak3/3aC4/7c1/9/6B2/9/9/5p3/4K4 w - - 0 1
	if(ei.bsafe == TRUE){
		if(BXiang_num() == 0 && RXiang_num() >= 1){
			if(StoY(bpawn) >= 0x7 && abs(StoY(rk) - StoY(bpawn)) <= 1){
				if(StoX(rk) == 0x4){
					RETRUN_MUL(4);
				}
			}
		}
	}
	if(ei.rsafe == TRUE){
		if(RXiang_num() == 0 && BXiang_num() >= 1){
			if(StoY(rpawn) <= 0x2 && abs(StoY(bk) - StoY(rpawn)) <= 1){
				if(StoX(bk) == 0x4){
					RETRUN_MUL(4);
				}
			}
		}
	}


	// fen 9/3P5/b2ak4/2C6/9/9/9/5K3/4p4/4c4 b - - 102 102
	if(RShi_num() == 0 && StoY(rpawn) <= 0x4 
		&& StoY(rpawn) != 0 && BShi_num() <= 1){
		if(StoY(bpawn) > StoY(rk)){
			if(StoY(bpao) >= 0x5){
				RETRUN_MUL(4);  // 炮要回家才行
			}
		}
	}
	if(BShi_num() == 0 && StoY(bpawn) >= 0x5 
		&& StoY(bpawn) != 9 && RShi_num() <= 1){
		if(StoY(rpawn) < StoY(bk)){
			if(StoY(rpao) <= 0x4){
				RETRUN_MUL(4);  // 炮要回家才行
			}
		}
	}

	// fen 3k5/2P1a1c1C/3ab3b/9/9/9/9/9/4p4/3K5 w - - 132 132
	//炮打着兵
	if(ei.bsafe == TRUE){
		if(abs(StoY(rk) - StoY(bpawn)) <= 1 && StoY(bpawn) >= 0x7){
			if(StoY(rpawn) == 0x1 && StoY(rpao) == 0x1){
				if(StoX(rk) == 0x3){
					if(StoX(rpawn) <= 0x3 && StoX(rpao) >= 0x6){
						RETRUN_MUL(4);
					}
				}
				if(StoX(rk) == 0x5){
					if(StoX(rpawn) >= 0x5 && StoX(rpao) <= 0x2){
						RETRUN_MUL(4);
					}
				}
			}
		}
		// fen 9/2P1ak1C1/4ba3/5c3/9/9/9/3K5/9/2p6 b - - 0 1
		if(StoY(bpawn) == 0x9 && StoY(rk) != 0x9){
			if(ei.rcan >= 1){
				RETRUN_MUL(4);
			}
		}
	}
	if(ei.rsafe == TRUE){
		if(abs(StoY(bk) - StoY(rpawn)) <= 1 && StoY(rpawn) <= 0x2){
			if(StoY(bpawn) == 0x8 && StoY(bpao) == 0x8){
				if(StoX(bk) == 0x3){
					if(StoX(bpawn) <= 0x3 && StoX(bpao) >= 0x6){
						RETRUN_MUL(4);
					}
				}
				if(StoX(bk) == 0x5){
					if(StoX(bpawn) >= 0x5 && StoX(bpao) <= 0x2){
						RETRUN_MUL(4);
					}
				}
			}
		}
		// fen 9/2P1ak1C1/4ba3/5c3/9/9/9/3K5/9/2p6 b - - 0 1
		if(StoY(rpawn) == 0x0 && StoY(bk) != 0x0){
			if(ei.bcan >= 1){
				RETRUN_MUL(4);
			}
		}
	}
	// fen 3k5/4a4/5a3/4P4/2b6/8C/9/4p4/5K2c/9 b - - 0 1
	if(ei.bsafe == TRUE){
		if(StoY(rpawn) == 0x3){
			if(StoY(bpawn) >= 0x7 && abs(StoY(rk) - StoY(bpawn)) <= 1){
				RETRUN_MUL(4);
			}
		}
	}
	if(ei.rsafe == TRUE){
		if(StoY(bpawn) == 0x6){
			if(StoY(rpawn) <= 0x2 && abs(StoY(bk) - StoY(rpawn)) <= 1){
				RETRUN_MUL(4);
			}
		}
	}
	
	if(ei.rsafe){
		// fen 4k4/9/3Cb4/6P2/2b6/2B6/4c4/3A5/5p3/2BAK4 b - - 0 1
       if(BXiang_num() == 2 || (BXiang_num() >= 1 && StoY(bpawn) == 0x6)){
		   if(RShi_num() == 0){
			   RETRUN_MUL(4);
		   }
		   if(StoY(bk) == 0x4 && PB90(0x0d) == rpawn){
		   }
		   else{
			    RETRUN_MUL(4);
		   }
	   }
	   // fen 3k5/9/b8/4P4/3c5/6B2/2p6/3ABK3/4A4/2C6 w - - 0 1
	}
	if(ei.bsafe){
		// fen 4k4/9/3Cb4/6P2/2b6/2B6/4c4/3A5/5p3/2BAK4 b - - 0 1
		if(RXiang_num() == 2 || (RXiang_num() >= 1 && StoY(rpawn) == 0x3) ){
			if(BShi_num() == 0){
				RETRUN_MUL(4);
			}
			if(StoY(rk) == 0x9 && PB90(0x4c) == bpawn){
			}
			else{
				RETRUN_MUL(4);
			}
		}
	}

	// fen 9/3Pa4/4k3b/5c3/6b2/9/9/3ABK3/3C5/4p4 w - - 0 1
	if (ei.rsafe){
		if (StoY(rpawn) < StoY(bk)){
			if ((BShi_num() + BXiang_num()) >= 2){
				if (RShi_num() <= 1){
					RETRUN_MUL(4);
				}
				RETRUN_MUL(8);
			}
		}
	}
	if (ei.bsafe){
		if (StoY(bpawn) > StoY(rk)){
			if ((RShi_num() + RXiang_num()) >= 2){
				if (BShi_num() <= 1){
					RETRUN_MUL(4);
				}
				RETRUN_MUL(8);
			}
		}
	}

	// fen 9/3k5/9/4P4/C8/5p3/c8/3A5/4A4/2B2K3 w - - 0 1
	if (ei.rsafe){
		if (StoY(bpawn) == 0x5 || StoY(bpawn) == 0x6){
			if (StoY(rpao) <= 0x5){
				RETRUN_MUL(8);
			}
		}
	}
	if (ei.bsafe){
		if (StoY(rpawn) == 0x4 || StoY(rpawn) == 0x3){
			if (StoY(bpao) >= 0x4){
				RETRUN_MUL(8);
			}
		}
	}


	// fen 3k1ab2/1c7/9/4P4/9/9/4C4/4p4/9/4K4 w - - 0 1
	if(ei.bsafe){
		if(rpawn == 0x28 || rpawn == 0x1f){
			if(StoX(rpao) == 0x4 && StoY(rpao) > StoY(rpawn)){
				if(StoX(rk) == 0x4){
					RETRUN_MUL(8);
				}
			}
		}
	}
	if(ei.rsafe){
		if(bpawn == 0x31 || bpawn == 0x3a){
			if(StoX(bpao) == 0x4 && StoY(bpao) < StoY(bpawn)){
				if(StoX(bk) == 0x4){
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 1C2k4/4a1c2/2P1b4/9/2b6/9/9/2p6/3K5/2B6 w - - 0 1
	if (ei.bsafe){
		if (BShi_num() <= 1 && RXiang_num() >= 1 && StoY(rpawn) >= 1){
			if (StoY(bpawn) >= 0x7 && StoY(rk) <= 0x8){
				if (StoX(bpawn) <= 0x2 && StoX(rk) == 0x3){
					if (StoX(rpawn) <= 0x3 && StoX(rpao) <= 0x1){
						RETRUN_MUL(8);
					}
				}
				if (StoX(bpawn) >= 0x6 && StoX(rk) == 0x5){
					if (StoX(rpawn) >= 0x5 && StoX(rpao) >= 0x7){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}
	if (ei.rsafe){
		if (RShi_num() <= 1 && BXiang_num() >= 1 && StoY(bpawn) <= 8){
			if (StoY(rpawn) <= 0x2 && StoY(bk) >= 0x1){
				if (StoX(rpawn) <= 0x2 && StoX(bk) == 0x3){
					if (StoX(bpawn) <= 0x3 && StoX(bpao) <= 0x1){
						RETRUN_MUL(8);
					}
				}
				if(StoX(rpawn) >= 0x6 && StoX(bk) == 0x5){
					if (StoX(bpawn) >= 0x5 && StoX(bpao) >= 0x7){
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 9/4k1P2/4b4/7c1/6b2/9/4p2C1/9/3K5/9 b - - 0 1
	if(ei.bsafe){
		if(BShi_num() == 0 && StoY(rpawn) >= 0x1){
			RETRUN_MUL(8);
		}
	}
	if(ei.rsafe){
		if(RShi_num() == 0 && StoY(bpawn) <= 0x8){
			RETRUN_MUL(8);
		}
	}

	// fen 4ka3/9/8b/4P4/9/9/9/9/cC2A1p2/5K3 w - - 0 1


	// fen 9/3Ca1P2/4bk3/4c4/9/9/9/9/3p5/3AKA3 b - - 0 1
	if(ei.rsafe){
		if(BShi_num() >= 1 && BXiang_num() >= 1){
			RETRUN_MUL(8);
		}
	}
	if(ei.bsafe){
		if(RShi_num() >= 1 && RXiang_num() >= 1){
			RETRUN_MUL(8);
		}
	}

	// fen 4ka3/9/8b/4P4/9/9/9/9/cC2A1p2/5K3 w - - 0 1
	if(BShi_num() >= 1 && BXiang_num() >= 1){
		if(StoY(rpawn) == 0x3){
			if(RShi_num() >= 1){
				RETRUN_MUL(8);
			}
		}
	}
	if(RShi_num() >= 1 && RXiang_num() >= 1){
		if(StoY(bpawn) == 0x6){
			if(BShi_num() >= 1){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 4ka3/9/8b/4P4/9/9/9/9/cC2A1p2/5K3 w - - 0 1
	//if(RShi_num() >= 1 && StoY())
	
}
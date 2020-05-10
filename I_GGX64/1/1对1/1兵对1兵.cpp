
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
//
//能不能和，怎样胜

//红方一个兵, 黑方一个兵, 总是和棋
void m_MT_PAWN_TO_PAWN(typePOS &POSITION, EvalInfo &ei){ //因为兵的位置分相差太大

	Square rpawn = S90_from_piecelist(POSITION, RPAWN, 0);
	Square bpawn = S90_from_piecelist(POSITION, BPAWN, 0);
	Square rk = S90_from_piecelist(POSITION, RKING, 0);
	Square bk = S90_from_piecelist(POSITION, BKING, 0);

	// fen 2b2k3/4a4/3a5/5P3/2b6/9/9/9/4p4/5K3 w - - 0 1 not he
	if(ei.rcan){
		if ((RShi_num() + RXiang_num()) >= 1){
			ei.rsafe = true;
		}
		if (StoX(rpawn) != StoX(bk)){
			ei.rsafe = true;
		}
	}
	if(ei.bcan){
		if ((BShi_num() + BXiang_num()) >= 1){
			ei.bsafe = true;
		}
		if (StoX(bpawn) != StoX(rk)){
			ei.bsafe = true;
		}
	}
	// fen 4k4/9/9/8p/9/2B3B1P/9/3A5/4A4/5K3 w - - 0 189
	if(!ei.rcan){
		ei.bsafe = true;
	}
	if(!ei.bcan){
		ei.rsafe = true;
	}

	if((RShi_num() + RXiang_num()) >= 1){
		ei.rsafe = true;
	}

	if((BShi_num() + BXiang_num()) >= 1){
		ei.bsafe = true;
	}



	// fen 9/9/4k4/5P3/9/9/9/4p4/9/4KA3 w - - 0 1
	if((BShi_num() + BXiang_num()) == 0){
        if(StoY(rpawn) > StoY(bk)){
			if(RShi_num() >= 1 && bpawn == 0x43){
				ei.bsafe = false;
			}
		}
	}
	if((RShi_num() + RXiang_num()) == 0){
		if(StoY(bpawn) < StoY(rk)){
			if(BShi_num() >= 1 && rpawn == 0x16){
				ei.rsafe = false;
			}
		}
	}

	// fen 3a1k2P/9/3a4b/9/9/9/9/5p3/3K5/9 w - - 0 1
	if(ei.bsafe){
		if(StoY(rpawn) <= 0x4){
			if(StoY(rpawn) <= 0x2 && abs(StoX(rpawn) - 0x4) <= 1){
			}
			else if (StoX(rpawn) == StoX(bk)){

			}
			else{
			    RETRUN_MUL(2);
			}
		}
	}
	if(ei.rsafe){
		if(StoY(bpawn) >= 0x5){
			if(StoY(bpawn) >= 0x7 && abs(StoX(bpawn) - 0x4) <= 1){
			}
			else if (StoX(bpawn) == StoX(rk)){
			}
			else{
				RETRUN_MUL(2);
			}
		}
	}

	// fen 9/9/5k3/9/p8/9/P8/5A3/9/2B1KA3 b - - 0 1
	if(ei.rsafe){
		if(ei.rcan == 0){
			RETRUN_MUL(4);
		}
	}
	if(ei.bsafe){
		if(ei.bcan == 0){
			RETRUN_MUL(4);
		}
	}

}



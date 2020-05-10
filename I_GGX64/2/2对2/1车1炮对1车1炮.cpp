
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"

//车炮对车炮
void m_MT_1che1pao_1che1pao(typePOS &POSITION, EvalInfo &ei){

	//int rche = S90_from_piecelist(POSITION,RCHE,0);
	//int rpao = S90_from_piecelist(POSITION,RPAO,0);
	//int bche = S90_from_piecelist(POSITION,BCHE,0);
	//int bpao = S90_from_piecelist(POSITION,BPAO,0);

	// fen 5k3/4a4/9/9/1R1c3r1/2B6/9/9/9/1C2K1B2 w - - 189 189
	int rche = S90_from_piecelist(POSITION,RCHE,0);
	int rpao = S90_from_piecelist(POSITION,RPAO,0);
	int bche = S90_from_piecelist(POSITION,BCHE,0);
	int bpao = S90_from_piecelist(POSITION,BPAO,0);
	Square rk = RKpos();
	Square bk = BKpos();

	if ((RShi_num() + RXiang_num()) >= 3 && StoY(rk) >= 8){
		ei.rsafe = true;
	}
	if ((BShi_num() + BXiang_num()) >= 3 && StoY(bk) <= 1){
		ei.bsafe = true;
	}


	// fen 9/3k5/3a5/9/9/6B2/9/9/r2c1R3/3CK4 w - - 151 151 
	//如果一方只有一仕,一方只有一相,
	if((BShi_num() + BXiang_num()) == 1 && (RShi_num() + RXiang_num()) == 1){
		RETRUN_MUL(2);
	}

	if((BShi_num() + BXiang_num()) >= 3 && (RShi_num() + RXiang_num()) >= 3){
		RETRUN_MUL(4);
	}

	if((BShi_num() + BXiang_num()) >= 2 && (RShi_num() + RXiang_num()) >= 2){
		RETRUN_MUL(4);
	}

	// fen 5k3/2C1R4/7c1/9/9/9/9/8B/4K4/5rB2 w - - 0 151
	if(RShi_num() == 0 && BShi_num() == 0){
        RETRUN_MUL(4);
	}
	// fen 3k5/6R2/c4a3/9/9/9/9/3AB4/4A4/1rC1K1B2 w - - 0 1
	if (ei.rsafe){
		if ((BShi_num() + BXiang_num()) >= 1 && StoY(bk) <= 1){
			if (StoY(bpao) <= 2){
				RETRUN_MUL(4);
			}
		}
	}
	if (ei.bsafe){
		if ((RShi_num() + RXiang_num()) >= 1 && StoY(rk) >= 8){
			if (StoY(rpao) >= 7){
				RETRUN_MUL(4);
			}
		}
	}

	// 如果一方的炮在车后面,而且和将在一线,就要减分
	if((RShi_num() + RXiang_num()) <= 1){
		if(StoX(rche) == StoX(rpao) && StoX(rche) == StoX(rk)){
			if(StoY(rpao) <= StoY(rk) && StoY(rche) < StoY(rpao)){
				RETRUN_MUL(8);
			}
		}
	}

	if((BShi_num() + BXiang_num()) <= 1){
		if(StoX(bche) == StoX(bpao) && StoX(bche) == StoX(bk)){
			if(StoY(bpao) >= StoY(bk) && StoY(bche) > StoY(bpao)){
				RETRUN_MUL(8);
			}
		}		
	}

	// fen 3k5/4R4/9/9/9/3r5/7c1/B4A2B/4A1C2/4K4 b - - 0 1
    if((RShi_num() + RXiang_num()) >= 2){
		if(StoX(bk) == 0x3 && StoX(bche) == 0x3 && StoY(bche) > StoY(bk)){
			if(StoX(rpao) > 0x4){
				RETRUN_MUL(8);
			}
		}
		if(StoX(bk) == 0x5 && StoX(bche) == 0x5 && StoY(bche) > StoY(bk)){
			if(StoX(rpao) < 0x4){
				RETRUN_MUL(8);
			}
		}
	}
	if((BShi_num() + BXiang_num()) >= 2){
		if(StoX(rk) == 0x3 && StoX(rche) == 0x3 && StoY(rche) < StoY(rk)){
			if(StoX(bpao) > 0x4){
				RETRUN_MUL(8);
			}
		}
		if(StoX(rk) == 0x5 && StoX(rche) == 0x5 && StoY(rche) < StoY(rk)){
			if(StoX(bpao) < 0x4){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3c3C1/4a4/3a1k3/9/5rb2/9/9/3A3R1/9/3K5 w - - 0 1
	if((RShi_num() >= 1 && StoY(rk) >= 0x8)
		|| ((RShi_num() + RXiang_num()) >= 2)){
			if((BShi_num() >= 1 && StoY(bk) <= 0x1)
				|| ((BShi_num() + BXiang_num()) >= 2)){
					RETRUN_MUL(8);
			}
	}
}
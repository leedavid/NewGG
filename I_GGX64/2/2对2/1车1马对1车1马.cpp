
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"


//车马对车马
// fen 2bak4/4a4/9/9/6b2/9/5r1n1/7R1/3NA4/3AK4 b - - 155 155
void m_MT_1che1ma_1che1ma(typePOS &POSITION, EvalInfo &ei){

	Square rk = RKpos();
	Square bk = BKpos();

	Square rma = S90_from_piecelist(POSITION,RMA,0);
	Square bma = S90_from_piecelist(POSITION,BMA,0);

	Square rche = S90_from_piecelist(POSITION,RCHE,0);
	Square bche = S90_from_piecelist(POSITION,BCHE,0);

	if(RShi_num() == 2){
		if(StoY(rk) == 0x9){
			ei.rsafe = TRUE;
		}
		if(StoY(rk) >= 0x8){
			if(0x42 == rma || 0x44 == rma){
				ei.rsafe = TRUE;
			}
		}
	}
	if(RXiang_num() == 2){
		if(StoY(rk) >= 8){
			ei.rsafe = TRUE;
		}
	}
	// fen 5a3/3ka1N2/3n5/9/9/3R5/9/4BA3/3KA4/1r4B2 b - - 128 128
	if(BShi_num() == 2){
		if(StoY(bk) == 0x0){
			ei.bsafe = TRUE;
		}
		if(StoY(bk) <= 0x1){
			if(0x15 == bma || 0x17 == bma){
				ei.bsafe = TRUE;
			}
		}
	}
	if(BXiang_num() == 2){
		if(StoY(bk) <= 1){
			ei.bsafe = TRUE;
		}
	}

	// fen 3k1a3/4a4/9/3r5/2RnN4/9/9/3AK4/9/2BA2B2 b - - 0 1
	if (BShi_num() == 2 && StoY(bk) <= 0x1) {
		if (StoX(bk) == 0x3 && StoX(bche) == StoX(bk)) {
			if (!have_bit(bb_black_shi, FileBB_A[0x3]) && StoX(rma) >= 0x4) {
				ei.bsafe = TRUE;
			}
		}
		if (StoX(bk) == 0x5 && StoX(bche) == StoX(bk)) {
			if (!have_bit(bb_black_shi, FileBB_A[0x5]) && StoX(rma) <= 0x4) {
				ei.bsafe = TRUE;
			}
		}
	}

	if (RShi_num() == 2 && StoY(rk) >= 0x8) {
		if (StoX(rk) == 0x3 && StoX(rche) == StoX(rk)) {
			if (!have_bit(bb_white_shi, FileBB_A[0x3]) && StoX(bma) >= 0x4) {
				ei.rsafe = TRUE;
			}
		}
		if (StoX(rk) == 0x5 && StoX(rche) == StoX(rk)) {
			if (!have_bit(bb_white_shi, FileBB_A[0x5]) && StoX(bma) <= 0x4) {
				ei.rsafe = TRUE;
			}
		}
	}

	// fen 3ak1b2/9/3ab4/9/9/9/N4R3/9/3K5/3n4r w - - 0 1
	if(ei.bsafe){
		if(StoY(rk) == 0x8 && PB90(XYtoS(StoX(rk),9)) == BMA && StoY(bche) >= 0x8){
			// 对方马的所有步子，都被控制了
			if(!m_have_bit(_mm_andnot_si128(ei.attacked_by(WHITE),ei.attacked_by(BMA)))){
				RETRUN_MUL(4);
			}
		}
	}
	if(ei.rsafe){
		if(StoY(bk) == 0x1 && PB90(XYtoS(StoX(bk),0)) == RMA && StoY(rche) <= 0x1){
			// 对方马的所有步子，都被控制了
			if(!m_have_bit(_mm_andnot_si128(ei.attacked_by(BLACK),ei.attacked_by(RMA)))){
				RETRUN_MUL(4);
			}
		}
	}
	// fen 9/3ka4/n3r4/3N5/5R3/9/9/4BA3/4A4/2B1K4 w - - 0 1
	if(ei.rsafe){
		if(BShi_num() >= 1 && StoY(bk) <= 0x1){
			if(StoY(bche) == 0x2 && StoY(bma) == 0x2){
				RETRUN_MUL(6);
			}
		}
	}
	if(ei.bsafe){
		if(RShi_num() >= 1 && StoY(rk) >= 0x8){
			if(StoY(rche) == 0x7 && StoY(rma) == 0x7){
				RETRUN_MUL(6);
			}
		}
	}

	// fen 4k4/8R/3a4N/5r3/2n6/9/9/3AB4/9/3AK4 b - - 0 1
	if(ei.rsafe && StoY(bma) <= 0x5){ // 对方的马在守
		if(StoY(bk) <= 0x1 && (BShi_num() + BXiang_num()) >= 1){

			// fen 4k4/4a4/4b4/4r4/3RN4/8n/9/4BA3/4A4/4K1B2 w - - 0 1
			if(StoY(bk) == 0x0 && StoY(rma) >= 0x4 && (rma - 9) == bche){
				RETRUN_MUL(6);
			}
			RETRUN_MUL(8);					
		}
	}
	if(ei.bsafe && StoY(rma) >= 0x4){
		if(StoY(rk) >= 0x8 && (RShi_num() + RXiang_num()) >= 1){

			// fen 4k4/4a4/4b4/4r4/3RN4/8n/9/4BA3/4A4/4K1B2 w - - 0 1
			if(StoY(rk) == 0x9 && StoY(bma) <= 0x5 && (bma + 9) == rche){
				RETRUN_MUL(6);
			}

			RETRUN_MUL(8);
		}
	}



	// fen 3k5/9/4rn3/5R3/9/2B3N2/9/3AB4/9/3AK4 w - - 0 1
    if(ei.rsafe){
		if(StoY(bma) <= 0x4){
			ei.evscore -= 96;
		}
		if(StoX(bche) == 0x4 && StoY(rma) >= 0x3 && StoY(bk) <= 1){
			if(StoY(bche) == 0x2){
				RETRUN_MUL(8);
			}
		}
	}
	if(ei.bsafe){
		if(StoY(rma) >= 0x5){
			ei.evscore += 96;
		}
		if(StoX(rche) == 0x4 && StoY(bma) <= 0x6 && StoY(rk) >= 8){
			if(StoY(rche) == 0x7){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3k1a3/4a4/9/3r5/2RnN4/9/9/3AK4/9/2BA2B2 b - - 0 1
	if (ei.bsafe) {
		if (RXiang_num() == 2 && RShi_num() == 2) {
			if (StoY(bma) <= 0x4) {
				RETRUN_MUL(8);
			}
		}
	}
	if (ei.rsafe) {
		if (BXiang_num() == 2 && BShi_num() == 2) {
			if (StoY(rma) >= 0x5) {
				RETRUN_MUL(8);
			}
		}
	}
}


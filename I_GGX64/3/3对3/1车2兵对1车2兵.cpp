
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
#include "..\\..\\endgame\mat.h"
// fen 4kab2/4a4/4b4/9/2r1P4/p5B2/4R4/4B4/4K4/9 b - - 0 0
//马兵兵对马兵兵
void m_MT_1che2pawn_1che2pawn(typePOS &POSITION, EvalInfo &ei){

	// fen 3R5/5k3/5a3/p3r3p/9/9/P7P/4B4/4A4/4KAB2 w - - 1 1 
    //如果双方的兵都没有过河,且一方的兵在一线,与车在一线,就是和了,

	Square rpawn1 = S90_from_piecelist(POSITION,RPAWN,0);
	Square rpawn2 = S90_from_piecelist(POSITION,RPAWN,1);

	Square bpawn1 = S90_from_piecelist(POSITION,BPAWN,0);
	Square bpawn2 = S90_from_piecelist(POSITION,BPAWN,1);

	// ADD_BR
	Square bk = BKpos();
	Bitboard bmp = m_and(bb_white_pawn,LowBB[StoY(bk)]);
	ei.evscore += (count_1s(bmp) * ADD_ChePawn_To_ChePawnByShi[BShi_num()]);
	// SUB
	Square rk = RKpos();
	Bitboard ymp = m_and(bb_black_pawn,UpBB[StoY(rk)]);
	ei.evscore -= (count_1s(ymp) * ADD_ChePawn_To_ChePawnByShi[RShi_num()]);
		
	Square rche = S90_from_piecelist(POSITION,RCHE,0);
	Square bche = S90_from_piecelist(POSITION,BCHE,0);

	// fen 3a2b2/2P1k4/3rb4/6P2/9/p8/9/3A2R2/4A2p1/3K2B2 b - - 0 1
	if(BShi_num() <= 1 && ei.rcan >= 2){
		ei.evscore += 32;
		if(RShi_num() == 2){
			if(have_bit(bb_black_pawn,LeftBB[0x1])){
				ei.evscore += 32;
			}
			if(have_bit(bb_black_pawn,RightBB[0x7])){
				ei.evscore += 32;
			}
		}
	}
	if(RShi_num() <= 1 && ei.bcan >= 2){
		ei.evscore -= 32;
		if(BShi_num() == 2){
			if(have_bit(bb_white_pawn,LeftBB[0x1])){
				ei.evscore -= 32;
			}
			if(have_bit(bb_white_pawn,RightBB[0x7])){
				ei.evscore -= 32;
			}
		}
	}

	if(rpawn1 > 0x2c && rpawn2 > 0x2c && bpawn1 < 0x2d && bpawn2 < 0x2d){ //二个兵全顶住了

		//还要看一下,是不是兵全顶住了,不能过河

        if(    (StoX(rpawn1) == StoX(bpawn1) && StoX(rpawn2) == StoX(bpawn2))
			|| (StoX(rpawn1) == StoX(bpawn2) && StoX(rpawn2) == StoX(bpawn1)) ){
			if(isStringByChe(POSITION,rpawn1,rche,rpawn2)){
				RETRUN_MUL(2);
			}

			if(isStringByChe(POSITION,bpawn1,bche,bpawn2)){
				RETRUN_MUL(2);
			}
		}
	}
	// fen 4kab2/4a4/4b4/8p/p2r5/4P1B1P/R8/4B4/4K4/9 w
	// fen 3ak1b2/4a4/4b4/p3PR1P1/2p6/r8/9/4B4/4A4/4KAB2 w - - 2 2
	if(BShi_num() == 2 && BXiang_num() == 2){
		if(StoY(bk) == 0x0){
			if(PB90(0x0C) == RPAWN && PB90(0x0E) == RPAWN){
			}
			else{
				ei.bsafe = TRUE;
			}
		}
	}
	if(RShi_num() == 2 && RXiang_num() == 2){
		if(StoY(rk) == 0x9){
			if(PB90(0x4B) == BPAWN && PB90(0x4D) == BPAWN){
			}
			else{
				ei.rsafe = TRUE;
			}
		}
	}

	// fen 2bak1b2/4a4/9/r4PP2/9/9/9/5A3/1pp1A4/3RK4 w - - 58 58
	//黑方有二个兵在一边
	//如果红方是连兵
	Bitboard rlp = White_get_connect_Pawn(POSITION);
	Bitboard blp = Black_get_connect_Pawn(POSITION);

	
	Bitboard r1 = m_and(rlp,LowBB[0x2]);
	if(m_have_bit(r1) && StoY(rk) == 0x9 && RShi_num() == 2){
		if(StoY(bpawn1) >= 0x8 && StoY(bpawn2) >= 0x8){
			if(StoX(bpawn1) < 0x4 && StoX(bpawn2) < 0x4){
				if(StoX(rk) >= 0x4){
					ei.rsafe = TRUE;
				}
			}
			if(StoX(bpawn1) > 0x4 && StoX(bpawn2) > 0x4){
				if(StoX(rk) <= 0x4){
					ei.rsafe = TRUE;
				}
			}
		}
	}

	// fen 3ak4/3r2P2/4b4/6R2/8p/9/8P/4BA3/3pAK3/9 w - - 123 123
	 if(RShi_num() == 2 && ei.bcan <= 1){
		 // 我方将的左右二格没有兵
		 Bitboard p = m_and(LowBB[0x6],bb_black_pawn);
		 p = m_and(m_and(LeftBB[StoX(rk) + 2],RightBB[StoX(rk) - 2]),p);
		 if(!m_have_bit(p)){
			 ei.rsafe = true;
		 }
	 }
	 if(BShi_num() == 2 && ei.rcan <= 1){
		 // 我方将的左右二格没有兵
		 Bitboard p = m_and(UpBB[0x3],bb_white_pawn);
		 p = m_and(m_and(LeftBB[StoX(bk) + 2],RightBB[StoX(bk) - 2]),p);
		 if(!m_have_bit(p)){
			 ei.bsafe = true;
		 }
	 }


	Bitboard b1 = m_and(blp,UpBB[0x7]);
	if(m_have_bit(b1) && StoY(bk) == 0x0 && BShi_num() == 2){
		if(StoY(rpawn1) <= 0x1 && StoY(rpawn2) <= 0x4){
			if(StoX(rpawn1) < 0x4 && StoX(rpawn2) < 0x4){
				if(StoX(bk) >= 0x4){
					ei.bsafe = TRUE;
				}
			}
			if(StoX(rpawn1) > 0x4 && StoX(rpawn2) > 0x4){
				if(StoX(bk) <= 0x7){
					ei.bsafe = TRUE;
				}
			}
		}
	}


	// fen 3ak4/3r2P2/4b4/6R2/8p/9/8P/4BA3/3pAK3/9 w - - 123 123
    //红兵给牵制住了, 另一个兵给顶住了.
	//if(board->

	// fen 2ba1a3/4k4/4b4/4PP3/9/2r6/9/5R3/4A1pp1/3AK4 w - - 0 0
	if(BShi_num() == 2 && PB90(0x04) == BKING){
		if(StoY(rpawn1) <= 0x1 && StoY(rpawn2) <= 0x1){
			if(StoX(rpawn1) >= 0x6 && StoX(rpawn2) >= 0x6){
				if(StoX(bche) == 0x5){
					ei.evscore -= 128;
				}
			}
			if(StoX(rpawn1) <= 0x2 && StoX(rpawn2) <= 0x2){
				if(StoX(bche) == 0x3){
					ei.evscore -= 128;
				}
			}
		}
	}
	// fen 2ba1a3/4k4/4b4/4PP3/9/2r6/9/5R3/4A1pp1/3AK4 w - - 0 0
	if(RShi_num() == 2 && PB90(0x55) == RKING){
		if(StoY(bpawn1) >= 0x8 && StoY(bpawn2) >= 0x8){
			if(StoX(bpawn1) >= 0x6 && StoX(bpawn2) >= 0x96){
				if(StoX(rche) == 0x5){
					ei.evscore += 128;
				}
			}
			if(StoX(bpawn1) <= 0x2 && StoX(bpawn2) <= 0x2){
				if(StoX(rche) == 0x3){
					ei.evscore += 128;
				}
			}
		}
	}

	// fen 4k4/9/4b4/p3r4/1R2p4/P1B6/4P4/4BA3/9/4KA3 b - - 0 1
	if(ei.rsafe){
		if(ei.rcan == 0 && (BShi_num() + BXiang_num()) >= 1 && StoY(bk) != 0x2){
			if(StoY(rpawn1) > 0x4 && StoY(rpawn2) > 0x4){
				if(bit_is_set(ei.attackedBy[BCHE],bpawn1) && bit_is_set(ei.attackedBy[BCHE],bpawn2)){
					RETRUN_MUL(2);
				}
			}
		}
	}
	if(ei.bsafe){
		if(ei.bcan == 0 && (RShi_num() + RXiang_num()) >= 1 && StoY(rk) != 0x7){
			if(StoY(bpawn1) < 0x5 && StoY(bpawn2) < 0x5){
				if(bit_is_set(ei.attackedBy[RCHE],rpawn1) && bit_is_set(ei.attackedBy[RCHE],rpawn2)){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 9/4k4/4b4/8r/p1b1p4/5R2P/P8/4B4/4A4/2BAK4 b - - 124 124
	if(ei.rsafe == TRUE){
		if(BXiang_num() == 2 || (BShi_num() + BXiang_num()) >= 2 && StoY(bk) <= 0x1){
			if(PB90(bpawn1 + 18) == RPAWN || PB90(bpawn2 + 18) == RPAWN){
				int x = XYtoS(StoX(bche),StoY(rche));
				if(StoY(x) >= 0x5 && PB90(x) == RPAWN){
                    RETRUN_MUL(4);
				}
			}
		}
	}
	// fen 9/4k4/4b4/8r/p1b1p4/5R2P/P8/4B4/4A4/2BAK4 b - - 124 124
	if(ei.bsafe == TRUE){
		if(RXiang_num() == 2 || (RShi_num() + RXiang_num()) >= 2 && StoY(rk) >= 0x8){
if (PB90(rpawn1 - 18) == BPAWN || PB90(rpawn2 - 18) == BPAWN) {
	int x = XYtoS(StoX(rche), StoY(bche));
	if (StoY(x) <= 0x4 && PB90(x) == BPAWN) {
		RETRUN_MUL(4);
	}
}
		}
	}

	// fen 3ak4/3r2P2/4b4/6R2/8p/9/8P/4BA3/3pAK3/9 w - - 123 123
	if (ei.rsafe) {
		if (ei.rcan <= 1) {
			if (BShi_num() >= 1 && BXiang_num() >= 1 && StoY(bk) == 0) {
				bool isbad = false;
				Square p = SQ_START;
				if (StoY(rpawn1) <= 1 && abs(StoX(rpawn1) - 0x4) >= 2) {
					isbad = true;
					p = rpawn1;
				}
				if (StoY(rpawn2) <= 1 && abs(StoX(rpawn2) - 0x4) >= 2) {
					isbad = true;
					p = rpawn2;
				}
				if (isbad) {
					if (bit_is_set(ei.attackedBy[BCHE], p) && bit_is_set(ei.attackedBy[RCHE], p)) {
						RETRUN_MUL(8);
					}
				}
			}
		}
	}
	if (ei.bsafe) {
		if (ei.bcan <= 1) {
			if (RShi_num() >= 1 && RXiang_num() >= 1 && StoY(rk) == 9) {
				bool isbad = false;
				Square p = SQ_START;
				if (StoY(bpawn1) >= 8 && abs(StoX(bpawn1) - 0x4) >= 2) {
					isbad = true;
					p = bpawn1;
				}
				if (StoY(bpawn2) >= 8 && abs(StoX(bpawn2) - 0x4) >= 2) {
					isbad = true;
					p = bpawn2;
				}
				if (isbad) {
					if (bit_is_set(ei.attackedBy[BCHE], p) && bit_is_set(ei.attackedBy[RCHE], p)) {
						RETRUN_MUL(8);
					}
				}
			}
		}
	}

	// fen 2bak4/4a4/4b4/9/P8/2B1R2pp/4P4/3A5/3KA4/1r7 b - - 0 1
	if (ei.bsafe) {
		if (RShi_num() == 2 && RXiang_num() >= 1 && StoY(rk) >= 0x8) {
			if (!have_bit(bb_black_pawn, LowBB[0x6])) {
				if (StoX(rk) <= 0x4 && !have_bit(bb_black_pawn, LeftBB[0X7])) {
					RETRUN_MUL(8);
				}
				if (StoX(rk) >= 0x4 && !have_bit(bb_black_pawn, RightBB[0X1])) {
					RETRUN_MUL(8);
				}
			}
		}
	}
	if (ei.rsafe) {
		if (BShi_num() == 2 && BXiang_num() >= 1 && StoY(bk) <= 0x1) {
			if (!have_bit(bb_white_pawn, UpBB[0x3])) {
				if (StoX(bk) <= 0x4 && !have_bit(bb_white_pawn, LeftBB[0X7])) {
					RETRUN_MUL(8);
				}
				if (StoX(bk) >= 0x4 && !have_bit(bb_white_pawn, RightBB[0X1])) {
					RETRUN_MUL(8);
				}
			}
		}
	}

	// fen 2baka3/9/4b4/4R4/2p6/3rp3P/P8/4B4/4A4/2B1K4 b - - 0 1
	if (ei.bsafe) {
		if (RShi_num() >= 1 && ei.bcan <= 1 && StoY(rk) == 0x9) {
			if (!have_bit(bb_black_pawn, LowBB[0x6])) {
				RETRUN_MUL(8);
			}
		}
	}
	if (ei.rsafe) {
		if (BShi_num() >= 1 && ei.rcan <= 1 && StoY(bk) == 0x0) {
			if (!have_bit(bb_white_pawn, UpBB[0x3])) {
				RETRUN_MUL(8);
			}
		}
	}

	//  fen 4kab2/4a4/9/2p1P3R/6p2/8P/8r/4BA3/9/3AK1B2 w - - 0 1
	if (ei.rsafe) {
		if (BShi_num() == 2 && BXiang_num() >= 1 && StoY(bk) == 0x0) {
			if (!have_bit(bb_white_pawn, UpBB[0x2])) {
				if (abs(StoX(rpawn1) - 0x4) == 4) {
					if (bit_is_set(ei.attackedBy[RCHE], rpawn1) && bit_is_set(ei.attackedBy[BCHE], rpawn1)) {
						RETRUN_MUL(8);
					}
				}
				if (abs(StoX(rpawn2) - 0x4) == 4) {
					if (bit_is_set(ei.attackedBy[RCHE], rpawn2) && bit_is_set(ei.attackedBy[BCHE], rpawn2)) {
						RETRUN_MUL(8);
					}
				}
			}
		};
	}
	if (ei.bsafe) {
		if (RShi_num() == 2 && RXiang_num() >= 1 && StoY(rk) == 0x9) {
			if (!have_bit(bb_black_pawn, LowBB[0x7])) {
				if (abs(StoX(bpawn1) - 0x4) == 4) {
					if (bit_is_set(ei.attackedBy[RCHE], bpawn1) && bit_is_set(ei.attackedBy[BCHE], bpawn1)) {
						RETRUN_MUL(8);
					}
				}
				if (abs(StoX(bpawn2) - 0x4) == 4) {
					if (bit_is_set(ei.attackedBy[RCHE], bpawn2) && bit_is_set(ei.attackedBy[BCHE], bpawn2)) {
						RETRUN_MUL(8);
					}
				}
			}
		}
	}
}
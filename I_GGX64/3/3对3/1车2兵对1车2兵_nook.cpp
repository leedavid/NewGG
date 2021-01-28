
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
#include "..\\..\\endgame\mat.h"
//fen 4kab2/4a4/4b4/9/2r1P4/p5B2/4R4/4B4/4K4/9 b - - 0 0
//马兵兵对马兵兵
void m_MT_1che2pawn_1che2pawn(typePOS *POSITION, EvalInfo *ei){

	//fen 3R5/5k3/5a3/p3r3p/9/9/P7P/4B4/4A4/4KAB2 w - - 1 1 
    //如果双方的兵都没有过河,且一方的兵在一线,与车在一线,就是和了,

	int rpawn1 = S90_from_piecelist(POSITION,RPAWN,0);
	int rpawn2 = S90_from_piecelist(POSITION,RPAWN,1);

	int bpawn1 = S90_from_piecelist(POSITION,BPAWN,0);
	int bpawn2 = S90_from_piecelist(POSITION,BPAWN,1);

	// ADD_BR
	int bk = BKpos();
	Bitboard bmp = m128_bb_and_bb(bitboard_white_pawn,LowBB[StoY(bk)]);
	ei->evscore += (count_1s(bmp) * ADD_ChePawn_To_ChePawnByShi[BShi_num()]);
	// SUB
	int rk = RKpos();
	Bitboard ymp = m128_bb_and_bb(bitboard_black_pawn,UpBB[StoY(rk)]);
	ei->evscore -= (count_1s(ymp) * ADD_ChePawn_To_ChePawnByShi[RShi_num()]);
		
	int rche = S90_from_piecelist(POSITION,RCHE,0);
	int bche = S90_from_piecelist(POSITION,BCHE,0);

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
	//fen 4kab2/4a4/4b4/8p/p2r5/4P1B1P/R8/4B4/4K4/9 w
	//fen 3ak1b2/4a4/4b4/p3PR1P1/2p6/r8/9/4B4/4A4/4KAB2 w - - 2 2
	if(BShi_num() == 2 && BXiang_num() == 2){
		if(StoY(bk) == 0x0){
			if(PB90[0x0C] == RPAWN && PB90[0x0E] == RPAWN){
			}
			else{
				ei->bsafe = TRUE;
			}
		}
	}
	if(RShi_num() == 2 && RXiang_num() == 2){
		if(StoY(rk) == 0x9){
			if(PB90[0x4B] == BPAWN && PB90[0x4D] == BPAWN){
			}
			else{
				ei->rsafe = TRUE;
			}
		}
	}

	//fen 2bak1b2/4a4/9/r4PP2/9/9/9/5A3/1pp1A4/3RK4 w - - 58 58
	//黑方有二个兵在一边
	//如果红方是连兵
	Bitboard rlp = White_get_connect_Pawn(POSITION);
	Bitboard blp = Black_get_connect_Pawn(POSITION);

	
	Bitboard r1 = m128_bb_and_bb(rlp,LowBB[0x2]);
	if(m128_is_have_bit(r1) && StoY(rk) == 0x9 && RShi_num() == 2){
		if(StoY(bpawn1) >= 0x8 && StoY(bpawn2) >= 0x8){
			if(StoX(bpawn1) < 0x4 && StoX(bpawn2) < 0x4){
				if(StoX(rk) >= 0x4){
					ei->rsafe = TRUE;
				}
			}
			if(StoX(bpawn1) > 0x4 && StoX(bpawn2) > 0x4){
				if(StoX(rk) <= 0x4){
					ei->rsafe = TRUE;
				}
			}
		}
	}


	Bitboard b1 = m128_bb_and_bb(blp,UpBB[0x7]);
	if(m128_is_have_bit(b1) && StoY(bk) == 0x0 && BShi_num() == 2){
		if(StoY(rpawn1) <= 0x1 && StoY(rpawn2) <= 0x4){
			if(StoX(rpawn1) < 0x4 && StoX(rpawn2) < 0x4){
				if(StoX(bk) >= 0x4){
					ei->bsafe = TRUE;
				}
			}
			if(StoX(rpawn1) > 0x4 && StoX(rpawn2) > 0x4){
				if(StoX(bk) <= 0x7){
					ei->bsafe = TRUE;
				}
			}
		}
	}


	//fen 3ak4/3r2P2/4b4/6R2/8p/9/8P/4BA3/3pAK3/9 w - - 123 123
    //红兵给牵制住了, 另一个兵给顶住了.
	//if(board->

	//fen 2ba1a3/4k4/4b4/4PP3/9/2r6/9/5R3/4A1pp1/3AK4 w - - 0 0
	if(BShi_num() == 2 && PB90[0x04] == BKING){
		if(StoY(rpawn1) <= 0x1 && StoY(rpawn2) <= 0x1){
			if(StoX(rpawn1) >= 0x6 && StoX(rpawn2) >= 0x6){
				if(StoX(bche) == 0x5){
					ei->evscore -= 128;
				}
			}
			if(StoX(rpawn1) <= 0x2 && StoX(rpawn2) <= 0x2){
				if(StoX(bche) == 0x3){
					ei->evscore -= 128;
				}
			}
		}
	}
	//fen 2ba1a3/4k4/4b4/4PP3/9/2r6/9/5R3/4A1pp1/3AK4 w - - 0 0
	if(RShi_num() == 2 && PB90[0x55] == RKING){
		if(StoY(bpawn1) >= 0x8 && StoY(bpawn2) >= 0x8){
			if(StoX(bpawn1) >= 0x6 && StoX(bpawn2) >= 0x96){
				if(StoX(rche) == 0x5){
					ei->evscore += 128;
				}
			}
			if(StoX(bpawn1) <= 0x2 && StoX(bpawn2) <= 0x2){
				if(StoX(rche) == 0x3){
					ei->evscore += 128;
				}
			}
		}
	}

	//fen 9/4k4/4b4/8r/p1b1p4/5R2P/P8/4B4/4A4/2BAK4 b - - 124 124
	if(ei->rsafe == TRUE){
		if(BXiang_num() == 2 || (BShi_num() + BXiang_num()) >= 2 && StoY(bk) <= 0x1){
			if(PB90[bpawn1 + 18] == RPAWN || PB90[bpawn2 + 18] == RPAWN){
				int x = XYtoS(StoX(bche),StoY(rche));
				if(StoY(x) >= 0x5 && PB90[x] == RPAWN){
                    RETRUN_MUL(4);
				}
			}
		}
	}
	//fen 9/4k4/4b4/8r/p1b1p4/5R2P/P8/4B4/4A4/2BAK4 b - - 124 124
	if(ei->bsafe == TRUE){
		if(RXiang_num() == 2 || (RShi_num() + RXiang_num()) >= 2 && StoY(rk) >= 0x8){
			if(PB90[rpawn1 - 18] == BPAWN || PB90[rpawn2 - 18] == BPAWN){
				int x = XYtoS(StoX(rche),StoY(bche));
				if(StoY(x) <= 0x4 && PB90[x] == BPAWN){
                     RETRUN_MUL(4);
				}
			}
		}
	}

}
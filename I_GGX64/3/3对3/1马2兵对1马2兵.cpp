#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"



//1马2兵对1马2兵
void m_MT_1ma2pawn_1ma2pawn(typePOS &POSITION, EvalInfo &ei){	

	//如果一方有仕,另一方的二个兵都到了低兵,且在一边,则一边要减分


	Square rpawn1 = S90_from_piecelist(POSITION,RPAWN,0);
	Square rpawn2 = S90_from_piecelist(POSITION,RPAWN,1);

	Square bpawn1 = S90_from_piecelist(POSITION,BPAWN,0);
	Square bpawn2 = S90_from_piecelist(POSITION,BPAWN,1);

	Square bma = S90_from_piecelist(POSITION,BMA,0);
	Square rma = S90_from_piecelist(POSITION,RMA,0);

	if((RShi_num() + RXiang_num()) >= 3 && StoY(bma) <= 0x2 && ei.rcan >= 1){
		ei.rsafe = true;
	}
	if((BShi_num() + BXiang_num()) >= 3 && StoY(rma) >= 0x7 && ei.bcan >= 1){
		ei.bsafe = true;
	}

	// fen 3k5/2N1aPP2/2n6/9/2b3p2/9/9/1p2BA3/9/2BAK4 b - - 24 24 
	// fen 5k3/2PPa4/4ba3/9/2b1N1p2/9/9/7nB/4Ap3/2B1K4 b - - 0 0

	// ADD_BR
	Square bk = BKpos();
	Bitboard bmp = m_and(bb_white_pawn,LowBB[StoY(bk)]);
	ei.evscore += (count_1s(bmp) * ADD_1MaXPawn_1MaXPawn_ByShi[BShi_num()]);
	// SUB
	Square rk = RKpos();
	Bitboard ymp = m_and(bb_black_pawn,UpBB[StoY(rk)]);
	ei.evscore -= (count_1s(ymp) * ADD_1MaXPawn_1MaXPawn_ByShi[RShi_num()]);

	if(StoY(rpawn1) <= 0x1 && StoY(rpawn2) <= 0x1 && IsOnSameSide(rpawn1,rpawn2) 
		&& BShi_num() >= 1 ){
		ei.evscore -= 196;
	}

	if(StoY(bpawn1) >= 0x8 && StoY(bpawn2) >= 0x8 && IsOnSameSide(bpawn1,bpawn2) 
		&& RShi_num() >= 1 ){
		ei.evscore += 196;
	}

	int rcan = ei.rcan;
	int bcan = ei.bcan;	

	ei.evscore += 80 * ( 2 - bcan);
	ei.evscore -= 80 * ( 2 - rcan);


	// fen 3k5/2N1aPP2/2n6/9/2b3p2/9/9/1p2BA3/9/2BAK4 b - - 24 24 

	if(rcan == 0 && bcan == 0){
		RETRUN_MUL(2);
	}

	// fen 3ak4/n3a4/4P4/p1P6/9/2N3B2/6p2/9/4AK3/5AB2 w - - 0 1
	if(BShi_num() == 2 && StoY(bk) == 0x0){
		if(PB90(0x16) == RPAWN && have_bit(RankBB_A[0x6],bb_black_pawn)){
			if(!have_bit(bb_white_pawn,UpBB[0x2])){
				if(ei.rsafe){
					RETRUN_MUL(6);
				}
			}
		}
	}
	if(RShi_num() == 2 && StoY(rk) == 0x9){
		if(PB90(0x43) == BPAWN && have_bit(RankBB_A[0x3],bb_white_pawn)){
			if(!have_bit(bb_black_pawn,LowBB[0x7])){
				if(ei.bsafe){
					RETRUN_MUL(6);
				}
			}
		}
	}


	// fen 4k1b2/2P1a4/6P2/4nN3/9/9/4pp3/B3B4/4A4/4KA3 b - - 121 121
	if(rcan == 2 && bcan == 2){
		if(BShi_num() >= 1 && RShi_num() >= 1){
			if((BShi_num() + BXiang_num()) >= 2 && (RShi_num() + RXiang_num()) >= 2 ){
				RETRUN_MUL(8);
			}
		}
	}

	// fen 3a5/P2k1P3/b8/2n6/2b6/2P6/4N4/3A1A3/2p3p2/2B1K4 b - - 0 1
	// 如果对方有仕, 且我方的一个兵在边上, 要扣分
	if(BShi_num() >= 1){
		if(abs(StoX(rpawn1) - 0x4) >= 4 || abs(StoX(rpawn2) - 0x4) >= 4){
			ei.evscore -= 64;
		}
	}

	if(RShi_num() >= 1){
		if(abs(StoX(bpawn1) - 0x4) >= 4 || abs(StoX(bpawn2) - 0x4) >= 4){
			ei.evscore += 64;
		}
	}

	// fen 3k1a3/9/3a5/6P1p/5n3/2B2N2P/6p2/3A4B/4A4/4K4 w - - 0 1
	if(ei.rcan <= 1 && ei.bcan <= 1){
		if(RShi_num() == 2 && BShi_num() == 2){
			RETRUN_MUL(8);
		}
	}

}
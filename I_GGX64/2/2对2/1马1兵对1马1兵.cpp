
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"

//马兵对马兵
void m_MT_1MA1PAWN_1MA1PAWN(typePOS &POSITION, EvalInfo &ei){

	
	Square rpawn = S90_from_piecelist(POSITION,RPAWN,0);
	Square bpawn = S90_from_piecelist(POSITION,BPAWN,0);

	Square rma = S90_from_piecelist(POSITION,RMA,0);
	Square bma = S90_from_piecelist(POSITION,BMA,0);

	Square bk = BKpos();
	Square rk = RKpos();

	//双方的兵到底线了，就和了
	if(StoY(bpawn) == 0x9 && StoY(rpawn) == 0x0){
		RETRUN_MUL(1);
	}

	if(StoY(rpawn) > StoY(bk)){
		ei.evscore += ADD_MaPawn_To_MaPawnByShi[BShi_num()];
	}

	if(StoY(bpawn) < StoY(rk)){
		ei.evscore -= ADD_MaPawn_To_MaPawnByShi[RShi_num()];
	}

	// fen 3k1a3/4a1P2/9/9/9/2B2N3/8n/3A1A2B/5p3/3K5 w - - 123 123
	if(StoY(bk) != 0x2 && StoY(rk) != 0x7){
		if(BShi_num() != 0 && RShi_num() != 0){
			RETRUN_MUL(2);
		}
	}

	int rcan = ei.rcan;
	int bcan = ei.bcan;
	
	//双方的兵都不能过河
	if(rcan == 0 && bcan == 0){
		RETRUN_MUL(2);
	}

	// fen 4k1N2/5P3/9/5n3/9/9/9/B1p6/3KA4/6B2 b - - 27 27
	//如果双方的将没有被制住,也是和棋
	if(FALSE){
	}
	else if(PB90(0x0D) == RPAWN && StoY(bk) == 0x0){
	}
	else if(PB90(0x4C) == BPAWN && StoY(rk) == 0x9){
	}
	else{
		if(((BShi_num() + BXiang_num()) != 0 || StoY(bpawn) >= 0x4)
			&& ((RShi_num() + RXiang_num()) != 0 || StoY(rpawn) <= 0x5)){
				RETRUN_MUL(2);
		}
	}

    // fen 5k3/4P4/9/4n4/6bN1/9/9/B2ABA3/6p2/3K5 w - - 53 53
	if(BShi_num() >=1 || BXiang_num() >= 1){
		if(StoY(bpawn) > 0x4) ei.bsafe = TRUE;
	}
	// fen 5k3/4P4/9/4n4/6bN1/9/9/B2ABA3/6p2/3K5 w - - 53 53
	if(RShi_num() >=1 || RXiang_num() >= 1){
		if(StoY(rpawn) < 0x5) ei.rsafe = TRUE;
	}



	//看能不能用帅牵制对方的马
	if(StoX(rk) == StoX(bk)){

		Bitboard peat = POSITION.Pao_Eat_bb(rk);
		if(bit_is_set(peat,bk)){
			Bitboard bet = m_and(BitboardOCC,BetweenBB[rk][bk]);
			int sq = pop_1st_bit_sq(bet);
			if(PB90(sq) == RMA){
				ei.evscore -= 128;
			}
			if(PB90(sq) == BMA){
				ei.evscore += 128;
			}
		}

		////得到将的上下信息
		//SlideMoveStruct *psmv;

		//psmv = FileMove(StoY(rk), board->wBitFiles[StoX(rk)]);

		//Square rkup = psmv->RookCap[DUpLeft] + StoX(rk);

		//psmv = FileMove(StoY(bk), board->wBitFiles[StoX(bk)]);

		//Square bklo  = psmv->RookCap[DLoRight] + StoX(bk);
		//
		//if(rkup == bklo){
		//	if(rkup == rma){
		//		board->mulScore -= 120;
		//	}
		//	else if(rkup == bma){
		//		board->mulScore += 120;
		//	}
		//}
	}
	// fen 5k3/4P4/9/9/7N1/6B2/5n3/3A5/2p1AK3/6B2 r
	// fen 5k3/4P4/9/4n4/7N1/6B2/9/3A1A3/2p2K3/6B2 w - - 0 1	
    if(ei.rsafe == TRUE && ei.bcan >= 1){
		if(!bit_is_set(ei.xray_bit[WHITE],bma)){
			// 控制住对方所有可将的步子。
			if(!m_have_bit(_mm_andnot_si128(ei.attacked_by(BLACK),
				m_and(POSITION.king_to_ma_attacks_bb(bk),
				ei.attacked_by(RMA))))){
				RETRUN_MUL(4);
			}
		}
	}
	if(ei.bsafe == TRUE && ei.rcan >= 1){
		if(!bit_is_set(ei.xray_bit[BLACK],rma)){
			// 控制住对方所有可将的步子。fen 5k3/4P4/9/9/5n1N1/6B2/9/3A1K3/2p6/6B2 r
			if(!m_have_bit(_mm_andnot_si128(ei.attacked_by(WHITE),
				m_and(POSITION.king_to_ma_attacks_bb(rk),
				ei.attacked_by(BMA))))){
					RETRUN_MUL(4);
			}
		}
	}

	
	

}


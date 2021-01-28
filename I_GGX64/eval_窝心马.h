// 窝心马的评估

if(PB90(0x0d) == BMA){
	ei.attPoint[WHITECOLOR] += Ma_at_WoXing_point;
	bool iswoxin = false;
	//看一下是不是上方有车
	if(PB90(0x04) == BKING){
		if(PB90(0x03) == BSHI && PB90(0x05) == BSHI){
			if(BXiang_num() == 0){
				// 看一下上方有没有车
				Bitboard att = m_and(bitboard_white_che,ei.attackKingPaoCan[BLACKCOLOR]);
				att = m_and(FileBB_A[StoX(bk)],att);
				if(m128_is_have_bit(att)){
					iswoxin = true;
				}
			}
			if(PIECE_SIDE(PB90(0x16)) == BLACK_TO_MOVE){
				Bitboard att = m_and(pao_super_attacks_bb(bk,occ), bitboard_white_pao);
				att = m_and(FileBB_A[StoX(bk)],att);
				if(m128_is_have_bit(att)){
					iswoxin = true;
				}
			}
		}
	}

	if(iswoxin){
		ei.attPoint[WHITECOLOR] += Wo_Xing_Ma_att_point; // 
		valu += point(64,512);
	}
}

if(PB90(0x4c) == RMA){
	ei.attPoint[BLACKCOLOR] += Ma_at_WoXing_point;
	bool iswoxin = false;
	//看一下是不是上方有车
	if(PB90(0x55) == RKING){
		if(PB90(0x54) == RSHI && PB90(0x56) == RSHI){
			if(RXiang_num() == 0){
				// 看一下上方有没有车
				Bitboard att = m_and(bitboard_black_che,ei.attackKingPaoCan[WHITECOLOR]);
				att = m_and(FileBB_A[StoX(rk)],att);
				if(m128_is_have_bit(att)){
					iswoxin = true;
				}
			}
			if(PIECE_SIDE(PB90(0x43)) == WHITE_TO_MOVE){
				Bitboard att = m_and(pao_super_attacks_bb(rk,occ), bitboard_black_pao);
				att = m_and(FileBB_A[StoX(rk)],att);
				if(m128_is_have_bit(att)){
					iswoxin = true;
				}
			}
		}
	}

	if(iswoxin){
		ei.attPoint[BLACKCOLOR] += Wo_Xing_Ma_att_point; // 
		valu -= point(64,512);
	}
}//fen 3a3CC/4k4/bc3ac2/1R6p/6b2/2P2p3/P3r3P/9/4N4/3AKA3 w - - 16 16

//BString = m_and(pao_super_attacks_bb(bk,occ), bitboard_white_pao);

//if(ei.ev_stat & EV_STAT_Bwoxin_By_R){   // 黑方被窝心马
//	ei.Rattack_B_Count += Wo_Xing_Ma_att_point; // 
//	 valu += point(64,512);
//}
//fen 3a3CC/4k4/bc3ac2/1R6p/6b2/2P2p3/P3r3P/9/4N4/3AKA3 w - - 16 16
//加上炮的可能将军分，
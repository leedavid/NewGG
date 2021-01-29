//***********************************************************
	// StringBB 牵制的总评估, 这儿只评价车X车将的评价 
	// 是不是还要加上炮 0 X 车的评价(这个不要了,已在炮3子中有评价了)
	// 还要判断这个车是不是有保护,如果有保护,就不算牵制哇???
	//***********************************************************
    //fen 4kabr1/4a2c1/9/p3P1P1p/2b4R1/P8/4P3P/4B1N2/4Ac3/4KA3 w - - 0 0
//Next_String:
//	while(m128_is_have_bit(ei.StringBB)){
//		int t = pop_1st_bit(&ei.StringBB); //  
//		if(PIECE_SIDE(PB90(t)) == WHITE_TO_MOVE){
//			// 除了车,将的保护,还有其它的保护
//			//if(m128_is_have_bit(
//			//	m_and(SetMaskBB[t],
//			//	m128_bb_or_bb(ei.attackedBy[RPAO],
//			//	m128_bb_or_bb(ei.attackedBy[RMA],
//			//	m128_bb_or_bb(ei.attackedBy[RSHI],
//			//	m128_bb_or_bb(ei.attackedBy[RXIANG],
//			//	ei.attackedBy[RPAWN]))))))){
//			//		continue;
//			//}
//
//			//1. 这个棋子能将军, 就不算牵制
//
//
//			//再看一下这个棋子的周围情况
//			//如果保护他的车有根,则这个棋子没有被牵制
//			Bitboard TBche = rook_attacks_bb(t,occ);
//			TBche = m_and(TBche,bitboard_white_che);	
//			while(m128_is_have_bit(TBche)){
//				int che = pop_1st_bit(&TBche);
//				if(bit_is_set(POSITION->DYN->attack_white,che)){
//                    goto Next_String;
//				}
//			}
//		}
//		else{
//			//if(m128_is_have_bit(
//			//	m_and(SetMaskBB[t],
//			//	m128_bb_or_bb(ei.attackedBy[BPAO],
//			//	m128_bb_or_bb(ei.attackedBy[BMA],
//			//	m128_bb_or_bb(ei.attackedBy[BSHI],
//			//	m128_bb_or_bb(ei.attackedBy[BXIANG],
//			//	ei.attackedBy[BPAWN]))))))){   // 有其它的棋子在保护,不算是牵制
//			//		continue;
//			//}
//			//再看一下这个棋子的周围情况
//			//如果保护他的车有根,则这个棋子没有被牵制
//			Bitboard TBche = rook_attacks_bb(t,occ);
//			TBche = m_and(TBche,bitboard_black_che);
//			while(m128_is_have_bit(TBche)){
//				int che = pop_1st_bit(&TBche);
//				if(bit_is_set(POSITION->DYN->attack_black,che)){
//					goto Next_String;
//				}
//			} //fen 3ak4/4a4/9/5r3/P5b2/2B6/1R3N1r1/3AB3p/4AKR2/c8 b - - 0 0
//		}		
//		valu -= Point_StringScoreByChe[PB90(t)]; //board_display(POSITION,"che string\n");
//	}
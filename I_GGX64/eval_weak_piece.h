

// 1. 评价黑方的弱子, 去了对方兵,仕,相保护的棋子
// 2. 也要去了自己的兵哇.
Bitboard weakEnemies = _mm_andnot_si128(
	m128_bb_or_bb(ei.BpawnAtt,ei.BShiXiangAtt),  // 去了兵,仕相
	m_and(
	_mm_andnot_si128(bitboard_black_pawn,bitboard_occ_black),
	POSITION->DYN->attack_white));

if(m128_is_have_bit(weakEnemies)){
	Bitboard b;
	// 红仕,红相在攻击
	b = m_and(ei.RShiXiangAtt,weakEnemies);	
	while(m128_is_have_bit(b)){
		int sq2    = pop_1st_bit(&b);
		valu += SHI_XIANG_ThreatBonus[PIECE_TYPE(PB90(sq2))];
	}
	// 红兵
	b = m_and(ei.RpawnAtt,weakEnemies);	
	while(m128_is_have_bit(b)){
		int sq2    = pop_1st_bit(&b);
		valu += PAWN_ThreatBonus[PIECE_TYPE(PB90(sq2))];
	}
	// 红炮, 棋子的自保护也算一起?
	for(int i = 0; i < RPao_num(); i++){
		b = m_and(ei.RPaoAtt[i],weakEnemies);	
		while(m128_is_have_bit(b)){
			int sq2    = pop_1st_bit(&b);
			valu += PAO_ThreatBonus[PIECE_TYPE(PB90(sq2))];
		}
	}
	// 红马
	for(int i = 0; i < RMa_num(); i++){
		b = m_and(ei.RmaAtt[i],weakEnemies);	
		while(m128_is_have_bit(b)){
			int sq2    = pop_1st_bit(&b);
			valu += MA_ThreatBonus[PIECE_TYPE(PB90(sq2))];
		}
	}
	// 红车
	for(int i = 0; i < RChe_num(); i++){
		b = m_and(ei.RcheAtt[i],weakEnemies);	
		while(m128_is_have_bit(b)){
			int sq2    = pop_1st_bit(&b);
			valu += CHE_ThreatBonus[PIECE_TYPE(PB90(sq2))];
		}
	}
}


// 1. 评价红方的弱子, 去了对方兵,仕,相保护的棋子
weakEnemies = _mm_andnot_si128(
	m128_bb_or_bb(ei.RpawnAtt,ei.RShiXiangAtt),  // 去了兵,仕相
	m_and(
	_mm_andnot_si128(bitboard_white_pawn,bitboard_occ_white),POSITION->DYN->attack_black));

if(m128_is_have_bit(weakEnemies)){
	Bitboard b;
	// 黑仕,黑相在攻击
	b = m_and(ei.BShiXiangAtt,weakEnemies);	
	while(m128_is_have_bit(b)){
		int sq2    = pop_1st_bit(&b);
		valu -= SHI_XIANG_ThreatBonus[PIECE_TYPE(PB90(sq2))];
	}
	// 黑兵
	b = m_and(ei.BpawnAtt,weakEnemies);	
	while(m128_is_have_bit(b)){
		int sq2    = pop_1st_bit(&b);
		valu -= PAWN_ThreatBonus[PIECE_TYPE(PB90(sq2))];
	}
	// 黑炮, 棋子的自保护也算一起?
	for(int i = 0; i < BPao_num(); i++){
		b = m_and(ei.BPaoAtt[i],weakEnemies);	
		while(m128_is_have_bit(b)){
			int sq2    = pop_1st_bit(&b);
			valu -= PAO_ThreatBonus[PIECE_TYPE(PB90(sq2))];
		}
	}
	// 黑马
	for(int i = 0; i < BMa_num(); i++){
		b = m_and(ei.BmaAtt[i],weakEnemies);	
		while(m128_is_have_bit(b)){
			int sq2    = pop_1st_bit(&b);
			valu -= MA_ThreatBonus[PIECE_TYPE(PB90(sq2))];
		}
	}
	// 黑车
	for(int i = 0; i < BChe_num(); i++){
		b = m_and(ei.BcheAtt[i],weakEnemies);	
		while(m128_is_have_bit(b)){
			int sq2    = pop_1st_bit(&b);
			valu -= CHE_ThreatBonus[PIECE_TYPE(PB90(sq2))];
		}
	}
}
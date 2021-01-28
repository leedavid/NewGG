

// 黑方攻击红帅

Bitboard undefended;
int attackCounter = count_1s(m_and(ei.attackKingBoard,bitboard_occ_black));

if(attackCounter >= 2){
	undefended = m_and(POSITION->DYN->attack_black,attacks_by_bpawn_bk(rk));

	Bitboard protect = m128_bb_or_bb(ei.RShiXiangAtt,
		m128_bb_or_bb(ei.RmaAtt[0],
		m128_bb_or_bb(ei.RmaAtt[1],
		m128_bb_or_bb(ei.RPaoAtt[0],
		m128_bb_or_bb(ei.RPaoAtt[1],
		m128_bb_or_bb(ei.RcheAtt[0],ei.RcheAtt[1]))))));

	undefended = _mm_andnot_si128(protect,undefended);  //print_bb(undefended);

	ei.attPoint[BLACKCOLOR] += 6 * (ei.kingAdjacentZoneAttacksCount[BLACKCOLOR] + count_1s(undefended));

	// 将是不是给兵攻击了
	Bitboard att = m_and(ei.attackKingBoard,bitboard_black_pawn);
    ei.attPoint[BLACKCOLOR] += PawnAttWeight * count_1s(att);
	
	// 将是不是给车攻击了
	att = m_and(ei.attackKingBoard,bitboard_black_che);
	if(m128_is_have_bit(att)){
		int che_num = count_1s(att);
	    ei.attPoint[BLACKCOLOR] += CheAttWeight * che_num;
	}

	// 将是不是给马攻击了
	att = m_and(ei.attackKingBoard,bitboard_black_ma);
	if(m128_is_have_bit(att)){
		int ma_num = count_1s(att);
	    ei.attPoint[BLACKCOLOR] += MaAttWeight * ma_num;
	}

	// 将是不是给炮攻击了
	att = m_and(ei.attackKingBoard,bitboard_black_pao);
	if(m128_is_have_bit(att)){
		int pao_num = count_1s(att);
	    ei.attPoint[BLACKCOLOR] += PaoAttWeight * pao_num;
	}

	// Analyse safe distance checks 分析对方的将军的安全步, 前面马,炮已分析过了

	// 抽将,叠将的得分
	
}



//
//Bitboard white_safe = m_not(m128_bb_or_bb(bitboard_occ_white,
//	POSITION->DYN->attack_black));  // 红方可安全走到的棋格,还得加上pao_NULL哇
//Bitboard black_safe = m_not(m128_bb_or_bb(bitboard_occ_black,
//	POSITION->DYN->attack_white));  // 黑方可安全走到的棋格


	//Bitboard RmaAtt[2];                                  // 保存中间的数据
	//Bitboard BmaAtt[2];
	//Bitboard RcheAtt[2];
	//Bitboard BcheAtt[2];
	//Bitboard RPaoAtt[2];
	//Bitboard BPaoAtt[2];
	//Bitboard RPaoCheAtt[2];                              // 炮可走到的棋格.
	//Bitboard BPaoCheAtt[2];
	//Bitboard RpawnAtt;
	//Bitboard BpawnAtt;

	//Bitboard RShiXiangAtt;      // 红仕红相
	//Bitboard BShiXiangAtt;      // 黑仕黑象
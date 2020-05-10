

// 红方攻击黑帅

//Bitboard undefended;
attackCounter = count_1s(m_and(ei.attackKingBoard,bitboard_occ_white));

if(attackCounter >= 2){
	undefended = m_and(POSITION->DYN->attack_white,attacks_by_rpawn_rk(bk));

	Bitboard protect = m128_bb_or_bb(ei.BShiXiangAtt,  // 自已的兵不能保护自己的老将.
		m128_bb_or_bb(ei.BmaAtt[0],
		m128_bb_or_bb(ei.BmaAtt[1],
		m128_bb_or_bb(ei.BPaoAtt[0],
		m128_bb_or_bb(ei.BPaoAtt[1],
		m128_bb_or_bb(ei.BcheAtt[0],ei.BcheAtt[1]))))));

	undefended = _mm_andnot_si128(protect,undefended);  //print_bb(undefended);

	ei.attPoint[WHITECOLOR] += 6 * (ei.kingAdjacentZoneAttacksCount[WHITECOLOR] + count_1s(undefended));

	// 将是不是给兵攻击了
	Bitboard att = m_and(ei.attackKingBoard,bitboard_white_pawn);

	if(m128_is_have_bit(att)){
	    ei.attPoint[WHITECOLOR] += PawnAttWeight * count_1s(att);
	}

	// 将是不是给车攻击了
	att = m_and(ei.attackKingBoard,bitboard_white_che);
	if(m128_is_have_bit(att)){
		int che_num = count_1s(att);
		ei.attPoint[WHITECOLOR] += CheAttWeight * che_num;
		// fen 3ak1b2/4a4/1R2b1n2/4p1C1p/p5P2/P1B4r1/4P3P/N4R3/4AK3/2BA3rc w - 
		//if(num == 2){

		//}
	}

	// 将是不是给马攻击了
	att = m_and(ei.attackKingBoard,bitboard_white_ma);
	if(m128_is_have_bit(att)){
		int ma_num = count_1s(att);
	    ei.attPoint[WHITECOLOR] += MaAttWeight * ma_num;
	}

	// 将是不是给炮攻击了
	att = m_and(ei.attackKingBoard,bitboard_white_pao);
	if(m128_is_have_bit(att)){
		int pao_num = count_1s(att);
	    ei.attPoint[WHITECOLOR] += PaoAttWeight * pao_num;
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
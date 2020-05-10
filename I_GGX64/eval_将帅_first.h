

	rk = RKpos();
	bk = BKpos();
	occ = POSITION->byWhiteBlack;
	bit_rk = SetMaskBB[rk];
	bit_bk = SetMaskBB[bk];	


	valu += POSITION->DYN->statico;  // 这个包括开局分与残局分 value = (DYNAMIC->statik) + (PAWN_VALUE->points);
	
	//stringBeChe = _mm_setzero_si128();
	POSITION->DYN->white_xray = _mm_setzero_si128();
	POSITION->DYN->black_xray = _mm_setzero_si128();

	POSITION->DYN->black_pao_null = _mm_setzero_si128();        // 炮可抽将的棋格
	POSITION->DYN->white_pao_null = _mm_setzero_si128();        // 

	POSITION->DYN->black_king_check = _mm_setzero_si128();      // 将军的棋格
	POSITION->DYN->white_king_check = _mm_setzero_si128();

	
	//***********************************************************
	// 黑将
	//*********************************************************** 
	POSITION->DYN->attack_black = one_bpawn_bk_attacks(bk);   // 

	ei.attackKingCheCan[BLACKCOLOR] = rook_attacks_bb(bk,occ);            // 对方的车能将军的棋格	
	// 对将检测
	if(m128_is_have_bit(m_and(ei.attackKingCheCan[BLACKCOLOR],bit_rk))){ // 看一下是不是对将了
		POSITION->DYN->black_king_check = bit_rk;  // 对将
		POSITION->DYN->white_king_check = bit_bk;
	}
	
	// 这儿可判断是不是对方有空炮,(或半空炮)

	// 再看一下是不是有红炮，因为可以叠将，叠将也能强大哇
	Bitboard kPao = m_and(ei.attackKingCheCan[BLACKCOLOR],bitboard_white_pao);
	if(m128_is_have_bit(kPao)){
		ei.KongPaoBB = m128_bb_or_bb(ei.KongPaoBB,kPao);
		while(m128_is_have_bit(kPao)){
			int pao = pop_1st_bit(&kPao);
			POSITION->DYN->white_pao_null = m128_bb_or_bb(POSITION->DYN->white_pao_null,
				BetweenBB[pao][bk]);
		}
	}

	ei.attackKingMaCan[BLACKCOLOR]   = king_to_ma_attacks_bb(bk,occ);       // 对方的马能将军的棋格
	ei.attackKingPaoCan[BLACKCOLOR]  = pao_eat_attacks_bb(bk,occ);          // 对方的炮能将军的棋格	

	//***********************************************************
	// 红将
	//***********************************************************

    POSITION->DYN->attack_white = one_rpawn_rk_attacks(rk);            // 王的可攻击性   

	ei.attackKingCheCan[WHITECOLOR] = rook_attacks_bb(rk,occ);            // 对方的车能将军的棋格

	if(ABS(StoX(rk) - StoX(bk)) <= 1){  // 将与将的相互攻击性。
		POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,
			m_and(ei.attackKingCheCan[BLACKCOLOR],KingKingAttBB[rk]));  
		POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,
			m_and(ei.attackKingCheCan[WHITECOLOR],KingKingAttBB[bk]));	
	}

	// 再看一下是不是有黑炮，因为可以叠将，叠将也能强大哇
	kPao = m_and(ei.attackKingCheCan[WHITECOLOR],bitboard_black_pao);
	if(m128_is_have_bit(kPao)){
		ei.KongPaoBB = m128_bb_or_bb(ei.KongPaoBB,kPao);
		while(m128_is_have_bit(kPao)){
			int pao = pop_1st_bit(&kPao);
			POSITION->DYN->black_pao_null = m128_bb_or_bb(POSITION->DYN->black_pao_null,
				BetweenBB[pao][rk]);  // 得到可空炮的将的棋格
		}
	}	

	ei.attackKingMaCan[WHITECOLOR]  = king_to_ma_attacks_bb(rk,occ);       // 对方的马能将军的棋格
	ei.attackKingPaoCan[WHITECOLOR] = pao_eat_attacks_bb(rk,occ);          // 对方的炮能将军的棋格


	// 再评估一下黑车与帅的关系
	BString = m_and(ei.attackKingPaoCan[WHITECOLOR],bitboard_black_che);
	while(m128_is_have_bit(BString)){
		int che = pop_1st_bit(&BString);
		Bitboard p = m_and(BetweenBB[rk][che],occ);
		int x   = pop_1st_bit(&p);
		// Xray
		set_bit(POSITION->DYN->black_xray,x);
		xray_black_list[x] = che;
	}
	// 再评估一下红车与帅的关系
	BString = m_and(ei.attackKingPaoCan[BLACKCOLOR],bitboard_white_che);
	while(m128_is_have_bit(BString)){
		int che = pop_1st_bit(&BString);
		Bitboard p = m_and(BetweenBB[bk][che],occ);
		int x   = pop_1st_bit(&p);
		// Xray
		set_bit(POSITION->DYN->white_xray,x);
		xray_white_list[x] = che;
	}

	// 再评估一下黑炮与帅的关系, 中炮,底炮
	BString = m_and(pao_super_attacks_bb(rk,occ), bitboard_black_pao);
	while(m128_is_have_bit(BString)){
		int pao = pop_1st_bit(&BString);
		Bitboard p2_bb = m_and(BetweenBB[pao][rk],
			m_and(ei.attackKingPaoCan[WHITECOLOR],occ));  // pao_eat_att = A
		int p2 = pop_1st_bit(&p2_bb);
		Bitboard p1_bb = m_and(BetweenBB[rk][p2],occ);
		int p1 = pop_1st_bit(&p1_bb);

		// xray
		set_bit(POSITION->DYN->black_xray,p1);
		set_bit(POSITION->DYN->black_xray,p2);

		xray_black_list[p1] = pao;
		xray_black_list[p2] = pao;
		// 用来评估中炮(铁门栓), 底炮, 窝心炮,马....
		set_bit(ei.ZhongDiPaoBB,pao);  // board_display(board,"中炮或底炮\n",stdout);

		//将这些炮做一个进攻的标志 
		set_bit(ei.attackKingBoard,pao);
	}

	// 再评估一下红炮与黑帅的关系, 中炮,底炮
	BString = m_and(pao_super_attacks_bb(bk,occ), bitboard_white_pao);
	while(m128_is_have_bit(BString)){
		int pao = pop_1st_bit(&BString);
		Bitboard p2_bb = m_and(BetweenBB[pao][bk],
			m_and(ei.attackKingPaoCan[BLACKCOLOR],occ));  // pao_eat_att = A
		int p2 = pop_1st_bit(&p2_bb);
		Bitboard p1_bb = m_and(BetweenBB[bk][p2],occ);
		int p1 = pop_1st_bit(&p1_bb);

		// xray
		set_bit(POSITION->DYN->white_xray,p1);
		set_bit(POSITION->DYN->white_xray,p2);

		xray_white_list[p1] = pao;
		xray_white_list[p2] = pao;
		// 用来评估中炮(铁门栓), 底炮, 窝心炮,马....
		set_bit(ei.ZhongDiPaoBB,pao);  // board_display(board,"中炮或底炮\n",stdout);

		set_bit(ei.attackKingBoard,pao);
	}


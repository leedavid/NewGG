for(int i = 0; i < RPao_num(); i++){
	
	int s = S90_from_piecelist(POSITION,RPAO,i);
	Bitboard A = ei.RPaoAtt[i];

	// 1, 炮吃子将军, 
	Bitboard ckatt = m_and(bitboard_occ_black,
		m_and(A,ei.attackKingPaoCan[BLACKCOLOR]));
	if(m128_is_have_bit(ckatt)){  // 红炮能吃子将军
		ei.attPoint[WHITECOLOR] += PaoCan_Eat_Check;  
		// 安全的吃子将军
		if(have_bit(white_safe,ckatt)){
			ei.attPoint[WHITECOLOR] += PaoCan_Safe_Eat_Check;
			set_bit(ei.attackKingBoard,s);   
		}
	}
	// 2. 炮不吃子直接将军
	Bitboard B = _mm_andnot_si128(occ,rook_attacks_bb(s,occ));  // 炮不吃子能走到的棋格
	ckatt = m_and(B,ei.attackKingPaoCan[BLACKCOLOR]);
	if(m128_is_have_bit(ckatt)){  // 炮不吃子直接将军
		ei.attPoint[WHITECOLOR] += PaoCan_Direct_Check;  
		// 安全的不吃子将军
		if(have_bit(white_safe,ckatt)){
			ei.attPoint[WHITECOLOR] += PaoCan_Safe_Direct_Check;
			set_bit(ei.attackKingBoard,s);   
		}
	}

	// 3. 炮能垒将
	if(m128_is_have_bit(m_and(B,
		_mm_andnot_si128(BetweenBB[s][bk],POSITION->DYN->white_pao_null)))){
			ei.attPoint[WHITECOLOR] += PaoCan_TwoPao_Check;            // 3. 炮能垒将
		set_bit(ei.attackKingBoard,s);   
	}

	if(bit_is_set(PaoCanAttKing[bk],s)){                // 有炮加入了进攻.要不在宫内哇
		if(m128_is_have_bit(m_and(A,KingAttackZone[bk]))){
			set_bit(ei.attackKingBoard,s);                         // 做一个标志
			// 炮能控制将步
			ei.kingAdjacentZoneAttacksCount[WHITECOLOR] += 1;				
		}
		//// 空炮
		//if(m128_is_have_bit(m_and(B,KingAttackZone[bk]))){ // 空炮也算在进攻
		//	set_bit(ei.attackKingBoard,s);                          // 做一个标志
		//}
	}
}

for(int i = 0; i < BPao_num(); i++){

	int s = S90_from_piecelist(POSITION,BPAO,i);
	Bitboard A = ei.BPaoAtt[i];

	// 1, 炮吃子将军, 
	Bitboard ckatt = m_and(bitboard_occ_white,
		m_and(A,ei.attackKingPaoCan[WHITECOLOR]));
	if(m128_is_have_bit(ckatt)){  // 炮能吃子将军
		ei.attPoint[BLACKCOLOR] += PaoCan_Eat_Check;  
		// 安全的吃子将军
		if(have_bit(black_safe,ckatt)){
			ei.attPoint[BLACKCOLOR] += PaoCan_Safe_Eat_Check;
			set_bit(ei.attackKingBoard,s);   
		}
	}
	// 2. 炮不吃子直接将军
	Bitboard B = _mm_andnot_si128(occ,rook_attacks_bb(s,occ));  // 炮不吃子能走到的棋格
	ckatt = m_and(B,ei.attackKingPaoCan[WHITECOLOR]);
	if(m128_is_have_bit(ckatt)){  // 炮不吃子直接将军
		ei.attPoint[BLACKCOLOR] += PaoCan_Direct_Check;  
		// 安全的不吃子将军
		if(have_bit(black_safe,ckatt)){
			ei.attPoint[BLACKCOLOR] += PaoCan_Safe_Direct_Check;
			set_bit(ei.attackKingBoard,s);   
		}
	}

	// 3. 炮能垒将
	if(m128_is_have_bit(m_and(B,
		_mm_andnot_si128(BetweenBB[s][rk],POSITION->DYN->black_pao_null)))){
			ei.attPoint[BLACKCOLOR] += PaoCan_TwoPao_Check;            // 3. 炮能垒将
			set_bit(ei.attackKingBoard,s);   
	}

	if(bit_is_set(PaoCanAttKing[rk],s)){                // 有炮加入了进攻.要不在宫内哇
		if(m128_is_have_bit(m_and(A,KingAttackZone[rk]))){
			set_bit(ei.attackKingBoard,s);                         // 做一个标志
			// 炮能控制将步
			ei.kingAdjacentZoneAttacksCount[BLACKCOLOR] += 1;				
		}
		//// 空炮
		//if(m128_is_have_bit(m_and(B,KingAttackZone[rk]))){ // 空炮也算在进攻
		//	set_bit(ei.attackKingBoard,s);                          // 做一个标志
		//}
	}
}
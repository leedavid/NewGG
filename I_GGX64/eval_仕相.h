
// 红相
for(int i = 0; i < RXiang_num(); i++){
	int s = S90_from_piecelist(POSITION,RXIANG,i);
	// 如果这个相被炮牵制了,就不能走了
	if(bit_is_set(POSITION->DYN->black_xray,s)){
		continue;
	}
	Bitboard A = xiang_attacks_bb(s,occ);
	ei.RShiXiangAtt = m128_bb_or_bb(ei.RShiXiangAtt,A);
	POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,A); 

	// 得到相保护自己的棋子的分
	A = m_and(A,occ);
	while (m128_is_have_bit(A))	{
		int p1 = pop_1st_bit(&A);
		valu += Point_R_XianProtectPoint[PB90(p1)];
	}
}

// black 相
for(int i = 0; i < BXiang_num(); i++){
	int s = S90_from_piecelist(POSITION,BXIANG,i);
	// 如果这个相被炮牵制了,就不能走了
	if(bit_is_set(POSITION->DYN->white_xray,s)){
		continue;
	}
	Bitboard A = xiang_attacks_bb(s,occ);
	ei.BShiXiangAtt = m128_bb_or_bb(ei.BShiXiangAtt,A);
	POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,A); 

	// 得到相保护自己的棋子的分
	A = m_and(A,occ);
	while (m128_is_have_bit(A))	{
		int p1 = pop_1st_bit(&A);
		valu -= Point_B_XianProtectPoint[PB90(p1)];
	}
}

for(int i = 0; i < RShi_num(); i++){
	int s = S90_from_piecelist(POSITION,RSHI,i);
	// 如果这个仕被炮牵制了,就不能走了
	if(bit_is_set(POSITION->DYN->black_xray,s)){
		continue;
	}
	Bitboard A = shi_attacks(s);
	ei.RShiXiangAtt = m128_bb_or_bb(ei.RShiXiangAtt,A);
	POSITION->DYN->attack_white 	= m128_bb_or_bb(POSITION->DYN->attack_white,A); 
}

for(int i = 0; i < BShi_num(); i++){
	int s = S90_from_piecelist(POSITION,BSHI,i);
	// 如果这个仕被炮牵制了,就不能走了
	if(bit_is_set(POSITION->DYN->white_xray,s)){
		continue;
	}
	Bitboard A = shi_attacks(s);
	ei.BShiXiangAtt = m128_bb_or_bb(ei.BShiXiangAtt,A);
	POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,A); 
}






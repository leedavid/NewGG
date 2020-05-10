
	//***********************************************************
	// 红炮 先算炮, 或马, 因为炮可能牵制对方的车,马,
	//***********************************************************
	for(int i = 0; i < RPao_num(); i++){
		int s = S90_from_piecelist(POSITION,RPAO,i);		
		// -------------------------------------------------------------------------------------------- 
		// 1. 炮的正常吃子, 仅是隔子打子.
		// --------------------------------------------------------------------------------------------
		Bitboard A = pao_eat_attacks_bb(s,occ); 
		ei.RPaoAtt[i] = A;
		POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,A); 
		// 将军检测
		if(have_bit(A,bit_bk)){
			set_bit(POSITION->DYN->black_king_check,s);      // 在将军
		}  
		// 炮的牵制放到弱子评估中.
	}  // rpao end
	//***********************************************************
	// 黑炮 先算炮, 或马, 因为炮可能牵制对方的车,马,
	//***********************************************************
	for(int i = 0; i < BPao_num(); i++){
		int s = S90_from_piecelist(POSITION,BPAO,i);
		Bitboard A = pao_eat_attacks_bb(s,occ); 
		ei.BPaoAtt[i] = A;
		POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,A); 
		// 将军检测
		if(have_bit(A,bit_rk)){
			set_bit(POSITION->DYN->white_king_check,s);      // 在将军
		}	
	} // bpao end
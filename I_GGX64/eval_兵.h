	


       // 红兵
		Bitboard p = bitboard_white_pawn;
		Bitboard B = p;
		//Bitboard Btmp;
		// 向前一步.
		B = _mm_andnot_si128(_mm_load_si128((__m128i*)Rank0BB),B);
		m128_RightShift(B,9);
		ei.attackedBy[RPAWN] = B;   // 第一次只要直接赋值
		POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,B);	
		B = m128_bb_and_bb(B,bit_bk);
		m128_LeftShift(B,9);	
		POSITION->DYN->black_king_check = m128_bb_or_bb(POSITION->DYN->black_king_check,B);
		// 过河兵	
		//fen 9/4k4/3a5/1P7/9/3N1R3/4r4/4Bn3/9/2BK1p3 w - - 0 0
		if(have_bit(p,_mm_load_si128((__m128i*)RpawnOverBB))){
			p = m128_bb_and_bb(p,_mm_load_si128((__m128i*)RpawnOverBB));
			// 兵将一线的加分
			Bitboard bKPC;
			bKPC = m128_bb_and_bb(ei.attackKingCheCan[WHITECOLOR],p);
			while (m128_is_have_bit(bKPC)){
				int kpawnche = pop_1st_bit(&bKPC);
				if(StoX(kpawnche) != StoX(rk)){
					continue;
				}
				else if(PB90[kpawnche] == RPAWN){ //fen 4ka3/4aP3/2n5b/4p1N1p/p5b2/4R4/1r2P3P/2r1B4/4A1C2/c1BA1K3 w
					if(m128_is_have_bit(m128_bb_and_bb(
						one_rpawn_rk_attacks(kpawnche),attacks_by_rpawn_rk(bk)))){ //board_display(POSITION,"将支撑兵!!");							
							ei.Rattack_B_Count += King_CheSameLineAtt ;
							break;
					}
				}
			}						
			//------- 过河兵数量的加分
			int gh_num  = count_1s(_mm_andnot_si128(_mm_load_si128((__m128i*)Rank0BB),p));	// 去了底线兵
			valu       += PAWN_NUM_OVER_RIVER_point[gh_num];
			B = p;
			//------- 如果对方没有仕了,要加分哇
			int yshi    = POSITION->pieceCount[BSHI];
			//int pnum    = 0;
			while(m128_is_have_bit(B)){ // 红兵
				int pawn = pop_1st_bit(&B);				
				valu += point_B_01Shi_R_Pawn90[yshi][pawn];   // 对方少仕后我方兵的加分
				if(yshi == 0){
					if(   (ei.R_att_Bside[BK_RIGHT] & (KS_S_CHE_MY_SIDE_1_OPEN + KS_S_CHE_MY_SIDE_2_OPEN))
						||(ei.R_att_Bside[BK_LEFT]  & (KS_S_CHE_MY_SIDE_1_OPEN + KS_S_CHE_MY_SIDE_2_OPEN))){
							valu += point_B_01Shi_R_Pawn90_My_CheOpen[pawn]; //再加一些分
                     
							// 比对一下车兵和对方的仕的数量
							// 2车1兵对2仕,1车1兵对1仕,如果对方有炮在防守,就要减一个. 如果对方有车在防守,就要减一个.
							if(StoY(bk) == 0x0){
								if(pawn == 0x0d){

								}
							}

					}


					//
				}
				int pawnSafe = PrePawnAttKingMul_Safe[yshi][pawn][bk];
				if(pawnSafe){
					valu += pawnSafe;
					if(StoX(pawn) == 0x4){
						ei.R_att_Bside[BK_RIGHT] |= KS_S_PAWN_SIDE_ATT;
						ei.R_att_Bside[BK_LEFT]  |= KS_S_PAWN_SIDE_ATT;
					}
					else{
						ei.R_att_Bside[King_4_Side(pawn)] |= KS_S_PAWN_SIDE_ATT;	
					}
				}
			}
			B = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),p);  // 去了左面兵
			m128_RightShift(B,1);                   //所有红兵向左一步
			ei.attackedBy[RPAWN] = m128_bb_or_bb(ei.attackedBy[RPAWN],B);
			POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,B);
			B = m128_bb_and_bb(B,bit_bk);
			m128_LeftShift(B,1);		
			POSITION->DYN->black_king_check = m128_bb_or_bb(POSITION->DYN->black_king_check,B);
			//
			B = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),p);
			m128_LeftShift(B,1);                   //所有红兵向右一步
			ei.attackedBy[RPAWN] = m128_bb_or_bb(ei.attackedBy[RPAWN],B);
			POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,B);
			B = m128_bb_and_bb(B,bit_bk);
			m128_RightShift(B,1);
			POSITION->DYN->black_king_check = m128_bb_or_bb(POSITION->DYN->black_king_check,B);

			// 得到卒保护自己的棋子的分
			B = m128_bb_and_bb(ei.attackedBy[RPAWN],occ);
			while (m128_is_have_bit(B))	{
				int p1 = pop_1st_bit(&B);
				valu += Point_R_pawn_Att_Score[PB90[p1]];
			}			
		}	


		// black 兵
		p = bitboard_black_pawn;
		B = p;
		// 向前一步.
		B = _mm_andnot_si128(_mm_load_si128((__m128i*)Rank9BB),B);
		m128_LeftShift(B,9);
		ei.attackedBy[BPAWN] = B;   // 第一次只要直接赋值
		POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,B);
		B = m128_bb_and_bb(B,bit_rk);
		m128_RightShift(B,9);
		POSITION->DYN->white_king_check = m128_bb_or_bb(POSITION->DYN->white_king_check,B);
		// 过河兵	
		if(have_bit(p,_mm_load_si128((__m128i*)BpawnOverBB))){
			p = m128_bb_and_bb(p,_mm_load_si128((__m128i*)BpawnOverBB));
			Bitboard bKPC;
			bKPC = m128_bb_and_bb(ei.attackKingCheCan[BLACKCOLOR],p);
			while (m128_is_have_bit(bKPC)){
				int kpawnche = pop_1st_bit(&bKPC);
				if(StoX(kpawnche) != StoX(bk)){
					continue;
				}
				else if(PB90[kpawnche] == BPAWN){ //再看一下我方的能不能吃到对方的将						
					if(m128_is_have_bit(m128_bb_and_bb(
						one_bpawn_bk_attacks(kpawnche),attacks_by_bpawn_bk(rk)))){ //board_display(POSITION,"将支撑兵!!"); //fen 3k1a3/Rc2a4/4b1n2/4p4/P1p1n1bC1/4RN3/2P1Pr2P/N3B1r2/3pA4/2BAK4 w					
							ei.Battack_R_Count += King_CheSameLineAtt ;
							break;
					}
				}
			}

			//------- 过河兵数量的加分
			int gh_num  = count_1s(_mm_andnot_si128(_mm_load_si128((__m128i*)Rank9BB),p));	// 去了底线兵
			valu       -= PAWN_NUM_OVER_RIVER_point[gh_num]; // fen 3ckab2/4a4/4b4/P2R1P2p/2r1P4/P1N6/5n2P/3AB4/9/2BK1A3 w - - 5 5
			
			B = p; // fen 4ka3/1PP1a4/9/9/4p1p2/7R1/4p4/4B4/3rA4/3AK1B2 b
			//------- 如果对方没有仕了,要加分哇
			int yshi    = POSITION->pieceCount[RSHI];
			//int pnum    = 0;
			while(m128_is_have_bit(B)){
				int pawn = pop_1st_bit(&B);		//fen 1N1k1a3/1N7/3a5/9/4C3p/4p4/4p3n/4B4/1n7/2BA1K3 b - - 0 0 	y	
				valu -= point_R_01Shi_B_Pawn90[yshi][pawn];
				if(yshi == 0){
					if(   (ei.B_att_Rside[RK_RIGHT] & (KS_S_CHE_MY_SIDE_1_OPEN + KS_S_CHE_MY_SIDE_2_OPEN))
						||(ei.B_att_Rside[RK_LEFT]  & (KS_S_CHE_MY_SIDE_1_OPEN + KS_S_CHE_MY_SIDE_2_OPEN))){
							valu -= point_R_01Shi_B_Pawn90_My_CheOpen[pawn]; //再加一些分
					}
				}
				int pawnSafe = PrePawnAttKingMul_Safe[yshi][pawn][rk];
				if(pawnSafe){
					valu -= pawnSafe;
					if(StoX(pawn) == 0x4){
						ei.B_att_Rside[RK_RIGHT]        |= KS_S_PAWN_SIDE_ATT;  //有兵另入进攻了
						ei.B_att_Rside[RK_LEFT]         |= KS_S_PAWN_SIDE_ATT;
					}
					else{
						ei.B_att_Rside[King_4_Side(pawn)] |= KS_S_PAWN_SIDE_ATT;	
					}
				}
			}

			B = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),p);  // 去了左面兵
			m128_RightShift(B,1);                   //所有红兵向左一步
			ei.attackedBy[BPAWN] = m128_bb_or_bb(ei.attackedBy[BPAWN],B);
			POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,B);
			B = m128_bb_and_bb(B,bit_rk);
			m128_LeftShift(B,1);
			POSITION->DYN->white_king_check = m128_bb_or_bb(POSITION->DYN->white_king_check,B);
			//
			B = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),p);
			m128_LeftShift(B,1);                   //所有红兵向右一步
			ei.attackedBy[BPAWN] = m128_bb_or_bb(ei.attackedBy[BPAWN],B);
			POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,B);
			B = m128_bb_and_bb(B,bit_rk);
			m128_RightShift(B,1);
			POSITION->DYN->white_king_check = m128_bb_or_bb(POSITION->DYN->white_king_check,B);

			// 得到黑卒保护自己的棋子的分
			B = m128_bb_and_bb(ei.attackedBy[BPAWN],occ);
			while (m128_is_have_bit(B))	{
				int p1 = pop_1st_bit(&B);
			    valu -= Point_B_pawn_Att_Score[PB90[p1]];
			}
		}

		
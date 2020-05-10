
	//***********************************************************
	// 红马 ( 第二次评估 )
	//***********************************************************
	for(int i = 0; i < RMa_num(); i++){
		int s = S90_from_piecelist(POSITION,RMA,i);
		Bitboard A = ei.RmaAtt[i];

		// 1. 看一下能不能垒将
		if(m128_is_have_bit(m_and(POSITION->DYN->white_pao_null,A))){
			ei.attPoint[WHITECOLOR] += MaCanPaoNullCHeckPoint;
			ei.kingAdjacentZoneAttacksCount[WHITECOLOR] ++;
			set_bit(ei.attackKingBoard,s);                  // 做一个标志, 如果马能垒将,则把马也加入进攻的棋子
		}

		Bitboard ckatt = m_and(A,ei.attackKingMaCan[BLACKCOLOR]);
		// 2. 看一下能不能直接将
		if(m128_is_have_bit(ckatt)){
			ei.attPoint[WHITECOLOR] += MaCanCHeckPoint;
			set_bit(ei.attackKingBoard,s);                  // 做一个标志

			// 看一下是不是安全的将
			if(have_bit(white_safe,ckatt)){
				ei.attPoint[WHITECOLOR] += MaSafeCheckBonus * count_1s(m_and(white_safe,ckatt));
				ei.kingAdjacentZoneAttacksCount[WHITECOLOR] ++;
			}
		}


		// 3. 马攻击到对方将的走步
		if(m128_is_have_bit(m_and(A,KingAttackZone[bk]))){
			set_bit(ei.attackKingBoard,s);  
			Bitboard bb = m_and(A,one_bpawn_bk_attacks(bk));				
			ei.kingAdjacentZoneAttacksCount[WHITECOLOR] += count_1s(bb);	
		}

		// 下面为灵活性评价, 
		A = m_and(A,Ma_Pseudo_Good_Att[s]);		  // 马的所有好步
		A = _mm_andnot_si128(LowBB[0x7],A);                   // 去了下面二层
		A = _mm_andnot_si128(bitboard_occ_white,A);           // 去了自已的棋格
		B = A;
		A = _mm_andnot_si128(POSITION->DYN->attack_black,A);  // 去了对方的攻击棋格

		int mob = count_1s(A);
		valu += Point_MaMob(MaMoveAddNoProtect[mob]);

		if(mob == 0){ // 马没有好步了
			if(m128_is_have_bit(B)){  // 原来有好步
				if(m128_is_have_bit(_mm_andnot_si128(ei.BpawnAtt,B)) == FALSE){
					valu -= point(32,48); // 但现在给兵控制了,没有好步了
				}
			}
		}
	}
	//***********************************************************
	// 黑马 ( 第二次评估 )
	//***********************************************************
	for(int i = 0; i < BMa_num(); i++){
		int s = S90_from_piecelist(POSITION,BMA,i);
		Bitboard A = ei.BmaAtt[i];

		// 1. 看一下能不能垒将
		if(m128_is_have_bit(m_and(POSITION->DYN->black_pao_null,A))){
			ei.attPoint[BLACKCOLOR] += MaCanPaoNullCHeckPoint;
			ei.kingAdjacentZoneAttacksCount[WHITECOLOR] ++;
			set_bit(ei.attackKingBoard,s);                  // 做一个标志, 如果马能垒将,则把马也加入进攻的棋子
		}

		Bitboard ckatt = m_and(A,ei.attackKingMaCan[WHITECOLOR]);
		// 2. 看一下能不能直接将
		if(m128_is_have_bit(ckatt)){
			ei.attPoint[BLACKCOLOR] += MaCanCHeckPoint;
			set_bit(ei.attackKingBoard,s);                  // 做一个标志

			// 看一下是不是安全的将
			if(have_bit(black_safe,ckatt)){
				ei.attPoint[BLACKCOLOR] += MaSafeCheckBonus * count_1s(m_and(black_safe,ckatt));
				ei.kingAdjacentZoneAttacksCount[BLACKCOLOR] ++;
			}
		}

		// 3. 马攻击到对方将的走步
		if(m128_is_have_bit(m_and(A,KingAttackZone[rk]))){
			set_bit(ei.attackKingBoard,s);  
			Bitboard bb = m_and(A,one_rpawn_rk_attacks(rk));				
			ei.kingAdjacentZoneAttacksCount[BLACKCOLOR] += count_1s(bb);	
		}
				

		A = m_and(A,Ma_Pseudo_Good_Att[s]);		
		A = _mm_andnot_si128(UpBB[0x2],A);   //A = _mm_andnot_si128(RankBB_A[0x0],A);
		A = _mm_andnot_si128(bitboard_occ_black,A);           // 去了自已人的棋格
		B = A;
		A = _mm_andnot_si128(POSITION->DYN->attack_white,A);  //

		int mob = count_1s(A);
		valu -= Point_MaMob(MaMoveAddNoProtect[mob]);

		if(mob == 0){ // 马没有好步了 POSITION->DYN->white_xray
			if(m128_is_have_bit(B)){  // 原来有好步
				if(m128_is_have_bit(_mm_andnot_si128(ei.RpawnAtt,B)) == FALSE){
					valu += point(32,48); // 但现在给兵控制了,没有好步了
				}
			}// fen 1c2kab2/4a1n2/b8/p2P2p1p/9/2P3P2/P1R6/3A1A3/3N5/c1BnK4 w - - 39 39
		}
	}
	
	
    //// ***********************************************************
	//// 窝心马的评估.   board_display(board,"车 窝心马!!",stdout);
	////*********************************************************** 
	//if(ei.ev_stat & EV_STAT_Rwoxin_By_B){   // 红方被窝心马
	//	ei.Battack_R_Count += Wo_Xing_Ma_att_point; // 
	//    valu -= point(64,512);
	//}

	//if(ei.ev_stat & EV_STAT_Bwoxin_By_R){   // 黑方被窝心马
	//	ei.Rattack_B_Count += Wo_Xing_Ma_att_point; // 
	//	 valu += point(64,512);
	//}
	//fen 3a3CC/4k4/bc3ac2/1R6p/6b2/2P2p3/P3r3P/9/4N4/3AKA3 w - - 16 16
	//加上炮的可能将军分，
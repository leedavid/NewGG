

// 红车
for(int i = 0; i < RChe_num(); i++){
	int s = S90_from_piecelist(POSITION,RCHE,i);

	Bitboard A = ei.RcheAtt[i];
	// -------------------------------------------------------------------------------------------- 
	// 1. 移动性能 Mobility
	// -------------------------------------------------------------------------------------------- 
	int mob; 
	Bitboard ratt = m_and(A,RankBB_A[StoY(s)]);
	ratt = _mm_andnot_si128(bitboard_occ_white,ratt);           // 去了自己的棋格
	ratt = _mm_andnot_si128(POSITION->DYN->attack_black,ratt);  // 去了对方的攻击的棋格
	mob =  count_1s(ratt);
	valu += r_CheMove[mob];  // 左右移动的分
	Bitboard fatt = m_and(A,FileBB_A[StoX(s)]);
	fatt = _mm_andnot_si128(bitboard_occ_white,fatt);
	fatt = _mm_andnot_si128(POSITION->DYN->attack_black,fatt);  //
	mob = count_1s(fatt);
	valu += f_CheMove[mob];
	
    // 1, 红车能攻击到对方. 
	if(m128_is_have_bit(m_and(A,KingAttackZone[bk]))){
		set_bit(ei.attackKingBoard,s);                  // 做一个标志, 车在进攻了
	}

	if(bit_is_set(POSITION->DYN->black_xray,s)){
		//还要减一些,因为这个车被牵制了.
		ei.attPoint[WHITECOLOR] -= Rook_CanNotMove_Att;
		continue;  // 这个车被牵制了
	}

	// ****************************************************************
	Bitboard ckatt = m_and(A,ei.attackKingCheCan[BLACKCOLOR]);
	if(m128_is_have_bit(ckatt)){  // 红车能将军

		set_bit(ei.attackKingBoard,s);  
		ei.kingAdjacentZoneAttacksCount[WHITECOLOR] ++;         // 红车能直接将

		// 看一下是不是安全的将
		if(have_bit(white_safe,ckatt)){
			ei.attPoint[WHITECOLOR] += RookSafeCheckBonus * count_1s(m_and(white_safe,ckatt));
		}

		//看一下是不是将军一线了,
		if(bit_is_set(A,rk) && StoX(s) == StoX(rk)){ //fen 4ka3/4aR3/2n5b/4p1N1p/p5b2/4R4/1r2P3P/2r1B4/4A1C2/c1BA1K3 w
			ei.attPoint[WHITECOLOR] += King_CheSameLineAtt;
		}

		// 看一下能不能垒将
		if(m128_is_have_bit(m_and(POSITION->DYN->white_pao_null,A))){
			ei.attPoint[WHITECOLOR] = CheCanPaoNullCHeckPoint;
		}

		if(have_bit(A,bit_bk)){  // 正在将军了, 这个一定要加上, 因为这个和
			continue;
		}


		//如果将不在原位，或没有二个仕 
		//fen 5kb2/4a4/3ab4/9/5R3/2r6/5r3/9/4A4/2B1KA3 b - - 0 0</
		//这个因为是在将军，
		if(0x04 != bk || BShi_num() == 0){   // 将不在原位，或没有仕了．
			while(m128_is_have_bit(ckatt)){   
				int ckq = pop_1st_bit(&ckatt);
				if(WhiteSEE(POSITION,MOVE_FromTo(s,ckq)) > 0){
					if(StoX(ckq) == StoX(bk)){  // 可以上下将,
						ei.rcx += 2;
					}
					else{
						ei.rcy += 2;
					}
				}
				else{
					if(StoX(ckq) == StoX(bk)){
						ei.rcx++;
					}
					else{
						ei.rcy++;
					}
				}
			}
		} // 二车错杀的情况		
     }
}

// ----------------------------------------------------------------------------
// 黑车 **************************************************************
// ----------------------------------------------------------------------------
//che_check = 0;
for(int i = 0; i < BChe_num(); i++){
	int s = S90_from_piecelist(POSITION,BCHE,i);

	Bitboard A = ei.BcheAtt[i];
	// -------------------------------------------------------------------------------------------- 
	// 1. 移动性能 Mobility
	// -------------------------------------------------------------------------------------------- 
	int mob; 
	Bitboard ratt = m_and(A,RankBB_A[StoY(s)]);
	ratt = _mm_andnot_si128(bitboard_occ_black,ratt);  
	ratt = _mm_andnot_si128(POSITION->DYN->attack_white,ratt);  //
	mob =  count_1s(ratt);
	valu -= r_CheMove[mob];  // 左右移动的分
	Bitboard fatt = m_and(A,FileBB_A[StoX(s)]);
	fatt = _mm_andnot_si128(bitboard_occ_black,fatt);
	fatt = _mm_andnot_si128(POSITION->DYN->attack_white,fatt);  //
	mob = count_1s(fatt);
	valu -= f_CheMove[mob];

	// 1, 黑车能攻击到对方. 
	if(m128_is_have_bit(m_and(A,KingAttackZone[rk]))){
		set_bit(ei.attackKingBoard,s);                  // 做一个标志, 车在进攻了
	}

	if(bit_is_set(POSITION->DYN->white_xray,s)){
		//还要减一些,因为这个车被牵制了.
		ei.attPoint[BLACKCOLOR] -= Rook_CanNotMove_Att;
		continue;  // 这个车被牵制了
	}

	// ****************************************************************
    // 黑车
	Bitboard ckatt = m_and(A,ei.attackKingCheCan[WHITECOLOR]);
	if(m128_is_have_bit(ckatt)){

		set_bit(ei.attackKingBoard,s);  
		ei.kingAdjacentZoneAttacksCount[BLACKCOLOR] ++;         // 红车能直接将
		
		// 看一下是不是安全的将
		if(have_bit(black_safe,ckatt)){
			ei.attPoint[BLACKCOLOR] += RookSafeCheckBonus * count_1s(m_and(black_safe,ckatt));
		}

		//看一下是不是将军一线了,
		if(bit_is_set(A,bk) && StoX(s) == StoX(bk)){ //fen 4ka3/4aR3/2n5b/4p1N1p/p5b2/4R4/1r2P3P/2r1B4/4A1C2/c1BA1K3 w
			ei.attPoint[BLACKCOLOR] += King_CheSameLineAtt;
		}

		// 看一下能不能垒将
		if(m128_is_have_bit(m_and(POSITION->DYN->black_pao_null,A))){
			ei.attPoint[BLACKCOLOR] += CheCanPaoNullCHeckPoint;
		}

		if(have_bit(A,bit_rk)){  // 正在将军了
			continue;
		}

		//如果将不在原位，或没有二个仕fen 3a1k3/4a4/4b1C2/5RP1p/6b2/5r2P/rn4N2/4C4/3RK4/9 b - - 0 0
		if(0x55 != rk || RShi_num() == 0) {      // 将不在原位		
			//ckatt = _mm_andnot_si128(BetweenBB[s][rk],ckatt); //去了相同的棋格
			while(m128_is_have_bit(ckatt)){ 
				int ckq = pop_1st_bit(&ckatt);
				if(BlackSEE(POSITION,MOVE_FromTo(s,ckq)) > 0){
					if(StoX(ckq) == StoX(rk)){
						ei.bcx += 2;
					}
					else{
						ei.bcy += 2;
					}
				}
				else{//fen 2b1kr3/4R4/4b4/R1p5p/9/2P1n1B1P/P8/3r5/3N5/3K1A3 b - - 0 0
					if(StoX(ckq) == StoX(rk)){
						ei.bcx++;
					}
					else{
						ei.bcy++;
					}
				}
			}				
		}
	}		
}
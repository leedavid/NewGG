
	// 第二次只评价过河兵
	// 红兵
	p = m_and(bitboard_white_pawn,_mm_load_si128((__m128i*)RpawnOverBB));
	if(m128_is_have_bit(p)){
		// 兵将一线的加分
		//Bitboard bKPC;
		//bKPC = m_and(ei.attackKingCheCan[WHITECOLOR],p);
		//while (m128_is_have_bit(bKPC)){
		//	int kpawnche = pop_1st_bit(&bKPC);  //fen 4ka3/4aP3/2n5b/4p1N1p/p5b2/4R4/1r2P3P/2r1B4/4A1C2/c1BA1K3 w
		//	if(m128_is_have_bit(m_and(
		//		one_rpawn_rk_attacks(kpawnche),attacks_by_rpawn_rk(bk)))){ //board_display(POSITION,"将支撑兵!!");							
		//			ei.Rattack_B_Count += King_CheSameLineAtt ;
		//			break;
		//	}
		//}						
		//------- 过河兵数量的加分
		int gh_num  = count_1s(_mm_andnot_si128(_mm_load_si128((__m128i*)Rank0BB),p));	// 去了底线兵
		valu       += PAWN_NUM_OVER_RIVER_point[gh_num];
		B = p;
		//------- 如果对方没有仕了,要加分哇
		int yshi    = POSITION->pieceCount[BSHI];
		//int pnum    = 0;
		while(m128_is_have_bit(B)){  // 红兵
			int pawn = pop_1st_bit(&B);			

			//fen 2ba1k3/3P5/9/9/p3pNb2/8p/P1c6/2N1BA3/4A1n2/2BK5 w - - 10 10
			//兵将不在一边,要扣分
			if(StoY(pawn) <= 0x2){
				if(!IsOnSameSide(pawn,bk)){
					valu -= PawnNotOnSameSide[yshi];
				}
			}

			valu += point_B_01Shi_R_Pawn90[yshi][pawn];              //过河兵才加分
			int pawnSafe = PrePawnAttKingMul_Safe[yshi][pawn][bk];   //兵控制将的分
			if(pawnSafe){
				// 1.看一下兵能不能将军, 转化为bcy,bcx, 这个就厉害了
				if(m128_is_have_bit(m_and( // 这个兵可以将军了
					one_rpawn_rk_attacks(pawn),attacks_by_rpawn_rk(bk)))){
						// 还要判断一下,1,要兵大于对方的将, 

						set_bit(ei.attackKingBoard,pawn);                         // 做一个标志

						ei.kingAdjacentZoneAttacksCount[WHITECOLOR] ++;

						if(bit_is_set(ei.attackKingCheCan[WHITECOLOR],pawn)){
							ei.attPoint[WHITECOLOR] += King_CheSameLineAtt ; 
						}
						//如果对方的将不在原位,如方只有一个仕没有
						if(StoY(pawn) != 0x0){						
							ei.rcy ++;	
							if(ABS(StoX(pawn) - 0x4) <= 1){
								if(PB90(pawn - 9) != BSHI || yshi <= 1 || bk != 0x4){
									ei.rcy++;
								}
							}
						}
						valu += pawnSafe;
				}
				else{ //2.看一下兵是不是不能前进了,
					if(StoY(pawn) < StoY(bk)){
					}
					else{ //POSITION->DYN->attack_black 兵没有好步
						if(m128_is_have_bit( // fen 1rbak4/1C2a4/4b4/6P2/p6PC/2B6/P1pn5/BRnA5/3KA4/9 r
							_mm_andnot_si128(
							m128_bb_or_bb(POSITION->DYN->attack_black,bitboard_occ_white),
							RPawnGoodMove[pawn]))){
							valu += pawnSafe;
						}	
					}
				}
			}
		}
	}

	// 黑兵
	p = m_and(bitboard_black_pawn,_mm_load_si128((__m128i*)BpawnOverBB));
	if(m128_is_have_bit(p)){

		//------- 过河兵数量的加分
		int gh_num  = count_1s(_mm_andnot_si128(_mm_load_si128((__m128i*)Rank9BB),p));	// 去了底线兵
		valu       -= PAWN_NUM_OVER_RIVER_point[gh_num]; // fen 3ckab2/4a4/4b4/P2R1P2p/2r1P4/P1N6/5n2P/3AB4/9/2BK1A3 w - - 5 5

		B = p; // fen 4ka3/1PP1a4/9/9/4p1p2/7R1/4p4/4B4/3rA4/3AK1B2 b
		//------- 如果对方没有仕了,要加分哇
		int yshi    = POSITION->pieceCount[RSHI];
		//int pnum    = 0;
		while(m128_is_have_bit(B)){
			int pawn = pop_1st_bit(&B);		//fen 1N1k1a3/1N7/3a5/9/4C3p/4p4/4p3n/4B4/1n7/2BA1K3 b - - 0 0 	y	
						
			//fen 2ba1k3/3P5/9/9/p3pNb2/8p/P1c6/2N1BA3/4A1n2/2BK5 w - - 10 10
			//兵将不在一边,要扣分
			if(StoY(pawn) >= 0x7){
				if(!IsOnSameSide(pawn,rk)){
					valu += PawnNotOnSameSide[yshi];
				}
			}
			
			valu -= point_R_01Shi_B_Pawn90[yshi][pawn];
			int pawnSafe = PrePawnAttKingMul_Safe[yshi][pawn][rk];
			if(pawnSafe){
				// 1.看一下兵能不能将军, 转化为bcy,bcx, 这个就厉害了
				if(m128_is_have_bit(m_and( // 这个兵可以将军了
					one_bpawn_bk_attacks(pawn),attacks_by_bpawn_bk(rk)))){
                   
					set_bit(ei.attackKingBoard,pawn);                         // 做一个标志

					ei.kingAdjacentZoneAttacksCount[BLACKCOLOR] ++;
					
					if(bit_is_set(ei.attackKingCheCan[BLACKCOLOR],pawn)){
						ei.attPoint[BLACKCOLOR] += King_CheSameLineAtt ; 
					}

					// 如果对方的将不在原位,如方只有一个仕没有
					if(StoY(pawn) != 0x9){						
						ei.bcy ++;	
						if(ABS(StoX(pawn) - 0x4) <= 1){
							if(PB90(pawn + 9) != RSHI || yshi <= 1 || rk != 0x55){
								ei.bcy++;
							}
						}
					}
					valu -= pawnSafe;
				}
				else{  //兵还不能将军, 看一下兵是不是不能前进了,
					if(StoY(pawn) > StoY(rk)){
					}
					else{ //POSITION->DYN->attack_black
						if(m128_is_have_bit( //fen 1rbak4/1C2a4/4b4/6P2/p6PC/2B6/P1pn5/BRnA5/3KA4/9 r
							_mm_andnot_si128(
							m128_bb_or_bb(POSITION->DYN->attack_white,bitboard_occ_black),
							BPawnGoodMove[pawn]))){
								valu -= pawnSafe;
						}
					}
				}
			}
		}
	}
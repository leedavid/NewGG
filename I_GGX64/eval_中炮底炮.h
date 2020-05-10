

//***********************************************************
	// 中炮的评估. (中炮,底炮)
	//*********************************************************** 
	Bitboard bzp = ei.ZhongDiPaoBB;
	while(m128_is_have_bit(bzp)){
		int msq    = pop_1st_bit(&bzp);
		uint8 mchess = PB90(msq);
		if(FALSE){
		}
		else if(mchess == RPAO){  // 有可能是红方中炮,底炮
			if(FALSE){
			}
			else if(StoX(msq) == StoX(bk)){ // 有可能是红方中炮

				// 看一下是不是在原位的中炮
				//if(msq == 0x43 && PB90(0x3A) == RPAWN && PB90(0x1F) == BPAWN && bk == 0x04){
				//	if(bit_is_set(POSITION->DYN->attack_black,0x1F)){
				//		continue;  //这个不是中炮哇
				//	}
				//}		

				ei.attPoint[WHITECOLOR] += MidPao_att_point;         // 中炮加攻击点
				// 还要判断一下是不是铁门栓
				if(bk == 0x04 && PB90(0x0D) == BSHI && PB90(0X16) != EMPTY){					
					//if((PIECE_SIDE(PB90(0x03)) == BLACK_TO_MOVE && PB90(0x03) == BSHI)	        // 只要将不能向左边移动,就是右边铁门栓	    			
					//	|| (bit_is_set(POSITION->DYN->attack_white,0x03))){ // 这个棋格受到对方的攻击 
					if(PB90(0x03) == BSHI){        // 只要将不能向左边移动,就是右边铁门栓	
						// 1, 车能不能攻击到将的 右边 底线, 
						for(int i = 0; i < RChe_num(); i++){
							int s = S90_from_piecelist(POSITION,RCHE,i);
							if(StoX(s) > 0x4){
								Bitboard C = rook_attacks_bb(s,_mm_andnot_si128(POSITION->byChessBB[RCHE],occ)); 
								C = m_and(C,m128_bb_or_bb(_mm_load_si128((__m128i*)Rank0BB),
									m_and(_mm_load_si128((__m128i*)TiMenBit_Pawn),UpBB[3])));
								if(m128_is_have_bit(C)){
									valu += TiMen_Che_att_Score;
									ei.attPoint[WHITECOLOR]  += TiMen_Che_att_point;
								}
							}
						}
						// 1, 如果兵在将的右肋,右上肋 则还要加上挡住的车
						Bitboard tbP = m_and(bitboard_white_pawn,
							m_and(RightBB[0x04],
							_mm_load_si128((__m128i*)TiMenBit_Pawn)));
						if(m128_is_have_bit(tbP)){
						  valu += TiMen_Pawn_att_Score;
						  ei.attPoint[WHITECOLOR]  += TiMen_Pawn_att_point;
						}
					    // 3, 将
						if(StoX(rk) > 0x4){
							Bitboard tkb = rook_attacks_bb(rk,
								_mm_andnot_si128(m128_bb_or_bb(POSITION->byChessBB[BCHE],
								tbP),occ));
							if(m128_is_have_bit(m_and(tkb,
								_mm_load_si128((__m128i*)TiMenBit_Pawn)))){
							  // print_bb(tkb);
							   valu += TiMen_King_att_Score;
							   ei.attPoint[WHITECOLOR]  += TiMen_King_att_point;
							}
						}
					    // 4, 如果马能攻击到将的右
						for(int i = 0; i < RMa_num(); i++){
							int s = S90_from_piecelist(POSITION,RMA,i);
							if(StoX(s) > 0x4){
								Bitboard A =  ma_to_king_attacks_bb(s,occ);  // 得到马的攻击位棋盘
								if(m128_is_have_bit(m_and(A,ei.attackKingMaCan[BLACKCOLOR]))){
								   valu += TiMen_Ma_att_Score;
								   ei.attPoint[WHITECOLOR]  += TiMen_Ma_att_point;
								}
							}
						}
					} // 右边铁门栓
					//if((PIECE_SIDE(PB90(0x05)) == BLACK_TO_MOVE && PB90(0x05) == BSHI)			    // 只要将不能向右边移动,就是左边铁门栓				
					//	|| (bit_is_set(POSITION->DYN->attack_white,0x05))){ // 这个棋格受到对方的攻击
					if(PB90(0x05) == BSHI) {
							// 1, 车能不能攻击到将的 右边 底线, 
							for(int i = 0; i < RChe_num(); i++){
								int s = S90_from_piecelist(POSITION,RCHE,i);
								if(StoX(s) < 0x4){
									Bitboard C = rook_attacks_bb(s,_mm_andnot_si128(POSITION->byChessBB[RCHE],occ)); 
									C = m_and(C,m128_bb_or_bb(_mm_load_si128((__m128i*)Rank0BB),
										m_and(_mm_load_si128((__m128i*)TiMenBit_Pawn),UpBB[3])));
									if(m128_is_have_bit(C)){
										valu += TiMen_Che_att_Score;
										ei.attPoint[WHITECOLOR]  += TiMen_Che_att_point;
									}
								}
							}
							// 1, 如果兵在将的右肋,右上肋 则还要加上挡住的车
							Bitboard tbP = m_and(bitboard_white_pawn,
								m_and(LeftBB[0x04],
								_mm_load_si128((__m128i*)TiMenBit_Pawn)));
							if(m128_is_have_bit(tbP)){
								valu += TiMen_Pawn_att_Score;
								ei.attPoint[WHITECOLOR]  += TiMen_Pawn_att_point;
							}
							// 3, 将
							if(StoX(rk) < 0x4){
								Bitboard tkb = rook_attacks_bb(rk,
									_mm_andnot_si128(m128_bb_or_bb(POSITION->byChessBB[RCHE],
									tbP),occ));
								if(m128_is_have_bit(m_and(tkb,
									_mm_load_si128((__m128i*)TiMenBit_Pawn)))){
									//print_bb(tkb);
									valu += TiMen_King_att_Score;
									ei.attPoint[WHITECOLOR]  += TiMen_King_att_point;
								}
							}
							// 4, 如果马能攻击到将的左
							for(int i = 0; i < RMa_num(); i++){
								int s = S90_from_piecelist(POSITION,RMA,i);
								if(StoX(s) < 0x4){
									Bitboard A =  ma_to_king_attacks_bb(s,occ);  // 得到马的攻击位棋盘
									if(m128_is_have_bit(m_and(A,ei.attackKingMaCan[BLACKCOLOR]))){
										valu += TiMen_Ma_att_Score;
										ei.attPoint[WHITECOLOR]  += TiMen_Ma_att_point;
									}
								}
							}
					}// 左边铁门栓
				} // if(bk == 0x04 && PB90(0x0D) == BSHI){	
			}// 有可能是红方中炮
			else if(StoY(msq) == StoY(bk)){ // 有可能是红方底炮
				
				if(pMat->searchInfo16 & CK_R_Only_1Che1PaoxPawn){	
					int palr = White_pawn_already_over_river(POSITION);
					if(palr == 0){
						continue;
					}
				}
				ei.attPoint[WHITECOLOR]  += Di_Pao_att_point;       // 底炮加攻击点
				//还要判断一下是不是受到对方的攻击
				if(bit_is_set(POSITION->DYN->attack_black,msq)){
					// 但还是给自己的马,兵,炮保护了,也要加分
					if(bit_is_set(POSITION->DYN->attack_white,msq)){
					}
					else{
					    ei.attPoint[WHITECOLOR]  -= Di_Pao_att_By_Other;
					}
				}
			}
		}
		else if(mchess == BPAO){  // 有可能是黑方中炮,底炮
			if(FALSE){
			}
			else if(StoX(msq) == StoX(rk)){ // 有可能是黑方中炮

				// 看一下是不是在原位的中炮
				//if(msq == 0x16 && PB90(0x3A) == RPAWN && PB90(0x1F) == BPAWN && rk == 0x55){
				//	if(bit_is_set(POSITION->DYN->attack_white,0x3A)){
				//		continue;  //这个不是中炮哇
				//	}
				//}
				ei.attPoint[BLACKCOLOR] += MidPao_att_point;         // 中炮加攻击点
				// 还要判断一下是不是铁门栓
				if(rk == 0x55 && PB90(0x4c) == RSHI && PB90(0X43) != EMPTY){					
					if(PB90(0x54) == RSHI){	        // 只要将不能向左边移动,就是右边铁门栓	
							// 1, 车能不能攻击到将的 右边 底线, 
							for(int i = 0; i < BChe_num(); i++){
								int s = S90_from_piecelist(POSITION,BCHE,i);
								if(StoX(s) > 0x4){
									Bitboard C = rook_attacks_bb(s,_mm_andnot_si128(POSITION->byChessBB[BCHE],occ)); 
									C = m_and(C,m128_bb_or_bb(_mm_load_si128((__m128i*)Rank9BB),
										m_and(_mm_load_si128((__m128i*)TiMenBit_Pawn),LowBB[6])));
									if(m128_is_have_bit(C)){
										valu -= TiMen_Che_att_Score;
										ei.attPoint[BLACKCOLOR]  += TiMen_Che_att_point;
									}
								}
							}
							// 1, 如果兵在将的右肋,右上肋 则还要加上挡住的车
							Bitboard tbP = m_and(bitboard_black_pawn,
								m_and(RightBB[0x04],
								_mm_load_si128((__m128i*)TiMenBit_Pawn)));
							if(m128_is_have_bit(tbP)){
								valu -= TiMen_Pawn_att_Score;
								ei.attPoint[BLACKCOLOR] += TiMen_Pawn_att_point;
							}
							// 3, 将
							if(StoX(bk) > 0x4){
								Bitboard tkb = rook_attacks_bb(bk,
									_mm_andnot_si128(m128_bb_or_bb(POSITION->byChessBB[BCHE],
									tbP),occ));
								if(m128_is_have_bit(m_and(tkb,
									_mm_load_si128((__m128i*)TiMenBit_Pawn)))){
									//print_bb(tkb);
									valu -= TiMen_King_att_Score;
									ei.attPoint[BLACKCOLOR] += TiMen_King_att_point;
								}
							}
							// 4, 如果马能攻击到将的右
							for(int i = 0; i < BMa_num(); i++){
								int s = S90_from_piecelist(POSITION,BMA,i);
								if(StoX(s) > 0x4){
									Bitboard A =  ma_to_king_attacks_bb(s,occ);  // 得到马的攻击位棋盘
									if(m128_is_have_bit(m_and(A,ei.attackKingMaCan[WHITECOLOR]))){
										valu -= TiMen_Ma_att_Score;
										ei.attPoint[BLACKCOLOR] += TiMen_Ma_att_point;
									}
								}
							}
					} // 右边铁门栓
					if(PB90(0x56) == RSHI){			    // 只要将不能向右边移动,就是左边铁门栓	
							// 1, 车能不能攻击到将的 右边 底线, 
							for(int i = 0; i < BChe_num(); i++){
								int s = S90_from_piecelist(POSITION,BCHE,i);
								if(StoX(s) < 0x4){
									Bitboard C = rook_attacks_bb(s,_mm_andnot_si128(POSITION->byChessBB[BCHE],occ)); 
									C = m_and(C,m128_bb_or_bb(_mm_load_si128((__m128i*)Rank9BB),
										m_and(_mm_load_si128((__m128i*)TiMenBit_Pawn),LowBB[6])));
									if(m128_is_have_bit(C)){
										valu -= TiMen_Che_att_Score;
										ei.attPoint[BLACKCOLOR] += TiMen_Che_att_point;
									}
								}
							}
							// 1, 如果兵在将的右肋,右上肋 则还要加上挡住的车
							Bitboard tbP = m_and(bitboard_black_pawn,
								m_and(LeftBB[0x04],_mm_load_si128((__m128i*)TiMenBit_Pawn)));
							if(m128_is_have_bit(tbP)){
								valu -= TiMen_Pawn_att_Score;
								ei.attPoint[BLACKCOLOR] += TiMen_Pawn_att_point;
							}
							// 3, 将
							if(StoX(bk) < 0x4){
								Bitboard tkb = rook_attacks_bb(bk,
									_mm_andnot_si128(m128_bb_or_bb(POSITION->byChessBB[BCHE],
									tbP),occ));
								if(m128_is_have_bit(m_and(tkb,
									_mm_load_si128((__m128i*)TiMenBit_Pawn)))){
									//print_bb(tkb);
									valu -= TiMen_King_att_Score;
									ei.attPoint[BLACKCOLOR] += TiMen_King_att_point;
								}
							}
							// 4, 如果马能攻击到将的右
							for(int i = 0; i < BMa_num(); i++){
								int s = S90_from_piecelist(POSITION,BMA,i);
								if(StoX(s) < 0x4){
									Bitboard A =  ma_to_king_attacks_bb(s,occ);  // 得到马的攻击位棋盘
									if(m128_is_have_bit(m_and(A,ei.attackKingMaCan[WHITECOLOR]))){
										valu -= TiMen_Ma_att_Score;
										ei.attPoint[BLACKCOLOR] += TiMen_Ma_att_point;
									}
								}
							}
					}// 左边铁门栓
				} // if(bk == 0x04 && PB90(0x0D) == BSHI){	
			}// 有可能是黑方中炮
			else if(StoY(msq) == StoY(rk)){ // 有可能是黑方底炮

				if(pMat->searchInfo16 & CK_B_Only_1Che1PaoxPawn){	
					int palr = Black_pawn_already_over_river(POSITION);
					if(palr == 0){
						continue;
					}
				}
				ei.attPoint[BLACKCOLOR] += Di_Pao_att_point;       // 底炮加攻击点
				//fen 3k1P3/4aR3/2n1b4/p3p3p/2P3c2/P8/R2C4P/4C3N/cr2AK3/3r2B2 b - - 0 1
				//还要判断一下是不是受到对方的攻击
				if(bit_is_set(POSITION->DYN->attack_white,msq)){
					// 但还是给自己的马,兵,炮保护了,也要加分
					if(bit_is_set(POSITION->DYN->attack_black,msq)){
					}
					else{
					   ei.attPoint[BLACKCOLOR] -= Di_Pao_att_By_Other;
					}
				}
				// 底炮时还可以抽将的分哇
			}
		}
	}
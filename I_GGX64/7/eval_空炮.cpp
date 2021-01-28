#include "eval_total.h"
//////////////////////////////////////////////////////////////////////////
///
template<Color Us>
void KongPao_isKingCanLeftRight(const Position& pos, EvalInfo& ei){
	//////////////////////////////////////////////////////////////////////////
	const Color Them = (Us == WHITE ? BLACK : WHITE);
	Square ksq = pos.king_square(Us);
	/// 将的左右棋步.
	Bitboard kcan = m_and(RankBB_A[StoY(ksq)],
		(Us == WHITE ? one_rpawn_rk_attacks(ksq) : one_bpawn_bk_attacks(ksq)));
	int orgatt = get_kong_pao_attack_point<Them>(pos,ei);
	if(have_bit(kcan,ei.SafeBit[Us])){          // 对方将能左右走动.
		if(StoX(ksq) == 0x4){
			ei.kongPaoAttpoint[Them]    += orgatt - 2;
		}
		else{
			ei.kongPaoAttpoint[Them]    += orgatt - 3;
		}
	}
	else{
		ei.kongPaoAttpoint[Them] += orgatt;
		if(!m_have_bit(_mm_andnot_si128(ei.attacked_by(Them),kcan))){
			ei.kongPaoAttpoint[Them] += 3; 
/*			print_bb(kcan);
			print_bb(ei.attacked_by(Them));	*/		
			//fen 2b1ka3/4ac3/4b4/1P6R/9/2P1C1B2/4P3P/N4KN2/6n2/2Br5 w - - 0 1
		}
	}
}

//////////////////////////////////////////////////////////////////////////
///
template<Color Us>
void KongPao_isKingCanUpDown(const Position& pos, EvalInfo& ei){
	//////////////////////////////////////////////////////////////////////////
	const Color Them = (Us == WHITE ? BLACK : WHITE);
	Square ksq = pos.king_square(Us);
	/// 将的上下棋步.
	Bitboard kcan = m_and(FileBB_A[StoX(ksq)],
		(Us == WHITE ? one_rpawn_rk_attacks(ksq) : one_bpawn_bk_attacks(ksq)));
	int orgatt = get_kong_pao_attack_point<Them>(pos,ei);
	if(have_bit(kcan,ei.SafeBit[Us])){     //  对方能上下走动               
		if(Us == WHITE ? StoY(ksq) != 0x9 : StoY(ksq) != 0x0){
			ei.kongPaoAttpoint[Them] += orgatt - 3;
		}
		else{
			ei.kongPaoAttpoint[Them] += orgatt - 4;
		}
	}
	else{ // 对方老将不能上下移动. 
		if(Us == WHITE ? StoY(ksq) != 0x9 : StoY(ksq) != 0x0){ // 将不在底线,空炮要减分
			ei.kongPaoAttpoint[Them] += orgatt - 4;
			if(!m_have_bit(_mm_andnot_si128(ei.attacked_by(Them),kcan))){
				ei.kongPaoAttpoint[Them] += 2; 
			}
		}
		else{  // 对方的将在底, 我方有空炮, 且对方的老将不能上下移动
			ei.kongPaoAttpoint[Them] += orgatt - 1;
			if(!m_have_bit(_mm_andnot_si128(ei.attacked_by(Them),kcan))){ // 走的方向有攻击.
				ei.kongPaoAttpoint[Them] += 3; 
			}
		}
	}

}

//////////////////////////////////////////////////////////////////////////
/// 空炮的攻击点数
template<Color Us>
sint8 get_kong_pao_attack_point(const Position& pos, EvalInfo& ei){

	const Piece delt = COLOR_BY_SIDE_ADD[Us];	
	//int attackCounter = count_1s(ei.attackKingBoard[Us]);

	//fen 1rbakabr1/5R3/1cn3c2/p7p/2p1C1p2/9/P1P1N1n1P/6N1C/9/R1BAKAB2 w - - 0 13 2c
	//fen 2bakabr1/5R3/1cn3c2/p7p/2p1C1p2/9/P1P1N1n1P/6N1C/9/2BAKAB2 w 1c
	//int che_num = pos.piece_count(RCHE + delt);
	//if(che_num == 1){
	//	bonus  += make_score(16,0);
	//}
	//else if(che_num == 2){
	//	bonus  += make_score(16,128);
	//}
	//else{
	//	bonus  += make_score(16,0);
	//}
	//fen 1Cbak2C1/1R2a4/3r1r3/9/2n1p1b1p/2B6/6n1P/3R5/4A4/2B1KA3 w - - 0 1
	//return  (count_1s(ei.attackKingBoard[Us]) - 1) * 3 // ***** 最多只能减一下哇. 
	//	+ (pos.piece_count(RCHE + delt)) * 4           // 大子数目, 没有车要减分
	//	+ (pos.piece_count(RPAO + delt)) * 2           // ***** 炮也只能减一下哇.
	//	+ pos.piece_count(RMA + delt) * 3;

	return  (ei.att_che_num[Us] - 1) * 4 
		+  (ei.att_pao_num[Us] - 1) * 3
		+  (ei.att_ma_num[Us]) * 2
		+  (pos.piece_count(RCHE + delt)) * 4 
		+  (pos.piece_count(RPAO + delt) - 1) * 3 
		+  pos.piece_count(RMA + delt) * 1;

	// 看一下可以攻击的棋子的数量.
}

//////////////////////////////////////////////////////////////////////////
/// 空_中炮底炮的评价
template<Color Us>
Score eval_kong_zhong_di_pao(const Position& pos, EvalInfo& ei){

	Score bonus = SCORE_ZERO;

	Bitboard bkp = ei.KongPaoBB[Us];
	if(m_have_bit(bkp)){
		const Color Them = (Us == WHITE ? BLACK : WHITE);
		//const Square mk  = pos.king_square(Us);
		const Square yk  = pos.king_square(Them);
		const Piece delt = COLOR_BY_SIDE_ADD[Us];	

		while(m_have_bit(bkp)){

			const Square pao = pop_1st_bit(&bkp);
			Bitboard pnull = BetweenBB[yk][pao];  //  对方的将，我方的炮

			if(m_have_bit(bkp)){
				// 如果有二个空炮, 要减
				// fen 5a1nN/1R2a4/C2k5/p7p/2p3n2/4p3P/Pc3r3/3CBA3/9/3A1KB2 b
				ei.kongPaoAttpoint[Us] -= 8;
				if(pos.piece_count(RCHE + delt) <= 1 && pos.piece_count(RMA + delt) == 0 ){
					ei.kongPaoAttpoint[Us] -= 3;
				}
			}

			//////////////////////////////////////////////////////////////////////////
			/// 空中炮
			if(StoX(pao) == StoX(yk)){
				if(Us == WHITE ? StoY(pao) <= 0x2 : StoY(pao) >= 0x7){
					goto Next_Kong_Pao; //fen 3C2b2/3k4C/2N2n3/3P5/8P/4cn3/9/2pAB4/4A4/4K1B2 w - - 0 0
				}
				if(ABS(StoY(pao) - StoY(yk)) >= 2){
					set_bit(ei.attackKingBoard[Us],pao);
					//////////////////////////////////////////////////////////////////////////
					if(pos.piece_count(RCHE + delt) == 2){
						bonus  += make_score(128, 64);
					}
					else if(pos.piece_count(RCHE + delt) == 1){
						bonus  += make_score(96, 32);
					}
					else{ //fen 1nbaka1n1/9/4b1c2/p3p1N1p/2p6/P5P2/2P1c3P/N1CC4B/9/2BAKA3 b - - 0 1
                        bonus  += make_score(64, 16);
					}

					KongPao_isKingCanLeftRight<Them>(pos,ei);

					//fen C3kab2/3Ra4/2C1c4/p3p3p/6p2/2P4r1/4P1ncP/6N2/9/1r1AKABR1 w - - 0 1
					if(have_bit(pnull,ei.attackedBy[BCHE - delt])){
						ei.attPoint[Us] -= 4;
						if(!bit_is_set(ei.attacked_by(Us),pao)){
							ei.attPoint[Us] -= 2;
						}
					}

				    // 如果对方的车能叠到炮的中间要减一些分。
					//if(have_bit())

					//还要判断一下是不是受到对方的攻击
					if(bit_is_set(ei.attacked_by(Them),pao)){
						ei.attPoint[Us] -= 4;
					}
				}
			}
			//////////////////////////////////////////////////////////////////////////
			/// 空底炮
			else{
				if(ABS(StoX(pao) - 0x4) <= 1){
					goto Next_Kong_Pao;
				}
				if(ABS(StoX(pao) - StoX(yk)) >= 2){		

					if(pos.piece_count(RCHE + delt) == 2){
						bonus  += make_score(64, 48);
					}
					//fen C3kab2/4a2C1/n2cb4/2n5p/pr2p1pN1/2P1PR2P/P8/4B4/4A4/2BAK4 b - - 0 1
					else if(pos.piece_count(RCHE + delt) == 1){ 
						bonus  += make_score(32, 16);
					}
					else{
						bonus += make_score(16, 0);
					}

					KongPao_isKingCanUpDown<Them>(pos,ei);

					//fen C3kab2/3Ra4/2C1c4/p3p3p/6p2/2P4r1/4P1ncP/6N2/9/1r1AKABR1 w - - 0 1
					if(have_bit(pnull,ei.attackedBy[BCHE - delt])){
						ei.attPoint[Us] -= 4;
						if(!bit_is_set(ei.attacked_by(Us),pao)){
							ei.attPoint[Us] -= 4;
						}
					}

					// 如果我方的车只有一个,且 进攻子只有二个.
					if(pos.piece_count(RCHE + delt) <= 1 && count_1s(ei.attackKingBoard[Us]) <= 2){
						if(pos.piece_count(RMA + delt) == 0){
							if(pos.piece_count(RPAO + delt) <= 1){
								ei.kongPaoAttpoint[Us] -= 3;
							}
							ei.kongPaoAttpoint[Us] -= 6;
						}
					}
				}
				//还要判断一下是不是受到对方的攻击
				if(bit_is_set(ei.attacked_by(Them),pao)){
					ei.attPoint[Us] -= 4;
				}
			}
Next_Kong_Pao:
			// 再算一下有没有杀棋分
			if(ei.haveKillDanger[Us] == false){

				// fen 3a1k3/4a4/7c1/7N1/p3PC3/2B6/1n7/9/4K4/7p1 b - - 0 1
				//　看一下是不是有马后炮在，而且对方不能走到马炮的中间。
				if(have_bit(ei.attacked_by(RMA + delt),m_and(MaHouPaoByKing[yk],pnull))){
					bonus += make_score(32,96);
					ei.haveKillDanger[Us] = true;
				}				

				// 看一下没有棋子攻击到将的边上一格. 
				Bitboard kingside = m_and(pnull,ei.attacked_by(BKING - delt));
				if(have_bit(kingside, ei.attacked_by(Us))){
					// 1. 看一下是不是还有其它子在攻击, // fen 1C2ka3/4a4/n2R5/p2Rp3p/2b3p2/3nr1Pr1/P7P/B8/4A4/3AK4 r
					if(have_bit(_mm_andnot_si128(kingside,pnull),ei.attacked_by(RCHE + delt))){

						// 我方的将不能上下运动, 1,对方的车数量大于2个。
						//if(have_bit(ei.attacked_by()
						if(pos.piece_count(RCHE + delt) == 2 || !have_bit(ei.attacked_by(BKING - delt),ei.SafeBit[Them])){
							ei.haveKillDanger[Us] = true;
							ei.attPoint[Us] += 4; // fen 1C2ka3/4a4/n2R5/p2Rp3p/2b3p2/3nr1Pr1/P7P/B8/4A4/3AK4 r
							continue;	
						}
						//else{  // fen 2b1k2r1/4a4/n1N1ba3/2p3R1p/3PC4/5c3/9/2C1BA3/9/2BAK3c b - - 0 1 这个不能算哇
						//	//print_bb(kingside);  // 对方的将的安全棋格
						//	//print_bb(ei.SafeBit[Them]); // 双方的安全棋格.)
						//	//print_bb(ei.attacked_by(BKING - delt));
						//	if(!have_bit(ei.attacked_by(BKING - delt),ei.SafeBit[Them])
						//}
					}
					//fen 2ba1k2C/9/3ab1R2/p3p3p/4c4/9/P7P/3p1A2B/C2r5/3NKA3 w - - 0 1
					Bitboard patt = m_and(m_and(pnull,ei.attacked_by(RPAWN + delt)),KpaoKingPawn[yk]);
					if(m_have_bit(patt)){
						ei.haveKillDanger[Us] = true;
						ei.attPoint[Us] += 4;
						continue;
					}
					// fen 4ka3/4a4/7rb/p7p/1Rp1RN3/2P3B2/P3Pr2P/6n1N/4A4/3AK2c1 r
					// 是不是攻击这个kingside超过二个点, 比如. 车,车. 车马. 
					if(have_bit(kingside,ei.attacked_by(RCHE + delt))){
						int c = 0;
						for(int i = 0; i < pos.piece_count(RCHE + delt); i++){
							//Square s =  pos.piece_list(RCHE+ delt,i);
							Bitboard A = ei.CheAtt[Us][i];                                // 得到炮的攻击位棋盘
							if(have_bit(A,kingside)){
								c ++; 
							}
						}
						if(c >= 2){
							ei.attPoint[Us] += 6; // fen 1C2ka3/4a4/n2R5/p2Rp3p/2b3p2/3nr1Pr1/P7P/B8/4A4/3AK4 r
						}
						for(int i = 0; i < pos.piece_count(RMA + delt); i++){
							//Square s =  pos.piece_list(RMA + delt,i);
							Bitboard A = ei.MaAtt[Us][i];                                // 得到炮的攻击位棋盘
							if(have_bit(A,kingside)){
								c ++; 
							}
						}
						if( c >= 2){ // fen 4ka3/4a4/7rb/p7p/1Rp1RN3/2P3B2/P3Pr2P/6n1N/4A4/3AK2c1 r
							ei.haveKillDanger[Us] = true;
							continue;
						}
					}
				}
			}			
		}	
		//fen 5a1nN/1R2a4/C2k5/p7p/2p3n2/4p3P/Pc3r3/3CBA3/9/3A1KB2 b
		if(ei.kongPaoAttpoint[Us] >= 16){
			ei.kongPaoAttpoint[Us] = 16;
		}
	}

	return bonus;
}


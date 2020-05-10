#include "eval_total.h"

//////////////////////////////////////////////////////////////////////////
// 评价一下空炮
template<Color Us>
Score eval_kong_zhong_di_pao(Position& pos, EvalInfo& ei){

	const int KpaoMul[16] = {
	//  0 1 2 3 4 5 6 7 8 910111213141516
		1,2,3,4,5,5,5,5,5,5,5,5,5,5,5,5
		//0,1,2,3,4,5,5,5,5,5,5,5,5,5,5,5
	};

	Score bonus = SCORE_ZERO;
	

	// 求得炮
	Bitboard bkp = ei.KongPao[Us];
	while(m_have_bit(bkp)){

		const Piece delt = COLOR_BY_SIDE_ADD[Us];	
		const Color Them = (Us == WHITE ? BLACK : WHITE);
		Square yk = pos.king_square(Them);
		Square mpao = pop_1st_bit_sq(bkp);

		if(m_have_bit(bkp)){ // 有二个空炮，要减
			ei.attPoint[Us] -= 8;	
			bonus -= make_score(168,80);
		}

		if(!bit_is_set(PaoCanAttKing[yk],mpao)){ // 去了在宫内的情况
			continue;
		}
		set_bit(ei.attackKingBoard[Us],mpao);

		Bitboard paoNull = BetweenBB[mpao][yk];
		

		//////////////////////////////////////////////////////////////////////////
		// paoNull

		// fen 2bak4/4a4/4b4/3Rp2P1/8r/C3P1B2/P2N3c1/4B1N2/4A4/3AK3c w - - 0 1
		//如果有二个炮，则要判断一下，另一个炮能不能重炮，
		bool twoPao = false;
		Bitboard otherp = _mm_andnot_si128(ei.KongPao[Us],pos.pieces(RPAO + delt));
		Square op;
		while (pop_1st_bit_sq(otherp, op)) {
			Bitboard patt = pos.Rook_attacks_bb(op);
			if(have_bit(patt,paoNull)){
				set_bit(ei.attackKingBoard[Us],op);
				twoPao = true;
				if(!bit_is_set(ei.attacked_by(Them),mpao)){
					ei.attPoint[Us] += 6;
				}
				if(StoX(mpao) == StoX(yk)){
					if(abs(StoY(op) - StoY(yk)) >= 2){
						ei.attPoint[Us] += 6;
					}
				}
				else if(StoY(mpao) == StoY(yk)){
					if(abs(StoX(op) - StoX(yk)) >= 2){
						ei.attPoint[Us] += 6;
					}
				}
			}
		}

		if(StoX(mpao) == StoX(yk)){
			if(pos.piece_count(RCHE + delt) == 2){
				bonus  += make_score(168, 96);
			}
			else if(pos.piece_count(RCHE + delt) == 1){
				bonus  += make_score(96, 32);
			}
			else {
				bonus += make_score(32,16);
			}

			// fen 4k4/4ac3/3Cb4/R8/2r6/4P4/8P/B8/2p1A4/3A1KB2 w - - 0 1
			if(StoX(yk) != 0x4 && !bit_is_set(ei.attacked_by(Us), XYtoS(0x4,StoY(yk)))){
				ei.attPoint[Us] -= 10;
			}
		}
		else{
			if(pos.piece_count(RCHE + delt) == 2){
				bonus  += make_score(108, 80);
			}
			else if(pos.piece_count(RCHE + delt) == 1){
				bonus  += make_score(32, 16);
				// fen 2bak4/2C1a1C2/9/p1p5p/9/2N6/P7P/B8/1r2A1R2/c2K1ABc1 b - - 0 1
				if(pos.piece_count(RMA + delt) == 0 && !twoPao){
					ei.attPoint[Us] -= 4;
					if(!have_bit(ei.attackKingBoard[Us], pos.pieces(RPAWN + delt))){
						ei.attPoint[Us] -= 6;
					}
				}
			}			
		}

		if(have_bit(ei.attacked_by(RMA + delt), paoNull)){
			ei.attPoint[Us] += 6;
		}
		if(have_bit(ei.attacked_by(RCHE + delt), paoNull)){
			ei.attPoint[Us] += 6;

			// fen 2b1ka3/4a4/n3c4/9/8p/PN2N4/4P1R1P/3AB4/1C5r1/3AK3c w - - 0 1
			if(StoY(mpao) == StoY(yk) && pos.piece_count(RCHE + delt) <= 1 && pos.piece_count(BCHE - delt) >= 1){
				Bitboard attp = m_and(pos.pieces_of_color(Us),Us == WHITE? UpBB[0x5] : LowBB[0x4]);
				attp = _mm_andnot_si128(pos.pieces(RCHE + delt),attp);
				if(count_1s(attp) <= 1){ // 过河的棋子
					ei.attPoint[Us] -= 8;
				}
			}

			if(have_bit(ei.attacked_by(RCHE + delt), 
				_mm_andnot_si128(ei.attacked_by(BKING - delt),paoNull))){
					// fen 1C2ka3/4a4/b3b4/2R6/9/5pC2/1p3r3/4BA3/2NnAK2c/2B6 w - - 0 1
					ei.attPoint[Us] += 3;
					// fen 2Rak1b2/9/2n2C3/p3p3p/9/1N7/PcrNP3P/1C7/c2KA4/5A3 w - - 0 1
					//如果对方的将只能移动一步不到
					if(count_1s(_mm_andnot_si128(pos.pieces_of_color(Them),ei.attacked_by(BKING - delt))) <= 1){
						ei.attPoint[Us] += 3;
					}
			}						
			//这个还要复杂，要判断有没有杀棋
			Bitboard B = m_and(ei.attacked_by(BKING - delt),paoNull);
			if(have_bit(ei.attacked_by(RMA + delt),B)){
				ei.attPoint[Us] += 4;
			}
			//还有车将一线的，
			
			// 这个还要另外算一下，如果隔了2格，还要厉害，如果隔了一格，
			// fen 1C2ka3/4a4/b3b4/2R6/9/5pC2/1p3r3/4BA3/2NnAK2c/2B6 w - - 0 1
		}

		// fen 2ba5/4k4/3a5/5R3/2c1C4/1p1C4P/1p2r4/3ABA3/9/1c2K1B2 w - - 0 1
		int attnum = (int)count_1s(ei.attackKingBoard[Us]);  // 不需要去了炮

		int m = KpaoMul[attnum];

		if(StoX(mpao) == StoX(yk)){
			ei.attPoint[Us] += 4 * m;
		}
		else{
			if(Us == WHITE ? StoY(yk) == 0x0 : StoY(yk) == 0x9){
				ei.attPoint[Us] += 3 * m;
			} 
			else{
               ei.attPoint[Us]  += 2 * m;
			}
		}

		// 如果这个炮给对方攻击中。要减一些
		if (bit_is_set(ei.attacked_by(Them), mpao)) {
			ei.attPoint[Us] -= 8;
		}
		
		//bonus += make_score(64*m, 32*m);
		// fen 1R1a5/C4kC2/3a5/p3p3p/9/2P5P/P5n2/4B4/4Ar3/2B1K2c1 w - - 0 1
	}

	return bonus;
}


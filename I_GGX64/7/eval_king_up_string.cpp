#include "eval_total.h"

///////////////////////////////////////////////////////////////////////////
/// 将上面的一个棋了被牵制了, 包括 窝心马, 铁门栓, ... 这儿算红方攻击黑方考虑
template<Color Us>
Score eval_king_up_one_string(const Position& pos, EvalInfo& ei){

	const Color Them = (Us == WHITE ? BLACK : WHITE);	
	const Square yk  = pos.king_square(Them);	
	Score bonus = SCORE_ZERO;
	
	// 对方将上面的棋子被牵制了. 
	if(bit_is_set(ei.xray_bit[Us],(Us == WHITE ? 0x0d : 0x4c)) && (Us == WHITE ? yk == 0x04 : yk == 0x55)){		

		const Piece delt = COLOR_BY_SIDE_ADD[Us];
		Bitboard  occ = pos.occupied_squares();
		const Square mk  = pos.king_square(Us);
		// 得到将上面的sq2,sq3.  k sq1 sq2 sq3
		//Bitboard bm = m_and(ei.attackKingPaoCan[Them], 
		//	m_or(pos.pieces(RKING + delt), pos.pieces(RCHE + delt))); // 
		Bitboard bm = m_and(ei.attackKingPaoCan[Them], m_and(occ,FileBB_A[0x4]));
		//bm = m_and(bm,FileBB_A[0x4]);   // print_bb(bm);
		Square sq2 = pop_1st_bit(&bm);
		assert(sq2 >= 0x04 && sq2 <= 0x55);

		Piece Up1Chess = (Us == WHITE ? pos.piece_on(Square(0x0d)) : pos.piece_on(Square(0x4c)));
		Piece Up2Chess = pos.piece_on(sq2);

		bool isMPao;  // 是不是对方的炮在牵制. 
		//bool istm = false;
		//print_bb(ei.ZhongDiPaoBB[Us]);
		if(have_bit(ei.ZhongDiPaoBB[Us],FileBB_A[0x4])){
			isMPao = true;			
		}
		else{
			isMPao = false;
		}
		//fen 2bak4/3ra4/4n2r1/pR1CCP2p/6b2/9/Pp6P/3R5/2nNA4/2c1KAB2 b - - 0 1
		// 将 仕 (将,车  炮)
		if(false){			
		}// 下面共四种可能.
		else if(Up1Chess == (BSHI - delt)){	 // 将 仕 sq2 sq3 有可能是铁门栓.
			if(isMPao){
				if(pos.piece_on(yk - 1) == (BSHI - delt) || pos.piece_on(yk + 1) == (BSHI - delt)){
					if(Up2Chess == (BMA - delt) || Up2Chess == (BPAO - delt)){
						bonus += make_score(16,32);
						ei.attPoint[Us] += 3;
					}
				}
			}
		} // fen r1bakab2/4n3r/1cn4c1/p1p1p1p1p/9/4C4/P1P1P1P1P/2N4C1/9/R1BAKABNR w - -
		else if(Up1Chess == (BMA - delt)){  // 将 马 sq2 sq3 
			// 将 马 sq2 炮 
			if(isMPao){
				// 如果是真的窝心马
				if(pos.piece_on(yk - 1) == (BSHI - delt) && pos.piece_on(yk + 1) == (BSHI - delt)){
					// 如果还有我方方的大子,还要减分
					if(Up2Chess == (BMA - delt) || Up2Chess == (BPAO - delt)){
						bonus  +=  make_score(96, 196);
					} //fen fen 3aka3/4n4/bc2b2c1/p3C1P1p/2nC5/2B6/3NP3P/9/9/2BAKA3 w - - 0 1
					bonus  += make_score(128,256);
					ei.attPoint[Us] += 24;
					//fen 3a5/2P1a4/b2kc4/9/9/9/3r5/4B4/4N4/R2AKAB2 b - - 0 1
				}
				// 也要减一些分哇
				else{
					if(Up2Chess == (BMA - delt) || Up2Chess == (BPAO - delt)){
						bonus  += make_score(16, 32);
					}
					bonus  += make_score(32,96);
					ei.attPoint[Us] += 6;
				}
			}
			// 将 马 车
			else if(Up2Chess == (RCHE + delt)){ 
				// 如果是真的窝心马
				if(pos.piece_on(yk - 1) == (BSHI - delt) && pos.piece_on(yk + 1) == (BSHI - delt)
					&& pos.piece_count(BXIANG - delt) == 0){
						bonus  += make_score(64,168);
						ei.attPoint[Us] += 18;
				}
				// 也要减一些分哇
				else{
					bonus  += make_score(32,96);
					ei.attPoint[Us] += 3;
				}
				//fen 2bak3C/4a4/9/p2P4p/3r5/4p4/P3r1c1P/6R2/4N4/1R2KA3 w - - 0 1
				if(pos.piece_on(yk + 1) == (BSHI - delt)){
					if(!have_bit(pos.pieces(BXIANG - delt), RightBB[0x4])){
						Bitboard apao = m_and(pos.pieces(RPAO + delt),RightBB[0x05]);
						ei.attackKingBoard[Us] = m_or(ei.attackKingBoard[Us],apao);
					}
				}
				if(pos.piece_on(yk - 1) == (BSHI - delt)){
					if(!have_bit(pos.pieces(BXIANG - delt), LeftBB[0x4])){
						Bitboard apao = m_and(pos.pieces(RPAO + delt),LeftBB[0x03]);
						ei.attackKingBoard[Us] = m_or(ei.attackKingBoard[Us],apao);
					}
				}
			}
			// 将 马 将
			else if(Up2Chess == (RKING + delt)){
				bonus  += make_score(16,64);
				ei.attPoint[Us] += 3;
			}
		}
		else if(Up1Chess == (BPAO - delt)){  // 将 炮 sq2 sq3 
			// 将 炮 车
			if(Up2Chess == (RCHE + delt)){
				// 如果是真的窝心炮
				if(pos.piece_on(yk - 1) == (BSHI - delt) && pos.piece_on(yk + 1) == (BSHI - delt)
					&& pos.piece_count(BXIANG - delt) == 0){
						bonus  += make_score(48,128);
						ei.attPoint[Us] += 12;
				}
				// 也要减一些分哇
				else{
					bonus  += make_score(16,80);
					ei.attPoint[Us] += 3;
				}
			}
			if(Up2Chess == (RKING + delt)){
				bonus  += make_score(0,64);
				ei.attPoint[Us] += 3;
			}
		}
		else if(Up1Chess == (BCHE - delt)){  // 将 车 sq2 sq3 
			if(isMPao){
				// 如果是真的窝心车
				if(pos.piece_on(yk - 1) == (BSHI - delt) && pos.piece_on(yk + 1) == (BSHI - delt)){
					// 如果还有我方方的大子,还要减分
					if(Up2Chess == (BMA - delt) || Up2Chess == (BPAO - delt)){
						bonus  += make_score(96, 196);
					}
					bonus  += make_score(128,256);
					ei.attPoint[Us] += 28;
				}
				// 也要减一些分哇
				else{
					if(Up2Chess == (BMA - delt) || Up2Chess == (BPAO - delt)){
						bonus  += make_score(64, 96);
					}
					bonus  += make_score(32,96);
					ei.attPoint[Us] += 4;
				}
			}
		}

		// 再看一下中路的攻势
		//////////////////////////////////////////////////////////////////////////					  
		// 1. 我方车能不能攻击到对方将的边线
		for(int i = 0; i < pos.piece_count(RCHE + delt); i++){
			Square s =  pos.piece_list(RCHE + delt,i);	

			if(StoX(s) == 0x4) continue;

			Bitboard att = ei.CheAtt[Us][i];		

			Us == WHITE ?
				att = m_and(att,m_or(_mm_load_si128((__m128i*)Rank0BB),  // 底线+兵的或攻击位置
				m_and(_mm_load_si128((__m128i*)TiMenBit_Pawn),UpBB[3])))
				: att = m_and(att,m_or(_mm_load_si128((__m128i*)Rank9BB),
				m_and(_mm_load_si128((__m128i*)TiMenBit_Pawn),LowBB[6])));

			// 如果车不能攻击
			if(!m_have_bit(att) && (Us == WHITE? StoY(s) >= 0x5 : StoY(s) <= 0x4)){
				continue;
			}

			// 左右一起写? 
			Square mside = yk - 1;
			Square oside = yk + 1;

			// 将的二边的信息
			if(StoX(s) < 0x4){
				att = m_and(LeftBB[0x4],att);
			}
			else if(StoX(s) > 0x4){
				mside = yk + 1;
				oside = yk - 1;
				att = m_and(RightBB[0x4],att);
			}

			// 这个是铁门栓.
			if(pos.piece_on(oside) == (BSHI - delt)){

				//fen 2baka1r1/4n4/4b4/pc2C3p/3P5/4P4/P4R2P/4BK3/4A4/9 b - - 0 1
				if(Up1Chess == (BMA - delt)){
					bonus += make_score(16,96);
				}

				if(isMPao){
					bonus  += make_score(16,96);
					ei.attPoint[Us] += 2;
					// 如果以方没有棋子在保护将军的那一条线,要加分
					if(!bit_is_set(ei.attacked_by(Them),mside) && pos.piece_on(mside) == EMPTY){
						// fen 2bak4/4a4/2c1b1n2/p3CR3/6p2/2Pr5/4P4/C3B1N2/1c2K4/2BA1A3 w - - 0 1
						bonus  += make_score(16,48);
					}
					//fen 2r1kab2/4a3n/4bc3/6P1p/R2NC4/1p7/P3P3P/2C6/4A4/1c2K1B2 w - - 0 1
					//如果是对方的车在底线,保着那个棋格,就要扣分.
					if(have_bit(ei.attackKingCheCan[Them],pos.pieces(BCHE - delt))){
						bonus  += make_score(16,64);
					}

					//fen 1nbak4/1N2a4/1c2b1nC1/1C2p1N1p/5r3/6P2/P2pc2RP/4B4/4A4/2BAK4 w - - 0 1
					//有棋子在保护我方的中炮
					if(have_bit(ei.attacked_by(Us),m_and(ei.ZhongDiPaoBB[Us],FileBB_A[0x04]))){
						bonus  += make_score(8,64);
					}
				}
				else{
					bonus  += make_score(8,48);
					ei.attPoint[Us] += 3;
					// 如果以方没有棋子在保护将军的那一条线,要加分
					if(!bit_is_set(ei.attacked_by(Them),mside) && pos.piece_on(mside) == EMPTY){
						// fen 2bak4/4a4/2c1b1n2/p3CR3/6p2/2Pr5/4P4/C3B1N2/1c2K4/2BA1A3 w - - 0 1
						bonus  += make_score(16,32);
					}
					//fen 2r1kab2/4a3n/4bc3/6P1p/R2NC4/1p7/P3P3P/2C6/4A4/1c2K1B2 w - - 0 1
					//如果是对方的车在底线,保着那个棋格,就要扣分.
					if(have_bit(ei.attackKingCheCan[Them],pos.pieces(BCHE - delt))){
						bonus  += make_score(6,32);
					}
				}
			}
			else if(pos.piece_on(mside) == EMPTY){
				bonus  += make_score(8,64);
				ei.attPoint[Us] += 4;

				// 如果以方没有棋子在保护将军的那一条线,要加分
				if(!bit_is_set(ei.attacked_by(Them),mside)){
					// fen 2bak4/4a4/2c1b1n2/p3CR3/6p2/2Pr5/4P4/C3B1N2/1c2K4/2BA1A3 w - - 0 1
					bonus  += make_score(16,48);
				}
			}
			else{ // 要看一下是不是能攻击到 mside
				if(bit_is_set(att,mside)){
					bonus  += make_score(4,32);
					ei.attPoint[Us] += 3;
				}
			}
			// fen 2bakc1R1/4a4/n1c1b4/N1prC3p/P8/2P3r2/4P1n1P/3C2N2/4A4/1RBAK4 b - - 0 1
			/// 5. 对方有炮在防守,也要扣分
			if(bit_is_set(ei.attacked_by(BPAO - delt),mside)){
				ei.attPoint[Us] -= 6;
			}
		} // che_end

		//////////////////////////////////////////////////////////////////////////
		// 2 看一下兵
		Bitboard tbp = m_and(pos.pieces(RPAWN + delt),_mm_load_si128((__m128i*)TiMenBit_Pawn));
		// 看一下,是不是另一边有仕.
		if(m_have_bit(tbp)){  
			if(pos.piece_on(yk + 1) == (BSHI -delt)){
				if(have_bit(tbp,LeftBB[0x4])){
					bonus  += make_score(8,64);
					ei.attPoint[Us] += 4;
				}
				else{
					bonus  += make_score(4,32);
					ei.attPoint[Us] += 2;
				}
			}
			if (pos.piece_on(yk - 1) == (BSHI -delt)){
				if(have_bit(tbp,RightBB[0x4])){
					bonus  += make_score(8,64);
					ei.attPoint[Us] += 4;
				}
				else{
					bonus  += make_score(4,32);
					ei.attPoint[Us] += 2;
				}
			}

			if(Up1Chess == (BMA - delt)){
				bonus += make_score(16,64);
			}
		}
		//////////////////////////////////////////////////////////////////////////
		/// 3. 将
		if(StoX(mk) != 0x4){  // if(StoX(s) == 0x4) continue;
			Bitboard tkb = rook_attacks_bb(mk,_mm_andnot_si128(
				m_or(pos.pieces(RCHE + delt), tbp),occ));
			if(have_bit(tkb,_mm_load_si128((__m128i*)TiMenBit_Pawn))){
				if(  (StoX(mk) < 0x4 && pos.piece_on(yk + 1) == (BSHI -delt))
					||(StoX(mk) > 0x4 && pos.piece_on(yk - 1) == (BSHI -delt))) {
						bonus  += make_score(16,64);
						ei.attPoint[Us] += 3;
				}
				else{
					bonus  += make_score(16,32);
					ei.attPoint[Us] += 2;
				}	

				if(Up1Chess == (BMA - delt)){
					bonus += make_score(16,64);
				}
			}
		}
		//////////////////////////////////////////////////////////////////////////
		/// 4. 马
		for(int i = 0; i < pos.piece_count(RMA + delt); i++){
			Square s =  pos.piece_list(RMA + delt,i);
			// 马在家里也要跳过
			if(Us == WHITE? StoY(s) >= 0x5 : StoY(s) <= 0x4) continue;
			Bitboard att = ei.MaAtt[Us][i];		
			if(have_bit(att,ei.attackKingMaCan[Them])){  // 马可以将军
				if(  (StoX(s) < 0x4 && pos.piece_on(yk + 1) == (BSHI -delt))
					||(StoX(s) > 0x4 && pos.piece_on(yk - 1) == (BSHI -delt))) {
						bonus  += make_score(8,64);
						ei.attPoint[Us] += 3;
				}
				else{
					bonus  += make_score(4,32);
					ei.attPoint[Us] += 2;
				}	

				if(Up1Chess == (BMA - delt)){
					bonus += make_score(16,64);
				}
			}			
		} // fen 2bakabC1/9/2n6/p3p1R1N/9/8P/P1r1P4/9/9/3AKABc1 w - - 0 1
		//////////////////////////////////////////////////////////////////////////

		
	}// end 

		
	return bonus;
}





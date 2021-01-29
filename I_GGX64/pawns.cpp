#include "chess.h"
#include "pawns.h"
#include "position.h"
#include "thread.h"


namespace {

	// fen 4kab2/4aR2c/1c2b1n2/r3p1R1p/2p4r1/p5P2/n1PCP3P/N3C1N2/9/2BAKAB2 w - - 0 16

	const int attControlbyPawn[5] = {0, 4,  8, 12,  16};
	const int PCHECK_SAFE[6] = {0,0,8,10,12,12};

                           // 使用“相” HASH 
//////////////////////////////////////////////////////////////////////////
// 这个只在 PAWN_HASH 中评估，所以不能有车的位置
template<Color Us>
Score evaluate_pawns_2(Position& pos, Pawns::Entry* e) {
	const Color Them = (Us == WHITE ? BLACK : WHITE);
	const Piece delt = COLOR_BY_SIDE_ADD[Us];
	Bitboard B, pcan, NotB = _mm_setzero_si128();

	const Square yk = pos.king_square(Them);
	const Square mk = pos.king_square(Us);
	Score bonus = SCORE_ZERO;

	// 求双方仕相兵的位棋盘
	Bitboard brsxp = m_or(pos.pieces(BSHI),
		m_or(pos.pieces(BXIANG),
			m_or(pos.pieces(BPAWN),
				m_or(pos.pieces(RSHI),
					m_or(pos.pieces(RXIANG), pos.pieces(RPAWN))))));

	Bitboard tmp = m_and(FileBB_A[StoX(mk)], brsxp);
	Square sq;

	if (Us == WHITE) {
		switch (abs(StoX(mk) - StoX(yk))) {
		case 2:
			e->_PawnInfo |= KING_CANNOT_STRING;  // 双方将帅不可能牵制
			e->_PawnInfo |= R_KING_CANNOT_ATT;
			break;
		case 1:
			e->_PawnInfo |= KING_CANNOT_STRING; // 双方将帅不可能牵制
			
			sq = XYtoS(StoX(mk), StoY(yk));
			clear_bit(tmp, sq);   // 去了对方边上的一棋子，
			if (pos.piece_on(sq + 9) == RPAWN) {
				clear_bit(tmp, sq + 9);   // 去了对方边上的一棋子，
			}
			if (count_1s(tmp) >= 1) {
				e->_PawnInfo |= R_KING_CANNOT_ATT;
			}
			break;
		case 0:  // 二个将在一条线上。
			if (count_1s(tmp) >= 2) {
				e->_PawnInfo |= KING_CANNOT_STRING; // 双方将帅不可能牵制
			}

			sq = XYtoS(StoX(mk), StoY(yk)+1);
			clear_bit(tmp, sq);            // 去了对方将下面的一棋子，
			if (pos.piece_on(sq + 9) == RPAWN) {
				clear_bit(tmp, sq + 9);   // 去了对方将下面二格的棋子，
			}
			if (count_1s(tmp) >= 1) {
				e->_PawnInfo |= R_KING_CANNOT_ATT;
			}
			break;
		default:
			break;
		}
	}
	else
	{
		switch (abs(StoX(mk) - StoX(yk))) {
		case 2:
			e->_PawnInfo |= KING_CANNOT_STRING;  // 双方将帅不可能牵制
			e->_PawnInfo |= B_KING_CANNOT_ATT;
			break;
		case 1:
			e->_PawnInfo |= KING_CANNOT_STRING; // 双方将帅不可能牵制

			sq = XYtoS(StoX(mk), StoY(yk));
			clear_bit(tmp, sq);   // 去了对方边上的一棋子，
			if (pos.piece_on(sq - 9) == BPAWN) {
				clear_bit(tmp, sq - 9);   // 去了对方边上的一棋子，
			}
			if (count_1s(tmp) >= 1) {
				e->_PawnInfo |= B_KING_CANNOT_ATT;
			}
			break;
		case 0:  // 二个将在一条线上。
			if (count_1s(tmp) >= 2) {
				e->_PawnInfo |= KING_CANNOT_STRING; // 双方将帅不可能牵制
			}

			sq = XYtoS(StoX(mk), StoY(yk) - 1);
			clear_bit(tmp, sq);            // 去了对方将下面的一棋子，
			if (pos.piece_on(sq - 9) == BPAWN) {
				clear_bit(tmp, sq - 9);   // 去了对方将下面二格的棋子，
			}
			if (count_1s(tmp) >= 1) {
				e->_PawnInfo |= B_KING_CANNOT_ATT;
			}
			break;
		default:
			break;
		}
	}






	//////////////////////////////////////////////////////////////////////////	
	// 4, 兵的过河能力检查
	if (Us == WHITE){
		if (have_bit(pos.pieces(RPAWN), LowBB[0x4])){
			B = m_and(LowBB[0x3], e->_pawnShiXiangAttacks[Them]); //print_bb(e->_pawnShiAttacks[Them]);
			// fen 4ka3/4a4/4R4/9/2P6/6Pp1/9/5A3/4AK3/6r2 b - - 0 1
			B = _mm_andnot_si128(pos.pieces(RPAWN), B);
			B = m_and(UpBB[0x6], B);
			NotB = m_or(NotB, B);
			m_Lsf(B, 9);
			NotB = m_or(NotB, B);
			m_Lsf(B, 9);
			NotB = m_or(NotB, B);
			NotB = _mm_andnot_si128(UpBB[0x5], NotB); // 已过河的兵.				 
		}
		NotB = m_or(_mm_load_si128((__m128i*)Rank0BB), NotB); // 去了底线兵
		pcan = _mm_andnot_si128(NotB, pos.pieces(RPAWN));  //print_bb(pcan); print_bb(NotB);

	}
	else{	// if use == BLACK	
		if (have_bit(pos.pieces(BPAWN), UpBB[0x5])){
			B = m_and(UpBB[0x6], e->_pawnShiXiangAttacks[Them]);
			// fen 4ka3/4a4/4R4/9/2P6/6Pp1/9/5A3/4AK3/6r2 b - - 0 1
			B = _mm_andnot_si128(pos.pieces(BPAWN), B);
			B = m_and(LowBB[0x3], B);
			NotB = m_or(NotB, B);
			m_Rsf(B, 9);
			NotB = m_or(NotB, B);
			m_Rsf(B, 9);
			NotB = m_or(NotB, B);
			NotB = _mm_andnot_si128(LowBB[0x4], NotB); // 已过河的兵.				 
		}
		NotB = m_or(_mm_load_si128((__m128i*)Rank9BB), NotB); // 去了底线兵
		pcan = _mm_andnot_si128(NotB, pos.pieces(BPAWN));  //print_bb(pcan); print_bb(NotB);		

	}
	//////////////////////////////////////////////////////////////////////////	
	// 兵的过河能力的加分
	e->_pcan[Us] = (int)count_1s(pcan);
	bonus += ((e->_pcan[Us] + 1) / 2 * make_score(8, 16));
	//////////////////////////////////////////////////////////////////////////	
	// 4, 兵的第二次评估
	Bitboard p = m_and(pos.pieces(RPAWN + delt),
		_mm_load_si128((__m128i*)(Us == WHITE ? RpawnOverBB : BpawnOverBB)));
	if (m_have_bit(p)){  // 有过河兵了
		int gh_num = (int)count_1s(_mm_andnot_si128(
			_mm_load_si128((__m128i*)(Us == WHITE ? Rank0BB : Rank9BB)), p));	// 去了底线兵
		bonus += PAWN_num_OVER_RIVER_point[gh_num];          // 过河兵的数量加分
		B = p;
		int yshi = pos.piece_count(BSHI - delt);
		Square pawn;
		while (pop_1st_bit_sq(B, pawn)) {
			// 得到兵的所有走步
			Bitboard patt = (Us == WHITE ? one_rpawn_rk_attacks(pawn) : one_bpawn_bk_attacks(pawn));
			if (abs(StoY(pawn) - StoY(yk)) <= 3){
				bonus += (Us == WHITE ? point_B_01Shi_R_Pawn90[yshi][pawn]
					: point_R_01Shi_B_Pawn90[yshi][pawn]);                     //过河兵才加分

				// 看一下是不是要判断有车在进攻。
				switch (yshi)
				{
				case 0:
					if ((abs(StoY(pawn) - StoY(yk)) + abs(StoX(pawn) - StoX(yk))) <= 4){
						e->_PawnInfo |= (Us == WHITE ? PEV_C_is_Rche_ATT : PEV_C_is_Bche_ATT);
					}
					break;
				case 1:
					if ((abs(StoY(pawn) - StoY(yk)) + abs(StoX(pawn) - StoX(yk))) <= 3){
						e->_PawnInfo |= (Us == WHITE ? PEV_C_is_Rche_ATT : PEV_C_is_Bche_ATT);
					}
					break;
				case 2:
					if ((abs(StoY(pawn) - StoY(yk)) + abs(StoX(pawn) - StoX(yk))) <= 2){
						e->_PawnInfo |= (Us == WHITE ? PEV_C_is_Rche_ATT : PEV_C_is_Bche_ATT);
					}
					break;
				default:
					break;
				}
				
			}
			Score pawnSafe = PrePawnAttKingMul_Safe[yshi][pawn][yk];    //兵控制将的分
			if (pawnSafe){
				set_bit(e->_attackKingBoard, pawn); //
				// 1.看一下兵能不能将军, 转化为bcy,bcx, 这个就厉害了
				Bitboard Bcheck = m_and( // 这个兵可以将军了
					patt,
					Us == WHITE ?
					attacks_by_rpawn_rk(yk) : attacks_by_bpawn_bk(yk));
				// 兵可以将军
				if (m_have_bit(Bcheck)){
					// 还要判断一下,1,要兵大于对方的将, 
					// fen 3k1a3/4ac3/8b/3C1P3/P8/2c3N2/9/4pA3/5K3/3A5 b - - 0 1
					if (Us == WHITE ? StoY(yk) == 0x0 : StoY(yk) == 0x9){
						e->_attPoint[Us] += attControlbyPawn[count_1s(Bcheck)];
					}
					else{
						e->_attPoint[Us] += attControlbyPawn[count_1s(Bcheck)] / 2;
					}
					bonus += pawnSafe;
				}
				else if (IsOnSameSide(pawn, yk)){
					bonus += pawnSafe / 2;
				}
			}
		}
	}
	return bonus;
}



//////////////////////////////////////////////////////////////////////////
// 
template<Color Us>
Score evaluate_pawns_1(Position& pos, Pawns::Entry* e) {

	const Color Them = (Us == WHITE ? BLACK : WHITE);
	const Piece delt = COLOR_BY_SIDE_ADD[Us];
	const Square yk = pos.king_square(Them);
	// const Square mk = pos.king_square(Us);
	Score bonus = SCORE_ZERO;
	// 1, 先计算兵的攻击位棋盘
	Bitboard p = pos.pieces(RPAWN + delt);
	Bitboard B = p;
	//////////////////////////////////////////////////////////////////////////	
	// 1. 向前一步
	B = _mm_andnot_si128(_mm_load_si128((__m128i*)(Us == WHITE ? Rank0BB : Rank9BB)), B);
	if (Us == WHITE){
		m_Rsf(B, 9);
	}
	else{
		m_Lsf(B, 9);
	}
	e->_pawnShiXiangAttacks[Us] = B;   // 这个是第一个算，只要直接赋值就行了。

	//////////////////////////////////////////////////////////////////////////	
	// 2. 过河兵
	p = m_and(p, _mm_load_si128((__m128i*)(Us == WHITE ? RpawnOverBB : BpawnOverBB)));
	if (m_have_bit(p)){
		B = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB), p);  // 去了左面兵
		m_Rsf(B, 1);                   //所有红兵向左一步
		e->_pawnShiXiangAttacks[Us] = m_or(e->_pawnShiXiangAttacks[Us], B);//		print_bb(B);

		B = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB), p);
		m_Lsf(B, 1);                   //所有红兵向右一步
		e->_pawnShiXiangAttacks[Us] = m_or(e->_pawnShiXiangAttacks[Us], B);//		print_bb(B);
	}
	//////////////////////////////////////////////////////////////////////////	
	// 3， 仕的攻击位棋盘
	for (int i = 0; i < pos.piece_count(RSHI + delt); i++){
		Square s = pos.piece_list(RSHI + delt, i);
		e->_pawnShiXiangAttacks[Us] = m_or(e->_pawnShiXiangAttacks[Us], shi_attacks(s));      // 仕的攻击位棋盘

		// 仕的子力值
		bonus += make_score(SHI_VAL, SHI_VAL * 4 / 8);  // 仕到了残局要减分

		// 对方的攻击点减一些
		e->_attPoint[Them] -= LACK_SHI_ATT_POINT;
	}
	//////////////////////////////////////////////////////////////////////////	
	// 3， 相的攻击位棋盘
	for (int i = 0; i < pos.piece_count(RXIANG + delt); i++){
		Square s = pos.piece_list(RXIANG + delt, i);
		// 相 的子力值	
		bonus += make_score(XIANG_VAL, XIANG_VAL * 4 / 8);  // 相的物质力量

		//
		Bitboard A = pos.xiang_attacks_bb(s);
		e->_pawnShiXiangAttacks[Us] = m_or(e->_pawnShiXiangAttacks[Us], A);
		// 相的攻击位棋盘，这儿因为计算了象眼HASH,所以可用这个

		// 对方的攻击点减一些
		e->_attPoint[Them] -= LACK_XIANG_ATT_POINT;
	}


	//////////////////////////////////////////////////////////////////////////	
	// 有可能闷宫的棋形
	// fen 3rkab2/4a4/2n1bc1Rn/p1p1p1p1p/2P3N2/1C7/Pr2P3P/2N1B1C2/4A4/2R1KAB2 b - - 0 1
	if (Us == WHITE){
		if (yk == 0x4 && pos.piece_count(BSHI) == 2){

			if (pos.piece_on(Square(0xd)) == BSHI){

				if (pos.piece_on(Square(0x3)) == BSHI){   // 
					e->_PawnInfo |= PEV_Bshi_MenGong;
				}
				else if (pos.piece_on(Square(0x5)) == BSHI){
					e->_PawnInfo |= PEV_Bshi_MenGong;
				}
			}
			// fen 2b1k1b2/9/9/5Pp2/8p/5RP2/1r1r1c2P/4BR3/1n2A4/2NAK1B2 w - - 0 1
			if (pos.piece_count(BXIANG) == 2){ // 仕相全，要加一些防守分。
				e->_attPoint[WHITE] -= ALL_SHIXIANG_ATT_POINT;
			}
		}
	}
	else{
		if (yk == 0x55 && pos.piece_count(RSHI) == 2){

			if (pos.piece_on(Square(0x4c)) == RSHI){
				if (pos.piece_on(Square(0x54)) == RSHI){   // 
					e->_PawnInfo |= PEV_Rshi_MenGong;
				}
				else if (pos.piece_on(Square(0x56)) == RSHI){
					e->_PawnInfo |= PEV_Rshi_MenGong;
				}
			}

			if (pos.piece_count(RXIANG) == 2){
				e->_attPoint[BLACK] -= ALL_SHIXIANG_ATT_POINT;
			}
		}
	}

	return bonus;
}


}; // namespace 


namespace Pawns {
/// PawnTable::probe() takes a position object as input, computes a PawnEntry
/// object, and returns a pointer to it. The result is also stored in a hash
/// table, so we don't have to recompute everything when the same pawn structure
/// occurs again.
Entry* probe(Position& pos, Table& entries ) {

	Key key = pos.pawn_key();
	Entry* e = entries[key];

	// If e->key matches the position's pawn hash key, it means that we
	// have analysed this pawn structure before, and we can simply return
	// the information we found the last time instead of recomputing it.
	if (e->key == key){		
		return e;
	}
	e->key = key;                              // 保存当前KEY
	e->_attackKingBoard = _mm_setzero_si128();
	e->_PawnInfo  = 0;                         // 要测试兵的其它信息。
	e->value = SCORE_ZERO;
	e->_attPoint[WHITE] = LACK_SHI_ATT_POINT * 2 + LACK_XIANG_ATT_POINT * 2;                  // 
	e->_attPoint[BLACK] = LACK_SHI_ATT_POINT * 2 + LACK_XIANG_ATT_POINT * 2;                  //

	e->value += evaluate_pawns_1<WHITE>(pos, e)			// 这儿也将无关
	          - evaluate_pawns_1<BLACK>(pos, e);

	e->value += evaluate_pawns_2<WHITE>(pos,e)
		      - evaluate_pawns_2<BLACK>(pos,e);

	return e;
}

}

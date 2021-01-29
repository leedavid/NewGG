#include "chess.h"
////
//// Includes
////

#include <cassert>
#include <cstring>
#include <fstream>
#include <iostream>


#include "mersenne.h"
#include "movegen.h"
#include "movepick.h"
#include "position.h"
#include "notation.h"
#include "tt.h"
#include "uci.h"

using std::string;


/// CheckInfo constructor

CheckInfo::CheckInfo(Position& pos) {


	const Color us   = pos.side_to_move();
	const Color them = ~us;

	ksq = pos.king_square(them);                                               // 对方的将的位置.
	dcCandidates = pos.discovered_check_candidates(us);                        // 找出所有可抽将的棋子.
	PaoNull      = pos.findPaoNullBiboard(us,ksq);                             // 找出所有可叠炮将的格子.

	Piece delt = COLOR_BY_SIDE_ADD[us];	
	checkSq[RCHE + delt]  = pos.Rook_attacks_bb(ksq);                           // 我方的车能将军的棋格
	checkSq[RMA + delt]   = pos.king_to_ma_attacks_bb(ksq);                     // 我方的马能将军的棋格
	checkSq[RPAO + delt]  = pos.Pao_Eat_bb(ksq);                                // 我方的炮能将军的棋格	
	checkSq[RPAWN + delt] = (us == WHITE ? 
		attacks_by_rpawn_rk(ksq) : attacks_by_bpawn_bk(ksq));                   // 我方的兵能将军的棋格	
	// 其它的清空一下. 后面要把不能直接将的棋子去了。
    // checkSq[RKING + delt] = checkSq[RSHI + delt] = checkSq[RXIANG + delt] = _mm_setzero_si128();
}



/// Position:discovered_check_candidates() returns a bitboard containing all
/// pieces for the given side which are candidates for giving a discovered
/// check. Contrary to pinned_pieces() here there is no need of checkersBB
/// to be already updated.
// 找出可抽将的棋子. 
Bitboard Position::discovered_check_candidates(Color c)  {

	//return hidden_checkers_FindPinned_false(c);

	Bitboard result  = _mm_setzero_si128();
	Bitboard occ      = occupied_squares();

	Square ksq = king_square(~c);
	Piece delt = COLOR_BY_SIDE_ADD[c];

	//1. 车挡. 
	Bitboard pin = m_and(pieces(RCHE + delt),ChePseudoMask_FR[ksq]);
	Square s;
	while (pop_1st_bit_sq(pin, s)) {
		Bitboard bb = m_and(squares_between(s,ksq),occ);
		if(count_1s(bb) == 1){
			result = m_or(result,m_and(bb,pieces_of_color(c)));
		}
	}

	//2. 炮挡
	pin = m_and(pieces(RPAO + delt),ChePseudoMask_FR[ksq]);
	//Square s;
	while (pop_1st_bit_sq(pin, s)) {
		Bitboard bb = m_and(squares_between(s,ksq),occ);
		if(count_1s(bb) == 2){
			result = m_or(result,m_and(bb,pieces_of_color(c)));
		}
	}

	//3. 挡马.
	pin = m_and(pieces(RMA + delt),Ma_Pseudo_Att[ksq]);
	//Square s;
	while (pop_1st_bit_sq(pin, s)) {
		Square leg = maleg(s,ksq);
		if(color_of(b90[leg]) == c){
			set_bit(result,leg);
		}
	}

	return result;
}

Bitboard Position::sq_attack_by_color(Square sq, Color side) {


	if(side == WHITE){
        return m_or(m_and(Attack_By_Rpawn_Rking[sq],m_or(pieces(RPAWN),pieces(RKING))),
               m_or(m_and(Rook_attacks_bb(sq),	pieces(RCHE)),
               m_or(m_and(king_to_ma_attacks_bb(sq,byWhiteBlack), pieces(RMA)),
			   m_or(m_and(Pao_Eat_bb(sq), pieces(RPAO)),
			   m_or(m_and(shi_attacks(sq), pieces(RSHI)),
			        m_and(xiang_attacks_bb(sq,byWhiteBlack), pieces(RXIANG)))))));
	}
	else{
		return m_or(m_and(Attack_By_Bpawn_Bking[sq],m_or(pieces(BPAWN),pieces(BKING))),
			   m_or(m_and(Rook_attacks_bb(sq),	pieces(BCHE)),
			   m_or(m_and(king_to_ma_attacks_bb(sq,byWhiteBlack), pieces(BMA)),
			   m_or(m_and(Pao_Eat_bb(sq), pieces(BPAO)),
			   m_or(m_and(shi_attacks(sq), pieces(BSHI)),
			        m_and(xiang_attacks_bb(sq,byWhiteBlack), pieces(BXIANG)))))));
	}
}

/// Position::attackers_to() computes a bitboard containing all pieces which
/// attacks a given square.

Bitboard Position::attackers_to(Square sq){

	Bitboard occ = occupied_squares();
	return m_or(m_and(Attack_By_Rpawn_Rking[sq],m_or(pieces(RPAWN),pieces(RKING))),
		   m_or(m_and(Attack_By_Bpawn_Bking[sq],m_or(pieces(BPAWN),pieces(BKING))),
		   m_or(m_and(Rook_attacks_bb(sq),m_or(pieces(RCHE),pieces(BCHE))),
		   m_or(m_and(king_to_ma_attacks_bb(sq,occ), m_or(pieces(RMA),pieces(BMA))),
		   m_or(m_and(Pao_Eat_bb(sq),m_or(pieces(RPAO),pieces(BPAO))),
		   m_or(m_and(shi_attacks(sq), m_or(pieces(RSHI),pieces(BSHI))),
		   m_and(xiang_attacks_bb(sq,occ),m_or(pieces(RXIANG),pieces(BXIANG)))))))));
	// 中象对将也要算哇??
}



Bitboard Position::attacks_from_occ(Piece p, Square s, Bitboard occ){
	
	ASSERT(square_is_ok(s));

	switch (p){
	case RCHE: // 车
	case BCHE:{
				 return Rook_attacks_bb(s, occ); //  Rook_attacks_bb(sq);
	}
	case RMA:  // 马
	case BMA:{
		         return ma_to_king_attacks_bb(s,occ);
	}
	case RPAO: // 炮
	case BPAO:
		return Pao_Eat_bb(s,occ);
	case RPAWN: // 兵
	case RKING:
		return one_rpawn_rk_attacks(s);
	case BPAWN:
	case BKING:
		return one_bpawn_bk_attacks(s);
	case RSHI:
	case BSHI:
		return shi_attacks(s);
	case RXIANG:
	case BXIANG:{
				return xiang_attacks_bb(s,occ);
	}
	default:
		break;
	}

	return _mm_setzero_si128();
}

/// Position::attacks_from() computes a bitboard of all attacks
/// of a given piece put in a given square.
Bitboard Position::attacks_from(Piece p, Square sq)  {

	ASSERT(square_is_ok(sq));

	switch(p){
	case RCHE: // 车
	case BCHE:
		return Rook_attacks_bb(sq);
	case RMA:  // 马
	case BMA:{
		return ma_to_king_attacks_bb(sq);
			 }
	case RPAO: // 炮
	case BPAO:
		return Pao_Eat_bb(sq);
	case RPAWN: // 兵
	case RKING:
		return one_rpawn_rk_attacks(sq);
	case BPAWN:
	case BKING:
		return one_bpawn_bk_attacks(sq);
	case RSHI:
	case BSHI:
		return shi_attacks(sq);
	case RXIANG:
	case BXIANG:{
		return xiang_attacks_bb(sq);
				}
	default:
		break;
	}

	return _mm_setzero_si128();
}

/// Position::move_attacks_square() tests whether a move from the current
/// position attacks a given square. 
/// 这个走法还没有走, 要走了之后再判断. 这个是不是捉子步? 这个判断好简单哇. 
//bool Position::move_attacks_square(Move m, Square s) {
//
//	ASSERT(is_ok(m));
//	ASSERT(square_is_ok(s));
//
//	Square f = from_sq(m), t = to_sq(m);
//
//	ASSERT(!square_is_empty(f));
//
//	// 直接可以吃到
//	if(bit_is_set(attacks_from(piece_on(f),t),s))
//		return true;
//
//	// Move the piece and scan for X-ray attacks behind it
//	Bitboard occ = occupied_squares();
//	Color us = color_of(b90[f]);
//
//	clear_bit(occ,f);
//	set_bit(occ,t);
//
//	Bitboard xray; 
//
//	Piece delt = COLOR_BY_SIDE_ADD[us];
//
//
//	//1, 看一下现在是不是给我们的车,攻击了,
//	xray = m_and(Rook_attacks_bb(s,occ),pieces(RCHE + delt));
//	//2, 现在是不是给我们的马攻击了.
//	xray = m_or(xray,
//		m_and(king_to_ma_attacks_bb(s,occ),pieces(RMA + delt)));
//	//3, 现在是不是给我们的炮攻击了. 
//	xray = m_or(xray,
//		m_and(Pao_Eat_bb(s,occ),pieces(RPAO + delt)));
//
//
//	// If we have attacks we need to verify that are caused by our move
//	// and are not already existent ones.
//	// 如果现在在攻击对方,我们要校验一下,是不是原先就在的攻击. 
//	// return xray && (xray ^ (xray & attacks_from<QUEEN>(s)));
//	if(m_have_bit(xray)){ // 现在有车,或马,或炮 在攻击 s 		
//		//1. 得到原先的车,马,炮攻击图.
//		Bitboard org;	
//
//		org =  m_and(Rook_attacks_bb(s),   pieces(RCHE + delt));
//		org = m_or(org,
//			m_and(king_to_ma_attacks_bb(s,occ), pieces(RMA + delt)));
//		org = m_or(org,
//			m_and(Pao_Eat_bb(s),    pieces(RPAO + delt)));		
//
//		org = m_and(org,xray);
//		xray = m_xor(org,xray); // (xray & attacks_from<QUEEN>(s)));
//
//		if(m_have_bit(xray)){
//			return true;  // 这是真捉哇.
//		}
//	}
//
//	return false;
//}

/////////////////////////////////////////////////////////////////////////
// 

//void Position::find_checkers() { // 找到对方将军的人。
//
//	Color Us = side_to_move();
//	const Piece delt = COLOR_BY_SIDE_ADD[Us];
//	Square mk = king_square(Us);
//
//	st->checkersBB = m_or(m_and(pieces(BPAWN - delt), 
//		Us == WHITE? Attack_By_Bpawn_Bking[mk] : Attack_By_Rpawn_Rking[mk]),m_or(
//		m_and(Rook_attacks_bb(mk),pieces(BCHE - delt)),m_or(
//		m_and(Pao_Eat_bb(mk),pieces(BPAO - delt)),
//		m_and(king_to_ma_attacks_bb(mk),pieces(BMA - delt)))));
//}

Bitboard Position::findPaoNullBiboard(Color c, Square ksq) {

	Bitboard result = _mm_setzero_si128();	
	// 找到空炮之间的空格.
	Piece delt = COLOR_BY_SIDE_ADD[c];
	if(have_bit(ChePseudoMask_FR[ksq],pieces(RPAO + delt))){
		// 找到我方所有的空炮
		for(int i = 0; i < piece_count(RPAO + delt); i++){
			Square pao =  piece_list(RPAO + delt,i);
			Bitboard bet = BetweenBB[pao][ksq];
            if(!have_bit(bet,byWhiteBlack)){
				result = m_or(result,bet);
			}
		}
	}

	return result;
}


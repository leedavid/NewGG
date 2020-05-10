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

#ifndef NDEBUG
bool Position::pl_move_is_legala(Move m) {

	ASSERT(is_ok(m));

	Square from = from_sq(m);
	Square to   = to_sq(m);
	Color Us = color_of(piece_on(from));  // side_to_move();
	const Piece delt = COLOR_BY_SIDE_ADD[Us];
	//ASSERT(color_of(piece_on(from)) == us);

	Bitboard occ = byWhiteBlack;
	clear_bit(occ,from);
	set_bit(occ,to);

	Square mk = king_square(Us);
	if(mk == from){
		mk = to;
	}

	Bitboard KFR = ChePseudoMask_FR[mk];
	//////////////////////////////////////////////////////////////////////////
	if(have_bit(KFR,m_or(pieces(BKING - delt),pieces(BCHE - delt)))){
		// 2.1.1. 是不是给对方的 车,将 将军, ** 但不包括吃了对方的棋.同时去了对方的棋子
		if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],
			m_or(pieces(BKING - delt),pieces(BCHE - delt))),
			Rook_attacks_bb(mk,occ)))) {    // 这个要加入，因为是要走了后
				return false; 
		}
	}
	//////////////////////////////////////////////////////////////////////////
	if(have_bit(KFR,pieces(BPAO - delt))){
		// 2.1.2. 是不是还给对方的炮将军
		if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],pieces(BPAO - delt)),
			Pao_Eat_bb(mk,occ)))){
				return false;
		}
	}
	//////////////////////////////////////////////////////////////////////////
	if(have_bit(Ma_Pseudo_Att[mk],pieces(BMA - delt))){
		if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],pieces(BMA - delt)),
			king_to_ma_attacks_bb(mk,occ)))){
				return false;
		}
	}
	// 2.1.4 是不是还给对方的兵将军
	if(have_bit(Us == WHITE? attacks_by_bpawn_bk(mk): attacks_by_rpawn_rk(mk),pieces(BPAWN - delt))){
		if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],pieces(BPAWN - delt)),
			Us == WHITE? attacks_by_bpawn_bk(mk): attacks_by_rpawn_rk(mk)))){
				return false;
		}
	}	

	return true;	
}
#endif

bool Position::legal(Move m) {

	// ASSERT(color_of(piece_on(from_sq(m))) == sideToMove);

	if(in_check()){

		Square from = from_sq(m);
		Color Us = color_of(piece_on(from));  // side_to_move();
		if (Us != sideToMove){
			return false;
		}

#ifndef NDEBUG
		ASSERT(pl_move_is_legala(m));
#endif

		return true;
	}

	ASSERT(is_ok(m));

	Square from = from_sq(m);
	Square to   = to_sq(m);
	Color Us = color_of(piece_on(from));  // side_to_move();
	const Piece delt = COLOR_BY_SIDE_ADD[Us];
	//ASSERT(color_of(piece_on(from)) == us);

	Bitboard occ = byWhiteBlack;
	clear_bit(occ,from);
	set_bit(occ,to);

	Square mk = king_square(Us);
	if(mk == from){
		mk = to;
	}

	Bitboard KFR = ChePseudoMask_FR[mk];
    //////////////////////////////////////////////////////////////////////////
	if(have_bit(KFR,m_or(pieces(BKING - delt),pieces(BCHE - delt)))){
		// 2.1.1. 是不是给对方的 车,将 将军, ** 但不包括吃了对方的棋.同时去了对方的棋子
		if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],
			m_or(pieces(BKING - delt),pieces(BCHE - delt))),
			Rook_attacks_bb(mk,occ)))) {    // 这个要加入，因为是要走了后
				return false; 
		}
	}
	//////////////////////////////////////////////////////////////////////////
	if(have_bit(KFR,pieces(BPAO - delt))){
		// 2.1.2. 是不是还给对方的炮将军
		if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],pieces(BPAO - delt)),
			Pao_Eat_bb(mk,occ)))){
				return false;
		}
	}
	//////////////////////////////////////////////////////////////////////////
	if(have_bit(Ma_Pseudo_Att[mk],pieces(BMA - delt))){
		if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],pieces(BMA - delt)),
			king_to_ma_attacks_bb(mk,occ)))){
				return false;
		}
	}
	// 2.1.4 是不是还给对方的兵将军
	if(have_bit(Us == WHITE? attacks_by_bpawn_bk(mk): attacks_by_rpawn_rk(mk),pieces(BPAWN - delt))){
		if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],pieces(BPAWN - delt)),
			Us == WHITE? attacks_by_bpawn_bk(mk): attacks_by_rpawn_rk(mk)))){
				return false;
		}
	}	

	return true;	
}


bool Position::pseudo_legal(Move move) {

	Square from  = from_sq(move);
	Square to    = to_sq(move);
	Piece piece  = b90[from];
	Piece cap    = b90[to];

	Color us = side_to_move();

	// If the from square is not occupied by a piece belonging to the side to
	// move, the move is obviously not legal.
	if (color_of(piece) != us)
		return false;

	if (color_of(cap) == us)
		return false;

	switch(piece){
	case RMA:
	case BMA:{
		//得到马的所有走步			
		return (bit_is_set(king_to_ma_attacks_bb(to),from));
			 }
			 break;
	case RXIANG:
	case BXIANG:{
		 return (bit_is_set(xiang_attacks_bb(to),from));
				}
				break;
	case BSHI:
	case RSHI:			{
		return (bit_is_set(shi_attacks(to),from));
						}
						break;
	case RCHE:
	case BCHE:{ //不吃子与吃子
		return (bit_is_set(Rook_attacks_bb(to),from));
			  }
			  break;
	case RPAO:
	case BPAO:{//不吃子
		if(cap == EMPTY){
			return (bit_is_set(Rook_attacks_bb(to),from));
		}
		else{
			return (bit_is_set(Pao_Eat_bb(to),from));
		}
			  }
			  break;
	case RPAWN:
	case RKING:	{
		return (bit_is_set(attacks_by_rpawn_rk(to),from));
			   }
			   break;
	case BPAWN:
	case BKING: {
		return (bit_is_set(attacks_by_bpawn_bk(to),from));
			   }
			   break;
	default:
		return false;
	}

	//return false;
}

static const  bool AlwaysZhouJiang[16] = {
	false,  // 这个不用了
	false,  true, true, true, false, false, false,
	false,
	false,  true, true, true, false, false, false,		

};



bool Position::gives_check(Move m, CheckInfo& ci) {

	//ASSERT(pos_is_ok());
	ASSERT(is_ok(m));
	ASSERT(m128_is_same(ci.dcCandidates, discovered_check_candidates(side_to_move())));
	ASSERT(color_of(b90[from_sq(m)]) == side_to_move());


	Square from = from_sq(m);
	Square to   = to_sq(m);
	Piece  pc   = piece_on(from);
	Square yk   = ci.ksq;
	

	// Direct check ? 直接将.
	if (ChessCanDirectCheck[pc]){
		if (bit_is_set(ci.checkSq[pc], to)){ // 晕,这个不是炮将哇.
			// fen 2bak2r1/4a4/4b1n2/p3pNR1p/2p6/5NP2/P3P3P/4B3C/3cK2c1/2r2A1R1 b - - 0 1
			if (type_of(pc) == PAO && bit_is_set(ChePseudoMask_FR[yk], from)){  // 炮也在将线上走
				Bitboard occ = occupied_squares();
				clear_bit(occ, from);
				set_bit(occ, to);
				Bitboard paoeat = Pao_Eat_bb(yk, occ);
				Bitboard pao = pieces(pc);
				clear_bit(pao, from);
				set_bit(pao, to);
				if (have_bit(paoeat, pao)){
					return true;
				}
			}
			else{
				return true;
			}
		}
	}

	// Discovery check ? 抽将, 中国象棋有炮抽将,车抽车,马抽将三种形式.
	//if (m_have_bit(ci.dcCandidates) && bit_is_set(ci.dcCandidates, from)){
	if (bit_is_set(ci.dcCandidates, from))	{		
		if(bit_is_set(ChePseudoMask_FR[yk],from)){
			// 1, 车的抽将.
			// 2, 炮的抽将.
			// 上面二种在,一直线上. 还有一种是吃中间的棋子将. 炮 a b 将, a可以吃b生产将. 
			// 如果是马,仕,相,就一定是将军步哇
			if(AlwaysZhouJiang[piece_on(from)]){
				return true;
			}
			// 再判断一下, 用复杂的方法. 
			if(direction_between_squares(from, yk) != direction_between_squares(to, yk)){
					return true;
			}
			// 再看一下是不是炮,车,兵等吃子将. 
			if(piece_on(to) != EMPTY){
				return true;
			}
		}
		else{  // 3, 马的抽将.			 
			return true;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	// 走到空炮中间的将
	if(bit_is_set(ci.PaoNull,to)){ // 还要这个棋子,不是这个炮才行哇.
		if(type_of(pc) == PAO && bit_is_set(ChePseudoMask_FR[yk],from)){			
			return false; // 这个不可能再将了. 			
		}
		return true;
	}

	//还要炮吃其它的子来将.
	// fen r1bakab1r/9/7c1/p1p1C1p1p/4n4/4n4/P1P3P1P/9/9/RNBAKABNR w - - 0 1
	// e6e2 红炮吃子将?? 这时炮也动了哇. 
	// fen rnbakabr1/9/4c2c1/p1p1C1p1p/9/9/P1P1P1P1P/9/9/RNBAKABNR b - - 0 1 // 这个不是将
	if(type_of(pc) == PAO && b90[to] != EMPTY 
		&& bit_is_set(ChePseudoMask_FR[yk],from)
		&& bit_is_set(ChePseudoMask_FR[yk],to)){

		Color Us = color_of(piece_on(from));  // side_to_move();
		const Piece delt = COLOR_BY_SIDE_ADD[Us];
        // 看一下是不是有炮在将了.
		Bitboard occ = occupied_squares();
		clear_bit(occ,from);
		set_bit(occ,to);
		//Bitboard paoeat = pao_eat_attacks_bb(ci.ksq,occ);
		Bitboard paoeat = Pao_Eat_bb(yk,occ);
		Bitboard pao = pieces(RPAO + delt);

		clear_bit(pao,from);
		set_bit(pao,to);

		if(have_bit(paoeat,pao)){
			return true;
		}
	}

	return false;
}


bool Position::test_Is_True_Cap(Square from, Square to, Color which){
	
	PieceType to_id;
	//Bitboard bb;
	Color oldside;
	Piece undo_capture;
	bool isP;

	to_id = type_of(b90[to]);

	//---------------------------------------------------------------------------
	//1, 是兵或将在吃, 就返回 FALSE ,这儿不用了, 因为前面的已去除了
	//---------------------------------------------------------------------------


	//---------------------------------------------------------------------------
	//2, 判断这个棋能不能走, 如果不能走,也就不可能去吃对方了
	//---------------------------------------------------------------------------
	//if(Is_Can_Move_To_Eat(board,from,to) == FALSE){  //捉方的子不能动.
	//	return;
	//}

	//上面的也不用,因为已在前面过滤了.

	//---------------------------------------------------------------------------
	//3, 再判断一下这个捉的棋的价值是不是比被捉的棋的价值小
	//---------------------------------------------------------------------------
	if(PieceValueMidgame[b90[from]] >= PieceValueMidgame[b90[to]]){
		//---------------------------------------------------------------------------
		//4, 如果双方的棋子相同,则要判断 1, 这个棋子能不能走, 2, 这个棋能不能反吃对方(马)
		//---------------------------------------------------------------------------
		if(type_of(b90[from]) == to_id){
			//判断是不是马捉
			//if(Is_Can_Move_To_Eat(board,to,from) == TRUE){
			if(legal(MOVE_FromTo(to,from)) == true){
				if(to_id != MA) return false;
				// fen 3ak4/4a4/2ncb4/4N4/2p1P1b2/6B2/2P6/1N7/9/3AKAB2 b - - 157 157 这个不是
				// fen 3ak4/4a4/2ncb4/4N4/2p3b2/6B2/2P6/1N7/9/3AKAB2 b 这个是常捉
				//再看一下这个马能不能反吃到自己.
				//king_to_ma_attacks(bb,board,sq);
				//BB_and_BB(bb,board->byChessBB[BMA]);
				//BB_or_BB(att,bb);	
				Bitboard bb = king_to_ma_attacks_bb(from,byWhiteBlack);
				if(bit_is_set(bb,to)){         //board_display(board,"cap too");
					return false;
				}
			}
		}
		//---------------------------------------------------------------------------
		//5, 再看一下这个棋有没有其它的棋子保护着
		//---------------------------------------------------------------------------

		oldside = sideToMove;
		sideToMove = color_of(b90[from]);
		move_do_test(MOVE_FromTo(from,to),&undo_capture);

		//b, 再看一下有没有其它的棋子保护着
		isP = isPretecte_TrueCap(which,to);	
		move_undo_test(MOVE_FromTo(from,to),undo_capture);	
		sideToMove = oldside;

		if(isP == true) return false;
	}

	return true;
}


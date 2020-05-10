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

/// Position::flipped_copy() makes a copy of the input position, but with
/// the white and black sides reversed. This is only useful for debugging,
/// especially for finding evaluation symmetry bugs.
/// 红黑双交换一下, 主要是用来调试用的. 

static const  Piece r2b_chess[16] = {
	EMPTY,  //这个不用了
	BKING,BSHI,BXIANG,BMA,BCHE,BPAO,BPAWN,
	_X_X,		
	RKING,RSHI,RXIANG,RMA,RCHE,RPAO,RPAWN,
};

void Position::board_red2black(const Position& pos) {

	//ASSERT(pos_is_ok());

	StateInfo* pst = st;
	Thread* ptd = pos.this_thread();
	std::memset(this, 0, sizeof(Position));
	st = pst;
	thisThread = ptd;

	// Board
	for (Square s = SQ_START; s < SQ_END90; s++){
		if (!pos.square_is_empty(s)){
			//put_piece(Piece(int(pos.piece_on(s)) ^ 8), flip_square(s));

			Piece  newP = r2b_chess[pos.piece_on(s)];
			Square newS = Square(89 - s);

			put_piece(newP, newS);
		}
	}

	// Side to move
	sideToMove = ~pos.side_to_move();
	
	set_state(st);

	ASSERT(pos_is_ok());
}

void Position::board_mirror(const Position& pos){

	StateInfo* pst = st;
	Thread* ptd = pos.this_thread();
	std::memset(this, 0, sizeof(Position));
	st = pst;
	thisThread = ptd;

	// Board
	for (Square s = SQ_START; s < SQ_END90; s++){
		if (!pos.square_is_empty(s)){
			//put_piece(Piece(int(pos.piece_on(s)) ^ 8), flip_square(s));

			Piece  newP = pos.piece_on(s);
			Square newS = Square(Mirror(s));

			put_piece(newP, newS);
		}
	}

	// Side to move
	sideToMove = pos.side_to_move();

	set_state(st);

	ASSERT(pos_is_ok());
}


/// Position::is_ok() performs some consitency checks for the position object.
/// This is meant to be helpful when debugging.

bool Position::pos_is_ok(int* failedStep) {

#ifndef USE_SLOW_BOARD  
	return true;
#endif

	// What features of the position should be verified?
	static const bool debugBitboards        = true; // = false;
	static const bool debugKingCount        = true; // = false;
	static const bool debugKingCapture      = true; // = false;
	static const bool debugCheckerCount     = true; // = false;
	static const bool debugKey              = true; // = false;
	//static const bool debugMaterialKey      = true; // = false;
	static const bool debugPawnKey          = true; // = false;
	static const bool debugIncrementalEval  = true; // = false;
	//static const bool debugNonPawnMaterial  = true; // = false;
	static const bool debugPieceCounts      = true; // = false;
	//static const bool debugPieceList        = true; // = false;
	//static const bool debugCastleSquares    = true; // = false;
	static const bool debugPmat             = true; // = false;
	static const bool debugFileRank         = true;
//	static const bool debugPawnKey = true;

	//if(gamePly > 512){
	//	return false;
	//}

		
	if (failedStep) *failedStep = 1;

	// Side to move OK?
	if (!color_is_ok(side_to_move()))
		return false;

	// Are the king squares in the position correct?
	if (failedStep) (*failedStep)++;  // 第几步错了. 
	//if (piece_on(king_square(WHITE)) != WK)
	//	return false;

	if (failedStep) (*failedStep)++;
	//if (piece_on(king_square(BLACK)) != BK)
	//	return false;

	// Castle files OK?
	//if (failedStep) (*failedStep)++;
	//if (!file_is_ok(initialKRFile))
	//	return false;

	//if (!file_is_ok(initialQRFile))
	//	return false;

	// Do both sides have exactly one king?
	if (failedStep) (*failedStep)++;
	if (debugKingCount)
	{
		//int kingCount[2] = {0, 0};
		//for (Square s = SQ_A1; s <= SQ_H8; s++)
		//	if (type_of(s) == KING)
		//		kingCount[color_of(s)]++;

		//if (kingCount[0] != 1 || kingCount[1] != 1)
		//	return false;

		if(pieceCount[RKING] != 1 || pieceCount[BKING] != 1){
			return false;
		}
	}

	// Can the side to move capture the opponent's king?
	if (failedStep) (*failedStep)++;
	if (debugKingCapture)
	{
		Color us = side_to_move();
		Color them = ~us;
		Square ksq = king_square(them);
		if (m_have_bit(
			m_and(attackers_to(ksq),pieces_of_color(us)))){
			board_display("我方可吃对方老将了！！");
			return false;
		}
	}

	// Is there more than 2 checkers?
	if (failedStep) (*failedStep)++;
	if (debugCheckerCount && count_1s(st->checkersBB) > 3){
		return false;  // 这个好象中象可以哇.
	}

	// Bitboards OK?
	if (failedStep) (*failedStep)++;
	if (debugBitboards)
	{
		// The intersection of the white and black pieces must be empty
		//if ((pieces_of_color(WHITE) & pieces_of_color(BLACK)) != EmptyBoardBB)
		//	return false;

		if(m_have_bit(m_and(pieces_of_color(WHITE),
			pieces_of_color(BLACK)))){
				return false;
		}

		// The union of the white and black pieces must be equal to all
		// occupied squares
		//if ((pieces_of_color(WHITE) | pieces_of_color(BLACK)) != occupied_squares())
		//	return false;
		Bitboard occ = occupied_squares();
		Bitboard br = m_or(pieces_of_color(WHITE), pieces_of_color(BLACK));
		if(m128_is_same(br,occ) == false){
				return false;
		}

		// Separate piece type bitboards must have empty intersections
		//for (PieceType p1 = PAWN; p1 <= KING; p1++)
		//	for (PieceType p2 = PAWN; p2 <= KING; p2++)
		//		if (p1 != p2 && (pieces(p1) & pieces(p2)))
		//			return false;

		// pieceCount
		//for(int i = 0; i < 16; i++){
		//	for(int j = 0; j < 16; j++){
		//		for(int n1 = 0; n1 < pieceCount[i]; n1++){
		//			for(int n2 = 0; n2 < pieceCount[j]; n2++){
		//				Square s1 = pieceList[i][n1];
		//				Square s2 = pieceList[j][n2];
		//				if(s1 != s2){
		//					if(m_have_bit(m_and(
		//						pieces()
		//				}
		//			}
		//		}
		//	}
		//}

		//#define S90_from_piecelist(POSITION,piece,index)  (POSITION.pieceList[piece][index])

		// 不同的棋子之前的位棋盘必须不同.

	}

	// En passant square OK?
	//if (failedStep) (*failedStep)++;
	//if (ep_square() != SQ_NONE)
	//{
	//	// The en passant square must be on rank 6, from the point of view of the
	//	// side to move.
	//	if (relative_rank(side_to_move(), ep_square()) != RANK_6)
	//		return false;
	//}

	// Hash key OK?
	if (failedStep) (*failedStep)++;
	if (debugKey && st->key != compute_key())
		return false;

	// Pawn hash key OK?
	if (failedStep) (*failedStep)++;
	if (debugPawnKey && st->pawnKey != compute_pawn_key())
		return false;

	// Material hash key OK?
	//if (failedStep) (*failedStep)++;
	//if (debugMaterialKey && st->materialKey != compute_material_key())
	//	return false;

	// Incremental eval OK?
	if (failedStep) (*failedStep)++;
	if (debugIncrementalEval && st->psq != compute_psq_value())
		return false;

	// Non-pawn material OK?
	//if (failedStep) (*failedStep)++;
	//if (debugNonPawnMaterial)
	//{
	//	if (st->npMaterial[WHITE] != compute_non_pawn_material(WHITE))
	//		return false;

	//	if (st->npMaterial[BLACK] != compute_non_pawn_material(BLACK))
	//		return false;
	//}

	// debugPmat
	if (failedStep) (*failedStep)++;
	if(debugPmat){
		if(st->pMat != compute_premat()){
			return false;
		}
	}

	// Piece counts OK?
	if (failedStep) (*failedStep)++;
	if (debugPieceCounts){
		//for (Color c = WHITE; c <= BLACK; c++)
		//	for (PieceType pt = PAWN; pt <= KING; pt++)
		//		if (pieceCount[c][pt] != (int)count_1s(pieces(pt, c)))
		//			return false;

		for(Piece p = RKING; p <= BPAWN; p++){
			if(p == EMPTY || p == _X_X) continue;
			if(pieceCount[p] != (int)count_1s(pieces(p))){
				return false;
			}
			//for(int i = 0; i < pos.piece_count(RPAO + delt); i++){
			//	Square s =  pos.piece_list(RPAO + delt,i);
			for(int i = 0; i < piece_count(p); i++){
				Square s = piece_list(p,i);
				if(b90[s] != p){
					return false;
				}
			}
		}
	}

	//if (failedStep) (*failedStep)++;
	//if (debugPieceList)
	//{
	//	for (Color c = WHITE; c <= BLACK; c++)
	//		for (PieceType pt = PAWN; pt <= KING; pt++)
	//			for (int i = 0; i < pieceCount[c][pt]; i++)
	//			{
	//				if (piece_on(piece_list(c, pt, i)) != piece_of_color_and_type(c, pt))
	//					return false;

	//				if (index[piece_list(c, pt, i)] != i)
	//					return false;
	//			}
	//}

	//if (failedStep) (*failedStep)++;
	//if (debugCastleSquares) {
	//	for (Color c = WHITE; c <= BLACK; c++) {
	//		if (can_castle_kingside(c) && piece_on(initial_kr_square(c)) != piece_of_color_and_type(c, ROOK))
	//			return false;
	//		if (can_castle_queenside(c) && piece_on(initial_qr_square(c)) != piece_of_color_and_type(c, ROOK))
	//			return false;
	//	}
	//	if (castleRightsMask[initial_kr_square(WHITE)] != (ALL_CASTLES ^ WHITE_OO))
	//		return false;
	//	if (castleRightsMask[initial_qr_square(WHITE)] != (ALL_CASTLES ^ WHITE_OOO))
	//		return false;
	//	if (castleRightsMask[initial_kr_square(BLACK)] != (ALL_CASTLES ^ BLACK_OO))
	//		return false;
	//	if (castleRightsMask[initial_qr_square(BLACK)] != (ALL_CASTLES ^ BLACK_OOO))
	//		return false;
	//}

	if (failedStep) *failedStep = 0;
	return true;
}


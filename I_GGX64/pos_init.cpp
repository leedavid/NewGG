#include "chess.h"

////
//// Includes
////

#include <cassert>
#include <cstring>
#include <fstream>
#include <iostream>


#include "rkiss.h"
#include "movegen.h"
#include "movepick.h"
#include "position.h"
#include "notation.h"
#include "tt.h"
#include "uci.h"

using std::string;





/// Position::clear() erases the position object to a pristine state, with an
/// empty board, white to move, and no castling rights.

//void Position::clear() {
//
//	std::memset(this, 0, sizeof(Position));
//	st = &startState;
//
//	//sideToMove = WHITE;
//	//nodes = 0;
//
//}


/// Position::put_piece() puts a piece on the given square of the board,
/// updating the board array, bitboards, and piece counts.
/// 在棋盘上添加一个棋子

void Position::put_piece(Piece p, Square s) {

	Color c = color_of(p);

	b90[s]   = p;
	index[s] = pieceCount[p];
	pieceList[p][index[s]] = s;
	pieceCount[p] ++;

	// bitboard
	set_bit(byWhiteBlack,s);
	set_bit(byChessBB[p],s);
	set_bit(byChessBB[COLOR_BY_SIDE_ADD[c]],s);

}










premat_t* Position::compute_premat() const {
	premat_t* result = 
   &PreMatInfo[pieceCount[RPAWN]]
	          [pieceCount[BPAWN]]
	[pieceCount[RCHE]]
	[pieceCount[RMA]]
	[pieceCount[RPAO]]
	[pieceCount[BCHE]]
	[pieceCount[BMA]]
	[pieceCount[BPAO]];

	return result;
};










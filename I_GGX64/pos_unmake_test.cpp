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

void Position::move_do_test(Move m, Piece* capture){

	Square from    = from_sq(m);
	Square to      = to_sq(m);
	Piece  piece   = b90[from];
	*capture       = b90[to];     // 保存刚才吃的子.

	ASSERT(sideToMove == color_of(piece));
	ASSERT(piece != NO_PIECE);

	sideToMove = color_of(piece);

	Color us   = sideToMove;
	Color them = ~us;

	//Piece delta = COLOR_BY_SIDE_ADD[sideToMove];	

	// bitboard from
	//byChessBB[COLOR_BY_SIDE[c]];
	clear_bit(byChessBB[COLOR_BY_SIDE_ADD[us]],from);         // di == from
	set_bit  (byChessBB[COLOR_BY_SIDE_ADD[us]],to);           // ai == to

	clear_bit(byChessBB[piece],from);  // di == from
	set_bit  (byChessBB[piece],to);    // ai == to

	clear_bit(byWhiteBlack,from);      // di == from

	if (*capture){
		//do_capture_move(key, capture, them, to, ep);

		clear_bit(byChessBB[*capture],to);
		clear_bit(byChessBB[COLOR_BY_SIDE_ADD[them]],to);

		// piece count
		pieceCount[*capture] --;

		// piecelist
		pieceList[*capture][index[to]] = pieceList[*capture][pieceCount[*capture]];

		// index
		index[pieceList[*capture][index[to]]] = index[to];

	}
	else{
		set_bit(byWhiteBlack,to);
	}

	b90[to]    = piece;
	b90[from]  = NO_PIECE;

	// pieceList
	pieceList[piece][index[from]] = to;

	// index
	index[to] = index[from];

	// Finish
	sideToMove = ~sideToMove;
}

void Position:: move_undo_test(Move m, Piece capture){

	Square from    = from_sq(m);
	Square to      = to_sq(m);
	Piece  piece   = b90[to];

	sideToMove  = color_of(piece);
	Color us    = side_to_move();
	Color them  = ~us;

	ASSERT(square_is_empty(from));
	ASSERT(color_of(b90[to]) == us);

	b90[from] = piece;
	b90[to]   = NO_PIECE;

	
	set_bit(byChessBB[COLOR_BY_SIDE_ADD[us]],from);
	clear_bit(byChessBB[COLOR_BY_SIDE_ADD[us]],to);

	set_bit  (byChessBB[piece],from);
	clear_bit(byChessBB[piece],to);

	set_bit(byWhiteBlack,from);        // occ 

	// Update piece list
	pieceList[piece][index[to]] = from;
	index[from] = index[to];

	if (capture)  // 如果有吃子了. 
	{
		//Square capsq = to;

		ASSERT(capture != RKING && capture != BKING);
		ASSERT(square_is_empty(to));

		// bitboard
		set_bit(byChessBB[COLOR_BY_SIDE_ADD[them]],to);
		set_bit(byChessBB[capture],to);

		b90[to] = capture;  // 这个加上,安全些		

		// Update piece list, add a new captured piece in capsq square
		pieceList[capture][pieceCount[capture]] = to;
		index[to] = (uint8)(pieceCount[capture]);

		// Update piece count
		pieceCount[capture]++;

	}
	else{
		clear_bit(byWhiteBlack,to); 
	}


} 


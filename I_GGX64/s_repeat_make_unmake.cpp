#include "chess.h"


////
//// Includes
////

#include <cassert>
#include <cstring>
#include <fstream>
#include <iostream>

#include "s_bitcount.h"
#include "s_mersenne.h"
#include "s_movegen.h"
#include "s_movepick.h"
#include "s_position.h"
#include "s_psqtab.h"
#include "s_san.h"
#include "s_tt.h"
#include "s_ucioption.h"

using std::string;

//void Position::repeat_make(){
//
//	Move m = st->m; // Move m = Move(history[gamePly].move);
//
//	//gamePly++;
//
//	//ASSERT(gamePly < 512 && gamePly >= 0);
//
//	Square from    = move_from(m);
//	Square to      = move_to(m);
//	Piece  piece   = b90[from];
//	//Piece  capture = b90[to];
//
//	ASSERT(sideToMove == color_of(piece));
//	ASSERT(piece != EMPTY);
//
//	sideToMove = color_of(piece);
//
//	Color us   = sideToMove;
//	//Color them = flip(us);
//
//	//Piece delta = COLOR_BY_SIDE_ADD[sideToMove];	
//
//	// bitboard from
//	//byChessBB[COLOR_BY_SIDE[c]];
//	clear_bit(byChessBB[COLOR_BY_SIDE_ADD[us]],from);           // di == from
//	set_bit  (byChessBB[COLOR_BY_SIDE_ADD[us]],to);           // ai == to
//
//	clear_bit(byChessBB[piece],from);  // di == from
//	set_bit  (byChessBB[piece],to);  // ai == to
//
//	clear_bit(byWhiteBlack,from);      // di == from
//
//	//if (capture){
//	//	//do_capture_move(key, capture, them, to, ep);
//
//	//	clear_bit(byChessBB[capture],to);
//	//	clear_bit(byChessBB[COLOR_BY_SIDE_ADD[them]],to);
//
//	//	// piece count
//	//	pieceCount[capture] --;
//
//	//	// piecelist
//	//	pieceList[capture][index[to]] = pieceList[capture][pieceCount[capture]];
//
//	//	// index
//	//	index[pieceList[capture][index[to]]] = index[to];
//
//	//}
//	//else{
//		set_bit(byWhiteBlack,to);
//	//}
//
//
//	b90[to]    = piece;
//	b90[from]  = EMPTY;
//
//	// pieceList
//	pieceList[piece][index[from]] = to;
//
//	// index
//	index[to] = index[from];
//	
//	// Finish
//	sideToMove = flip(sideToMove);
//
//}
/*
void Position::repeat_unmake(){

	Move m = Move(history[gamePly-1].move);

	Square from    = move_from(m);
	Square to      = move_to(m);
	Piece  piece   = b90[to];
	//Piece  capture = Piece(history[gamePly-1].capture);

	sideToMove  = flip(sideToMove);
	Color us    = side_to_move();
	//Color them  = flip(us);

	ASSERT(square_is_empty(from));
	ASSERT(color_of(to) == us);

	// Put the piece back at the source square
	//Bitboard move_bb = make_move_bb(to, from);
	//do_move_bb(&(byColorBB[us]), move_bb);
	//do_move_bb(&(byTypeBB[pt]), move_bb);
	//do_move_bb(&(byTypeBB[0]), move_bb); // HACK: byTypeBB[0] == occupied squares	


	b90[from] = piece;
	b90[to]   = EMPTY;

	// bitboard clear_bit(byChessBB[COLOR_BY_SIDE_ADD[us]],from);           // di == from
	set_bit(byChessBB[COLOR_BY_SIDE_ADD[us]],from);
	clear_bit(byChessBB[COLOR_BY_SIDE_ADD[us]],to);

	set_bit  (byChessBB[piece],from);
	clear_bit(byChessBB[piece],to);

	set_bit(byWhiteBlack,from);        // occ 

	// Update piece list
	pieceList[piece][index[to]] = from;
	index[from] = index[to];

	//if (capture)  // 如果有吃子了. 
	//{
	//	//Square capsq = to;

	//	ASSERT(capture != RKING && capture != BKING);
	//	ASSERT(square_is_empty(to));

	//	// Restore the captured piece
	//	//set_bit(&(byColorBB[them]), capsq);
	//	//set_bit(&(byTypeBB[st->capture]), capsq);
	//	//set_bit(&(byTypeBB[0]), capsq);

	//	// bitboard
	//	set_bit(byChessBB[COLOR_BY_SIDE_ADD[them]],to);
	//	set_bit(byChessBB[capture],to);

	//	b90[to] = capture;  // 这个加上,安全些		

	//	// Update piece list, add a new captured piece in capsq square
	//	pieceList[capture][pieceCount[capture]] = to;
	//	index[to] = pieceCount[capture];

	//	// Update piece count
	//	pieceCount[capture]++;

	//}
	//else{
		clear_bit(byWhiteBlack,to); 
	//}

	//gamePly --;
}


*/